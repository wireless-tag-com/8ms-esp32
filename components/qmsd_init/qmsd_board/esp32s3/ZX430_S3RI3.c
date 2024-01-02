#include <sdkconfig.h>
#ifdef CONFIG_ZX430_S3RI3
#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/gpio.h"
#include "esp_freertos_hooks.h"
#include "esp_log.h"
#include "esp_lcd_panel_io.h"
#include "esp_lcd_panel_vendor.h"
#include "esp_lcd_panel_ops.h"
#include "esp_lcd_panel_interface.h"
#include "qmsd_lcd_rgb_panel.h"
#include "qmsd_rgb_init.h"
#include "i2c_bus.h"
#include "gt1151.h"
#include "../qmsd_board_init.h"

#define TAG "QMSD BOARD INIT"

#define LCD_H_RES         (800)
#define LCD_V_RES         (480)

#define TP_SCL      (1)
#define TP_SDA      (2)

#define LCD_VSYNC_GPIO    (48)
#define LCD_HSYNC_GPIO    (47)
#define LCD_DE_GPIO       (45)
#define LCD_PCLK_GPIO     (21)
#define LCD_DATA0_GPIO    (3)  // B0
#define LCD_DATA1_GPIO    (4)  // B1
#define LCD_DATA2_GPIO    (5)  // B2
#define LCD_DATA3_GPIO    (6)  // B3
#define LCD_DATA4_GPIO    (7)  // B4
#define LCD_DATA5_GPIO    (8)  // G0
#define LCD_DATA6_GPIO    (9)  // G1
#define LCD_DATA7_GPIO    (10) // G2
#define LCD_DATA8_GPIO    (11) // G3
#define LCD_DATA9_GPIO    (12) // G4
#define LCD_DATA10_GPIO   (13) // G5
#define LCD_DATA11_GPIO   (14) // R0
#define LCD_DATA12_GPIO   (15) // R1
#define LCD_DATA13_GPIO   (16) // R2
#define LCD_DATA14_GPIO   (17) // R3
#define LCD_DATA15_GPIO   (18) // R4
#define LCD_DISP_EN_GPIO  (39)

#define LCD_PIXEL_CLOCK_HZ (10 * 1000 * 1000)
#define LCD_BK_LIGHT_ON_LEVEL  1
#define LCD_BK_LIGHT_OFF_LEVEL !LCD_BK_LIGHT_ON_LEVEL
#define LCD_PIN_DATA0          47  /*!< for 1-line SPI, this also refered as MOSI */
#define LCD_PIN_PCLK           48
#define LCD_PIN_CS             41
#define LCD_PIN_DC             -1
#define LCD_PIN_RST            4
#define LCD_PIN_BK_LIGHT       39

#define LCD_BK_LIGHT_ON_LEVEL  1
#define LCD_BK_LIGHT_OFF_LEVEL !LCD_BK_LIGHT_ON_LEVEL

IRAM_ATTR bool touchpad_gt1151_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
{
    uint8_t tp_num = 0;
    uint16_t x = 0, y = 0;

    tp_num = gt1151_pos_read(&x, &y);

    /* FT series touch IC might return 0xff before first touch. */
    if ((0 == tp_num) || (5 < tp_num)) {
        data->state = LV_INDEV_STATE_REL;
        return false;
    } else {
        data->point.x = x;
        data->point.y = y;
        data->state = LV_INDEV_STATE_PR;
        return true;
    }
}

/* Input device interface，Initialize your touchpad */
static esp_err_t qmsd_indev_init(void)
{
    lv_indev_drv_t indev_drv;               /*Descriptor of an input device driver*/
    lv_indev_drv_init(&indev_drv);          /*Basic initialization*/

    gt1151_i2c_init(I2C_NUM_0, 400000, TP_SCL, TP_SDA);
    gt1151_init(LCD_H_RES, LCD_V_RES);

    indev_drv.type = LV_INDEV_TYPE_POINTER; /*The touchpad is pointer type device*/
    indev_drv.read_cb = touchpad_gt1151_read;            /*Library ready your touchpad via this function*/

    lv_indev_drv_register(&indev_drv);      /*Finally register the driver*/
    return ESP_OK;
}

void qmsd_board_init(qmsd_screen_rotation_t dir)
{
    gpio_config_t bk_gpio_config = {
        .mode = GPIO_MODE_OUTPUT,
        .pin_bit_mask = 1ULL << LCD_PIN_BK_LIGHT
    };
    // Initialize the GPIO of backlight
    ESP_ERROR_CHECK(gpio_config(&bk_gpio_config));

    ESP_ERROR_CHECK(gpio_set_level(LCD_PIN_BK_LIGHT, LCD_BK_LIGHT_OFF_LEVEL));

    qmsd_lcd_rgb_panel_config_t panel_config = {
        .data_width = 16,
        .pclk_gpio_num = LCD_PCLK_GPIO,
        .vsync_gpio_num = LCD_VSYNC_GPIO,
        .hsync_gpio_num = LCD_HSYNC_GPIO,
        .de_gpio_num = LCD_DE_GPIO,
        .disp_gpio_num = LCD_DISP_EN_GPIO,
        .data_gpio_nums = {
            LCD_DATA0_GPIO,
            LCD_DATA1_GPIO,
            LCD_DATA2_GPIO,
            LCD_DATA3_GPIO,
            LCD_DATA4_GPIO,
            LCD_DATA5_GPIO,
            LCD_DATA6_GPIO,
            LCD_DATA7_GPIO,
            LCD_DATA8_GPIO,
            LCD_DATA9_GPIO,
            LCD_DATA10_GPIO,
            LCD_DATA11_GPIO,
            LCD_DATA12_GPIO,
            LCD_DATA13_GPIO,
            LCD_DATA14_GPIO,
            LCD_DATA15_GPIO,
        },
        .timings = {
            .pclk_hz = 11000000,
            .h_res = LCD_H_RES,
            .v_res = LCD_V_RES,
            .hsync_pulse_width = 40,
            .hsync_back_porch = 20,
            .hsync_front_porch = 10,
            .vsync_pulse_width = 20,
            .vsync_back_porch = 10,
            .vsync_front_porch = 10,
            .flags.pclk_active_neg = 1,
        },
        .flags.fb_in_psram = 1,
        .flags.relax_on_idle = 0,
        .flags.double_buffer = 1,
        .clk_src = LCD_CLK_SRC_PLL240M,
    };

    qmsd_indev_init();
    qmsd_rgb_init(&panel_config);

    ESP_ERROR_CHECK(gpio_set_level(LCD_PIN_BK_LIGHT, LCD_BK_LIGHT_ON_LEVEL));
}
#endif