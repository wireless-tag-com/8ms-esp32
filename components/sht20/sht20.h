#pragma once

#include "stdint.h"

#define SHT20_IIC_ADDR 0x40

#ifdef __cplusplus
extern "C" {
#endif

void sht20_init(uint8_t sda, uint8_t scl);

void sht20_reset();

float sht20_get_temperature();

float sht20_get_humidity();

#ifdef __cplusplus
}
#endif