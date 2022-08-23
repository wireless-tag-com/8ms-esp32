#ifndef _QMSD_WIDGET_TIMER_H_
#define _QMSD_WIDGET_TIMER_H_

#include "base_widget_type.h"
#include "qmsd_gui_obj.h"
#include "qmsd_top_gui.h"

#ifdef __cplusplus
extern "C" {
#endif


#if defined QMSD_GUI_LVGL_V7
typedef lv_task_t qmsd_timer_t;
typedef void(*qmsd_timer_cb_t)(struct _lv_task_t*);
#elif defined QMSD_GUI_LVGL_V8
typedef lv_timer_t qmsd_timer_t;
typedef void (*qmsd_timer_cb_t)(struct _lv_timer_t*);
#endif
/**
 * @brief Create a timer
 * 
 * @param cb cb
 * @param period 
 * @param user_data 
 * @return qmsd_timer_t 
 */
qmsd_timer_t* qmsd_timer_create(qmsd_timer_cb_t cb,uint32_t period,void* user_data);

qmsd_err_t qmsd_timer_del(qmsd_timer_t* t);

qmsd_err_t qmsd_timer_ready(qmsd_timer_t* t);

qmsd_err_t qmsd_timer_set_period(qmsd_timer_t* t,uint32_t period);

qmsd_err_t qmsd_timer_set_repeat_limit(qmsd_timer_t* t,uint32_t repeat);

#ifdef __cplusplus
} /* extern "C" */
#endif
#endif // _QMSD_WIDGET_TIMER_H_