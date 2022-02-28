#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "sdkconfig.h"
#include "qmsd_gui_init.h"
#include "esp_log.h"
#include "lvgl_helpers.h"
#include "sdkconfig.h"
#include "qm_screen_config.h"
#include "esp_freertos_hooks.h"
#include "esp_system.h"
#include "driver/gpio.h"
#include "esp_task_wdt.h"
#include "screen_driver.h"
#include "qmsd_tft/interface_driver/scr_interface_driver.h"
#include "qmsd_ctrl.h"
#include "qmsd_gui.h"
#include "touch_driver.h"

#define TAG "QMSD BOARD INIT"
#define PIXEL_TO_SIZE(v) ((v) * sizeof(lv_color_t))

static scr_driver_t g_lcd;

scr_driver_t* qmsd_board_init(int buf_size)
{
    esp_err_t ret = ESP_OK;
#if defined CONFIG_WT_SC_8080
#if (defined CONFIG_WT154_S2MI1) || defined (CONFIG_LCD01TG_A_SP)
        gpio_reset_pin(CONFIG_LCD_RD);
        gpio_set_direction(CONFIG_LCD_RD, GPIO_MODE_OUTPUT);
        gpio_set_level(CONFIG_LCD_RD, 1);
#endif
i2s_lcd_config_t i2s_lcd_cfg = {
        .data_width = 8,
        .pin_data_num = {
            CONFIG_LCD_D0,
            CONFIG_LCD_D1,
            CONFIG_LCD_D2,
            CONFIG_LCD_D3,
            CONFIG_LCD_D4,
            CONFIG_LCD_D5,
            CONFIG_LCD_D6,
            CONFIG_LCD_D7,
            // 1, 2, 3, 4, 5, 6, 7, 8,
        },
        .pin_num_cs = CONFIG_LCD_CS,
        .pin_num_wr = CONFIG_LCD_WR_SCK,
        .pin_num_rs = CONFIG_LCD_RS_DC,
        .clk_freq = 20000000,
        .i2s_port = I2S_NUM_0,
#if ((defined CONFIG_WT_86_32_3ZW0)||(defined CONFIG_WT_86_32_3ZW1)) && (!defined CONFIG_QMSD_PERFORMANCE_MODE)
        .buffer_size = 16000,
#else
        .buffer_size = 32000,
#endif
        .swap_data = 1,
    };
    scr_interface_driver_t *iface_drv;
    scr_interface_create(SCREEN_IFACE_8080, &i2s_lcd_cfg, &iface_drv);
    ret = scr_find_driver(LCD_DRIVER, &g_lcd);
    if (ESP_OK != ret)
    {
        ESP_LOGE(TAG, "screen find failed");
        return NULL;
    }
    scr_controller_config_t lcd_cfg = {
        .interface_drv = iface_drv,
        .pin_num_rst = CONFIG_LCD_RST,
        .pin_num_bckl = CONFIG_LCD_BL,
        .rst_active_level = 0,
        .bckl_active_level = 1,
        .offset_hor = 0,
        .offset_ver = 0,
        .width = CONFIG_SCREEN_INIT_HOR,
        .height = CONFIG_SCREEN_INIT_VER,
        .rotate = SCR_DIR, 
    };
    ret = g_lcd.init(&lcd_cfg);
    if (ESP_OK != ret)
    {
        ESP_LOGE(TAG, "screen initialize failed");
        return NULL;
    }
#elif defined CONFIG_WT_SC_SPI
    spi_config_t bus_conf = {
        .mosi_io_num = CONFIG_LV_DISP_SPI_MOSI,
        .sclk_io_num = CONFIG_LV_DISP_SPI_CLK,
        .max_transfer_sz=buf_size>0?PIXEL_TO_SIZE(buf_size):PIXEL_TO_SIZE(DISP_BUF_SIZE),
    };
    void *s_spi2_bus_handle = spi_bus_create(SPI2_HOST, &bus_conf);
    scr_interface_spi_config_t spi_lcd_cfg = {
        .spi_bus = s_spi2_bus_handle,
        .pin_num_cs = CONFIG_LV_DISP_SPI_CS,
        .pin_num_dc = CONFIG_LV_DISP_PIN_DC,
        .clk_freq = 26000000,
        .swap_data = false,
    };
    scr_interface_driver_t *iface_drv;
    scr_interface_create(SCREEN_IFACE_SPI, &spi_lcd_cfg, &iface_drv);
    ret = scr_find_driver(LCD_DRIVER, &g_lcd);
    if (ESP_OK != ret) {
        ESP_LOGE(TAG, "screen find failed");
        return NULL;
    }
    scr_controller_config_t lcd_cfg = {
        .interface_drv = iface_drv,
        .pin_num_rst = CONFIG_LV_DISP_PIN_RST,
        .pin_num_bckl = CONFIG_LV_DISP_PIN_BCKL,
        .rst_active_level = 0,
        .bckl_active_level = 1,
        .offset_hor = 0,
        .offset_ver = 0,
        .width = CONFIG_SCREEN_INIT_HOR,
        .height = CONFIG_SCREEN_INIT_VER,
        .rotate = SCR_DIR ,
    };
    ret = g_lcd.init(&lcd_cfg);
    if (ret!=ESP_OK)
    {
        return NULL;
    }
    
#endif

    return &g_lcd;
}