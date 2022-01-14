#ifndef __QMSD_LANG_H__
#define __QMSD_LANG_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "esp_system.h"
#include "nvs_flash.h"
#include "nvs.h"

#define QMSD_LANG_PARTITION  "qmsd_lang"

int qmsd_lang_set(const char *lang);
char *qmsd_lang_get(void);
int qmsd_lang_save(const char *lang);
int qmsd_lang_init(const char *lang);
char *qmsd_lang_get_trans(const char *key);
void qmsd_lang_deinit(void);
esp_err_t qmsd_lang_set_trans(const char *key, const char *val);

#ifdef __cplusplus
}
#endif

#endif
