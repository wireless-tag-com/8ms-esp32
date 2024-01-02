#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "freertos/semphr.h"
#include "driver/gpio.h"
#include "driver/spi_master.h"
#include "esp_freertos_hooks.h"
#include "esp_log.h"
#include "esp_lcd_panel_io.h"
#include "esp_lcd_panel_vendor.h"
#include "esp_lcd_panel_ops.h"
#include "esp_lcd_panel_interface.h"
#include "qmsd_lcd_rgb_panel.h"
#include "lvgl.h"

#if SOC_LCD_RGB_SUPPORTED
#define TAG "RGB"

esp_lcd_panel_handle_t g_panel_handle = NULL;

static QueueHandle_t g_qmsd_rgb_queue;
typedef struct  {
    lv_color_t *color;
    lv_area_t area;
    lv_disp_drv_t *drv;
} __packed lv_flush_data_t;

SemaphoreHandle_t g_qmsd_rgb_flush_done;

extern int Cache_WriteBack_Addr(uint32_t addr, uint32_t size);

static SemaphoreHandle_t trans_ready = NULL;
static SemaphoreHandle_t flush_ready = NULL;
static void qmsd_rgb_lcd_task(void *args);

extern int Cache_WriteBack_Addr(uint32_t addr, uint32_t size);

IRAM_ATTR static bool __lcd_vsync_event(void)
{
    BaseType_t high_task_awoken = pdFALSE;

    xSemaphoreGiveFromISR(trans_ready, &high_task_awoken);
    xSemaphoreGiveFromISR(flush_ready, &high_task_awoken);

    return high_task_awoken == pdTRUE;
}

static void qmsd_rgb_lcd_task(void *args)
{
    TickType_t tick;
    for (;;) {
        tick = xTaskGetTickCount();
        xSemaphoreTake(trans_ready, portMAX_DELAY);
        vTaskDelayUntil(&tick, pdMS_TO_TICKS(20));
        qsmd_lcd_rgb_panel_refresh(g_panel_handle);
        xSemaphoreTake(flush_ready, 0);
    }
}

static IRAM_ATTR void __qmsd_rgb_flush(void *arg)
{
    (void)arg;
    lv_flush_data_t show_data;
    for (;;) {
        if (xQueueReceive(g_qmsd_rgb_queue, &show_data, portMAX_DELAY) == pdTRUE) {
            uint16_t w = show_data.area.x2 - show_data.area.x1 + 1;
            uint16_t h = show_data.area.y2 - show_data.area.y1 + 1;
            Cache_WriteBack_Addr((uint32_t)show_data.color, (w * h) << 1);
            qmsd_lcd_buffer_select(g_panel_handle, (uint8_t *)show_data.color);
            lv_disp_flush_ready(show_data.drv);
            xSemaphoreGive(g_qmsd_rgb_flush_done);
        }
    }
}

static IRAM_ATTR void qmsd_rgb_tear_flush(lv_disp_drv_t * drv, const lv_area_t * area, lv_color_t * color_map)
{
    uint16_t w = area->x2 - area->x1 + 1;
    uint16_t h = area->y2 - area->y1 + 1;
    Cache_WriteBack_Addr((uint32_t)color_map, (w * h) << 1);

    qmsd_lcd_buffer_select(g_panel_handle, (uint8_t *)color_map);
    xSemaphoreTake(flush_ready, portMAX_DELAY);

    lv_disp_flush_ready(drv);
}

static IRAM_ATTR void qmsd_rgb_flush(lv_disp_drv_t * drv, const lv_area_t * area, lv_color_t * color_map)
{
    lv_flush_data_t show_data;
    memcpy(&(show_data.area), area, sizeof(lv_area_t));
    show_data.color = color_map;
    show_data.drv = drv;

    xQueueSend(g_qmsd_rgb_queue, (void *)&show_data, portMAX_DELAY);
}

static IRAM_ATTR void qmsd_rgb_wait_cb(lv_disp_drv_t *drv)
{
    xSemaphoreTake(g_qmsd_rgb_flush_done, portMAX_DELAY);
}

void qmsd_rgb_init(qmsd_lcd_rgb_panel_config_t *panel_config)
{
    g_qmsd_rgb_queue = xQueueCreate(2, sizeof(lv_flush_data_t));
    g_qmsd_rgb_flush_done = xSemaphoreCreateBinary();
    xSemaphoreGive(g_qmsd_rgb_flush_done); // initialize the semaphore count to 1

    qmsd_lcd_new_rgb_panel(panel_config, &g_panel_handle);

    esp_lcd_panel_reset(g_panel_handle);
    esp_lcd_panel_init(g_panel_handle);

    qmsd_lcd_rgb_panel_start(g_panel_handle);
    static lv_disp_buf_t draw_buf;

    lv_color_t *buf1;
    lv_color_t *buf2;

    qmsd_lcd_rgb_panel_get_buffer(g_panel_handle, (uint8_t **)&buf1, (uint8_t **)&buf2);
    
    lv_disp_buf_init(&draw_buf, buf1, buf2, panel_config->timings.h_res * panel_config->timings.v_res);

    static lv_disp_drv_t disp_drv;     
    lv_disp_drv_init(&disp_drv);         
    disp_drv.flush_cb = qmsd_rgb_flush;
    disp_drv.buffer = &draw_buf;
    disp_drv.hor_res = panel_config->timings.h_res;
    disp_drv.ver_res = panel_config->timings.v_res;; 

#if 0
    if (panel_config->bounce_buffer_size_px == 0) {
        disp_drv.flush_cb = qmsd_rgb_tear_flush;
        lv_disp_drv_register(&disp_drv);
        qmsd_lcd_rgb_panel_register_vsync(g_panel_handle, __lcd_vsync_event);
        trans_ready = xSemaphoreCreateBinary();
        assert(trans_ready);
        xSemaphoreGive(trans_ready);
        flush_ready = xSemaphoreCreateBinary();
        assert(flush_ready);
        xTaskCreate(qmsd_rgb_lcd_task, "qmsd_lcd_task", 2048, NULL, 5, NULL);
    } else {
#endif
        disp_drv.flush_cb = qmsd_rgb_flush;
        disp_drv.wait_cb = qmsd_rgb_wait_cb;
        lv_disp_drv_register(&disp_drv);
        xTaskCreatePinnedToCore(__qmsd_rgb_flush, "qmsd_rgb_flush", 4 * 1024, NULL, 5, NULL, 0);
}
#endif
