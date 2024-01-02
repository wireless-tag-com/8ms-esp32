#include <sdkconfig.h>

#ifdef CONFIG_ZX430_S3RI1
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

#define TAG "QMSD BOARD INIT"

#define LCD_VSYNC_GPIO    (38)
#define LCD_HSYNC_GPIO    (45)
#define LCD_DE_GPIO       (39)
#define LCD_PCLK_GPIO     (40)
#define LCD_DATA0_GPIO    (48)  // B0
#define LCD_DATA1_GPIO    (47)  // B1
#define LCD_DATA2_GPIO    (21)  // B2
#define LCD_DATA3_GPIO    (14)  // B3
#define LCD_DATA4_GPIO    (13)  // B4
#define LCD_DATA5_GPIO    (12)  // G0
#define LCD_DATA6_GPIO    (11) // G1
#define LCD_DATA7_GPIO    (10) // G2
#define LCD_DATA8_GPIO    (9) // G3
#define LCD_DATA9_GPIO    (46) // G4
#define LCD_DATA10_GPIO   (3) // G5
#define LCD_DATA11_GPIO   (8) // R0
#define LCD_DATA12_GPIO   (18) // R1
#define LCD_DATA13_GPIO   (17) // R2
#define LCD_DATA14_GPIO   (16) // R3
#define LCD_DATA15_GPIO   (15) // R4
#define LCD_DISP_EN_GPIO  (-1)

#define LCD_PIXEL_CLOCK_HZ (10 * 1000 * 1000)
#define LCD_PIN_DATA0          47  /*!< for 1-line SPI, this also refered as MOSI */
#define LCD_PIN_PCLK           48
#define LCD_PIN_CS             41
#define LCD_PIN_DC             -1
#define LCD_PIN_RST            4
#define LCD_PIN_BK_LIGHT       1

#define LCD_BK_LIGHT_ON_LEVEL  1
#define LCD_BK_LIGHT_OFF_LEVEL !LCD_BK_LIGHT_ON_LEVEL

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

    ESP_ERROR_CHECK(gpio_set_level(LCD_PIN_RST, 0));
    vTaskDelay(pdMS_TO_TICKS(20));
    ESP_ERROR_CHECK(gpio_set_level(LCD_PIN_RST, 1));
    vTaskDelay(pdMS_TO_TICKS(20));

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
            .h_res = 480,
            .v_res = 272,
            .hsync_pulse_width = 10,
            .hsync_back_porch = 30,
            .hsync_front_porch = 20,
            .vsync_pulse_width = 10,
            .vsync_back_porch = 30,
            .vsync_front_porch = 10,
            .flags.pclk_active_neg = 1,
        },
        .flags.fb_in_psram = 1,
        .flags.relax_on_idle = 0,
        .flags.double_buffer = 1,
#ifdef CONFIG_SPIRAM_MODE_QUAD
        .bounce_buffer_size_px = 480 * 8,
#else
        .bounce_buffer_size_px = 0,
#endif
        .clk_src = LCD_CLK_SRC_PLL160M,
    };

    qmsd_rgb_init(&panel_config);

    ESP_ERROR_CHECK(gpio_set_level(LCD_PIN_BK_LIGHT, LCD_BK_LIGHT_ON_LEVEL));
}
#endif