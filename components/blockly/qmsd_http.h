#ifndef __QMSD_HTTP_H
#define __QMSD_HTTP_H

typedef int (*_qmsd_http_cb_t)(char* data);
void qmsd_httprequest(const char* url,const char* port,const char* path);
void qmsd_set_http_cb(_qmsd_http_cb_t cb);

#endif