#ifndef __LV_8MS_WIFI_H
#define __LV_8MS_WIFI_H

/**
 * @brief wifi连接
 * 
 * @param ssid     wifi的名称
 * @param password wifi的密码
 * @param type     设置wifi操作模式
 */
void lv_8ms_wifi_connect(const char* ssid,const char* password,int type);
#endif