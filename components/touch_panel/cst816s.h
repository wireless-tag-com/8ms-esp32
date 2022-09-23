#ifndef _TOUCH_CST816S_H
#define _TOUCH_CST816S_H

#define CST816S_ADDR    0x1

void cst816s_touch_init(int8_t sda, int8_t scl, int8_t intr_pin);
void cst816s_read_status(uint16_t* x, uint16_t* y, uint8_t* touched);

#endif
