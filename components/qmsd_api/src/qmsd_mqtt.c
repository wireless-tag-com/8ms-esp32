#include <stddef.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_log.h"
#include "mqtt_client.h"
#include "esp_tls.h"
#include <sys/param.h>

#include "qmsd_api.h"
#include "qmsd_notifier.h"

#define MQTT_SUCCESS_BIT BIT0
#define MQTT_FAIL_BIT BIT1

static const char *TAG = "QMSD_MQTT";

static esp_mqtt_client_handle_t g_mqtt_client;
static uint8_t g_mqtt_status = -1;

static void __qmsd_mqtt_event_handler(void *handler_args, esp_event_base_t base, int32_t event_id, void *event_data)
{
    esp_mqtt_event_handle_t event = event_data;
    switch ((esp_mqtt_event_id_t)event_id)
    {
    case MQTT_EVENT_CONNECTED:
        ESP_LOGI(TAG, "MQTT_EVENT_CONNECTED");
        g_mqtt_status = 1;
        qmsd_notifier_call_nolock(QMSD_MQTT_EVENT_CONNECTED, NULL);
        break;
    case MQTT_EVENT_DISCONNECTED:
        ESP_LOGI(TAG, "MQTT_EVENT_DISCONNECTED");
        g_mqtt_status = -1;
        qmsd_notifier_call_nolock(QMSD_MQTT_EVENT_DISCONNECTED, NULL);
        break;
    case MQTT_EVENT_SUBSCRIBED:
        ESP_LOGI(TAG, "MQTT_EVENT_SUBSCRIBED, msg_id=%d", event->msg_id);
        break;
    case MQTT_EVENT_UNSUBSCRIBED:
        ESP_LOGI(TAG, "MQTT_EVENT_UNSUBSCRIBED, msg_id=%d", event->msg_id);
        break;
    case MQTT_EVENT_PUBLISHED:
        ESP_LOGI(TAG, "MQTT_EVENT_PUBLISHED, msg_id=%d", event->msg_id);
        break;
    case MQTT_EVENT_DATA:
        ESP_LOGI(TAG, "MQTT_EVENT_DATA");
        qmsd_notifier_call_nolock(QMSD_MQTT_EVENT_DATA, event_data);
        break;
    case MQTT_EVENT_ERROR:
        ESP_LOGW(TAG, "MQTT_EVENT_ERROR");
        if (event->error_handle->error_type == MQTT_ERROR_TYPE_TCP_TRANSPORT)
        {
            ESP_LOGE(TAG, "Last error code reported from esp-tls: 0x%x", event->error_handle->esp_tls_last_esp_err);
            ESP_LOGE(TAG, "Last tls stack error number: 0x%x", event->error_handle->esp_tls_stack_err);
            ESP_LOGE(TAG, "Last captured errno : %d (%s)", event->error_handle->esp_transport_sock_errno,
                     strerror(event->error_handle->esp_transport_sock_errno));
            g_mqtt_status = -2;
        }
        else if (event->error_handle->error_type == MQTT_ERROR_TYPE_CONNECTION_REFUSED)
        {
            ESP_LOGE(TAG, "Connection refused error: 0x%x", event->error_handle->connect_return_code);
            g_mqtt_status = -2;
        }
        else
        {
            ESP_LOGE(TAG, "Unknown error type: 0x%x", event->error_handle->error_type);
            g_mqtt_status = -2;
        }
        qmsd_notifier_call_nolock(QMSD_MQTT_EVENT_ERROR, &event->error_handle->error_type);
        break;
    default:
        ESP_LOGI(TAG, "Other event id:%d", event->event_id);
        break;
    }
}

int qmsd_mqtt_status(void)
{
    return g_mqtt_status;
}

int qmsd_mqtt_start(esp_mqtt_client_config_t *config)
{
    esp_err_t err = ESP_FAIL;

    qmsd_mqtt_stop();

    g_mqtt_client = esp_mqtt_client_init(config);

    if (g_mqtt_client == NULL) {
        ESP_LOGE(TAG, "mqtt client init error 0x%x", err);
        return -1;
    }

    err = esp_mqtt_client_register_event(g_mqtt_client, ESP_EVENT_ANY_ID, __qmsd_mqtt_event_handler, NULL);
    if (err != ESP_OK)
    {
        ESP_LOGE(TAG, "mqtt client event faile");
        return err;
    }

    err = esp_mqtt_client_start(g_mqtt_client);
    if (err != ESP_OK)
    {
        ESP_LOGE(TAG, "mqtt client start error 0x%x", err);
    }
    return err;
}

int qmsd_mqtt_stop(void)
{
    esp_err_t err = ESP_FAIL;

    if (g_mqtt_client)
    {
        err = esp_mqtt_client_disconnect(g_mqtt_client);
        if (err != ESP_OK)
        {
            ESP_LOGE(TAG, "mqtt disconnect fail! 0x%x", err);
        }

        err = esp_mqtt_client_stop(g_mqtt_client);
        if (err != ESP_OK)
        {
            ESP_LOGE(TAG, "mqtt stop fail! 0x%x", err);
        }

        esp_mqtt_client_destroy(g_mqtt_client);
        g_mqtt_client = NULL;
    }

    return err;
}

int qmsd_mqtt_pub(const char *topic, const char *data, int len, const int qos, const int retain)
{
    int msg_id = -1;
    if (g_mqtt_client)
    {
        msg_id = esp_mqtt_client_publish(g_mqtt_client, topic, data, len, qos, retain);
        if (msg_id == -1)
        {
            ESP_LOGE(TAG, "mqtt publish(%s) fail! %d", topic, msg_id);
        }
    }

    return msg_id;
}

int qmsd_mqtt_sub(const char *topic, int qos)
{
    int msg_id = -1;
    if (g_mqtt_client)
    {
        msg_id = esp_mqtt_client_subscribe(g_mqtt_client, topic, qos);
        if (msg_id == -1)
        {
            ESP_LOGE(TAG, "mqtt subscribe(%s) fail!", topic);
        }
    }

    return msg_id;
}

int qmsd_mqtt_unsub(const char *topic)
{
    int msg_id = -1;
    if (g_mqtt_client)
    {
        msg_id = esp_mqtt_client_unsubscribe(g_mqtt_client, topic);
        if (msg_id == -1)
        {
            ESP_LOGE(TAG, "mqtt unsubscribe(%s) fail! %d", topic, msg_id);
        }
    }

    return msg_id;
}
