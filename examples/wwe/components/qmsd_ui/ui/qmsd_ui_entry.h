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
LV_FONT_DECLARE(ali_font_54);
LV_FONT_DECLARE(ali_font_22);
LV_FONT_DECLARE(ali_font_23);
LV_FONT_DECLARE(ali_font_24);
LV_FONT_DECLARE(ali_font_27);
LV_FONT_DECLARE(ali_font_29);

LV_IMG_DECLARE(imgrobot_png);
LV_IMG_DECLARE(imgbase_bg_3_png);
LV_IMG_DECLARE(imgbase_bg_2_png);
LV_IMG_DECLARE(imgtheme_4_png);
LV_IMG_DECLARE(imgtheme_3_png);
LV_IMG_DECLARE(imgtheme_2_png);
LV_IMG_DECLARE(imgset_sound_png);
LV_IMG_DECLARE(imgset_theme_png);
LV_IMG_DECLARE(imgset_light_png);
LV_IMG_DECLARE(imgset_wifi_png);
LV_IMG_DECLARE(imgback_png);
LV_IMG_DECLARE(imgtop_set_png);
LV_IMG_DECLARE(imgtop_mode_png);
LV_IMG_DECLARE(imgwea_lighting_png);
LV_IMG_DECLARE(imgtop_home_png);
LV_IMG_DECLARE(imgb5_stop_png);
LV_IMG_DECLARE(imgb5_close_png);
LV_IMG_DECLARE(imgb5_open_png);
LV_IMG_DECLARE(imgbase_green_png);
LV_IMG_DECLARE(imgbase_light_png);
LV_IMG_DECLARE(imgbase_off_png);
LV_IMG_DECLARE(imgbaase_on_png);
LV_IMG_DECLARE(imgwifi_3_png);
LV_IMG_DECLARE(imgdesktop1_png);
LV_IMG_DECLARE(imgsun_png);

/*
* declear screen_main
*/
extern lv_obj_t * screen_main;
extern lv_obj_t * image_base;
extern lv_obj_t * tileview_2093;
extern lv_obj_t * cont_link_f61c;
void screen_main_build(void);
void screen_main_show(void);
void screen_main_delete(void);
/*
* declear main_tile_1
*/
extern lv_obj_t * main_tile_1;
extern lv_obj_t * label_main_time;
extern lv_obj_t * label_main_date;
extern lv_obj_t * image_0284;
extern lv_obj_t * image_c40b;
extern lv_obj_t * label_63b0;
extern lv_obj_t * image_ad04;
extern lv_obj_t * button_b1;
extern lv_obj_t * __button_b1_label;
extern lv_obj_t * button_b2;
extern lv_obj_t * __button_b2_label;
extern lv_obj_t * image_b1;
extern lv_obj_t * image_b2;
extern lv_obj_t * label_tile_b1;
extern lv_obj_t * label_tile_b2;
extern lv_obj_t * label_st_b1;
extern lv_obj_t * label_st_b2;
void main_tile_1_build(void);
void main_tile_1_show(void);
void main_tile_1_delete(void);
/*
* declear main_tile_2
*/
extern lv_obj_t * main_tile_2;
extern lv_obj_t * button_b3;
extern lv_obj_t * __button_b3_label;
extern lv_obj_t * image_b3;
extern lv_obj_t * label_tile_b3;
extern lv_obj_t * label_st_b3;
extern lv_obj_t * button_b4;
extern lv_obj_t * __button_b4_label;
extern lv_obj_t * image_b4;
extern lv_obj_t * label_tile_b4;
extern lv_obj_t * label_st_b4;
extern lv_obj_t * image_6d7d;
extern lv_obj_t * bar_main;
extern lv_obj_t * image_close;
extern lv_obj_t * image_stop;
extern lv_obj_t * image_open;
extern lv_obj_t * label_d51e;
void main_tile_2_build(void);
void main_tile_2_show(void);
void main_tile_2_delete(void);
/*
* declear cont_top
*/
extern lv_obj_t * cont_top;
extern lv_obj_t * image_e005;
extern lv_obj_t * label_0bb8;
extern lv_obj_t * image_top_home;
extern lv_obj_t * image_top_set;
extern lv_obj_t * image_top_mode;
lv_obj_t* cont_top_build(lv_obj_t* parent);
void cont_top_show(void);
void cont_top_delete(void);
/*
* declear screen_set
*/
extern lv_obj_t * screen_set;
extern lv_obj_t * screen_set_back;
extern lv_obj_t * label_2984;
extern lv_obj_t * list_86ba;
void screen_set_build(void);
void screen_set_show(void);
void screen_set_delete(void);
/*
* declear screen_wifi
*/
extern lv_obj_t * screen_wifi;
extern lv_obj_t * image_wifi_back;
extern lv_obj_t * switch_wifi;
extern lv_obj_t * label_0c49;
extern lv_obj_t * image_net;
extern lv_obj_t * label_net;
void screen_wifi_build(void);
void screen_wifi_show(void);
void screen_wifi_delete(void);
/*
* declear screen_theme
*/
extern lv_obj_t * screen_theme;
extern lv_obj_t * image_themeback;
extern lv_obj_t * image_theme_1;
extern lv_obj_t * image_theme_2;
extern lv_obj_t * image_theme_3;
extern lv_obj_t * label_226a;
extern lv_obj_t * label_a4ee;
extern lv_obj_t * label_e877;
extern lv_obj_t * label_adfc;
void screen_theme_build(void);
void screen_theme_show(void);
void screen_theme_delete(void);

extern lv_obj_t * g_kb;

void qmsd_ui_entry(void);
void qmsd_ui_loop(void);
lv_img_src_t *qmsd_get_img(const char *w_name);
lv_font_t *qmsd_get_font(const char *w_name);

void g_create_kb_ifneeded(void);
void g_show_kb(void);
#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*QM_UI_ENTRY_H*/