#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

#ifndef GT1151_IRQ_PIN
#define GT1151_IRQ_PIN     108
#endif

#ifndef GT1151_TOUCH_WIDTH
#define GT1151_TOUCH_WIDTH  800
#endif

#ifndef GT1151_TOUCH_HEIGHT
#define GT1151_TOUCH_HEIGHT 480
#endif

#ifndef GT1151_SUPPORT_POINTS
#define GT1151_SUPPORT_POINTS 10
#endif

bool touchpad_gt1151_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data);
esp_err_t gt1151_i2c_init(int bus_num, uint32_t clk_speed, int scl, int sda);

int gt1151_init(void);

#ifdef __cplusplus
}
#endif
