#ifndef _QMSD_WIDGET_TABVIEW_H_
#define _QMSD_WIDGET_TABVIEW_H_

#include "base_widget_type.h"

#ifdef __cplusplus
extern "C" {
#endif

#if defined QMSD_GUI_LVGL_V7
typedef lv_tabview_btns_pos_t qmsd_tabview_type_t;
#elif defined QMSD_GUI_LVGL_V8
typedef uint8_t qmsd_tabview_type_t;
#endif

qmsd_widget_t* qmsd_widget_tabview_create(qmsd_widget_t* parent);

qmsd_err_t qmsd_widget_tabview_set_title_dir(qmsd_widget_t* tabview ,qmsd_tabview_type_t type);

qmsd_widget_t* qmsd_widget_tabview_add_tab(qmsd_widget_t* tabview,const char* title);

qmsd_err_t qmsd_widget_tabview_tab_switch(qmsd_widget_t* tabview ,uint16_t index,uint16_t anime_time);

qmsd_err_t qmsd_widget_tabview_rename(qmsd_widget_t* tabview ,uint16_t index ,const char* title);

uint16_t qmsd_widget_tabview_get_tab_act(qmsd_widget_t* tabview);

uint16_t qmsd_widget_tabview_get_tab_count(qmsd_widget_t* tabview);



#ifdef __cplusplus
} /* extern "C" */
#endif
#endif // _QMSD_WIDGET_TABVIEW_H_