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
LV_FONT_DECLARE(ali_font_20);
LV_FONT_DECLARE(ali_font_38);
LV_FONT_DECLARE(ali_font_22);
LV_FONT_DECLARE(ali_font_39);
LV_FONT_DECLARE(ali_font_24);
LV_FONT_DECLARE(ali_font_41);
LV_FONT_DECLARE(ali_font_28);

LV_IMG_DECLARE(imgbutton_bg_L_png);
LV_IMG_DECLARE(imgwater_box_n_png);
LV_IMG_DECLARE(imgp_88_png);
LV_IMG_DECLARE(imgp_80_png);
LV_IMG_DECLARE(imgfilter_element_l_png);
LV_IMG_DECLARE(imgupward_png);
LV_IMG_DECLARE(imgpodetium_g_L_png);
LV_IMG_DECLARE(imgdownward_png);
LV_IMG_DECLARE(imgpodetium_g_png);
LV_IMG_DECLARE(imgbg_blue_c_png);
LV_IMG_DECLARE(imgpodetium_or_png);
LV_IMG_DECLARE(imgpodetium_blue_png);
LV_IMG_DECLARE(imgdown_png);
LV_IMG_DECLARE(imgtitle_png);
LV_IMG_DECLARE(imgdown_un_point_png);
LV_IMG_DECLARE(imgdown_s_point_png);
LV_IMG_DECLARE(imgmenu_ivn_png);
LV_IMG_DECLARE(imgxiaoka_png);
LV_IMG_DECLARE(imgright_icn_png);
LV_IMG_DECLARE(imgleft_icn_png);

/*
* declear screen_main
*/
extern lv_obj_t * screen_main;
extern lv_obj_t * image_bg_blue;
extern lv_obj_t * image_xiaoka;
extern lv_obj_t * image_s_pon_1;
extern lv_obj_t * image_un_pon_1;
extern lv_obj_t * image_un_pon_2;
extern lv_obj_t * image_un_pon_3;
extern lv_obj_t * image_title;
extern lv_obj_t * button_left;
extern lv_obj_t * __button_left_label;
extern lv_obj_t * image_left_icn;
extern lv_obj_t * button_right;
extern lv_obj_t * __button_right_label;
extern lv_obj_t * image_right_icn;
extern lv_obj_t * label_main_left;
extern lv_obj_t * label_main_rig;
extern lv_obj_t * image_down;
extern lv_obj_t * image_menu;
extern lv_obj_t * image_L_Pod;
extern lv_obj_t * image_R_Pod;
extern lv_obj_t * image_L_Pod_g;
extern lv_obj_t * image_R_Pod_g;
extern lv_obj_t * image_dw_L;
extern lv_obj_t * image_dw_R;
extern lv_obj_t * image_L_or;
extern lv_obj_t * image_R_or;
extern lv_obj_t * image_LL_pod;
extern lv_obj_t * image_RL_pod;
void screen_main_build(void);
void screen_main_show(void);
void screen_main_delete(void);
/*
* declear screen_humidity
*/
extern lv_obj_t * screen_humidity;
extern lv_obj_t * image_hu_bg;
extern lv_obj_t * image_hu_xiaoka;
extern lv_obj_t * image_hu_u_pon1;
extern lv_obj_t * image_hu_s_pon;
extern lv_obj_t * image_hu_u_pon2;
extern lv_obj_t * image_hu_u_pon3;
extern lv_obj_t * image_hu_down;
extern lv_obj_t * image_hu_menu;
extern lv_obj_t * label_hu_left;
extern lv_obj_t * label_hu_right;
extern lv_obj_t * image_hu_L_pod;
extern lv_obj_t * image_hu_R_pod;
extern lv_obj_t * image_h_L_podg;
extern lv_obj_t * image_h_R_podg;
extern lv_obj_t * button_hu_left;
extern lv_obj_t * __button_hu_left_label;
extern lv_obj_t * image_hu_left;
extern lv_obj_t * button_hu_right;
extern lv_obj_t * __button_hu_right_label;
extern lv_obj_t * image_hu_right;
extern lv_obj_t * image_hu_dw_L;
extern lv_obj_t * image_hu_dw_R;
extern lv_obj_t * image_hu_L_or;
extern lv_obj_t * image_hu_R_or;
extern lv_obj_t * image_hu_LD_or;
extern lv_obj_t * image_hu_RD_or;
extern lv_obj_t * label_title_t;
extern lv_obj_t * label_title_hu;
extern lv_obj_t * label_du;
extern lv_obj_t * label_perc;
void screen_humidity_build(void);
void screen_humidity_show(void);
void screen_humidity_delete(void);
/*
* declear screen_water_b
*/
extern lv_obj_t * screen_water_b;
extern lv_obj_t * image_w_bg;
extern lv_obj_t * image_w_xiaoka;
extern lv_obj_t * image_w_u_pon1;
extern lv_obj_t * image_w_u_pon2;
extern lv_obj_t * image_w_s_pon;
extern lv_obj_t * image_w_u_pon3;
extern lv_obj_t * image_w_down;
extern lv_obj_t * image_w_menu;
extern lv_obj_t * button_w_left;
extern lv_obj_t * __button_w_left_label;
extern lv_obj_t * image_w_left;
extern lv_obj_t * button_w_right;
extern lv_obj_t * __button_w_right_label;
extern lv_obj_t * image_w_right;
extern lv_obj_t * image_w_box;
extern lv_obj_t * label_w_title;
extern lv_obj_t * label_w_title_d;
extern lv_obj_t * image_w_p_80;
void screen_water_b_build(void);
void screen_water_b_show(void);
void screen_water_b_delete(void);
/*
* declear screen_filter
*/
extern lv_obj_t * screen_filter;
extern lv_obj_t * image_fif_bg;
extern lv_obj_t * image_f_xiaoka;
extern lv_obj_t * image_f_u_pon1;
extern lv_obj_t * image_f_u_pon2;
extern lv_obj_t * image_f_u_pon3;
extern lv_obj_t * image_f_s_pon;
extern lv_obj_t * image_f_down;
extern lv_obj_t * image_f_menu;
extern lv_obj_t * button_f_left;
extern lv_obj_t * __button_f_left_label;
extern lv_obj_t * image_f_left;
extern lv_obj_t * button_f_right;
extern lv_obj_t * __button_f_right_label;
extern lv_obj_t * image_f_right;
extern lv_obj_t * image_filter;
extern lv_obj_t * label_f_title;
extern lv_obj_t * label_f_title_d;
extern lv_obj_t * image_f_p_88;
void screen_filter_build(void);
void screen_filter_show(void);
void screen_filter_delete(void);

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