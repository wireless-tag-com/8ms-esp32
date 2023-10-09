#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_event.h"
#include "esp_log.h"
#include "esp_ota_ops.h"
#include "esp_http_client.h"
#include "esp_https_ota.h"
#include "string.h"

#include <sys/socket.h>

#include "qmsd_notifier.h"
#include "qmsd_api.h"

static const char *TAG = "QMSD_OTA";
TaskHandle_t g_http_ota_handle;
static char *g_server_cert_pem = NULL;
static esp_https_ota_handle_t g_ota_handle;
static char *g_ota_url;

static esp_err_t __qmsd_http_event_handler(esp_http_client_event_t *evt)
{
    switch (evt->event_id)
    {
    case HTTP_EVENT_ERROR:
        ESP_LOGD(TAG, "HTTP_EVENT_ERROR");
        break;
    case HTTP_EVENT_ON_CONNECTED:
        ESP_LOGD(TAG, "HTTP_EVENT_ON_CONNECTED");
        break;
    case HTTP_EVENT_HEADER_SENT:
        ESP_LOGD(TAG, "HTTP_EVENT_HEADER_SENT");
        break;
    case HTTP_EVENT_ON_HEADER:
        ESP_LOGD(TAG, "HTTP_EVENT_ON_HEADER, key=%s, value=%s", evt->header_key, evt->header_value);
        break;
    case HTTP_EVENT_ON_DATA:
        ESP_LOGD(TAG, "HTTP_EVENT_ON_DATA, len=%d", evt->data_len);
        break;
    case HTTP_EVENT_ON_FINISH:
        ESP_LOGD(TAG, "HTTP_EVENT_ON_FINISH");
        break;
    case HTTP_EVENT_DISCONNECTED:
        ESP_LOGD(TAG, "HTTP_EVENT_DISCONNECTED");
        break;
    case HTTP_EVENT_REDIRECT:
        break;
    }
    return ESP_OK;
}

static int __qmsd_http_ota(const char *url)
{
    ESP_LOGI(TAG, "Starting HTTP OTA");

    if (!g_ota_url) {
        return ESP_FAIL;
    }
    esp_http_client_config_t client_config = {
        .url = g_ota_url,
        .timeout_ms = 8000,
        .cert_pem = NULL,
        .event_handler = __qmsd_http_event_handler,
        .keep_alive_count = true,
    };
    
    esp_https_ota_config_t ota_config = {
        .http_config = &client_config,
    };

    esp_err_t err = esp_https_ota_begin(&ota_config, &g_ota_handle);
    if (g_ota_handle == NULL) {
        return ESP_FAIL;
    }

    while (1) {
        err = esp_https_ota_perform(g_ota_handle);
        if (err != ESP_ERR_HTTPS_OTA_IN_PROGRESS) {
            break;
        }
    }

    if (err != ESP_OK) {
        esp_https_ota_abort(g_ota_handle);
        return err;
    }

    esp_err_t ota_finish_err = esp_https_ota_finish(g_ota_handle);
    if (ota_finish_err != ESP_OK) {
        return ota_finish_err;
    }

    return ESP_OK;
}

static void __qmsd_ota_task(void *pvParameter)
{
    esp_err_t err = __qmsd_http_ota((char *)pvParameter);
    if (err == ESP_OK)
    {
        qmsd_notifier_call_nolock(QMSD_SYSTEM_OTA_OK, NULL);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        esp_restart();
    }
    else
    {
        qmsd_notifier_call_nolock(QMSD_SYSTEM_OTA_FAIL, NULL);
        ESP_LOGE(TAG, "Firmware upgrade failed");
    }

    g_http_ota_handle = NULL;

    vTaskDelete(NULL);
}

void qmsd_ota_set_pem(char *pem)
{
    g_server_cert_pem = pem;
}

int qmsd_http_ota_status(void)
{
    if (g_ota_handle) {
        int rlen = esp_https_ota_get_image_len_read(g_ota_handle);
        int ilen = esp_https_ota_get_image_size(g_ota_handle);
        return (rlen * 100) / ilen;
    }

    return 0;
}

int qmsd_ota_start(const char *url)
{
    if (g_http_ota_handle) {
        vTaskDelete(g_http_ota_handle);
    }

    if (url) {
        if (g_ota_url)
            free(g_ota_url);
        g_ota_url = strdup(url);
    }

    if (xTaskCreate(&__qmsd_ota_task, "qmsd_ota_task", 8192, (void *)g_ota_url, 7, &g_http_ota_handle) != pdPASS) {
        return -1;
    }

    return 0;
}

#define HTTP_READ_SIZE      (1460)
#define OTA_WRITE_SIZE      (20)

static char http_read_buf[HTTP_READ_SIZE];

void __qmsd_ota_low_task(void *pvParameter)
{
    esp_err_t err = ESP_FAIL;
    esp_http_client_handle_t client_handle = NULL;
    bool http_status = false;
    int ret;
    int i;
    const esp_partition_t *app_partition = esp_ota_get_running_partition();
    const esp_partition_t *ota_partition = esp_ota_get_next_update_partition(NULL);
    if (!g_ota_url) {
        ESP_LOGI(TAG, "Starting HTTP OTA failed");
        vTaskDelete(NULL);
        return;
    }

    ESP_LOGI(TAG, "partition: cur-(%s), ota-(%s) %s", app_partition->label, ota_partition->label, g_ota_url);

    for (i = 0; i < 10; i++) {
        esp_http_client_config_t client_config = {
            .url = g_ota_url,
            .timeout_ms = 8000,
            .cert_pem = NULL,
            .keep_alive_count = true,
        };

        client_handle = esp_http_client_init(&client_config);
        if (!client_handle) {
            ESP_LOGE(TAG, "http client failed");
            vTaskDelay(3000 / portTICK_PERIOD_MS);
            continue;
        }

        err = esp_http_client_open(client_handle, 0);
        if (err != ESP_OK) {
            ESP_LOGE(TAG, "Failed to open HTTP connection: %s", esp_err_to_name(err));
            vTaskDelay(3000 / portTICK_PERIOD_MS);
            continue;
        }
        ret = esp_http_client_fetch_headers(client_handle);
        if (ret < 0) {
            ESP_LOGE(TAG, "Failed to fetch header: %s", esp_err_to_name(err));
            vTaskDelay(3000 / portTICK_PERIOD_MS);
            continue;
        } else {
            http_status = true;
            break;
        }
    }

    if (http_status) {
        int data_read;
        int data_read_sum = 0;
        bool ota_running = false;
        esp_ota_handle_t ota_handle;
        int ota_write_amount = HTTP_READ_SIZE / OTA_WRITE_SIZE;
        int ota_write_rest = HTTP_READ_SIZE % OTA_WRITE_SIZE;
        ESP_LOGI(TAG, "OTA write amount & rest: %d, %d", ota_write_amount, ota_write_rest);
        void *write_buf;
        for (;;) {
            data_read = esp_http_client_read(client_handle, http_read_buf, HTTP_READ_SIZE);
            if (data_read > 0) {
                if (!ota_running) {
                    ota_running = true;
                    if (data_read > sizeof(esp_image_header_t) + sizeof(esp_image_segment_header_t) + sizeof(esp_app_desc_t)) {
                        const esp_app_desc_t *app_ota = (esp_app_desc_t *)(http_read_buf + sizeof(esp_image_header_t) + sizeof(esp_image_segment_header_t));
                        const esp_app_desc_t *app_cur = esp_ota_get_app_description();
                        ESP_LOGI(TAG, "app version: cur-(%s), ota-(%s)", app_cur->version, app_ota->version);
                        esp_ota_begin(ota_partition, OTA_WITH_SEQUENTIAL_WRITES, &ota_handle);
                        vTaskDelay(pdMS_TO_TICKS(500));
                    }
                    else {
                        ESP_LOGE(TAG, "http read size samller than image header");
                        goto end;
                    }
                }
                write_buf = http_read_buf;
                for (int i = 0; i < ota_write_amount; i++) {
                    esp_ota_write(ota_handle, write_buf, OTA_WRITE_SIZE);
                    vTaskDelay(pdMS_TO_TICKS(2));
                    write_buf += OTA_WRITE_SIZE;
                }
                if (ota_write_rest) {
                    esp_ota_write(ota_handle, write_buf, ota_write_rest);
                    vTaskDelay(pdMS_TO_TICKS(2));
                }
                data_read_sum += data_read;
            }
            else if (data_read == 0) {
                ESP_LOGI(TAG, "http read bytes: %d(%dK)", data_read_sum, data_read_sum / 1024);
                break;
            }
            else {
                qmsd_notifier_call_nolock(QMSD_SYSTEM_OTA_FAIL, NULL);

                ESP_LOGE(TAG, "http read error");
                goto end;
            }
        }
        qmsd_notifier_call_nolock(QMSD_SYSTEM_OTA_OK, NULL);
        /* Slow pclk to prevent dispaly from flickering */
        vTaskDelay(pdMS_TO_TICKS(100));
        esp_ota_end(ota_handle);
        esp_ota_set_boot_partition(ota_partition);
        esp_restart();
    }

end:
	g_http_ota_handle = NULL;
    esp_http_client_close(client_handle);
    esp_http_client_cleanup(client_handle);
    vTaskDelete(NULL);
}

int qmsd_ota_low_start(const char *url)
{
    if (g_http_ota_handle) {
        vTaskDelete(g_http_ota_handle);
    }

    if (url) {
        if (g_ota_url)
            free(g_ota_url);

        g_ota_url = strdup(url);
    }

    if (xTaskCreate(&__qmsd_ota_low_task, "qmsd_ota_task", 8192, NULL, 4, &g_http_ota_handle) != pdPASS) {
        return -1;
    }

    return 0;
}

void qmsd_ota_low_stop(void)
{
    if (g_http_ota_handle) {
        vTaskDelete(g_http_ota_handle);
    }
}

void qmsd_ota_stop(void)
{
    if (g_http_ota_handle) {
        vTaskDelete(g_http_ota_handle);
    }

    if (g_ota_url) {
        free(g_ota_url);
    }

    g_ota_handle = NULL;
}
