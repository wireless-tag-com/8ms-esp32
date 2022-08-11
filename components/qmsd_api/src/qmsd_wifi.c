#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "freertos/queue.h"
#include "esp_system.h"
#include "esp_event.h"
#include "esp_log.h"
#include "lwip/err.h"
#include "lwip/sys.h"
#include "lwip/sockets.h"

#include "qmsd_api.h"
#include "qmsd_wifi.h"
#include "qmsd_notifier.h"

#define QMSD_SCAN_LIST_MAX_SIZE 128

#define WIFI_CONNECTED_BIT BIT0
#define WIFI_FAIL_BIT BIT1
#define SARTCONFIG_DONE_BIT BIT2

#define QMSD_WIFI_CONFIG_LEN    (sizeof(wifi_config_t) + 1)

extern esp_err_t qmsd_storage_get_u8(const char *namespace, const char *key, uint8_t *value);
extern esp_err_t qmsd_storage_set_u8(const char *namespace, const char* key,uint8_t input);
extern esp_err_t qmsd_storage_set_blob(const char *name, const char *key, void *data, size_t length);
extern esp_err_t qmsd_storage_get_blob(const char *name, const char *key, void *data, size_t length);

static esp_err_t __qmsd_wifi_connect(void);
static const char *TAG = "QMSD_WIFI";
static EventGroupHandle_t qmsd_wifi_event_group = NULL;

static TaskHandle_t sc_task_handle = NULL;

static esp_netif_t *esp_netif_sta = NULL;
static esp_netif_t *esp_netif_ap = NULL;
static esp_timer_handle_t wifi_connect_timer = NULL;

typedef enum qmsd_wifi_state
{
    QMSD_WIFI_NO_CONNECT = 0,
    QMSD_WIFI_GOT_IP,
    QMSD_WIFI_CONNECTING,
    QMSD_WIFI_DISCONNECT,
    QMSD_WIFI_POWER_ON_CONNECT,
} qmsd_wifi_state_t;
static qmsd_wifi_state_t wifi_state = QMSD_WIFI_NO_CONNECT;

/**
 * WiFi disconnect reason
 */
static uint8_t reason = 0;

/**
 * WiFi retry connect when disconnect
 */
static int retry_num = 0;

esp_err_t qmsd_wifi_sta_config(const char *ssid, const char *password, const char *bssid);

static esp_err_t __qmsd_save_mode(uint8_t mode)
{
    return qmsd_storage_set_u8(QMSD_WIFI_NAME, QMSD_WIFI_MODE, mode);
}

static esp_err_t __qmsd_get_mode(uint8_t *mode)
{
    return qmsd_storage_get_u8(QMSD_WIFI_NAME, QMSD_WIFI_MODE, mode);
}

static esp_err_t __qmsd_save_wifi_config(void *data, size_t length)
{
    return qmsd_storage_set_blob(QMSD_WIFI_NAME, QMSD_WIFI_CONFIG, data, length);
}

static esp_err_t __qmsd_get_wifi_config(void *data, size_t length)
{
    return qmsd_storage_get_blob(QMSD_WIFI_NAME, QMSD_WIFI_CONFIG, data, length);
}

static void __wifi_timer_callback(void *arg)
{
    ESP_LOGI(TAG, "retry connect timer called, retry connect wifi");
    esp_wifi_connect();
}

esp_err_t qmsd_wifi_get_scan_result(uint16_t *number, wifi_ap_record_t *ap_records)
{
    esp_err_t err = ESP_FAIL;
    err = esp_wifi_scan_get_ap_records(number, ap_records);
    if (err != ESP_OK)
    {
        ESP_LOGE(TAG, "wifi scan get ap records %d", err);
        return err;
    }

    return err;
}

static void __qmsd_event_handler(void *arg, esp_event_base_t event_base,
                                 int32_t event_id, void *event_data)
{
    if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_START)
    {
        ESP_LOGI(TAG, "WIFI_EVENT_STA_START");
    }
    else if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_CONNECTED)
    {
        ESP_LOGI(TAG, "WIFI_EVENT_STA_CONNECTED");
    }
    else if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_DISCONNECTED)
    {
        wifi_event_sta_disconnected_t *disconnected = (wifi_event_sta_disconnected_t *)event_data;
        ESP_LOGI(TAG, "STA disconnect reason %d", disconnected->reason);
        reason = disconnected->reason;

        if (wifi_state == QMSD_WIFI_CONNECTING)
        {
            if (retry_num < QMSD_WIFI_CONNECT_RETRY)
            {
                esp_wifi_connect();
                retry_num++;
                ESP_LOGI(TAG, "retry to connect to the AP");
            }
            else
            {
                retry_num = 0;
                qmsd_notifier_call_nolock(QMSD_WIFI_STA_DISCONNECT, event_data);
                xEventGroupSetBits(qmsd_wifi_event_group, WIFI_FAIL_BIT);
                ESP_LOGW(TAG, "connect to the AP fail");
            }
        }
        else if (wifi_state == QMSD_WIFI_GOT_IP)
        {
            if (retry_num < QMSD_WIFI_CONNECT_RETRY)
            {
                esp_wifi_connect();
                retry_num++;
                ESP_LOGI(TAG, "retry to connect to the AP");
            }
            else
            {
                retry_num = 0;
                if (reason == WIFI_REASON_NO_AP_FOUND)
                {
                    if (wifi_connect_timer != NULL)
                    {
                        esp_timer_stop(wifi_connect_timer);
                        esp_timer_delete(wifi_connect_timer);
                        wifi_connect_timer = NULL;
                    }
                    const esp_timer_create_args_t oneshot_timer_args = {
                        .callback = &__wifi_timer_callback,
                        .name = "wifi retry connect",
                    };
                    esp_timer_create(&oneshot_timer_args, &wifi_connect_timer);
                    esp_timer_start_once(wifi_connect_timer, 10000000);
                    ESP_LOGI(TAG, "retry connect to the AP after 10s");
                }
                qmsd_notifier_call_nolock(QMSD_WIFI_STA_DISCONNECT, event_data);
                xEventGroupSetBits(qmsd_wifi_event_group, WIFI_FAIL_BIT);
                ESP_LOGW(TAG, "disconnect to the AP %d", reason);
            }
        }
        else
        {
            ESP_LOGW(TAG, "disconnect to the AP");
            qmsd_notifier_call_nolock(QMSD_WIFI_STA_DISCONNECT, event_data);
            xEventGroupClearBits(qmsd_wifi_event_group, WIFI_CONNECTED_BIT);
            xEventGroupSetBits(qmsd_wifi_event_group, WIFI_FAIL_BIT);
        }
    }
    else if (event_base == IP_EVENT && event_id == IP_EVENT_STA_GOT_IP)
    {
        if (wifi_connect_timer != NULL)
        {
            esp_timer_stop(wifi_connect_timer);
            esp_timer_delete(wifi_connect_timer);
            wifi_connect_timer = NULL;
        }

        qmsd_notifier_call_nolock(QMSD_WIFI_STA_GOT_IP, event_data);
        retry_num = 0;
        wifi_state = QMSD_WIFI_GOT_IP;

        xEventGroupClearBits(qmsd_wifi_event_group, WIFI_FAIL_BIT);
        xEventGroupSetBits(qmsd_wifi_event_group, WIFI_CONNECTED_BIT);
    }
    else if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_SCAN_DONE)
    {
        wifi_event_sta_scan_done_t *event = (wifi_event_sta_scan_done_t *)event_data;
        if (event->status == 0)
        {
            ESP_LOGI(TAG, "wifi scan number %d", event->number);
            if (event->number > 0) {
                struct qmsd_wifi_scan_res res;
                res.ap_info = malloc(sizeof(wifi_ap_record_t) * event->number);
                if (res.ap_info) {
                    res.number = event->number;
                    esp_err_t err = qmsd_wifi_get_scan_result(&(res.number), res.ap_info);
                    if (err == ESP_OK)
                    {
                        qmsd_notifier_call_nolock(QMSD_WIFI_SCAN_DONE, &res);
                    }
                    else
                    {
                        ESP_LOGE(TAG, "get ap records err 0x%x", err);
                    }

                    free(res.ap_info);
                } else {
                    ESP_LOGI(TAG, "wifi scan no memory for scan result");
                }
            }
        }
        else
        {
            ESP_LOGW(TAG, "scan not found ");
            qmsd_notifier_call_nolock(QMSD_WIFI_SCAN_DONE, NULL);
        }
    }
    else if (event_base == SC_EVENT && event_id == SC_EVENT_SCAN_DONE)
    {
        ESP_LOGI(TAG, "Scan done");
    }
    else if (event_base == SC_EVENT && event_id == SC_EVENT_FOUND_CHANNEL)
    {
        ESP_LOGI(TAG, "Found channel");
    }
    else if (event_base == SC_EVENT && event_id == SC_EVENT_GOT_SSID_PSWD)
    {
        ESP_LOGI(TAG, "Got SSID and password");
        smartconfig_event_got_ssid_pswd_t *evt = (smartconfig_event_got_ssid_pswd_t *)event_data;
        wifi_config_t *wifi_config;
        char buf[QMSD_WIFI_CONFIG_LEN] = {0};

        wifi_config = (wifi_config_t *)buf;
        memcpy(wifi_config->sta.ssid, evt->ssid, sizeof(wifi_config->sta.ssid));
        memcpy(wifi_config->sta.password, evt->password, sizeof(wifi_config->sta.password));
        wifi_config->sta.bssid_set = evt->bssid_set;
        if (wifi_config->sta.bssid_set == true) {
            memcpy(wifi_config->sta.bssid, evt->bssid, sizeof(wifi_config->sta.bssid));
        }

        ESP_LOGI(TAG, "SSID:%s", evt->ssid);
        ESP_LOGI(TAG, "PASSWORD:%s", evt->password);
        if (evt->type == SC_TYPE_ESPTOUCH_V2)
        {
            uint8_t rvd_data[33] = { 0 };
            ESP_ERROR_CHECK(esp_smartconfig_get_rvd_data(rvd_data, sizeof(uint8_t) * 33));
        }

        __qmsd_save_wifi_config(buf, QMSD_WIFI_CONFIG_LEN);
        __qmsd_save_mode(WIFI_MODE_STA);
        esp_wifi_set_config(WIFI_IF_STA, wifi_config);
        __qmsd_wifi_connect();
    }
    else if (event_base == SC_EVENT && event_id == SC_EVENT_SEND_ACK_DONE)
    {
        xEventGroupSetBits(qmsd_wifi_event_group, SARTCONFIG_DONE_BIT);
    }
    else if (event_id == WIFI_EVENT_AP_STACONNECTED)
    {
        wifi_event_ap_staconnected_t *event = (wifi_event_ap_staconnected_t *)event_data;
        ESP_LOGI(TAG, "station " MACSTR " join, AID=%d",
                 MAC2STR(event->mac), event->aid);
    }
    else if (event_id == WIFI_EVENT_AP_STADISCONNECTED)
    {
        wifi_event_ap_stadisconnected_t *event = (wifi_event_ap_stadisconnected_t *)event_data;
        ESP_LOGI(TAG, "station " MACSTR " leave, AID=%d",
                 MAC2STR(event->mac), event->aid);
    }
}

static void __qmsd_smartconfig_task(void *parm)
{
    xEventGroupClearBits(qmsd_wifi_event_group, WIFI_CONNECTED_BIT);
    xEventGroupClearBits(qmsd_wifi_event_group, WIFI_FAIL_BIT);
    xEventGroupClearBits(qmsd_wifi_event_group, SARTCONFIG_DONE_BIT);
    EventBits_t uxBits;
    ESP_ERROR_CHECK(esp_smartconfig_set_type((smartconfig_type_t)parm));
    smartconfig_start_config_t cfg = SMARTCONFIG_START_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_smartconfig_start(&cfg));
    while (1)
    {
        uxBits = xEventGroupWaitBits(qmsd_wifi_event_group, WIFI_CONNECTED_BIT | SARTCONFIG_DONE_BIT, true, false, portMAX_DELAY);
        if (uxBits & WIFI_CONNECTED_BIT)
        {
            ESP_LOGI(TAG, "WiFi Connected to ap");
        }
        if (uxBits & SARTCONFIG_DONE_BIT)
        {
            ESP_LOGI(TAG, "smartconfig over");
            esp_smartconfig_stop();
            vTaskDelete(NULL);
        }
    }
}

void qmsd_wifi_sc_start(smartconfig_type_t type)
{
    esp_wifi_set_mode(WIFI_MODE_STA);
    esp_wifi_stop();
    esp_wifi_start();
    xTaskCreate(__qmsd_smartconfig_task, "qmsd_smartconfig_task", 4096, (void *)type, 3, &sc_task_handle);
}

void qmsd_wifi_sc_stop(void)
{
    xEventGroupSetBits(qmsd_wifi_event_group, SARTCONFIG_DONE_BIT);
}

esp_err_t qmsd_wifi_get_ip(wifi_interface_t interface, char *ip, char *gw, char *netmask)
{
    esp_err_t err = ESP_FAIL;
    esp_netif_ip_info_t ip_info;
    if (interface == WIFI_IF_STA)
    {
        err = esp_netif_get_ip_info(esp_netif_sta, &ip_info);
        if (err != ESP_OK)
        {
            ESP_LOGE(TAG, "get sta ip info error %s", esp_err_to_name(err));
            return ESP_FAIL;
        }
    }
    else if (interface == WIFI_IF_AP)
    {
        err = esp_netif_get_ip_info(esp_netif_ap, &ip_info);
        if (err != ESP_OK)
        {
            ESP_LOGE(TAG, "get ap ip info error %s", esp_err_to_name(err));
            return ESP_FAIL;
        }
    }
    else
    {
        ESP_LOGE(TAG, "wifi interface err");
        return ESP_FAIL;
    }

    esp_ip4addr_ntoa(&ip_info.ip, ip, IP4ADDR_STRLEN_MAX);
    esp_ip4addr_ntoa(&ip_info.gw, gw, IP4ADDR_STRLEN_MAX);
    esp_ip4addr_ntoa(&ip_info.netmask, netmask, IP4ADDR_STRLEN_MAX);

    return err;
}

esp_err_t qmsd_wifi_scan(char *ssid, bool block)
{
    esp_err_t err = ESP_FAIL;
    wifi_scan_config_t scan_config = {0};

    if (ssid != NULL)
        scan_config.ssid = (uint8_t *)ssid;

    err = esp_wifi_scan_start(&scan_config, block);
    if (err != ESP_OK)
    {
        ESP_LOGE(TAG, "wifi scan error %s", esp_err_to_name(err));
    }

    return err;
}

esp_err_t qmsd_wifi_disconnect(void)
{
    esp_err_t err = ESP_FAIL;
    wifi_state = QMSD_WIFI_DISCONNECT;
    err = esp_wifi_disconnect();
    if (err != ESP_OK)
        ESP_LOGE(TAG, "wifi disconnect error %s", esp_err_to_name(err));

    return err;
}

static esp_err_t __qmsd_wifi_connect(void)
{
    esp_err_t err = ESP_FAIL;
    if (wifi_state == QMSD_WIFI_GOT_IP)
    {
        err = qmsd_wifi_disconnect();
    }

    wifi_state = QMSD_WIFI_CONNECTING;
    err = esp_wifi_connect();
    if (err != ESP_OK)
        ESP_LOGE(TAG, "wifi connect error %s", esp_err_to_name(err));

    return err;
}

esp_err_t qmsd_wifi_set_mode(wifi_mode_t mode)
{
    esp_err_t err = ESP_FAIL;
    err = esp_wifi_set_mode(mode);
    if (err != ESP_OK)
        ESP_LOGE(TAG, "wifi set mode %d fail err %s", mode, esp_err_to_name(err));

    if (mode == WIFI_MODE_NULL)
    {
        err = esp_wifi_stop();
        if (err != ESP_OK)
            ESP_LOGE(TAG, "wifi stop err %s", esp_err_to_name(err));
    }
    else
    {
        err = esp_wifi_start();
        if (err != ESP_OK)
            ESP_LOGE(TAG, "wifi start err %s", esp_err_to_name(err));
    }

    if (err == ESP_OK)
    {
        if (__qmsd_save_mode(mode) != ESP_OK)
            ESP_LOGE(TAG, "save wifi mode error");
    }

    return err;
}

esp_err_t qmsd_wifi_save_config(wifi_mode_t mode, wifi_interface_t interface)
{
    wifi_config_t *wifi_config;
    char buf[QMSD_WIFI_CONFIG_LEN] = {0};
    esp_err_t err = ESP_OK;

    wifi_config = (wifi_config_t *)buf;
    if (esp_wifi_get_config(interface, wifi_config) == ESP_OK)
    {
        err = __qmsd_save_wifi_config(buf, QMSD_WIFI_CONFIG_LEN);
        if (err != ESP_OK) {
            ESP_LOGE(TAG, "save wifi config error");
            return err;
        }
        
    }
    else
    {
        ESP_LOGE(TAG, "get wifi config error");
    }
    __qmsd_save_mode(mode);

    return err;
}

esp_err_t qmsd_wifi_sta_config(const char *ssid, const char *password, const char *bssid)
{
    esp_err_t err = ESP_FAIL;
    wifi_config_t *wifi_config;
    char buf[QMSD_WIFI_CONFIG_LEN] = {0};

    wifi_config = (wifi_config_t *)buf;
    
	esp_wifi_set_mode(WIFI_MODE_STA);

    if (bssid != NULL)
    {
        wifi_config->sta.bssid_set = true;
        memcpy(wifi_config->sta.bssid, bssid, sizeof(wifi_config->sta.bssid));
    }
    memcpy(wifi_config->sta.ssid, ssid, strlen(ssid));
    memcpy(wifi_config->sta.password, password, strlen(password));
    err = esp_wifi_set_config(WIFI_IF_STA, wifi_config);
    if (err != ESP_OK)
        ESP_LOGE(TAG, "sta wifi set config err %s", esp_err_to_name(err));

    __qmsd_save_wifi_config(buf, QMSD_WIFI_CONFIG_LEN);
    __qmsd_save_mode(WIFI_MODE_STA);

    err = __qmsd_wifi_connect();

    return err;
}

esp_err_t qmsd_wifi_ap_config(char *ssid, char *password)
{
    esp_err_t err = ESP_FAIL;
    wifi_config_t wifi_config = {
        .ap = {
            .ssid_len = strlen(ssid),
            .channel = QMSD_WIFI_CHANNEL,
            .max_connection = QMSD_MAX_STA_CONN,
            .authmode = WIFI_AUTH_WPA_WPA2_PSK,
        },
    };
    memcpy(wifi_config.ap.ssid, ssid, strlen(ssid));
    memcpy(wifi_config.ap.password, password, strlen(password));
    if (strlen(password) == 0)
    {
        wifi_config.ap.authmode = WIFI_AUTH_OPEN;
    }

    err = esp_wifi_set_config(WIFI_IF_AP, &wifi_config);
    if (err != ESP_OK)
        ESP_LOGE(TAG, "ap wifi set config err %s", esp_err_to_name(err));

    qmsd_wifi_save_config(WIFI_MODE_AP, WIFI_IF_AP);

    return err;
}

static esp_err_t __qmsd_wifi_power_on_connect()
{
    esp_err_t err = ESP_FAIL;
    uint8_t mode;

    if (__qmsd_get_mode(&mode) == ESP_OK)
    {
        err = esp_wifi_set_mode(WIFI_MODE_STA);
        if (err == ESP_OK) {
            wifi_config_t *wifi_config;
            char buf[QMSD_WIFI_CONFIG_LEN] = {0};
            size_t len = QMSD_WIFI_CONFIG_LEN;
    
            if (__qmsd_get_wifi_config(buf, len) == ESP_OK) {
                wifi_config = (wifi_config_t *)buf;
                printf("coonect\n");
                esp_wifi_set_config(WIFI_IF_STA, wifi_config);
                __qmsd_wifi_connect();
            }
        }
    }

    return err;
}

uint8_t qmsd_wifi_wait_connect(void)
{
    esp_err_t err = ESP_FAIL;
    uint8_t res = 0;
    xEventGroupClearBits(qmsd_wifi_event_group, WIFI_CONNECTED_BIT);
    xEventGroupClearBits(qmsd_wifi_event_group, WIFI_FAIL_BIT);

    wifi_config_t wifi_sta_config = {0};
    err = esp_wifi_get_config(WIFI_IF_STA, &wifi_sta_config);
    if (err != ESP_OK)
    {
        ESP_LOGE(TAG, "wifi get config error %d", err);
        return err;
    }

    EventBits_t bits = xEventGroupWaitBits(qmsd_wifi_event_group,
                                           WIFI_CONNECTED_BIT | WIFI_FAIL_BIT,
                                           pdFALSE,
                                           pdFALSE,
                                           portMAX_DELAY);

    if (bits & WIFI_CONNECTED_BIT)
    {
        ESP_LOGI(TAG, "connected to ap SSID:%s password:%s",
                 wifi_sta_config.sta.ssid, wifi_sta_config.sta.password);
    }
    else if (bits & WIFI_FAIL_BIT)
    {
        res = reason;
        ESP_LOGI(TAG, "Failed to connect to SSID:%s, password:%s",
                 wifi_sta_config.sta.ssid, wifi_sta_config.sta.password);
    }
    else
    {
        ESP_LOGE(TAG, "UNEXPECTED EVENT");
    }
    return res;
}

esp_err_t qmsd_wifi_init(bool auto_connect)
{
    esp_err_t err = ESP_FAIL;
    qmsd_wifi_event_group = xEventGroupCreate();

    ESP_ERROR_CHECK(esp_netif_init());
    esp_netif_sta = esp_netif_create_default_wifi_sta();
    esp_netif_ap = esp_netif_create_default_wifi_ap();

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));

    esp_event_handler_instance_t instance_any_wifi;
    esp_event_handler_instance_t instance_got_ip;
    esp_event_handler_instance_t instance_any_sc;
    ESP_ERROR_CHECK(esp_event_handler_instance_register(WIFI_EVENT,
                                                        ESP_EVENT_ANY_ID,
                                                        &__qmsd_event_handler,
                                                        NULL,
                                                        &instance_any_wifi));
    ESP_ERROR_CHECK(esp_event_handler_instance_register(IP_EVENT,
                                                        IP_EVENT_STA_GOT_IP,
                                                        &__qmsd_event_handler,
                                                        NULL,
                                                        &instance_got_ip));
    ESP_ERROR_CHECK(esp_event_handler_instance_register(SC_EVENT,
                                                        ESP_EVENT_ANY_ID,
                                                        &__qmsd_event_handler,
                                                        NULL,
                                                        &instance_any_sc));

    esp_wifi_set_ps(WIFI_PS_NONE);

    ESP_ERROR_CHECK(esp_wifi_start());

    if (auto_connect) {
        err = __qmsd_wifi_power_on_connect();
        if (err != ESP_OK)
            ESP_LOGW(TAG, "wifi power on connect %s", esp_err_to_name(err));
    }

    return ESP_OK;
}
