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

LV_FONT_DECLARE(ali_font_10);
LV_FONT_DECLARE(ali_font_75);
LV_FONT_DECLARE(ali_font_13);
LV_FONT_DECLARE(ali_font_14);
LV_FONT_DECLARE(ali_font_16);
LV_FONT_DECLARE(ali_font_18);
LV_FONT_DECLARE(ali_font_19);
LV_FONT_DECLARE(ali_font_20);
LV_FONT_DECLARE(ali_font_21);
LV_FONT_DECLARE(ali_font_22);
LV_FONT_DECLARE(ali_font_23);
LV_FONT_DECLARE(ali_font_24);
LV_FONT_DECLARE(ali_font_26);
LV_FONT_DECLARE(ali_font_27);
LV_FONT_DECLARE(ali_font_124);
LV_FONT_DECLARE(ali_font_29);
LV_FONT_DECLARE(ali_font_30);

LV_IMG_DECLARE(imgwifi_png);
LV_IMG_DECLARE(imgma_fan_png);
LV_IMG_DECLARE(imgma_low_png);
LV_IMG_DECLARE(imgma_high_png);
LV_IMG_DECLARE(imgma_next_png);
LV_IMG_DECLARE(imgma_stop_png);
LV_IMG_DECLARE(imgma_prev_png);
LV_IMG_DECLARE(imgimg_ma_singer_png);
LV_IMG_DECLARE(imgbuletooth_png);
LV_IMG_DECLARE(imgte_bar_png);
LV_IMG_DECLARE(imgte_bottom_png);
LV_IMG_DECLARE(imgte_fan_png);
LV_IMG_DECLARE(imgte_up_png);
LV_IMG_DECLARE(imgmu_bottom_png);
LV_IMG_DECLARE(imgmu_mode_png);
LV_IMG_DECLARE(imgmu_next_png);
LV_IMG_DECLARE(imgmu_stop_png);
LV_IMG_DECLARE(imgmu_prev_png);
LV_IMG_DECLARE(imgmu_list_png);
LV_IMG_DECLARE(imgline_png);
LV_IMG_DECLARE(imgreturn_png);
LV_IMG_DECLARE(imgma_smile_png);
LV_IMG_DECLARE(imgma_sun_png);
LV_IMG_DECLARE(imgma_light_png);
LV_IMG_DECLARE(imgte_silder_png);
LV_IMG_DECLARE(imgimg_mu_1_png);
LV_IMG_DECLARE(imgli_set_png);
LV_IMG_DECLARE(imgli_setb_png);
LV_IMG_DECLARE(imgli_bottom_png);
LV_IMG_DECLARE(imgli_bar_png);
LV_IMG_DECLARE(imgli_light_png);
LV_IMG_DECLARE(imgte_set_png);
LV_IMG_DECLARE(imgte_light_png);
LV_IMG_DECLARE(imgimg_mu_2_png);
LV_IMG_DECLARE(imgpl_png);
LV_IMG_DECLARE(imgtxdx_png);
LV_IMG_DECLARE(imgll_png);
LV_IMG_DECLARE(imghcd_png);
LV_IMG_DECLARE(imgimg_play_return_png);
LV_IMG_DECLARE(imgimg_play_re_png);
LV_IMG_DECLARE(imgwin_l_a_r_png);
LV_IMG_DECLARE(imgwin_top_png);
LV_IMG_DECLARE(imgimg_play_ing_png);
LV_IMG_DECLARE(imgimg_play_line_png);
LV_IMG_DECLARE(imgimg_play_sign_png);
LV_IMG_DECLARE(imgimg_play_bt_png);
LV_IMG_DECLARE(imgte_new_bottom_png);
LV_IMG_DECLARE(imgimg_mu_3_png);

/*
* declear screen_main
*/
extern lv_obj_t * screen_main;
extern lv_obj_t * label_main_time;
extern lv_obj_t * label_main_day;
extern lv_obj_t * image_main_wifi;
extern lv_obj_t * image_buletooth;
extern lv_obj_t * button_ma_music;
extern lv_obj_t * __button_ma_music_label;
extern lv_obj_t * button_ma_tem;
extern lv_obj_t * __button_ma_tem_label;
extern lv_obj_t * button_ma_light;
extern lv_obj_t * __button_ma_light_label;
extern lv_obj_t * label_ma_music;
extern lv_obj_t * image_singer;
extern lv_obj_t * label_ma_singer;
extern lv_obj_t * label_ma_song;
extern lv_obj_t * image_ma_prev;
extern lv_obj_t * image_ma_stop;
extern lv_obj_t * image_ma_next;
extern lv_obj_t * label_ma_windy;
extern lv_obj_t * label_ma_centig;
extern lv_obj_t * image_ma_high;
extern lv_obj_t * image_ma_low;
extern lv_obj_t * image_ma_light;
extern lv_obj_t * label_ma_light;
extern lv_obj_t * switch_ma;
extern lv_obj_t * button_ma_bott;
extern lv_obj_t * __button_ma_bott_label;
extern lv_obj_t * label_ma_label;
extern lv_obj_t * image_ma_sun;
extern lv_obj_t * label_ma_sun;
extern lv_obj_t * label_ma_sun_c;
extern lv_obj_t * label_ma_morn;
extern lv_obj_t * image_ma_smile;
extern lv_obj_t * slider_ma;
extern lv_obj_t * button_ma_color;
extern lv_obj_t * __button_ma_color_label;
extern lv_obj_t * label_ma_temper;
extern lv_obj_t * button_ma_barbt;
extern lv_obj_t * __button_ma_barbt_label;
extern lv_obj_t * button_ma_barra;
extern lv_obj_t * __button_ma_barra_label;
extern lv_obj_t * image_ma_fan;
void screen_main_build(void);
void screen_main_show(void);
void screen_main_delete(void);
/*
* declear screen_music
*/
extern lv_obj_t * screen_music;
extern lv_obj_t * image_mu_return;
extern lv_obj_t * label_mu_return;
extern lv_obj_t * image_mu_line;
extern lv_obj_t * label_mu_singer;
extern lv_obj_t * label_mu_song;
extern lv_obj_t * slider_mu;
extern lv_obj_t * label_mu_begin;
extern lv_obj_t * label_mu_end;
extern lv_obj_t * image_mu_list;
extern lv_obj_t * image_mu_prev;
extern lv_obj_t * image_mu_stop;
extern lv_obj_t * image_mu_next;
extern lv_obj_t * image_mu_mode;
extern lv_obj_t * image_mu_bottom;
extern lv_obj_t * image_mu_s_r;
extern lv_obj_t * image_mu_s_l;
extern lv_obj_t * image_mu_s_m;
extern lv_obj_t * image_play_bo;
extern lv_obj_t * image_play_sign;
extern lv_obj_t * image_play_line;
extern lv_obj_t * label_play_sign;
extern lv_obj_t * image_play_re;
void screen_music_build(void);
void screen_music_show(void);
void screen_music_delete(void);
/*
* declear screen_temper
*/
extern lv_obj_t * screen_temper;
extern lv_obj_t * image_te_bottom;
extern lv_obj_t * image_te_return;
extern lv_obj_t * label_te_return;
extern lv_obj_t * image_te_line;
extern lv_obj_t * switch_te;
extern lv_obj_t * label_te_temper;
extern lv_obj_t * label_te_curent;
extern lv_obj_t * label_te_centig;
extern lv_obj_t * image_te_up;
extern lv_obj_t * button_te_bott;
extern lv_obj_t * __button_te_bott_label;
extern lv_obj_t * label_te_set1;
extern lv_obj_t * label_te_set2;
extern lv_obj_t * label_te_windy;
extern lv_obj_t * image_te_slider;
extern lv_obj_t * image_te_light;
extern lv_obj_t * image_te_set;
extern lv_obj_t * button_te_barbt;
extern lv_obj_t * __button_te_barbt_label;
extern lv_obj_t * button_te_barra;
extern lv_obj_t * __button_te_barra_label;
extern lv_obj_t * image_te_fan;
extern lv_obj_t * image_te_bar;
void screen_temper_build(void);
void screen_temper_show(void);
void screen_temper_delete(void);
/*
* declear screen_light
*/
extern lv_obj_t * screen_light;
extern lv_obj_t * image_li_bottom;
extern lv_obj_t * image_li_return;
extern lv_obj_t * label_li_return;
extern lv_obj_t * image_li_line;
extern lv_obj_t * image_li_light;
extern lv_obj_t * image_li_setb;
extern lv_obj_t * image_li_set;
extern lv_obj_t * label_li_light;
extern lv_obj_t * label_li_color;
extern lv_obj_t * button_li_l_bt;
extern lv_obj_t * __button_li_l_bt_label;
extern lv_obj_t * button_li_l_ra;
extern lv_obj_t * __button_li_l_ra_label;
extern lv_obj_t * image_li_barl;
extern lv_obj_t * button_li_c_bt;
extern lv_obj_t * __button_li_c_bt_label;
extern lv_obj_t * button_li_c_ra;
extern lv_obj_t * __button_li_c_ra_label;
extern lv_obj_t * image_li_barc;
void screen_light_build(void);
void screen_light_show(void);
void screen_light_delete(void);
/*
* declear screen_test
*/
extern lv_obj_t * screen_test;
extern lv_obj_t * label_4617;
extern lv_obj_t * label_b020;
extern lv_obj_t * label_1db1;
extern lv_obj_t * label_b558;
extern lv_obj_t * label_019e;
extern lv_obj_t * label_d5af;
extern lv_obj_t * label_a4c0;
void screen_test_build(void);
void screen_test_show(void);
void screen_test_delete(void);

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

extern lv_indev_t* get_point;
extern lv_indev_data_t my_data;

#endif /*QM_UI_ENTRY_H*/
