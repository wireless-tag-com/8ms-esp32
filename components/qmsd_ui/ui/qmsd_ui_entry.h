#ifndef QMSD_UI_ENTRY_H
#define QMSD_UI_ENTRY_H

#ifdef __cplusplus
extern "C" {
#endif


#include "lvgl/lvgl.h"

LV_IMG_DECLARE(img1639365041009_png);

extern lv_obj_t *screen_main;
extern lv_obj_t* screen_main_button_1;
extern lv_obj_t* screen_main_label_1;

extern lv_obj_t *screen_test;
extern lv_obj_t* screen_test_button_1;
extern lv_obj_t* screen_test_img_1;

extern lv_obj_t *screen_test2;
extern lv_obj_t* screen_test2_button_1;

void screen_main_build(void);
void screen_main_delete(void);
void screen_test_build(void);
void screen_test_delete(void);

void qmsd_ui_entry(void);
lv_obj_t *qmsd_get_screen(const char *name);
lv_obj_t *qmsd_get_widget(const char *w_name);
const char *qmsd_get_obj_name(lv_obj_t *obj);
lv_img_src_t *qmsd_get_img(const char *w_name);

typedef void (*qmsd_ui_event_cb)(const char *obj_name, lv_obj_t* obj,lv_event_t event);
void qmsd_set_ui_event_cb(qmsd_ui_event_cb init_cb);
void qmsd_call_ui_event_cb(const char *obj_name, lv_obj_t* obj,lv_event_t event);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*QMSD_UI_ENTRY_H*/
