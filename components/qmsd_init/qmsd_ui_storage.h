#ifndef __QMSD_UI_STORAGE_H__
#define __QMSD_UI_STORAGE_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include "cJSON.h"

typedef void (*qmsd_ui_storage_list_cb)(void *val, int index);
cJSON *qmsd_ui_storage_init(const char *filename, bool create);
int qmsd_ui_storage_set_int(const cJSON *json, const char *key, const int val);
int qmsd_ui_storage_get_array_size(const cJSON *json, const char *key, int *size);
int qmsd_ui_storage_set_int_array(const cJSON *json, const char *key, const int *val, int count);
int qmsd_ui_storage_set_double_array(const cJSON *json, const char *key, const double *val, int count);
int qmsd_ui_storage_set_str_array(const cJSON *json, const char *key, const char **val, int count);
int qmsd_ui_storage_list_int_array(const cJSON *json, const char *key, qmsd_ui_storage_list_cb cb);
int qmsd_ui_storage_list_double_array(const cJSON *json, const char *key, qmsd_ui_storage_list_cb cb);
int qmsd_ui_storage_list_str_array(const cJSON *json, const char *key, qmsd_ui_storage_list_cb cb);
int qmsd_ui_storage_get_int(const cJSON *json, const char *key, int *val);
int qmsd_ui_storage_set_double(const cJSON *json, const char *key, const double val);
int qmsd_ui_storage_get_double(const cJSON *json, const char *key, double *val);
int qmsd_ui_storage_set_bool(const cJSON *json, const char *key, const bool val);
int qmsd_ui_storage_get_bool(const cJSON *json, const char *key, bool *val);
int qmsd_ui_storage_set_str(const cJSON *json, const char *key, const char *val);
char *qmsd_ui_storage_get_str(const cJSON *json, const char *key);
int qmsd_ui_storage_save(cJSON *json, const char *filename);
void qmsd_ui_storage_deinit(cJSON *json);

#ifdef __cplusplus
}
#endif

#endif
