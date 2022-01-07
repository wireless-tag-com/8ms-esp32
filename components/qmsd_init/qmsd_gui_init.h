#ifndef _QMSD_GUI_INIT_H
#define _QMSD_GUI_INIT_H

#include "lvgl.h"
#include "esp_err.h"
#include "lvgl_helpers.h"
#include "screen_driver.h"
#include "lvgl/src/lv_core/qmsd_type.h"
#ifdef __cplusplus
extern "C"
{
#endif

esp_err_t qmsd_gui_init(unsigned long custom_fb_size);

typedef void (*qmsd_init_cb)(void);
void qmsd_set_init_cb(qmsd_init_cb init_cb);

int qmsd_gui_lock(uint32_t timeout);
void qmsd_gui_unlock(void);

#ifdef __cplusplus
}
#endif

#endif /* _QMSD_GUI_INIT_H */
