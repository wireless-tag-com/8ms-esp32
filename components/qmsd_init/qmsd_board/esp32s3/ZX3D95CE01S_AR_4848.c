#include <sdkconfig.h>
#ifdef CONFIG_ZX3D95CE01S_AR_4848
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
#include "qmsd_gui_init.h"
#include "qmsd_board_init.h"
#include "driver/ledc.h"

#define TAG "QMSD BOARD INIT"

#define LCD_PCLK_GPIO     (14)
#define LCD_DE_GPIO       (13)
#define LCD_VSYNC_GPIO    (12)
#define LCD_HSYNC_GPIO    (11)
#define LCD_DATA0_GPIO    (10)  // B0
#define LCD_DATA1_GPIO    (9)   // B1
#define LCD_DATA2_GPIO    (40)  // B2
#define LCD_DATA3_GPIO    (20)  // B3
#define LCD_DATA4_GPIO    (19)  // B4
#define LCD_DATA5_GPIO    (41)  // G0
#define LCD_DATA6_GPIO    (46)  // G1
#define LCD_DATA7_GPIO    (3)   // G2
#define LCD_DATA8_GPIO    (42)  // G3
#define LCD_DATA9_GPIO    (8)   // G4
#define LCD_DATA10_GPIO   (18)  // G5
#define LCD_DATA11_GPIO   (2)   // R0
#define LCD_DATA12_GPIO   (17)  // R1
#define LCD_DATA13_GPIO   (16)  // R2
#define LCD_DATA14_GPIO   (1)   // R3
#define LCD_DATA15_GPIO   (15)  // R4
#define LCD_DISP_EN_GPIO  (-1)

#define LCD_PIXEL_CLOCK_HZ (10 * 1000 * 1000)
#define LCD_PIN_MOSI          9  /*!< for 1-line SPI, this also refered as MOSI */
#define LCD_PIN_SCLK			10
#define LCD_PIN_CS             0
#define LCD_PIN_RST            -1
#define LCD_PIN_BK_LIGHT       45

#define TOUCH_IIC_SCL   6
#define TOUCH_IIC_SDA   7

#define LCD_BK_LIGHT_ON_LEVEL  1
#define LCD_BK_LIGHT_OFF_LEVEL !LCD_BK_LIGHT_ON_LEVEL

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
	__spi_send_cmd (0xF0);
	__spi_send_data (0x55);
	__spi_send_data (0xAA);
	__spi_send_data (0x52);
	__spi_send_data (0x08);
	__spi_send_data (0x00);

	__spi_send_cmd (0xF6);
	__spi_send_data (0x5A);
	__spi_send_data (0x87);

	__spi_send_cmd (0xC1);
	__spi_send_data (0x3F);

	__spi_send_cmd (0xC2);
	__spi_send_data (0x0E);

	__spi_send_cmd (0xC6);
	__spi_send_data (0xF8);

	__spi_send_cmd (0xC9);
	__spi_send_data (0x10);

	__spi_send_cmd (0xCD);
	__spi_send_data (0x25);

	__spi_send_cmd (0xF8);
	__spi_send_data (0x8A);

	__spi_send_cmd (0xAC);
	__spi_send_data (0x45);

	__spi_send_cmd (0xA0);
	__spi_send_data (0xDD);

	__spi_send_cmd (0xA7);
	__spi_send_data (0x47);

	__spi_send_cmd (0xFA);
	__spi_send_data (0x00);
	__spi_send_data (0x00);
	__spi_send_data (0x00);
	__spi_send_data (0x04);

	__spi_send_cmd (0x86);
	__spi_send_data (0x99);
	__spi_send_data (0xa3);
	__spi_send_data (0xa3);
	__spi_send_data (0x51);

	__spi_send_cmd (0xA3);
	__spi_send_data (0xEE);

	__spi_send_cmd (0xFD);
	__spi_send_data (0x3c);
	__spi_send_data (0x3c);
	__spi_send_data (0x00);

	__spi_send_cmd (0x71);
	__spi_send_data (0x48);

	__spi_send_cmd (0x72);
	__spi_send_data (0x48);

	__spi_send_cmd (0x73);
	__spi_send_data (0x00);
	__spi_send_data (0x44);

	__spi_send_cmd (0x97);
	__spi_send_data (0xEE);

	__spi_send_cmd (0x83);
	__spi_send_data (0x93);

	__spi_send_cmd (0x9A);
	__spi_send_data (0x72);

	__spi_send_cmd (0x9B);
	__spi_send_data (0x5a);

	__spi_send_cmd (0x82);
	__spi_send_data (0x2c);
	__spi_send_data (0x2c);

	__spi_send_cmd (0xB1);
	__spi_send_data (0x10);

	__spi_send_cmd (0x6D);
	__spi_send_data (0x00);
	__spi_send_data (0x1F);
	__spi_send_data (0x19);
	__spi_send_data (0x1A);
	__spi_send_data (0x10);
	__spi_send_data (0x0e);
	__spi_send_data (0x0c);
	__spi_send_data (0x0a);
	__spi_send_data (0x02);
	__spi_send_data (0x07);
	__spi_send_data (0x1E);
	__spi_send_data (0x1E);
	__spi_send_data (0x1E);
	__spi_send_data (0x1E);
	__spi_send_data (0x1E);
	__spi_send_data (0x1E);
	__spi_send_data (0x1E);
	__spi_send_data (0x1E);
	__spi_send_data (0x1E);
	__spi_send_data (0x1E);
	__spi_send_data (0x1E);
	__spi_send_data (0x1E);
	__spi_send_data (0x08);
	__spi_send_data (0x01);
	__spi_send_data (0x09);
	__spi_send_data (0x0b);
	__spi_send_data (0x0D);
	__spi_send_data (0x0F);
	__spi_send_data (0x1a);
	__spi_send_data (0x19);
	__spi_send_data (0x1f);
	__spi_send_data (0x00);

	__spi_send_cmd (0x64);
	__spi_send_data (0x38);
	__spi_send_data (0x05);
	__spi_send_data (0x01);
	__spi_send_data (0xdb);
	__spi_send_data (0x03);
	__spi_send_data (0x03);
	__spi_send_data (0x38);
	__spi_send_data (0x04);
	__spi_send_data (0x01);
	__spi_send_data (0xdc);
	__spi_send_data (0x03);
	__spi_send_data (0x03);
	__spi_send_data (0x7A);
	__spi_send_data (0x7A);
	__spi_send_data (0x7A);
	__spi_send_data (0x7A);

	__spi_send_cmd (0x65);
	__spi_send_data (0x38);
	__spi_send_data (0x03);
	__spi_send_data (0x01);
	__spi_send_data (0xdd);
	__spi_send_data (0x03);
	__spi_send_data (0x03);
	__spi_send_data (0x38);
	__spi_send_data (0x02);
	__spi_send_data (0x01);
	__spi_send_data (0xde);
	__spi_send_data (0x03);
	__spi_send_data (0x03);
	__spi_send_data (0x7A);
	__spi_send_data (0x7A);
	__spi_send_data (0x7A);
	__spi_send_data (0x7A);

	__spi_send_cmd (0x66);
	__spi_send_data (0x38);
	__spi_send_data (0x01);
	__spi_send_data (0x01);
	__spi_send_data (0xdf);
	__spi_send_data (0x03);
	__spi_send_data (0x03);
	__spi_send_data (0x38);
	__spi_send_data (0x00);
	__spi_send_data (0x01);
	__spi_send_data (0xe0);
	__spi_send_data (0x03);
	__spi_send_data (0x03);
	__spi_send_data (0x7A);
	__spi_send_data (0x7A);
	__spi_send_data (0x7A);
	__spi_send_data (0x7A);

	__spi_send_cmd (0x67);
	__spi_send_data (0x30);
	__spi_send_data (0x01);
	__spi_send_data (0x01);
	__spi_send_data (0xe1);
	__spi_send_data (0x03);
	__spi_send_data (0x03);
	__spi_send_data (0x30);
	__spi_send_data (0x02);
	__spi_send_data (0x01);
	__spi_send_data (0xe2);
	__spi_send_data (0x03);
	__spi_send_data (0x03);
	__spi_send_data (0x7A);
	__spi_send_data (0x7A);
	__spi_send_data (0x7A);
	__spi_send_data (0x7A);

	__spi_send_cmd (0x68);
	__spi_send_data (0x00);
	__spi_send_data (0x08);
	__spi_send_data (0x15);
	__spi_send_data (0x08);
	__spi_send_data (0x15);
	__spi_send_data (0x7A);
	__spi_send_data (0x7A);
	__spi_send_data (0x08);
	__spi_send_data (0x15);
	__spi_send_data (0x08);
	__spi_send_data (0x15);
	__spi_send_data (0x7A);
	__spi_send_data (0x7A);

	__spi_send_cmd (0x60);
	__spi_send_data (0x38);
	__spi_send_data (0x08);
	__spi_send_data (0x7A);
	__spi_send_data (0x7A);
	__spi_send_data (0x38);
	__spi_send_data (0x09);
	__spi_send_data (0x7A);
	__spi_send_data (0x7A);

	__spi_send_cmd (0x63);
	__spi_send_data (0x31);
	__spi_send_data (0xe4);
	__spi_send_data (0x7A);
	__spi_send_data (0x7A);
	__spi_send_data (0x31);
	__spi_send_data (0xe5);
	__spi_send_data (0x7A);
	__spi_send_data (0x7A);

	__spi_send_cmd (0x69);
	__spi_send_data (0x04);
	__spi_send_data (0x22);
	__spi_send_data (0x14);
	__spi_send_data (0x22);
	__spi_send_data (0x14);
	__spi_send_data (0x22);
	__spi_send_data (0x08);

	__spi_send_cmd (0x6B);
	__spi_send_data (0x07);

	__spi_send_cmd (0x7A);
	__spi_send_data (0x08);
	__spi_send_data (0x13);

	__spi_send_cmd (0x7B);
	__spi_send_data (0x08);
	__spi_send_data (0x13);

	__spi_send_cmd (0xD1);
	__spi_send_data (0x00);
	__spi_send_data (0x00);
	__spi_send_data (0x00);
	__spi_send_data (0x04);
	__spi_send_data (0x00);
	__spi_send_data (0x12);
	__spi_send_data (0x00);
	__spi_send_data (0x18);
	__spi_send_data (0x00);
	__spi_send_data (0x21);
	__spi_send_data (0x00);
	__spi_send_data (0x2a);
	__spi_send_data (0x00);
	__spi_send_data (0x35);
	__spi_send_data (0x00);
	__spi_send_data (0x47);
	__spi_send_data (0x00);
	__spi_send_data (0x56);
	__spi_send_data (0x00);
	__spi_send_data (0x90);
	__spi_send_data (0x00);
	__spi_send_data (0xe5);
	__spi_send_data (0x01);
	__spi_send_data (0x68);
	__spi_send_data (0x01);
	__spi_send_data (0xd5);
	__spi_send_data (0x01);
	__spi_send_data (0xd7);
	__spi_send_data (0x02);
	__spi_send_data (0x36);
	__spi_send_data (0x02);
	__spi_send_data (0xa6);
	__spi_send_data (0x02);
	__spi_send_data (0xee);
	__spi_send_data (0x03);
	__spi_send_data (0x48);
	__spi_send_data (0x03);
	__spi_send_data (0xa0);
	__spi_send_data (0x03);
	__spi_send_data (0xba);
	__spi_send_data (0x03);
	__spi_send_data (0xc5);
	__spi_send_data (0x03);
	__spi_send_data (0xd0);
	__spi_send_data (0x03);
	__spi_send_data (0xE0);
	__spi_send_data (0x03);
	__spi_send_data (0xea);
	__spi_send_data (0x03);
	__spi_send_data (0xFa);
	__spi_send_data (0x03);
	__spi_send_data (0xFF);

	__spi_send_cmd (0xD2);
	__spi_send_data (0x00);
	__spi_send_data (0x00);
	__spi_send_data (0x00);
	__spi_send_data (0x04);
	__spi_send_data (0x00);
	__spi_send_data (0x12);
	__spi_send_data (0x00);
	__spi_send_data (0x18);
	__spi_send_data (0x00);
	__spi_send_data (0x21);
	__spi_send_data (0x00);
	__spi_send_data (0x2a);
	__spi_send_data (0x00);
	__spi_send_data (0x35);
	__spi_send_data (0x00);
	__spi_send_data (0x47);
	__spi_send_data (0x00);
	__spi_send_data (0x56);
	__spi_send_data (0x00);
	__spi_send_data (0x90);
	__spi_send_data (0x00);
	__spi_send_data (0xe5);
	__spi_send_data (0x01);
	__spi_send_data (0x68);
	__spi_send_data (0x01);
	__spi_send_data (0xd5);
	__spi_send_data (0x01);
	__spi_send_data (0xd7);
	__spi_send_data (0x02);
	__spi_send_data (0x36);
	__spi_send_data (0x02);
	__spi_send_data (0xa6);
	__spi_send_data (0x02);
	__spi_send_data (0xee);
	__spi_send_data (0x03);
	__spi_send_data (0x48);
	__spi_send_data (0x03);
	__spi_send_data (0xa0);
	__spi_send_data (0x03);
	__spi_send_data (0xba);
	__spi_send_data (0x03);
	__spi_send_data (0xc5);
	__spi_send_data (0x03);
	__spi_send_data (0xd0);
	__spi_send_data (0x03);
	__spi_send_data (0xE0);
	__spi_send_data (0x03);
	__spi_send_data (0xea);
	__spi_send_data (0x03);
	__spi_send_data (0xFa);
	__spi_send_data (0x03);
	__spi_send_data (0xFF);

	__spi_send_cmd (0xD3);
	__spi_send_data (0x00);
	__spi_send_data (0x00);
	__spi_send_data (0x00);
	__spi_send_data (0x04);
	__spi_send_data (0x00);
	__spi_send_data (0x12);
	__spi_send_data (0x00);
	__spi_send_data (0x18);
	__spi_send_data (0x00);
	__spi_send_data (0x21);
	__spi_send_data (0x00);
	__spi_send_data (0x2a);
	__spi_send_data (0x00);
	__spi_send_data (0x35);
	__spi_send_data (0x00);
	__spi_send_data (0x47);
	__spi_send_data (0x00);
	__spi_send_data (0x56);
	__spi_send_data (0x00);
	__spi_send_data (0x90);
	__spi_send_data (0x00);
	__spi_send_data (0xe5);
	__spi_send_data (0x01);
	__spi_send_data (0x68);
	__spi_send_data (0x01);
	__spi_send_data (0xd5);
	__spi_send_data (0x01);
	__spi_send_data (0xd7);
	__spi_send_data (0x02);
	__spi_send_data (0x36);
	__spi_send_data (0x02);
	__spi_send_data (0xa6);
	__spi_send_data (0x02);
	__spi_send_data (0xee);
	__spi_send_data (0x03);
	__spi_send_data (0x48);
	__spi_send_data (0x03);
	__spi_send_data (0xa0);
	__spi_send_data (0x03);
	__spi_send_data (0xba);
	__spi_send_data (0x03);
	__spi_send_data (0xc5);
	__spi_send_data (0x03);
	__spi_send_data (0xd0);
	__spi_send_data (0x03);
	__spi_send_data (0xE0);
	__spi_send_data (0x03);
	__spi_send_data (0xea);
	__spi_send_data (0x03);
	__spi_send_data (0xFa);
	__spi_send_data (0x03);
	__spi_send_data (0xFF);

	__spi_send_cmd (0xD4);
	__spi_send_data (0x00);
	__spi_send_data (0x00);
	__spi_send_data (0x00);
	__spi_send_data (0x04);
	__spi_send_data (0x00);
	__spi_send_data (0x12);
	__spi_send_data (0x00);
	__spi_send_data (0x18);
	__spi_send_data (0x00);
	__spi_send_data (0x21);
	__spi_send_data (0x00);
	__spi_send_data (0x2a);
	__spi_send_data (0x00);
	__spi_send_data (0x35);
	__spi_send_data (0x00);
	__spi_send_data (0x47);
	__spi_send_data (0x00);
	__spi_send_data (0x56);
	__spi_send_data (0x00);
	__spi_send_data (0x90);
	__spi_send_data (0x00);
	__spi_send_data (0xe5);
	__spi_send_data (0x01);
	__spi_send_data (0x68);
	__spi_send_data (0x01);
	__spi_send_data (0xd5);
	__spi_send_data (0x01);
	__spi_send_data (0xd7);
	__spi_send_data (0x02);
	__spi_send_data (0x36);
	__spi_send_data (0x02);
	__spi_send_data (0xa6);
	__spi_send_data (0x02);
	__spi_send_data (0xee);
	__spi_send_data (0x03);
	__spi_send_data (0x48);
	__spi_send_data (0x03);
	__spi_send_data (0xa0);
	__spi_send_data (0x03);
	__spi_send_data (0xba);
	__spi_send_data (0x03);
	__spi_send_data (0xc5);
	__spi_send_data (0x03);
	__spi_send_data (0xd0);
	__spi_send_data (0x03);
	__spi_send_data (0xE0);
	__spi_send_data (0x03);
	__spi_send_data (0xea);
	__spi_send_data (0x03);
	__spi_send_data (0xFa);
	__spi_send_data (0x03);
	__spi_send_data (0xFF);

	__spi_send_cmd (0xD5);
	__spi_send_data (0x00);
	__spi_send_data (0x00);
	__spi_send_data (0x00);
	__spi_send_data (0x04);
	__spi_send_data (0x00);
	__spi_send_data (0x12);
	__spi_send_data (0x00);
	__spi_send_data (0x18);
	__spi_send_data (0x00);
	__spi_send_data (0x21);
	__spi_send_data (0x00);
	__spi_send_data (0x2a);
	__spi_send_data (0x00);
	__spi_send_data (0x35);
	__spi_send_data (0x00);
	__spi_send_data (0x47);
	__spi_send_data (0x00);
	__spi_send_data (0x56);
	__spi_send_data (0x00);
	__spi_send_data (0x90);
	__spi_send_data (0x00);
	__spi_send_data (0xe5);
	__spi_send_data (0x01);
	__spi_send_data (0x68);
	__spi_send_data (0x01);
	__spi_send_data (0xd5);
	__spi_send_data (0x01);
	__spi_send_data (0xd7);
	__spi_send_data (0x02);
	__spi_send_data (0x36);
	__spi_send_data (0x02);
	__spi_send_data (0xa6);
	__spi_send_data (0x02);
	__spi_send_data (0xee);
	__spi_send_data (0x03);
	__spi_send_data (0x48);
	__spi_send_data (0x03);
	__spi_send_data (0xa0);
	__spi_send_data (0x03);
	__spi_send_data (0xba);
	__spi_send_data (0x03);
	__spi_send_data (0xc5);
	__spi_send_data (0x03);
	__spi_send_data (0xd0);
	__spi_send_data (0x03);
	__spi_send_data (0xE0);
	__spi_send_data (0x03);
	__spi_send_data (0xea);
	__spi_send_data (0x03);
	__spi_send_data (0xFa);
	__spi_send_data (0x03);
	__spi_send_data (0xFF);

	__spi_send_cmd (0xD6);
	__spi_send_data (0x00);
	__spi_send_data (0x00);
	__spi_send_data (0x00);
	__spi_send_data (0x04);
	__spi_send_data (0x00);
	__spi_send_data (0x12);
	__spi_send_data (0x00);
	__spi_send_data (0x18);
	__spi_send_data (0x00);
	__spi_send_data (0x21);
	__spi_send_data (0x00);
	__spi_send_data (0x2a);
	__spi_send_data (0x00);
	__spi_send_data (0x35);
	__spi_send_data (0x00);
	__spi_send_data (0x47);
	__spi_send_data (0x00);
	__spi_send_data (0x56);
	__spi_send_data (0x00);
	__spi_send_data (0x90);
	__spi_send_data (0x00);
	__spi_send_data (0xe5);
	__spi_send_data (0x01);
	__spi_send_data (0x68);
	__spi_send_data (0x01);
	__spi_send_data (0xd5);
	__spi_send_data (0x01);
	__spi_send_data (0xd7);
	__spi_send_data (0x02);
	__spi_send_data (0x36);
	__spi_send_data (0x02);
	__spi_send_data (0xa6);
	__spi_send_data (0x02);
	__spi_send_data (0xee);
	__spi_send_data (0x03);
	__spi_send_data (0x48);
	__spi_send_data (0x03);
	__spi_send_data (0xa0);
	__spi_send_data (0x03);
	__spi_send_data (0xba);
	__spi_send_data (0x03);
	__spi_send_data (0xc5);
	__spi_send_data (0x03);
	__spi_send_data (0xd0);
	__spi_send_data (0x03);
	__spi_send_data (0xE0);
	__spi_send_data (0x03);
	__spi_send_data (0xea);
	__spi_send_data (0x03);
	__spi_send_data (0xFa);
	__spi_send_data (0x03);
	__spi_send_data (0xFF);

	__spi_send_cmd (0x3a);
	__spi_send_data (0x66);

	__spi_send_cmd (0x11);
	vTaskDelay(pdMS_TO_TICKS(120));
	__spi_send_cmd (0x29);
	vTaskDelay(pdMS_TO_TICKS(20));
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

	spi_bus_remove_device(g_spi);
	spi_bus_free(SPI2_HOST);
}

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
            .i2c_addr = 0x38,
        },
        .interface_type = TOUCH_PANEL_IFACE_I2C,
        .pin_num_int = -1,
        .direction = TOUCH_DIR_LRTB,
        .width = 480,
        .height = 480,
    };
    touch_panel_find_driver(TOUCH_PANEL_CONTROLLER_FT5X06, &g_touch);
    g_touch.init(&touch_cfg);

    lvgl_indev_init(&g_touch);
}

void board_backlight_init(int16_t blk_pin) {
    if (blk_pin < 0) {
        return ;
    }

    // Prepare and then apply the LEDC PWM timer configuration
    ledc_timer_config_t ledc_timer = {
        .speed_mode       = LEDC_LOW_SPEED_MODE,
        .timer_num        = LEDC_TIMER_0,
        .duty_resolution  = LEDC_TIMER_10_BIT,
        .freq_hz          = 2000,  // Set output frequency at 1 kHz
        .clk_cfg          = LEDC_AUTO_CLK
    };
    ESP_ERROR_CHECK(ledc_timer_config(&ledc_timer));

    // Prepare and then apply the LEDC PWM channel configuration
    ledc_channel_config_t ledc_channel = {
        .speed_mode     = LEDC_LOW_SPEED_MODE,
        .channel        = LEDC_CHANNEL_0,
        .timer_sel      = LEDC_TIMER_0,
        .intr_type      = LEDC_INTR_DISABLE,
        .gpio_num       = blk_pin,
        .duty           = 0, // Set duty to 0%
        .hpoint         = 0
    };
    ESP_ERROR_CHECK(ledc_channel_config(&ledc_channel));
}

void board_backlight_control(uint8_t light) {
    if (LCD_PIN_BK_LIGHT < 0) {
        return ;
    }

    if (light > 100) {
        light = 100;
    }
    uint16_t duty = 1024.0 / 100.0 * light;
    ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0, duty);
    ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0);
}

void qmsd_board_init(qmsd_screen_rotation_t dir)
{
	qmsd_gui_mode_t mode = qmsd_gui_get_mode();

    gpio_config_t bk_gpio_config = {
        .mode = GPIO_MODE_OUTPUT,
        .pin_bit_mask = 1ULL << LCD_PIN_BK_LIGHT
    };
    // Initialize the GPIO of backlight
    ESP_ERROR_CHECK(gpio_config(&bk_gpio_config));

    ESP_ERROR_CHECK(gpio_set_level(LCD_PIN_BK_LIGHT, LCD_BK_LIGHT_OFF_LEVEL));

	board_backlight_init(LCD_PIN_BK_LIGHT);
	board_backlight_control(0);

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
            .v_res = 480,
            .hsync_pulse_width = 10,
            .hsync_back_porch = 80,
            .hsync_front_porch = 60,
            .vsync_pulse_width = 10,
            .vsync_back_porch = 20,
            .vsync_front_porch = 100,
        },
        .flags.fb_in_psram = 1,
        .flags.relax_on_idle = 0,
        .flags.double_buffer = 1,
		.bounce_buffer_size_px = 0,
        .clk_src = LCD_CLK_SRC_PLL240M,
    };

	if (mode == QMSD_GUI_MODE_PERFORMENCE) {
		panel_config.timings.pclk_hz = 15000000;
		panel_config.timings.hsync_pulse_width = 10;
		panel_config.timings.hsync_back_porch = 40;
		panel_config.timings.hsync_front_porch = 8;
		panel_config.timings.vsync_pulse_width = 10;
		panel_config.timings.vsync_back_porch = 40;
		panel_config.timings.vsync_front_porch = 8;
		panel_config.bounce_buffer_size_px = 0;
	} else {
		panel_config.timings.pclk_hz = 24000000;
		panel_config.timings.hsync_pulse_width = 10;
		panel_config.timings.hsync_back_porch = 80;
		panel_config.timings.hsync_front_porch = 60;
		panel_config.timings.vsync_pulse_width = 10;
		panel_config.timings.vsync_back_porch = 20;
		panel_config.timings.vsync_front_porch = 100;
		panel_config.bounce_buffer_size_px = 480 * 16;
	}

	qmsd_spi_init(LCD_PIN_CS, LCD_PIN_SCLK, LCD_PIN_MOSI);
    qmsd_rgb_init(&panel_config);
	__qmsd_touch_init();

	board_backlight_control(100);
}
#endif