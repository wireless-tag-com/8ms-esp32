/**
 * @file qmsd_widget_calendar.h
 * @author sk (shuke@wireless-tag.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef _QMSD_WIDGET_CALENDAR_H_
#define _QMSD_WIDGET_CALENDAR_H_

#include "base_widget_type.h"

#ifdef __cplusplus
extern "C" {
#endif

#if defined QMSD_GUI_LVGL_V7
typedef lv_calendar_date_t qmsd_date_t; 
#elif defined QMSD_GUI_LVGL_V8
typedef lv_calendar_date_t qmsd_date_t; 
#endif

qmsd_widget_t* qmsd_widget_calendar_create(qmsd_widget_t* parent);

qmsd_err_t qmsd_widget_calendar_set_date(qmsd_widget_t* calendar,qmsd_date_t* date);

qmsd_err_t qmsd_widget_calendar_focus_date(qmsd_widget_t* calendar,qmsd_date_t* date);

qmsd_err_t qmsd_widget_calendar_get_date(qmsd_widget_t* calendar,qmsd_date_t* date);

qmsd_err_t qmsd_widget_calendar_get_focused_date(qmsd_widget_t* calendar,qmsd_date_t* date);

#ifdef __cplusplus
} /* extern "C" */
#endif
#endif // _QMSD_WIDGET_CALENDAR_H_