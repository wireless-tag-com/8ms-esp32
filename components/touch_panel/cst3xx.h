#ifndef _TOUCH_CST3XX_H
#define _TOUCH_CST3XX_H

#define CST3XX_ADDRESS 	0x1A

void cst3xx_touch_init(int8_t sda, int8_t scl, int8_t intr_pin);
void cst3xx_read_status(uint16_t* x, uint16_t* y, uint8_t* touched);

#endif
