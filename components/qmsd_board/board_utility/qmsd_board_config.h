#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#ifndef CONFIG_QMSD_BOARD_TOUCH_EN
#define CONFIG_QMSD_BOARD_TOUCH_EN 0
#define CONFIG_QMSD_TOUCH_I2C_FREQ 400000
#endif

#ifndef CONFIG_QMSD_TOUCH_THREAD_EN
#define CONFIG_QMSD_TOUCH_THREAD_EN 0
#define CONFIG_QMSD_TOUCH_THREAD_PRIORITY 5
#define CONFIG_QMSD_TOUCH_THREAD_CORE 0
#endif

#ifndef CONFIG_QMSD_BOARD_GUI_EN
#define CONFIG_QMSD_BOARD_GUI_EN 0
#define CONFIG_QMSD_GUI_DOUBLE_BUFFER 0
#define CONFIG_QMSD_GUI_BUFFER_IN_PSRAM 0
#define CONFIG_QMSD_GUI_BUFFER_SIZE 0
#endif

#ifndef CONFIG_QMSD_GUI_REFRESH_THREAD_EN
#define CONFIG_QMSD_GUI_REFRESH_THREAD_EN 0
#define CONFIG_QMSD_GUI_REFRESH_THREAD_PRIORITY 5
#define CONFIG_QMSD_GUI_REFRESH_THREAD_CORE 0
#endif

#ifndef CONFIG_QMSD_GUI_UPDATE_THREAD_EN
#define CONFIG_QMSD_GUI_UPDATE_THREAD_PRIORITY 5
#define CONFIG_QMSD_GUI_UPDATE_THREAD_CORE 0
#endif

#ifdef CONFIG_QMSD_SCREEN_ROTATION_0
#define QMSD_BOARD_ROTATION BOARD_ROTATION_0
#elif CONFIG_QMSD_SCREEN_ROTATION_90
#define QMSD_BOARD_ROTATION BOARD_ROTATION_90
#elif CONFIG_QMSD_SCREEN_ROTATION_180
#define QMSD_BOARD_ROTATION BOARD_ROTATION_180
#elif CONFIG_QMSD_SCREEN_ROTATION_270
#define QMSD_BOARD_ROTATION BOARD_ROTATION_270
#endif

#define QMSD_BOARD_DEFAULT_CONFIG { \
    .board_dir = QMSD_BOARD_ROTATION, \
    .gui = { \
        .en = CONFIG_QMSD_BOARD_GUI_EN, \
        .buffer_size = CONFIG_QMSD_GUI_BUFFER_SIZE, \
        .update_task = { \
            .en = CONFIG_QMSD_GUI_UPDATE_THREAD_EN, \
            .priority = CONFIG_QMSD_GUI_UPDATE_THREAD_PRIORITY, \
            .core = CONFIG_QMSD_GUI_UPDATE_THREAD_CORE, \
        }, \
        .refresh_task = { \
            .en = CONFIG_QMSD_GUI_REFRESH_THREAD_EN, \
            .priority = CONFIG_QMSD_GUI_REFRESH_THREAD_PRIORITY, \
            .core = CONFIG_QMSD_GUI_REFRESH_THREAD_CORE, \
        }, \
        .flags = { \
            .double_fb = CONFIG_QMSD_GUI_DOUBLE_BUFFER, \
            .fb_in_psram = CONFIG_QMSD_GUI_BUFFER_IN_PSRAM, \
            .full_refresh = 0, \
            .direct_mode = 0, \
            .antialiasing = 0, \
        } \
    }, \
    .touch = { \
        .en = CONFIG_QMSD_BOARD_TOUCH_EN, \
        .i2c_freq = CONFIG_QMSD_TOUCH_I2C_FREQ, \
        .update_task = { \
            .en = CONFIG_QMSD_TOUCH_THREAD_EN, \
            .priority = CONFIG_QMSD_TOUCH_THREAD_PRIORITY, \
            .core = CONFIG_QMSD_TOUCH_THREAD_CORE, \
        } \
    }, \
}

#ifdef __cplusplus
}
#endif
