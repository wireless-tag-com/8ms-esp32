#ifndef __QMSD_OTA_H
#define __QMSD_OTA_H

int ota_set_url(const char *url);
void ota_start(const char *url);
void ota_clear_url(void);

#endif