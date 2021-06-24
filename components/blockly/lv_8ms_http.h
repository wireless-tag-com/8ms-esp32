#ifndef __LV_8MS_HTTP_H
#define __LV_8MS_HTTP_H
typedef int (*_8ms_http_cb_t)(char* data);
void lv_8ms_httprequest(const char* url,const char* port,const char* path);
void lv_8ms_set_http_cb(_8ms_http_cb_t cb);
#endif