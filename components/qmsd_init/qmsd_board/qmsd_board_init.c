#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "sdkconfig.h"
#include "qmsd_gui_init.h"
#include "esp_log.h"
#include "sdkconfig.h"
#include "qmsd_screen_config.h"
#include "esp_freertos_hooks.h"
#include "esp_system.h"
#include "driver/gpio.h"
#include "esp_task_wdt.h"
#include "screen_driver.h"
#include "qmsd_ctrl.h"
#include "qmsd_gui.h"
#include "touch_panel.h"

#define TAG "QMSD BOARD INIT"

scr_driver_t *g_lcd;
touch_panel_driver_t g_touch;

__attribute__((weak)) void qmsd_disp_wait(uint32_t x, uint32_t y)
{

}
static void ex_disp_flush(lv_disp_drv_t *drv, const lv_area_t *area, lv_color_t *color_map)
{
    qmsd_disp_wait(area->x2-area->x1+1, area->y2-area->y1+1);
    if (g_lcd)
        g_lcd->draw_bitmap(area->x1, area->y1, (uint16_t)(area->x2 - area->x1 + 1), (uint16_t)(area->y2 - area->y1 + 1), (uint16_t *)color_map);
    /* IMPORTANT!!!
     * Inform the graphics library that you are ready with the flushing*/
    lv_disp_flush_ready(drv);
}

esp_err_t lvgl_display_init(int w, int h, void * buf1, void * buf2, uint32_t size_in_px_cnt)
{
#ifdef CONFIG_WT154_S2MI1
    gpio_pad_select_gpio(GPIO_NUM_20);
    gpio_set_direction(GPIO_NUM_20, GPIO_MODE_INPUT);
#endif

    lv_disp_drv_t disp_drv;

    lv_disp_drv_init(&disp_drv);
    disp_drv.hor_res = w;
    disp_drv.ver_res = h;
    disp_drv.flush_cb = ex_disp_flush; /*Used in buffered mode (LV_VDB_SIZE != 0  in lv_conf.h)*/

    static lv_disp_buf_t disp_buf;

    lv_disp_buf_init(&disp_buf, buf1, buf2, size_in_px_cnt);

    disp_drv.buffer = &disp_buf;

    /* Finally register the driver */
    lv_disp_drv_register(&disp_drv);

    return ESP_OK;
}

static bool ex_tp_read(struct _lv_indev_drv_t *indev_drv, lv_indev_data_t *data)
{
    data->state = LV_INDEV_STATE_REL;
    touch_panel_points_t points;
    g_touch.read_point_data(&points);

    // please be sure that your touch driver every time return old (last clcked) value.
    if (TOUCH_EVT_PRESS == points.event) {
        int32_t x = points.curx[0];
        int32_t y = points.cury[0];
        data->point.x = x;
        data->point.y = y;
        data->state = LV_INDEV_STATE_PR;
        return false;
    }

    return false;
}

/* Input device interface，Initialize your touchpad */
esp_err_t lvgl_indev_init(touch_panel_driver_t *driver)
{
    if (NULL == driver) {
        ESP_LOGE(TAG, "Pointer of touch driver is invalid");
        return ESP_ERR_INVALID_ARG;
    }

    lv_indev_drv_t indev_drv;               /*Descriptor of an input device driver*/
    lv_indev_drv_init(&indev_drv);          /*Basic initialization*/

    indev_drv.type = LV_INDEV_TYPE_POINTER; /*The touchpad is pointer type device*/
    indev_drv.read_cb = ex_tp_read;            /*Library ready your touchpad via this function*/

    lv_indev_drv_register(&indev_drv);      /*Finally register the driver*/
    return ESP_OK;
}

extern qmsd_board_init_cus g_qmsd_board_init;

void qmsd_bkl_ctrl(int level)
{
    if(g_qmsd_board_init||BOARD_BKL_PIN<0) return;
    gpio_pad_select_gpio(BOARD_BKL_PIN);
    gpio_set_direction(BOARD_BKL_PIN, GPIO_MODE_OUTPUT);
    gpio_set_level(BOARD_BKL_PIN, level);
}

