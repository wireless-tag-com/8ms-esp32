#include "sdkconfig.h"
#ifdef CONFIG_WT32_SC01
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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

#define QMSD_DIS_BUF    (480 * 40)

extern esp_err_t lcd_st7796_set_invert(bool is_invert);

void qmsd_board_init(qmsd_screen_rotation_t dir)
{
    esp_err_t ret = ESP_OK;
    int scr_dir=0;
    int tp_dir=0;
    switch (dir)
    {
    case SCREEN_ORIGIN:
        scr_dir=SCR_DIR_TBLR;
        tp_dir=TOUCH_DIR_BTLR;
        break;
    case SCREEN_180:
        scr_dir=SCR_DIR_BTRL;
        tp_dir=TOUCH_DIR_TBRL;
        break;
    case SCREEN_90:
        scr_dir=SCR_DIR_LRBT;
        tp_dir=TOUCH_DIR_RLBT;
        break;
    case SCREEN_270:
        scr_dir=SCR_DIR_RLTB;
        tp_dir=TOUCH_DIR_LRTB;
        break;
    
    default:
        break;
    }

    uint8_t * buf1 = NULL;
    uint32_t qmsd_buf_size = QMSD_DIS_BUF;
    if (g_dis_buf_size > 0) {
        buf1 = heap_caps_malloc(PIXEL_TO_SIZE(g_dis_buf_size), MALLOC_CAP_DMA);
        qmsd_buf_size = g_dis_buf_size;
    } else {
        buf1 = heap_caps_malloc(PIXEL_TO_SIZE(QMSD_DIS_BUF), MALLOC_CAP_DMA);
        qmsd_buf_size = QMSD_DIS_BUF;
    }

    spi_config_t bus_conf = {
        .miso_io_num = -1,
        .mosi_io_num = 13,
        .sclk_io_num = 14,
        .max_transfer_sz = g_dis_buf_size>0?PIXEL_TO_SIZE(g_dis_buf_size):PIXEL_TO_SIZE(qmsd_buf_size),
    };
    void *s_spi2_bus_handle = spi_bus_create(SPI2_HOST, &bus_conf);
    scr_interface_spi_config_t spi_lcd_cfg = {
        .spi_bus = s_spi2_bus_handle,
        .pin_num_cs = 15,
        .pin_num_dc = 21,
        .clk_freq = 26000000,
        .swap_data = true,
    };
    scr_interface_driver_t *iface_drv;
    scr_interface_create(SCREEN_IFACE_SPI, &spi_lcd_cfg, &iface_drv);
    extern scr_driver_t lcd_st7796_default_driver;

    g_lcd = &lcd_st7796_default_driver;

    scr_controller_config_t lcd_cfg = {
        .interface_drv = iface_drv,
        .pin_num_rst = 22,
        .pin_num_bckl = 23,
        .rst_active_level = 0,
        .bckl_active_level = 1,
        .offset_hor = 0,
        .offset_ver = 0,
        .width = 320,
        .height = 480,
        .rotate =  scr_dir,
    };
    ret = g_lcd->init(&lcd_cfg);
    if (ret!=ESP_OK)
    {
        return;
    }
    
    lcd_st7796_set_invert(false);

    if (buf1) {
        lvgl_display_init(dir < 2 ? 480:320,dir < 2 ? 320:480, buf1, NULL, qmsd_buf_size);
    }

    i2c_config_t i2c_conf = {
        .mode = I2C_MODE_MASTER,
        .sda_io_num = 18,
        .sda_pullup_en = GPIO_PULLUP_ENABLE,
        .scl_io_num = 19,
        .scl_pullup_en = GPIO_PULLUP_ENABLE,
        .master.clk_speed = 100000,
    };
    i2c_bus_handle_t i2c_bus = i2c_bus_create(I2C_NUM_0, &i2c_conf);

    touch_panel_config_t touch_cfg = {
        .interface_i2c = {
            .i2c_bus = i2c_bus,
            .clk_freq = 100000,
            .i2c_addr = 0x38,
        },
        .interface_type = TOUCH_PANEL_IFACE_I2C,
        .pin_num_int = -1,
        .direction = tp_dir,
        .width = 320,
        .height = 480,
    };
    touch_panel_find_driver(TOUCH_PANEL_CONTROLLER_FT5X06, &g_touch);
    g_touch.init(&touch_cfg);

    lvgl_indev_init(&g_touch);
    qmsd_board_sleep_init(23,300,1);
}
#endif