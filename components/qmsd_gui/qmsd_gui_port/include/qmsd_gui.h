#pragma once

#include "stdint.h"

#define QMSD_GUI_MAX_BUFFER_NUM 3

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*draw_bitmap_fun)(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t *bitmap, void* lvgl_drv);
typedef void (*touch_read_fun)(uint8_t press, uint16_t x, uint16_t y);

typedef struct {
    uint32_t double_fb: 1;
    uint32_t fb_in_psram: 1;
    uint32_t full_refresh: 1;
    uint32_t direct_mode: 1;
    uint32_t antialiasing: 1;
} qmsd_gui_flags_t;

typedef struct  {  
    uint16_t width;
    uint16_t hight;
    uint8_t* buffer[QMSD_GUI_MAX_BUFFER_NUM];
    uint8_t buffer_nums;
    uint32_t buffer_size;

    struct {
        uint8_t en: 1;
        uint8_t priority: 7;
        int8_t core;
    } refresh_task;

    struct {
        uint8_t en: 1;
        uint8_t priority: 7;
        int8_t core;
    } update_task;

    struct {
        uint32_t full_refresh: 1;
        uint32_t direct_mode: 1;
        uint32_t antialiasing: 1;
    } flags;

    void (*draw_bitmap) (uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t *bitmap);
    void (*touch_read)(uint8_t* press, uint16_t* x, uint16_t* y);
} qmsd_gui_config_t;

void qmsd_gui_init(qmsd_gui_config_t* lvgl_config);

void qmsd_gui_loop();

int qmsd_gui_lock(uint32_t ticks);

void qmsd_gui_unlock();

#ifdef __cplusplus
}
#endif
