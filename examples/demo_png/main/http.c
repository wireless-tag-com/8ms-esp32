#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "esp_system.h"
#include "esp_event.h"
#include "esp_tls.h"

#include "esp_http_client.h"
#include "qmsd_ui_entry.h"
#include "qmsd_ctrl.h"
#include "qmsd_gui_init.h"

static const char *TAG = "QMSD_HTTP";

extern void screen_show_png(char *filename);

FILE *g_img_file;
static esp_err_t __http_event_handler(esp_http_client_event_t *evt)
{
    switch (evt->event_id)
    {
    case HTTP_EVENT_ERROR:
        ESP_LOGD(TAG, "HTTP_EVENT_ERROR");
        break;
    case HTTP_EVENT_ON_CONNECTED:
        g_img_file = fopen(QMSD_TEST_PNG_FILE, "w");
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
        if (g_img_file)
            fwrite(evt->data, evt->data_len, 1, g_img_file);
        break;
    case HTTP_EVENT_ON_FINISH:
        ESP_LOGD(TAG, "HTTP_EVENT_ON_FINISH");
        break;
    case HTTP_EVENT_DISCONNECTED:
        ESP_LOGI(TAG, "HTTP_EVENT_DISCONNECTED");
        break;
    }

    return ESP_OK;
}

esp_err_t qmsd_http_get_start(const char *url, const char *header, const char *user_agent)
{
    esp_err_t err = ESP_FAIL;
    int i;

    esp_http_client_config_t config = {
        .event_handler = __http_event_handler,
        .url = url,
        .user_agent = user_agent,
        .buffer_size = 5120,
        .method = HTTP_METHOD_GET,
        .cert_pem = NULL,
    };
    esp_http_client_handle_t client = esp_http_client_init(&config);

    if (header) {
        err = esp_http_client_set_header(client, "Content-Type", header);
        if (err != ESP_OK)
            ESP_LOGE(TAG, "http client set header error");
    }

    for (i = 0; i < 5; i++) {
        err = esp_http_client_perform(client);
        if (err == ESP_OK)
        {
            ESP_LOGI(TAG, "HTTPS Status = %d, content_length = %d",
                    esp_http_client_get_status_code(client),
                    esp_http_client_get_content_length(client));
            if (g_img_file) {
                fclose(g_img_file);
                g_img_file = NULL;
            }

            /*
             * show png
             */
            qmsd_gui_lock(portMAX_DELAY);
            screen_show_png(QMSD_TEST_PNG_FILE);
            qmsd_gui_unlock();

            break;
        }
        else
        {
            ESP_LOGE(TAG, "Error perform http request %s", esp_err_to_name(err));
            vTaskDelay(pdMS_TO_TICKS(120));
        }
    }

    esp_http_client_cleanup(client);

    return err;
}
