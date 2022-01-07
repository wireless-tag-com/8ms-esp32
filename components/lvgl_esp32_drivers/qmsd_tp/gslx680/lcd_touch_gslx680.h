#ifndef _LCD_TOUCH_GSLX680
#define _LCD_TOUCH_GSLX680
#include "lvgl.h"
#include "lv_conf.h"

void init_lcd_touch_gslx680(void);
bool touchpad_gslx680_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data);

#endif



