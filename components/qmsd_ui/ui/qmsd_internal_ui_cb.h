#ifndef __QMSD_INTERNEL_UI_CB_H
#define __QMSD_INTERNEL_UI_CB_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "lvgl.h"

#define BLOCKLY_button_light_EVENT_HANDLER
void __qmsd_button_light_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_button_curtain_EVENT_HANDLER
void __qmsd_button_curtain_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_button_conditioner_EVENT_HANDLER
void __qmsd_button_conditioner_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_button_control_EVENT_HANDLER
void __qmsd_button_control_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_button_screen_light_EVENT_HANDLER
void __qmsd_button_screen_light_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_button_screen_curtain_EVENT_HANDLER
void __qmsd_button_screen_curtain_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_button_screen_condition_EVENT_HANDLER
void __qmsd_button_screen_condition_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_button_screen_control_EVENT_HANDLER
void __qmsd_button_screen_control_cb(lv_obj_t* obj,lv_event_t event);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif //__QMSD_INTERNEL_UI_CB_H