#ifndef _TOUCH_CST836U_H
#define _TOUCH_CST836U_H

void cst836u_touch_init(int8_t sda, int8_t scl, int8_t intr_pin);
void cst836u_read_status(uint16_t* x, uint16_t* y, uint8_t* touched);

#endif
