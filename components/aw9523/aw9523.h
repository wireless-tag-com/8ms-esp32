#pragma once

#include "stdint.h"

typedef enum {
    AW9523_PORT_0,
    AW9523_PORT_1
} aw9523_port_t;

typedef enum {
    AW9523_MODE_OUTPUT,
    AW9523_MODE_INPUT,
} aw9523_inout_mode_t;

typedef enum {
    AW9523_MODE_LED,
    AW9523_MODE_GPIO,
} aw9523_mode_t;

typedef enum {
    AW9523_37mA = 0x00,
    AW9523_27P25mA,
    AW9523_18P5mA,
    AW9523_9P25mA,
} aw9523_current_t;

#ifdef __cplusplus
extern "C" {
#endif

void aw9523_init(uint8_t sda_pin, uint8_t scl_pin);

uint8_t aw9523_read_level(aw9523_port_t port);

void aw9523_set_level(aw9523_port_t port, uint8_t value);

void aw9523_io_set_level(aw9523_port_t port, uint8_t pin_num, uint8_t value);

void aw9523_set_inout(aw9523_port_t port, uint8_t mode);

void aw9523_io_set_inout(aw9523_port_t port, uint8_t pin_num, aw9523_inout_mode_t mode);

void aw9523_set_port0_pp(uint8_t pp_enable);

void aw9523_set_led_max_current(aw9523_current_t current);

void aw9523_set_gpio_or_led(aw9523_port_t port, uint8_t mode);

void aw9523_io_set_gpio_or_led(aw9523_port_t port, uint8_t pin_num, aw9523_mode_t mode);

void aw9523_led_set_duty(aw9523_port_t port, uint8_t pin_num, uint8_t duty);

void aw9523_leds_set_duty(aw9523_port_t port, uint8_t pin_num, uint8_t nums, uint8_t duty);

void aw9523_softreset();

#ifdef __cplusplus
}
#endif

