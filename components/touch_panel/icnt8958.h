#ifndef _TOUCH_ICNT8958_H
#define _TOUCH_ICNT8958_H

void touch_icnt8958_init(uint8_t sda, uint8_t scl, uint8_t intr_pin);
void touch_icnt8958_read(uint16_t* x, uint16_t* y, uint8_t* touched);

#endif
