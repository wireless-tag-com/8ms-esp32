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

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "nvs_flash.h"
#include"qmsd_gui_init.h"
#include "qmsd_control.h"
#include "qmsd_ui_entry.h"
#include "qmsd_ui_cb.h"
#include "qmsd_storage.h"
#include "qmsd_ui_storage.h"
#include "qmsd_msgque.h"
#include "qmsd_screen_config.h"
#include "qmsd_version.h"
#include "qmsd_mod.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "freertos/ringbuf.h"
#include "lv_freetype.h"

/*********************
 *      DEFINES
 *********************/
#define TAG "main"

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *   APPLICATION MAIN
 **********************/

RingbufHandle_t g_buf_handle;

lv_ft_info_t g_ttf_info;
lv_style_t g_ttf_style;

extern const uint8_t font_ttf_start[] asm("_binary_font_ttf_start");
extern const uint8_t font_ttf_end[]   asm("_binary_font_ttf_end");

void qmsd_ui_init_cb(void)
{
    /*
     * add some init, lang or other logic init
     */

    lv_freetype_init(64, 1, 0);

    g_ttf_info.name = "8ms.ttf";
    g_ttf_info.weight = 18;
    g_ttf_info.style = FT_FONT_STYLE_NORMAL;
    g_ttf_info.mem = (void *)font_ttf_start;
    g_ttf_info.mem_size = font_ttf_end - font_ttf_start - 1;
    lv_ft_font_init(&g_ttf_info);

    lv_style_init(&g_ttf_style);
    lv_style_set_text_font(&g_ttf_style, LV_STATE_DEFAULT, g_ttf_info.font);
    lv_style_set_text_color(&g_ttf_style, LV_STATE_DEFAULT, LV_COLOR_WHITE);
    lv_style_set_text_line_space(&g_ttf_style, LV_STATE_DEFAULT, 0);

    if(!lv_ft_font_init(&g_ttf_info)) {
        LV_LOG_ERROR("create failed.");
    }

    qmsd_ui_storage_init("qmsd_ui_data", true);
    qmsd_set_ui_event_cb(qmsd_ui_cb);
    qmsd_ui_entry();
}

void qmsd_ui_loop_cb(void)
{
    if (g_buf_handle) {
        size_t item_size;
        /*
         * recv ble data
         */
        char *item = (char *)xRingbufferReceive(g_buf_handle, &item_size, pdMS_TO_TICKS(10));

        if (item) {
            char *str = malloc(item_size + 1);
            if (str) {
                memset(str, 0, item_size + 1);
                memcpy(str, item, item_size);
                qmsd_update_7038(str);
                free(str);
            }
            vRingbufferReturnItem(g_buf_handle, (void *)item);
        }
    }
}
extern void qmsd_gatts_start(void);

void app_main(void)
{
    printf("version: %s\n", QMSD_VERSION);
    nvs_flash_init();
    qmsd_storage_init();

    qmsd_main_msgque_init(16);
    esp_event_loop_create_default();
    qmsd_mod_init();

    g_buf_handle = xRingbufferCreate(4096, RINGBUF_TYPE_NOSPLIT);

    /*
     * ui loop cb
     */
    qmsd_gui_set_loop_cb(qmsd_ui_loop_cb);
    /*
     * use freetype need 64K task stack size
     */
    qmsd_gui_set_task_size(64 * 1024);
    qmsd_set_init_cb(qmsd_ui_init_cb);

    qmsd_gui_init(0,DIR_INPUT);

	qmsd_gatts_start();
}
