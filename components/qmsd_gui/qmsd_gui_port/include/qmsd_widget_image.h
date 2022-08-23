/**
 * @file qmsd_widget_image.h
 * @author sk (shuke@wireless-tag.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef _QMSD_WIDGET_IMAGE_H_
#define _QMSD_WIDGET_IMAGE_H_

#include "base_widget_type.h"

#ifdef __cplusplus
extern "C" {
#endif

qmsd_widget_t* qmsd_widget_image_create(qmsd_widget_t* parent);

qmsd_err_t qmsd_widget_image_set_src(qmsd_widget_t* img , const void* src );

qmsd_err_t qmsd_widget_image_set_pivot(qmsd_widget_t* img ,int16_t x , int16_t y);

qmsd_err_t qmsd_widget_image_set_rotation(qmsd_widget_t* img ,int16_t rotation);

qmsd_err_t qmsd_widget_image_set_zoom(qmsd_widget_t* img ,int16_t zoom);

#ifdef __cplusplus
} /* extern "C" */
#endif
#endif // _QMSD_WIDGET_IMAGE_H_