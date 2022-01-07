#ifndef _LCD_TOUCH_
#define _LCD_TOUCH_
#include <stdbool.h>
#include "lvgl.h"
#include "lv_conf.h"

void init_lcd_touch_gt911(void);
bool touchpad_gt911_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data);

#endif



