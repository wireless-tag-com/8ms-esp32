#include <sdkconfig.h>

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
#include "qmsd_board_init.h"

#define TAG "QMSD BOARD INIT"

#define LCD_PCLK_GPIO     (13)
#define LCD_DE_GPIO       (48)
#define LCD_VSYNC_GPIO    (47)
#define LCD_HSYNC_GPIO    (0)

#define RGB_B0 (20) 
#define RGB_B1 (9)
#define RGB_B2 (10)
#define RGB_B3 (11)
#define RGB_B4 (12)
#define RGB_B5 (-1)

#define RGB_G0 (17)
#define RGB_G1 (18)
#define RGB_G2 (8)
#define RGB_G3 (3)
#define RGB_G4 (46)
#define RGB_G5 (19)

#define RGB_R0 (5)
#define RGB_R1 (6)
#define RGB_R2 (7)
#define RGB_R3 (15)
#define RGB_R4 (16)
#define RGB_R5 (-1)

#define LCD_DATA0_GPIO    (RGB_B0)   // B0
#define LCD_DATA1_GPIO    (RGB_B1)   // B1
#define LCD_DATA2_GPIO    (RGB_B2)   // B2
#define LCD_DATA3_GPIO    (RGB_B3)   // B3
#define LCD_DATA4_GPIO    (RGB_B4)   // B4
#define LCD_DATA5_GPIO    (RGB_G0)   // G0
#define LCD_DATA6_GPIO    (RGB_G1)    // G1
#define LCD_DATA7_GPIO    (RGB_G2)   // G2
#define LCD_DATA8_GPIO    (RGB_G3)   // G3
#define LCD_DATA9_GPIO    (RGB_G4)   // G4
#define LCD_DATA10_GPIO   (RGB_G5)   // G5
#define LCD_DATA11_GPIO   (RGB_R0)   // R0
#define LCD_DATA12_GPIO   (RGB_R1)    // R1
#define LCD_DATA13_GPIO   (RGB_R2)    // R2
#define LCD_DATA14_GPIO   (RGB_R3)    // R3
#define LCD_DATA15_GPIO   (RGB_R4)    // R4
#define LCD_DISP_EN_GPIO  (21)

#define LCD_PIN_BK_LIGHT       4

#define LCD_BK_LIGHT_ON_LEVEL  1
#define LCD_BK_LIGHT_OFF_LEVEL !LCD_BK_LIGHT_ON_LEVEL

void qmsd_board_cus_init(qmsd_screen_rotation_t dir)
{
    gpio_config_t en_gpio_config = {
        .mode = GPIO_MODE_OUTPUT,
        .pin_bit_mask = 1ULL << LCD_DISP_EN_GPIO
    };
    // Initialize the GPIO of lcd en
    ESP_ERROR_CHECK(gpio_config(&en_gpio_config));

	ESP_ERROR_CHECK(gpio_set_level(LCD_DISP_EN_GPIO, 0));

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
            .pclk_hz = 14000000,
            .h_res = 480,
            .v_res = 272,
            .hsync_pulse_width = 10,
            .hsync_back_porch = 80,
            .hsync_front_porch = 60,    // 630
            .vsync_pulse_width = 10,
            .vsync_back_porch = 20,
            .vsync_front_porch = 60,    // 362
            .flags.pclk_active_neg = 1,
        },
        .flags.fb_in_psram = 1,
        .flags.relax_on_idle = 0,
        .flags.double_buffer = 1,
        .bounce_buffer_size_px = 0,
        .clk_src = LCD_CLK_SRC_PLL240M,
    };

    qmsd_rgb_init(&panel_config);

	ESP_ERROR_CHECK(gpio_set_level(LCD_DISP_EN_GPIO, 1));

    ESP_ERROR_CHECK(gpio_set_level(LCD_PIN_BK_LIGHT, LCD_BK_LIGHT_ON_LEVEL));
}
