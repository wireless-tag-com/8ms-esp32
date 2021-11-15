/**
 * @file ili9488.c
 */

/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "driver/gpio.h"
#include "screen_driver.h"
#include "screen_utility.h"
#include "ili9488.h"
#include "esp_log.h"
#include "esp_heap_caps.h"
#include "driver/gpio.h"
#include "driver/i2s.h"
#include "esp32s2/rom/lldesc.h"
//#include "soc/system_reg.h"
#include "freertos/semphr.h"
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

/*********************
 *      DEFINES
 *********************/
#define TAG "ILI9488"

/**********************
 *      TYPEDEFS
 **********************/

typedef struct
{
    uint32_t dma_buffer_size;
    uint32_t dma_half_buffer_size;
    uint32_t dma_node_buffer_size;
    uint32_t dma_node_cnt;
    uint32_t dma_half_node_cnt;
    lldesc_t *dma;
    uint8_t *dma_buffer;
    QueueHandle_t event_queue;
    uint8_t width;
    bool swap_data;
} lcd_obj_t;

/*The LCD needs a bunch of command/argument values to be initialized. They are stored in this struct. */
typedef struct
{
    uint8_t cmd;
    uint8_t data[16];
    uint8_t databytes; //No of data in data; bit 7 = delay after set; 0xFF = end of cmds.
} lcd_init_cmd_t;

typedef struct
{
    lcd_obj_t lcd;
    intr_handle_t lcd_cam_intr_handle;
    i2s_dev_t *i2s_dev;
} lcd_cam_obj_t;

/**********************
 *      MACROS
 **********************/

#define LCD_CHECK(a, str, ret)                                                 \
    if (!(a))                                                                  \
    {                                                                          \
        ESP_LOGE(TAG, "%s:%d (%s):%s", __FILE__, __LINE__, __FUNCTION__, str); \
        return (ret);                                                          \
    }

#define ILI9488_CASET 0x2A
#define ILI9488_RASET 0x2B
#define ILI9488_RAMWR 0x2C
#define ILI9488_MADCTL 0x36

/* MADCTL Defines */
#define MADCTL_MY 0x80
#define MADCTL_MX 0x40
#define MADCTL_MV 0x20
#define MADCTL_ML 0x10
#define MADCTL_RGB 0x08
#define MADCTL_MH 0x04

#define LCD_NAME "ILI9488"
#define LCD_BPP 16
#define ILI9488_RESOLUTION_HOR 320
#define ILI9488_RESOLUTION_VER 480

static scr_handle_t g_lcd_handle;

/**
 * This header file is only used to redefine the function to facilitate the call.
 * It can only be placed in this position, not in the head of the file.
 */
#include "interface_drv_def.h"

scr_driver_t lcd_ili9488_default_driver = {
    .init = lcd_ili9488_init,
    .deinit = lcd_ili9488_deinit,
    .set_direction = lcd_ili9488_set_rotation,
    .set_window = lcd_ili9488_set_window,
    .write_ram_data = lcd_ili9488_write_ram_data,
    .draw_pixel = lcd_ili9488_draw_pixel,
    .draw_bitmap = lcd_ili9488_draw_bitmap,
    .get_info = lcd_ili9488_get_info,
};

#if 0
/**********************		
 *   GLOBAL FUNCTIONS
 **********************/
static void i2s_lcd_reg_config(i2s_dev_t *i2s_dev)
{
	// Configure the clock
	i2s_dev->clkm_conf.clkm_div_num = 2; // 160MHz / 2 = 80MHz
	i2s_dev->clkm_conf.clkm_div_b = 0;
	i2s_dev->clkm_conf.clkm_div_a = 0;
	i2s_dev->clkm_conf.clk_sel = 2;
	i2s_dev->clkm_conf.clk_en = 1;
	i2s_dev->conf.val = 0;
	i2s_dev->fifo_conf.val = 0;
	i2s_dev->fifo_conf.dscr_en = 1;
	i2s_dev->lc_conf.ahbm_fifo_rst = 1;
	i2s_dev->lc_conf.ahbm_fifo_rst = 0;
	i2s_dev->lc_conf.ahbm_rst = 1;
	i2s_dev->lc_conf.ahbm_rst = 0;
	i2s_dev->lc_conf.check_owner = 0;
	i2s_dev->timing.val = 0;
	i2s_dev->int_ena.val = 0;
	i2s_dev->int_clr.val = ~0;
	i2s_dev->conf2.lcd_en = 1;
	i2s_dev->sample_rate_conf.tx_bck_div_num = 40000000 / 20000000; // Fws = Fbck / 2
	i2s_dev->sample_rate_conf.tx_bits_mod = BOARD_LCD_I2S_BITWIDTH;
	i2s_dev->conf.tx_right_first = 1;
	i2s_dev->conf.tx_msb_right = 1;
	i2s_dev->conf.tx_dma_equal = 1;
	i2s_dev->conf1.tx_pcm_bypass = 1;
	i2s_dev->conf1.tx_stop_en = 1;
	i2s_dev->conf2.lcd_en = 1;
	i2s_dev->conf_chan.tx_chan_mod = 1;
	i2s_dev->fifo_conf.tx_fifo_mod_force_en = 1;
	i2s_dev->fifo_conf.tx_data_num = 32;
	i2s_dev->fifo_conf.tx_fifo_mod = 2;
	i2s_dev->fifo_conf.tx_24msb_en = 0;
	i2s_dev->lc_conf.out_rst = 1;
	i2s_dev->lc_conf.out_rst = 0;
	i2s_dev->int_ena.out_eof = 1;
}

static esp_err_t lcd_dma_config(lcd_cam_obj_t *lcd_cam_obj, uint32_t max_dma_buffer_size)
{
	int cnt = 0;
	if (LCD_CAM_DMA_NODE_BUFFER_MAX_SIZE % 2 != 0)
	{
		ESP_LOGE(TAG, "ESP32 only supports 2-byte aligned data length");
		return ESP_FAIL;
	}
	if (max_dma_buffer_size >= LCD_CAM_DMA_NODE_BUFFER_MAX_SIZE * 2)
	{
		lcd_cam_obj->lcd.dma_node_buffer_size = LCD_CAM_DMA_NODE_BUFFER_MAX_SIZE;
		for (cnt = 0; cnt < max_dma_buffer_size - 8; cnt++)
		{ // Find a buffer size that can divide dma_size
			if ((max_dma_buffer_size - cnt) % (lcd_cam_obj->lcd.dma_node_buffer_size * 2) == 0)
			{
				break;
			}
		}
		lcd_cam_obj->lcd.dma_buffer_size = max_dma_buffer_size - cnt;
	}
	else
	{
		lcd_cam_obj->lcd.dma_node_buffer_size = max_dma_buffer_size / 2;
		lcd_cam_obj->lcd.dma_buffer_size = lcd_cam_obj->lcd.dma_node_buffer_size * 2;
	}

	lcd_cam_obj->lcd.dma_half_buffer_size = lcd_cam_obj->lcd.dma_buffer_size / 2;
	lcd_cam_obj->lcd.dma_node_cnt = (lcd_cam_obj->lcd.dma_buffer_size) / lcd_cam_obj->lcd.dma_node_buffer_size; // Number of DMA nodes
	lcd_cam_obj->lcd.dma_half_node_cnt = lcd_cam_obj->lcd.dma_node_cnt / 2;

	ESP_LOGI(TAG, "lcd_buffer_size: %d, lcd_dma_size: %d, lcd_dma_node_cnt: %d", lcd_cam_obj->lcd.dma_buffer_size, lcd_cam_obj->lcd.dma_node_buffer_size, lcd_cam_obj->lcd.dma_node_cnt);

	lcd_cam_obj->lcd.dma = (lldesc_t *)heap_caps_malloc(lcd_cam_obj->lcd.dma_node_cnt * sizeof(lldesc_t), MALLOC_CAP_DMA | MALLOC_CAP_8BIT);
	lcd_cam_obj->lcd.dma_buffer = (uint8_t *)heap_caps_malloc(lcd_cam_obj->lcd.dma_buffer_size * sizeof(uint8_t), MALLOC_CAP_DMA | MALLOC_CAP_8BIT);
	lcd_cam_obj->lcd.event_queue = xQueueCreate(1, sizeof(int));
	return ESP_OK;
}

static void lcd_dma_set_left(lcd_cam_obj_t *lcd_cam_obj, int pos, size_t len)
{
	int end_pos = 0, size = 0;
	// Processing data length is an integer multiple of lcd_cam_obj->lcd.dma_node_buffer_size
	if (len % lcd_cam_obj->lcd.dma_node_buffer_size)
	{
		end_pos = (pos % 2) * lcd_cam_obj->lcd.dma_half_node_cnt + len / lcd_cam_obj->lcd.dma_node_buffer_size;
		size = len % lcd_cam_obj->lcd.dma_node_buffer_size;
	}
	else
	{
		end_pos = (pos % 2) * lcd_cam_obj->lcd.dma_half_node_cnt + len / lcd_cam_obj->lcd.dma_node_buffer_size - 1;
		size = lcd_cam_obj->lcd.dma_node_buffer_size;
	}
	// Process the tail node to make it a DMA tail
	lcd_cam_obj->lcd.dma[end_pos].size = size;
	lcd_cam_obj->lcd.dma[end_pos].length = size;
	lcd_cam_obj->lcd.dma[end_pos].eof = 1;
	lcd_cam_obj->lcd.dma[end_pos].empty = (uint32_t)NULL;
}

static void lcd_dma_set_int(lcd_cam_obj_t *lcd_cam_obj)
{
	// Generate a data DMA linked list
	for (int x = 0; x < lcd_cam_obj->lcd.dma_node_cnt; x++)
	{
		lcd_cam_obj->lcd.dma[x].size = lcd_cam_obj->lcd.dma_node_buffer_size;
		lcd_cam_obj->lcd.dma[x].length = lcd_cam_obj->lcd.dma_node_buffer_size;
		lcd_cam_obj->lcd.dma[x].buf = (lcd_cam_obj->lcd.dma_buffer + lcd_cam_obj->lcd.dma_node_buffer_size * x);
		lcd_cam_obj->lcd.dma[x].eof = !((x + 1) % lcd_cam_obj->lcd.dma_half_node_cnt);
		lcd_cam_obj->lcd.dma[x].empty = (uint32_t)&lcd_cam_obj->lcd.dma[(x + 1) % lcd_cam_obj->lcd.dma_node_cnt];
	}
	lcd_cam_obj->lcd.dma[lcd_cam_obj->lcd.dma_half_node_cnt - 1].empty = (uint32_t)NULL;
	lcd_cam_obj->lcd.dma[lcd_cam_obj->lcd.dma_node_cnt - 1].empty = (uint32_t)NULL;
}

static void lcd_i2s_start(i2s_dev_t *i2s_dev, uint32_t addr, size_t len)
{
	while (!i2s_dev->state.tx_idle)
		;
	i2s_dev->conf.tx_reset = 1;
	i2s_dev->conf.tx_reset = 0;
	i2s_dev->conf.tx_fifo_reset = 1;
	i2s_dev->conf.tx_fifo_reset = 0;
	i2s_dev->out_link.addr = addr;
	i2s_dev->out_link.start = 1;
	ets_delay_us(1);
	i2s_dev->conf.tx_start = 1;
}

static void i2s_write_data(uint8_t *data, size_t len)
{
	int event = 0;
	int x = 0, y = 0, left = 0, cnt = 0;
	if (len <= 0)
	{
		ESP_LOGE(TAG, "wrong len!");
		return;
	}

	lcd_dma_set_int(lcd_cam_obj);
	cnt = len / lcd_cam_obj->lcd.dma_half_buffer_size;
	// Start signal
	xQueueSend(lcd_cam_obj->lcd.event_queue, &event, 0);

	// Process a complete piece of data, ping-pong operation
	for (x = 0; x < cnt; x++)
	{
		uint8_t *out = (uint8_t *)lcd_cam_obj->lcd.dma[(x % 2) * lcd_cam_obj->lcd.dma_half_node_cnt].buf;
		uint8_t *in = data;
		if (lcd_cam_obj->lcd.swap_data)
		{
			for (y = 0; y < lcd_cam_obj->lcd.dma_half_buffer_size; y += 2)
			{
				out[y + 1] = in[y + 0];
				out[y + 0] = in[y + 1];
			}
		}
		else
		{
			memcpy(out, in, lcd_cam_obj->lcd.dma_half_buffer_size);
		}
		data += lcd_cam_obj->lcd.dma_half_buffer_size;
		xQueueReceive(lcd_cam_obj->lcd.event_queue, (void *)&event, portMAX_DELAY);
		lcd_i2s_start(lcd_cam_obj->i2s_dev, ((uint32_t)&lcd_cam_obj->lcd.dma[(x % 2) * lcd_cam_obj->lcd.dma_half_node_cnt]) & 0xfffff, lcd_cam_obj->lcd.dma_half_buffer_size);
	}
	left = len % lcd_cam_obj->lcd.dma_half_buffer_size;
	// Process remaining incomplete segment data
	if (left)
	{
		uint8_t *out = (uint8_t *)lcd_cam_obj->lcd.dma[(x % 2) * lcd_cam_obj->lcd.dma_half_node_cnt].buf;
		uint8_t *in = data;
		cnt = left - left % 2;
		if (cnt)
		{
			if (lcd_cam_obj->lcd.swap_data)
			{
				for (y = 0; y < cnt; y += 2)
				{
					out[y + 1] = in[y + 0];
					out[y + 0] = in[y + 1];
				}
			}
			else
			{
				memcpy(out, in, cnt);
			}
		}

		if (left % 2)
		{
			out[cnt] = in[cnt];
		}

		lcd_dma_set_left(lcd_cam_obj, x, left);
		xQueueReceive(lcd_cam_obj->lcd.event_queue, (void *)&event, portMAX_DELAY);
		lcd_i2s_start(lcd_cam_obj->i2s_dev, ((uint32_t)&lcd_cam_obj->lcd.dma[(x % 2) * lcd_cam_obj->lcd.dma_half_node_cnt]) & 0xfffff, left);
	}

	xQueueReceive(lcd_cam_obj->lcd.event_queue, (void *)&event, portMAX_DELAY);
}

static void i2s_lcd_write(const uint8_t *data, uint32_t length)
{
	i2s_write_data((uint8_t *)data, length);
}

static void LCD_WRITE_CMD(uint16_t cmd)
{
	gpio_set_level(BOARD_LCD_I2S_RS_PIN, 0);
	i2s_write_data((uint8_t *)&cmd, 2);
	gpio_set_level(BOARD_LCD_I2S_RS_PIN, 1);
}

static void LCD_WRITE_DATA(uint16_t data)
{
	i2s_write_data((uint8_t *)&data, 2);
}

static void IRAM_ATTR i2s_isr(void *arg)
{
	BaseType_t HPTaskAwoken = pdFALSE;
	lcd_cam_obj_t *lcd_cam_obj = (lcd_cam_obj_t *)arg;
	i2s_dev_t *i2s_dev = lcd_cam_obj->i2s_dev;

	typeof(i2s_dev->int_st) status = i2s_dev->int_st;
	i2s_dev->int_clr.val = status.val;
	if (status.val == 0)
	{
		return;
	}

	if (status.out_eof)
	{
		xQueueSendFromISR(lcd_cam_obj->lcd.event_queue, (void *)&status.val, &HPTaskAwoken);
	}

	if (HPTaskAwoken == pdTRUE)
	{
		portYIELD_FROM_ISR();
	}
}
#endif

static void lcd_ili9488_init_reg(void);

esp_err_t lcd_ili9488_init(const scr_controller_config_t *lcd_conf)
{
    LCD_CHECK(lcd_conf->width <= ILI9488_RESOLUTION_HOR, "Width greater than maximum", ESP_ERR_INVALID_ARG);
    LCD_CHECK(lcd_conf->height <= ILI9488_RESOLUTION_VER, "Height greater than maximum", ESP_ERR_INVALID_ARG);
    LCD_CHECK(NULL != lcd_conf, "config pointer invalid", ESP_ERR_INVALID_ARG);
    LCD_CHECK((NULL != lcd_conf->interface_drv->write_cmd &&
               NULL != lcd_conf->interface_drv->write_data &&
               NULL != lcd_conf->interface_drv->write &&
               NULL != lcd_conf->interface_drv->read &&
               NULL != lcd_conf->interface_drv->bus_acquire &&
               NULL != lcd_conf->interface_drv->bus_release),
              "Interface driver invalid", ESP_ERR_INVALID_ARG);

    esp_err_t ret;

    // Reset the display
    if (lcd_conf->pin_num_rst >= 0)
    {
        gpio_pad_select_gpio(lcd_conf->pin_num_rst);
        gpio_set_direction(lcd_conf->pin_num_rst, GPIO_MODE_OUTPUT);
        gpio_set_level(lcd_conf->pin_num_rst, (lcd_conf->rst_active_level) & 0x1);
        vTaskDelay(100 / portTICK_RATE_MS);
        gpio_set_level(lcd_conf->pin_num_rst, (~(lcd_conf->rst_active_level)) & 0x1);
        vTaskDelay(100 / portTICK_RATE_MS);
    }

    g_lcd_handle.interface_drv = lcd_conf->interface_drv;
    g_lcd_handle.original_width = lcd_conf->width;
    g_lcd_handle.original_height = lcd_conf->height;
    g_lcd_handle.offset_hor = lcd_conf->offset_hor;
    g_lcd_handle.offset_ver = lcd_conf->offset_ver;

    lcd_ili9488_init_reg();

    // Enable backlight
    if (lcd_conf->pin_num_bckl >= 0)
    {
        gpio_pad_select_gpio(lcd_conf->pin_num_bckl);
        gpio_set_direction(lcd_conf->pin_num_bckl, GPIO_MODE_OUTPUT);
        gpio_set_level(lcd_conf->pin_num_bckl, (lcd_conf->bckl_active_level) & 0x1);
    }

    LCD_WRITE_CMD(ILI9488_CMD_MEMORY_ACCESS_CONTROL);
    LCD_WRITE_DATA(0xA8);

    ret = lcd_ili9488_set_rotation(lcd_conf->rotate);
    LCD_CHECK(ESP_OK == ret, "set rotation failed", ESP_FAIL);

    return ESP_OK;
}

esp_err_t lcd_ili9488_deinit(void)
{
    memset(&g_lcd_handle, 0, sizeof(scr_handle_t));
    return ESP_OK;
}

esp_err_t lcd_ili9488_set_rotation(scr_dir_t dir)
{
    esp_err_t ret;
    uint8_t reg_data = MADCTL_RGB;
    if (SCR_DIR_MAX < dir)
    {
        dir >>= 5;
    }
    LCD_CHECK(dir < 8, "Unsupport rotate direction", ESP_ERR_INVALID_ARG);
    switch (dir)
    {
    case SCR_DIR_LRTB:
        g_lcd_handle.width = g_lcd_handle.original_width;
        g_lcd_handle.height = g_lcd_handle.original_height;
        break;
    case SCR_DIR_LRBT:
        reg_data |= MADCTL_MY;
        g_lcd_handle.width = g_lcd_handle.original_width;
        g_lcd_handle.height = g_lcd_handle.original_height;
        break;
    case SCR_DIR_RLTB:
        reg_data |= MADCTL_MX;
        g_lcd_handle.width = g_lcd_handle.original_width;
        g_lcd_handle.height = g_lcd_handle.original_height;
        break;
    case SCR_DIR_RLBT:
        reg_data |= MADCTL_MX | MADCTL_MY;
        g_lcd_handle.width = g_lcd_handle.original_width;
        g_lcd_handle.height = g_lcd_handle.original_height;
        break;

    case SCR_DIR_TBLR:
        reg_data |= MADCTL_MV;
        g_lcd_handle.width = g_lcd_handle.original_height;
        g_lcd_handle.height = g_lcd_handle.original_width;
        break;
    case SCR_DIR_BTLR:
        reg_data |= MADCTL_MY | MADCTL_MV;
        g_lcd_handle.width = g_lcd_handle.original_height;
        g_lcd_handle.height = g_lcd_handle.original_width;
        break;
    case SCR_DIR_TBRL:
        reg_data |= MADCTL_MX | MADCTL_MV;
        g_lcd_handle.width = g_lcd_handle.original_height;
        g_lcd_handle.height = g_lcd_handle.original_width;
        break;
    case SCR_DIR_BTRL:
        reg_data |= MADCTL_MX | MADCTL_MY | MADCTL_MV;
        g_lcd_handle.width = g_lcd_handle.original_height;
        g_lcd_handle.height = g_lcd_handle.original_width;
        break;
    default:
        break;
    }
    ESP_LOGI(TAG, "MADCTL=0x%x", reg_data);
    ret = LCD_WRITE_REG(ILI9488_MADCTL, reg_data);
    LCD_CHECK(ESP_OK == ret, "Set screen rotate failed", ESP_FAIL);
    g_lcd_handle.dir = dir;
    return ESP_OK;
}

esp_err_t lcd_ili9488_get_info(scr_info_t *info)
{
    LCD_CHECK(NULL != info, "info pointer invalid", ESP_ERR_INVALID_ARG);
    info->width = g_lcd_handle.width;
    info->height = g_lcd_handle.height;
    info->dir = g_lcd_handle.dir;
    info->name = LCD_NAME;
    info->color_type = SCR_COLOR_TYPE_RGB565;
    info->bpp = LCD_BPP;
    return ESP_OK;
}

#if 0
static void scr_utility_apply_offset(uint16_t *x0, uint16_t *y0, uint16_t *x1, uint16_t *y1)
{
	// uint16_t xoffset = 0, yoffset = 0;
	// // yoffset = lcd_handle->offset_hor;
	// xoffset = ILI9488_RESOLUTION_VER;
	// *x0 += xoffset;
	// *x1 += xoffset;
	// *y0 += yoffset;
	// *y1 += yoffset;
}
#endif

esp_err_t lcd_ili9488_set_window(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1)
{
    LCD_CHECK((x1 < g_lcd_handle.width) && (y1 < g_lcd_handle.height), "The set coordinates exceed the screen size", ESP_ERR_INVALID_ARG);
    LCD_CHECK((x0 <= x1) && (y0 <= y1), "Window coordinates invalid", ESP_ERR_INVALID_ARG);
    esp_err_t ret = ESP_OK;
    scr_utility_apply_offset(&g_lcd_handle, ILI9488_RESOLUTION_HOR, ILI9488_RESOLUTION_VER, &x0, &y0, &x1, &y1);

    ret |= LCD_WRITE_CMD(ILI9488_CMD_COLUMN_ADDRESS_SET);
    ret |= LCD_WRITE_DATA(x0 >> 8);
    ret |= LCD_WRITE_DATA(x0 & 0xff);
    ret |= LCD_WRITE_DATA(x1 >> 8);
    ret |= LCD_WRITE_DATA(x1 & 0xff);
    ret |= LCD_WRITE_CMD(ILI9488_CMD_PAGE_ADDRESS_SET);
    ret |= LCD_WRITE_DATA(y0 >> 8);
    ret |= LCD_WRITE_DATA(y0 & 0xff);
    ret |= LCD_WRITE_DATA(y1 >> 8);
    ret |= LCD_WRITE_DATA(y1 & 0xff);

    ret |= LCD_WRITE_CMD(ILI9488_CMD_MEMORY_WRITE);
    LCD_CHECK(ESP_OK == ret, "Set window failed", ESP_FAIL);
    return ESP_OK;
}

esp_err_t lcd_ili9488_draw_bitmap(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t *bitmap)
{
    esp_err_t ret;
    LCD_CHECK(NULL != bitmap, "bitmap pointer invalid", ESP_ERR_INVALID_ARG);

    LCD_IFACE_ACQUIRE();
    ret = lcd_ili9488_set_window(x, y, x + w - 1, y + h - 1);
    if (ESP_OK != ret)
    {
        return ESP_FAIL;
    }

    uint32_t len = w * h;
    ret = LCD_WRITE((uint8_t *)bitmap, 2 * len);
    LCD_IFACE_RELEASE();
    LCD_CHECK(ESP_OK == ret, "lcd write ram data failed", ESP_FAIL);
    return ESP_OK;
}

esp_err_t lcd_ili9488_write_ram_data(uint16_t color)
{
    static uint8_t data[2];
    data[0] = (uint8_t)(color & 0xff);
    data[1] = (uint8_t)(color >> 8);
    return LCD_WRITE(data, 2);
}

esp_err_t lcd_ili9488_draw_pixel(uint16_t x, uint16_t y, uint16_t color)
{
    esp_err_t ret;
    ret = lcd_ili9488_set_window(x, y, x, y);
    if (ESP_OK != ret)
    {
        return ESP_FAIL;
    }
    return lcd_ili9488_write_ram_data(color);
}

static void lcd_ili9488_init_reg(void)
{
#if 0
    LCD_WRITE_CMD(0x01); // SW reset
    vTaskDelay(120 / portTICK_RATE_MS);
    // Interface Mode Control
    LCD_WRITE_CMD(0xb0);
    LCD_WRITE_DATA(0x00);
    // Interface Pixel Format, 16 bits / pixel
    LCD_WRITE_CMD(0x3A);
    LCD_WRITE_DATA(0x55); // 5D
    // PGAMCTRL(Positive Gamma Control)
    LCD_WRITE_CMD(0xE0);
    LCD_WRITE_DATA(0x0F);
    LCD_WRITE_DATA(0x1F);
    LCD_WRITE_DATA(0x1C);
    LCD_WRITE_DATA(0x0C);
    LCD_WRITE_DATA(0x0F);
    LCD_WRITE_DATA(0x08);
    LCD_WRITE_DATA(0x48);
    LCD_WRITE_DATA(0x98);
    LCD_WRITE_DATA(0x37);
    LCD_WRITE_DATA(0x0A);
    LCD_WRITE_DATA(0x13);
    LCD_WRITE_DATA(0x04);
    LCD_WRITE_DATA(0x11);
    LCD_WRITE_DATA(0x0D);
    LCD_WRITE_DATA(0x00);
    // NGAMCTRL (Negative Gamma Correction)
    LCD_WRITE_CMD(0xE1);
    LCD_WRITE_DATA(0x0F);
    LCD_WRITE_DATA(0x32);
    LCD_WRITE_DATA(0x2E);
    LCD_WRITE_DATA(0x0B);
    LCD_WRITE_DATA(0x0D);
    LCD_WRITE_DATA(0x05);
    LCD_WRITE_DATA(0x47);
    LCD_WRITE_DATA(0x75);
    LCD_WRITE_DATA(0x37);
    LCD_WRITE_DATA(0x06);
    LCD_WRITE_DATA(0x10);
    LCD_WRITE_DATA(0x03);
    LCD_WRITE_DATA(0x24);
    LCD_WRITE_DATA(0x20);
    LCD_WRITE_DATA(0x00);
    // Digital Gamma Control 1
    LCD_WRITE_CMD(0xE2);
    LCD_WRITE_DATA(0x0F);
    LCD_WRITE_DATA(0x32);
    LCD_WRITE_DATA(0x2E);
    LCD_WRITE_DATA(0x0B);
    LCD_WRITE_DATA(0x0D);
    LCD_WRITE_DATA(0x05);
    LCD_WRITE_DATA(0x47);
    LCD_WRITE_DATA(0x75);
    LCD_WRITE_DATA(0x37);
    LCD_WRITE_DATA(0x06);
    LCD_WRITE_DATA(0x10);
    LCD_WRITE_DATA(0x03);
    LCD_WRITE_DATA(0x24);
    LCD_WRITE_DATA(0x20);
    LCD_WRITE_DATA(0x00);

    // Set rotation
    // setRotation(_rotation);

    // Idle mode control + Power +  Frame rate ctrl
    LCD_WRITE_CMD(0x38);
    // frame rate ctrl
    LCD_WRITE_CMD(0xB1);
    // Frame rate(Hz) (default: 70kHz) /-/ Division Ratio (default: fosc)
    LCD_WRITE_DATA(0xB0);
    // Clock per Line (default: 17 clk cycles)
    LCD_WRITE_DATA(0x11);
    // Power Control 3 (For Normal Mode)
    LCD_WRITE_CMD(0xC2);
    LCD_WRITE_DATA(0x55); // 44

    // Display Inversion Control
    LCD_WRITE_CMD(0xB4);
    LCD_WRITE_DATA(0x02); // 2 dot invercion /-/ disabled | 0x12 to enable
    // Display Function Control
    LCD_WRITE_CMD(0xB6);
    LCD_WRITE_DATA(0x02);
    LCD_WRITE_DATA(0x22);
    LCD_WRITE_DATA(0x3B);
    // # Sleep OUT
    LCD_WRITE_CMD(0x11);
    vTaskDelay(150 / portTICK_RATE_MS);
    // Display ON
    LCD_WRITE_CMD(0x29);
#endif
#if 1
    LCD_WRITE_CMD(ILI9488_CMD_POSITIVE_GAMMA_CORRECTION); //P-Gamma
    LCD_WRITE_DATA(0x00);
    LCD_WRITE_DATA(0x07);
    LCD_WRITE_DATA(0x0F);
    LCD_WRITE_DATA(0x04);
    LCD_WRITE_DATA(0x11);
    LCD_WRITE_DATA(0x06);
    LCD_WRITE_DATA(0x39);
    LCD_WRITE_DATA(0x67);
    LCD_WRITE_DATA(0x4E);
    LCD_WRITE_DATA(0x02);
    LCD_WRITE_DATA(0x0A);
    LCD_WRITE_DATA(0x09);
    LCD_WRITE_DATA(0x2D);
    LCD_WRITE_DATA(0x33);
    LCD_WRITE_DATA(0x0F);
    LCD_WRITE_CMD(ILI9488_CMD_NEGATIVE_GAMMA_CORRECTION); //N-Gamma
    LCD_WRITE_DATA(0x00);
    LCD_WRITE_DATA(0x0F);
    LCD_WRITE_DATA(0x14);
    LCD_WRITE_DATA(0x03);
    LCD_WRITE_DATA(0x10);
    LCD_WRITE_DATA(0x06);
    LCD_WRITE_DATA(0x33);
    LCD_WRITE_DATA(0x34);
    LCD_WRITE_DATA(0x45);
    LCD_WRITE_DATA(0x06);
    LCD_WRITE_DATA(0x0E);
    LCD_WRITE_DATA(0x0C);
    LCD_WRITE_DATA(0x2A);
    LCD_WRITE_DATA(0x30);
    LCD_WRITE_DATA(0x0F);
    LCD_WRITE_CMD(ILI9488_CMD_POWER_CONTROL_1); //Power Control 1
    LCD_WRITE_DATA(0x14);                       //Vreg1out
    LCD_WRITE_DATA(0x14);                       //Verg2out
    LCD_WRITE_CMD(ILI9488_CMD_POWER_CONTROL_2); //Power Control 2
    LCD_WRITE_DATA(0x45);                       //VGH,VGL
    LCD_WRITE_CMD(ILI9488_CMD_VCOM_CONTROL_1);  //Power Control 3
    LCD_WRITE_DATA(0x00);
    LCD_WRITE_DATA(0x55); //Vcom
    LCD_WRITE_DATA(0x80);
    LCD_WRITE_CMD(ILI9488_CMD_MEMORY_ACCESS_CONTROL); //Memory Access
    LCD_WRITE_DATA(0x08);
    LCD_WRITE_CMD(ILI9488_CMD_COLMOD_PIXEL_FORMAT_SET); // Interface Pixel Format
    LCD_WRITE_DATA(0x55);
    // LCD_WRITE_CMD(ILI9488_CMD_INTERFACE_MODE_CONTROL); // Interface Mode Control
    // LCD_WRITE_DATA(0x00);
    LCD_WRITE_CMD(ILI9488_CMD_FRAME_RATE_CONTROL_NORMAL); //Frame rate
    LCD_WRITE_DATA(0xB0);
    LCD_WRITE_DATA(0x11);                                 //60Hz
    LCD_WRITE_CMD(ILI9488_CMD_DISPLAY_INVERSION_CONTROL); //Display Inversion Control
    LCD_WRITE_DATA(0x02);                                 //2-dot
    LCD_WRITE_CMD(ILI9488_CMD_DISPLAY_FUNCTION_CONTROL);  //RGB/MCU Interface Control
    LCD_WRITE_DATA(0x02);                                 //MCU
    LCD_WRITE_DATA(0x02);                                 //Source,Gate scan dieection
    LCD_WRITE_CMD(ILI9488_CMD_SET_IMAGE_FUNCTION);        // Set Image Function
    LCD_WRITE_DATA(0x00);                                 // Disable 24 bit data input
    LCD_WRITE_CMD(ILI9488_CMD_ADJUST_CONTROL_3);          // Adjust Control
    LCD_WRITE_DATA(0xA9);
    LCD_WRITE_DATA(0x51);
    LCD_WRITE_DATA(0x2C);
    LCD_WRITE_DATA(0x82);
    LCD_WRITE_CMD(ILI9488_CMD_COLUMN_ADDRESS_SET);
    LCD_WRITE_DATA(0x00);
    LCD_WRITE_DATA(0x00);
    LCD_WRITE_DATA(0x01);
    LCD_WRITE_DATA(0x3F);
    LCD_WRITE_CMD(ILI9488_CMD_PAGE_ADDRESS_SET);
    LCD_WRITE_DATA(0x00);
    LCD_WRITE_DATA(0xA0);
    LCD_WRITE_DATA(0x01);
    LCD_WRITE_DATA(0xDF);
    LCD_WRITE_CMD(ILI9488_CMD_DISP_INVERSION_ON);
    // D7 stream, loose
    LCD_WRITE_CMD(ILI9488_CMD_SLEEP_OUT); //Sleep out
    vTaskDelay(12);
    LCD_WRITE_CMD(ILI9488_CMD_DISPLAY_ON); //Display on
#endif
}