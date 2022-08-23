#ifndef _QMSD_WIDGET_LINE_H_
#define _QMSD_WIDGET_LINE_H_

#include "base_widget_type.h"

#ifdef __cplusplus
extern "C" {
#endif
#if defined QMSD_GUI_LVGL_V7
typedef lv_point_t qmsd_line_point_t;
#elif defined QMSD_GUI_LVGL_V8
typedef lv_point_t qmsd_line_point_t;
#endif

qmsd_widget_t* qmsd_widget_line_create(qmsd_widget_t* parent);

qmsd_err_t qmsd_widget_line_add_point(qmsd_widget_t* line,qmsd_line_point_t point[],uint16_t point_num);

qmsd_err_t qmsd_widget_line_set_point_radius(qmsd_widget_t* line,uint16_t radius);

#ifdef __cplusplus
} /* extern "C" */
#endif
#endif // _QMSD_WIDGET_LINE_H_