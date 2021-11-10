#ifndef __LV_8MS_HTTP_H
#define __LV_8MS_HTTP_H
typedef int (*_8ms_http_cb_t)(char* data);
/**
 * @brief 发送Http请求
 * 
 * @param url  请求接口（网址）
 * @param port 要连接的端口
 * @param path 访问资源的路径
 */
void lv_8ms_httprequest(const char* url,const char* port,const char* path);

/**
 * @brief 设置http响应回调函数
 * 
 * @param cb 响应回调函数指针
 */
void lv_8ms_set_http_cb(_8ms_http_cb_t cb);
#endif