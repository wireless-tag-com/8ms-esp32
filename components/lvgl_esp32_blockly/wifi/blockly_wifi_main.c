#include "blockly_wifi.h"
#include "esp_log.h"
#include "../blufi/blockly_blufi.h"
#include "freertos/task.h"

static const char *TAG = "blockly_wifi";

/* FreeRTOS event group to signal when we are connected & ready to make a request */
static EventGroupHandle_t wifi_event_group;

/* The event group allows multiple bits for each event,
   but we only care about one event - are we connected
   to the AP with an IP? */
const int CONNECTED_BIT = BIT0;

/* store the station info for send back to phone */
bool gl_sta_connected = false;

/*wifi积木块开启标志位 true：开启；false：关闭*/
bool blockly_wifi_flag = false;

bool callback_switch = false;

static esp_err_t example_net_event_handler(void *ctx, system_event_t *event)
{

    switch (event->event_id) {
    case SYSTEM_EVENT_STA_START:
        esp_wifi_connect();
        break;
    case SYSTEM_EVENT_STA_GOT_IP: 
        xEventGroupSetBits(wifi_event_group, CONNECTED_BIT);
        user_blufi_event_sta_got_ip_handle();
        break;
    case SYSTEM_EVENT_STA_CONNECTED:
        gl_sta_connected = true;
        user_blufi_event_sta_connected_handle(event);
        break; 
    case SYSTEM_EVENT_STA_DISCONNECTED:
        /* This is a workaround as ESP32 WiFi libs don't currently
           auto-reassociate. */
        gl_sta_connected = false;
        user_blufi_event_sta_disconnected_handle();
        esp_wifi_connect();
        xEventGroupClearBits(wifi_event_group, CONNECTED_BIT);
        break;
    case SYSTEM_EVENT_AP_START:
        user_blufi_event_ap_start_handle();
        break;
    case SYSTEM_EVENT_SCAN_DONE: 
        user_blufi_event_scan_done_handle();
        break;
    default:
        break;
    }
    return ESP_OK;
}

void wifi_init_sta()
{
    tcpip_adapter_init();
    wifi_event_group = xEventGroupCreate();
    ESP_ERROR_CHECK( esp_event_loop_init(example_net_event_handler, NULL) );
    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK( esp_wifi_init(&cfg) );
    ESP_ERROR_CHECK( esp_wifi_set_mode(WIFI_MODE_STA) );
    ESP_ERROR_CHECK( esp_wifi_start() );
}

void blockly_wifi_init()
{
    blockly_wifi_flag = true;
    ESP_LOGI(TAG, "ESP_WIFI_MODE_STA");
    wifi_init_sta();
}

__attribute__((weak)) void wifi_callback(void)
{
    printf("234\n");
}

void wifi_callback_again()
{
    callback_switch = false;
}

void blockly_wifi_loop(void)
{
    if (gl_sta_connected && callback_switch != gl_sta_connected)
    {
        callback_switch = gl_sta_connected;
        vTaskDelay(100 / portTICK_PERIOD_MS);
        wifi_callback();
    }
    
}
