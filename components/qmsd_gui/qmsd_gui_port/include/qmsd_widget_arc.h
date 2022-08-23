/**
 * @file qmsd_widget_arc.h
 * @author sk (shuke@wireless-tag.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef _QMSD_WIDGET_ARC_H_
#define _QMSD_WIDGET_ARC_H_

#include "base_widget_type.h"

#ifdef __cplusplus
extern "C" {
#endif

qmsd_widget_t* qmsd_widget_arc_create(qmsd_widget_t* parent);

qmsd_err_t qmsd_widget_arc_set_angles(qmsd_widget_t* arc,uint16_t angles);

qmsd_err_t qmsd_widget_arc_set_offset(qmsd_widget_t* arc , int16_t offset);

qmsd_err_t qmsd_widget_arc_set_range(qmsd_widget_t* arc , int16_t min, int16_t max);

qmsd_err_t qmsd_widget_arc_set_value(qmsd_widget_t* arc , int16_t value);

qmsd_err_t qmsd_widget_arc_enable_slide(qmsd_widget_t* arc , bool slide);

int16_t qmsd_widget_arc_get_value(qmsd_widget_t* arc);

int16_t qmsd_widget_arc_get_start(qmsd_widget_t* arc);

int16_t qmsd_widget_arc_get_end(qmsd_widget_t* arc);

int16_t qmsd_widget_arc_get_offset(qmsd_widget_t* arc);

#ifdef __cplusplus
} /* extern "C" */
#endif
#endif // _QMSD_WIDGET_ARC_H_