#include <sdkconfig.h>
#ifdef CONFIG_ZX2D10GE01R_V_4848
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
#include "button.h"
#include "mt8901.h"
#include "qmsd_board_init.h"

#define TAG "QMSD BOARD INIT"

#define DEVICE_RST (-1)

// RGB interface
#define LCD_PCLK_GPIO (45)
#define LCD_VSYNC_GPIO (48)
#define LCD_HSYNC_GPIO (40)
#define LCD_DE_GPIO (39)
#define LCD_DATA0_GPIO (47)	 // B0
#define LCD_DATA1_GPIO (41)	 // B1
#define LCD_DATA2_GPIO (0)	 // B2
#define LCD_DATA3_GPIO (42)	 // B3
#define LCD_DATA4_GPIO (14)	 // B4
#define LCD_DATA5_GPIO (8)	 // G0
#define LCD_DATA6_GPIO (13)	 // G1
#define LCD_DATA7_GPIO (18)	 // G2
#define LCD_DATA8_GPIO (12)	 // G3
#define LCD_DATA9_GPIO (11)	 // G4
#define LCD_DATA10_GPIO (17) // G5
#define LCD_DATA11_GPIO (10) // R0
#define LCD_DATA12_GPIO (16) // R1
#define LCD_DATA13_GPIO (9)	 // R2
#define LCD_DATA14_GPIO (15) // R3
#define LCD_DATA15_GPIO (46) // R4
#define LCD_DISP_EN_GPIO (-1)

#define LCD_PIXEL_CLOCK_HZ (10 * 1000 * 1000)
#define LCD_SPI_DATA0          41  /*!< for 1-line SPI, this also refered as MOSI */
#define LCD_SPI_CLK			47
#define LCD_SPI_CS             21
#define LCD_PIN_DC        -1
#define LCD_PIN_BK_LIGHT  38

#define LCD_BK_LIGHT_ON_LEVEL  1
#define LCD_BK_LIGHT_OFF_LEVEL !LCD_BK_LIGHT_ON_LEVEL

#define ECO_O(y) (y>0)? -1:1
#define ECO_STEP(x) x? ECO_O(x):0

static button_t *g_btn;
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
	SPI_WriteComm(0xFF);
	SPI_WriteData(0x77);
	SPI_WriteData(0x01);
	SPI_WriteData(0x00);
	SPI_WriteData(0x00);
	SPI_WriteData(0x10);

	SPI_WriteComm(0xC0);
	SPI_WriteData(0x3B); //Scan line	
	SPI_WriteData(0x00);

	SPI_WriteComm(0xC1);
	SPI_WriteData(0x0B);	//VBP
	SPI_WriteData(0x02);

	SPI_WriteComm(0xC2);
	SPI_WriteData(0x07);
	SPI_WriteData(0x02);

	SPI_WriteComm(0xCC);
	SPI_WriteData(0x10);

	SPI_WriteComm(0xCD);//RGB format
	SPI_WriteData(0x08);

	SPI_WriteComm(0xB0); // IPS   
	SPI_WriteData(0x00); // 255 
	SPI_WriteData(0x11); // 251    
	SPI_WriteData(0x16); // 247  down
	SPI_WriteData(0x0e); // 239    
	SPI_WriteData(0x11); // 231    
	SPI_WriteData(0x06); // 203    
	SPI_WriteData(0x05); // 175 
	SPI_WriteData(0x09); // 147    
	SPI_WriteData(0x08); // 108    
	SPI_WriteData(0x21); // 80  
	SPI_WriteData(0x06); // 52   
	SPI_WriteData(0x13); // 24    
	SPI_WriteData(0x10); // 16    
	SPI_WriteData(0x29); // 8    down
	SPI_WriteData(0x31); // 4    
	SPI_WriteData(0x18); // 0   

	SPI_WriteComm(0xB1);//  IPS	   
	SPI_WriteData(0x00);//  255 
	SPI_WriteData(0x11);//  251
	SPI_WriteData(0x16);//  247   down
	SPI_WriteData(0x0e);//  239
	SPI_WriteData(0x11);//  231
	SPI_WriteData(0x07);//  203    
	SPI_WriteData(0x05);//  175
	SPI_WriteData(0x09);//  147  
	SPI_WriteData(0x09);//  108  
	SPI_WriteData(0x21);//  80 
	SPI_WriteData(0x05);//  52   
	SPI_WriteData(0x13);//  24 
	SPI_WriteData(0x11);//  16 
	SPI_WriteData(0x2a);//  8  down 
	SPI_WriteData(0x31);//  4  
	SPI_WriteData(0x18);//  0  

	SPI_WriteComm(0xFF);
	SPI_WriteData(0x77);
	SPI_WriteData(0x01);
	SPI_WriteData(0x00);
	SPI_WriteData(0x00);
	SPI_WriteData(0x11);

	SPI_WriteComm(0xB0);  //VOP  3.5375+ *x 0.0125
	SPI_WriteData(0x6d);  //5D
	
	SPI_WriteComm(0xB1); 	//VCOM amplitude setting  
	SPI_WriteData(0x37);  //
	
	SPI_WriteComm(0xB2); 	//VGH Voltage setting  
	SPI_WriteData(0x81);	//12V

	SPI_WriteComm(0xB3);
	SPI_WriteData(0x80);

	SPI_WriteComm(0xB5); 	//VGL Voltage setting  
	SPI_WriteData(0x43);	//-8.3V

	SPI_WriteComm(0xB7);
	SPI_WriteData(0x85);

	SPI_WriteComm(0xB8);
	SPI_WriteData(0x20);

	SPI_WriteComm(0xC1);
	SPI_WriteData(0x78);

	SPI_WriteComm(0xC2);
	SPI_WriteData(0x78);

	SPI_WriteComm(0xD0);
	SPI_WriteData(0x88);

	SPI_WriteComm(0xE0);
	SPI_WriteData(0x00);
	SPI_WriteData(0x00);
	SPI_WriteData(0x02);

	SPI_WriteComm(0xE1);
	SPI_WriteData(0x03);	
	SPI_WriteData(0xA0);
	SPI_WriteData(0x00);	
	SPI_WriteData(0x00);
	SPI_WriteData(0x04);	
	SPI_WriteData(0xA0);
	SPI_WriteData(0x00);	
	SPI_WriteData(0x00);	
	SPI_WriteData(0x00);
	SPI_WriteData(0x20);
	SPI_WriteData(0x20);

	SPI_WriteComm(0xE2);
	SPI_WriteData(0x00);	
	SPI_WriteData(0x00);	  
	SPI_WriteData(0x00);	
	SPI_WriteData(0x00);	
	SPI_WriteData(0x00);	
	SPI_WriteData(0x00);	
	SPI_WriteData(0x00);	
	SPI_WriteData(0x00);	
	SPI_WriteData(0x00);	
	SPI_WriteData(0x00);	
	SPI_WriteData(0x00);	
	SPI_WriteData(0x00);	
	SPI_WriteData(0x00);

	SPI_WriteComm(0xE3);
	SPI_WriteData(0x00);
	SPI_WriteData(0x00);
	SPI_WriteData(0x11);
	SPI_WriteData(0x00);

	SPI_WriteComm(0xE4);
	SPI_WriteData(0x22);
	SPI_WriteData(0x00);

	SPI_WriteComm(0xE5);		
	SPI_WriteData(0x05);	
	SPI_WriteData(0xEC);	
	SPI_WriteData(0xA0);
	SPI_WriteData(0xA0);
	SPI_WriteData(0x07);	
	SPI_WriteData(0xEE);	
	SPI_WriteData(0xA0);
	SPI_WriteData(0xA0);
	SPI_WriteData(0x00);
	SPI_WriteData(0x00);	
	SPI_WriteData(0x00);
	SPI_WriteData(0x00);
	SPI_WriteData(0x00);
	SPI_WriteData(0x00);	
	SPI_WriteData(0x00);
	SPI_WriteData(0x00);

	SPI_WriteComm(0xE6);
	SPI_WriteData(0x00);
	SPI_WriteData(0x00);
	SPI_WriteData(0x11);
	SPI_WriteData(0x00);

	SPI_WriteComm(0xE7);
	SPI_WriteData(0x22);
	SPI_WriteData(0x00);

	SPI_WriteComm(0xE8);		
	SPI_WriteData(0x06);	
	SPI_WriteData(0xED);	
	SPI_WriteData(0xA0);
	SPI_WriteData(0xA0);
	SPI_WriteData(0x08);	
	SPI_WriteData(0xEF);	
	SPI_WriteData(0xA0); 
	SPI_WriteData(0xA0);
	SPI_WriteData(0x00);	
	SPI_WriteData(0x00);	
	SPI_WriteData(0x00);
	SPI_WriteData(0x00);
	SPI_WriteData(0x00);	
	SPI_WriteData(0x00);	
	SPI_WriteData(0x00);
	SPI_WriteData(0x00);

	SPI_WriteComm(0xEB);
	SPI_WriteData(0x00); 	
	SPI_WriteData(0x00);
	SPI_WriteData(0x40);
	SPI_WriteData(0x40);
	SPI_WriteData(0x00);
	SPI_WriteData(0x00);
	SPI_WriteData(0x00);  

	SPI_WriteComm(0xED);  
	SPI_WriteData(0xFF); 
	SPI_WriteData(0xFF);  
	SPI_WriteData(0xFF); 	
	SPI_WriteData(0xBA); 		
	SPI_WriteData(0x0A); 	
	SPI_WriteData(0xBF); 	
	SPI_WriteData(0x45); 	
	SPI_WriteData(0xFF); 
	SPI_WriteData(0xFF);  
	SPI_WriteData(0x54); 	
	SPI_WriteData(0xFB); 	
	SPI_WriteData(0xA0); 	
	SPI_WriteData(0xAB); 	
	SPI_WriteData(0xFF); 
	SPI_WriteData(0xFF); 
	SPI_WriteData(0xFF); 

	SPI_WriteComm(0xEF);
	SPI_WriteData(0x10); 
	SPI_WriteData(0x0D); 
	SPI_WriteData(0x04); 
	SPI_WriteData(0x08); 
	SPI_WriteData(0x3F); 
	SPI_WriteData(0x1F);

	SPI_WriteComm(0xFF);
	SPI_WriteData(0x77);
	SPI_WriteData(0x01);
	SPI_WriteData(0x00);
	SPI_WriteData(0x00);
	SPI_WriteData(0x13);

	SPI_WriteComm(0xEF);
	SPI_WriteData(0x08);

	SPI_WriteComm(0xFF);
	SPI_WriteData(0x77);
	SPI_WriteData(0x01);
	SPI_WriteData(0x00);
	SPI_WriteData(0x00);
	SPI_WriteData(0x00);

	SPI_WriteComm(0x36);
	SPI_WriteData(0x00);

	SPI_WriteComm(0x3a);
	SPI_WriteData(0x66);

	SPI_WriteComm(0x11);

	vTaskDelay(pdMS_TO_TICKS(120));

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

static bool __qmsd_encoder_read(lv_indev_drv_t *drv, lv_indev_data_t *data)
{
    static int16_t cont_last = 0;
    int16_t cont_now = mt8901_get_count();
    data->enc_diff = ECO_STEP(cont_now - cont_last);
    cont_last = cont_now;
    if (button_isPressed(g_btn)){
        data->state = LV_INDEV_STATE_PR;
        return false;
    } else {
        data->state = LV_INDEV_STATE_REL;
        return false;
    }
}

static void __qsmd_encoder_init(void)
{
    lv_indev_drv_t indev_drv;
    lv_indev_t *indev_encoder;

    g_btn = button_attch(3, 1, 10);
    mt8901_init(5,6);

    lv_indev_drv_init(&indev_drv);
    indev_drv.read_cb = __qmsd_encoder_read;
    indev_drv.type = LV_INDEV_TYPE_ENCODER;
    indev_encoder = lv_indev_drv_register(&indev_drv);
}

void qmsd_board_init(qmsd_screen_rotation_t dir)
{
    ESP_LOGI(TAG, "ZX2D10ECS_cESCP01 init");
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
            .pclk_hz = 15000000,
            .h_res = 480,
            .v_res = 480,
            .hsync_pulse_width = 10,
            .hsync_back_porch = 10,
            .hsync_front_porch = 10, 
            .vsync_pulse_width = 2,
            .vsync_back_porch = 12,
            .vsync_front_porch = 14,
        },
        .flags.fb_in_psram = 1,
        .flags.relax_on_idle = 0,
        .flags.double_buffer = 1,
		.bounce_buffer_size_px = 0,
        .clk_src = LCD_CLK_SRC_PLL240M,
    };

	qmsd_rgb_spi_init();

    qmsd_rgb_init(&panel_config);
	//__qsmd_encoder_init();

    ESP_ERROR_CHECK(gpio_set_level(LCD_PIN_BK_LIGHT, LCD_BK_LIGHT_ON_LEVEL));
}
#endif
