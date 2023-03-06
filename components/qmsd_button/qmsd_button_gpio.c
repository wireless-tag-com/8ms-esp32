#include "driver/gpio.h"
#include "qmsd_button.h"

uint8_t qmsd_button_gpio_read(uint8_t scan_start, uint8_t wait_press, void* hardware_data) {
    return gpio_get_level((uint32_t)hardware_data);
}

btn_handle_t qmsd_button_create_gpio(uint8_t gpio_num, uint8_t active_level, void* user_data) {
    gpio_config_t cfg = {
        .pin_bit_mask = BIT64(gpio_num),
        .mode = GPIO_MODE_INPUT,
        .pull_up_en = 0,
        .pull_down_en = 0,
        .intr_type = GPIO_INTR_DISABLE,
    };
    if (active_level == 0) {
        cfg.pull_down_en = 0;
        cfg.pull_up_en = 1;
    } else {
        cfg.pull_down_en = 1;
        cfg.pull_up_en = 0;
    }
    gpio_config(&cfg);
    return qmsd_button_create(qmsd_button_gpio_read, (void *)(uint32_t)gpio_num, active_level, user_data);
}
