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
static char *g_server_cert_pem;
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
    }
    return ESP_OK;
}

static int __qmsd_http_ota(const char *url)
{
    ESP_LOGI(TAG, "Starting HTTP OTA");

    esp_http_client_config_t config = {
        .url = url,
        .cert_pem = (char *)g_server_cert_pem,
        .event_handler = __qmsd_http_event_handler,
        .keep_alive_enable = true,
    };

    esp_https_ota_config_t ota_config = {
        .http_config = &config,
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

    vTaskDelete(NULL);
    g_http_ota_handle = NULL;
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

    if (g_ota_url) {
        free(g_ota_url);
    }

    g_ota_url = strdup(url);
    if (g_ota_url) {
        if (xTaskCreate(&__qmsd_ota_task, "qmsd_ota_task", 8192, (void *)url, 7, &g_http_ota_handle) != pdPASS) {
            return -1;
        }
    }

    return 0;
}

void qmsd_ota_stop(void)
{
    if (g_ota_url) {
        free(g_ota_url);
    }

    if (g_http_ota_handle) {
        vTaskDelete(g_http_ota_handle);
    }

    g_ota_handle = NULL;
}
