#ifndef __QMSD_LCD_RGB_PANEL_H
#define __QMSD_LCD_RGB_PANEL_H

#pragma once

#include "esp_lcd_panel_rgb.h"

#if SOC_LCD_RGB_SUPPORTED
#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    lcd_clock_source_t clk_src;   /*!< Clock source for the RGB LCD peripheral */
    esp_lcd_rgb_timing_t timings; /*!< RGB timing parameters */
    size_t data_width;            /*!< Number of data lines */
    int hsync_gpio_num;           /*!< GPIO used for HSYNC signal */
    int vsync_gpio_num;           /*!< GPIO used for VSYNC signal */
    int de_gpio_num;              /*!< GPIO used for DE signal, set to -1 if it's not used */
    int pclk_gpio_num;            /*!< GPIO used for PCLK signal */
    int data_gpio_nums[SOC_LCD_RGB_DATA_WIDTH]; /*!< GPIOs used for data lines */
    int disp_gpio_num; /*!< GPIO used for display control signal, set to -1 if it's not used */
    uint8_t* buf1;
    uint8_t* buf2;
    int bounce_buffer_size_px;
    struct {
        unsigned int disp_active_low: 1; /*!< If this flag is enabled, a low level of display control signal can turn the screen on; vice versa */
        unsigned int relax_on_idle: 1;   /*!< If this flag is enabled, the host won't refresh the LCD if nothing changed in host's frame buffer (this is usefull for LCD with built-in GRAM) */
        unsigned int fb_in_psram: 1;     /*!< If this flag is enabled, the frame buffer will be allocated from PSRAM preferentially */
        unsigned int double_buffer: 1;     /*!< If this flag is enabled, the frame buffer will be allocated from PSRAM preferentially */
    } flags;
} qmsd_lcd_rgb_panel_config_t;

/**
 * @brief RGB LCD VSYNC event callback prototype
 *
 * @param[in] panel LCD panel handle, returned from `esp_lcd_new_rgb_panel()`
 * @param[in] user_ctx User data, passed from `esp_lcd_rgb_panel_register_event_callbacks()`
 * @return Whether a high priority task has been waken up by this function
 */
typedef bool (*qmsd_rgb_panel_vsync_cb_t)(void);

esp_err_t qmsd_lcd_new_rgb_panel(const qmsd_lcd_rgb_panel_config_t *rgb_panel_config, esp_lcd_panel_handle_t *ret_panel);

void qmsd_lcd_rgb_panel_get_buffer(esp_lcd_panel_t *panel, uint8_t** buf1, uint8_t** buf2);

void qmsd_lcd_rgb_panel_start(esp_lcd_panel_t *panel);

void qmsd_lcd_panel_cache_flush(esp_lcd_panel_t *panel);

void qmsd_lcd_panel_wait_flush(esp_lcd_panel_t *panel);

void qmsd_lcd_buffer_select(esp_lcd_panel_t *panel, uint8_t* buf);
esp_err_t qmsd_lcd_rgb_panel_register_vsync(esp_lcd_panel_t *panel, qmsd_rgb_panel_vsync_cb_t on_vsync);
esp_err_t qsmd_lcd_rgb_panel_refresh(esp_lcd_panel_t *panel);

#ifdef __cplusplus
}
#endif

#endif

#endif
