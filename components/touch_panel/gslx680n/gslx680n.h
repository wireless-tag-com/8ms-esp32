#pragma once
#include "stdint.h"

void gslx680n_init(int8_t sda, int8_t scl, int8_t intr_pin, int8_t rst_pin);
void gslx680n_read_status(uint16_t* x, uint16_t* y, uint8_t* touched);

