#include <sdkconfig.h>
#ifdef CONFIG_ZX7D00CE01S_UR_8048
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

#define LCD_VSYNC_GPIO    (48)
#define LCD_HSYNC_GPIO    (47)
#define LCD_DE_GPIO       (38)
#define LCD_PCLK_GPIO     (15)
#define LCD_DATA0_GPIO    (11)  // B0
#define LCD_DATA1_GPIO    (12)  // B1
#define LCD_DATA2_GPIO    (13)  // B2
#define LCD_DATA3_GPIO    (14)  // B3
#define LCD_DATA4_GPIO    (21)  // B4
#define LCD_DATA5_GPIO    (46)  // G0
#define LCD_DATA6_GPIO    (19) // G1
#define LCD_DATA7_GPIO    (20) // G2
#define LCD_DATA8_GPIO    (9) // G3
#define LCD_DATA9_GPIO    (39) // G4
#define LCD_DATA10_GPIO   (10) // G5
#define LCD_DATA11_GPIO   (16) // R0
#define LCD_DATA12_GPIO   (17) // R1
#define LCD_DATA13_GPIO   (18) // R2
#define LCD_DATA14_GPIO   (8) // R3
#define LCD_DATA15_GPIO   (3) // R4
#define LCD_DISP_EN_GPIO  (-1)

#define LCD_PIN_RST            40
#define LCD_PIN_BK_LIGHT       45
#define LCD_PIN_EN       4

#define TOUCH_IIC_SCL   5
#define TOUCH_IIC_SDA   6
#define TOUCH_INT   7

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
    gt911_init(TOUCH_IIC_SDA, TOUCH_IIC_SCL, TOUCH_INT,0x5D);
    lv_indev_drv_t indev_drv;               /*Descriptor of an input device driver*/
    lv_indev_drv_init(&indev_drv);          /*Basic initialization*/

    indev_drv.type = LV_INDEV_TYPE_POINTER; /*The touchpad is pointer type device*/
    indev_drv.read_cb = touchpad_gt911_read;            /*Library ready your touchpad via this function*/

    lv_indev_drv_register(&indev_drv);      /*Finally register the driver*/
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

    gpio_config_t rst_gpio_config = {
        .mode = GPIO_MODE_OUTPUT,
        .pin_bit_mask = 1ULL << LCD_PIN_RST
    };
    // Initialize the GPIO of rst
    ESP_ERROR_CHECK(gpio_config(&rst_gpio_config));

    gpio_config_t int_gpio_config = {
        .mode = GPIO_MODE_OUTPUT,
        .pin_bit_mask = 1ULL << TOUCH_INT
    };
    // Initialize the GPIO of rst
    ESP_ERROR_CHECK(gpio_config(&int_gpio_config));
    ESP_ERROR_CHECK(gpio_set_level(TOUCH_INT, 0));

	ESP_ERROR_CHECK(gpio_set_level(LCD_PIN_RST, 1));
	vTaskDelay(pdMS_TO_TICKS(100));
    ESP_ERROR_CHECK(gpio_set_level(LCD_PIN_RST, 0));
    vTaskDelay(pdMS_TO_TICKS(100));
    ESP_ERROR_CHECK(gpio_set_level(LCD_PIN_RST, 1));
    vTaskDelay(pdMS_TO_TICKS(100));

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

	vTaskDelay(pdMS_TO_TICKS(20));
    gpio_config_t en_gpio_config = {
        .mode = GPIO_MODE_OUTPUT,
        .pin_bit_mask = 1ULL << LCD_PIN_EN
    };
    // Initialize the GPIO of backlight
    ESP_ERROR_CHECK(gpio_config(&en_gpio_config));

    ESP_ERROR_CHECK(gpio_set_level(LCD_PIN_EN, 1));
	__qmsd_touch_init();

    ESP_ERROR_CHECK(gpio_set_level(LCD_PIN_BK_LIGHT, LCD_BK_LIGHT_ON_LEVEL));
}
#endif