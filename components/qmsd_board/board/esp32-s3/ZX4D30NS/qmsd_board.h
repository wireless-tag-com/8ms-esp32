#pragma once

#include "stdint.h"
#include "sdkconfig.h"
#include "qmsd_board_pin.h"
#include "qmsd_board_def.h"
#include "qmsd_board_config.h"
#include "qmsd_board_utils.h"
#include "qmsd_touch.h"
#include "qmsd_gui.h"

#include "esp_lcd_panel_ops.h"
#include "esp_lcd_panel_interface.h"
#include "qmsd_lcd_panel_rgb.h"
#include "screen_driver.h"

#ifdef __cplusplus
extern "C" {
#endif

extern esp_lcd_panel_handle_t g_rgb_panel_handle;

void qmsd_board_init(qmsd_board_config_t* config);

void qmsd_board_init_screen();

void qmsd_board_init_touch();

void qmsd_board_init_gui();

scr_driver_t* qmsd_get_screen_driver();

#ifdef __cplusplus
}
#endif