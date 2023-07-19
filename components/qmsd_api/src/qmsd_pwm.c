#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/ledc.h"
#include "esp_log.h"
#include "soc/soc_caps.h"

#include "qmsd_api.h"

#define LEDC_DUTY_RES           LEDC_TIMER_13_BIT // Set duty resolution to 13 bits
#if SOC_LEDC_SUPPORT_HS_MODE
#define LEDC_MODE               LEDC_HIGH_SPEED_MODE
#else
#define LEDC_MODE               LEDC_LOW_SPEED_MODE
#endif

int qmsd_pwm_start(int timer_num, int channel, int gpio, uint32_t freq_hz, uint32_t duty)
{
    // Prepare and then apply the LEDC PWM timer configuration
    ledc_timer_config_t ledc_timer = {
        .speed_mode       = LEDC_MODE,
        .timer_num        = timer_num,
        .duty_resolution  = LEDC_DUTY_RES,
        .freq_hz          = freq_hz,  // Set output frequency at 5 kHz
        .clk_cfg          = LEDC_AUTO_CLK
    };
    ledc_timer_config(&ledc_timer);

    // Prepare and then apply the LEDC PWM channel configuration
    ledc_channel_config_t ledc_channel = {
        .speed_mode     = LEDC_MODE,
        .channel        = channel,
        .timer_sel      = timer_num,
        .intr_type      = LEDC_INTR_DISABLE,
        .gpio_num       = gpio,
        .duty           = 0, // Set duty to 0%
        .hpoint         = 0
    };
    ledc_channel_config(&ledc_channel);

    return qmsd_pwm_set_duty(channel, duty);
}

int qmsd_pwm_stop(int channel, uint32_t idle_level)
{
    return ledc_stop(LEDC_MODE, channel, idle_level);
}

int qmsd_pwm_set_freq(int timer_num, uint32_t freq_hz)
{
    return ledc_set_freq(LEDC_MODE, timer_num, freq_hz);
}

int qmsd_pwm_set_duty(int channel, uint32_t duty)
{
    uint32_t s_duty = ((1<<13) - 1) * duty / 100;

    ledc_set_duty(LEDC_MODE, channel, s_duty);
    return ledc_update_duty(LEDC_MODE, channel);
}