#ifndef _QMSD_WIDGET_CHART_H_
#define _QMSD_WIDGET_CHART_H_

#include "base_widget_type.h"

#ifdef __cplusplus
extern "C" {
#endif

#if defined QMSD_GUI_LVGL_V7
typedef lv_chart_type_t qmsd_widget_chart_type_t;
typedef lv_chart_series_t qmsd_chart_series_t;
#elif defined QMSD_GUI_LVGL_V8
typedef lv_chart_type_t qmsd_widget_chart_type_t;
typedef lv_chart_series_t qmsd_chart_series_t;
#endif

qmsd_widget_t* qmsd_widget_chart_create(qmsd_widget_t* parent);

qmsd_err_t qmsd_widget_chart_set_type(qmsd_widget_t* chart,qmsd_widget_chart_type_t type);

qmsd_err_t qmsd_widget_chart_set_div_line(qmsd_widget_t* chart,uint8_t hor_div , uint8_t ver_div);

qmsd_err_t qmsd_widget_chart_set_y_range(qmsd_widget_t* chart,int16_t min ,int16_t max);

qmsd_chart_series_t* qmsd_widget_chart_add_series(qmsd_widget_t*chart, lv_color_t color);

qmsd_err_t qmsd_widget_chart_set_x_tick_txt(qmsd_widget_t* chart);

qmsd_err_t qmsd_widget_chart_set_y_tick_txt(qmsd_widget_t* chart);

qmsd_err_t qmsd_widget_chart_set_x_tick_length(qmsd_widget_t* chart);

qmsd_err_t qmsd_widget_chart_set_y_tick_length(qmsd_widget_t* chart);

qmsd_err_t qmsd_widget_chart_set_point_count(qmsd_widget_t* chart);

qmsd_err_t qmsd_widget_chart_set_points(qmsd_widget_t* chart);

#ifdef __cplusplus
} /* extern "C" */
#endif
#endif // _QMSD_WIDGET_CHART_H_