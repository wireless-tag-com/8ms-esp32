#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "i2c_device.h"
#include "driver/gpio.h"
#include "aw9523.h"

static I2CDevice_t aw9523_device;

#define AW9523_CHECK_NUM(pin_num) if ((pin_num) > 7) { return; }

void aw9523_init(uint8_t sda_pin, uint8_t scl_pin) {
    aw9523_device = i2c_malloc_device(I2C_NUM_0, sda_pin, scl_pin, 400000, 0x5b);
}

uint8_t aw9523_read_level(aw9523_port_t port) {
    uint8_t data = 0x00;
    i2c_read_byte(aw9523_device, (port == AW9523_PORT_0) ? 0x00 : 0x01, &data);
    return data;
}

void aw9523_set_level(aw9523_port_t port, uint8_t value) {
    uint8_t reg = (port == AW9523_PORT_0) ? 0x02 : 0x03;
    i2c_write_byte(aw9523_device, reg, value);
}

void aw9523_io_set_level(aw9523_port_t port, uint8_t pin_num, uint8_t value) {
    AW9523_CHECK_NUM(pin_num);
    uint8_t reg = (port == AW9523_PORT_0) ? 0x02 : 0x03;
    i2c_write_bit(aw9523_device, reg, value > 0, pin_num);
}

void aw9523_set_inout(aw9523_port_t port, uint8_t mode) {
    uint8_t reg = (port == AW9523_PORT_0) ? 0x04 : 0x05;
    i2c_write_byte(aw9523_device, reg, mode);
}

void aw9523_io_set_inout(aw9523_port_t port, uint8_t pin_num, aw9523_inout_mode_t mode) {
    AW9523_CHECK_NUM(pin_num);
    uint8_t reg = (port == AW9523_PORT_0) ? 0x04 : 0x05;
    uint8_t value = (mode == AW9523_MODE_INPUT) ? 1 : 0;
    i2c_write_bit(aw9523_device, reg, value, pin_num);
}

void aw9523_set_port0_pp(uint8_t pp_enable) {
    i2c_write_bit(aw9523_device, 0x11, pp_enable ? 1 : 0, 4);
}

void aw9523_set_led_max_current(aw9523_current_t current) {
    i2c_write_bits(aw9523_device, 0x11, current, 0, 2);
}

void aw9523_set_gpio_or_led(aw9523_port_t port, uint8_t mode) {
    uint8_t reg = (port == AW9523_PORT_0) ? 0x12 : 0x13;
    i2c_write_byte(aw9523_device, reg, mode);
}

void aw9523_io_set_gpio_or_led(aw9523_port_t port, uint8_t pin_num, aw9523_mode_t mode) {
    AW9523_CHECK_NUM(pin_num);
    uint8_t reg = (port == AW9523_PORT_0) ? 0x12 : 0x13;
    uint8_t value = (mode == AW9523_MODE_GPIO) ? 1 : 0;
    i2c_write_bit(aw9523_device, reg, value, pin_num);
}

void aw9523_led_set_duty(aw9523_port_t port, uint8_t pin_num, uint8_t duty) {
    AW9523_CHECK_NUM(pin_num);
    uint8_t reg;
    if (port == AW9523_PORT_0) {
        reg = 0x24 + pin_num;
    } else {
        reg = 0x20 + pin_num + ((pin_num > 3) ? 0x08 : 0x00);
    }
    i2c_write_byte(aw9523_device, reg, duty);
}

void aw9523_leds_set_duty(aw9523_port_t port, uint8_t pin_num, uint8_t nums, uint8_t duty) {
    AW9523_CHECK_NUM(pin_num + nums);
    uint8_t dutys[8] = {0};
    memset(dutys, duty, 8);
    uint8_t reg;
    if (port == AW9523_PORT_0) {
        reg = 0x24 + pin_num;
        i2c_write_bytes(aw9523_device, reg, dutys, nums);
    } else {
        if (pin_num < 4) {
            uint8_t need_write = 4 - pin_num;
            if (need_write > nums) {
                need_write = nums;
            }
            nums -= need_write;
            pin_num = 4;
            i2c_write_bytes(aw9523_device, 0x20 + pin_num, dutys, need_write);
        }
        if (nums) {
            i2c_write_bytes(aw9523_device, 0x20 + 0x08 + pin_num, dutys, nums);
        }
    }
}

void aw9523_softreset() {
    i2c_write_byte(aw9523_device, 0x7f, 0x00);
}

