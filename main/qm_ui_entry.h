#ifndef QM_UI_ENTRY_H
#define QM_UI_ENTRY_H

#ifdef __cplusplus
extern "C" {
#endif


#include "lvgl/lvgl.h"

void lv_qm_ui_entry(void);
void lv_qm_ui_loop(void);
lv_obj_t *lv_8ms_get_screen(char *name);
lv_obj_t *lv_8ms_get_widget(char *w_name);
const char *lv_8ms_get_obj_name(lv_obj_t *obj);
int lv_8ms_gpio_app_init(void);
void lv_8ms_uart_app_init(int uart_num);
#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*QM_UI_ENTRY_H*/
