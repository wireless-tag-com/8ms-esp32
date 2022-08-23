#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "soc/soc_caps.h"
#include "qmsd_board_pin.h"
#include "driver/gpio.h"
#include "driver/spi_master.h"

static spi_device_handle_t g_screen_spi;

static void lcd_cmd(spi_device_handle_t spi, const uint16_t data) {
    esp_err_t ret;
    uint16_t tmp_cmd =(data | 0x0000);
    spi_transaction_ext_t trans =(spi_transaction_ext_t) {
        .base = {
            .flags = SPI_TRANS_VARIABLE_CMD,
            .cmd = tmp_cmd,
        },
        .command_bits = 9,
    };
    ret = spi_device_transmit(spi,(spi_transaction_t *)&trans);
    assert(ret == ESP_OK);          //Should have had no issues.
}

static void lcd_data(spi_device_handle_t spi, const uint16_t data) {
    esp_err_t ret;
    uint16_t tmp_cmd =(data | 0x0100);
    spi_transaction_ext_t trans =(spi_transaction_ext_t) {
        .base = {
            .flags = SPI_TRANS_VARIABLE_CMD,
            .cmd = tmp_cmd,
        },
        .command_bits = 9,
    };
    ret = spi_device_transmit(spi,(spi_transaction_t *)&trans);

    assert(ret == ESP_OK);          //Should have had no issues.
}

static void SPI_WriteComm(uint16_t cmd) {
    lcd_cmd(g_screen_spi, cmd);
}

static void SPI_WriteData(uint16_t data) {
    lcd_data(g_screen_spi, data);
}

static void rgb_driver_init(void) {
	SPI_WriteComm(0xF0);
	SPI_WriteData(0x55);
	SPI_WriteData(0xAA);
	SPI_WriteData(0x52);
	SPI_WriteData(0x08);
	SPI_WriteData(0x00);

	SPI_WriteComm(0xF6);
	SPI_WriteData(0x5A);
	SPI_WriteData(0x87);

	SPI_WriteComm(0xC1);
	SPI_WriteData(0x3F);

	SPI_WriteComm(0xC2);
	SPI_WriteData(0x0E);

	SPI_WriteComm(0xC6);
	SPI_WriteData(0xF8);

	SPI_WriteComm(0xC9);
	SPI_WriteData(0x10);

	SPI_WriteComm(0xCD);
	SPI_WriteData(0x25);

	SPI_WriteComm(0xF8);
	SPI_WriteData(0x8A);

	SPI_WriteComm(0xAC);
	SPI_WriteData(0x45);

	SPI_WriteComm(0xA0);
	SPI_WriteData(0xDD);

	SPI_WriteComm(0xA7);
	SPI_WriteData(0x47);

	SPI_WriteComm(0xFA);
	SPI_WriteData(0x00);
	SPI_WriteData(0x00);
	SPI_WriteData(0x00);
	SPI_WriteData(0x04);

	SPI_WriteComm(0x86);
	SPI_WriteData(0x99);
	SPI_WriteData(0xa3);
	SPI_WriteData(0xa3);
	SPI_WriteData(0x51);

	SPI_WriteComm(0xA3);
	SPI_WriteData(0xEE);

	SPI_WriteComm(0xFD);
	SPI_WriteData(0x28);
	SPI_WriteData(0x28);
	SPI_WriteData(0x00);

	SPI_WriteComm(0x71);
	SPI_WriteData(0x48);

	SPI_WriteComm(0x72);
	SPI_WriteData(0x48);

	SPI_WriteComm(0x73);
	SPI_WriteData(0x00);
	SPI_WriteData(0x44);

	SPI_WriteComm(0x97);
	SPI_WriteData(0xEE);

	SPI_WriteComm(0x83);
	SPI_WriteData(0x93);

	SPI_WriteComm(0x9A);
	SPI_WriteData(0x72);

	SPI_WriteComm(0x9B);
	SPI_WriteData(0x5a);

	SPI_WriteComm(0x82);
	SPI_WriteData(0x2c);
	SPI_WriteData(0x2c);

	SPI_WriteComm(0xB1);
	SPI_WriteData(0x10);

	SPI_WriteComm(0x6D);
	SPI_WriteData(0x00);
	SPI_WriteData(0x1F);
	SPI_WriteData(0x19);
	SPI_WriteData(0x1A);
	SPI_WriteData(0x10);
	SPI_WriteData(0x0e);
	SPI_WriteData(0x0c);
	SPI_WriteData(0x0a);
	SPI_WriteData(0x02);
	SPI_WriteData(0x07);
	SPI_WriteData(0x1E);
	SPI_WriteData(0x1E);
	SPI_WriteData(0x1E);
	SPI_WriteData(0x1E);
	SPI_WriteData(0x1E);
	SPI_WriteData(0x1E);
	SPI_WriteData(0x1E);
	SPI_WriteData(0x1E);
	SPI_WriteData(0x1E);
	SPI_WriteData(0x1E);
	SPI_WriteData(0x1E);
	SPI_WriteData(0x1E);
	SPI_WriteData(0x08);
	SPI_WriteData(0x01);
	SPI_WriteData(0x09);
	SPI_WriteData(0x0b);
	SPI_WriteData(0x0D);
	SPI_WriteData(0x0F);
	SPI_WriteData(0x1a);
	SPI_WriteData(0x19);
	SPI_WriteData(0x1f);
	SPI_WriteData(0x00);

	SPI_WriteComm(0x64);
	SPI_WriteData(0x38);
	SPI_WriteData(0x05);
	SPI_WriteData(0x01);
	SPI_WriteData(0xdb);
	SPI_WriteData(0x03);
	SPI_WriteData(0x03);
	SPI_WriteData(0x38);
	SPI_WriteData(0x04);
	SPI_WriteData(0x01);
	SPI_WriteData(0xdc);
	SPI_WriteData(0x03);
	SPI_WriteData(0x03);
	SPI_WriteData(0x7A);
	SPI_WriteData(0x7A);
	SPI_WriteData(0x7A);
	SPI_WriteData(0x7A);

	SPI_WriteComm(0x65);
	SPI_WriteData(0x38);
	SPI_WriteData(0x03);
	SPI_WriteData(0x01);
	SPI_WriteData(0xdd);
	SPI_WriteData(0x03);
	SPI_WriteData(0x03);
	SPI_WriteData(0x38);
	SPI_WriteData(0x02);
	SPI_WriteData(0x01);
	SPI_WriteData(0xde);
	SPI_WriteData(0x03);
	SPI_WriteData(0x03);
	SPI_WriteData(0x7A);
	SPI_WriteData(0x7A);
	SPI_WriteData(0x7A);
	SPI_WriteData(0x7A);

	SPI_WriteComm(0x66);
	SPI_WriteData(0x38);
	SPI_WriteData(0x01);
	SPI_WriteData(0x01);
	SPI_WriteData(0xdf);
	SPI_WriteData(0x03);
	SPI_WriteData(0x03);
	SPI_WriteData(0x38);
	SPI_WriteData(0x00);
	SPI_WriteData(0x01);
	SPI_WriteData(0xe0);
	SPI_WriteData(0x03);
	SPI_WriteData(0x03);
	SPI_WriteData(0x7A);
	SPI_WriteData(0x7A);
	SPI_WriteData(0x7A);
	SPI_WriteData(0x7A);

	SPI_WriteComm(0x67);
	SPI_WriteData(0x30);
	SPI_WriteData(0x01);
	SPI_WriteData(0x01);
	SPI_WriteData(0xe1);
	SPI_WriteData(0x03);
	SPI_WriteData(0x03);
	SPI_WriteData(0x30);
	SPI_WriteData(0x02);
	SPI_WriteData(0x01);
	SPI_WriteData(0xe2);
	SPI_WriteData(0x03);
	SPI_WriteData(0x03);
	SPI_WriteData(0x7A);
	SPI_WriteData(0x7A);
	SPI_WriteData(0x7A);
	SPI_WriteData(0x7A);

	SPI_WriteComm(0x68);
	SPI_WriteData(0x00);
	SPI_WriteData(0x08);
	SPI_WriteData(0x15);
	SPI_WriteData(0x08);
	SPI_WriteData(0x15);
	SPI_WriteData(0x7A);
	SPI_WriteData(0x7A);
	SPI_WriteData(0x08);
	SPI_WriteData(0x15);
	SPI_WriteData(0x08);
	SPI_WriteData(0x15);
	SPI_WriteData(0x7A);
	SPI_WriteData(0x7A);

	SPI_WriteComm(0x60);
	SPI_WriteData(0x38);
	SPI_WriteData(0x08);
	SPI_WriteData(0x7A);
	SPI_WriteData(0x7A);
	SPI_WriteData(0x38);
	SPI_WriteData(0x09);
	SPI_WriteData(0x7A);
	SPI_WriteData(0x7A);

	SPI_WriteComm(0x63);
	SPI_WriteData(0x31);
	SPI_WriteData(0xe4);
	SPI_WriteData(0x7A);
	SPI_WriteData(0x7A);
	SPI_WriteData(0x31);
	SPI_WriteData(0xe5);
	SPI_WriteData(0x7A);
	SPI_WriteData(0x7A);

	SPI_WriteComm(0x69);
	SPI_WriteData(0x04);
	SPI_WriteData(0x22);
	SPI_WriteData(0x14);
	SPI_WriteData(0x22);
	SPI_WriteData(0x14);
	SPI_WriteData(0x22);
	SPI_WriteData(0x08);

	SPI_WriteComm(0x6B);
	SPI_WriteData(0x07);

	SPI_WriteComm(0x7A);
	SPI_WriteData(0x08);
	SPI_WriteData(0x13);

	SPI_WriteComm(0x7B);
	SPI_WriteData(0x08);
	SPI_WriteData(0x13);

	SPI_WriteComm(0xD1);
	SPI_WriteData(0x00);
	SPI_WriteData(0x00);
	SPI_WriteData(0x00);
	SPI_WriteData(0x04);
	SPI_WriteData(0x00);
	SPI_WriteData(0x12);
	SPI_WriteData(0x00);
	SPI_WriteData(0x18);
	SPI_WriteData(0x00);
	SPI_WriteData(0x21);
	SPI_WriteData(0x00);
	SPI_WriteData(0x2a);
	SPI_WriteData(0x00);
	SPI_WriteData(0x35);
	SPI_WriteData(0x00);
	SPI_WriteData(0x47);
	SPI_WriteData(0x00);
	SPI_WriteData(0x56);
	SPI_WriteData(0x00);
	SPI_WriteData(0x90);
	SPI_WriteData(0x00);
	SPI_WriteData(0xe5);
	SPI_WriteData(0x01);
	SPI_WriteData(0x68);
	SPI_WriteData(0x01);
	SPI_WriteData(0xd5);
	SPI_WriteData(0x01);
	SPI_WriteData(0xd7);
	SPI_WriteData(0x02);
	SPI_WriteData(0x36);
	SPI_WriteData(0x02);
	SPI_WriteData(0xa6);
	SPI_WriteData(0x02);
	SPI_WriteData(0xee);
	SPI_WriteData(0x03);
	SPI_WriteData(0x48);
	SPI_WriteData(0x03);
	SPI_WriteData(0xa0);
	SPI_WriteData(0x03);
	SPI_WriteData(0xba);
	SPI_WriteData(0x03);
	SPI_WriteData(0xc5);
	SPI_WriteData(0x03);
	SPI_WriteData(0xd0);
	SPI_WriteData(0x03);
	SPI_WriteData(0xE0);
	SPI_WriteData(0x03);
	SPI_WriteData(0xea);
	SPI_WriteData(0x03);
	SPI_WriteData(0xFa);
	SPI_WriteData(0x03);
	SPI_WriteData(0xFF);

	SPI_WriteComm(0xD2);
	SPI_WriteData(0x00);
	SPI_WriteData(0x00);
	SPI_WriteData(0x00);
	SPI_WriteData(0x04);
	SPI_WriteData(0x00);
	SPI_WriteData(0x12);
	SPI_WriteData(0x00);
	SPI_WriteData(0x18);
	SPI_WriteData(0x00);
	SPI_WriteData(0x21);
	SPI_WriteData(0x00);
	SPI_WriteData(0x2a);
	SPI_WriteData(0x00);
	SPI_WriteData(0x35);
	SPI_WriteData(0x00);
	SPI_WriteData(0x47);
	SPI_WriteData(0x00);
	SPI_WriteData(0x56);
	SPI_WriteData(0x00);
	SPI_WriteData(0x90);
	SPI_WriteData(0x00);
	SPI_WriteData(0xe5);
	SPI_WriteData(0x01);
	SPI_WriteData(0x68);
	SPI_WriteData(0x01);
	SPI_WriteData(0xd5);
	SPI_WriteData(0x01);
	SPI_WriteData(0xd7);
	SPI_WriteData(0x02);
	SPI_WriteData(0x36);
	SPI_WriteData(0x02);
	SPI_WriteData(0xa6);
	SPI_WriteData(0x02);
	SPI_WriteData(0xee);
	SPI_WriteData(0x03);
	SPI_WriteData(0x48);
	SPI_WriteData(0x03);
	SPI_WriteData(0xa0);
	SPI_WriteData(0x03);
	SPI_WriteData(0xba);
	SPI_WriteData(0x03);
	SPI_WriteData(0xc5);
	SPI_WriteData(0x03);
	SPI_WriteData(0xd0);
	SPI_WriteData(0x03);
	SPI_WriteData(0xE0);
	SPI_WriteData(0x03);
	SPI_WriteData(0xea);
	SPI_WriteData(0x03);
	SPI_WriteData(0xFa);
	SPI_WriteData(0x03);
	SPI_WriteData(0xFF);

	SPI_WriteComm(0xD3);
	SPI_WriteData(0x00);
	SPI_WriteData(0x00);
	SPI_WriteData(0x00);
	SPI_WriteData(0x04);
	SPI_WriteData(0x00);
	SPI_WriteData(0x12);
	SPI_WriteData(0x00);
	SPI_WriteData(0x18);
	SPI_WriteData(0x00);
	SPI_WriteData(0x21);
	SPI_WriteData(0x00);
	SPI_WriteData(0x2a);
	SPI_WriteData(0x00);
	SPI_WriteData(0x35);
	SPI_WriteData(0x00);
	SPI_WriteData(0x47);
	SPI_WriteData(0x00);
	SPI_WriteData(0x56);
	SPI_WriteData(0x00);
	SPI_WriteData(0x90);
	SPI_WriteData(0x00);
	SPI_WriteData(0xe5);
	SPI_WriteData(0x01);
	SPI_WriteData(0x68);
	SPI_WriteData(0x01);
	SPI_WriteData(0xd5);
	SPI_WriteData(0x01);
	SPI_WriteData(0xd7);
	SPI_WriteData(0x02);
	SPI_WriteData(0x36);
	SPI_WriteData(0x02);
	SPI_WriteData(0xa6);
	SPI_WriteData(0x02);
	SPI_WriteData(0xee);
	SPI_WriteData(0x03);
	SPI_WriteData(0x48);
	SPI_WriteData(0x03);
	SPI_WriteData(0xa0);
	SPI_WriteData(0x03);
	SPI_WriteData(0xba);
	SPI_WriteData(0x03);
	SPI_WriteData(0xc5);
	SPI_WriteData(0x03);
	SPI_WriteData(0xd0);
	SPI_WriteData(0x03);
	SPI_WriteData(0xE0);
	SPI_WriteData(0x03);
	SPI_WriteData(0xea);
	SPI_WriteData(0x03);
	SPI_WriteData(0xFa);
	SPI_WriteData(0x03);
	SPI_WriteData(0xFF);

	SPI_WriteComm(0xD4);
	SPI_WriteData(0x00);
	SPI_WriteData(0x00);
	SPI_WriteData(0x00);
	SPI_WriteData(0x04);
	SPI_WriteData(0x00);
	SPI_WriteData(0x12);
	SPI_WriteData(0x00);
	SPI_WriteData(0x18);
	SPI_WriteData(0x00);
	SPI_WriteData(0x21);
	SPI_WriteData(0x00);
	SPI_WriteData(0x2a);
	SPI_WriteData(0x00);
	SPI_WriteData(0x35);
	SPI_WriteData(0x00);
	SPI_WriteData(0x47);
	SPI_WriteData(0x00);
	SPI_WriteData(0x56);
	SPI_WriteData(0x00);
	SPI_WriteData(0x90);
	SPI_WriteData(0x00);
	SPI_WriteData(0xe5);
	SPI_WriteData(0x01);
	SPI_WriteData(0x68);
	SPI_WriteData(0x01);
	SPI_WriteData(0xd5);
	SPI_WriteData(0x01);
	SPI_WriteData(0xd7);
	SPI_WriteData(0x02);
	SPI_WriteData(0x36);
	SPI_WriteData(0x02);
	SPI_WriteData(0xa6);
	SPI_WriteData(0x02);
	SPI_WriteData(0xee);
	SPI_WriteData(0x03);
	SPI_WriteData(0x48);
	SPI_WriteData(0x03);
	SPI_WriteData(0xa0);
	SPI_WriteData(0x03);
	SPI_WriteData(0xba);
	SPI_WriteData(0x03);
	SPI_WriteData(0xc5);
	SPI_WriteData(0x03);
	SPI_WriteData(0xd0);
	SPI_WriteData(0x03);
	SPI_WriteData(0xE0);
	SPI_WriteData(0x03);
	SPI_WriteData(0xea);
	SPI_WriteData(0x03);
	SPI_WriteData(0xFa);
	SPI_WriteData(0x03);
	SPI_WriteData(0xFF);

	SPI_WriteComm(0xD5);
	SPI_WriteData(0x00);
	SPI_WriteData(0x00);
	SPI_WriteData(0x00);
	SPI_WriteData(0x04);
	SPI_WriteData(0x00);
	SPI_WriteData(0x12);
	SPI_WriteData(0x00);
	SPI_WriteData(0x18);
	SPI_WriteData(0x00);
	SPI_WriteData(0x21);
	SPI_WriteData(0x00);
	SPI_WriteData(0x2a);
	SPI_WriteData(0x00);
	SPI_WriteData(0x35);
	SPI_WriteData(0x00);
	SPI_WriteData(0x47);
	SPI_WriteData(0x00);
	SPI_WriteData(0x56);
	SPI_WriteData(0x00);
	SPI_WriteData(0x90);
	SPI_WriteData(0x00);
	SPI_WriteData(0xe5);
	SPI_WriteData(0x01);
	SPI_WriteData(0x68);
	SPI_WriteData(0x01);
	SPI_WriteData(0xd5);
	SPI_WriteData(0x01);
	SPI_WriteData(0xd7);
	SPI_WriteData(0x02);
	SPI_WriteData(0x36);
	SPI_WriteData(0x02);
	SPI_WriteData(0xa6);
	SPI_WriteData(0x02);
	SPI_WriteData(0xee);
	SPI_WriteData(0x03);
	SPI_WriteData(0x48);
	SPI_WriteData(0x03);
	SPI_WriteData(0xa0);
	SPI_WriteData(0x03);
	SPI_WriteData(0xba);
	SPI_WriteData(0x03);
	SPI_WriteData(0xc5);
	SPI_WriteData(0x03);
	SPI_WriteData(0xd0);
	SPI_WriteData(0x03);
	SPI_WriteData(0xE0);
	SPI_WriteData(0x03);
	SPI_WriteData(0xea);
	SPI_WriteData(0x03);
	SPI_WriteData(0xFa);
	SPI_WriteData(0x03);
	SPI_WriteData(0xFF);

	SPI_WriteComm(0xD6);
	SPI_WriteData(0x00);
	SPI_WriteData(0x00);
	SPI_WriteData(0x00);
	SPI_WriteData(0x04);
	SPI_WriteData(0x00);
	SPI_WriteData(0x12);
	SPI_WriteData(0x00);
	SPI_WriteData(0x18);
	SPI_WriteData(0x00);
	SPI_WriteData(0x21);
	SPI_WriteData(0x00);
	SPI_WriteData(0x2a);
	SPI_WriteData(0x00);
	SPI_WriteData(0x35);
	SPI_WriteData(0x00);
	SPI_WriteData(0x47);
	SPI_WriteData(0x00);
	SPI_WriteData(0x56);
	SPI_WriteData(0x00);
	SPI_WriteData(0x90);
	SPI_WriteData(0x00);
	SPI_WriteData(0xe5);
	SPI_WriteData(0x01);
	SPI_WriteData(0x68);
	SPI_WriteData(0x01);
	SPI_WriteData(0xd5);
	SPI_WriteData(0x01);
	SPI_WriteData(0xd7);
	SPI_WriteData(0x02);
	SPI_WriteData(0x36);
	SPI_WriteData(0x02);
	SPI_WriteData(0xa6);
	SPI_WriteData(0x02);
	SPI_WriteData(0xee);
	SPI_WriteData(0x03);
	SPI_WriteData(0x48);
	SPI_WriteData(0x03);
	SPI_WriteData(0xa0);
	SPI_WriteData(0x03);
	SPI_WriteData(0xba);
	SPI_WriteData(0x03);
	SPI_WriteData(0xc5);
	SPI_WriteData(0x03);
	SPI_WriteData(0xd0);
	SPI_WriteData(0x03);
	SPI_WriteData(0xE0);
	SPI_WriteData(0x03);
	SPI_WriteData(0xea);
	SPI_WriteData(0x03);
	SPI_WriteData(0xFa);
	SPI_WriteData(0x03);
	SPI_WriteData(0xFF);

	SPI_WriteComm(0x3a);
	SPI_WriteData(0x66);

	SPI_WriteComm(0x11);
	vTaskDelay(pdMS_TO_TICKS(200));
	SPI_WriteComm(0x29);
}

void qmsd_rgb_spi_init() {
    spi_bus_config_t buscfg = {
        .sclk_io_num = LCD_SPI_CLK,
        .mosi_io_num = LCD_SPI_DATA0,
        .miso_io_num = -1,
        .quadwp_io_num = -1,
        .quadhd_io_num = -1,
        .max_transfer_sz = 10 * 1024,
    };
    ESP_ERROR_CHECK(spi_bus_initialize(SPI2_HOST, &buscfg, SPI_DMA_CH_AUTO));

    spi_device_interface_config_t devcfg = {
        .clock_speed_hz = SPI_MASTER_FREQ_10M,   //Clock out at 10 MHz
        .mode = 0,                               //SPI mode 0
        .spics_io_num = LCD_SPI_CS,              //CS pin
        .queue_size = 7,                         //We want to be able to queue 7 transactions at a time
    };
    
    ESP_ERROR_CHECK(spi_bus_add_device(SPI2_HOST, &devcfg, &g_screen_spi));
    rgb_driver_init();

	spi_bus_remove_device(g_screen_spi);
	spi_bus_free(SPI2_HOST);
}
