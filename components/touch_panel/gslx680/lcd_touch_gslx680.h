#ifndef _LCD_TOUCH_GSLX680
#define _LCD_TOUCH_GSLX680
typedef struct
{
    uint16_t x, y;
} tp_position_t;
extern xQueueHandle tp_queue;
void init_lcd_touch_gslx680(void);

#endif



