#include <sdkconfig.h>
#ifdef CONFIG_ZX480_S3ZW2
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

static spi_device_handle_t st7701s_spi;

static void st7701s_send_16_cmd(uint16_t cmd)
{
    uint16_t tmp_cmd = ((cmd >> 8) | 0x2000);;
    spi_transaction_ext_t trans = (spi_transaction_ext_t)
    {
        .base =
        {
            .flags = SPI_TRANS_VARIABLE_CMD,
            .cmd = tmp_cmd,
        },
        .command_bits = 16,
    };
    spi_device_transmit(st7701s_spi, (spi_transaction_t *)&trans);

    tmp_cmd = ((cmd & 0xff) | 0x0000);
    trans.base.cmd = tmp_cmd;
    spi_device_transmit(st7701s_spi, (spi_transaction_t *)&trans);
}

static void st7701s_send_16_data(uint16_t data)
{
    uint16_t tmp_data = (data | 0x4000);
    spi_transaction_ext_t trans = (spi_transaction_ext_t){
        .base = {
            .flags = SPI_TRANS_VARIABLE_CMD,
            .cmd = tmp_data,
        },
        .command_bits = 16,
    };
    spi_device_transmit(st7701s_spi, (spi_transaction_t *)&trans);
}

static void st7701s_init(void)
{
    st7701s_send_16_cmd(0x1100); //Software reset
	vTaskDelay(300 / portTICK_RATE_MS);

	//---------------------------------------Bank0 Setting-------------------------------------------------//
	//------------------------------------Display Control setting----------------------------------------------//
	st7701s_send_16_cmd(0xFF00); st7701s_send_16_data(0x77);
	st7701s_send_16_cmd(0xFF01); st7701s_send_16_data(0x01);
	st7701s_send_16_cmd(0xFF02); st7701s_send_16_data(0x00);
	st7701s_send_16_cmd(0xFF03); st7701s_send_16_data(0x00);
	st7701s_send_16_cmd(0xFF04); st7701s_send_16_data(0x10);

	st7701s_send_16_cmd(0xC000); st7701s_send_16_data(0x3B);
	st7701s_send_16_cmd(0xC001); st7701s_send_16_data(0x00);

    st7701s_send_16_cmd(0xC100); st7701s_send_16_data(0x0D);
    st7701s_send_16_cmd(0xC101); st7701s_send_16_data(0x02);

	st7701s_send_16_cmd(0xC200); st7701s_send_16_data(0x21);
	st7701s_send_16_cmd(0xC201); st7701s_send_16_data(0x08);
	
	st7701s_send_16_cmd(0xB000); st7701s_send_16_data(0x00);
	st7701s_send_16_cmd(0xB001); st7701s_send_16_data(0x11);
	st7701s_send_16_cmd(0xB002); st7701s_send_16_data(0x18);
	st7701s_send_16_cmd(0xB003); st7701s_send_16_data(0x0D);
	st7701s_send_16_cmd(0xB004); st7701s_send_16_data(0x11);
	st7701s_send_16_cmd(0xB005); st7701s_send_16_data(0x06);
	st7701s_send_16_cmd(0xB006); st7701s_send_16_data(0x07);
	st7701s_send_16_cmd(0xB007); st7701s_send_16_data(0x08);
	st7701s_send_16_cmd(0xB008); st7701s_send_16_data(0x07);
	st7701s_send_16_cmd(0xB009); st7701s_send_16_data(0x22);
	st7701s_send_16_cmd(0xB00A); st7701s_send_16_data(0x04);
	st7701s_send_16_cmd(0xB00B); st7701s_send_16_data(0x12);
	st7701s_send_16_cmd(0xB00C); st7701s_send_16_data(0x0F);
	st7701s_send_16_cmd(0xB00D); st7701s_send_16_data(0xAA);
	st7701s_send_16_cmd(0xB00E); st7701s_send_16_data(0x31);
	st7701s_send_16_cmd(0xB00F); st7701s_send_16_data(0x18);

	st7701s_send_16_cmd(0xB100); st7701s_send_16_data(0x00);
	st7701s_send_16_cmd(0xB101); st7701s_send_16_data(0x11);
	st7701s_send_16_cmd(0xB102); st7701s_send_16_data(0x19);
	st7701s_send_16_cmd(0xB103); st7701s_send_16_data(0x0E);
	st7701s_send_16_cmd(0xB104); st7701s_send_16_data(0x12);
	st7701s_send_16_cmd(0xB105); st7701s_send_16_data(0x07);
	st7701s_send_16_cmd(0xB106); st7701s_send_16_data(0x08);
	st7701s_send_16_cmd(0xB107); st7701s_send_16_data(0x08);
	st7701s_send_16_cmd(0xB108); st7701s_send_16_data(0x08);
	st7701s_send_16_cmd(0xB109); st7701s_send_16_data(0x22);
	st7701s_send_16_cmd(0xB10A); st7701s_send_16_data(0x04);
	st7701s_send_16_cmd(0xB10B); st7701s_send_16_data(0x11);
	st7701s_send_16_cmd(0xB10C); st7701s_send_16_data(0x11);
	st7701s_send_16_cmd(0xB10D); st7701s_send_16_data(0xA9);
	st7701s_send_16_cmd(0xB10E); st7701s_send_16_data(0x32);
	st7701s_send_16_cmd(0xB10F); st7701s_send_16_data(0x18);

	st7701s_send_16_cmd(0xFF00); st7701s_send_16_data(0x77);
	st7701s_send_16_cmd(0xFF01); st7701s_send_16_data(0x01);
	st7701s_send_16_cmd(0xFF02); st7701s_send_16_data(0x00);
	st7701s_send_16_cmd(0xFF03); st7701s_send_16_data(0x00);
	st7701s_send_16_cmd(0xFF04); st7701s_send_16_data(0x11);

	st7701s_send_16_cmd(0xB000); st7701s_send_16_data(0x60);
	st7701s_send_16_cmd(0xB100); st7701s_send_16_data(0x30);
	st7701s_send_16_cmd(0xB200); st7701s_send_16_data(0x87);
	st7701s_send_16_cmd(0xB300); st7701s_send_16_data(0x80);
	st7701s_send_16_cmd(0xB500); st7701s_send_16_data(0x49);
	st7701s_send_16_cmd(0xB700); st7701s_send_16_data(0x85);
	st7701s_send_16_cmd(0xB800); st7701s_send_16_data(0x21);

	//st7701s_send_16_cmd(0xB900);st7701s_send_16_data(0x10);
	st7701s_send_16_cmd(0xC100); st7701s_send_16_data(0x78);
	st7701s_send_16_cmd(0xC200); st7701s_send_16_data(0x78);
	vTaskDelay(100 / portTICK_RATE_MS);

	//---------------------------------------------GIP Setting----------------------------------------------------//
	st7701s_send_16_cmd(0xE000); st7701s_send_16_data(0x00);
	st7701s_send_16_cmd(0xE001); st7701s_send_16_data(0x1B);
	st7701s_send_16_cmd(0xE002); st7701s_send_16_data(0x02);
	
	st7701s_send_16_cmd(0xE100); st7701s_send_16_data(0x08);
	st7701s_send_16_cmd(0xE101); st7701s_send_16_data(0xA0);
	st7701s_send_16_cmd(0xE102); st7701s_send_16_data(0x00);
	st7701s_send_16_cmd(0xE103); st7701s_send_16_data(0x00);
	st7701s_send_16_cmd(0xE104); st7701s_send_16_data(0x07);
	st7701s_send_16_cmd(0xE105); st7701s_send_16_data(0xA0);
	st7701s_send_16_cmd(0xE106); st7701s_send_16_data(0x00);
	st7701s_send_16_cmd(0xE107); st7701s_send_16_data(0x00);
	st7701s_send_16_cmd(0xE108); st7701s_send_16_data(0x00);
	st7701s_send_16_cmd(0xE109); st7701s_send_16_data(0x44);
	st7701s_send_16_cmd(0xE10A); st7701s_send_16_data(0x44);

	st7701s_send_16_cmd(0xE200); st7701s_send_16_data(0x11);
	st7701s_send_16_cmd(0xE201); st7701s_send_16_data(0x11);
	st7701s_send_16_cmd(0xE202); st7701s_send_16_data(0x44);
	st7701s_send_16_cmd(0xE203); st7701s_send_16_data(0x44);
	st7701s_send_16_cmd(0xE204); st7701s_send_16_data(0xED);
	st7701s_send_16_cmd(0xE205); st7701s_send_16_data(0xA0);
	st7701s_send_16_cmd(0xE206); st7701s_send_16_data(0x00);
	st7701s_send_16_cmd(0xE207); st7701s_send_16_data(0x00);
	st7701s_send_16_cmd(0xE208); st7701s_send_16_data(0xEC);
	st7701s_send_16_cmd(0xE209); st7701s_send_16_data(0xA0);
	st7701s_send_16_cmd(0xE20A); st7701s_send_16_data(0x00);
	st7701s_send_16_cmd(0xE20B); st7701s_send_16_data(0x00);
	//st7701s_send_16_cmd(0xE20C);st7701s_send_16_data(0x00);
	 //**********************************//
	st7701s_send_16_cmd(0xE300); st7701s_send_16_data(0x00);
	st7701s_send_16_cmd(0xE301); st7701s_send_16_data(0x00);
	st7701s_send_16_cmd(0xE302); st7701s_send_16_data(0x11);
	st7701s_send_16_cmd(0xE303); st7701s_send_16_data(0x11);
	
	st7701s_send_16_cmd(0xE400); st7701s_send_16_data(0x44);
	st7701s_send_16_cmd(0xE401); st7701s_send_16_data(0x44);
	
	st7701s_send_16_cmd(0xE500); st7701s_send_16_data(0x0A);
	st7701s_send_16_cmd(0xE501); st7701s_send_16_data(0xE9);
	st7701s_send_16_cmd(0xE502); st7701s_send_16_data(0xD8);
	st7701s_send_16_cmd(0xE503); st7701s_send_16_data(0xA0);
	st7701s_send_16_cmd(0xE504); st7701s_send_16_data(0x0C);
	st7701s_send_16_cmd(0xE505); st7701s_send_16_data(0xEB);
	st7701s_send_16_cmd(0xE506); st7701s_send_16_data(0xD8);
	st7701s_send_16_cmd(0xE507); st7701s_send_16_data(0xA0);
	st7701s_send_16_cmd(0xE508); st7701s_send_16_data(0x0E);
	st7701s_send_16_cmd(0xE509); st7701s_send_16_data(0xED);
	st7701s_send_16_cmd(0xE50A); st7701s_send_16_data(0xD8);
	st7701s_send_16_cmd(0xE50B); st7701s_send_16_data(0xA0);
	st7701s_send_16_cmd(0xE50C); st7701s_send_16_data(0x10);
	st7701s_send_16_cmd(0xE50D); st7701s_send_16_data(0xEF);
	st7701s_send_16_cmd(0xE50E); st7701s_send_16_data(0xD8);
	st7701s_send_16_cmd(0xE50F); st7701s_send_16_data(0xA0);
	
	st7701s_send_16_cmd(0xE600); st7701s_send_16_data(0x00);
	st7701s_send_16_cmd(0xE601); st7701s_send_16_data(0x00);
	st7701s_send_16_cmd(0xE602); st7701s_send_16_data(0x11);
	st7701s_send_16_cmd(0xE603); st7701s_send_16_data(0x11);
	
	st7701s_send_16_cmd(0xE700); st7701s_send_16_data(0x44);
	st7701s_send_16_cmd(0xE701); st7701s_send_16_data(0x44);
	
	st7701s_send_16_cmd(0xE800); st7701s_send_16_data(0x09);
	st7701s_send_16_cmd(0xE801); st7701s_send_16_data(0xE8);
	st7701s_send_16_cmd(0xE802); st7701s_send_16_data(0xD8);
	st7701s_send_16_cmd(0xE803); st7701s_send_16_data(0xA0);
	st7701s_send_16_cmd(0xE804); st7701s_send_16_data(0x0B);
	st7701s_send_16_cmd(0xE805); st7701s_send_16_data(0xEA);
	st7701s_send_16_cmd(0xE806); st7701s_send_16_data(0xD8);
	st7701s_send_16_cmd(0xE807); st7701s_send_16_data(0xA0);
	st7701s_send_16_cmd(0xE808); st7701s_send_16_data(0x0D);
	st7701s_send_16_cmd(0xE809); st7701s_send_16_data(0xEC);
	st7701s_send_16_cmd(0xE80A); st7701s_send_16_data(0xD8);
	st7701s_send_16_cmd(0xE80B); st7701s_send_16_data(0xA0);
	st7701s_send_16_cmd(0xE80C); st7701s_send_16_data(0x0F);
	st7701s_send_16_cmd(0xE80D); st7701s_send_16_data(0xEE);
	st7701s_send_16_cmd(0xE80E); st7701s_send_16_data(0xD8);
	st7701s_send_16_cmd(0xE80F); st7701s_send_16_data(0xA0);
	
	st7701s_send_16_cmd(0xEB00); st7701s_send_16_data(0x02);
	st7701s_send_16_cmd(0xEB01); st7701s_send_16_data(0x00);
	st7701s_send_16_cmd(0xEB02); st7701s_send_16_data(0xE4);
	st7701s_send_16_cmd(0xEB03); st7701s_send_16_data(0xE4);
	st7701s_send_16_cmd(0xEB04); st7701s_send_16_data(0x88);
	st7701s_send_16_cmd(0xEB05); st7701s_send_16_data(0x00);
	st7701s_send_16_cmd(0xEB06); st7701s_send_16_data(0x40);
	
	st7701s_send_16_cmd(0xEC00); st7701s_send_16_data(0x3C);
	st7701s_send_16_cmd(0xEC01); st7701s_send_16_data(0x00);
	
	st7701s_send_16_cmd(0xED00); st7701s_send_16_data(0xAB);
	st7701s_send_16_cmd(0xED01); st7701s_send_16_data(0x89);
	st7701s_send_16_cmd(0xED02); st7701s_send_16_data(0x76);
	st7701s_send_16_cmd(0xED03); st7701s_send_16_data(0x54);
	st7701s_send_16_cmd(0xED04); st7701s_send_16_data(0x02);
	st7701s_send_16_cmd(0xED05); st7701s_send_16_data(0xFF);
	st7701s_send_16_cmd(0xED06); st7701s_send_16_data(0xFF);
	st7701s_send_16_cmd(0xED07); st7701s_send_16_data(0xFF);
	st7701s_send_16_cmd(0xED08); st7701s_send_16_data(0xFF);
	st7701s_send_16_cmd(0xED09); st7701s_send_16_data(0xFF);
	st7701s_send_16_cmd(0xED0A); st7701s_send_16_data(0xFF);
	st7701s_send_16_cmd(0xED0B); st7701s_send_16_data(0x20);
	st7701s_send_16_cmd(0xED0C); st7701s_send_16_data(0x45);
	st7701s_send_16_cmd(0xED0D); st7701s_send_16_data(0x67);
	st7701s_send_16_cmd(0xED0E); st7701s_send_16_data(0x98);
	st7701s_send_16_cmd(0xED0F); st7701s_send_16_data(0xBA);

	//--------------------------------------------End GIP Setting-----------------------------------------------//
	//------------------------------ Power Control Registers Initial End-----------------------------------//
	//------------------------------------------Bank1 Setting----------------------------------------------------//
	st7701s_send_16_cmd(0xFF00); st7701s_send_16_data(0x77);
	st7701s_send_16_cmd(0xFF01); st7701s_send_16_data(0x01);
	st7701s_send_16_cmd(0xFF02); st7701s_send_16_data(0x00);
	st7701s_send_16_cmd(0xFF03); st7701s_send_16_data(0x00);
	st7701s_send_16_cmd(0xFF04); st7701s_send_16_data(0x00);
	

	st7701s_send_16_cmd(0x3A00); st7701s_send_16_data(0x66);
	//st7701s_send_16_cmd(0x3600); st7701s_send_16_data(0x08);	//08
	
	st7701s_send_16_cmd(0x1100);
	vTaskDelay(500 / portTICK_RATE_MS);
	st7701s_send_16_cmd(0x2900);
	vTaskDelay(50 / portTICK_RATE_MS); 
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
    
    ESP_ERROR_CHECK(spi_bus_add_device(SPI2_HOST, &devcfg, &st7701s_spi));

    st7701s_init();
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

    ESP_ERROR_CHECK(gpio_set_level(LCD_PIN_RST, 0));
    vTaskDelay(pdMS_TO_TICKS(20));
    ESP_ERROR_CHECK(gpio_set_level(LCD_PIN_RST, 1));
    vTaskDelay(pdMS_TO_TICKS(20));

    qmsd_spi_init(LCD_PIN_CS, LCD_PIN_PCLK, LCD_PIN_DATA0);

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
            .pclk_hz = 15000000,
            .h_res = 480,
            .v_res = 480,
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
        .clk_src = LCD_CLK_SRC_PLL240M,
    };

    qmsd_rgb_init(&panel_config);

    ESP_ERROR_CHECK(gpio_set_level(LCD_PIN_BK_LIGHT, LCD_BK_LIGHT_ON_LEVEL));
}
#endif