#include <sdkconfig.h>
#ifdef CONFIG_ZX3D50CE02S_USRC_4832
#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "esp_log.h"
#include "driver/gpio.h"
#include "esp_heap_caps.h"
#include "soc/system_reg.h"
#include "screen_driver.h"
#include "driver/gpio.h"
#include "../qmsd_board_init.h"

#if CONFIG_SPIRAM
#include "spiram.h"
#endif

#define TAG "QMSD BOARD INIT"

#define LCD_H_RES         (480)
#define LCD_V_RES         (320)

#define LCD_RESET_PIN 4
#define LCD_CS_PIN -1
#define LCD_TE_PIN 48
#define LCD_WR_PIN 47
#define LCD_RS_PIN 0
#define LCD_RD_PIN -1

#define LCD_D0_PIN 9
#define LCD_D1_PIN 46
#define LCD_D2_PIN 3
#define LCD_D3_PIN 8
#define LCD_D4_PIN 18
#define LCD_D5_PIN 17
#define LCD_D6_PIN 16
#define LCD_D7_PIN 15

#define TP_SDA  6
#define TP_SCL  5
#define TP_RST  4

#define LCD_WIDTH 320
#define LCD_HIGHT 480

//backlight pwm I/O
#define LCD_BL_PIN 45

#define QMSD_DIS_BUF    (480 * 40)

void qmsd_disp_wait(uint32_t x, uint32_t y)
{
    while( gpio_get_level(LCD_TE_PIN) == 0) {
        if ((x == 480) && (y >= 80))
            break;
        taskYIELD();
    }
}

static void __qmsd_touch_init(int dir)
{
    i2c_config_t i2c_conf = {
        .mode = I2C_MODE_MASTER,
        .sda_io_num = TP_SDA,
        .sda_pullup_en = GPIO_PULLUP_ENABLE,
        .scl_io_num = TP_SCL,
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
        .direction = dir,
        .width = 320,
        .height = 480,
    };
    touch_panel_find_driver(TOUCH_PANEL_CONTROLLER_FT5X06, &g_touch);
    g_touch.init(&touch_cfg);

    lvgl_indev_init(&g_touch);
}

void qmsd_board_init(qmsd_screen_rotation_t dir)
{
    int width = 480;
    int height = 320;
	gpio_pad_select_gpio(LCD_BL_PIN);
	gpio_set_direction(LCD_BL_PIN, GPIO_MODE_OUTPUT);
	gpio_set_level(LCD_BL_PIN, 1);

    int scr_dir=0;
    int tp_dir=0;
    switch (dir)
    {
    case SCREEN_ORIGIN:
        scr_dir=SCR_DIR_LRBT;
        tp_dir=TOUCH_DIR_RLBT;
        width = 320;
        height = 480;
        break;
    case SCREEN_180:
        scr_dir=SCR_DIR_BTRL;
        tp_dir=TOUCH_DIR_TBRL;
        width = 480;
        height = 320;
        break;
    case SCREEN_90:
        scr_dir=SCR_DIR_TBLR;
        tp_dir=TOUCH_DIR_BTLR;
        width = 480;
        height = 320;
        break;
    case SCREEN_270:
        scr_dir=SCR_DIR_RLTB;
        tp_dir=TOUCH_DIR_LRTB;
        width = 320;
        height = 480;
        break;
    
    default:
        break;
    }

    i2s_lcd_config_t i2s_lcd_cfg = {
        .data_width = 8,
        .pin_data_num = {
            LCD_D0_PIN,
            LCD_D1_PIN,
            LCD_D2_PIN,
            LCD_D3_PIN,
            LCD_D4_PIN,
            LCD_D5_PIN,
            LCD_D6_PIN,
            LCD_D7_PIN,
        },
        .pin_num_cs = LCD_CS_PIN,
        .pin_num_wr = LCD_WR_PIN,                          
        .pin_num_rs = LCD_RS_PIN,
        .clk_freq = 20000000,
        .i2s_port = I2S_NUM_0,
        .buffer_size = 32000,
        .swap_data = true,
    };

    scr_interface_driver_t *iface_drv;
    scr_interface_create(SCREEN_IFACE_8080, &i2s_lcd_cfg, &iface_drv);
    extern scr_driver_t lcd_st7796_default_driver;

    g_lcd = &lcd_st7796_default_driver;

    scr_controller_config_t lcd_cfg = {
        .interface_drv = iface_drv,
        .pin_num_rst = LCD_RESET_PIN,
        .pin_num_bckl = 45,
        .rst_active_level = 0,
        .bckl_active_level = 1,
        .offset_hor = 0,
        .offset_ver = 0,
        .width = LCD_WIDTH,
        .height = LCD_HIGHT,
        .rotate = scr_dir,
    };

    g_lcd->init(&lcd_cfg);

	gpio_pad_select_gpio(LCD_TE_PIN);
	gpio_set_direction(LCD_TE_PIN, GPIO_MODE_INPUT);

    uint8_t * buf1 = NULL;
    uint8_t * buf2 = NULL;
    uint32_t qmsd_buf_size = QMSD_DIS_BUF;

#ifdef CONFIG_SPIRAM
    qmsd_buf_size = LCD_H_RES * LCD_V_RES;
    buf1 = heap_caps_aligned_calloc(64, 1, qmsd_buf_size * 2, MALLOC_CAP_SPIRAM);
    buf2 = heap_caps_aligned_calloc(64, 1, qmsd_buf_size * 2, MALLOC_CAP_SPIRAM);
#else
    if (g_dis_buf_size > 0) {
        buf1 = heap_caps_malloc(g_dis_buf_size * 2, MALLOC_CAP_DMA);
        qmsd_buf_size = g_dis_buf_size;
    } else {
        buf1 = heap_caps_malloc(QMSD_DIS_BUF * 2, MALLOC_CAP_DMA);
        qmsd_buf_size = QMSD_DIS_BUF;
    }
#endif

    if (buf1) {
        lvgl_display_init(width, height, buf1, buf2, qmsd_buf_size);
    }
    __qmsd_touch_init(tp_dir);
}

#endif
