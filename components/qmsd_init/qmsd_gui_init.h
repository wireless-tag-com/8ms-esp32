#ifndef _QMSD_GUI_INIT_H
#define _QMSD_GUI_INIT_H

#include "lvgl.h"
#include "esp_err.h"
#include "screen_driver.h"
#include "lvgl/src/lv_core/qmsd_type.h"
#ifdef __cplusplus
extern "C"
{
#endif


esp_err_t qmsd_gui_init(scr_driver_t* driver,unsigned long custom_fb_size);

typedef void (*qmsd_init_cb)(void);
void qmsd_set_init_cb(qmsd_init_cb init_cb);

int qmsd_gui_lock(uint32_t timeout);
void qmsd_gui_unlock(void);

typedef void (*qmsd_ui_event_cb)(const char *obj_name, lv_obj_t* obj,lv_event_t event);
void qmsd_set_ui_event_cb(qmsd_ui_event_cb init_cb);
void qmsd_call_ui_event_cb(const char *obj_name, lv_obj_t* obj,lv_event_t event);

#ifdef __cplusplus
}
#endif

#endif /* _QMSD_GUI_INIT_H */
