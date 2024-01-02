#include <sdkconfig.h>
#ifdef CONFIG_ZX4D60_AR_4896
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

#define LCD_VSYNC_GPIO    (41)
#define LCD_HSYNC_GPIO    (42)
#define LCD_DE_GPIO       (40)
#define LCD_PCLK_GPIO     (39)
#define LCD_DATA0_GPIO    (45)  // B0
#define LCD_DATA1_GPIO    (48)  // B1
#define LCD_DATA2_GPIO    (47)  // B2
#define LCD_DATA3_GPIO    (21)  // B3
#define LCD_DATA4_GPIO    (14)  // B4
#define LCD_DATA5_GPIO    (13)  // G0
#define LCD_DATA6_GPIO    (12) // G1
#define LCD_DATA7_GPIO    (11) // G2
#define LCD_DATA8_GPIO    (10) // G3
#define LCD_DATA9_GPIO    (16) // G4
#define LCD_DATA10_GPIO   (17) // G5
#define LCD_DATA11_GPIO   (18) // R0
#define LCD_DATA12_GPIO   (8) // R1
#define LCD_DATA13_GPIO   (3) // R2
#define LCD_DATA14_GPIO   (46) // R3
#define LCD_DATA15_GPIO   (9) // R4
#define LCD_DISP_EN_GPIO  (-1)

#define LCD_PIXEL_CLOCK_HZ (10 * 1000 * 1000)
#define LCD_PIN_MOSI          48  /*!< for 1-line SPI, this also refered as MOSI */
#define LCD_PIN_SCLK			45
#define LCD_PIN_CS             38
#define LCD_PIN_RST            5
#define LCD_PIN_BK_LIGHT       4

#define LCD_BK_LIGHT_ON_LEVEL  1
#define LCD_BK_LIGHT_OFF_LEVEL !LCD_BK_LIGHT_ON_LEVEL

#define TP_SDA	15
#define TP_SCL	6
#define TP_INT	7


static spi_device_handle_t g_spi;

static void __spi_send_cmd(uint8_t cmd)
{
    uint16_t tmp_cmd = (cmd | 0x0000);;
    spi_transaction_ext_t trans = (spi_transaction_ext_t)
    {
        .base =
        {
            .flags = SPI_TRANS_VARIABLE_CMD,
            .cmd = tmp_cmd,
        },
        .command_bits = 9,
    };
    spi_device_transmit(g_spi, (spi_transaction_t *)&trans);
}

static void __spi_send_data(uint8_t data)
{
    uint16_t tmp_data = (data | 0x0100);
    spi_transaction_ext_t trans = (spi_transaction_ext_t){
        .base = {
            .flags = SPI_TRANS_VARIABLE_CMD,
            .cmd = tmp_data,
        },
        .command_bits = 9,
    };
    spi_device_transmit(g_spi, (spi_transaction_t *)&trans);
}

static void __lcd_init(void)
{
__spi_send_cmd( 0xFF);     
__spi_send_data( 0x77);   
__spi_send_data( 0x01);   
__spi_send_data( 0x00);   
__spi_send_data( 0x00);   
__spi_send_data( 0x13);   

__spi_send_cmd( 0xEF);     
__spi_send_data( 0x08);   

__spi_send_cmd( 0xFF);     
__spi_send_data( 0x77);   
__spi_send_data( 0x01);   
__spi_send_data( 0x00);   
__spi_send_data( 0x00);   
__spi_send_data( 0x10);   

__spi_send_cmd( 0xC0);     
__spi_send_data( 0x77);   
__spi_send_data( 0x00);   

__spi_send_cmd( 0xC1);     
__spi_send_data( 0x09);   
__spi_send_data( 0x08);   

__spi_send_cmd( 0xC2);     
__spi_send_data( 0x07);   
__spi_send_data( 0x02);   

__spi_send_cmd( 0xC7);     
__spi_send_data( 0x04); 

__spi_send_cmd( 0xCC);     
__spi_send_data( 0x10);   

__spi_send_cmd( 0xB0);     
__spi_send_data( 0x40);   
__spi_send_data( 0x14);   
__spi_send_data( 0x59);   
__spi_send_data( 0x10);   
__spi_send_data( 0x12);   
__spi_send_data( 0x08);   
__spi_send_data( 0x03);   
__spi_send_data( 0x09);   
__spi_send_data( 0x05);   
__spi_send_data( 0x1E);   
__spi_send_data( 0x05);   
__spi_send_data( 0x14);   
__spi_send_data( 0x10);   
__spi_send_data( 0x68);   
__spi_send_data( 0x33);   
__spi_send_data( 0x15);   

__spi_send_cmd( 0xB1);     
__spi_send_data( 0x40);   
__spi_send_data( 0x08);   
__spi_send_data( 0x53);   
__spi_send_data( 0x09);   
__spi_send_data( 0x11);   
__spi_send_data( 0x09);   
__spi_send_data( 0x02);   
__spi_send_data( 0x07);   
__spi_send_data( 0x09);   
__spi_send_data( 0x1A);   
__spi_send_data( 0x04);   
__spi_send_data( 0x12);   
__spi_send_data( 0x12);   
__spi_send_data( 0x64);   
__spi_send_data( 0x29);   
__spi_send_data( 0x29);   

__spi_send_cmd( 0xFF);     
__spi_send_data( 0x77);   
__spi_send_data( 0x01);   
__spi_send_data( 0x00);   
__spi_send_data( 0x00);   
__spi_send_data( 0x11);   

__spi_send_cmd( 0xB0);     
__spi_send_data( 0x6D);   

__spi_send_cmd( 0xB1);     
__spi_send_data( 0x1D);   

__spi_send_cmd( 0xB2);     
__spi_send_data( 0x87);   

__spi_send_cmd( 0xB3);     
__spi_send_data( 0x80);   

__spi_send_cmd( 0xB5);     
__spi_send_data( 0x49);   

__spi_send_cmd( 0xB7);     
__spi_send_data( 0x85);   

__spi_send_cmd( 0xB8);     
__spi_send_data( 0x20);   

__spi_send_cmd( 0xC1);     
__spi_send_data( 0x78);   

__spi_send_cmd( 0xC2);     
__spi_send_data( 0x78);   

__spi_send_cmd( 0xD0);     
__spi_send_data( 0x88);   

__spi_send_cmd( 0xE0);     
__spi_send_data( 0x00);   
__spi_send_data( 0x00);   
__spi_send_data( 0x02);   

__spi_send_cmd( 0xE1);     
__spi_send_data( 0x02);   
__spi_send_data( 0x8C);   
__spi_send_data( 0x00);   
__spi_send_data( 0x00);   
__spi_send_data( 0x03);   
__spi_send_data( 0x8C);   
__spi_send_data( 0x00);   
__spi_send_data( 0x00);   
__spi_send_data( 0x00);   
__spi_send_data( 0x33);   
__spi_send_data( 0x33);   

__spi_send_cmd( 0xE2);     
__spi_send_data( 0x33);   
__spi_send_data( 0x33);   
__spi_send_data( 0x33);   
__spi_send_data( 0x33);   
__spi_send_data( 0xC9);   
__spi_send_data( 0x3C);   
__spi_send_data( 0x00);   
__spi_send_data( 0x00);   
__spi_send_data( 0xCA);   
__spi_send_data( 0x3C);   
__spi_send_data( 0x00);   
__spi_send_data( 0x00);   
__spi_send_data( 0x00);   

__spi_send_cmd( 0xE3);     
__spi_send_data( 0x00);   
__spi_send_data( 0x00);   
__spi_send_data( 0x33);   
__spi_send_data( 0x33);   

__spi_send_cmd( 0xE4);     
__spi_send_data( 0x44);   
__spi_send_data( 0x44);   

__spi_send_cmd( 0xE5);     
__spi_send_data( 0x05);   
__spi_send_data( 0xCD);   
__spi_send_data( 0x82);   
__spi_send_data( 0x82);   
__spi_send_data( 0x01);   
__spi_send_data( 0xC9);   
__spi_send_data( 0x82);   
__spi_send_data( 0x82);   
__spi_send_data( 0x07);   
__spi_send_data( 0xCF);   
__spi_send_data( 0x82);   
__spi_send_data( 0x82);   
__spi_send_data( 0x03);   
__spi_send_data( 0xCB);   
__spi_send_data( 0x82);   
__spi_send_data( 0x82);   

__spi_send_cmd( 0xE6);     
__spi_send_data( 0x00);   
__spi_send_data( 0x00);   
__spi_send_data( 0x33);   
__spi_send_data( 0x33);   

__spi_send_cmd( 0xE7);     
__spi_send_data( 0x44);   
__spi_send_data( 0x44);   

__spi_send_cmd( 0xE8);     
__spi_send_data( 0x06);   
__spi_send_data( 0xCE);   
__spi_send_data( 0x82);   
__spi_send_data( 0x82);   
__spi_send_data( 0x02);   
__spi_send_data( 0xCA);   
__spi_send_data( 0x82);   
__spi_send_data( 0x82);   
__spi_send_data( 0x08);   
__spi_send_data( 0xD0);   
__spi_send_data( 0x82);   
__spi_send_data( 0x82);   
__spi_send_data( 0x04);   
__spi_send_data( 0xCC);   
__spi_send_data( 0x82);   
__spi_send_data( 0x82);   

__spi_send_cmd( 0xEB);     
__spi_send_data( 0x08);   
__spi_send_data( 0x01);   
__spi_send_data( 0xE4);   
__spi_send_data( 0xE4);   
__spi_send_data( 0x88);   
__spi_send_data( 0x00);   
__spi_send_data( 0x40);   

__spi_send_cmd( 0xEC);     
__spi_send_data( 0x00);   
__spi_send_data( 0x00);   
__spi_send_data( 0x00);   

__spi_send_cmd( 0xED);     
__spi_send_data( 0xFF);   
__spi_send_data( 0xF0);   
__spi_send_data( 0x07);   
__spi_send_data( 0x65);   
__spi_send_data( 0x4C);   
__spi_send_data( 0xCF);   
__spi_send_data( 0xF2);   
__spi_send_data( 0x2F);   
__spi_send_data( 0xF2);   
__spi_send_data( 0x2F);   
__spi_send_data( 0xFC);   
__spi_send_data( 0xC4);   
__spi_send_data( 0x56);   
__spi_send_data( 0x70);   
__spi_send_data( 0x0F);   
__spi_send_data( 0xFF);   

__spi_send_cmd( 0xEF);     
__spi_send_data( 0x10);   
__spi_send_data( 0x0D);   
__spi_send_data( 0x04);   
__spi_send_data( 0x08);   
__spi_send_data( 0x3F);   
__spi_send_data( 0x1F);   

__spi_send_cmd( 0xFF);     
__spi_send_data( 0x77);   
__spi_send_data( 0x01);   
__spi_send_data( 0x00);   
__spi_send_data( 0x00);   
__spi_send_data( 0x00);   

__spi_send_cmd( 0x11);     

vTaskDelay(pdMS_TO_TICKS(120));            

__spi_send_cmd( 0x35);     
__spi_send_data( 0x00);   

__spi_send_cmd( 0x36);     
__spi_send_data( 0x10);   

__spi_send_cmd( 0x3A);     
__spi_send_data( 0x66);   

__spi_send_cmd( 0x29);     
}

static void qmsd_spi_init(int cs_pin, int sclk, int mosi)
{
    spi_bus_config_t buscfg = {
        .sclk_io_num = sclk,
        .mosi_io_num = mosi,
        .miso_io_num = -1,
        .quadwp_io_num = -1,
        .quadhd_io_num = -1,
        .max_transfer_sz = 10 * 1024,
    };
    ESP_ERROR_CHECK(spi_bus_initialize(SPI2_HOST, &buscfg, SPI_DMA_CH_AUTO));

    spi_device_interface_config_t devcfg =
    {
        .clock_speed_hz = SPI_MASTER_FREQ_10M,         //Clock out at 10 MHz
        .mode = 0,                              //SPI mode 0
        .spics_io_num = cs_pin,               		//CS pin
        .queue_size = 7,                        //We want to be able to queue 7 transactions at a time
    };
    
    ESP_ERROR_CHECK(spi_bus_add_device(SPI2_HOST, &devcfg, &g_spi));

    __lcd_init();
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

    ESP_ERROR_CHECK(gpio_set_level(LCD_PIN_RST, 1));
    vTaskDelay(pdMS_TO_TICKS(20));

    ESP_ERROR_CHECK(gpio_set_level(LCD_PIN_RST, 0));
    vTaskDelay(pdMS_TO_TICKS(50));
    ESP_ERROR_CHECK(gpio_set_level(LCD_PIN_RST, 1));
    vTaskDelay(pdMS_TO_TICKS(120));

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
            .h_res = 480,
            .v_res = 960,
            .hsync_pulse_width = 4,
            .hsync_back_porch = 4,
            .hsync_front_porch = 4,
            .vsync_pulse_width = 6,
            .vsync_back_porch = 20,
            .vsync_front_porch = 18,
        },
        .flags.fb_in_psram = 1,
        .flags.relax_on_idle = 0,
        .flags.double_buffer = 1,
		.bounce_buffer_size_px = 480 * 32,
        .clk_src = LCD_CLK_SRC_PLL240M,
    };

    qmsd_spi_init(LCD_PIN_CS, LCD_PIN_SCLK, LCD_PIN_MOSI);
    qmsd_rgb_init(&panel_config);

    ESP_ERROR_CHECK(gpio_set_level(LCD_PIN_BK_LIGHT, LCD_BK_LIGHT_ON_LEVEL));
}
#endif
