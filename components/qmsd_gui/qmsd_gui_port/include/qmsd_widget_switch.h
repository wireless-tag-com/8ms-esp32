/**
 * @file qmsd_widget_switch.h
 * @author sk (shuke@wireless-tag.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef _QMSD_WIDGET_SWITCH_H_
#define _QMSD_WIDGET_SWITCH_H_

#include "base_widget_type.h"

#ifdef __cplusplus
extern "C" {
#endif

qmsd_widget_t* qmsd_widget_switch_create(qmsd_widget_t* parent);

qmsd_err_t qmsd_widget_switch_troggle(qmsd_widget_t* sw);

bool qmsd_widget_switch_is_checked(qmsd_widget_t* sw);

#ifdef __cplusplus
} /* extern "C" */
#endif
#endif // _QMSD_WIDGET_SWITCH_H_