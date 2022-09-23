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
#include "qmsd_api.h"
#include "qmsd_notifier.h"

extern const char https_root_cert_pem_start[] asm("_binary_https_root_cert_pem_start");
extern const char https_root_root_cert_pem_end[] asm("_binary_https_root_cert_pem_end");

static const char *TAG = "QMSD_HTTP";

static esp_err_t __http_event_handler(esp_http_client_event_t *evt)
{
    switch (evt->event_id)
    {
    case HTTP_EVENT_ERROR:
        ESP_LOGD(TAG, "HTTP_EVENT_ERROR");
        break;
    case HTTP_EVENT_ON_CONNECTED:
        qmsd_notifier_call_nolock(QMSD_HTTP_CONNECTED, NULL);
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
        struct qmsd_http_get_data data;
        data.data = (char *)evt->data;
        data.size = evt->data_len;
        qmsd_notifier_call_nolock(QMSD_HTTP_DATA, &data);
        break;
    case HTTP_EVENT_ON_FINISH:
        qmsd_notifier_call_nolock(QMSD_HTTP_FINISH, NULL);
        ESP_LOGD(TAG, "HTTP_EVENT_ON_FINISH");
        break;
    case HTTP_EVENT_DISCONNECTED:
        qmsd_notifier_call_nolock(QMSD_HTTP_DIS, NULL);
        ESP_LOGI(TAG, "HTTP_EVENT_DISCONNECTED");
        break;
    case HTTP_EVENT_REDIRECT:
        break;
    }

    return ESP_OK;
}

esp_err_t qmsd_http_get(const char *url, const char *header, const char *user_agent)
{
    esp_err_t err = ESP_FAIL;

    esp_http_client_config_t config = {
        .event_handler = __http_event_handler,
        .url = url,
        .user_agent = user_agent,
        .buffer_size = 5120,
        .method = HTTP_METHOD_GET,
        .cert_pem = https_root_cert_pem_start,
    };
    esp_http_client_handle_t client = esp_http_client_init(&config);

    if (header) {
        err = esp_http_client_set_header(client, "Content-Type", header);
        if (err != ESP_OK)
            ESP_LOGE(TAG, "http client set header error");
    }

    err = esp_http_client_perform(client);
    if (err == ESP_OK)
    {
        ESP_LOGI(TAG, "HTTPS Status = %d, content_length = %d",
                 esp_http_client_get_status_code(client),
                 esp_http_client_get_content_length(client));
    }
    else
    {
        ESP_LOGE(TAG, "Error perform http request %s", esp_err_to_name(err));
    }

    esp_http_client_cleanup(client);

    return err;
}

esp_err_t qmsd_http_post(char *url, const char *post_data, int post_len)
{
    esp_err_t err = ESP_FAIL;

    esp_http_client_config_t config = {
        .event_handler = __http_event_handler,
        .url = url,
        .method = HTTP_METHOD_POST,
        .cert_pem = https_root_cert_pem_start,
    };
    esp_http_client_handle_t client = esp_http_client_init(&config);
    esp_http_client_set_header(client, "Content-Type", "application/x-www-form-urlencoded");
    esp_http_client_set_post_field(client, post_data, post_len);
    err = esp_http_client_perform(client);
    if (err == ESP_OK)
    {
        ESP_LOGI(TAG, "HTTP POST Status = %d, content_length = %d",
                 esp_http_client_get_status_code(client),
                 esp_http_client_get_content_length(client));
    }
    else
    {
        ESP_LOGE(TAG, "HTTP POST request failed: %s", esp_err_to_name(err));
    }

    esp_http_client_cleanup(client);
    return err;
}

esp_err_t qmsd_http_post_json(char *url, const char *post_data, int post_len)
{
    esp_err_t err = ESP_FAIL;

    esp_http_client_config_t config = {
        .event_handler = __http_event_handler,
        .url = url,
        .method = HTTP_METHOD_POST,
        .cert_pem = https_root_cert_pem_start,
    };
    esp_http_client_handle_t client = esp_http_client_init(&config);
    esp_http_client_set_header(client, "Content-Type", "application/json");
    esp_http_client_set_post_field(client, post_data, post_len);
    err = esp_http_client_perform(client);
    if (err == ESP_OK)
    {
        ESP_LOGI(TAG, "HTTP POST Status = %d, content_length = %d",
                 esp_http_client_get_status_code(client),
                 esp_http_client_get_content_length(client));
    }
    else
    {
        ESP_LOGE(TAG, "HTTP POST request failed: %s", esp_err_to_name(err));
    }

    esp_http_client_cleanup(client);
    return err;
}

esp_err_t qmsd_http_post_img(char *url, const char *post_data, int post_len)
{
    char *post = (char *)malloc(post_len + 1024);
    esp_http_client_config_t config = {
        .url = url,
        .event_handler = __http_event_handler,
        .method = HTTP_METHOD_POST,
        .user_agent = "QMSD HTTP POST",
    };
    esp_http_client_handle_t client = esp_http_client_init(&config);

    esp_http_client_set_header(client, "Content-Type", "multipart/form-data; boundary=----WebKitFormBoundary7MA4YWxkTrZu0gW");

    memcpy(post, "------WebKitFormBoundary7MA4YWxkTrZu0gW\r\nContent-Disposition: form-data; name=\"file\"; filename=\"img.jpeg\"\r\nContent-Type: image/jpeg\r\n\r\n", 135);
    memcpy(post + 135, post_data, post_len);
    memcpy(post + 135 + post_len, "\r\n------WebKitFormBoundary7MA4YWxkTrZu0gW--\r\n", 45);

    esp_http_client_set_post_field(client, post, post_len + 180);
    esp_err_t err = esp_http_client_perform(client);
    if (err == ESP_OK)
    {
        ESP_LOGI(TAG, "HTTP POST Status = %d, content_length = %d",
                 esp_http_client_get_status_code(client),
                 esp_http_client_get_content_length(client));
    }
    else
    {
        ESP_LOGE(TAG, "HTTP POST request failed: %s", esp_err_to_name(err));
    }
    esp_http_client_cleanup(client);

    return err;
}