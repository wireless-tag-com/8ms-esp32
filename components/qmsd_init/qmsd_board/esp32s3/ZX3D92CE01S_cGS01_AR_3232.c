#include "sdkconfig.h"
#ifdef CONFIG_ZX3D92CE01S_cGS01_AR_3232
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
#include "touch.h"
#include "../qmsd_board_init.h"

#define TAG "QMSD BOARD INIT"
#define PIXEL_TO_SIZE(v) ((v) * sizeof(lv_color_t))

#define QMSD_DIS_BUF    (320 * 320)

extern esp_err_t lcd_st7796_set_invert(bool is_invert);

static int g_tp_roll=0;

void qmsd_disp_wait(uint32_t x, uint32_t y)
{
}

bool touchpad_gslx680_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data)
{
    uint16_t tp_x,tp_y;
    uint8_t press;
    touch_read_status(&tp_x,&tp_y,&press);
    data->state = press;
        switch (g_tp_roll)
        {
        case SCREEN_ORIGIN:
            data->point.x = tp_x;
            data->point.y = tp_y;
            break;
        case SCREEN_180:
            data->point.x = 320 - tp_x;
            data->point.y = 320 - tp_y;
            break;
        case SCREEN_90:
            data->point.x = tp_y;
            data->point.y = 320 - tp_x;
            break;
        case SCREEN_270:
            data->point.x = 320 - tp_y;
            data->point.y = tp_x;
            break;

        default:
            break;
        }
    return false;
}

void qmsd_board_init(qmsd_screen_rotation_t dir)
{
    ESP_LOGI(TAG,"Init board:%s","WT-86-32-3ZW1");
    esp_err_t ret = ESP_OK;
    int scr_dir=0;

    switch (dir)
    {
    case SCREEN_ORIGIN:
        scr_dir=SCR_DIR_RLTB;
        break;
    case SCREEN_180:
        scr_dir=SCR_DIR_LRBT;
        break;
    case SCREEN_90:
        scr_dir=SCR_DIR_TBLR;
        break;
    case SCREEN_270:
        scr_dir=SCR_DIR_BTRL;
        break;
    
    default:
        break;
    }
    g_tp_roll=dir;
    i2s_lcd_config_t i2s_lcd_cfg = {
        .data_width = 8,
        .pin_data_num = {
            36,
            35,
            34,
            33,
            21,
            18,
            17,
            16,
            // 1, 2, 3, 4, 5, 6, 7, 8,
        },
        .pin_num_cs = -1,
        .pin_num_wr = 39,
        .pin_num_rs = 38,
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
        .pin_num_rst = 37,
        .pin_num_bckl = 0,
        .rst_active_level = 0,
        .bckl_active_level = 1,
        .offset_hor = 0,
        .offset_ver = 0,
        .width = 320,
        .height = 320,
        .rotate = scr_dir, 
    };
    ret = g_lcd->init(&lcd_cfg);
    lcd_st7796_set_invert(true);
    if (ESP_OK != ret)
    {
        ESP_LOGE(TAG, "screen initialize failed");
        return;
    }

    uint8_t * buf1 = NULL;
	uint8_t * buf2 = NULL;
    uint32_t qmsd_buf_size = QMSD_DIS_BUF;

    if (g_dis_buf_size > 0) {
        buf1 = heap_caps_malloc(g_dis_buf_size * 2, MALLOC_CAP_SPIRAM);
		buf2 = heap_caps_malloc(g_dis_buf_size * 2, MALLOC_CAP_SPIRAM);
        qmsd_buf_size = g_dis_buf_size;
    } else {
        buf1 = heap_caps_malloc(QMSD_DIS_BUF * 2, MALLOC_CAP_SPIRAM);
		buf2 = heap_caps_malloc(g_dis_buf_size * 2, MALLOC_CAP_SPIRAM);
        qmsd_buf_size = QMSD_DIS_BUF;
    }

    if (buf1 && buf2) {
        lvgl_display_init(320, 320, buf1, buf2, qmsd_buf_size);
    } else {
		ESP_LOGE(TAG, "lvgl buf malloc failed");	
	}

    touch_init(15,14,13,12);
    lv_indev_drv_t indev_drv;               /*Descriptor of an input device driver*/
    lv_indev_drv_init(&indev_drv);          /*Basic initialization*/

    indev_drv.type = LV_INDEV_TYPE_POINTER; /*The touchpad is pointer type device*/
    indev_drv.read_cb = touchpad_gslx680_read;            /*Library ready your touchpad via this function*/

    lv_indev_drv_register(&indev_drv);      /*Finally register the driver*/
}
#endif