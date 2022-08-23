/**
 * @file qmsd_widget_gauge.h
 * @author sk (shuke@wireless-tag.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef _QMSD_WIDGET_GAUGE_H_
#define _QMSD_WIDGET_GAUGE_H_

#include "base_widget_type.h"

#ifdef _gauge_cplusplus
extern "C" {
#endif

qmsd_widget_t* qmsd_widget_gauge_create(qmsd_widget_t* parent);

qmsd_err_t qmsd_widget_gauge_set_needle_amount(qmsd_widget_t* gauge ,uint16_t amount,lv_color_t* color_array);

qmsd_err_t qmsd_widget_gauge_set_needle_img(qmsd_widget_t* gauge,const void* imgsrc,int16_t pivot_x ,int16_t pivot_y);

qmsd_err_t qmsd_widget_gauge_set_range(qmsd_widget_t* gauge , int16_t min , int16_t max);

qmsd_err_t qmsd_widget_gauge_set_needle_value(qmsd_widget_t* gauge , uint16_t index , int16_t value);

int16_t qmsd_widget_gauge_get_needle_value(qmsd_widget_t* gauge,uint8_t needle);

#ifdef _gauge_cplusplus
} /* extern "C" */
#endif
#endif // _QMSD_WIDGET_GAUGE_H_