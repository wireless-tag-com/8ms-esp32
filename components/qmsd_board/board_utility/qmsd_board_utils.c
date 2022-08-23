#include "driver/ledc.h"
#include "qmsd_board_utils.h"

static int16_t g_active_level = -1;

void qmsd_board_backlight_init(int16_t blk_pin, uint8_t active_level, uint32_t pwm_freq) {
    if (blk_pin < 0) {
        return ;
    }
    g_active_level = active_level;
    // Prepare and then apply the LEDC PWM timer configuration
    ledc_timer_config_t ledc_timer = {
        .speed_mode       = BACKLIGHT_LEDC_MODE,
        .timer_num        = BACKLIGHT_LEDC_TIMER,
        .duty_resolution  = BACKLIGHT_LEDC_DUTY_RES,
        .freq_hz          = pwm_freq,
        .clk_cfg          = LEDC_AUTO_CLK
    };
    ESP_ERROR_CHECK(ledc_timer_config(&ledc_timer));

    // Prepare and then apply the LEDC PWM channel configuration
    ledc_channel_config_t ledc_channel = {
        .speed_mode     = BACKLIGHT_LEDC_MODE,
        .channel        = BACKLIGHT_LEDC_CHANNEL,
        .timer_sel      = BACKLIGHT_LEDC_TIMER,
        .intr_type      = LEDC_INTR_DISABLE,
        .gpio_num       = blk_pin,
        .duty           = (g_active_level == 0) ? 100 : 0, // Set duty to 0%
        .hpoint         = 0
    };
    ESP_ERROR_CHECK(ledc_channel_config(&ledc_channel));
}

void qmsd_board_backlight_set(float light) {
    if (g_active_level < 0) {
        return ;
    }

    if (light > 100) {
        light = 100;
    }
    if (g_active_level == 0) {
        light = 100 - light;
    }
    uint16_t duty = 1024.0 / 100.0 * light;
    ledc_set_duty(BACKLIGHT_LEDC_MODE, BACKLIGHT_LEDC_CHANNEL, duty);
    ledc_update_duty(BACKLIGHT_LEDC_MODE, BACKLIGHT_LEDC_CHANNEL);
}
