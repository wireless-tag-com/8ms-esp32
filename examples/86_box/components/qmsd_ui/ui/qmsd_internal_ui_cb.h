#ifndef __QMSD_INTERNEL_UI_CB_H
#define __QMSD_INTERNEL_UI_CB_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "lvgl.h"

#define BLOCKLY_screen_main_SCREEN_INIT
void __qmsd_screen_main_init(void);

#define BLOCKLY_screen_temper_SCREEN_INIT
void __qmsd_screen_temper_init(void);

#define BLOCKLY_image_mu_list_EVENT_HANDLER
void __qmsd_image_mu_list_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_image_play_re_EVENT_HANDLER
void __qmsd_image_play_re_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_screen_music_SCREEN_INIT
void __qmsd_screen_music_init(void);

#define BLOCKLY_button_ma_music_EVENT_HANDLER
void __qmsd_button_ma_music_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_button_ma_tem_EVENT_HANDLER
void __qmsd_button_ma_tem_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_button_ma_light_EVENT_HANDLER
void __qmsd_button_ma_light_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_image_mu_return_EVENT_HANDLER
void __qmsd_image_mu_return_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_screen_light_SCREEN_INIT
void __qmsd_screen_light_init(void);

#define BLOCKLY_image_te_return_EVENT_HANDLER
void __qmsd_image_te_return_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_label_mu_return_EVENT_HANDLER
void __qmsd_label_mu_return_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_image_li_return_EVENT_HANDLER
void __qmsd_image_li_return_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_label_te_return_EVENT_HANDLER
void __qmsd_label_te_return_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_label_li_return_EVENT_HANDLER
void __qmsd_label_li_return_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_image_ma_high_EVENT_HANDLER
void __qmsd_image_ma_high_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_image_te_up_EVENT_HANDLER
void __qmsd_image_te_up_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_image_ma_low_EVENT_HANDLER
void __qmsd_image_ma_low_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_image_mu_prev_EVENT_HANDLER
void __qmsd_image_mu_prev_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_image_mu_next_EVENT_HANDLER
void __qmsd_image_mu_next_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_switch_ma_EVENT_HANDLER
void __qmsd_switch_ma_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_switch_te_EVENT_HANDLER
void __qmsd_switch_te_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_image_mu_s_l_EVENT_HANDLER
void __qmsd_image_mu_s_l_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_image_mu_s_r_EVENT_HANDLER
void __qmsd_image_mu_s_r_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_image_li_set_EVENT_HANDLER
void __qmsd_image_li_set_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_image_mu_s_m_EVENT_HANDLER
void __qmsd_image_mu_s_m_cb(lv_obj_t* obj,lv_event_t event);

#ifdef __cplusplus
} /* extern "C" */
#endif

// int set_windy;

#endif //__QMSD_INTERNEL_UI_CB_H