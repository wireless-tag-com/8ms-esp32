#ifndef QM_UI_ENTRY_H
#define QM_UI_ENTRY_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/lvgl.h"
#include "lvgl_device.h"

void lv_qm_ui_entry(void);
void lv_qm_ui_loop(void);
void lvgl_blockly_init(void);
void lvgl_blockly_loop(void);
void lvgl_device_init(void);
void lvgl_device_loop(void);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*QM_UI_ENTRY_H*/
