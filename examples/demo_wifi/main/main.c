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
#include "qmsd_api.h"

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

void qmsd_ui_init_cb(void)
{
    /*
     * add some init, lang or other logic init
     */

    qmsd_ui_storage_init("qmsd_ui_data", true);
    qmsd_set_ui_event_cb(qmsd_ui_cb);
    qmsd_ui_entry();
}

extern void qmsd_lable_ip_set(const char *ip);

static int __qmsd_nb_func(struct qmsd_notifier_block *nb, unsigned int action, void *data)
{
    if (action == QMSD_WIFI_STA_GOT_IP) {
        ip_event_got_ip_t *event;
        char ip_buf[64];

        event = (ip_event_got_ip_t*)data;
        memset(ip_buf, 0, sizeof(ip_buf));
        sprintf(ip_buf, "%d.%d.%d.%d", IP2STR(&event->ip_info.ip));
        qmsd_gui_lock(portMAX_DELAY);
        qmsd_lable_ip_set(ip_buf);
        qmsd_gui_unlock();
    }

    return QMSD_NOTIFY_OK;
}

static struct qmsd_notifier_block g_nb = {
    .notifier_call = __qmsd_nb_func,
};

void app_main(void)
{
    printf("version: %s\n", QMSD_VERSION);
    qmsd_storage_init();

    qmsd_main_msgque_init(16);
    esp_event_loop_create_default();
    qmsd_mod_init();
    qmsd_notifier_register(&g_nb);

    qmsd_wifi_init(true);
    // 手动设置SSID和密码
    //qmsd_wifi_sta_config("test-ssid", "test-pwd111", NULL);

    qmsd_set_init_cb(qmsd_ui_init_cb);

    qmsd_gui_init(0, DIR_INPUT);
    qmsd_control_init();
}
