#include "sdkconfig.h"
#ifdef CONFIG_WT154_C3SI1
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
#define QMSD_DIS_BUF    (240 * 60)

void qmsd_board_init(qmsd_screen_rotation_t dir)
{
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

    spi_config_t bus_conf = {
        .miso_io_num = -1,
        .mosi_io_num = 18,
        .sclk_io_num = 7,
        .max_transfer_sz=g_dis_buf_size>0?PIXEL_TO_SIZE(g_dis_buf_size):PIXEL_TO_SIZE(240*60),
    };
    void *s_spi2_bus_handle = spi_bus_create(SPI2_HOST, &bus_conf);
    scr_interface_spi_config_t spi_lcd_cfg = {
        .spi_bus = s_spi2_bus_handle,
        .pin_num_cs = 6,
        .pin_num_dc = 5,
        .clk_freq = 26000000,
        .swap_data = true,
    };
    scr_interface_driver_t *iface_drv;
    scr_interface_create(SCREEN_IFACE_SPI, &spi_lcd_cfg, &iface_drv);
    extern scr_driver_t lcd_st7789_default_driver;

    g_lcd = &lcd_st7789_default_driver;

    scr_controller_config_t lcd_cfg = {
        .interface_drv = iface_drv,
        .pin_num_rst = 19,
        .pin_num_bckl = 10,
        .rst_active_level = 0,
        .bckl_active_level = 1,
        .offset_hor = 0,
        .offset_ver = 0,
        .width = 240,
        .height = 240,
        .rotate =  scr_dir,
    };
    ret = g_lcd->init(&lcd_cfg);
    if (ret!=ESP_OK)
    {
        return;
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
        lvgl_display_init(240,240, buf1, NULL, qmsd_buf_size);
    }
}
#endif