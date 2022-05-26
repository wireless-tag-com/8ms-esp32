#ifndef __QMSD_WIFI_H__
#define __QMSD_WIFI_H__

#include "lwip/ip4_addr.h"
#include "esp_smartconfig.h"
#include "esp_wifi.h"

#define QMSD_STA_POWER_SAVE WIFI_PS_NONE
#define QMSD_WIFI_CONNECT_RETRY 3
#define QMSD_WIFI_CHANNEL 1
#define QMSD_MAX_STA_CONN 5

/*qmsd wifi config*/
#define QMSD_WIFI_NAME "wifi"
#define QMSD_WIFI_CONFIG "config"
#define QMSD_WIFI_MODE "mode"

esp_err_t qmsd_wifi_set_mode(wifi_mode_t mode);
esp_err_t qmsd_wifi_init(bool auto_connect);
esp_err_t qmsd_wifi_sta_config(const char *ssid, const char *password, const char *bssid);
esp_err_t qmsd_wifi_ap_config(char *ssid, char *password);
void qmsd_wifi_sc_start(smartconfig_type_t type);
void qmsd_wifi_sc_stop(void);
esp_err_t qmsd_wifi_get_ip(wifi_interface_t interface, char *ip, char *gw, char *netmask);
esp_err_t qmsd_wifi_get_scan_result(uint16_t *number, wifi_ap_record_t *ap_records);
esp_err_t qmsd_wifi_save_config(wifi_mode_t mode, wifi_interface_t interface);

#endif
