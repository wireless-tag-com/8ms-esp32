#ifndef __GT2863_H
#define __GT2863_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void gt2863_read_status(uint16_t* x, uint16_t* y, uint8_t* touched);
void gt2863_init(int8_t sda, int8_t scl, int8_t intr_pin);

#ifdef __cplusplus
}
#endif
#endif /* __GT911_H */
