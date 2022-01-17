#ifndef QM_UI_ENTRY_H
#define QM_UI_ENTRY_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>

#include "lvgl/lvgl.h"
#include "qmsd_lang.h"
#include "qmsd_gui.h"
LV_FONT_DECLARE(ali_font_16);
LV_FONT_DECLARE(ali_font_10);
LV_FONT_DECLARE(ali_font_27);
LV_FONT_DECLARE(ali_font_11);
LV_FONT_DECLARE(ali_font_13);
LV_FONT_DECLARE(ali_font_14);

LV_IMG_DECLARE(imgsun_png);
LV_IMG_DECLARE(imgwifi_png);
LV_IMG_DECLARE(imgscreen_curtain_png);
LV_IMG_DECLARE(imgscreen_contrl_png);
LV_IMG_DECLARE(imgscreen_condition_png);
LV_IMG_DECLARE(imgscreen_light_png);
LV_IMG_DECLARE(imgcontrl_light_png);
LV_IMG_DECLARE(imgconditioner_png);
LV_IMG_DECLARE(imglight_png);
LV_IMG_DECLARE(imgcurtain_png);

/*
* declear screen_main
*/
extern lv_obj_t * screen_main;
extern lv_obj_t * label_black;
extern lv_obj_t * image_wifi;
extern lv_obj_t * label_weather;
extern lv_obj_t * label_temperature;
extern lv_obj_t * label_time;
extern lv_obj_t * image_sun;
extern lv_obj_t * label_date;
extern lv_obj_t * label_weekend;
extern lv_obj_t * button_light;
extern lv_obj_t * __button_light_label;
extern lv_obj_t * button_curtain;
extern lv_obj_t * __button_curtain_label;
extern lv_obj_t * button_conditioner;
extern lv_obj_t * __button_conditioner_label;
extern lv_obj_t * button_control;
extern lv_obj_t * __button_control_label;
extern lv_obj_t * image_light;
extern lv_obj_t * image_curtain;
extern lv_obj_t * image_condition;
extern lv_obj_t * image_control_light;
extern lv_obj_t * label_light;
extern lv_obj_t * label_conditioner;
extern lv_obj_t * label_contain;
extern lv_obj_t * label_control_light;
extern lv_obj_t * button_point1;
extern lv_obj_t * __button_point1_label;
extern lv_obj_t * button_point2;
extern lv_obj_t * __button_point2_label;
extern lv_obj_t * button_point4;
extern lv_obj_t * __button_point4_label;
extern lv_obj_t * button_point3;
extern lv_obj_t * __button_point3_label;
extern lv_obj_t * button_point5;
extern lv_obj_t * __button_point5_label;
extern lv_obj_t * label_curtain_data;
extern lv_obj_t * label_condition_data;
extern lv_obj_t * label_c544;
extern lv_obj_t * line_6fc1;
extern lv_obj_t * label_3c93;
extern lv_obj_t * label_min;
void screen_main_build(void);
void screen_main_show(void);
void screen_main_delete(void);
/*
* declear screen_light
*/
extern lv_obj_t * screen_light;
extern lv_obj_t * button_screen_light;
extern lv_obj_t * __button_screen_light_label;
void screen_light_build(void);
void screen_light_show(void);
void screen_light_delete(void);
/*
* declear screen_curtain
*/
extern lv_obj_t * screen_curtain;
extern lv_obj_t * button_screen_curtain;
extern lv_obj_t * __button_screen_curtain_label;
void screen_curtain_build(void);
void screen_curtain_show(void);
void screen_curtain_delete(void);
/*
* declear screen_condition
*/
extern lv_obj_t * screen_condition;
extern lv_obj_t * button_screen_condition;
extern lv_obj_t * __button_screen_condition_label;
void screen_condition_build(void);
void screen_condition_show(void);
void screen_condition_delete(void);
/*
* declear screen_control
*/
extern lv_obj_t * screen_control;
extern lv_obj_t * button_screen_control;
extern lv_obj_t * __button_screen_control_label;
void screen_control_build(void);
void screen_control_show(void);
void screen_control_delete(void);

void qmsd_ui_entry(void);
void qmsd_ui_loop(void);
lv_obj_t *qmsd_get_screen(const char *name);
lv_obj_t *qmsd_get_widget(const char *w_name);
const char *qmsd_get_obj_name(lv_obj_t *obj);
lv_img_src_t *qmsd_get_img(const char *w_name);

void g_create_kb_ifneeded(void);
void g_show_kb(void);
#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*QM_UI_ENTRY_H*/