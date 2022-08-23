/**
 * @file qmsd_widget_slider.h
 * @author sk (shuke@wireless-tag.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef _QMSD_WIDGET_SLIDER_H_
#define _QMSD_WIDGET_SLIDER_H_

#include "base_widget_type.h"

#ifdef __cplusplus
extern "C" {
#endif

qmsd_widget_t* qmsd_widget_slider_create(qmsd_widget_t* parent);

qmsd_err_t qmsd_widget_slider_set_range(qmsd_widget_t* slider , int16_t min , int16_t max);

qmsd_err_t qmsd_widget_slider_set_value(qmsd_widget_t* slider , int16_t value , bool anime);

int16_t qmsd_widget_slider_get_value(qmsd_widget_t* slider);



#ifdef __cplusplus
} /* extern "C" */
#endif
#endif // _QMSD_WIDGET_SLIDER_H_