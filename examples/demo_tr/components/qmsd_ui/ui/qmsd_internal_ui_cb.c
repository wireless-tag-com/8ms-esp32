#include "qmsd_ui_entry.h"
#include "qmsd_lang.h"

float get_tem_data;
float get_hum_data;
lv_task_t* tileview1_tem_hum;
void tileview1_tem_hum_cb(lv_task_t* t);

int screen_saver_sign = -1; 
int scr_equipment_sign = 0; 
lv_anim_t all_anim_obj;  lv_anim_path_t all_anim_obj_path;  
int screen_tileview_sign = 0; 
int screen_tileview_show_sign  = -1; 
int screen_tileview_choice_sign  = -1; 
lv_task_t* task_callback_sa_time; 
int screen_tileview_air_sign  = -1; 
int task_callback_time_sign = -1; lv_task_t* task_callback_time; 
int screen_tileview_equi_sign  = -1; 
void callback_sa_time(lv_task_t* t) {
    static int _timer_index=1;
    if(_timer_index<1)
    {
      _timer_index=1;
    }
  
      if(screen_saver_sign == 1) 
      {
          if(_timer_index == 1) {
              lv_label_set_text(lab_sa_scr, ":");
          }else {
              lv_label_set_text(lab_sa_scr, "");
              _timer_index = 0;
          }
      }else if(screen_saver_sign == 2) {
          lv_task_del(t);
      }
  
    _timer_index++;

}

void callback_time(lv_task_t* t) {
    static int _timer_index=1;
    if(_timer_index<1) {
      _timer_index=1;
    }
  
      if(screen_tileview_sign == 0) {
          if(_timer_index == 1) {
              lv_label_set_text(lab_tile1_time, ":");
          }else {
              lv_label_set_text(lab_tile1_time, "");
              _timer_index = 0;
          }
      }else if(screen_tileview_sign == 1) {
          lv_task_del(t);
      }
  
    _timer_index++;

}

int screen_tile1_le_sign  = 1; 
int screen_tile1_mi_sign = 1; 
void lv_anim_logo_function_cb(void* obj,lv_anim_value_t values) {
  lv_obj_set_style_local_image_opa(obj,LV_IMG_PART_MAIN,LV_STATE_DEFAULT,values);

}

void time_sign_control( bool sign_control) {
      if(sign_control && !(screen_tileview_sign)) {
          lv_label_set_text(lab_tile1_time, "");
          task_callback_time_sign = 1;
          task_callback_time = lv_task_create(callback_time, 1000 , LV_TASK_PRIO_HIGH , NULL);
      }else {
          task_callback_time_sign = 2;        
      }

}

void lv_anim_ima_sa_ima_function_cb(void* obj,lv_anim_value_t values) {
  lv_obj_set_y(obj, values);

}

int bar_tile2_bar_sign = 0; int bar_tile2_bar_value = 0; int bar_tile2_bar_stop_sign = 0; int tileview2_temperature = 26; 
int scr_curtain_but_cur_sign = 0; int curtain_value = 0; int ima_cur_on_sign = 0; int ima_cur_on_stop_sign = 0; 
void lv_anim_logo_function(void) {
    lv_anim_path_init(&all_anim_obj_path);
    lv_anim_path_set_cb(&all_anim_obj_path, lv_anim_path_ease_in_out);
    lv_anim_set_path(&all_anim_obj, &all_anim_obj_path);
    lv_anim_init(&all_anim_obj);
    lv_anim_set_var(&all_anim_obj, image_ma_logo);
    lv_anim_set_values(&all_anim_obj, 0, 255);
    lv_anim_set_time(&all_anim_obj, 1000);
    lv_anim_set_playback_delay(&all_anim_obj, 0);
    lv_anim_set_playback_time(&all_anim_obj, 0);
    lv_anim_set_repeat_delay(&all_anim_obj, 0);
    lv_anim_set_repeat_count(&all_anim_obj, 0);
    lv_anim_set_exec_cb(&all_anim_obj, (lv_anim_exec_xcb_t)lv_anim_logo_function_cb);
    lv_anim_start(&all_anim_obj);

}

void lv_anim_tile2_bar_function_cb(void* obj,lv_anim_value_t values) {
    lv_bar_set_value(bar_tile2_bar, values, LV_ANIM_OFF);
    bar_tile2_bar_value = lv_bar_get_value(bar_tile2_bar);

}

void lv_anim_ima_sa_ima_function(void) {
    lv_anim_path_init(&all_anim_obj_path);
    lv_anim_path_set_cb(&all_anim_obj_path, lv_anim_path_ease_in_out);
    lv_anim_set_path(&all_anim_obj, &all_anim_obj_path);
    lv_anim_init(&all_anim_obj);
    lv_anim_set_var(&all_anim_obj, ima_sa_ima);
    lv_anim_set_values(&all_anim_obj, 359, 364);
    lv_anim_set_time(&all_anim_obj, 500);
    lv_anim_set_playback_delay(&all_anim_obj, 0);
    lv_anim_set_playback_time(&all_anim_obj, 500);
    lv_anim_set_repeat_delay(&all_anim_obj, 0);
    lv_anim_set_repeat_count(&all_anim_obj, LV_ANIM_REPEAT_INFINITE);
    lv_anim_set_exec_cb(&all_anim_obj, (lv_anim_exec_xcb_t)lv_anim_ima_sa_ima_function_cb);
    lv_anim_start(&all_anim_obj);

}

void lv_anim_ima_cur_le_function_cb(void* obj,lv_anim_value_t values) {
      lv_obj_set_x(obj, values);

}

lv_obj_t* list_main; lv_obj_t* list_main_son[8]; /* 无线网络--wifi */ lv_obj_t* ima_list_wifi; lv_obj_t* lab_list_wifi; lv_obj_t* ima_list_wifi_return; lv_obj_t* lab_list_wifi_name; /* 添加设备--equipment */ lv_obj_t* ima_list_equipment; lv_obj_t* lab_list_equipment; lv_obj_t* ima_list_equipment_return; /* 语音控制--voice */ lv_obj_t* ima_list_voice; lv_obj_t* ima_list_voice_return; lv_obj_t* lab_list_voice; lv_obj_t* lab_list_voice_sign; /* 显示--show */ lv_obj_t* ima_list_show; lv_obj_t* ima_list_show_return; lv_obj_t* lab_list_show; /* 声音--song */ lv_obj_t* ima_list_song; lv_obj_t* ima_list_song_return; lv_obj_t* lab_list_song; /* 用户指南--user */ lv_obj_t* ima_list_user; lv_obj_t* ima_list_user_return; lv_obj_t* lab_list_user; /* 系统升级--ota */ lv_obj_t* ima_list_ota; lv_obj_t* ima_list_ota_return; lv_obj_t* lab_list_ota; lv_obj_t* lab_list_ota_name; /* 关于本机--about */ lv_obj_t* ima_list_about; lv_obj_t* ima_list_about_return; lv_obj_t* lab_list_about; 
void screen_air_function(void) {
  switch(tileview2_temperature) {
      case 16:
          lv_obj_set_x(ima_air_sign, 124);
          lv_img_set_src(ima_air_4, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_18, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_17, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_16, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_15, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_14, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_13, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_12, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_11, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_10, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_9, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_8, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_7, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_6, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_5, &imgair_conditioner_off_png);
          break;
      case 17:
          lv_obj_set_x(ima_air_sign, 140);
          lv_img_set_src(ima_air_5, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_4, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_18, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_17, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_16, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_15, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_14, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_13, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_12, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_11, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_10, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_9, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_8, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_7, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_6, &imgair_conditioner_off_png);
          break;
      case 18:
          lv_obj_set_x(ima_air_sign, 156);
          lv_img_set_src(ima_air_6, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_5, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_4, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_18, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_17, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_16, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_15, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_14, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_13, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_12, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_11, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_10, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_9, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_8, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_7, &imgair_conditioner_off_png);
          break;
      case 19:
          lv_obj_set_x(ima_air_sign, 172);
          lv_img_set_src(ima_air_7, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_6, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_5, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_4, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_18, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_17, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_16, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_15, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_14, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_13, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_12, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_11, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_10, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_9, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_8, &imgair_conditioner_off_png);
          break;
      case 20:
          lv_obj_set_x(ima_air_sign, 188);
          lv_img_set_src(ima_air_8, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_7, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_6, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_5, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_4, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_18, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_17, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_16, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_15, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_14, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_13, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_12, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_11, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_10, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_9, &imgair_conditioner_off_png);
          break;
      case 21:
          lv_obj_set_x(ima_air_sign, 204);
          lv_img_set_src(ima_air_9, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_8, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_7, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_6, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_5, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_4, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_18, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_17, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_16, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_15, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_14, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_13, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_12, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_11, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_10, &imgair_conditioner_off_png);
          break;
      case 22:
          lv_obj_set_x(ima_air_sign, 220);
          lv_img_set_src(ima_air_10, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_9, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_8, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_7, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_6, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_5, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_4, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_18, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_17, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_16, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_15, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_14, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_13, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_12, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_11, &imgair_conditioner_off_png);
          break;
      case 23:
          lv_obj_set_x(ima_air_sign, 236);
          lv_img_set_src(ima_air_11, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_10, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_9, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_8, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_7, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_6, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_5, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_4, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_18, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_17, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_16, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_15, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_14, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_13, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_12, &imgair_conditioner_off_png);
          break;
      case 24:
          lv_obj_set_x(ima_air_sign, 252);
          lv_img_set_src(ima_air_12, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_11, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_10, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_9, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_8, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_7, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_6, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_5, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_4, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_18, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_17, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_16, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_15, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_14, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_13, &imgair_conditioner_off_png);
          break;
      case 25:
          lv_obj_set_x(ima_air_sign, 268);
          lv_img_set_src(ima_air_13, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_12, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_11, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_10, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_9, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_8, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_7, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_6, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_5, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_4, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_18, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_17, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_16, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_15, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_14, &imgair_conditioner_off_png);
          break;
      case 26:
          lv_obj_set_x(ima_air_sign, 284);
          lv_img_set_src(ima_air_14, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_13, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_12, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_11, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_10, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_9, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_8, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_7, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_6, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_5, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_4, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_18, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_17, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_16, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_15, &imgair_conditioner_off_png);
          break;
      case 27:
          lv_obj_set_x(ima_air_sign, 300);
          lv_img_set_src(ima_air_15, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_14, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_13, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_12, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_11, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_10, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_9, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_8, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_7, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_6, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_5, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_4, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_18, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_17, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_16, &imgair_conditioner_off_png);
          break;
      case 28:
          lv_obj_set_x(ima_air_sign, 316);
          lv_img_set_src(ima_air_16, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_15, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_14, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_13, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_12, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_11, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_10, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_9, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_8, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_7, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_6, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_5, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_4, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_18, &imgair_conditioner_off_png);
          lv_img_set_src(ima_air_17, &imgair_conditioner_off_png);
          break;
      case 29:
          lv_obj_set_x(ima_air_sign, 332);
          lv_img_set_src(ima_air_17, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_16, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_15, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_14, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_13, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_12, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_11, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_10, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_9, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_8, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_7, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_6, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_5, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_4, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_18, &imgair_conditioner_off_png);
          break;
      case 30:
          lv_obj_set_x(ima_air_sign, 348);
          lv_img_set_src(ima_air_18, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_17, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_16, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_15, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_14, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_13, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_12, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_11, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_10, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_9, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_8, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_7, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_6, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_5, &imgair_conditioner_on_png);
          lv_img_set_src(ima_air_4, &imgair_conditioner_on_png);
          break;
      }

}

void lv_anim_ima_equ_smi_function_cb(void* obj,lv_anim_value_t values) {
  lv_obj_set_y(obj, values);

}

void list_event_handler(lv_obj_t* obj, lv_event_t* event) {
     if(event == LV_EVENT_SHORT_CLICKED)
     {
         if(obj == list_main_son[0])
         {
              screen_set_delete();
              screen_wifi_set_show();
         }else if(obj == list_main_son[1])
         {
              screen_tileview_equi_sign = 1;
              screen_set_delete();
              scr_equipment_show();
         }
     } 

}

void lv_anim_tile2_bar_function(void) {
    bar_tile2_bar_stop_sign = 1;
    lv_anim_path_init(&all_anim_obj_path);
    lv_anim_path_set_cb(&all_anim_obj_path, lv_anim_path_ease_in_out);
    lv_anim_set_path(&all_anim_obj, &all_anim_obj_path);
    lv_anim_init(&all_anim_obj);
    lv_anim_set_var(&all_anim_obj, bar_tile2_bar);
    bar_tile2_bar_value = lv_bar_get_value(bar_tile2_bar);
    if(bar_tile2_bar_sign == 1)/* open */
    {
      lv_anim_set_values(&all_anim_obj, bar_tile2_bar_value, 100);
  
    }else if(bar_tile2_bar_sign == 2)/* close */
    {
      lv_anim_set_values(&all_anim_obj, bar_tile2_bar_value, 0);
    }
    lv_anim_set_time(&all_anim_obj, 3000);
    lv_anim_set_playback_delay(&all_anim_obj, 0);
    lv_anim_set_playback_time(&all_anim_obj, 0);
    lv_anim_set_repeat_delay(&all_anim_obj, 0);
    lv_anim_set_repeat_count(&all_anim_obj, 0);
    lv_anim_set_exec_cb(&all_anim_obj, (lv_anim_exec_xcb_t)lv_anim_tile2_bar_function_cb);
    lv_anim_start(&all_anim_obj);

}

void lv_anim_ima_cur_ri_function_cb(void* obj,lv_anim_value_t values) {
      lv_obj_set_x(obj, values);
      bar_tile2_bar_value = 100-(((422-lv_obj_get_x(ima_cur_cri))*100)/165);

}

void lv_anim_ima_equ_smi_function(void) {
    lv_anim_path_init(&all_anim_obj_path);
    lv_anim_path_set_cb(&all_anim_obj_path, lv_anim_path_ease_in_out);
    lv_anim_set_path(&all_anim_obj, &all_anim_obj_path);
    lv_anim_init(&all_anim_obj);
    lv_anim_set_var(&all_anim_obj, ima_equ_smi);
    lv_anim_set_values(&all_anim_obj, 188, 178);
    lv_anim_set_time(&all_anim_obj, 1000);
    lv_anim_set_playback_delay(&all_anim_obj, 0);
    lv_anim_set_playback_time(&all_anim_obj, 1000);
    lv_anim_set_repeat_delay(&all_anim_obj, 0);
    lv_anim_set_repeat_count(&all_anim_obj, LV_ANIM_REPEAT_INFINITE);
    lv_anim_set_exec_cb(&all_anim_obj, (lv_anim_exec_xcb_t)lv_anim_ima_equ_smi_function_cb);
    lv_anim_start(&all_anim_obj);

}

void my_list_create_fullction(void) {
      list_main = lv_list_create(screen_set, NULL);
      lv_obj_set_size(list_main, 480, 400);
      lv_obj_set_pos(list_main,0,80);    
      lv_list_set_scroll_propagation(list_main,false);
      lv_list_set_edge_flash(list_main, false);
      lv_obj_set_style_local_bg_color(list_main,0,0,LV_COLOR_MAKE(0x10,0x27,0x30));
      lv_obj_set_style_local_bg_opa(list_main,0,0,LV_OPA_COVER);
      lv_obj_set_style_local_border_width(list_main,0,0,0);
      lv_obj_set_style_local_radius(list_main,LV_BTN_PART_MAIN,LV_STATE_DEFAULT,0);
      lv_obj_set_style_local_radius(list_main,LV_BTN_PART_MAIN,LV_STATE_PRESSED,0);
      lv_obj_set_style_local_radius(list_main,LV_BTN_PART_MAIN,LV_STATE_FOCUSED,0);
  
    lv_obj_set_style_local_text_color(list_main,LV_LIST_PART_BG, LV_STATE_DEFAULT, LV_COLOR_MAKE(0xff, 0xff, 0xff));     
    lv_obj_set_style_local_bg_color(list_main,LV_LIST_PART_BG, LV_STATE_DEFAULT, LV_COLOR_MAKE(0x20, 0x20, 0x20));
    lv_obj_set_style_local_border_width(list_main,LV_LIST_PART_BG, LV_STATE_DEFAULT, 0);     
    lv_obj_set_style_local_border_color(list_main,LV_LIST_PART_BG, LV_STATE_DEFAULT, LV_COLOR_MAKE(0xd6, 0xdd, 0xe3));     
    lv_obj_set_style_local_bg_color(list_main,LV_LIST_PART_BG, LV_STATE_PRESSED, LV_COLOR_MAKE(0x00, 0x00, 0x00));     
    lv_obj_set_style_local_bg_opa(list_main,LV_LIST_PART_BG, LV_STATE_DEFAULT, LV_OPA_COVER);
    lv_obj_set_style_local_border_width(list_main,LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 0);
    lv_obj_set_style_local_border_width(list_main,LV_BTN_PART_MAIN, LV_STATE_PRESSED, 0);
    lv_obj_set_style_local_border_width(list_main,LV_BTN_PART_MAIN, LV_STATE_FOCUSED, 0);
    lv_list_set_scrollbar_mode(list_main, LV_SCROLLBAR_MODE_OFF);
  

      list_main_son[0] = lv_list_add_btn(list_main, NULL, NULL);
      lv_obj_set_size(list_main_son[0], 480, 80);
    lv_obj_set_style_local_bg_opa(list_main_son[0],LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 255); 
    lv_obj_set_style_local_bg_color(list_main_son[0],LV_BTN_PART_MAIN, LV_STATE_DEFAULT, lv_color_hex(0x202020));
    lv_obj_set_style_local_bg_color(list_main_son[0],LV_BTN_PART_MAIN, LV_STATE_PRESSED, lv_color_hex(0x000000));
    lv_obj_set_style_local_border_opa(list_main_son[0],LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 0);
    lv_obj_set_style_local_border_opa(list_main_son[0],LV_BTN_PART_MAIN, LV_STATE_PRESSED, 0);
    lv_obj_set_style_local_border_opa(list_main_son[0],LV_BTN_PART_MAIN, LV_STATE_FOCUSED, 0);       
    lv_btn_set_layout(list_main_son[0], LV_LAYOUT_OFF);     
    lv_btn_set_fit2(list_main_son[0], LV_FIT_NONE, LV_FIT_NONE);
  
    lv_obj_set_style_local_outline_width(list_main_son[0],0, LV_STATE_FOCUSED, 0);
    lv_obj_set_style_local_border_width(list_main_son[0],0, LV_STATE_FOCUSED, 0);
    lv_obj_set_style_local_border_width(list_main_son[0],0, LV_STATE_DEFAULT, 0);
  
    lv_obj_set_style_local_image_opa(list_main_son[0],0,LV_STATE_DEFAULT, LV_OPA_70);
    lv_obj_set_style_local_image_opa(list_main_son[0],0, LV_STATE_PRESSED, LV_OPA_100);
    lv_obj_set_style_local_text_opa(list_main_son[0],0,LV_STATE_DEFAULT, LV_OPA_70);
    lv_obj_set_style_local_text_opa(list_main_son[0],0, LV_STATE_PRESSED, LV_OPA_100);
    lv_obj_set_event_cb(list_main_son[0], list_event_handler);
  
      ima_list_wifi = lv_img_create(list_main_son[0], NULL);
      lv_img_set_src(ima_list_wifi, &imglist_wifi_png); 
      lv_obj_set_pos(ima_list_wifi, 40, 32); 
      lv_obj_set_hidden(ima_list_wifi, false);
  
      ima_list_wifi_return = lv_img_create(list_main_son[0], NULL);
      lv_img_set_src(ima_list_wifi_return, &imglist_return_png); 
      lv_obj_set_pos(ima_list_wifi_return, 423, 34); 
      lv_obj_set_hidden(ima_list_wifi_return, false);
  
      lab_list_wifi = lv_label_create(list_main_son[0], NULL);
      lv_obj_set_size(lab_list_wifi, 93, 22);
      lv_obj_set_pos(lab_list_wifi, 97, 34);
      lv_obj_set_style_local_text_font(lab_list_wifi,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_23);
      lv_label_set_text(lab_list_wifi, "无线网络"); 
      lv_obj_set_hidden(lab_list_wifi, false);
  
      lab_list_wifi_name = lv_label_create(list_main_son[0], NULL);
      lv_obj_set_size(lab_list_wifi_name, 174, 19);
      lv_obj_set_pos(lab_list_wifi_name, 248, 34);
      lv_obj_set_style_local_text_font(lab_list_wifi_name,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_19);
      lv_label_set_text(lab_list_wifi_name, ""); 
      lv_obj_set_hidden(lab_list_wifi_name, false);
  
      list_main_son[1] = lv_list_add_btn(list_main, NULL, NULL);
      lv_obj_set_size(list_main_son[1], 480, 80);
    lv_obj_set_style_local_bg_color(list_main_son[1],LV_BTN_PART_MAIN, LV_STATE_DEFAULT, lv_color_hex(0x202020));
    lv_obj_set_style_local_bg_color(list_main_son[1],LV_BTN_PART_MAIN, LV_STATE_PRESSED, lv_color_hex(0x000000));
    lv_obj_set_style_local_bg_opa(list_main_son[1],LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 255);  
    lv_obj_set_style_local_border_opa(list_main_son[1],LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 0);
    lv_obj_set_style_local_border_opa(list_main_son[1],LV_BTN_PART_MAIN, LV_STATE_PRESSED, 0);
    lv_obj_set_style_local_border_opa(list_main_son[1],LV_BTN_PART_MAIN, LV_STATE_FOCUSED, 0);      
    lv_btn_set_layout(list_main_son[1], LV_LAYOUT_OFF);     
    lv_btn_set_fit2(list_main_son[1], LV_FIT_NONE, LV_FIT_NONE);
  
    lv_obj_set_style_local_outline_width(list_main_son[1],0, LV_STATE_FOCUSED, 0);
    lv_obj_set_style_local_border_width(list_main_son[1],0, LV_STATE_FOCUSED, 0);
    lv_obj_set_style_local_border_width(list_main_son[1],0, LV_STATE_DEFAULT, 0);
  
    lv_obj_set_style_local_image_opa(list_main_son[1],0,LV_STATE_DEFAULT, LV_OPA_70);
    lv_obj_set_style_local_image_opa(list_main_son[1],0, LV_STATE_PRESSED, LV_OPA_100);
    lv_obj_set_style_local_text_opa(list_main_son[1],0,LV_STATE_DEFAULT, LV_OPA_70);
    lv_obj_set_style_local_text_opa(list_main_son[1],0, LV_STATE_PRESSED, LV_OPA_100);
    lv_obj_set_event_cb(list_main_son[1], list_event_handler);
  
      ima_list_equipment = lv_img_create(list_main_son[1], NULL);
      lv_img_set_src(ima_list_equipment, &imglist_equipment_png); 
      lv_obj_set_pos(ima_list_equipment, 40, 32); 
      lv_obj_set_hidden(ima_list_equipment, false);
  
      ima_list_equipment_return = lv_img_create(list_main_son[1], NULL);
      lv_img_set_src(ima_list_equipment_return, &imglist_return_png); 
      lv_obj_set_pos(ima_list_equipment_return, 423, 34); 
      lv_obj_set_hidden(ima_list_equipment_return, false);
  
      lab_list_equipment = lv_label_create(list_main_son[1], NULL);
      lv_obj_set_size(lab_list_equipment, 93, 22);
      lv_obj_set_pos(lab_list_equipment, 97, 34);
      lv_obj_set_style_local_text_font(lab_list_equipment,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_23);
      lv_label_set_text(lab_list_equipment, "添加设备"); 
      lv_obj_set_hidden(lab_list_equipment, false);
  
      list_main_son[2] = lv_list_add_btn(list_main, NULL, NULL);
      lv_obj_set_size(list_main_son[2], 480, 80);
    lv_obj_set_style_local_bg_color(list_main_son[2],LV_LIST_PART_BG, LV_STATE_DEFAULT, lv_color_hex(0x202020));
    lv_obj_set_style_local_bg_color(list_main_son[2],LV_LIST_PART_BG, LV_STATE_PRESSED, lv_color_hex(0x000000));
    lv_obj_set_style_local_bg_opa(list_main_son[2],LV_LIST_PART_BG, LV_STATE_DEFAULT, 255);  
    lv_obj_set_style_local_border_opa(list_main_son[2],LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 0);
    lv_obj_set_style_local_border_opa(list_main_son[2],LV_BTN_PART_MAIN, LV_STATE_PRESSED, 0);
    lv_obj_set_style_local_border_opa(list_main_son[2],LV_BTN_PART_MAIN, LV_STATE_FOCUSED, 0);
    lv_btn_set_layout(list_main_son[2], LV_LAYOUT_OFF);     
    lv_btn_set_fit2(list_main_son[2], LV_FIT_NONE, LV_FIT_NONE); 
  
    lv_obj_set_style_local_outline_width(list_main_son[2],0, LV_STATE_FOCUSED, 0);
    lv_obj_set_style_local_border_width(list_main_son[2],0, LV_STATE_FOCUSED, 0);
    lv_obj_set_style_local_border_width(list_main_son[2],0, LV_STATE_DEFAULT, 0);
  
    lv_obj_set_style_local_image_opa(list_main_son[2],0,LV_STATE_DEFAULT, LV_OPA_70);
    lv_obj_set_style_local_image_opa(list_main_son[2],0, LV_STATE_PRESSED, LV_OPA_100);
    lv_obj_set_style_local_text_opa(list_main_son[2],0,LV_STATE_DEFAULT, LV_OPA_70);
    lv_obj_set_style_local_text_opa(list_main_son[2],0, LV_STATE_PRESSED, LV_OPA_100);
  
      ima_list_voice = lv_img_create(list_main_son[2], NULL);
      lv_img_set_src(ima_list_voice, &imglist_voice_png); 
      lv_obj_set_pos(ima_list_voice, 40, 32); 
      lv_obj_set_hidden(ima_list_voice, false);
  
      ima_list_voice_return = lv_img_create(list_main_son[2], NULL);
      lv_img_set_src(ima_list_voice_return, &imglist_return_png); 
      lv_obj_set_pos(ima_list_voice_return, 423, 34); 
      lv_obj_set_hidden(ima_list_voice_return, false);
  
      lab_list_voice = lv_label_create(list_main_son[2], NULL);
      lv_obj_set_size(lab_list_voice, 93, 22);
      lv_obj_set_pos(lab_list_voice, 97, 34);
      lv_obj_set_style_local_text_font(lab_list_voice,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_23);
      lv_label_set_text(lab_list_voice, "语音控制"); 
      lv_obj_set_hidden(lab_list_voice, false);
  
      lab_list_voice_sign = lv_label_create(list_main_son[2], NULL);
      lv_obj_set_size(lab_list_voice_sign, 56, 19);
      lv_obj_set_pos(lab_list_voice_sign, 362, 34);
      lv_obj_set_style_local_text_font(lab_list_voice_sign,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_19);
      lv_label_set_text(lab_list_voice_sign, "已开启"); 
      lv_obj_set_hidden(lab_list_voice_sign, false);
  
  /* 显示--show */
      list_main_son[3] = lv_list_add_btn(list_main, NULL, NULL);
      lv_obj_set_size(list_main_son[3], 480, 80);
    lv_obj_set_style_local_bg_color(list_main_son[3],LV_LIST_PART_BG, LV_STATE_DEFAULT, lv_color_hex(0x202020));
    lv_obj_set_style_local_bg_color(list_main_son[3],LV_LIST_PART_BG, LV_STATE_PRESSED, lv_color_hex(0x000000));
    lv_obj_set_style_local_bg_opa(list_main_son[3],LV_LIST_PART_BG, LV_STATE_DEFAULT, 255);  
    lv_obj_set_style_local_border_opa(list_main_son[3],LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 0);
    lv_obj_set_style_local_border_opa(list_main_son[3],LV_BTN_PART_MAIN, LV_STATE_PRESSED, 0);
    lv_obj_set_style_local_border_opa(list_main_son[3],LV_BTN_PART_MAIN, LV_STATE_FOCUSED, 0);  
    lv_btn_set_layout(list_main_son[3], LV_LAYOUT_OFF);     
    lv_btn_set_fit2(list_main_son[3], LV_FIT_NONE, LV_FIT_NONE);
  
    lv_obj_set_style_local_outline_width(list_main_son[3],0, LV_STATE_FOCUSED, 0);
    lv_obj_set_style_local_border_width(list_main_son[3],0, LV_STATE_FOCUSED, 0);
    lv_obj_set_style_local_border_width(list_main_son[3],0, LV_STATE_DEFAULT, 0);  
  
    lv_obj_set_style_local_image_opa(list_main_son[3],0,LV_STATE_DEFAULT, LV_OPA_70);
    lv_obj_set_style_local_image_opa(list_main_son[3],0, LV_STATE_PRESSED, LV_OPA_100);
    lv_obj_set_style_local_text_opa(list_main_son[3],0,LV_STATE_DEFAULT, LV_OPA_70);
    lv_obj_set_style_local_text_opa(list_main_son[3],0, LV_STATE_PRESSED, LV_OPA_100);
  
      ima_list_show = lv_img_create(list_main_son[3], NULL);
      lv_img_set_src(ima_list_show, &imglist_show_png); 
      lv_obj_set_pos(ima_list_show, 40, 32); 
      lv_obj_set_hidden(ima_list_show, false);
  
      ima_list_show_return = lv_img_create(list_main_son[3], NULL);
      lv_img_set_src(ima_list_show_return, &imglist_return_png); 
      lv_obj_set_pos(ima_list_show_return, 423, 34); 
      lv_obj_set_hidden(ima_list_show_return, false);
  
      lab_list_show = lv_label_create(list_main_son[3], NULL);
      lv_obj_set_size(lab_list_show, 46, 22);
      lv_obj_set_pos(lab_list_show, 97, 34);
      lv_obj_set_style_local_text_font(lab_list_show,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_23);
      lv_label_set_text(lab_list_show, "显示"); 
      lv_obj_set_hidden(lab_list_show, false);
  
      list_main_son[4] = lv_list_add_btn(list_main, NULL, NULL);
      lv_obj_set_size(list_main_son[4], 480, 80);
    lv_obj_set_style_local_bg_color(list_main_son[4],LV_LIST_PART_BG, LV_STATE_DEFAULT, lv_color_hex(0x202020));
    lv_obj_set_style_local_bg_color(list_main_son[4],LV_LIST_PART_BG, LV_STATE_PRESSED, lv_color_hex(0x000000));
    lv_obj_set_style_local_bg_opa(list_main_son[4],LV_LIST_PART_BG, LV_STATE_DEFAULT, 255);  
    lv_obj_set_style_local_border_opa(list_main_son[4],LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 0);
    lv_obj_set_style_local_border_opa(list_main_son[4],LV_BTN_PART_MAIN, LV_STATE_PRESSED, 0);
    lv_obj_set_style_local_border_opa(list_main_son[4],LV_BTN_PART_MAIN, LV_STATE_FOCUSED, 0);  
    lv_btn_set_layout(list_main_son[4], LV_LAYOUT_OFF);     
    lv_btn_set_fit2(list_main_son[4], LV_FIT_NONE, LV_FIT_NONE); 
  
    lv_obj_set_style_local_outline_width(list_main_son[4],0, LV_STATE_FOCUSED, 0);
    lv_obj_set_style_local_border_width(list_main_son[4],0, LV_STATE_FOCUSED, 0);
    lv_obj_set_style_local_border_width(list_main_son[4],0, LV_STATE_DEFAULT, 0);
  
    lv_obj_set_style_local_image_opa(list_main_son[4],0,LV_STATE_DEFAULT, LV_OPA_70);
    lv_obj_set_style_local_image_opa(list_main_son[4],0, LV_STATE_PRESSED, LV_OPA_100);
    lv_obj_set_style_local_text_opa(list_main_son[4],0,LV_STATE_DEFAULT, LV_OPA_70);
    lv_obj_set_style_local_text_opa(list_main_son[4],0, LV_STATE_PRESSED, LV_OPA_100);
  
      ima_list_song = lv_img_create(list_main_son[4], NULL);
      lv_img_set_src(ima_list_song, &imglist_song_png); 
      lv_obj_set_pos(ima_list_song, 40, 32); 
      lv_obj_set_hidden(ima_list_song, false);
  
      ima_list_song_return = lv_img_create(list_main_son[4], NULL);
      lv_img_set_src(ima_list_song_return, &imglist_return_png); 
      lv_obj_set_pos(ima_list_song_return, 423, 34); 
      lv_obj_set_hidden(ima_list_song_return, false);
  
      lab_list_song = lv_label_create(list_main_son[4], NULL);
      lv_obj_set_size(lab_list_song, 46, 22);
      lv_obj_set_pos(lab_list_song, 97, 34);
      lv_obj_set_style_local_text_font(lab_list_song,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_23);
      lv_label_set_text(lab_list_song, "声音"); 
      lv_obj_set_hidden(lab_list_song, false);
  
      list_main_son[5] = lv_list_add_btn(list_main, NULL, NULL);
      lv_obj_set_size(list_main_son[5], 480, 80);
    lv_obj_set_style_local_bg_color(list_main_son[5],LV_LIST_PART_BG, LV_STATE_DEFAULT, lv_color_hex(0x202020));
    lv_obj_set_style_local_bg_color(list_main_son[5],LV_LIST_PART_BG, LV_STATE_PRESSED, lv_color_hex(0x000000));
    lv_obj_set_style_local_bg_opa(list_main_son[5],LV_LIST_PART_BG, LV_STATE_DEFAULT, 255);  
    lv_obj_set_style_local_border_opa(list_main_son[5],LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 0);
    lv_obj_set_style_local_border_opa(list_main_son[5],LV_BTN_PART_MAIN, LV_STATE_PRESSED, 0);
    lv_obj_set_style_local_border_opa(list_main_son[5],LV_BTN_PART_MAIN, LV_STATE_FOCUSED, 0);   
    lv_btn_set_layout(list_main_son[5], LV_LAYOUT_OFF);     
    lv_btn_set_fit2(list_main_son[5], LV_FIT_NONE, LV_FIT_NONE); 
  
    lv_obj_set_style_local_outline_width(list_main_son[5],0, LV_STATE_FOCUSED, 0);
    lv_obj_set_style_local_border_width(list_main_son[5],0, LV_STATE_FOCUSED, 0);
    lv_obj_set_style_local_border_width(list_main_son[5],0, LV_STATE_DEFAULT, 0);
  
    lv_obj_set_style_local_image_opa(list_main_son[5],0,LV_STATE_DEFAULT, LV_OPA_70);
    lv_obj_set_style_local_image_opa(list_main_son[5],0, LV_STATE_PRESSED, LV_OPA_100);
    lv_obj_set_style_local_text_opa(list_main_son[5],0,LV_STATE_DEFAULT, LV_OPA_70);
    lv_obj_set_style_local_text_opa(list_main_son[5],0, LV_STATE_PRESSED, LV_OPA_100);
  
      ima_list_song = lv_img_create(list_main_son[5], NULL);
      lv_img_set_src(ima_list_song, &imglist_user_png); 
      lv_obj_set_pos(ima_list_song, 40, 32); 
      lv_obj_set_hidden(ima_list_song, false);
  
      ima_list_song_return = lv_img_create(list_main_son[5], NULL);
      lv_img_set_src(ima_list_song_return, &imglist_return_png); 
      lv_obj_set_pos(ima_list_song_return, 423, 34); 
      lv_obj_set_hidden(ima_list_song_return, false);
  
      lab_list_song = lv_label_create(list_main_son[5], NULL);
      lv_obj_set_size(lab_list_song, 93, 22);
      lv_obj_set_pos(lab_list_song, 97, 34);
      lv_obj_set_style_local_text_font(lab_list_song,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_23);
      lv_label_set_text(lab_list_song, "用户指南"); 
      lv_obj_set_hidden(lab_list_song, false);
  
  /* 系统升级--ota */
      list_main_son[6] = lv_list_add_btn(list_main, NULL, NULL);
      lv_obj_set_size(list_main_son[6], 480, 80);
    lv_obj_set_style_local_bg_color(list_main_son[6],LV_LIST_PART_BG, LV_STATE_DEFAULT, lv_color_hex(0x202020));
    lv_obj_set_style_local_bg_color(list_main_son[6],LV_LIST_PART_BG, LV_STATE_PRESSED, lv_color_hex(0x000000));
    lv_obj_set_style_local_bg_opa(list_main_son[6],LV_LIST_PART_BG, LV_STATE_DEFAULT, 255);  
    lv_obj_set_style_local_border_opa(list_main_son[6],LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 0);
    lv_obj_set_style_local_border_opa(list_main_son[6],LV_BTN_PART_MAIN, LV_STATE_PRESSED, 0);
    lv_obj_set_style_local_border_opa(list_main_son[6],LV_BTN_PART_MAIN, LV_STATE_FOCUSED, 0);    
    lv_btn_set_layout(list_main_son[6], LV_LAYOUT_OFF);     
    lv_btn_set_fit2(list_main_son[6], LV_FIT_NONE, LV_FIT_NONE); 
  
    lv_obj_set_style_local_outline_width(list_main_son[6],0, LV_STATE_FOCUSED, 0);
    lv_obj_set_style_local_border_width(list_main_son[6],0, LV_STATE_FOCUSED, 0);
    lv_obj_set_style_local_border_width(list_main_son[6],0, LV_STATE_DEFAULT, 0);  
  
    lv_obj_set_style_local_image_opa(list_main_son[6],0,LV_STATE_DEFAULT, LV_OPA_70);
    lv_obj_set_style_local_image_opa(list_main_son[6],0, LV_STATE_PRESSED, LV_OPA_100);
    lv_obj_set_style_local_text_opa(list_main_son[6],0,LV_STATE_DEFAULT, LV_OPA_70);
    lv_obj_set_style_local_text_opa(list_main_son[6],0, LV_STATE_PRESSED, LV_OPA_100);
  
      ima_list_ota = lv_img_create(list_main_son[6], NULL);
      lv_img_set_src(ima_list_ota, &imglist_ota_png); 
      lv_obj_set_pos(ima_list_ota, 40, 32); 
      lv_obj_set_hidden(ima_list_ota, false);
  
      ima_list_ota_return = lv_img_create(list_main_son[6], NULL);
      lv_img_set_src(ima_list_ota_return, &imglist_return_png); 
      lv_obj_set_pos(ima_list_ota_return, 423, 34); 
      lv_obj_set_hidden(ima_list_ota_return, false);
  
      lab_list_ota = lv_label_create(list_main_son[6], NULL);
      lv_obj_set_size(lab_list_ota, 93, 22);
      lv_obj_set_pos(lab_list_ota, 97, 34);
      lv_obj_set_style_local_text_font(lab_list_ota,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_23);
      lv_label_set_text(lab_list_ota, "系统升级"); 
      lv_obj_set_hidden(lab_list_ota, false);
  
      lab_list_ota_name = lv_label_create(list_main_son[6], NULL);
      lv_obj_set_size(lab_list_ota_name, 56, 19);
      lv_obj_set_pos(lab_list_ota_name, 362, 34);
      lv_obj_set_style_local_text_font(lab_list_ota_name,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_19);
      lv_label_set_text(lab_list_ota_name, "新版本"); 
      lv_obj_set_hidden(lab_list_ota_name, false);
  
      list_main_son[7] = lv_list_add_btn(list_main, NULL, NULL);
      lv_obj_set_size(list_main_son[7], 480, 80);
    lv_obj_set_style_local_bg_color(list_main_son[7],LV_LIST_PART_BG, LV_STATE_DEFAULT, lv_color_hex(0x202020));
    lv_obj_set_style_local_bg_color(list_main_son[7],LV_LIST_PART_BG, LV_STATE_PRESSED, lv_color_hex(0x000000));
    lv_obj_set_style_local_bg_opa(list_main_son[7],LV_LIST_PART_BG, LV_STATE_DEFAULT, 255);  
    lv_obj_set_style_local_border_opa(list_main_son[7],LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 0);
    lv_obj_set_style_local_border_opa(list_main_son[7],LV_BTN_PART_MAIN, LV_STATE_PRESSED, 0);
    lv_obj_set_style_local_border_opa(list_main_son[7],LV_BTN_PART_MAIN, LV_STATE_FOCUSED, 0);   
    lv_btn_set_layout(list_main_son[7], LV_LAYOUT_OFF);     
    lv_btn_set_fit2(list_main_son[7], LV_FIT_NONE, LV_FIT_NONE);
  
    lv_obj_set_style_local_outline_width(list_main_son[7],0, LV_STATE_FOCUSED, 0);
    lv_obj_set_style_local_border_width(list_main_son[7],0, LV_STATE_FOCUSED, 0);
    lv_obj_set_style_local_border_width(list_main_son[7],0, LV_STATE_DEFAULT, 0);
  
    lv_obj_set_style_local_image_opa(list_main_son[7],0,LV_STATE_DEFAULT, LV_OPA_70);
    lv_obj_set_style_local_image_opa(list_main_son[7],0, LV_STATE_PRESSED, LV_OPA_100);
    lv_obj_set_style_local_text_opa(list_main_son[7],0,LV_STATE_DEFAULT, LV_OPA_70);
    lv_obj_set_style_local_text_opa(list_main_son[7],0, LV_STATE_PRESSED, LV_OPA_100);
  
      ima_list_about = lv_img_create(list_main_son[7], NULL);
      lv_img_set_src(ima_list_about, &imglist_about_png); 
      lv_obj_set_pos(ima_list_about, 40, 32); 
      lv_obj_set_hidden(ima_list_about, false);
  
      ima_list_about_return = lv_img_create(list_main_son[7], NULL);
      lv_img_set_src(ima_list_about_return, &imglist_return_png); 
      lv_obj_set_pos(ima_list_about_return, 423, 34); 
      lv_obj_set_hidden(ima_list_about_return, false);
  
      lab_list_about = lv_label_create(list_main_son[7], NULL);
      lv_obj_set_size(lab_list_about, 93, 22);
      lv_obj_set_pos(lab_list_about, 97, 34);
      lv_obj_set_style_local_text_font(lab_list_about,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_23);
      lv_label_set_text(lab_list_about, "关于本机"); 
      lv_obj_set_hidden(lab_list_about, false);

}

void lv_anim_ima_cur_function(void) {
      lv_anim_path_init(&all_anim_obj_path);
      lv_anim_path_set_cb(&all_anim_obj_path, lv_anim_path_ease_in_out);
      lv_anim_set_path(&all_anim_obj, &all_anim_obj_path);
      lv_anim_init(&all_anim_obj);
      lv_anim_set_var(&all_anim_obj, ima_cur_cle);
      if(ima_cur_on_sign == 0)
      {
          ima_cur_on_sign = 1;
      }else if(ima_cur_on_sign == 1)
      {
          ima_cur_on_sign = 2;
      }else if(ima_cur_on_sign == 2)
      {
          ima_cur_on_sign = 1;
      }
  
      if(ima_cur_on_sign == 1)/* open */
      {
          lv_anim_set_values(&all_anim_obj, lv_obj_get_x(ima_cur_cle), (-105));
          if((lv_obj_get_x(ima_cur_cle)) <= 60 && (lv_obj_get_x(ima_cur_cle)) > 40)
          {
              lv_anim_set_time(&all_anim_obj, 8000);
          }else if((lv_obj_get_x(ima_cur_cle)) <= 40 && (lv_obj_get_x(ima_cur_cle)) > 20)
          {
              lv_anim_set_time(&all_anim_obj, 7000);
          }else if((lv_obj_get_x(ima_cur_cle)) <= 20 && (lv_obj_get_x(ima_cur_cle)) > 0)
          {
              lv_anim_set_time(&all_anim_obj, 6000);
          }else if((lv_obj_get_x(ima_cur_cle)) <= 0 && (lv_obj_get_x(ima_cur_cle)) > (-20))
          {
              lv_anim_set_time(&all_anim_obj, 5000);
          }else if((lv_obj_get_x(ima_cur_cle)) <= (-20) && (lv_obj_get_x(ima_cur_cle)) > (-40))
          {
              lv_anim_set_time(&all_anim_obj, 4000);
          }else if((lv_obj_get_x(ima_cur_cle)) <= (-40) && (lv_obj_get_x(ima_cur_cle)) > (-60))
          {
              lv_anim_set_time(&all_anim_obj, 3000);
          }else if((lv_obj_get_x(ima_cur_cle)) <= (-60) && (lv_obj_get_x(ima_cur_cle)) > (-80))
          {
              lv_anim_set_time(&all_anim_obj, 2000);
          }else if((lv_obj_get_x(ima_cur_cle)) <= (-80) && (lv_obj_get_x(ima_cur_cle)) >= (-105))
          {
              lv_anim_set_time(&all_anim_obj, 1000);
          }
      }else if(ima_cur_on_sign == 2)/* close */
      {
          lv_anim_set_values(&all_anim_obj, lv_obj_get_x(ima_cur_cle), 60);
          if((lv_obj_get_x(ima_cur_cle)) <= 60 && (lv_obj_get_x(ima_cur_cle)) > 40)
          {
              lv_anim_set_time(&all_anim_obj, 1000);
          }else if((lv_obj_get_x(ima_cur_cle)) <= 40 && (lv_obj_get_x(ima_cur_cle)) > 20)
          {
              lv_anim_set_time(&all_anim_obj, 2000);
          }else if((lv_obj_get_x(ima_cur_cle)) <= 20 && (lv_obj_get_x(ima_cur_cle)) > 0)
          {
              lv_anim_set_time(&all_anim_obj, 3000);
          }else if((lv_obj_get_x(ima_cur_cle)) <= 0 && (lv_obj_get_x(ima_cur_cle)) > (-20))
          {
              lv_anim_set_time(&all_anim_obj, 4000);
          }else if((lv_obj_get_x(ima_cur_cle)) <= (-20) && (lv_obj_get_x(ima_cur_cle)) > (-40))
          {
              lv_anim_set_time(&all_anim_obj, 5000);
          }else if((lv_obj_get_x(ima_cur_cle)) <= (-40) && (lv_obj_get_x(ima_cur_cle)) > (-60))
          {
              lv_anim_set_time(&all_anim_obj, 6000);
          }else if((lv_obj_get_x(ima_cur_cle)) <= (-60) && (lv_obj_get_x(ima_cur_cle)) > (-80))
          {
              lv_anim_set_time(&all_anim_obj, 7000);
          }else if((lv_obj_get_x(ima_cur_cle)) <= (-80) && (lv_obj_get_x(ima_cur_cle)) >= (-105))
          {
              lv_anim_set_time(&all_anim_obj, 8000);
          }
      }
  
      lv_anim_set_playback_delay(&all_anim_obj, 0);
      lv_anim_set_playback_time(&all_anim_obj, 0);
      lv_anim_set_repeat_delay(&all_anim_obj, 0);
      lv_anim_set_repeat_count(&all_anim_obj, 0);
      lv_anim_set_exec_cb(&all_anim_obj, (lv_anim_exec_xcb_t)lv_anim_ima_cur_le_function_cb);
      lv_anim_start(&all_anim_obj);
  
      lv_anim_set_var(&all_anim_obj, ima_cur_cri);
      if(ima_cur_on_sign == 1)/* open */
      {
          lv_anim_set_values(&all_anim_obj, lv_obj_get_x(ima_cur_cri), 422);
      }else if(ima_cur_on_sign == 2)/* close */
      {
          lv_anim_set_values(&all_anim_obj, lv_obj_get_x(ima_cur_cri), 257);
      }
      lv_anim_set_exec_cb(&all_anim_obj, (lv_anim_exec_xcb_t)lv_anim_ima_cur_ri_function_cb);
      lv_anim_start(&all_anim_obj);

}

void redrag_obj(lv_anim_t * a) {
      lv_obj_set_drag(screen_cont,true);
      if (((int)lv_obj_get_y(screen_cont)) < -100) {
        lv_obj_set_style_local_bg_opa(screen_cont, LV_CONT_PART_MAIN, LV_STATE_DEFAULT,255);
      } else {
        lv_obj_set_style_local_bg_opa(screen_cont, LV_CONT_PART_MAIN, LV_STATE_DEFAULT,245);
      }

}

void obj_move(lv_obj_t* obj,int y_start,int y_end) {
    lv_anim_t a;
            lv_anim_init(&a);
            lv_anim_set_var(&a, obj);
            lv_anim_set_values(&a, y_start, y_end);
            lv_anim_set_exec_cb(&a, (lv_anim_exec_xcb_t)lv_obj_set_y);
            lv_anim_set_time(&a, 400);
    lv_anim_set_ready_cb(&a,redrag_obj);
            lv_anim_start(&a);
  

}

int screen_main_anim_sign = -1; 

lv_task_t* _task_callback_50kf8f;
void callback_50kf8f(lv_task_t* t){
  static int _timer_index=1;
  if(_timer_index<1)
    _timer_index=1;
  if (((int)_timer_index) == 1) {
    screen_saver_show();
    screen_main_anim_sign = 1;
  }

  _timer_index++;
}


lv_task_t* _task_callback_3hxqvc;
void callback_3hxqvc(lv_task_t* t){
  static int _timer_index=1;
  if(_timer_index<1)
    _timer_index=1;
  if (((int)screen_tileview_sign) == 0) {
    lv_coord_t x, y;
    lv_tileview_get_tile_act(tile_main, &x, &y);
    if (x == 0 && y == 0) {
        lv_obj_set_style_local_bg_opa(but_tile_left,LV_BTN_PART_MAIN, LV_BTN_STATE_RELEASED, LV_OPA_COVER);
        lv_obj_set_style_local_bg_opa(but_tile_middle,LV_BTN_PART_MAIN, LV_BTN_STATE_RELEASED, LV_OPA_60);
        lv_obj_set_style_local_bg_opa(but_tile_right,LV_BTN_PART_MAIN, LV_BTN_STATE_RELEASED, LV_OPA_60); 
        screen_tileview_show_sign = 0; 
    }
    else if (x == 1 && y == 0) {
        lv_obj_set_style_local_bg_opa(but_tile_left,LV_BTN_PART_MAIN, LV_BTN_STATE_RELEASED, LV_OPA_60);
        lv_obj_set_style_local_bg_opa(but_tile_middle,LV_BTN_PART_MAIN, LV_BTN_STATE_RELEASED, LV_OPA_COVER);
        lv_obj_set_style_local_bg_opa(but_tile_right,LV_BTN_PART_MAIN, LV_BTN_STATE_RELEASED, LV_OPA_60); 
        screen_tileview_show_sign = 1;
    }
    else if (x == 2 && y == 0) {
        lv_obj_set_style_local_bg_opa(but_tile_left,LV_BTN_PART_MAIN, LV_BTN_STATE_RELEASED, LV_OPA_60);
        lv_obj_set_style_local_bg_opa(but_tile_middle,LV_BTN_PART_MAIN, LV_BTN_STATE_RELEASED, LV_OPA_60);
        lv_obj_set_style_local_bg_opa(but_tile_right,LV_BTN_PART_MAIN, LV_BTN_STATE_RELEASED, LV_OPA_COVER); 
        screen_tileview_show_sign = 2;
    }
    if(screen_tileview_air_sign == 1)
    {
      lv_label_set_text(lab_tile2_ai_, "正在运行");
    }else if(screen_tileview_air_sign == 2)
    {
      lv_label_set_text(lab_tile2_ai_, "停止运行");
    }
    bar_tile2_bar_value = lv_bar_get_value(bar_tile2_bar);
    if(bar_tile2_bar_value == 0)
    {
      lv_label_set_text(lab_tile2_cu_, "窗帘已关闭");
    }else if(bar_tile2_bar_value > 0)
    {
      lv_label_set_text(lab_tile2_cu_, "窗帘已打开");
    }
  } else {
    lv_task_del(t);
  }

  _timer_index++;
}


lv_task_t* _task_callback_eybwxi;
void callback_eybwxi(lv_task_t* t){
  static int _timer_index=1;
  if(_timer_index<1)
    _timer_index=1;
  if (((int)scr_equipment_sign) == 1) {
    lv_img_set_angle(ima_equ_load,((_timer_index) * 2)*10);
  } else if (((int)scr_equipment_sign) == 0) {
    lv_task_del(t);
  }

  _timer_index++;
}
    void __qmsd_ima_tile1_mi_cb(lv_obj_t * obj, lv_event_t event) {
  if ((event) == (LV_EVENT_PRESSED)) {
    if (((int)screen_tile1_mi_sign) == 1) {
      screen_tile1_mi_sign = 0;
        lv_img_set_src(ima_tile1_mi, &imgtileview1_press_png);
      screen_tile1_le_sign = 1;
        lv_img_set_src(ima_tile1_le, &imgtileview_1_png);
    } else if (((int)screen_tile1_mi_sign) == 0) {
      screen_tile1_mi_sign = 1;
        lv_img_set_src(ima_tile1_mi, &imgtileview_2_png);
    }
  }
}

void __qmsd_ima_tile1_mi__cb(lv_obj_t * obj, lv_event_t event) {
  if ((event) == (LV_EVENT_PRESSED)) {
    if (((int)screen_tile1_mi_sign) == 1) {
      screen_tile1_mi_sign = 0;
        lv_img_set_src(ima_tile1_mi, &imgtileview1_press_png);
      screen_tile1_le_sign = 1;
        lv_img_set_src(ima_tile1_le, &imgtileview_1_png);
    } else if (((int)screen_tile1_mi_sign) == 0) {
      screen_tile1_mi_sign = 1;
        lv_img_set_src(ima_tile1_mi, &imgtileview_2_png);
    }
  }
}

void __qmsd_ima_tile1_le_cb(lv_obj_t * obj, lv_event_t event) {
  if ((event) == (LV_EVENT_PRESSED)) {
    if (((int)screen_tile1_le_sign) == 1) {
      screen_tile1_le_sign = 0;
        lv_img_set_src(ima_tile1_le, &imgtileview1_press_png);
      screen_tile1_mi_sign = 1;
        lv_img_set_src(ima_tile1_mi, &imgtileview_2_png);
    } else if (((int)screen_tile1_le_sign) == 0) {
      screen_tile1_le_sign = 1;
        lv_img_set_src(ima_tile1_le, &imgtileview_1_png);
    }
  }
}

void __qmsd_lab_tile1_le_cb(lv_obj_t * obj, lv_event_t event) {
  if ((event) == (LV_EVENT_PRESSED)) {
    if (((int)screen_tile1_le_sign) == 1) {
      screen_tile1_le_sign = 0;
        lv_img_set_src(ima_tile1_le, &imgtileview1_press_png);
      screen_tile1_mi_sign = 1;
        lv_img_set_src(ima_tile1_mi, &imgtileview_2_png);
    } else if (((int)screen_tile1_le_sign) == 0) {
      screen_tile1_le_sign = 1;
        lv_img_set_src(ima_tile1_le, &imgtileview_1_png);
    }
  }
}

void __qmsd_lab_tile1_mi_cb(lv_obj_t * obj, lv_event_t event) {
  if ((event) == (LV_EVENT_PRESSED)) {
    if (((int)screen_tile1_mi_sign) == 1) {
      screen_tile1_mi_sign = 0;
        lv_img_set_src(ima_tile1_mi, &imgtileview1_press_png);
      screen_tile1_le_sign = 1;
        lv_img_set_src(ima_tile1_le, &imgtileview_1_png);
    } else if (((int)screen_tile1_mi_sign) == 0) {
      screen_tile1_mi_sign = 1;
        lv_img_set_src(ima_tile1_mi, &imgtileview_2_png);
    }
  }
}

void __qmsd_ima_tile1_le__cb(lv_obj_t * obj, lv_event_t event) {
  if ((event) == (LV_EVENT_PRESSED)) {
    if (((int)screen_tile1_le_sign) == 1) {
      screen_tile1_le_sign = 0;
        lv_img_set_src(ima_tile1_le, &imgtileview1_press_png);
      screen_tile1_mi_sign = 1;
        lv_img_set_src(ima_tile1_mi, &imgtileview_2_png);
    } else if (((int)screen_tile1_le_sign) == 0) {
      screen_tile1_le_sign = 1;
        lv_img_set_src(ima_tile1_le, &imgtileview_1_png);
    }
  }
}

void __qmsd_ima_tile2_one_cb(lv_obj_t * obj, lv_event_t event) {
  if ((event) == (LV_EVENT_PRESSED)) {
    lv_event_send(but_tile2_one, LV_EVENT_PRESSED, NULL);/* 按下 */
    /*按下*/
    lv_obj_set_style_local_bg_color(but_tile2_one, LV_BTN_PART_MAIN, LV_STATE_DEFAULT,lv_color_hex(0x7ed321));
    lv_obj_set_style_local_bg_opa(but_tile2_one, LV_BTN_PART_MAIN, LV_STATE_DEFAULT,204);
  } else if ((event) == (LV_EVENT_RELEASED)) {
    lv_event_send(but_tile2_one, LV_EVENT_RELEASED, NULL);/* 释放 */
    /*释放*/
    lv_obj_set_style_local_bg_color(but_tile2_one, LV_BTN_PART_MAIN, LV_STATE_DEFAULT,lv_color_hex(0xffffff));
    lv_obj_set_style_local_bg_opa(but_tile2_one, LV_BTN_PART_MAIN, LV_STATE_DEFAULT,25);
  }
}

void __qmsd_ima_tile1_ri_cb(lv_obj_t * obj, lv_event_t event) {
  if ((event) == (LV_EVENT_PRESSED)) {
    lv_img_set_src(ima_tile1_ri, &imgtileview1_press_png);
    screen_tileview_delete();
    /*add here*/
    lv_task_del(tileview1_tem_hum);

    screen_choice_show();
    screen_tileview_sign = 1;
    screen_tileview_choice_sign= 1;
  } else if ((event) == (LV_EVENT_RELEASED)) {
      lv_img_set_src(ima_tile1_ri, &imgtileview_3_png);
  }
}

void __qmsd_ima_tile2_two_cb(lv_obj_t * obj, lv_event_t event) {
  if ((event) == (LV_EVENT_PRESSED)) {
    lv_event_send(but_tile2_two, LV_EVENT_PRESSED, NULL);/* 按下 */
    /*按下*/
    lv_obj_set_style_local_bg_color(but_tile2_two, LV_BTN_PART_MAIN, LV_STATE_DEFAULT,lv_color_hex(0x7ed321));
    lv_obj_set_style_local_bg_opa(but_tile2_two, LV_BTN_PART_MAIN, LV_STATE_DEFAULT,204);
  } else if ((event) == (LV_EVENT_RELEASED)) {
    lv_event_send(but_tile2_two, LV_EVENT_RELEASED, NULL);/* 释放 */
    /*释放*/
    lv_obj_set_style_local_bg_color(but_tile2_two, LV_BTN_PART_MAIN, LV_STATE_DEFAULT,lv_color_hex(0xffffff));
    lv_obj_set_style_local_bg_opa(but_tile2_two, LV_BTN_PART_MAIN, LV_STATE_DEFAULT,25);
  }
}

void __qmsd_screen_cont_cb(lv_obj_t * obj, lv_event_t event) {
  if ((event) == 8) {
    if (((int)lv_obj_get_y(obj)) < -100) {
      obj_move(screen_cont,-338,0);
      lv_obj_set_style_local_image_opa(ima_con_sign,LV_IMG_PART_MAIN,LV_STATE_DEFAULT,LV_OPA_COVER);
    } else {
      obj_move(screen_cont,0,-338);
      lv_obj_set_style_local_bg_opa(contlink_main,LV_CONT_PART_MAIN,LV_STATE_DEFAULT,0);
      lv_obj_set_style_local_image_opa(ima_con_sign,LV_IMG_PART_MAIN,LV_STATE_DEFAULT,LV_OPA_TRANSP);
    }
    lv_obj_set_drag(screen_cont,false);
    lv_indev_finish_drag(lv_indev_get_act());
  }
}

void __qmsd_ima_tile1_ri__cb(lv_obj_t * obj, lv_event_t event) {
  if ((event) == (LV_EVENT_PRESSED)) {
      lv_img_set_src(ima_tile1_ri, &imgtileview1_press_png);
    screen_choice_show();
    screen_tileview_delete();
    lv_task_del(tileview1_tem_hum);

    screen_tileview_sign = 1;
    screen_tileview_choice_sign= 1;
  } else if ((event) == (LV_EVENT_RELEASED)) {
      lv_img_set_src(ima_tile1_ri, &imgtileview_3_png);
  }
}

void __qmsd_ima_tile2_thr_cb(lv_obj_t * obj, lv_event_t event) {
  if ((event) == (LV_EVENT_PRESSED)) {
    lv_event_send(but_tile2_thr, LV_EVENT_PRESSED, NULL);/* 按下 */
    /*按下*/
    lv_obj_set_style_local_bg_color(but_tile2_thr, LV_BTN_PART_MAIN, LV_STATE_DEFAULT,lv_color_hex(0x7ed321));
    lv_obj_set_style_local_bg_opa(but_tile2_thr, LV_BTN_PART_MAIN, LV_STATE_DEFAULT,204);
  } else if ((event) == (LV_EVENT_RELEASED)) {
    lv_event_send(but_tile2_thr, LV_EVENT_RELEASED, NULL);/* 释放 */
    /*释放*/
    lv_obj_set_style_local_bg_color(but_tile2_thr, LV_BTN_PART_MAIN, LV_STATE_DEFAULT,lv_color_hex(0xffffff));
    lv_obj_set_style_local_bg_opa(but_tile2_thr, LV_BTN_PART_MAIN, LV_STATE_DEFAULT,25);
  }
}

void __qmsd_lab_tile1_ri_cb(lv_obj_t * obj, lv_event_t event) {
  if ((event) == (LV_EVENT_PRESSED)) {
      lv_img_set_src(ima_tile1_ri, &imgtileview1_press_png);
    screen_tileview_sign = 1;
    screen_tileview_delete();
    /*add here*/
    lv_task_del(tileview1_tem_hum);

    screen_choice_show();
    screen_tileview_choice_sign= 1;
  } else if ((event) == (LV_EVENT_RELEASED)) {
      lv_img_set_src(ima_tile1_ri, &imgtileview_3_png);
  }
}

void __qmsd_ima_tile2_fou_cb(lv_obj_t * obj, lv_event_t event) {
  if ((event) == (LV_EVENT_PRESSED)) {
    lv_event_send(but_tile2_fou, LV_EVENT_PRESSED, NULL);/* 按下 */
    /*按下*/
    lv_obj_set_style_local_bg_color(but_tile2_fou, LV_BTN_PART_MAIN, LV_STATE_DEFAULT,lv_color_hex(0x7ed321));
    lv_obj_set_style_local_bg_opa(but_tile2_fou, LV_BTN_PART_MAIN, LV_STATE_DEFAULT,204);
  } else if ((event) == (LV_EVENT_RELEASED)) {
    lv_event_send(but_tile2_fou, LV_EVENT_RELEASED, NULL);/* 释放 */
    /*释放*/
    lv_obj_set_style_local_bg_color(but_tile2_fou, LV_BTN_PART_MAIN, LV_STATE_DEFAULT,lv_color_hex(0xffffff));
    lv_obj_set_style_local_bg_opa(but_tile2_fou, LV_BTN_PART_MAIN, LV_STATE_DEFAULT,25);
  }
}

void __qmsd_screen_main_init(void) {
  screen_main_anim_sign = 0;
  _task_callback_50kf8f=lv_task_create(callback_50kf8f,1500 , LV_TASK_PRIO_HIGH , NULL);
  if (((int)screen_main_anim_sign) == 0) {
    lv_anim_logo_function();
  } else {
    lv_anim_del(image_ma_logo, (lv_anim_exec_xcb_t)lv_anim_logo_function_cb);
  }
}

void __qmsd_screentileview3_cb(lv_obj_t * obj, lv_event_t event) {
  if ((event) == 9) {
    lv_coord_t x, y;
    lv_tileview_get_tile_act(obj, &x, &y);
    if (x == 0 && y == 0) {
        lv_obj_set_style_local_bg_opa(but_tile_left,LV_BTN_PART_MAIN, LV_BTN_STATE_RELEASED, LV_OPA_COVER);
        lv_obj_set_style_local_bg_opa(but_tile_middle,LV_BTN_PART_MAIN, LV_BTN_STATE_RELEASED, LV_OPA_60);
        lv_obj_set_style_local_bg_opa(but_tile_right,LV_BTN_PART_MAIN, LV_BTN_STATE_RELEASED, LV_OPA_60);  
    }
    else if (x == 1 && y == 0) {
        lv_obj_set_style_local_bg_opa(but_tile_left,LV_BTN_PART_MAIN, LV_BTN_STATE_RELEASED, LV_OPA_60);
        lv_obj_set_style_local_bg_opa(but_tile_middle,LV_BTN_PART_MAIN, LV_BTN_STATE_RELEASED, LV_OPA_COVER);
        lv_obj_set_style_local_bg_opa(but_tile_right,LV_BTN_PART_MAIN, LV_BTN_STATE_RELEASED, LV_OPA_60); 
    }
    else if (x == 2 && y == 0) {
        lv_obj_set_style_local_bg_opa(but_tile_left,LV_BTN_PART_MAIN, LV_BTN_STATE_RELEASED, LV_OPA_60);
        lv_obj_set_style_local_bg_opa(but_tile_middle,LV_BTN_PART_MAIN, LV_BTN_STATE_RELEASED, LV_OPA_60);
        lv_obj_set_style_local_bg_opa(but_tile_right,LV_BTN_PART_MAIN, LV_BTN_STATE_RELEASED, LV_OPA_COVER); 
    }
  }
}

void __qmsd_screentileview1_cb(lv_obj_t * obj, lv_event_t event) {
  if ((event) == 9) {
    lv_coord_t x, y;
    lv_tileview_get_tile_act(obj, &x, &y);
    if (x == 0 && y == 0) {
        lv_obj_set_style_local_bg_opa(but_tile_left,LV_BTN_PART_MAIN, LV_BTN_STATE_RELEASED, LV_OPA_COVER);
        lv_obj_set_style_local_bg_opa(but_tile_middle,LV_BTN_PART_MAIN, LV_BTN_STATE_RELEASED, LV_OPA_60);
        lv_obj_set_style_local_bg_opa(but_tile_right,LV_BTN_PART_MAIN, LV_BTN_STATE_RELEASED, LV_OPA_60);  
    }
    else if (x == 1 && y == 0) {
        lv_obj_set_style_local_bg_opa(but_tile_left,LV_BTN_PART_MAIN, LV_BTN_STATE_RELEASED, LV_OPA_60);
        lv_obj_set_style_local_bg_opa(but_tile_middle,LV_BTN_PART_MAIN, LV_BTN_STATE_RELEASED, LV_OPA_COVER);
        lv_obj_set_style_local_bg_opa(but_tile_right,LV_BTN_PART_MAIN, LV_BTN_STATE_RELEASED, LV_OPA_60); 
    }
    else if (x == 2 && y == 0) {
        lv_obj_set_style_local_bg_opa(but_tile_left,LV_BTN_PART_MAIN, LV_BTN_STATE_RELEASED, LV_OPA_60);
        lv_obj_set_style_local_bg_opa(but_tile_middle,LV_BTN_PART_MAIN, LV_BTN_STATE_RELEASED, LV_OPA_60);
        lv_obj_set_style_local_bg_opa(but_tile_right,LV_BTN_PART_MAIN, LV_BTN_STATE_RELEASED, LV_OPA_COVER); 
    }
  }
}

void __qmsd_ima_tile2_cu_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  screen_tileview_sign = 1;
  screen_tileview_delete();
  /*add here*/
  lv_task_del(tileview1_tem_hum);

  scr_curtain_ti1_show();
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_ima_tile2_pr_cb(lv_obj_t * obj, lv_event_t event) {
  if ((event) == (LV_EVENT_PRESSED)) {
    lv_event_send(but_tile2_pr, LV_EVENT_PRESSED, NULL);/* 按下 */
    lv_obj_set_style_local_bg_opa(but_tile2_pr, LV_BTN_PART_MAIN, LV_STATE_DEFAULT,204);
  } else if ((event) == (LV_EVENT_RELEASED)) {
    lv_event_send(but_tile2_pr, LV_EVENT_RELEASED, NULL);/* 释放 */
    lv_obj_set_style_local_bg_opa(but_tile2_pr, LV_BTN_PART_MAIN, LV_STATE_DEFAULT,100);
  }
}

void __qmsd_ima_cur_op_cb(lv_obj_t * obj, lv_event_t event) {
  if ((event) == (LV_EVENT_PRESSED)) {
    lv_img_set_src(ima_cur_op, &imgcurtain_button_on_png);
  } else if ((event) == (LV_EVENT_RELEASED)) {
    lv_img_set_src(ima_cur_op, &imgcurtain_button_off_png);
    /* open */
    if((lv_obj_get_x(ima_cur_cle)-10) >= (-105))
    {
        lv_obj_set_x(ima_cur_cle, (lv_obj_get_x(ima_cur_cle)-10));
        lv_obj_set_x(ima_cur_cri, (lv_obj_get_x(ima_cur_cri)+10));
        bar_tile2_bar_value = (100-((422-lv_obj_get_x(ima_cur_cri))*100)/165);
    }else
    {
        lv_obj_set_x(ima_cur_cle, (-105));
        lv_obj_set_x(ima_cur_cri, 422);
        bar_tile2_bar_value = 100;
    }
  }
}

void __qmsd_ima_tile2_ai_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  screen_tileview_sign = 1;
  screen_tileview_delete();
  /*add here*/
  lv_task_del(tileview1_tem_hum);

  screen_air_show();
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_ima_air_co_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  lv_obj_set_pos(lab_air_pat,61,441);
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_ima_cur_op__cb(lv_obj_t * obj, lv_event_t event) {
  if ((event) == (LV_EVENT_PRESSED)) {
    lv_img_set_src(ima_cur_op, &imgcurtain_button_on_png);
  } else if ((event) == (LV_EVENT_RELEASED)) {
    lv_img_set_src(ima_cur_op, &imgcurtain_button_off_png);
    /* open */
    if((lv_obj_get_x(ima_cur_cle)-10) >= (-105))
    {
        lv_obj_set_x(ima_cur_cle, (lv_obj_get_x(ima_cur_cle)-10));
        lv_obj_set_x(ima_cur_cri, (lv_obj_get_x(ima_cur_cri)+10));
        bar_tile2_bar_value = (100-((422-lv_obj_get_x(ima_cur_cri))*100)/165);
    }else
    {
        lv_obj_set_x(ima_cur_cle, (-105));
        lv_obj_set_x(ima_cur_cri, 422);
        bar_tile2_bar_value = 100;
    }
  }
}

void __qmsd_screen_saver_init(void) {
  screen_saver_sign = 1;
  if (((int)screen_saver_sign) == 1) {
    lv_obj_set_click(image_saver_bot,true);
    lv_anim_ima_sa_ima_function();
    lv_label_set_text(lab_sa_scr, "");
    task_callback_sa_time = lv_task_create(callback_sa_time, 1000, LV_TASK_PRIO_HIGH , NULL);
  }
}

void __qmsd_ima_tile2_ne_cb(lv_obj_t * obj, lv_event_t event) {
  if ((event) == (LV_EVENT_PRESSED)) {
    lv_event_send(but_tile2_ne, LV_EVENT_PRESSED, NULL);/* 按下 */
    lv_obj_set_style_local_bg_opa(but_tile2_ne, LV_BTN_PART_MAIN, LV_STATE_DEFAULT,204);
  } else if ((event) == (LV_EVENT_RELEASED)) {
    lv_event_send(but_tile2_ne, LV_EVENT_RELEASED, NULL);/* 释放 */
    lv_obj_set_style_local_bg_opa(but_tile2_ne, LV_BTN_PART_MAIN, LV_STATE_DEFAULT,100);
  }
}

void __qmsd_screentileview2_cb(lv_obj_t * obj, lv_event_t event) {
  if ((event) == 9) {
    lv_coord_t x, y;
    lv_tileview_get_tile_act(obj, &x, &y);
    if (x == 0 && y == 0) {
        lv_obj_set_style_local_bg_opa(but_tile_left,LV_BTN_PART_MAIN, LV_BTN_STATE_RELEASED, LV_OPA_COVER);
        lv_obj_set_style_local_bg_opa(but_tile_middle,LV_BTN_PART_MAIN, LV_BTN_STATE_RELEASED, LV_OPA_60);
        lv_obj_set_style_local_bg_opa(but_tile_right,LV_BTN_PART_MAIN, LV_BTN_STATE_RELEASED, LV_OPA_60);  
    }
    else if (x == 1 && y == 0) {
        lv_obj_set_style_local_bg_opa(but_tile_left,LV_BTN_PART_MAIN, LV_BTN_STATE_RELEASED, LV_OPA_60);
        lv_obj_set_style_local_bg_opa(but_tile_middle,LV_BTN_PART_MAIN, LV_BTN_STATE_RELEASED, LV_OPA_COVER);
        lv_obj_set_style_local_bg_opa(but_tile_right,LV_BTN_PART_MAIN, LV_BTN_STATE_RELEASED, LV_OPA_60); 
    }
    else if (x == 2 && y == 0) {
        lv_obj_set_style_local_bg_opa(but_tile_left,LV_BTN_PART_MAIN, LV_BTN_STATE_RELEASED, LV_OPA_60);
        lv_obj_set_style_local_bg_opa(but_tile_middle,LV_BTN_PART_MAIN, LV_BTN_STATE_RELEASED, LV_OPA_60);
        lv_obj_set_style_local_bg_opa(but_tile_right,LV_BTN_PART_MAIN, LV_BTN_STATE_RELEASED, LV_OPA_COVER); 
    }
  }
}

void __qmsd_ima_air_sun_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  lv_obj_set_pos(lab_air_pat,154,441);
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_ima_cur_cl_cb(lv_obj_t * obj, lv_event_t event) {
  if ((event) == (LV_EVENT_PRESSED)) {
    lv_img_set_src(ima_cur_cl, &imgcurtain_button_on_png);
  } else if ((event) == (LV_EVENT_RELEASED)) {
    lv_img_set_src(ima_cur_cl, &imgcurtain_button_off_png);
    /* close */
    if((lv_obj_get_x(ima_cur_cle)+10) <= (60))
    {
        lv_obj_set_x(ima_cur_cle, (lv_obj_get_x(ima_cur_cle)+10));
        lv_obj_set_x(ima_cur_cri, (lv_obj_get_x(ima_cur_cri)-10));
        bar_tile2_bar_value = (100-((422-lv_obj_get_x(ima_cur_cri))*100)/165);
    }else
    {
        lv_obj_set_x(ima_cur_cle, 60);
        lv_obj_set_x(ima_cur_cri, 257);
        bar_tile2_bar_value = 0;
    }
  }
}

void __qmsd_ima_air_re_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  screen_tileview_sign = 0;
  screen_air_delete();
  screen_tileview_show();
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_but_tile2_pr_cb(lv_obj_t * obj, lv_event_t event) {
  if ((event) == (LV_EVENT_PRESSED)) {
    if(tileview2_temperature > 16 && tileview2_temperature <= 31)
    {
        tileview2_temperature--;
    }
    lv_label_set_text_fmt(lab_tile2_ai__, "%d", tileview2_temperature);
  }
}

void __qmsd_ima_air_lo_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  lv_obj_set_pos(lab_air_pow,292,441);
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_ima_cho_re_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  screen_tileview_sign = 0;
  screen_choice_delete();
  screen_tileview_show();
  screen_tileview_sign = 0;
  if(screen_tileview_choice_sign == 2)
  {
      lv_obj_set_y(screen_cont, 0);
      lv_obj_set_style_local_bg_opa(screen_cont,0,0,245);
  }
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_lab_air_re_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  screen_tileview_sign = 0;
  screen_air_delete();
  screen_tileview_show();
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_ima_air_mi_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  lv_obj_set_pos(lab_air_pow,354,441);
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_lab_cho_re_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  screen_tileview_sign = 0;
  screen_choice_delete();
  screen_tileview_show();
  if(screen_tileview_choice_sign == 2)
  {
      /*lv_event_send(screen_cont, LV_EVENT_DRAG_BEGIN, NULL);*/
      lv_obj_set_y(screen_cont, 0);
      lv_obj_set_style_local_bg_opa(screen_cont,0,0,245);
  }
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_ima_tile2_le_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  bar_tile2_bar_sign = 1;
  lv_anim_tile2_bar_function();
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_ima_cur_cl__cb(lv_obj_t * obj, lv_event_t event) {
  if ((event) == (LV_EVENT_PRESSED)) {
    lv_img_set_src(ima_cur_cl, &imgcurtain_button_on_png);
  } else if ((event) == (LV_EVENT_RELEASED)) {
    lv_img_set_src(ima_cur_cl, &imgcurtain_button_off_png);
    /* close */
    if((lv_obj_get_x(ima_cur_cle)+10) <= (60))
    {
        lv_obj_set_x(ima_cur_cle, (lv_obj_get_x(ima_cur_cle)+10));
        lv_obj_set_x(ima_cur_cri, (lv_obj_get_x(ima_cur_cri)-10));
        bar_tile2_bar_value = (100-((422-lv_obj_get_x(ima_cur_cri))*100)/165);
    }else
    {
        lv_obj_set_x(ima_cur_cle, 60);
        lv_obj_set_x(ima_cur_cri, 257);
        bar_tile2_bar_value = 0;
    }
  }
}

void __qmsd_ima_cur_re_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  screen_tileview_sign = 0;
  scr_curtain_ti1_delete();
  screen_tileview_show();
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_ima_air_hi_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  lv_obj_set_pos(lab_air_pow,416,441);
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_but_tile2_ne_cb(lv_obj_t * obj, lv_event_t event) {
  if ((event) == (LV_EVENT_PRESSED)) {
    if(tileview2_temperature < 31 && tileview2_temperature >= 16)
    {
        tileview2_temperature++;
    }
    lv_label_set_text_fmt(lab_tile2_ai__, "%d", tileview2_temperature);
  }
}

void __qmsd_ima_tile2_ri_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  bar_tile2_bar_sign = 2;
  lv_anim_tile2_bar_function();
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_lab_cur_le_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  lv_obj_set_x(but_cur_bot, 189);
  lv_obj_set_style_local_bg_opa(but_cur_le,LV_BTN_PART_MAIN, LV_BTN_STATE_RELEASED, LV_OPA_100);
  lv_obj_set_style_local_bg_opa(but_cur_ri,LV_BTN_PART_MAIN, LV_BTN_STATE_RELEASED, LV_OPA_60);
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_swi_air_swi_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_VALUE_CHANGED) {
  if(lv_switch_get_state(swi_air_swi))/*open*/
  {
      screen_tileview_air_sign = 1;
      lv_obj_set_click(ima_air_co, true);
      lv_obj_set_click(ima_air_sun, true);
      lv_obj_set_click(ima_air_lo, true);
      lv_obj_set_click(ima_air_mi, true);
      lv_obj_set_click(ima_air_hi, true);
  }else if(!(lv_switch_get_state(swi_air_swi)))/*close*/
  {
      screen_tileview_air_sign = 2;
      lv_obj_set_click(ima_air_co, false);
      lv_obj_set_click(ima_air_sun, false);
      lv_obj_set_click(ima_air_lo, false);
      lv_obj_set_click(ima_air_mi, false);
      lv_obj_set_click(ima_air_hi, false);  
  }
}
}

void __qmsd_ima_tile2_st_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  if(bar_tile2_bar_stop_sign == 1)
  {
      lv_anim_del(bar_tile2_bar, (lv_anim_exec_xcb_t)lv_anim_tile2_bar_function_cb);
  }
  bar_tile2_bar_stop_sign = 0;
  bar_tile2_bar_value = lv_bar_get_value(bar_tile2_bar);
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_image_saver_bot_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  screen_saver_sign = 2;
  lv_anim_del(ima_sa_ima, (lv_anim_exec_xcb_t)lv_anim_ima_sa_ima_function_cb);
  lv_label_set_text(lab_sa_scr, ":");
  screen_tileview_show();
  screen_saver_delete();
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_lab_cur_ri_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  lv_obj_set_x(but_cur_bot, 275);
  lv_obj_set_style_local_bg_opa(but_cur_le,LV_BTN_PART_MAIN, LV_BTN_STATE_RELEASED, LV_OPA_60);
  lv_obj_set_style_local_bg_opa(but_cur_ri,LV_BTN_PART_MAIN, LV_BTN_STATE_RELEASED, LV_OPA_100);
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_ima_cur_on_cb(lv_obj_t * obj, lv_event_t event) {
  if ((event) == (LV_EVENT_PRESSED)) {
    lv_img_set_src(ima_cur_on, &imgcurtain_button_on_png);
  } else if ((event) == (LV_EVENT_RELEASED)) {
    lv_img_set_src(ima_cur_on, &imgcurtain_button_off_png);
    lv_anim_ima_cur_function();
  }
}

void __qmsd_swi_tile2_ai_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_VALUE_CHANGED) {
  if(lv_switch_get_state(swi_tile2_ai))
  {
    screen_tileview_air_sign = 1;
    lv_obj_set_click(ima_tile2_ai,true);
    lv_obj_set_click(ima_tile2_pr,true);
    lv_obj_set_click(ima_tile2_ne,true);
    lv_obj_set_click(ima_tile2_one,true);
    lv_obj_set_click(ima_tile2_two,true);
    lv_obj_set_click(ima_tile2_thr,true);
    lv_obj_set_click(ima_tile2_fou,true); 
  
    lv_obj_set_click(but_tile2_pr,true);
    lv_obj_set_click(but_tile2_ne,true);
    lv_obj_set_click(but_tile2_one,true);
    lv_obj_set_click(but_tile2_two,true);
    lv_obj_set_click(but_tile2_thr,true);
    lv_obj_set_click(but_tile2_fou,true); 
  }else if(!(lv_switch_get_state(swi_tile2_ai)))
  {
    screen_tileview_air_sign = 2;
    lv_obj_set_click(ima_tile2_ai,false);
    lv_obj_set_click(ima_tile2_pr,false);
    lv_obj_set_click(ima_tile2_ne,false);
    lv_obj_set_click(ima_tile2_one,false);
    lv_obj_set_click(ima_tile2_two,false);
    lv_obj_set_click(ima_tile2_thr,false);
    lv_obj_set_click(ima_tile2_fou,false); 
  
    lv_obj_set_click(but_tile2_pr,false);
    lv_obj_set_click(but_tile2_ne,false);
    lv_obj_set_click(but_tile2_one,false);
    lv_obj_set_click(but_tile2_two,false);
    lv_obj_set_click(but_tile2_thr,false);
    lv_obj_set_click(but_tile2_fou,false);
  }
}
}

void __qmsd_ima_tile2_stb_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  if(bar_tile2_bar_stop_sign == 1)
  {
      lv_anim_del(bar_tile2_bar, (lv_anim_exec_xcb_t)lv_anim_tile2_bar_function_cb);
  }
  bar_tile2_bar_stop_sign = 0;
  bar_tile2_bar_value = lv_bar_get_value(bar_tile2_bar);
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_ima_cur_on__cb(lv_obj_t * obj, lv_event_t event) {
  if ((event) == (LV_EVENT_PRESSED)) {
    lv_img_set_src(ima_cur_on, &imgcurtain_button_on_png);
  } else if ((event) == (LV_EVENT_RELEASED)) {
    lv_img_set_src(ima_cur_on, &imgcurtain_button_off_png);
    lv_anim_ima_cur_function();
  }
}

void __qmsd_ima_con_re_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  lv_event_send(screen_cont, LV_EVENT_DRAG_BEGIN, NULL);
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_lab_con_re_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  lv_event_send(screen_cont, LV_EVENT_DRAG_BEGIN, NULL);
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_ima_cur_st_cb(lv_obj_t * obj, lv_event_t event) {
  if ((event) == (LV_EVENT_PRESSED)) {
    lv_img_set_src(ima_cur_st, &imgcurtain_button_on_png);
  } else if ((event) == (LV_EVENT_RELEASED)) {
    ima_cur_on_stop_sign = 1;
    lv_img_set_src(ima_cur_st, &imgcurtain_button_off_png);
    if(ima_cur_on_stop_sign == 1)
    {
        lv_anim_del(ima_cur_cle, (lv_anim_exec_xcb_t)lv_anim_ima_cur_le_function_cb);
        lv_anim_del(ima_cur_cri, (lv_anim_exec_xcb_t)lv_anim_ima_cur_ri_function_cb);
    }
    ima_cur_on_stop_sign = 0;
    bar_tile2_bar_value = (((422-lv_obj_get_x(ima_cur_cri))*100)/422);
  }
}

void __qmsd_ima_con_set_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  screen_tileview_sign = 1;
  screen_tileview_delete();
  /*add here*/
    lv_task_del(tileview1_tem_hum);

  screen_set_show();
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_lab_wif_re_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  screen_wifi_set_delete();
  screen_set_show();
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_lab_con_set_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  screen_tileview_sign = 1;
  screen_tileview_delete();
  /*add here*/
    lv_task_del(tileview1_tem_hum);

  screen_set_show();
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_screen_tileview_init(void) {
  lv_obj_set_click(ima_tile1_mi,true);
  lv_obj_set_click(ima_tile2_res,true);
  // lv_obj_set_click(image_21da,true);
  lv_obj_set_click(image_21da,false);
  /* screen_cont init*/
  lv_obj_set_click(ima_con_re, true);
  lv_obj_set_click(ima_con_set, true);
  lv_obj_set_click(ima_con_mor, true);
  lv_obj_set_click(lab_con_re, true);
  lv_obj_set_click(lab_con_set, true);
  lv_obj_set_click(lab_con_mor, true);
  /* tileview1 */
    lv_obj_set_click(ima_tile1_le,true);
    lv_obj_set_click(ima_tile1_le_,true);
    lv_obj_set_click(lab_tile1_le,true);
    lv_obj_set_click(ima_tile1_mi,true);
    lv_obj_set_click(ima_tile1_mi_,true);
    lv_obj_set_click(lab_tile1_mi,true);
    lv_obj_set_click(ima_tile1_ri,true);
    lv_obj_set_click(ima_tile1_ri_,true);
    lv_obj_set_click(lab_tile1_ri,true);
    lv_obj_set_click(but_tile1_bot, false);
  if(screen_tileview_air_sign == 1)/*open*/
  {
      lv_switch_on(swi_tile2_ai, LV_ANIM_OFF);
  }else if(screen_tileview_air_sign == 2)/*close*/
  {
      lv_switch_off(swi_tile2_ai, LV_ANIM_OFF);
  }else/*close*/
  {
      lv_switch_off(swi_tile2_ai, LV_ANIM_OFF);
  }
  if(lv_switch_get_state(swi_tile2_ai))
  {
    screen_tileview_air_sign = 1;
    lv_obj_set_click(ima_tile2_ai,true);
    lv_obj_set_click(ima_tile2_pr,true);
    lv_obj_set_click(ima_tile2_ne,true);
    lv_obj_set_click(ima_tile2_one,true);
    lv_obj_set_click(ima_tile2_two,true);
    lv_obj_set_click(ima_tile2_thr,true);
    lv_obj_set_click(ima_tile2_fou,true); 
  
    lv_obj_set_click(but_tile2_pr,true);
    lv_obj_set_click(but_tile2_ne,true);
    lv_obj_set_click(but_tile2_one,true);
    lv_obj_set_click(but_tile2_two,true);
    lv_obj_set_click(but_tile2_thr,true);
    lv_obj_set_click(but_tile2_fou,true); 
  }else if(!(lv_switch_get_state(swi_tile2_ai)))
  {
    screen_tileview_air_sign = 2;
    lv_obj_set_click(ima_tile2_ai,false);
    lv_obj_set_click(ima_tile2_pr,false);
    lv_obj_set_click(ima_tile2_ne,false);
    lv_obj_set_click(ima_tile2_one,false);
    lv_obj_set_click(ima_tile2_two,false);
    lv_obj_set_click(ima_tile2_thr,false);
    lv_obj_set_click(ima_tile2_fou,false); 
  
    lv_obj_set_click(but_tile2_pr,false);
    lv_obj_set_click(but_tile2_ne,false);
    lv_obj_set_click(but_tile2_one,false);
    lv_obj_set_click(but_tile2_two,false);
    lv_obj_set_click(but_tile2_thr,false);
    lv_obj_set_click(but_tile2_fou,false);
  }
  lv_tileview_set_edge_flash(tile_main,false);
  lv_obj_set_click(bar_tile2_bar, false);
  /*tileview3*/
  lv_obj_set_click(ima_tile3_mo, true);
  lv_obj_set_click(ima_tile3_mo_, true);
  lv_obj_set_click(lab_tile3_mo, true);
  /* screen_tileview init */
  if(screen_tileview_show_sign == 0)
  {
      lv_tileview_set_tile_act(tile_main, 0, 0, LV_ANIM_OFF);
  }else if(screen_tileview_show_sign == 1)
  {
      lv_tileview_set_tile_act(tile_main, 1, 0, LV_ANIM_OFF); 
  }else if(screen_tileview_show_sign == 2)
  {
      lv_tileview_set_tile_act(tile_main, 2, 0, LV_ANIM_OFF);  
  }else
  {
      lv_tileview_set_tile_act(tile_main, 0, 0, LV_ANIM_OFF);
  }
  lv_obj_set_style_local_bg_color(swi_tile2_li,LV_SWITCH_PART_BG, LV_STATE_DEFAULT, lv_color_hex(0xffffff));
  lv_obj_set_style_local_bg_opa(swi_tile2_li,LV_SWITCH_PART_BG, LV_STATE_DEFAULT, LV_OPA_50);
  
  lv_obj_set_style_local_bg_color(swi_tile2_li,LV_SWITCH_PART_INDIC, LV_STATE_DEFAULT, lv_color_hex(0x4a90e2));
  lv_obj_set_style_local_bg_opa(swi_tile2_li,LV_SWITCH_PART_INDIC, LV_STATE_DEFAULT, LV_OPA_100);
  
  lv_obj_set_style_local_bg_color(swi_tile2_li,LV_SWITCH_PART_KNOB, LV_STATE_DEFAULT, lv_color_hex(0xffffff));
  lv_obj_set_style_local_bg_opa(swi_tile2_li,LV_SWITCH_PART_KNOB, LV_STATE_DEFAULT, LV_OPA_100);
  
  lv_obj_set_style_local_border_opa(swi_tile2_li,LV_SWITCH_PART_BG, LV_STATE_DEFAULT, 0);
  lv_obj_set_style_local_border_opa(swi_tile2_li,LV_SWITCH_PART_BG, LV_STATE_PRESSED, 0);
  lv_obj_set_style_local_border_opa(swi_tile2_li,LV_SWITCH_PART_BG, LV_STATE_FOCUSED, 0);       
  
  lv_obj_set_style_local_outline_width(swi_tile2_li,LV_SWITCH_PART_BG, LV_STATE_FOCUSED, 0);
  lv_obj_set_style_local_border_width(swi_tile2_li,LV_SWITCH_PART_BG, LV_STATE_FOCUSED, 0);
  lv_obj_set_style_local_border_width(swi_tile2_li,LV_SWITCH_PART_BG, LV_STATE_DEFAULT, 0);
  
  lv_obj_set_style_local_shadow_width(swi_tile2_li,LV_SWITCH_PART_BG, LV_STATE_DEFAULT, 0);
  lv_obj_set_style_local_shadow_width(swi_tile2_li,LV_SWITCH_PART_INDIC, LV_STATE_DEFAULT, 0);
  lv_obj_set_style_local_shadow_width(swi_tile2_li,LV_SWITCH_PART_KNOB, LV_STATE_DEFAULT, 0);
  lv_obj_set_style_local_bg_color(swi_tile2_res,LV_SWITCH_PART_BG, LV_STATE_DEFAULT, lv_color_hex(0xffffff));
  lv_obj_set_style_local_bg_opa(swi_tile2_res,LV_SWITCH_PART_BG, LV_STATE_DEFAULT, LV_OPA_50);
  
  lv_obj_set_style_local_bg_color(swi_tile2_res,LV_SWITCH_PART_INDIC, LV_STATE_DEFAULT, lv_color_hex(0x4a90e2));
  lv_obj_set_style_local_bg_opa(swi_tile2_res,LV_SWITCH_PART_INDIC, LV_STATE_DEFAULT, LV_OPA_100);
  
  lv_obj_set_style_local_bg_color(swi_tile2_res,LV_SWITCH_PART_KNOB, LV_STATE_DEFAULT, lv_color_hex(0xffffff));
  lv_obj_set_style_local_bg_opa(swi_tile2_res,LV_SWITCH_PART_KNOB, LV_STATE_DEFAULT, LV_OPA_100);
  
  lv_obj_set_style_local_border_opa(swi_tile2_res,LV_SWITCH_PART_BG, LV_STATE_DEFAULT, 0);
  lv_obj_set_style_local_border_opa(swi_tile2_res,LV_SWITCH_PART_BG, LV_STATE_PRESSED, 0);
  lv_obj_set_style_local_border_opa(swi_tile2_res,LV_SWITCH_PART_BG, LV_STATE_FOCUSED, 0);       
  
  lv_obj_set_style_local_outline_width(swi_tile2_res,LV_SWITCH_PART_BG, LV_STATE_FOCUSED, 0);
  lv_obj_set_style_local_border_width(swi_tile2_res,LV_SWITCH_PART_BG, LV_STATE_FOCUSED, 0);
  lv_obj_set_style_local_border_width(swi_tile2_res,LV_SWITCH_PART_BG, LV_STATE_DEFAULT, 0);
  
  lv_obj_set_style_local_shadow_width(swi_tile2_res,LV_SWITCH_PART_BG, LV_STATE_DEFAULT, 0);
  lv_obj_set_style_local_shadow_width(swi_tile2_res,LV_SWITCH_PART_INDIC, LV_STATE_DEFAULT, 0);
  lv_obj_set_style_local_shadow_width(swi_tile2_res,LV_SWITCH_PART_KNOB, LV_STATE_DEFAULT, 0);
  lv_obj_set_style_local_bg_color(swi_tile2_ai,LV_SWITCH_PART_BG, LV_STATE_DEFAULT, lv_color_hex(0xffffff));
  lv_obj_set_style_local_bg_opa(swi_tile2_ai,LV_SWITCH_PART_BG, LV_STATE_DEFAULT, LV_OPA_50);
  
  lv_obj_set_style_local_bg_color(swi_tile2_ai,LV_SWITCH_PART_INDIC, LV_STATE_DEFAULT, lv_color_hex(0x4a90e2));
  lv_obj_set_style_local_bg_opa(swi_tile2_ai,LV_SWITCH_PART_INDIC, LV_STATE_DEFAULT, LV_OPA_100);
  
  lv_obj_set_style_local_bg_color(swi_tile2_ai,LV_SWITCH_PART_KNOB, LV_STATE_DEFAULT, lv_color_hex(0xffffff));
  lv_obj_set_style_local_bg_opa(swi_tile2_ai,LV_SWITCH_PART_KNOB, LV_STATE_DEFAULT, LV_OPA_100);
  
  lv_obj_set_style_local_border_opa(swi_tile2_ai,LV_SWITCH_PART_BG, LV_STATE_DEFAULT, 0);
  lv_obj_set_style_local_border_opa(swi_tile2_ai,LV_SWITCH_PART_BG, LV_STATE_PRESSED, 0);
  lv_obj_set_style_local_border_opa(swi_tile2_ai,LV_SWITCH_PART_BG, LV_STATE_FOCUSED, 0);       
  
  lv_obj_set_style_local_outline_width(swi_tile2_ai,LV_SWITCH_PART_BG, LV_STATE_FOCUSED, 0);
  lv_obj_set_style_local_border_width(swi_tile2_ai,LV_SWITCH_PART_BG, LV_STATE_FOCUSED, 0);
  lv_obj_set_style_local_border_width(swi_tile2_ai,LV_SWITCH_PART_BG, LV_STATE_DEFAULT, 0);
  
  lv_obj_set_style_local_shadow_width(swi_tile2_ai,LV_SWITCH_PART_BG, LV_STATE_DEFAULT, 0);
  lv_obj_set_style_local_shadow_width(swi_tile2_ai,LV_SWITCH_PART_INDIC, LV_STATE_DEFAULT, 0);
  lv_obj_set_style_local_shadow_width(swi_tile2_ai,LV_SWITCH_PART_KNOB, LV_STATE_DEFAULT, 0);
  lv_obj_set_style_local_bg_color(swi_tile3_swi,LV_SWITCH_PART_BG, LV_STATE_DEFAULT, lv_color_hex(0xffffff));
  lv_obj_set_style_local_bg_opa(swi_tile3_swi,LV_SWITCH_PART_BG, LV_STATE_DEFAULT, LV_OPA_50);
  
  lv_obj_set_style_local_bg_color(swi_tile3_swi,LV_SWITCH_PART_INDIC, LV_STATE_DEFAULT, lv_color_hex(0x4a90e2));
  lv_obj_set_style_local_bg_opa(swi_tile3_swi,LV_SWITCH_PART_INDIC, LV_STATE_DEFAULT, LV_OPA_100);
  
  lv_obj_set_style_local_bg_color(swi_tile3_swi,LV_SWITCH_PART_KNOB, LV_STATE_DEFAULT, lv_color_hex(0xffffff));
  lv_obj_set_style_local_bg_opa(swi_tile3_swi,LV_SWITCH_PART_KNOB, LV_STATE_DEFAULT, LV_OPA_100);
  
  lv_obj_set_style_local_border_opa(swi_tile3_swi,LV_SWITCH_PART_BG, LV_STATE_DEFAULT, 0);
  lv_obj_set_style_local_border_opa(swi_tile3_swi,LV_SWITCH_PART_BG, LV_STATE_PRESSED, 0);
  lv_obj_set_style_local_border_opa(swi_tile3_swi,LV_SWITCH_PART_BG, LV_STATE_FOCUSED, 0);       
  
  lv_obj_set_style_local_outline_width(swi_tile3_swi,LV_SWITCH_PART_BG, LV_STATE_FOCUSED, 0);
  lv_obj_set_style_local_border_width(swi_tile3_swi,LV_SWITCH_PART_BG, LV_STATE_FOCUSED, 0);
  lv_obj_set_style_local_border_width(swi_tile3_swi,LV_SWITCH_PART_BG, LV_STATE_DEFAULT, 0);
  
  lv_obj_set_style_local_shadow_width(swi_tile3_swi,LV_SWITCH_PART_BG, LV_STATE_DEFAULT, 0);
  lv_obj_set_style_local_shadow_width(swi_tile3_swi,LV_SWITCH_PART_INDIC, LV_STATE_DEFAULT, 0);
  lv_obj_set_style_local_shadow_width(swi_tile3_swi,LV_SWITCH_PART_KNOB, LV_STATE_DEFAULT, 0);
  lv_obj_set_style_local_border_width(screen_cont,0,0,0);
  lv_obj_set_drag_dir(screen_cont,LV_DRAG_DIR_VER);
  lv_obj_set_style_local_bg_opa(contlink_main,LV_CONT_PART_MAIN,LV_STATE_DEFAULT,0);
  /*lv_obj_set_style_local_image_opa(ima_con_bot,LV_IMG_PART_MAIN,LV_STATE_DEFAULT,LV_OPA_TRANSP);*/
  lv_obj_set_style_local_image_opa(ima_con_sign,LV_IMG_PART_MAIN,LV_STATE_DEFAULT,LV_OPA_TRANSP);
  lv_obj_set_style_local_bg_opa(screen_cont, LV_CONT_PART_MAIN, LV_STATE_DEFAULT, 120);
  lv_label_set_text_fmt(lab_tile2_ai__,"%d",tileview2_temperature);
  screen_tileview_sign = 0;
  lv_bar_set_value(bar_tile2_bar, bar_tile2_bar_value, LV_ANIM_OFF);
  lv_obj_set_hidden(ima_con_bot, true);
  /*ext_click tileview2*/
  lv_obj_set_ext_click_area(ima_tile2_le, 15,5, 20, 20);
  lv_obj_set_ext_click_area(ima_tile2_stb, 5, 5, 20, 20);
  lv_obj_set_ext_click_area(ima_tile2_ri, 5, 15, 20, 20);
  lv_obj_set_ext_click_area(but_tile2_pr, 15, 15, 15, 15);
  lv_obj_set_ext_click_area(but_tile2_ne, 15, 15, 15, 15);
  lv_obj_set_ext_click_area(but_tile2_one, 15, 0, 15, 15);
  lv_obj_set_ext_click_area(but_tile2_two, 0, 0, 15, 15);
  lv_obj_set_ext_click_area(but_tile2_thr, 0, 0, 15, 15);
  lv_obj_set_ext_click_area(but_tile2_fou, 0, 15, 15, 15);
  lv_obj_set_style_local_radius(bar_tile2_bar,LV_BAR_PART_INDIC,LV_STATE_DEFAULT,0);
  lv_obj_set_style_local_radius(bar_tile2_bar,LV_BAR_PART_BG,LV_STATE_DEFAULT,5);
  _task_callback_3hxqvc=lv_task_create(callback_3hxqvc,10 , LV_TASK_PRIO_HIGH , NULL);
  if (((int)screen_tile1_mi_sign) == 0) {
      lv_img_set_src(ima_tile1_mi, &imgtileview1_press_png);
  } else if (((int)screen_tile1_mi_sign) == 1) {
      lv_img_set_src(ima_tile1_mi, &imgtileview_2_png);
  }
  if (((int)screen_tile1_le_sign) == 0) {
      lv_img_set_src(ima_tile1_le, &imgtileview1_press_png);
  } else if (((int)screen_tile1_le_sign) == 1) {
      lv_img_set_src(ima_tile1_le, &imgtileview_1_png);
  }
  lv_label_set_text(lab_tile1_time, "");

  lv_tileview_set_anim_time(tile_main, 100);

  task_callback_time = lv_task_create(callback_time, 1000 , LV_TASK_PRIO_HIGH , NULL);

  tileview1_tem_hum=lv_task_create(tileview1_tem_hum_cb,100 , LV_TASK_PRIO_HIGH , NULL);
}

void __qmsd_ima_tile3_mo_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  screen_tileview_equi_sign = 2;
  screen_tileview_sign = 1;
  scr_equipment_show();
  screen_tileview_delete();
  /*add here*/
    lv_task_del(tileview1_tem_hum);

} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_ima_cur_st__cb(lv_obj_t * obj, lv_event_t event) {
  if ((event) == (LV_EVENT_PRESSED)) {
    lv_img_set_src(ima_cur_st, &imgcurtain_button_on_png);
  } else if ((event) == (LV_EVENT_RELEASED)) {
    ima_cur_on_stop_sign = 1;
    lv_img_set_src(ima_cur_st, &imgcurtain_button_off_png);
    if(ima_cur_on_stop_sign == 1)
    {
        lv_anim_del(ima_cur_cle, (lv_anim_exec_xcb_t)lv_anim_ima_cur_le_function_cb);
        lv_anim_del(ima_cur_cri, (lv_anim_exec_xcb_t)lv_anim_ima_cur_ri_function_cb);
    }
    ima_cur_on_stop_sign = 0;
    bar_tile2_bar_value = (((422-lv_obj_get_x(ima_cur_cri))*100)/165);
  }
}

void __qmsd_ima_set_re_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  screen_tileview_sign = 0;
    lv_obj_del(list_main);
  screen_set_delete();
  screen_tileview_show();
  lv_obj_set_y(screen_cont, 0);
  lv_obj_set_style_local_bg_opa(screen_cont,0,0,245);
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_ima_tile3_mo__cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  screen_tileview_equi_sign = 2;
  screen_tileview_sign = 1;
  scr_equipment_show();
  screen_tileview_delete();
  /*add here*/
    lv_task_del(tileview1_tem_hum);

} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_ima_con_mor_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  screen_tileview_sign = 1;
  screen_tileview_choice_sign  = 2;
  screen_tileview_delete();
  /*add here*/
    lv_task_del(tileview1_tem_hum);

  screen_choice_show();
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_lab_tile3_mo_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  screen_tileview_equi_sign = 2;
  screen_tileview_sign = 1;
  scr_equipment_show();
  screen_tileview_delete();
  /*add here*/
    lv_task_del(tileview1_tem_hum);

} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_lab_con_mor_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  screen_tileview_sign = 1;
  screen_tileview_choice_sign  = 2;
  screen_tileview_delete();
  /*add here*/
    lv_task_del(tileview1_tem_hum);

  screen_choice_show();
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_screen_choice_init(void) {
  lv_obj_set_click(ima_cho_re,true);
  lv_obj_set_click(lab_cho_re,true);
  lv_obj_set_click(ima_cho_gh,true);
  lv_obj_set_click(ima_cho_lh,true);
  lv_obj_set_click(ima_cho_gb,true);
  lv_obj_set_click(ima_cho_sl,true);
  lv_obj_set_click(ima_cho_me,true);
  lv_obj_set_click(ima_cho_fi,true);
  lv_obj_set_click(ima_cho_gh_,true);
  lv_obj_set_click(ima_cho_lh_,true);
  lv_obj_set_click(ima_cho_gb_,true);
  lv_obj_set_click(ima_cho_sl_,true);
  lv_obj_set_click(ima_cho_me_,true);
  lv_obj_set_click(ima_cho_fi_,true);
  lv_obj_set_click(lab_cho_gh,true);
  lv_obj_set_click(lab_cho_lh,true);
  lv_obj_set_click(lab_cho_gb,true);
  lv_obj_set_click(lab_cho_sl,true);
  lv_obj_set_click(lab_cho_me,true);
  lv_obj_set_click(lab_cho_fi,true);
  /*ext_click screen_choice*/
  lv_obj_set_ext_click_area(lab_cho_re, 0, 10, 15, 15);
  lv_obj_set_ext_click_area(ima_cho_re, 15, 0, 15, 15);
}

void __qmsd_scr_curtain_ti1_init(void) {
  /* scr_curtain_til1 */
  lv_obj_set_click(ima_cur_re,true);
  lv_obj_set_click(lab_cur_le,true);
  lv_obj_set_click(lab_cur_ri,true);
  lv_obj_set_click(ima_cur_op,true);
  lv_obj_set_click(ima_cur_st,true);
  lv_obj_set_click(ima_cur_cl,true);
  lv_obj_set_click(ima_cur_on,true);
  lv_obj_set_click(ima_cur_op_,true);
  lv_obj_set_click(ima_cur_st_,true);
  lv_obj_set_click(ima_cur_cl_,true);
  lv_obj_set_click(ima_cur_on_,true);
  lv_obj_set_click(but_cur_ble,false);
  lv_obj_set_click(but_cur_bri,false);
  lv_obj_set_click(but_cur_le,false);
  lv_obj_set_click(but_cur_ri,false);
  lv_obj_set_style_local_bg_opa(but_cur_le,LV_BTN_PART_MAIN, LV_BTN_STATE_RELEASED, LV_OPA_100);
  lv_obj_set_style_local_bg_opa(but_cur_ri,LV_BTN_PART_MAIN, LV_BTN_STATE_RELEASED, LV_OPA_60);
  curtain_value = (60-(bar_tile2_bar_value*165)/100);
  lv_obj_set_x(ima_cur_cle, curtain_value);
  
  curtain_value = ((bar_tile2_bar_value*165)/100+257);
  lv_obj_set_x(ima_cur_cri, curtain_value);
  /*ext_click scr_curtain_til1*/
  lv_obj_set_ext_click_area(ima_cur_re, 20, 20, 20, 20);
}

void __qmsd_screen_air_init(void) {
  screen_air_function();
  lv_label_set_text_fmt(lab_air_tem,"%d",tileview2_temperature);
  /* screen_air init */
  lv_obj_set_click(ima_air_re, true);
  lv_obj_set_click(lab_air_re, true);
  lv_obj_set_click(ima_air_co, true);
  lv_obj_set_click(ima_air_sun, true);
  lv_obj_set_click(ima_air_lo, true);
  lv_obj_set_click(ima_air_mi, true);
  lv_obj_set_click(ima_air_hi, true);
  lv_obj_set_style_local_bg_color(swi_air_swi,LV_SWITCH_PART_BG, LV_STATE_DEFAULT, lv_color_hex(0xffffff));
  lv_obj_set_style_local_bg_opa(swi_air_swi,LV_SWITCH_PART_BG, LV_STATE_DEFAULT, LV_OPA_50);
  
  lv_obj_set_style_local_bg_color(swi_air_swi,LV_SWITCH_PART_INDIC, LV_STATE_DEFAULT, lv_color_hex(0x4a90e2));
  lv_obj_set_style_local_bg_opa(swi_air_swi,LV_SWITCH_PART_INDIC, LV_STATE_DEFAULT, LV_OPA_100);
  
  lv_obj_set_style_local_bg_color(swi_air_swi,LV_SWITCH_PART_KNOB, LV_STATE_DEFAULT, lv_color_hex(0xffffff));
  lv_obj_set_style_local_bg_opa(swi_air_swi,LV_SWITCH_PART_KNOB, LV_STATE_DEFAULT, LV_OPA_100);
  
  lv_obj_set_style_local_border_opa(swi_air_swi,LV_SWITCH_PART_BG, LV_STATE_DEFAULT, 0);
  lv_obj_set_style_local_border_opa(swi_air_swi,LV_SWITCH_PART_BG, LV_STATE_PRESSED, 0);
  lv_obj_set_style_local_border_opa(swi_air_swi,LV_SWITCH_PART_BG, LV_STATE_FOCUSED, 0);       
  
  lv_obj_set_style_local_outline_width(swi_air_swi,LV_SWITCH_PART_BG, LV_STATE_FOCUSED, 0);
  lv_obj_set_style_local_border_width(swi_air_swi,LV_SWITCH_PART_BG, LV_STATE_FOCUSED, 0);
  lv_obj_set_style_local_border_width(swi_air_swi,LV_SWITCH_PART_BG, LV_STATE_DEFAULT, 0);
  
  lv_obj_set_style_local_shadow_width(swi_air_swi,LV_SWITCH_PART_BG, LV_STATE_DEFAULT, 0);
  lv_obj_set_style_local_shadow_width(swi_air_swi,LV_SWITCH_PART_INDIC, LV_STATE_DEFAULT, 0);
  lv_obj_set_style_local_shadow_width(swi_air_swi,LV_SWITCH_PART_KNOB, LV_STATE_DEFAULT, 0);
  if(screen_tileview_air_sign == 1)/*open*/
  {
      lv_switch_on(swi_air_swi, LV_ANIM_OFF);
  }else if(screen_tileview_air_sign == 2)/*close*/
  {
      lv_switch_off(swi_air_swi, LV_ANIM_OFF);  
  }
  if(lv_switch_get_state(swi_air_swi))/*open*/
  {
      screen_tileview_air_sign = 1;
      lv_obj_set_click(ima_air_co, true);
      lv_obj_set_click(ima_air_sun, true);
      lv_obj_set_click(ima_air_lo, true);
      lv_obj_set_click(ima_air_mi, true);
      lv_obj_set_click(ima_air_hi, true);
  }else if(!(lv_switch_get_state(swi_air_swi)))/*close*/
  {
      screen_tileview_air_sign = 2;
      lv_obj_set_click(ima_air_co, false);
      lv_obj_set_click(ima_air_sun, false);
      lv_obj_set_click(ima_air_lo, false);
      lv_obj_set_click(ima_air_mi, false);
      lv_obj_set_click(ima_air_hi, false);  
  }
  /*ext_click screen_air*/
  lv_obj_set_ext_click_area(lab_air_re, 0, 10, 15, 15);
  lv_obj_set_ext_click_area(ima_air_re, 15, 0, 15, 15);
}

void __qmsd_ima_equ_re_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  scr_equipment_sign = 0;
  scr_equipment_delete();
  if (((int)screen_tileview_equi_sign) == 1) {
    screen_set_show();
  } else if (((int)screen_tileview_equi_sign) == 2) {
    screen_tileview_sign = 0;
    screen_tileview_show();
  }
  screen_tileview_equi_sign= -1;
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_screen_set_init(void) {
  my_list_create_fullction();
  lv_obj_set_click(ima_set_re, true);
  /*ext_click screen_set*/
  lv_obj_set_ext_click_area(ima_set_re, 20, 20, 20, 20);
}

void __qmsd_lab_equ_re_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  scr_equipment_sign = 0;
  scr_equipment_delete();
  if (((int)screen_tileview_equi_sign) == 1) {
    screen_set_show();
  } else if (((int)screen_tileview_equi_sign) == 2) {
    screen_tileview_sign = 0;
    screen_tileview_show();
  }
  screen_tileview_equi_sign= -1;
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_scr_equipment_init(void) {
  lv_anim_ima_equ_smi_function();
  scr_equipment_sign = 1;
  lv_img_set_pivot(ima_equ_load, 152, 89);
  lv_obj_set_click(lab_equ_re, true);
  lv_obj_set_click(ima_equ_re, true);
  _task_callback_eybwxi=lv_task_create(callback_eybwxi,10 , LV_TASK_PRIO_HIGH , NULL);
}

void __qmsd_screen_wifi_set_init(void) {
  lv_obj_set_click(lab_wif_re, true);
  lv_obj_set_style_local_bg_color(swi_wif_swi,LV_SWITCH_PART_BG, LV_STATE_DEFAULT, lv_color_hex(0xffffff));
  lv_obj_set_style_local_bg_opa(swi_wif_swi,LV_SWITCH_PART_BG, LV_STATE_DEFAULT, LV_OPA_50);
  
  lv_obj_set_style_local_bg_color(swi_wif_swi,LV_SWITCH_PART_INDIC, LV_STATE_DEFAULT, lv_color_hex(0x4a90e2));
  lv_obj_set_style_local_bg_opa(swi_wif_swi,LV_SWITCH_PART_INDIC, LV_STATE_DEFAULT, LV_OPA_100);
  
  lv_obj_set_style_local_bg_color(swi_wif_swi,LV_SWITCH_PART_KNOB, LV_STATE_DEFAULT, lv_color_hex(0xffffff));
  lv_obj_set_style_local_bg_opa(swi_wif_swi,LV_SWITCH_PART_KNOB, LV_STATE_DEFAULT, LV_OPA_100);
  
  lv_obj_set_style_local_border_opa(swi_wif_swi,LV_SWITCH_PART_BG, LV_STATE_DEFAULT, 0);
  lv_obj_set_style_local_border_opa(swi_wif_swi,LV_SWITCH_PART_BG, LV_STATE_PRESSED, 0);
  lv_obj_set_style_local_border_opa(swi_wif_swi,LV_SWITCH_PART_BG, LV_STATE_FOCUSED, 0);       
  
  lv_obj_set_style_local_outline_width(swi_wif_swi,LV_SWITCH_PART_BG, LV_STATE_FOCUSED, 0);
  lv_obj_set_style_local_border_width(swi_wif_swi,LV_SWITCH_PART_BG, LV_STATE_FOCUSED, 0);
  lv_obj_set_style_local_border_width(swi_wif_swi,LV_SWITCH_PART_BG, LV_STATE_DEFAULT, 0);
  
  lv_obj_set_style_local_shadow_width(swi_wif_swi,LV_SWITCH_PART_BG, LV_STATE_DEFAULT, 0);
  lv_obj_set_style_local_shadow_width(swi_wif_swi,LV_SWITCH_PART_INDIC, LV_STATE_DEFAULT, 0);
  lv_obj_set_style_local_shadow_width(swi_wif_swi,LV_SWITCH_PART_KNOB, LV_STATE_DEFAULT, 0);
  /*ext_click screen_wifi_set*/
  lv_obj_set_ext_click_area(lab_wif_re, 20, 20, 20, 20);
}

void __qmsd_screen_input_init(void) {
  g_show_kb();
  lv_keyboard_set_textarea(g_kb,tex_inp_tex);
}

// lv_task_t* tileview1_tem_hum;
void tileview1_tem_hum_cb(lv_task_t* t){
  if((int)get_tem_data == -1 && (int)get_hum_data == -1){
    lv_obj_set_style_local_text_color(lab_tile1_hum_,LV_LIST_PART_BG, LV_STATE_DEFAULT, lv_color_hex(0xD0021B));
    lv_label_set_text_fmt(lab_tile1_hum_, "%s", "EE");
    lv_obj_set_style_local_text_color(lab_tile1_tem,LV_LIST_PART_BG, LV_STATE_DEFAULT, lv_color_hex(0xD0021B));
    lv_label_set_text_fmt(lab_tile1_tem, "%s", "EE");
  }else{
    lv_obj_set_style_local_text_color(lab_tile1_hum_,LV_LIST_PART_BG, LV_STATE_DEFAULT, lv_color_hex(0xffffff));
    lv_label_set_text_fmt(lab_tile1_hum_, "%.2d", (int)get_hum_data);
    lv_obj_set_style_local_text_color(lab_tile1_tem,LV_LIST_PART_BG, LV_STATE_DEFAULT, lv_color_hex(0xffffff));
    lv_label_set_text_fmt(lab_tile1_tem, "%.2d",  (int)get_tem_data);
  }
}
