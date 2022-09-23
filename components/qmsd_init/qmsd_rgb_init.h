/**
 * @file qmsd_rgb_init.h
 */

#ifndef __QMSD_RGB_INIT_H
#define __QMSD_RGB_INIT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "qmsd_lcd_rgb_panel.h"

#if SOC_LCD_RGB_SUPPORTED

void qmsd_rgb_init(esp_lcd_rgb_panel_config_t *panel_config);

#endif

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*__QMSD_SPI_INIT_H*/
