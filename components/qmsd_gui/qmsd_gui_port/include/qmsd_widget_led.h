/**
 * @file qmsd_widget_led.h
 * @author sk (shuke@wireless-tag.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef _QMSD_WIDGET_LED_H_
#define _QMSD_WIDGET_LED_H_

#include "base_widget_type.h"

#ifdef __cplusplus
extern "C" {
#endif

qmsd_widget_t* qmsd_widget_led_create(qmsd_widget_t* parent);

qmsd_err_t qmsd_widget_led_set_bright(qmsd_widget_t* led,uint8_t level);

qmsd_err_t qmsd_widget_led_toggle(qmsd_widget_t* led);

bool qmsd_widget_led_get_state(qmsd_widget_t* led);

#ifdef __cplusplus
} /* extern "C" */
#endif
#endif // _QMSD_WIDGET_LED_H_