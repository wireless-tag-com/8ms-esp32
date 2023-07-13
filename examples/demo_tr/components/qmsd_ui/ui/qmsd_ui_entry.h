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

LV_FONT_DECLARE(ali_font_32);
LV_FONT_DECLARE(ali_font_35);
LV_FONT_DECLARE(ali_font_104);
LV_FONT_DECLARE(ali_font_40);
LV_FONT_DECLARE(ali_font_11);
LV_FONT_DECLARE(ali_font_107);
LV_FONT_DECLARE(ali_font_13);
LV_FONT_DECLARE(ali_font_14);
LV_FONT_DECLARE(ali_font_16);
LV_FONT_DECLARE(ali_font_17);
LV_FONT_DECLARE(ali_font_18);
LV_FONT_DECLARE(ali_font_19);
LV_FONT_DECLARE(ali_font_20);
LV_FONT_DECLARE(ali_font_21);
LV_FONT_DECLARE(ali_font_23);
LV_FONT_DECLARE(ali_font_24);
LV_FONT_DECLARE(ali_font_30);

LV_IMG_DECLARE(imgtips_png);
LV_IMG_DECLARE(imgair_conditioner_off_png);
LV_IMG_DECLARE(imgair_conditioner_on_png);
LV_IMG_DECLARE(imgair_conditioner_sign_png);
LV_IMG_DECLARE(imgtileview2_next_png);
LV_IMG_DECLARE(imgtileview3_robot_png);
LV_IMG_DECLARE(imgtileview2_stop_bottom_png);
LV_IMG_DECLARE(imgtileview2_stop_open_png);
LV_IMG_DECLARE(imgcontlink_bottom_png);
LV_IMG_DECLARE(imgcontlink_sign_png);
LV_IMG_DECLARE(imgtileview1_press_png);
LV_IMG_DECLARE(imgcurtain_button_on_png);
LV_IMG_DECLARE(imgtileview2_stop_stop_png);
LV_IMG_DECLARE(imglist_equipment_png);
LV_IMG_DECLARE(imglist_wifi_png);
LV_IMG_DECLARE(imgcontlink_main_more_png);
LV_IMG_DECLARE(imgcontlink_main_set_png);
LV_IMG_DECLARE(imgcontlink_main_home_png);
LV_IMG_DECLARE(imgcurtain_curtain_cloth_png);
LV_IMG_DECLARE(imgcurtain_button_all_png);
LV_IMG_DECLARE(imgcurtain_button_close_png);
LV_IMG_DECLARE(imgcurtain_button_stop_png);
LV_IMG_DECLARE(imgcurtain_button_open_png);
LV_IMG_DECLARE(imgcurtain_button_off_png);
LV_IMG_DECLARE(imgcurtain_curtain_right_png);
LV_IMG_DECLARE(imgcurtain_curtain_left_png);
LV_IMG_DECLARE(imglist_return_png);
LV_IMG_DECLARE(imglist_voice_png);
LV_IMG_DECLARE(imglist_show_png);
LV_IMG_DECLARE(imglist_song_png);
LV_IMG_DECLARE(imglist_user_png);
LV_IMG_DECLARE(imglist_ota_png);
LV_IMG_DECLARE(imglist_about_png);
LV_IMG_DECLARE(imglist_delete_png);
LV_IMG_DECLARE(imgequipment_load_png);
LV_IMG_DECLARE(imgequipment_smile_png);
LV_IMG_DECLARE(imgwifi_lock_png);
LV_IMG_DECLARE(imgwifi_load_png);
LV_IMG_DECLARE(imgwifi_choice_png);
LV_IMG_DECLARE(imgwifi_error_png);
LV_IMG_DECLARE(imgair_curditioner_middle_png);
LV_IMG_DECLARE(imgcurtain_curtain_top_png);
LV_IMG_DECLARE(imgair_curditioner_high_png);
LV_IMG_DECLARE(imgair_curditioner_low_png);
LV_IMG_DECLARE(imgtileview2_curtain0_png);
LV_IMG_DECLARE(imgtileview2_left_png);
LV_IMG_DECLARE(imgtileview2_right_png);
LV_IMG_DECLARE(imgtileview2_air_conditioner_bottom_png);
LV_IMG_DECLARE(imgtilevwe2_prev_button_png);
LV_IMG_DECLARE(imgtileview2_button_one_png);
LV_IMG_DECLARE(imgtileview2_button_two_png);
LV_IMG_DECLARE(imgtileview_button_three_png);
LV_IMG_DECLARE(imgtileview_button_four_png);
LV_IMG_DECLARE(imgtileview3_button_more_png);
LV_IMG_DECLARE(imgtileview3_more_png);
LV_IMG_DECLARE(imgchoice_return_png);
LV_IMG_DECLARE(imgchoice_leave_home_png);
LV_IMG_DECLARE(imgchoice_go_home_png);
LV_IMG_DECLARE(imgair_curditioner_sun_png);
LV_IMG_DECLARE(imgair_curditioner_cold_png);
LV_IMG_DECLARE(imgchoice_fime__png);
LV_IMG_DECLARE(imgchoice_fime_png);
LV_IMG_DECLARE(imgchoice_meet__png);
LV_IMG_DECLARE(imgchoice_meet_png);
LV_IMG_DECLARE(imgchoice_sleep__png);
LV_IMG_DECLARE(imgchoice_sleep_png);
LV_IMG_DECLARE(imgchoice_go_bed__png);
LV_IMG_DECLARE(imgchoice_go_bed_png);
LV_IMG_DECLARE(imgsaver_button_png);
LV_IMG_DECLARE(imgsaver_image_png);
LV_IMG_DECLARE(imgweather_png);
LV_IMG_DECLARE(imghumidity_png);
LV_IMG_DECLARE(imgair_png);
LV_IMG_DECLARE(imgtileview_1_png);
LV_IMG_DECLARE(imgtileview_2_png);
LV_IMG_DECLARE(imgtileview_3_png);
LV_IMG_DECLARE(imgtileview_go_home_png);
LV_IMG_DECLARE(imgtileview_leave_home_png);
LV_IMG_DECLARE(imgtileview_more_png);
LV_IMG_DECLARE(imgtileview2_leave_home_png);
LV_IMG_DECLARE(imgtileview2_go_home_png);
LV_IMG_DECLARE(imgtileview2_living_room_png);
LV_IMG_DECLARE(imgtileview2_living_room_light_png);
LV_IMG_DECLARE(imgtileview2_restaurant_png);
LV_IMG_DECLARE(imgtileview2_curtain_1_png);
LV_IMG_DECLARE(imglogo_png);

/*
* declear screen_main
*/
extern lv_obj_t * screen_main;
extern lv_obj_t * image_ma_logo;
void screen_main_build(void);
void screen_main_show(void);
void screen_main_delete(void);
/*
* declear screen_saver
*/
extern lv_obj_t * screen_saver;
extern lv_obj_t * image_saver_bot;
extern lv_obj_t * lab_sa_hour;
extern lv_obj_t * lab_sa_min;
extern lv_obj_t * lab_sa_scr;
extern lv_obj_t * lab_sa_data;
extern lv_obj_t * lab_sa_week;
extern lv_obj_t * but_sa_but_deep;
extern lv_obj_t * __but_sa_but_deep_label;
extern lv_obj_t * ima_sa_ima;
extern lv_obj_t * lab_sa_tips;
void screen_saver_build(void);
void screen_saver_show(void);
void screen_saver_delete(void);
/*
* declear screen_tileview
*/
extern lv_obj_t * screen_tileview;
extern lv_obj_t * tile_main;
extern lv_obj_t * but_tile_left;
extern lv_obj_t * __but_tile_left_label;
extern lv_obj_t * but_tile_middle;
extern lv_obj_t * __but_tile_middle_label;
extern lv_obj_t * but_tile_right;
extern lv_obj_t * __but_tile_right_label;
extern lv_obj_t * contlink_main;
void screen_tileview_build(void);
void screen_tileview_show(void);
void screen_tileview_delete(void);
/*
* declear screentileview1
*/
extern lv_obj_t * screentileview1;
extern lv_obj_t * lab_tile1_time;
extern lv_obj_t * lab_tile1_data;
extern lv_obj_t * lab_tile1_week;
extern lv_obj_t * ima_tile1_wea;
extern lv_obj_t * lab_tile1_tem;
extern lv_obj_t * lab_tile1_com;
extern lv_obj_t * but_tile1_bot;
extern lv_obj_t * __but_tile1_bot_label;
extern lv_obj_t * ima_tile1_hum;
extern lv_obj_t * lab_tile1_hum;
extern lv_obj_t * lab_tile1_hum_;
extern lv_obj_t * lab_tile1_humc;
extern lv_obj_t * ima_tile1_air;
extern lv_obj_t * lab_tile1_air;
extern lv_obj_t * lab_tile1_air_;
extern lv_obj_t * ima_tile1_le;
extern lv_obj_t * ima_tile1_mi;
extern lv_obj_t * ima_tile1_ri;
extern lv_obj_t * ima_tile1_le_;
extern lv_obj_t * lab_tile1_le;
extern lv_obj_t * ima_tile1_mi_;
extern lv_obj_t * lab_tile1_mi;
extern lv_obj_t * ima_tile1_ri_;
extern lv_obj_t * lab_tile1_ri;
extern lv_obj_t * lab_tile1_hour;
extern lv_obj_t * lab_tile1_min;
void screentileview1_build(void);
void screentileview1_show(void);
void screentileview1_delete(void);
/*
* declear screentileview2
*/
extern lv_obj_t * screentileview2;
extern lv_obj_t * ima_tile2_lh;
extern lv_obj_t * ima_tile2_lh_;
extern lv_obj_t * lab_tile2_lh;
extern lv_obj_t * ima_tile2_gh;
extern lv_obj_t * ima_tile2_gh_;
extern lv_obj_t * lab_tile2_gh;
extern lv_obj_t * ima_tile2_li;
extern lv_obj_t * lab_tile2_li;
extern lv_obj_t * ima_tile2_li_;
extern lv_obj_t * swi_tile2_li;
extern lv_obj_t * ima_tile2_res;
extern lv_obj_t * lab_tile2_res;
extern lv_obj_t * ima_tile2_res_;
extern lv_obj_t * swi_tile2_res;
extern lv_obj_t * ima_tile2_cu;
extern lv_obj_t * lab_tile2_cu;
extern lv_obj_t * lab_tile2_cu_;
extern lv_obj_t * ima_tile2_cu_;
extern lv_obj_t * bar_tile2_bar;
extern lv_obj_t * ima_tile2_le;
extern lv_obj_t * ima_tile2_ri;
extern lv_obj_t * ima_tile2_ai;
extern lv_obj_t * swi_tile2_ai;
extern lv_obj_t * lab_tile2_ai;
extern lv_obj_t * lab_tile2_ai_;
extern lv_obj_t * but_tile2_pr;
extern lv_obj_t * __but_tile2_pr_label;
extern lv_obj_t * ima_tile2_pr;
extern lv_obj_t * but_tile2_ne;
extern lv_obj_t * __but_tile2_ne_label;
extern lv_obj_t * ima_tile2_ne;
extern lv_obj_t * lab_tile2_ai__;
extern lv_obj_t * lab_tile2_ai_c;
extern lv_obj_t * but_tile2_one;
extern lv_obj_t * __but_tile2_one_label;
extern lv_obj_t * but_tile2_two;
extern lv_obj_t * __but_tile2_two_label;
extern lv_obj_t * but_tile2_thr;
extern lv_obj_t * __but_tile2_thr_label;
extern lv_obj_t * but_tile2_fou;
extern lv_obj_t * __but_tile2_fou_label;
extern lv_obj_t * ima_tile2_one;
extern lv_obj_t * ima_tile2_two;
extern lv_obj_t * ima_tile2_thr;
extern lv_obj_t * ima_tile2_fou;
extern lv_obj_t * ima_tile2_stb;
extern lv_obj_t * ima_tile2_st;
void screentileview2_build(void);
void screentileview2_show(void);
void screentileview2_delete(void);
/*
* declear screentileview3
*/
extern lv_obj_t * screentileview3;
extern lv_obj_t * image_21da;
extern lv_obj_t * swi_tile3_swi;
extern lv_obj_t * lab_tile3_rob;
extern lv_obj_t * ima_tile3_mo;
extern lv_obj_t * ima_tile3_mo_;
extern lv_obj_t * lab_tile3_mo;
void screentileview3_build(void);
void screentileview3_show(void);
void screentileview3_delete(void);
/*
* declear screen_choice
*/
extern lv_obj_t * screen_choice;
extern lv_obj_t * ima_cho_re;
extern lv_obj_t * lab_cho_re;
extern lv_obj_t * ima_cho_gh;
extern lv_obj_t * ima_cho_lh;
extern lv_obj_t * ima_cho_gb;
extern lv_obj_t * ima_cho_sl;
extern lv_obj_t * ima_cho_me;
extern lv_obj_t * ima_cho_fi;
extern lv_obj_t * ima_cho_gh_;
extern lv_obj_t * lab_cho_gh;
extern lv_obj_t * ima_cho_lh_;
extern lv_obj_t * lab_cho_lh;
extern lv_obj_t * ima_cho_gb_;
extern lv_obj_t * lab_cho_gb;
extern lv_obj_t * ima_cho_sl_;
extern lv_obj_t * lab_cho_sl;
extern lv_obj_t * ima_cho_me_;
extern lv_obj_t * lab_cho_me;
extern lv_obj_t * ima_cho_fi_;
extern lv_obj_t * lab_cho_fi;
void screen_choice_build(void);
void screen_choice_show(void);
void screen_choice_delete(void);
/*
* declear screen_air
*/
extern lv_obj_t * screen_air;
extern lv_obj_t * ima_air_re;
extern lv_obj_t * lab_air_re;
extern lv_obj_t * swi_air_swi;
extern lv_obj_t * lab_air_text;
extern lv_obj_t * lab_air_tem;
extern lv_obj_t * lab_air_tem_;
extern lv_obj_t * ima_air_co;
extern lv_obj_t * ima_air_sun;
extern lv_obj_t * ima_air_lo;
extern lv_obj_t * ima_air_mi;
extern lv_obj_t * ima_air_hi;
extern lv_obj_t * lab_air_pat;
extern lv_obj_t * lab_air_pow;
extern lv_obj_t * ima_air_4;
extern lv_obj_t * ima_air_5;
extern lv_obj_t * ima_air_6;
extern lv_obj_t * ima_air_7;
extern lv_obj_t * ima_air_8;
extern lv_obj_t * ima_air_9;
extern lv_obj_t * ima_air_10;
extern lv_obj_t * ima_air_11;
extern lv_obj_t * ima_air_12;
extern lv_obj_t * ima_air_13;
extern lv_obj_t * ima_air_14;
extern lv_obj_t * ima_air_15;
extern lv_obj_t * ima_air_16;
extern lv_obj_t * ima_air_17;
extern lv_obj_t * ima_air_18;
extern lv_obj_t * ima_air_sign;
void screen_air_build(void);
void screen_air_show(void);
void screen_air_delete(void);
/*
* declear scr_curtain_ti1
*/
extern lv_obj_t * scr_curtain_ti1;
extern lv_obj_t * ima_cur_re;
extern lv_obj_t * lab_cur_le;
extern lv_obj_t * lab_cur_ri;
extern lv_obj_t * but_cur_top;
extern lv_obj_t * __but_cur_top_label;
extern lv_obj_t * but_cur_bot;
extern lv_obj_t * __but_cur_bot_label;
extern lv_obj_t * ima_cur_;
extern lv_obj_t * ima_cur_cul;
extern lv_obj_t * ima_cur_cur;
extern lv_obj_t * ima_cur_op;
extern lv_obj_t * ima_cur_st;
extern lv_obj_t * ima_cur_cl;
extern lv_obj_t * ima_cur_on;
extern lv_obj_t * ima_cur_op_;
extern lv_obj_t * ima_cur_st_;
extern lv_obj_t * ima_cur_cl_;
extern lv_obj_t * ima_cur_on_;
extern lv_obj_t * ima_cur_cle;
extern lv_obj_t * ima_cur_cri;
extern lv_obj_t * but_cur_le;
extern lv_obj_t * __but_cur_le_label;
extern lv_obj_t * but_cur_ri;
extern lv_obj_t * __but_cur_ri_label;
extern lv_obj_t * but_cur_ble;
extern lv_obj_t * __but_cur_ble_label;
extern lv_obj_t * but_cur_bri;
extern lv_obj_t * __but_cur_bri_label;
void scr_curtain_ti1_build(void);
void scr_curtain_ti1_show(void);
void scr_curtain_ti1_delete(void);
/*
* declear screen_set
*/
extern lv_obj_t * screen_set;
extern lv_obj_t * lab_set_set;
extern lv_obj_t * ima_set_re;
void screen_set_build(void);
void screen_set_show(void);
void screen_set_delete(void);
/*
* declear screen_cont
*/
extern lv_obj_t * screen_cont;
extern lv_obj_t * ima_con_bot;
extern lv_obj_t * ima_con_re;
extern lv_obj_t * ima_con_set;
extern lv_obj_t * ima_con_mor;
extern lv_obj_t * lab_con_re;
extern lv_obj_t * lab_con_set;
extern lv_obj_t * lab_con_mor;
extern lv_obj_t * ima_con_sign;
lv_obj_t* screen_cont_build(lv_obj_t* parent);
void screen_cont_show(void);
void screen_cont_delete(void);
/*
* declear scr_equipment
*/
extern lv_obj_t * scr_equipment;
extern lv_obj_t * ima_equ_re;
extern lv_obj_t * lab_equ_re;
extern lv_obj_t * ima_equ_load;
extern lv_obj_t * ima_equ_smi;
extern lv_obj_t * lab_equ_lab;
extern lv_obj_t * label_b479;
void scr_equipment_build(void);
void scr_equipment_show(void);
void scr_equipment_delete(void);
/*
* declear screen_wifi_set
*/
extern lv_obj_t * screen_wifi_set;
extern lv_obj_t * lab_wif_lab;
extern lv_obj_t * lab_wif_re;
extern lv_obj_t * lab_wif_tip;
extern lv_obj_t * swi_wif_swi;
void screen_wifi_set_build(void);
void screen_wifi_set_show(void);
void screen_wifi_set_delete(void);
/*
* declear screen_input
*/
extern lv_obj_t * screen_input;
extern lv_obj_t * ima_inp_re;
extern lv_obj_t * lab_inp_lab;
extern lv_obj_t * but_inp_inp;
extern lv_obj_t * __but_inp_inp_label;
extern lv_obj_t * tex_inp_tex;
void screen_input_build(void);
void screen_input_show(void);
void screen_input_delete(void);
/*
* declear screen_text
*/
extern lv_obj_t * screen_text;
extern lv_obj_t * label_5a9a;
extern lv_obj_t * label_dd93;
extern lv_obj_t * lab_3d4d;
void screen_text_build(void);
void screen_text_show(void);
void screen_text_delete(void);

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
