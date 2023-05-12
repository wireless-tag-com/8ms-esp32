#ifndef __QMSD_INTERNEL_UI_CB_H
#define __QMSD_INTERNEL_UI_CB_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "lvgl.h"

#define BLOCKLY_button_left_EVENT_HANDLER
void __qmsd_button_left_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_button_hu_left_EVENT_HANDLER
void __qmsd_button_hu_left_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_button_right_EVENT_HANDLER
void __qmsd_button_right_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_button_hu_right_EVENT_HANDLER
void __qmsd_button_hu_right_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_button_w_left_EVENT_HANDLER
void __qmsd_button_w_left_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_button_f_left_EVENT_HANDLER
void __qmsd_button_f_left_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_button_w_right_EVENT_HANDLER
void __qmsd_button_w_right_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_button_f_right_EVENT_HANDLER
void __qmsd_button_f_right_cb(lv_obj_t* obj,lv_event_t event);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif //__QMSD_INTERNEL_UI_CB_H