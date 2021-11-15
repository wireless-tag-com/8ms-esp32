/* LVGL Example project
 * 
 * Basic project to test LVGL on ESP32 based projects.
 *
 * This example code is in the Public Domain (or CC0 licensed, at your option.)
 *
 * Unless required by applicable law or agreed to in writing, this
 * software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
 * CONDITIONS OF ANY KIND, either express or implied.
 */
#include "sdkconfig.h"
#if defined CONFIG_WT_SC_SPI
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_freertos_hooks.h"
#include "freertos/semphr.h"
#include "esp_system.h"
#include "driver/gpio.h"
#include "driver/uart.h"
#include "nvs_flash.h"

/* Littlevgl specific */
#include "lvgl/lvgl.h"
#include "lvgl_helpers.h"
#include "qm_ui_entry.h"
#include "wtctrl.h"

/*********************
 *      DEFINES
 *********************/
#define TAG "main"
#define LV_TICK_PERIOD_MS 10

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void lv_tick_task(void *arg);
void guiTask(void *pvParameter);

/**********************
 *   APPLICATION MAIN
 **********************/
static void user_nvs_init()
{
    esp_err_t ret;
    // Initialize NVS
    ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND)
    {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);
}

void app_main()
{
    user_nvs_init();
    xTaskCreatePinnedToCore(guiTask, "gui", 4096 * 2, NULL, 0, NULL, 1);

#ifdef LV_8MS_UART_CTRL
    lv_8ms_uart_ctrl_init(UART_NUM_0);
#endif
}

static void lv_tick_task(void *arg)
{
    (void)arg;
    lv_tick_inc(LV_TICK_PERIOD_MS);
}

extern void lv_8ms_init(void);

//Creates a semaphore to handle concurrent call to lvgl stuff
//If you wish to call *any* lvgl function from other threads/tasks
//you should lock on the very same semaphore!
SemaphoreHandle_t xGuiSemaphore;

void guiTask(void *pvParameter)
{

    (void)pvParameter;
    xGuiSemaphore = xSemaphoreCreateMutex();

    lv_init();

    /* Initialize SPI or I2C bus used by the drivers */
    lvgl_driver_init();

    static lv_color_t buf1[DISP_BUF_SIZE];
#ifndef CONFIG_LVGL_TFT_DISPLAY_MONOCHROME
    static lv_color_t buf2[DISP_BUF_SIZE];
#endif
    static lv_disp_buf_t disp_buf;

    uint32_t size_in_px = DISP_BUF_SIZE;

#if defined CONFIG_LVGL_TFT_DISPLAY_CONTROLLER_IL3820
    /* Actual size in pixel, not bytes and use single buffer */
    size_in_px *= 8;
    lv_disp_buf_init(&disp_buf, buf1, NULL, size_in_px);
#elif defined CONFIG_LVGL_TFT_DISPLAY_MONOCHROME
    lv_disp_buf_init(&disp_buf, buf1, NULL, size_in_px);
#else
    lv_disp_buf_init(&disp_buf, buf1, buf2, size_in_px);
#endif

    lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.flush_cb = disp_driver_flush;

#ifdef CONFIG_LVGL_TFT_DISPLAY_MONOCHROME
    disp_drv.rounder_cb = disp_driver_rounder;
    disp_drv.set_px_cb = disp_driver_set_px;
#endif

    disp_drv.buffer = &disp_buf;
    lv_disp_drv_register(&disp_drv);

#if CONFIG_LV_TOUCH_CONTROLLER != TOUCH_CONTROLLER_NONE
    lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);
    indev_drv.read_cb = touch_driver_read;
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    lv_indev_drv_register(&indev_drv);
#endif

    const esp_timer_create_args_t periodic_timer_args = {
        .callback = &lv_tick_task,
        .name = "periodic_gui"};
    esp_timer_handle_t periodic_timer;
    ESP_ERROR_CHECK(esp_timer_create(&periodic_timer_args, &periodic_timer));
    ESP_ERROR_CHECK(esp_timer_start_periodic(periodic_timer, LV_TICK_PERIOD_MS * 1000));

    lv_8ms_init();

    lv_qm_ui_entry();
    while (1)
    {
        vTaskDelay(10 / portTICK_PERIOD_MS);
        //Try to lock the semaphore, if success, call lvgl stuff
        if (xSemaphoreTake(xGuiSemaphore, (TickType_t)10) == pdTRUE)
        {
            lv_qm_ui_loop();
            lv_task_handler();
            xSemaphoreGive(xGuiSemaphore);
        }
    }

    //A task should NEVER return
    vTaskDelete(NULL);
}
#elif defined CONFIG_WT_SC_8080

#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "esp_log.h"
#include "esp_task_wdt.h"
#include "screen_driver.h"
#include "../lvgl/include/lvgl_gui.h"
#include "qm_ui_entry.h"
extern void lv_8ms_init(void);
#ifdef CONFIG_WT154_S2MI1
#define LCD_WR_SCK 12
#define LCD_RS_DC 11
#define LCD_CS 10
#define LCD_RD 13
#define LCD_RST 8
#define LCD_BL 39
#define LCD_D0 35
#define LCD_D1 36
#define LCD_D2 37
#define LCD_D3 38
#define LCD_D4 34
#define LCD_D5 33
#define LCD_D6 21
#define LCD_D7 14
#define SWAP_DATA 0
#define LCD_DRIVER SCREEN_CONTROLLER_ST7789
#define SC_DIR SCR_DIR_LRTB
#elif defined CONFIG_WT_86_32_3ZW1

#define LCD_WR_SCK 39
#define LCD_RS_DC 38
#define LCD_CS -1
#define LCD_RST 37
#define LCD_BL 0
#define LCD_D0 36
#define LCD_D1 35
#define LCD_D2 34
#define LCD_D3 33
#define LCD_D4 21
#define LCD_D5 18
#define LCD_D6 17
#define LCD_D7 16
#define SWAP_DATA 1
#define LCD_DRIVER SCREEN_CONTROLLER_ILI9488
#define SC_DIR SCR_DIR_RLTB

#elif defined CONFIG_WT_86_32_3ZW2

#define LCD_WR_SCK 39
#define LCD_RS_DC 38
#define LCD_CS -1
#define LCD_RST 37
#define LCD_BL 0
#define LCD_D0 36
#define LCD_D1 35
#define LCD_D2 34
#define LCD_D3 33
#define LCD_D4 21
#define LCD_D5 18
#define LCD_D6 17
#define LCD_D7 16
#define SWAP_DATA 1
#define LCD_DRIVER SCREEN_CONTROLLER_ST7796
#define SC_DIR SCR_DIR_RLTB

#elif defined CONFIG_WT280_S2MI1
#define LCD_WR_SCK 12
#define LCD_RS_DC 11
#define LCD_CS 10
#define LCD_RST 17
#define LCD_BL 16
#define LCD_D0 35
#define LCD_D1 36
#define LCD_D2 37
#define LCD_D3 34
#define LCD_D4 33
#define LCD_D5 21
#define LCD_D6 14
#define LCD_D7 13
#define SWAP_DATA 1
#define LCD_DRIVER SCREEN_CONTROLLER_ST7789
#define SC_DIR SCR_DIR_LRTB

#elif defined CONFIG_LCD01TG_A_SP
#define LCD_WR_SCK 12
#define LCD_RS_DC 11
#define LCD_CS 10
#define LCD_RST 8
#define LCD_BL 42
#define LCD_RD 15
#define LCD_D0 35
#define LCD_D1 36
#define LCD_D2 37
#define LCD_D3 34
#define LCD_D4 33
#define LCD_D5 21
#define LCD_D6 14
#define LCD_D7 13
#define SWAP_DATA 0
#define LCD_DRIVER SCREEN_CONTROLLER_ILI9341
#define SC_DIR SCR_DIR_TBLR
#endif

#define MAX_LOGO_TIME 20 // Duration of logo display

static const char *TAG = "main";

static scr_driver_t g_lcd;

void app_main(void)
{
    esp_err_t ret = ESP_OK;
    #if (defined CONFIG_WT154_S2MI1) || defined (CONFIG_LCD01TG_A_SP)
    gpio_reset_pin(LCD_RD);
    gpio_set_direction(LCD_RD, GPIO_MODE_OUTPUT);
    gpio_set_level(LCD_RD, 1);
    #endif
    i2s_lcd_config_t i2s_lcd_cfg = {
        .data_width = 8,
        .pin_data_num = {
            LCD_D0,
            LCD_D1,
            LCD_D2,
            LCD_D3,
            LCD_D4,
            LCD_D5,
            LCD_D6,
            LCD_D7,
            // 1, 2, 3, 4, 5, 6, 7, 8,
        },
        .pin_num_cs = LCD_CS,
        .pin_num_wr = LCD_WR_SCK,
        .pin_num_rs = LCD_RS_DC,

        .clk_freq = 20000000,
        .i2s_port = I2S_NUM_0,
        .buffer_size = 32000,
        .swap_data = SWAP_DATA,
    };

    scr_interface_driver_t *iface_drv;
    scr_interface_create(SCREEN_IFACE_8080, &i2s_lcd_cfg, &iface_drv);
    ret = scr_find_driver(LCD_DRIVER, &g_lcd);
    if (ESP_OK != ret)
    {
        ESP_LOGE(TAG, "screen find failed");
        return;
    }
    scr_controller_config_t lcd_cfg = {
        .interface_drv = iface_drv,
        .pin_num_rst = LCD_RST,
        .pin_num_bckl = LCD_BL,
        .rst_active_level = 0,
        .bckl_active_level = 1,
        .offset_hor = 0,
        .offset_ver = 0,
        .width = CONFIG_LV_HOR_RES_MAX,
        .height = CONFIG_LV_VER_RES_MAX,
        .rotate = SC_DIR, 
    };
    ret = g_lcd.init(&lcd_cfg);
    if (ESP_OK != ret)
    {
        ESP_LOGE(TAG, "screen initialize failed");
        return;
    }
    
    lvgl_init(&g_lcd);
    
    lv_8ms_init();
    
    lv_qm_ui_entry();
}
#endif
