#ifndef __QMSD_INTERNEL_UI_CB_H
#define __QMSD_INTERNEL_UI_CB_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "lvgl.h"

#define BLOCKLY_button_b1_EVENT_HANDLER
void __qmsd_button_b1_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_button_b2_EVENT_HANDLER
void __qmsd_button_b2_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_cont_top_EVENT_HANDLER
void __qmsd_cont_top_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_screen_main_SCREEN_INIT
void __qmsd_screen_main_init(void);

#define BLOCKLY_image_open_EVENT_HANDLER
void __qmsd_image_open_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_image_close_EVENT_HANDLER
void __qmsd_image_close_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_image_stop_EVENT_HANDLER
void __qmsd_image_stop_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_button_b3_EVENT_HANDLER
void __qmsd_button_b3_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_image_top_set_EVENT_HANDLER
void __qmsd_image_top_set_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_screen_wifi_SCREEN_INIT
void __qmsd_screen_wifi_init(void);

#define BLOCKLY_screen_set_back_EVENT_HANDLER
void __qmsd_screen_set_back_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_button_b4_EVENT_HANDLER
void __qmsd_button_b4_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_image_top_home_EVENT_HANDLER
void __qmsd_image_top_home_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_switch_wifi_EVENT_HANDLER
void __qmsd_switch_wifi_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_list_86ba_EVENT_HANDLER
void __qmsd_list_86ba_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_screen_theme_SCREEN_INIT
void __qmsd_screen_theme_init(void);

#define BLOCKLY_image_wifi_back_EVENT_HANDLER
void __qmsd_image_wifi_back_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_image_themeback_EVENT_HANDLER
void __qmsd_image_themeback_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_image_theme_1_EVENT_HANDLER
void __qmsd_image_theme_1_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_image_theme_2_EVENT_HANDLER
void __qmsd_image_theme_2_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_image_theme_3_EVENT_HANDLER
void __qmsd_image_theme_3_cb(lv_obj_t* obj,lv_event_t event);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif //__QMSD_INTERNEL_UI_CB_H