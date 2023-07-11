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
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "freertos/ringbuf.h"
#include "lv_png.h"
#include "qmsd_notifier.h"
#include "esp_vfs_dev.h"
#include "esp_vfs_fat.h"

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
    qmsd_ui_storage_init("qmsd_ui_data", true);
    qmsd_set_ui_event_cb(qmsd_ui_cb);
    lv_png_init();
    qmsd_ui_entry();
}

extern esp_err_t qmsd_http_get_start(const char *url, const char *header, const char *user_agent);

static int __qmsd_nb_func(struct qmsd_notifier_block *nb, unsigned int action, void *data)
{
    if(action == QMSD_WIFI_STA_GOT_IP) {
        // start http get png
        qmsd_http_get_start("http://10.10.0.1:8080/test.png", NULL, NULL);
    }

    return QMSD_NOTIFY_OK;
}

extern void qmsd_test_init(void);

static struct qmsd_notifier_block g_nb = {
    .notifier_call = __qmsd_nb_func,
};


#define MOUNT_PATH "/img"

void app_main(void)
{
    printf("version: %s\n", QMSD_VERSION);
    nvs_flash_init();
    qmsd_storage_init();

    static wl_handle_t wl_handle;
    const esp_vfs_fat_mount_config_t mount_config = {
            .max_files = 10,
            .format_if_mount_failed = true
    };
    esp_err_t err = esp_vfs_fat_spiflash_mount(MOUNT_PATH, "img", &mount_config, &wl_handle);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "Failed to mount FATFS (%s)", esp_err_to_name(err));
        return;
    }

    qmsd_main_msgque_init(16);
    esp_event_loop_create_default();
    qmsd_mod_init();
    qmsd_notifier_register(&g_nb);
    qmsd_wifi_init(true);
    qmsd_wifi_set_mode(WIFI_MODE_STA);
    // set wifi sta config
    qmsd_wifi_sta_config("2G-TEST", "123456789", NULL);

    qmsd_set_init_cb(qmsd_ui_init_cb);

    qmsd_gui_init(0,DIR_INPUT);
}
