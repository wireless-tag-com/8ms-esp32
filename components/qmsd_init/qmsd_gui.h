#ifndef _QMSD_GUI_H
#define _QMSD_GUI_H

#include "lvgl.h"
#ifdef __cplusplus
extern "C"
{
#endif
typedef void (*qmsd_ui_event_cb)(const char *obj_name, lv_obj_t* obj,lv_event_t event);
void qmsd_set_ui_event_cb(qmsd_ui_event_cb init_cb);
void qmsd_call_ui_event_cb(const char *obj_name, lv_obj_t* obj,lv_event_t event);
lv_group_t* qmsd_get_group(void);

#ifdef __cplusplus
}
#endif

#endif /* _QMSD_GUI_H */
