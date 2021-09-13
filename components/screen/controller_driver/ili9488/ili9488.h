/**
 * @file ili9488.h
 */

#ifndef ILI9844_H
#define ILI9844_H

#ifdef __cplusplus
extern "C"
{
#endif

/*********************
 *      INCLUDES
 *********************/
#include <stdbool.h>
#include <stdint.h>

/*********************
 *      DEFINES
 *********************/
#define BOARD_LCD_I2S_BITWIDTH 16
#define BOARD_LCD_I2S_PORT_NUM 0
#define LCD_DATA_MAX_WIDTH 24

#define LCD_CAM_DMA_NODE_BUFFER_MAX_SIZE (4000) // 4-byte aligned

#define BOARD_LCD_I2S_CS_PIN 17
#define BOARD_LCD_I2S_WR_PIN 18
#define BOARD_LCD_I2S_RS_PIN 19
#define BOARD_LCD_I2S_D0_PIN 1
#define BOARD_LCD_I2S_D1_PIN 2
#define BOARD_LCD_I2S_D2_PIN 3
#define BOARD_LCD_I2S_D3_PIN 4
#define BOARD_LCD_I2S_D4_PIN 5
#define BOARD_LCD_I2S_D5_PIN 6
#define BOARD_LCD_I2S_D6_PIN 7
#define BOARD_LCD_I2S_D7_PIN 8
#define BOARD_LCD_I2S_D8_PIN 9
#define BOARD_LCD_I2S_D9_PIN 10
#define BOARD_LCD_I2S_D10_PIN 11
#define BOARD_LCD_I2S_D11_PIN 12
#define BOARD_LCD_I2S_D12_PIN 13
#define BOARD_LCD_I2S_D13_PIN 14
#define BOARD_LCD_I2S_D14_PIN 15
#define BOARD_LCD_I2S_D15_PIN 16
#define BOARD_LCD_I2S_RESET_PIN 20
#define BOARD_LCD_I2S_BL_PIN 21

#define ILI9488_ENABLE_BACKLIGHT_CONTROL CONFIG_LVGL_ENABLE_BACKLIGHT_CONTROL

/*******************
 * ILI9488 REGS
*********************/

/* Level 1 Commands (from the display Datasheet) */
#define ILI9488_CMD_NOP 0x00
#define ILI9488_CMD_SOFTWARE_RESET 0x01
#define ILI9488_CMD_READ_DISP_ID 0x04
#define ILI9488_CMD_READ_ERROR_DSI 0x05
#define ILI9488_CMD_READ_DISP_STATUS 0x09
#define ILI9488_CMD_READ_DISP_POWER_MODE 0x0A
#define ILI9488_CMD_READ_DISP_MADCTRL 0x0B
#define ILI9488_CMD_READ_DISP_PIXEL_FORMAT 0x0C
#define ILI9488_CMD_READ_DISP_IMAGE_MODE 0x0D
#define ILI9488_CMD_READ_DISP_SIGNAL_MODE 0x0E
#define ILI9488_CMD_READ_DISP_SELF_DIAGNOSTIC 0x0F
#define ILI9488_CMD_ENTER_SLEEP_MODE 0x10
#define ILI9488_CMD_SLEEP_OUT 0x11
#define ILI9488_CMD_PARTIAL_MODE_ON 0x12
#define ILI9488_CMD_NORMAL_DISP_MODE_ON 0x13
#define ILI9488_CMD_DISP_INVERSION_OFF 0x20
#define ILI9488_CMD_DISP_INVERSION_ON 0x21
#define ILI9488_CMD_PIXEL_OFF 0x22
#define ILI9488_CMD_PIXEL_ON 0x23
#define ILI9488_CMD_DISPLAY_OFF 0x28
#define ILI9488_CMD_DISPLAY_ON 0x29
#define ILI9488_CMD_COLUMN_ADDRESS_SET 0x2A
#define ILI9488_CMD_PAGE_ADDRESS_SET 0x2B
#define ILI9488_CMD_MEMORY_WRITE 0x2C
#define ILI9488_CMD_MEMORY_READ 0x2E
#define ILI9488_CMD_PARTIAL_AREA 0x30
#define ILI9488_CMD_VERT_SCROLL_DEFINITION 0x33
#define ILI9488_CMD_TEARING_EFFECT_LINE_OFF 0x34
#define ILI9488_CMD_TEARING_EFFECT_LINE_ON 0x35
#define ILI9488_CMD_MEMORY_ACCESS_CONTROL 0x36
#define ILI9488_CMD_VERT_SCROLL_START_ADDRESS 0x37
#define ILI9488_CMD_IDLE_MODE_OFF 0x38
#define ILI9488_CMD_IDLE_MODE_ON 0x39
#define ILI9488_CMD_COLMOD_PIXEL_FORMAT_SET 0x3A
#define ILI9488_CMD_WRITE_MEMORY_CONTINUE 0x3C
#define ILI9488_CMD_READ_MEMORY_CONTINUE 0x3E
#define ILI9488_CMD_SET_TEAR_SCANLINE 0x44
#define ILI9488_CMD_GET_SCANLINE 0x45
#define ILI9488_CMD_WRITE_DISPLAY_BRIGHTNESS 0x51
#define ILI9488_CMD_READ_DISPLAY_BRIGHTNESS 0x52
#define ILI9488_CMD_WRITE_CTRL_DISPLAY 0x53
#define ILI9488_CMD_READ_CTRL_DISPLAY 0x54
#define ILI9488_CMD_WRITE_CONTENT_ADAPT_BRIGHTNESS 0x55
#define ILI9488_CMD_READ_CONTENT_ADAPT_BRIGHTNESS 0x56
#define ILI9488_CMD_WRITE_MIN_CAB_LEVEL 0x5E
#define ILI9488_CMD_READ_MIN_CAB_LEVEL 0x5F
#define ILI9488_CMD_READ_ABC_SELF_DIAG_RES 0x68
#define ILI9488_CMD_READ_ID1 0xDA
#define ILI9488_CMD_READ_ID2 0xDB
#define ILI9488_CMD_READ_ID3 0xDC

/* Level 2 Commands (from the display Datasheet) */
#define ILI9488_CMD_INTERFACE_MODE_CONTROL 0xB0
#define ILI9488_CMD_FRAME_RATE_CONTROL_NORMAL 0xB1
#define ILI9488_CMD_FRAME_RATE_CONTROL_IDLE_8COLOR 0xB2
#define ILI9488_CMD_FRAME_RATE_CONTROL_PARTIAL 0xB3
#define ILI9488_CMD_DISPLAY_INVERSION_CONTROL 0xB4
#define ILI9488_CMD_BLANKING_PORCH_CONTROL 0xB5
#define ILI9488_CMD_DISPLAY_FUNCTION_CONTROL 0xB6
#define ILI9488_CMD_ENTRY_MODE_SET 0xB7
#define ILI9488_CMD_BACKLIGHT_CONTROL_1 0xB9
#define ILI9488_CMD_BACKLIGHT_CONTROL_2 0xBA
#define ILI9488_CMD_HS_LANES_CONTROL 0xBE
#define ILI9488_CMD_POWER_CONTROL_1 0xC0
#define ILI9488_CMD_POWER_CONTROL_2 0xC1
#define ILI9488_CMD_POWER_CONTROL_NORMAL_3 0xC2
#define ILI9488_CMD_POWER_CONTROL_IDEL_4 0xC3
#define ILI9488_CMD_POWER_CONTROL_PARTIAL_5 0xC4
#define ILI9488_CMD_VCOM_CONTROL_1 0xC5
#define ILI9488_CMD_CABC_CONTROL_1 0xC6
#define ILI9488_CMD_CABC_CONTROL_2 0xC8
#define ILI9488_CMD_CABC_CONTROL_3 0xC9
#define ILI9488_CMD_CABC_CONTROL_4 0xCA
#define ILI9488_CMD_CABC_CONTROL_5 0xCB
#define ILI9488_CMD_CABC_CONTROL_6 0xCC
#define ILI9488_CMD_CABC_CONTROL_7 0xCD
#define ILI9488_CMD_CABC_CONTROL_8 0xCE
#define ILI9488_CMD_CABC_CONTROL_9 0xCF
#define ILI9488_CMD_NVMEM_WRITE 0xD0
#define ILI9488_CMD_NVMEM_PROTECTION_KEY 0xD1
#define ILI9488_CMD_NVMEM_STATUS_READ 0xD2
#define ILI9488_CMD_READ_ID4 0xD3
#define ILI9488_CMD_ADJUST_CONTROL_1 0xD7
#define ILI9488_CMD_READ_ID_VERSION 0xD8
#define ILI9488_CMD_POSITIVE_GAMMA_CORRECTION 0xE0
#define ILI9488_CMD_NEGATIVE_GAMMA_CORRECTION 0xE1
#define ILI9488_CMD_DIGITAL_GAMMA_CONTROL_1 0xE2
#define ILI9488_CMD_DIGITAL_GAMMA_CONTROL_2 0xE3
#define ILI9488_CMD_SET_IMAGE_FUNCTION 0xE9
#define ILI9488_CMD_ADJUST_CONTROL_2 0xF2
#define ILI9488_CMD_ADJUST_CONTROL_3 0xF7
#define ILI9488_CMD_ADJUST_CONTROL_4 0xF8
#define ILI9488_CMD_ADJUST_CONTROL_5 0xF9
#define ILI9488_CMD_SPI_READ_SETTINGS 0xFB
#define ILI9488_CMD_ADJUST_CONTROL_6 0xFC
#define ILI9488_CMD_ADJUST_CONTROL_7 0xFF

#define ILI9488_RESOLUTION_HOR 320
#define ILI9488_RESOLUTION_VER 480

    /**********************
 *      TYPEDEFS
 **********************/
    typedef struct
    {
        uint8_t red;
        uint8_t green;
        uint8_t blue;
    } lv_color_custom_t;

    /**********************
 * GLOBAL PROTOTYPES
 **********************/
    /**
 * @brief Initialize screen
 *
 * @param lcd_conf Pointer to a structure with lcd config arguments.
 * 
 * @return
 *      - ESP_OK on success
 *      - ESP_FAIL Driver not installed
 */
    esp_err_t lcd_ili9488_init(const scr_controller_config_t *lcd_conf);

    /**
 * @brief Deinitialize screen
 * 
 * @return
 *      - ESP_OK on success
 *      - ESP_FAIL Deinitialize failed
 *      - ESP_ERR_NOT_SUPPORTED unsupported
 */
    esp_err_t lcd_ili9488_deinit(void);

    /**
 * @brief Set screen direction of rotation
 *
 * @param dir Pointer to a scr_dir_t structure.
 * 
 * @return
 *      - ESP_OK on success
 *      - ESP_FAIL Failed
 */
    esp_err_t lcd_ili9488_set_rotation(scr_dir_t dir);

    /**
 * @brief Get screen information
 *
 * @param info Pointer to a scr_info_t structure.
 * 
 * @return
 *      - ESP_OK on success
 *      - ESP_FAIL Failed
 */
    esp_err_t lcd_ili9488_get_info(scr_info_t *info);

    /**
 * @brief Set screen window
 *
 * @param x0 Starting point in X direction
 * @param y0 Starting point in Y direction
 * @param x1 End point in X direction
 * @param y1 End point in Y direction
 * 
 * @return
 *      - ESP_OK on success
 *      - ESP_FAIL Failed
 */
    esp_err_t lcd_ili9488_set_window(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1);

    /**
 * @brief Write a RAM data
 * 
 * @param color New color of a pixel
 * 
 * @return 
 *      - ESP_OK on success
 *      - ESP_FAIL Failed
 */
    esp_err_t lcd_ili9488_write_ram_data(uint16_t color);

    /**
 * @brief Draw one pixel in screen with color
 * 
 * @param x X co-ordinate of set orientation
 * @param y Y co-ordinate of set orientation
 * @param color New color of the pixel
 * 
 * @return  
 *      - ESP_OK on success
 *      - ESP_FAIL Failed
 */
    esp_err_t lcd_ili9488_draw_pixel(uint16_t x, uint16_t y, uint16_t color);

    /**
 * @brief Fill the pixels on LCD screen with bitmap
 * 
 * @param x Starting point in X direction
 * @param y Starting point in Y direction
 * @param w width of image in bitmap array
 * @param h height of image in bitmap array
 * @param bitmap pointer to bitmap array
 * 
 * @return
 *      - ESP_OK on success
 *      - ESP_FAIL Failed
 */
    esp_err_t lcd_ili9488_draw_bitmap(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t *bitmap);

    /**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*ILI9488_H*/
