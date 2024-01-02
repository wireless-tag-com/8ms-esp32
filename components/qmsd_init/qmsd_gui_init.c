#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "freertos/semphr.h"
#include "freertos/queue.h"
#include "freertos/timers.h"
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
#include "qmsd_msgque.h"
#include "qmsd_board_init.h"

#define QMSD_MSG_MAX  16

#ifndef CUSTOM_DISPLAY_BUFFER_BYTES
#define QMSD_BOARD_INIT_BUF_SIZE 0
#else
#define QMSD_BOARD_INIT_BUF_SIZE CUSTOM_DISPLAY_BUFFER_BYTES
#endif

static const char *TAG = "QMSD";

static qmsd_gui_mode_t g_gui_mode = QMSD_GUI_MODE_PERFORMENCE;

#define PIXEL_TO_SIZE(v) ((v) * sizeof(lv_color_t))
extern void qmsd_init(void);
// wait for execute lv_task_handler and lv_tick_inc to avoid some widget don't refresh.
#define LVGL_TICK_MS 10
#define QMSD_TIMER_PERIOD 20

uint32_t g_dis_buf_size=0;
uint8_t g_scr_dir=0;

static uint32_t g_qmsd_gui_task_size;

#if LV_TICK_CUSTOM == 1
IRAM_ATTR uint32_t custom_tick_get(void)
{
    static uint32_t qmsd_tick_start = 0;
    uint32_t qmsd_tick_now;
    uint32_t qmsd_tick_elaps;

    if (qmsd_tick_start == 0) {
        qmsd_tick_start = xTaskGetTickCount();
    }

    qmsd_tick_now = xTaskGetTickCount();

    /*If there is no overflow in sys_time simple subtract*/
    if(qmsd_tick_now >= qmsd_tick_start) {
        qmsd_tick_elaps = qmsd_tick_now - qmsd_tick_start;
    }
    else {
        qmsd_tick_elaps = UINT32_MAX - qmsd_tick_start + 1;
        qmsd_tick_elaps += qmsd_tick_now;
    }

    return (qmsd_tick_now - qmsd_tick_start) * portTICK_PERIOD_MS;
}
#else
static void lv_tick_timercb(void *timer)
{
    lv_tick_inc(LVGL_TICK_MS);
}
#endif

/* Creates a semaphore to handle concurrent call to lvgl stuff
 * If you wish to call *any* lvgl function from other threads/tasks
 * you should lock on the very same semaphore! */
static SemaphoreHandle_t xGuiSemaphore = NULL;

static qmsd_init_cb g_qmsd_init_cb;
qmsd_board_init_cus g_qmsd_board_init;
static qmsd_gui_loop_cb g_qmsd_gui_loop_cb;

void qmsd_set_init_cb(qmsd_init_cb init_cb)
{
    g_qmsd_init_cb = init_cb;
}

void qmsd_set_board_init_cus(qmsd_board_init_cus init_cus)
{
    g_qmsd_board_init = init_cus;
}

void qmsd_gui_set_loop_cb(qmsd_gui_loop_cb l_cb)
{
    g_qmsd_gui_loop_cb = l_cb;
}

int qmsd_gui_lock(uint32_t timeout)
{
	if (!xGuiSemaphore)
		return -1;
    if (pdTRUE == xSemaphoreTake(xGuiSemaphore, timeout)) {
        return 0;
    } else {
        return -1;
    }
}

void qmsd_gui_unlock(void)
{
	if (xGuiSemaphore)
    		xSemaphoreGive(xGuiSemaphore);
}

static void __qmsd_gui_task(void *args)
{
    /* Initialize LittlevGL */
    lv_init();

    if (g_qmsd_board_init)
        g_qmsd_board_init(g_scr_dir);
    else
        qmsd_board_init(g_scr_dir);

#if LV_TICK_CUSTOM == 0
    esp_timer_create_args_t timer_conf = {
        .callback = lv_tick_timercb,
        .name = "lv_tick_timer"};
    esp_timer_handle_t g_qmsd_tick_timer = NULL;
    esp_timer_create(&timer_conf, &g_qmsd_tick_timer);
    esp_timer_start_periodic(g_qmsd_tick_timer, LVGL_TICK_MS * 1000U);
#endif

    /*
     * init msgque
     */
    qmsd_msgque_init(QMSD_MSG_MAX);

    xGuiSemaphore = xSemaphoreCreateMutex();
    qmsd_init();

    ESP_LOGI(TAG,"%s(%d) %s %s", QMSD_PROJECT_VER, LV_COLOR_DEPTH, __TIME__, __DATE__);
    ESP_LOGI(TAG, "LVGL inited,Ver:%s Mem left:%d Bytes",QMSD_LVGL_ADDON_VERSION,heap_caps_get_free_size(MALLOC_CAP_INTERNAL | MALLOC_CAP_8BIT));

    if (g_qmsd_init_cb)
        g_qmsd_init_cb();

    while (1)
    {
        uint32_t handler_start = lv_tick_get();
        uint32_t handler_end;
        void *msg;
        unsigned int msglen;
        int ret_msg;

        
        ret_msg = qmsd_msgque_recv((void **)&msg, &msglen, pdMS_TO_TICKS(1));
        if (ret_msg < 0) {
            msglen = 0;
        }

        if (qmsd_gui_lock(portMAX_DELAY) == 0) {
            if (msglen > 0) {
                char *res;
                res = qmsd_ctrl_str_gui(msg);
                if (res) {
                    free(res);
                }
                free(msg);
            }

            lv_task_handler();
            qmsd_gui_unlock();
        }

        if (g_qmsd_gui_loop_cb) {
            g_qmsd_gui_loop_cb();
        }

        handler_end = lv_tick_elaps(handler_start);
        if (handler_end > 30) {
            vTaskDelay(pdMS_TO_TICKS(5));
        } else {
            vTaskDelay(pdMS_TO_TICKS(10));
        }
    }
}

void qmsd_gui_set_mode(qmsd_gui_mode_t mode)
{
    g_gui_mode = mode;
}

qmsd_gui_mode_t qmsd_gui_get_mode(void)
{
    return g_gui_mode;
}

void qmsd_gui_set_task_size(uint32_t task_size)
{
    g_qmsd_gui_task_size = task_size;
}

esp_err_t qmsd_gui_init(uint32_t custom_fb_size, uint8_t dir)
{
    /* If you want to use a task to create the graphic, you NEED to create a Pinned task
      * Otherwise there can be problem such as memory corruption and so on.
      * NOTE: When not using Wi-Fi nor Bluetooth you can pin the gui_task to core 0 */
    esp_chip_info_t chip_info;
    esp_chip_info(&chip_info);

    g_scr_dir= dir;

    if (custom_fb_size)
    {
        g_dis_buf_size = custom_fb_size;
    }
    
    if (g_qmsd_gui_task_size > 16 * 1024) {
        xTaskCreatePinnedToCore(__qmsd_gui_task, "qmsd gui", g_qmsd_gui_task_size, NULL, 5, NULL, chip_info.cores - 1);
    } else {
        xTaskCreatePinnedToCore(__qmsd_gui_task, "qmsd gui", 1024 * 16, NULL, 5, NULL, chip_info.cores - 1);
    }
    return ESP_OK;
}

static qmsd_ui_event_cb g_qmsd_ui_event_cb;

void qmsd_set_ui_event_cb(qmsd_ui_event_cb init_cb)
{
    g_qmsd_ui_event_cb = init_cb;
}

void qmsd_call_ui_event_cb(const char *obj_name, lv_obj_t* obj,lv_event_t event)
{
    if (g_qmsd_ui_event_cb) {
        g_qmsd_ui_event_cb(obj_name, obj, event);
    }
}

lv_group_t *qmsd_create_group(void)
{
    lv_group_t *group = lv_group_create();

    if (group) {
        for (lv_indev_t *cur_drv = lv_indev_get_next(NULL); cur_drv != NULL; cur_drv = lv_indev_get_next(cur_drv))
        {
            if (cur_drv->driver.type == LV_INDEV_TYPE_ENCODER)
            {
                lv_indev_set_group(cur_drv, group);
            }
        }
    }

    return group;
}
