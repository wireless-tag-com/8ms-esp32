#include <sdkconfig.h>

#ifdef CONFIG_ZX4D30NE01S_UR_4827
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

#define LCD_PCLK_GPIO     (14)
#define LCD_DE_GPIO       (40)
#define LCD_VSYNC_GPIO    (48)
#define LCD_HSYNC_GPIO    (47)

#define RGB_B0 (9) 
#define RGB_B1 (10)
#define RGB_B2 (11)
#define RGB_B3 (12)
#define RGB_B4 (13)
#define RGB_B5 (-1)

#define RGB_G0 (16)
#define RGB_G1 (17)
#define RGB_G2 (18)
#define RGB_G3 (8)
#define RGB_G4 (3)
#define RGB_G5 (46)

#define RGB_R0 (4)
#define RGB_R1 (5)
#define RGB_R2 (6)
#define RGB_R3 (7)
#define RGB_R4 (15)
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
#define LCD_DISP_EN_GPIO  (-1)

#define LCD_PIN_BK_LIGHT       45

#define LCD_BK_LIGHT_ON_LEVEL  1
#define LCD_BK_LIGHT_OFF_LEVEL !LCD_BK_LIGHT_ON_LEVEL

#define TOUCH_IIC_SCL   0
#define TOUCH_IIC_SDA   45
#define TOUCH_IIC_INT   39

#if 0
static void __qmsd_touch_init(void)
{
    i2c_config_t i2c_conf = {
        .mode = I2C_MODE_MASTER,
        .sda_io_num = TOUCH_IIC_SDA,
        .sda_pullup_en = GPIO_PULLUP_ENABLE,
        .scl_io_num = TOUCH_IIC_SCL,
        .scl_pullup_en = GPIO_PULLUP_ENABLE,
        .master.clk_speed = 100000,
    };
    i2c_bus_handle_t i2c_bus = i2c_bus_create(I2C_NUM_0, &i2c_conf);

    touch_panel_config_t touch_cfg = {
        .interface_i2c = {
            .i2c_bus = i2c_bus,
            .clk_freq = 100000,
            .i2c_addr = 0x90,
        },
        .interface_type = TOUCH_PANEL_IFACE_I2C,
        .pin_num_int = -1,
        .direction = TOUCH_DIR_LRTB,
        .width = 480,
        .height = 272,
    };
    touch_panel_find_driver(CONFIG_TOUCH_DRIVER_NS2016, &g_touch);
    g_touch.init(&touch_cfg);

    lvgl_indev_init(&g_touch);
}
#endif

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
#ifdef CONFIG_SPIRAM_MODE_QUAD
        .bounce_buffer_size_px = 480 * 8,
#else
        .bounce_buffer_size_px = 0,
#endif
        .clk_src = LCD_CLK_SRC_PLL240M,
    };

    qmsd_rgb_init(&panel_config);

    ESP_ERROR_CHECK(gpio_set_level(LCD_PIN_BK_LIGHT, LCD_BK_LIGHT_ON_LEVEL));
}
#endif
