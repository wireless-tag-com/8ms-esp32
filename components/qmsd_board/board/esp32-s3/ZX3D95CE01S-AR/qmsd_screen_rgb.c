#include "esp_lcd_panel_ops.h"
#include "esp_lcd_panel_interface.h"

#include "qmsd_lcd_panel_rgb.h"
#include "qmsd_board.h"

#include "screen_driver.h"

esp_lcd_panel_handle_t g_rgb_panel_handle = NULL;

static esp_err_t qmsd_screen_init(const scr_controller_config_t *lcd_conf);
static esp_err_t qmsd_screen_drawbitmap(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t *bitmap);
static esp_err_t qmsd_screen_draw_pixel(uint16_t x, uint16_t y, uint16_t color);

scr_driver_t qmsd_lcd_default_driver = {
    .init = qmsd_screen_init,
    .deinit = NULL,
    .set_direction = NULL,
    .set_window = NULL,
    .write_ram_data = NULL,
    .draw_pixel = qmsd_screen_draw_pixel,
    .draw_bitmap = qmsd_screen_drawbitmap,
    .get_info = NULL,
};

static esp_err_t qmsd_screen_init(const scr_controller_config_t *lcd_conf) {
    (void)lcd_conf;
    qmsd_lcd_rgb_panel_config_t panel_config = {
        .data_width = 16,
        .disp_gpio_num = LCD_DISP_EN_GPIO,
        .pclk_gpio_num = LCD_PCLK_GPIO,
        .vsync_gpio_num = LCD_VSYNC_GPIO,
        .hsync_gpio_num = LCD_HSYNC_GPIO,
        .de_gpio_num = LCD_DE_GPIO,
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
        .bounce_buffer_size_px = QMSD_RGB_CLK_FREQ > 15000000 ? QMSD_SCREEN_WIDTH * 16 : 0,
        .clk_src = USER_RGB_CLK_SRC_PLL240M,
        .timings = {
            .pclk_hz = QMSD_RGB_CLK_FREQ,
            .h_res = QMSD_SCREEN_WIDTH,
            .v_res = QMSD_SCREEN_HIGHT,
            .hsync_pulse_width = QMSD_RGB_HSYNC_PULSE_WIDTH,
            .hsync_back_porch = QMSD_RGB_HSYNC_BACK_PORCH,
            .hsync_front_porch = QMSD_RGB_HSYNC_FRONT_PORCH,
            .vsync_pulse_width = QMSD_RGB_VSYNC_PULSE_WIDTH,
            .vsync_back_porch = QMSD_RGB_VSYNC_BACK_PORCH,
            .vsync_front_porch = QMSD_RGB_VSYNC_FRONT_PORCH,
        },

        .flags = {
            .fb_in_psram = 1,
            .double_fb = 1,
            .avoid_te = 1,
        },
    };

    extern void qmsd_rgb_spi_init();
    qmsd_rgb_spi_init();
    
    qmsd_lcd_new_rgb_panel(&panel_config, &g_rgb_panel_handle);
    g_rgb_panel_handle->reset(g_rgb_panel_handle);
    return g_rgb_panel_handle->init(g_rgb_panel_handle);
}

static esp_err_t qmsd_screen_draw_pixel(uint16_t x, uint16_t y, uint16_t color) {
    return g_rgb_panel_handle->draw_bitmap(g_rgb_panel_handle, x, y, x + 1, y + 1, &color);
}

static esp_err_t qmsd_screen_drawbitmap(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t *bitmap) {
    g_rgb_panel_handle->draw_bitmap(g_rgb_panel_handle, x, y, x + w, y + h, (void *)bitmap);
    vTaskDelay(pdMS_TO_TICKS(2));
    return ESP_OK;
}
