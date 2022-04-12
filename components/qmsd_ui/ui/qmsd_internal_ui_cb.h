#ifndef __QMSD_INTERNEL_UI_CB_H
#define __QMSD_INTERNEL_UI_CB_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "lvgl.h"

void __qmsd_main_button_1_cb(lv_obj_t* obj,lv_event_t event);
void __qmsd_test_button_1_cb(lv_obj_t* obj,lv_event_t event);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif //__QMSD_INTERNEL_UI_CB_H