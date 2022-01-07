/**
 * @file touch_driver.h
 */

#ifndef TOUCH_DRIVER_H
#define TOUCH_DRIVER_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include <stdint.h>
#include <stdbool.h>
#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#if defined (CONFIG_LV_TOUCH_CONTROLLER_XPT2046)
#include "xpt2046.h"
#elif defined (CONFIG_LV_TOUCH_CONTROLLER_FT6X06)
#include "ft6x36.h"
#elif defined (CONFIG_LV_TOUCH_CONTROLLER_STMPE610)
#include "stmpe610.h"
#elif defined (CONFIG_LV_TOUCH_CONTROLLER_ADCRAW)
#include "adcraw.h"
#elif defined (CONFIG_LV_TOUCH_CONTROLLER_FT81X)
#include "FT81x.h"
#elif defined (CONFIG_LV_TOUCH_CONTROLLER_RA8875)
#include "ra8875_touch.h"
#elif defined (CONFIG_WT_86_32_3ZW0)
#include "../qmsd_tp/gt911/lcd_touch.h"
#elif defined (CONFIG_WT_86_32_3ZW1)
#include "../qmsd_tp/gslx680/lcd_touch_gslx680.h"
#endif

/*********************
*      DEFINES
*********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/
void touch_driver_init(void);
bool touch_driver_read(lv_indev_drv_t *drv, lv_indev_data_t *data);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* TOUCH_DRIVER_H */
