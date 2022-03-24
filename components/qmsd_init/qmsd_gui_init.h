#ifndef _QMSD_GUI_INIT_H
#define _QMSD_GUI_INIT_H

#include "lvgl.h"
#include "esp_err.h"
#include "screen_driver.h"
#include "lvgl/src/lv_core/qmsd_type.h"
#include "qmsd_board_init.h"

#ifdef __cplusplus
extern "C"
{
#endif


esp_err_t qmsd_gui_init(uint32_t custom_fb_size,uint8_t dir);

typedef void (*qmsd_init_cb)(void);

typedef void (*qmsd_board_init_cus)(qmsd_screen_rotation_t dir);

void qmsd_set_init_cb(qmsd_init_cb init_cb);
void qmsd_set_board_init_cus(qmsd_board_init_cus init_cus);

int qmsd_gui_lock(uint32_t timeout);
void qmsd_gui_unlock(void);

typedef void (*qmsd_ui_event_cb)(const char *obj_name, lv_obj_t* obj,lv_event_t event);
void qmsd_set_ui_event_cb(qmsd_ui_event_cb init_cb);
void qmsd_call_ui_event_cb(const char *obj_name, lv_obj_t* obj,lv_event_t event);
lv_group_t *qmsd_create_group(void);

#ifdef __cplusplus
}
#endif

#endif /* _QMSD_GUI_INIT_H */
