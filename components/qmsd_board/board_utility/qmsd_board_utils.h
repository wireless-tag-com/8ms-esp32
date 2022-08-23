#pragma once

#include "stdint.h"

#ifdef __cplusplus
extern "C" {
#endif

enum {
    BOARD_ROTATION_0 = 0x0,
    BOARD_ROTATION_90,
    BOARD_ROTATION_180,
    BOARD_ROTATION_270,
};

typedef struct {
    uint8_t en: 1;
    uint8_t priority: 7;
    int8_t core;
} qmsd_task_config_t;

typedef struct {
    uint8_t board_dir;

    struct {
        uint8_t en;
        uint32_t buffer_size;
        qmsd_task_config_t update_task;
        qmsd_task_config_t refresh_task;
        struct {
            uint32_t double_fb: 1;
            uint32_t fb_in_psram: 1;
            uint32_t full_refresh: 1;
            uint32_t direct_mode: 1;
            uint32_t antialiasing: 1;
        } flags;
    } gui;

    struct {
        uint8_t en;
        uint32_t i2c_freq;
        qmsd_task_config_t update_task;
    } touch;

} qmsd_board_config_t;


#define BACKLIGHT_LEDC_TIMER        LEDC_TIMER_3
#define BACKLIGHT_LEDC_MODE         LEDC_LOW_SPEED_MODE
#define BACKLIGHT_LEDC_CHANNEL      LEDC_CHANNEL_5
#define BACKLIGHT_LEDC_DUTY_RES     LEDC_TIMER_10_BIT

void qmsd_board_backlight_init(int16_t blk_pin, uint8_t active_level, uint32_t pwm_freq);

// light: 0.0 ~ 100.0
void qmsd_board_backlight_set(float light);

#ifdef __cplusplus
}
#endif