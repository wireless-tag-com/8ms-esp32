#include <sdkconfig.h>
#ifdef CONFIG_ZX210_S3MLW1
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
#include "button.h"
#include "mt8901.h"
#include "../qmsd_board_init.h"

#define TAG "QMSD BOARD INIT"

#define LCD_VSYNC_GPIO    (48)
#define LCD_HSYNC_GPIO    (40)
#define LCD_DE_GPIO       (39)
#define LCD_PCLK_GPIO     (45)
#define LCD_DATA0_GPIO    (47)  // B0
#define LCD_DATA1_GPIO    (41)  // B1
#define LCD_DATA2_GPIO    (21)  // B2
#define LCD_DATA3_GPIO    (42)  // B3
#define LCD_DATA4_GPIO    (14)  // B4
#define LCD_DATA5_GPIO    (8)  // G0
#define LCD_DATA6_GPIO    (13) // G1
#define LCD_DATA7_GPIO    (18) // G2
#define LCD_DATA8_GPIO    (12) // G3
#define LCD_DATA9_GPIO    (11) // G4
#define LCD_DATA10_GPIO   (17) // G5
#define LCD_DATA11_GPIO   (10) // R0
#define LCD_DATA12_GPIO   (16) // R1
#define LCD_DATA13_GPIO   (9) // R2
#define LCD_DATA14_GPIO   (15) // R3
#define LCD_DATA15_GPIO   (46) // R4
#define LCD_DISP_EN_GPIO  (-1)

#define LCD_PIXEL_CLOCK_HZ (10 * 1000 * 1000)
#define LCD_BK_LIGHT_ON_LEVEL  1
#define LCD_BK_LIGHT_OFF_LEVEL !LCD_BK_LIGHT_ON_LEVEL
#define LCD_PIN_DATA0          41  /*!< for 1-line SPI, this also refered as MOSI */
#define LCD_PIN_PCLK           47
#define LCD_PIN_CS             0
#define LCD_PIN_DC             -1
#define LCD_PIN_RST            2
#define LCD_PIN_BK_LIGHT       38

#define LCD_TOUCH_INT_PIN      1

#define ECO_O(y) (y>0)? -1:1
#define ECO_STEP(x) x? ECO_O(x):0

static button_t *g_btn;

static spi_device_handle_t st7701s_spi;

static void st7701s_send_cmd(uint8_t cmd)
{
    uint16_t tmp_cmd = (cmd | 0x0000);
    spi_transaction_ext_t trans = (spi_transaction_ext_t)
    {
        .base =
        {
            .flags = SPI_TRANS_VARIABLE_CMD,
            .cmd = tmp_cmd,
        },
        .command_bits = 9,
    };
    spi_device_transmit(st7701s_spi, (spi_transaction_t *)&trans);
}

static void st7701s_send_data(uint8_t data)
{
    uint16_t tmp_data = (data | 0x0100);
    spi_transaction_ext_t trans = (spi_transaction_ext_t)
    {
        .base =
        {
            .flags = SPI_TRANS_VARIABLE_CMD,
            .cmd = tmp_data,
        },
        .command_bits = 9,
    };

    spi_device_transmit(st7701s_spi, (spi_transaction_t *)&trans);
}

static void st7701s_init(void)
{
    st7701s_send_cmd(0xFF);
    st7701s_send_data(0x77);
    st7701s_send_data(0x01);
    st7701s_send_data(0x00);
    st7701s_send_data(0x00);
    st7701s_send_data(0x10);

    st7701s_send_cmd(0xC0);
    st7701s_send_data(0x3B);//Scan line	
    st7701s_send_data(0x00);

    st7701s_send_cmd(0xC1);
    st7701s_send_data(0x0B);	//VBP
    st7701s_send_data(0x02);

    st7701s_send_cmd(0xC2);
    st7701s_send_data(0x07);
    st7701s_send_data(0x02);

    st7701s_send_cmd(0xCC);
    st7701s_send_data(0x10);

    st7701s_send_cmd(0xCD);//RGB format
    st7701s_send_data(0x08);

    st7701s_send_cmd(0xB0); // IPS   
    st7701s_send_data(0x00); // 255 
    st7701s_send_data(0x11); // 251    
    st7701s_send_data(0x16); // 247  down
    st7701s_send_data(0x0e); // 239    
    st7701s_send_data(0x11); // 231    
    st7701s_send_data(0x06); // 203    
    st7701s_send_data(0x05); // 175 
    st7701s_send_data(0x09); // 147    
    st7701s_send_data(0x08); // 108    
    st7701s_send_data(0x21); // 80  
    st7701s_send_data(0x06); // 52   
    st7701s_send_data(0x13); // 24    
    st7701s_send_data(0x10); // 16    
    st7701s_send_data(0x29); // 8    down
    st7701s_send_data(0x31); // 4    
    st7701s_send_data(0x18); // 0   

    st7701s_send_cmd(0xB1);//  IPS	   
    st7701s_send_data(0x00);//  255 
    st7701s_send_data(0x11);//  251
    st7701s_send_data(0x16);//  247   down
    st7701s_send_data(0x0e);//  239
    st7701s_send_data(0x11);//  231
    st7701s_send_data(0x07);//  203    
    st7701s_send_data(0x05);//  175
    st7701s_send_data(0x09);//  147  
    st7701s_send_data(0x09);//  108  
    st7701s_send_data(0x21);//  80 
    st7701s_send_data(0x05);//  52   
    st7701s_send_data(0x13);//  24 
    st7701s_send_data(0x11);//  16 
    st7701s_send_data(0x2a);//  8  down 
    st7701s_send_data(0x31);//  4  
    st7701s_send_data(0x18);//  0  

    st7701s_send_cmd(0xFF);
    st7701s_send_data(0x77);
    st7701s_send_data(0x01);
    st7701s_send_data(0x00);
    st7701s_send_data(0x00);
    st7701s_send_data(0x11);

    st7701s_send_cmd(0xB0);  //VOP  3.5375+ *x 0.0125
    st7701s_send_data(0x6d);  //5D
    
    st7701s_send_cmd(0xB1); 	//VCOM amplitude setting  
    st7701s_send_data(0x37);  //
    
    st7701s_send_cmd(0xB2); 	//VGH Voltage setting  
    st7701s_send_data(0x81);	//12V

    st7701s_send_cmd(0xB3);
    st7701s_send_data(0x80);

    st7701s_send_cmd(0xB5); 	//VGL Voltage setting  
    st7701s_send_data(0x43);	//-8.3V

    st7701s_send_cmd(0xB7);
    st7701s_send_data(0x85);

    st7701s_send_cmd(0xB8);
    st7701s_send_data(0x20);

    st7701s_send_cmd(0xC1);
    st7701s_send_data(0x78);

    st7701s_send_cmd(0xC2);
    st7701s_send_data(0x78);

    st7701s_send_cmd(0xD0);
    st7701s_send_data(0x88);

    st7701s_send_cmd(0xE0);
    st7701s_send_data(0x00);
    st7701s_send_data(0x00);
    st7701s_send_data(0x02);

    st7701s_send_cmd(0xE1);
    st7701s_send_data(0x03);	
    st7701s_send_data(0xA0);
    st7701s_send_data(0x00);	
    st7701s_send_data(0x00);
    st7701s_send_data(0x04);	
    st7701s_send_data(0xA0);
    st7701s_send_data(0x00);	
    st7701s_send_data(0x00);	
    st7701s_send_data(0x00);
    st7701s_send_data(0x20);
    st7701s_send_data(0x20);

    st7701s_send_cmd(0xE2);
    st7701s_send_data(0x00);	
    st7701s_send_data(0x00);	  
    st7701s_send_data(0x00);	
    st7701s_send_data(0x00);	
    st7701s_send_data(0x00);	
    st7701s_send_data(0x00);	
    st7701s_send_data(0x00);	
    st7701s_send_data(0x00);	
    st7701s_send_data(0x00);	
    st7701s_send_data(0x00);	
    st7701s_send_data(0x00);	
    st7701s_send_data(0x00);	
    st7701s_send_data(0x00);

    st7701s_send_cmd(0xE3);
    st7701s_send_data(0x00);
    st7701s_send_data(0x00);
    st7701s_send_data(0x11);
    st7701s_send_data(0x00);

    st7701s_send_cmd(0xE4);
    st7701s_send_data(0x22);
    st7701s_send_data(0x00);

    st7701s_send_cmd(0xE5);		
    st7701s_send_data(0x05);	
    st7701s_send_data(0xEC);	
    st7701s_send_data(0xA0);
    st7701s_send_data(0xA0);
    st7701s_send_data(0x07);	
    st7701s_send_data(0xEE);	
    st7701s_send_data(0xA0);
    st7701s_send_data(0xA0);
    st7701s_send_data(0x00);
    st7701s_send_data(0x00);	
    st7701s_send_data(0x00);
    st7701s_send_data(0x00);
    st7701s_send_data(0x00);
    st7701s_send_data(0x00);	
    st7701s_send_data(0x00);
    st7701s_send_data(0x00);

    st7701s_send_cmd(0xE6);
    st7701s_send_data(0x00);
    st7701s_send_data(0x00);
    st7701s_send_data(0x11);
    st7701s_send_data(0x00);

    st7701s_send_cmd(0xE7);
    st7701s_send_data(0x22);
    st7701s_send_data(0x00);

    st7701s_send_cmd(0xE8);		
    st7701s_send_data(0x06);	
    st7701s_send_data(0xED);	
    st7701s_send_data(0xA0);
    st7701s_send_data(0xA0);
    st7701s_send_data(0x08);	
    st7701s_send_data(0xEF);	
    st7701s_send_data(0xA0); 
    st7701s_send_data(0xA0);
    st7701s_send_data(0x00);	
    st7701s_send_data(0x00);	
    st7701s_send_data(0x00);
    st7701s_send_data(0x00);
    st7701s_send_data(0x00);	
    st7701s_send_data(0x00);	
    st7701s_send_data(0x00);
    st7701s_send_data(0x00);

    st7701s_send_cmd(0xEB);
    st7701s_send_data(0x00);
    st7701s_send_data(0x00);
    st7701s_send_data(0x40);
    st7701s_send_data(0x40);
    st7701s_send_data(0x00);
    st7701s_send_data(0x00);
    st7701s_send_data(0x00);

    st7701s_send_cmd(0xED);
    st7701s_send_data(0xFF);
    st7701s_send_data(0xFF);
    st7701s_send_data(0xFF);
    st7701s_send_data(0xBA);
    st7701s_send_data(0x0A);
    st7701s_send_data(0xBF);
    st7701s_send_data(0x45);
    st7701s_send_data(0xFF);
    st7701s_send_data(0xFF); 
    st7701s_send_data(0x54);
    st7701s_send_data(0xFB);
    st7701s_send_data(0xA0);
    st7701s_send_data(0xAB);
    st7701s_send_data(0xFF); 
    st7701s_send_data(0xFF); 
    st7701s_send_data(0xFF); 

    st7701s_send_cmd(0xEF);
    st7701s_send_data(0x10); 
    st7701s_send_data(0x0D); 
    st7701s_send_data(0x04); 
    st7701s_send_data(0x08); 
    st7701s_send_data(0x3F); 
    st7701s_send_data(0x1F);

    st7701s_send_cmd(0xFF);
    st7701s_send_data(0x77);
    st7701s_send_data(0x01);
    st7701s_send_data(0x00);
    st7701s_send_data(0x00);
    st7701s_send_data(0x13);

    st7701s_send_cmd(0xEF);
    st7701s_send_data(0x08);

    st7701s_send_cmd(0xFF);
    st7701s_send_data(0x77);
    st7701s_send_data(0x01);
    st7701s_send_data(0x00);
    st7701s_send_data(0x00);
    st7701s_send_data(0x00);

    st7701s_send_cmd(0x36);
    st7701s_send_data(0x00);

    st7701s_send_cmd(0x3A);
    st7701s_send_data(0x66);

    st7701s_send_cmd(0x11);
    vTaskDelay(pdMS_TO_TICKS(120));
    st7701s_send_cmd(0x29);
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

static bool __qmsd_encoder_read(lv_indev_drv_t *drv, lv_indev_data_t *data)
{
    static int16_t cont_last = 0;
    int16_t cont_now = mt8901_get_count();
    data->enc_diff = ECO_STEP(cont_now - cont_last);
    cont_last = cont_now;
    if (button_isPressed(g_btn)){
        data->state = LV_INDEV_STATE_PR;
        return true;
    }
    else {
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
            .vsync_front_porch = 30,
            .flags.pclk_active_neg = 0,
        },
        .flags.fb_in_psram = 1,
        .flags.relax_on_idle = 0,
        .flags.double_buffer = 1,
        .clk_src = LCD_CLK_SRC_PLL240M,
    };

    qmsd_rgb_init(&panel_config);
    __qsmd_encoder_init();

    ESP_ERROR_CHECK(gpio_set_level(LCD_PIN_BK_LIGHT, LCD_BK_LIGHT_ON_LEVEL));
}
#endif