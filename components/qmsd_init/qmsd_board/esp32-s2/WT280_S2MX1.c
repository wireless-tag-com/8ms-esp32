#include "sdkconfig.h"
#ifdef CONFIG_WT280_S2MX1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "sdkconfig.h"
#include "qmsd_gui_init.h"
#include "esp_log.h"
#include "sdkconfig.h"
#include "qmsd_screen_config.h"
#include "esp_freertos_hooks.h"
#include "esp_system.h"
#include "driver/gpio.h"
#include "esp_task_wdt.h"
#include "screen_driver.h"
#include "qmsd_ctrl.h"
#include "qmsd_gui.h"
#include "touch_panel.h"
#include "../qmsd_board_init.h"

#define TAG "QMSD BOARD INIT"
#define PIXEL_TO_SIZE(v) ((v) * sizeof(lv_color_t))

#define QMSD_DIS_BUF    (320 * 40)

extern esp_err_t lcd_st7789_set_invert(bool is_invert);

void qmsd_disp_wait(uint32_t x, uint32_t y)
{
}

void qmsd_board_init(qmsd_screen_rotation_t dir)
{
    ESP_LOGI(TAG,"Init board:%s","WT280-S2MI1");
    esp_err_t ret = ESP_OK;
    int scr_dir=0;

    switch (dir)
    {
    case SCREEN_ORIGIN:
        scr_dir=SCR_DIR_LRTB;
        break;
    case SCREEN_180:
        scr_dir=SCR_DIR_RLBT;
        break;
    case SCREEN_90:
        scr_dir=SCR_DIR_TBRL;
        break;
    case SCREEN_270:
        scr_dir=SCR_DIR_BTLR;
        break;
    
    default:
        break;
    }

    i2s_lcd_config_t i2s_lcd_cfg = {
        .data_width = 8,
        .pin_data_num = {
            35,
            36,
            37,
            34,
            33,
            21,
            14,
            13,
            // 1, 2, 3, 4, 5, 6, 7, 8,
        },
        .pin_num_cs = 10,
        .pin_num_wr = 12,
        .pin_num_rs = 11,
        .clk_freq = 20000000,
        .i2s_port = I2S_NUM_0,
        .buffer_size = 32000,
        .swap_data = true,
    };
    scr_interface_driver_t *iface_drv;
    scr_interface_create(SCREEN_IFACE_8080, &i2s_lcd_cfg, &iface_drv);
    extern scr_driver_t lcd_st7789_default_driver;

    g_lcd = &lcd_st7789_default_driver;

    scr_controller_config_t lcd_cfg = {
        .interface_drv = iface_drv,
        .pin_num_rst = 17,
        .pin_num_bckl = 16,
        .rst_active_level = 0,
        .bckl_active_level = 1,
        .offset_hor = 0,
        .offset_ver = 0,
        .width = 240,
        .height = 320,
        .rotate = scr_dir, 
    };
    ret = g_lcd->init(&lcd_cfg);
    if (ESP_OK != ret)
    {
        ESP_LOGE(TAG, "screen initialize failed");
        return NULL;
    }

    uint8_t * buf1 = NULL;
    uint32_t qmsd_buf_size = QMSD_DIS_BUF;
    if (g_dis_buf_size > 0) {
        buf1 = heap_caps_malloc(g_dis_buf_size * 2, MALLOC_CAP_DMA);
        qmsd_buf_size = g_dis_buf_size;
    } else {
        buf1 = heap_caps_malloc(QMSD_DIS_BUF * 2, MALLOC_CAP_DMA);
        qmsd_buf_size = QMSD_DIS_BUF;
    }

    if (buf1) {
        lvgl_display_init(dir < 2 ? 240:320,dir < 2 ? 320:240, buf1, NULL, qmsd_buf_size);
    }

    return &g_lcd;
}
#endif