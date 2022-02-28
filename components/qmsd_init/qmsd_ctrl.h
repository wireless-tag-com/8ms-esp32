#ifndef __QMSD_CTRL_H
#define __QMSD_CTRL_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C"
{
#endif

typedef lv_obj_t *(*__qmsd_get_screen)(const char *name);
typedef lv_obj_t *(*__qmsd_get_widget)(const char *name);
typedef lv_img_src_t *(*__qmsd_get_img)(const char *name);
typedef lv_font_t *(*__qmsd_get_font)(const char *name);

/*
 * call from other task, sync be false
 * if sync to true, will wait for gui task
 */
int qmsd_ctrl_str(const char *json_str, bool sync);

/*
 * call from gui task, no need lock
 */
char *qmsd_ctrl_str_gui(const char *json_str);

/*
 * call from other task, sync be false
 * if sync to true, will wait for gui task
 */
int qmsd_ctrl_cjson(const char *wid, qmsd_ctrl_type type, const cJSON *attr, bool sync);

/*
 * call from gui task, no need lock
 */
int qmsd_ctrl_cjson_gui(const char *wid, qmsd_ctrl_type type, const cJSON *attr);

void qmsd_set_screen(__qmsd_get_screen get_screen);
void qmsd_set_widget(__qmsd_get_widget get_widget);
void qmsd_set_img(__qmsd_get_img get_img);
void qmsd_set_font(__qmsd_get_font get_font);
lv_img_src_t *qmsd_ctrl_get_img(const char *name);
lv_font_t *qmsd_ctrl_get_font(const char *name);
void mqtt_app_start(void *pvParameters);
#ifdef __cplusplus
}
#endif

#endif //__QMSD_CTRL_H