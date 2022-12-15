#ifndef __QMSD_UI_CB_H
#define __QMSD_UI_CB_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "lvgl.h"

void qmsd_ui_cb(const char *name, lv_obj_t* obj,lv_event_t event);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif //__QMSD_UI_CB_H