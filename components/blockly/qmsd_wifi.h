#ifndef __QMSD_WIFI_H
#define __QMSD_WIFI_H

void qmsd_wifi_connect(const char* ssid,const char* password,int type);
void qmsd_wifi_set_sta_config(const char* ssid,const char* password, uint8_t enable);
void qmsd_wifi_start_sta(void);
void qmsd_wifi_stop_sta(void);
void qmsd_wifi_clear_config(void);
void qmsd_wifi_scan(void);
void qmsd_wifi_reconnect(void);

#endif