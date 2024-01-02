#include <sdkconfig.h>
#ifdef CONFIG_ZX7D00CE01S_V12_8048
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
#include "../qmsd_board_init.h"
#include "gt911.h"

#define TAG "QMSD BOARD INIT"

#define LCD_VSYNC_GPIO    (38)
#define LCD_HSYNC_GPIO    (5)
#define LCD_DE_GPIO       (39)
#define LCD_PCLK_GPIO     (9)
#define LCD_D0_GPIO         (17)    // B0
#define LCD_D1_GPIO         (16)    // B1
#define LCD_D2_GPIO         (15)    // B2
#define LCD_D3_GPIO         (7)     // B3
#define LCD_D4_GPIO         (6)     // B4
#define LCD_D5_GPIO         (21)    // G0
#define LCD_D6_GPIO         (0)     // G1
#define LCD_D7_GPIO         (46)    // G2
#define LCD_D8_GPIO         (3)     // G3
#define LCD_D9_GPIO         (8)     // G4
#define LCD_D10_GPIO        (18)    // G5
#define LCD_D11_GPIO        (10)    // R0
#define LCD_D12_GPIO        (11)    // R1
#define LCD_D13_GPIO        (12)    // R2
#define LCD_D14_GPIO        (13)    // R3
#define LCD_D15_GPIO        (14)    // R4
#define LCD_DISP_EN_GPIO  (-1)

#define LCD_PIN_RST            -1
#define LCD_PIN_BK_LIGHT       45

#define TOUCH_IIC_SCL   47
#define TOUCH_IIC_SDA   48

#define LCD_BK_LIGHT_ON_LEVEL  1
#define LCD_BK_LIGHT_OFF_LEVEL !LCD_BK_LIGHT_ON_LEVEL

bool touchpad_gt911_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data)
{
    uint16_t tp_x,tp_y;
    uint8_t press;
    gt911_read_status(&tp_x,&tp_y,&press);
    data->state = press;
	data->point.x = tp_x;
	data->point.y = tp_y;
    return false;
}

static void __qmsd_touch_init(void)
{
    gt911_init(TOUCH_IIC_SDA, TOUCH_IIC_SCL, -1, 0x5D);
    lv_indev_drv_t indev_drv;               /*Descriptor of an input device driver*/
    lv_indev_drv_init(&indev_drv);          /*Basic initialization*/

    indev_drv.type = LV_INDEV_TYPE_POINTER; /*The touchpad is pointer type device*/
    indev_drv.read_cb = touchpad_gt911_read;            /*Library ready your touchpad via this function*/

    lv_indev_drv_register(&indev_drv);      /*Finally register the driver*/
}


void qmsd_board_init(qmsd_screen_rotation_t dir)
{
    printf("init ZX7D00CE01S_V12_8048\n");
    gpio_config_t bk_gpio_config = {
        .mode = GPIO_MODE_OUTPUT,
        .pin_bit_mask = 1ULL << LCD_PIN_BK_LIGHT
    };
    // Initialize the GPIO of backlight
    ESP_ERROR_CHECK(gpio_config(&bk_gpio_config));

    ESP_ERROR_CHECK(gpio_set_level(LCD_PIN_BK_LIGHT, LCD_BK_LIGHT_OFF_LEVEL));

    if (LCD_PIN_RST > -1) {
        gpio_config_t rst_gpio_config = {
            .mode = GPIO_MODE_OUTPUT,
            .pin_bit_mask = 1ULL << LCD_PIN_RST
        };
        // Initialize the GPIO of rst
        ESP_ERROR_CHECK(gpio_config(&rst_gpio_config));

        ESP_ERROR_CHECK(gpio_set_level(LCD_PIN_RST, 1));
        vTaskDelay(pdMS_TO_TICKS(100));
        ESP_ERROR_CHECK(gpio_set_level(LCD_PIN_RST, 0));
        vTaskDelay(pdMS_TO_TICKS(100));
        ESP_ERROR_CHECK(gpio_set_level(LCD_PIN_RST, 1));
        vTaskDelay(pdMS_TO_TICKS(100));
    }

    qmsd_lcd_rgb_panel_config_t panel_config = {
        .data_width = 16,
        .pclk_gpio_num = LCD_PCLK_GPIO,
        .vsync_gpio_num = LCD_VSYNC_GPIO,
        .hsync_gpio_num = LCD_HSYNC_GPIO,
        .de_gpio_num = LCD_DE_GPIO,
        .disp_gpio_num = LCD_DISP_EN_GPIO,
        .data_gpio_nums = {
            LCD_D0_GPIO,
            LCD_D1_GPIO,
            LCD_D2_GPIO,
            LCD_D3_GPIO,
            LCD_D4_GPIO,
            LCD_D5_GPIO,
            LCD_D6_GPIO,
            LCD_D7_GPIO,
            LCD_D8_GPIO,
            LCD_D9_GPIO,
            LCD_D10_GPIO,
            LCD_D11_GPIO,
            LCD_D12_GPIO,
            LCD_D13_GPIO,
            LCD_D14_GPIO,
            LCD_D15_GPIO,
        },
        .timings = {
            .pclk_hz = 24000000,
            .h_res = 800,
            .v_res = 480,
            .hsync_pulse_width = 10,
            .hsync_back_porch = 40,
            .hsync_front_porch = 40,
            .vsync_pulse_width = 6,
            .vsync_back_porch = 31,
            .vsync_front_porch = 18,
        },
        .flags.fb_in_psram = 1,
        .flags.relax_on_idle = 0,
        .flags.double_buffer = 1,
        .clk_src = LCD_CLK_SRC_PLL240M,
        .bounce_buffer_size_px = 16 * 800,
    };

    qmsd_rgb_init(&panel_config);

	__qmsd_touch_init();

    ESP_ERROR_CHECK(gpio_set_level(LCD_PIN_BK_LIGHT, LCD_BK_LIGHT_ON_LEVEL));
}
#endif