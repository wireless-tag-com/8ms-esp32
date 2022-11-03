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
#include "esp_wifi.h"
#include "qmsd_api.h"
#include "qmsd_ctrl.h"
#include "qmsd_mod.h"

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

extern void board_init(void);
extern void wwe_init(void);
extern void wwe_init_model(void);
extern void wwe_stop(void);

void qmsd_ui_init_cb(void)
{
    /*
     * add some init, lang or other logic init
     */
    qmsd_ui_storage_init("qmsd_ui_data", true);
    qmsd_set_ui_event_cb(qmsd_ui_cb);
    qmsd_ui_entry();
    board_init();
}

static int __qmsd_nb_func(struct qmsd_notifier_block *nb, unsigned int action, void *data)
{
    if (action == QMSD_WIFI_STA_GOT_IP) {
        wifi_ap_record_t ap_info;
        qmsd_sntp_start("ntp1.aliyun.com", "cn.pool.ntp.org", "pool.ntp.org");

        esp_wifi_sta_get_ap_info(&ap_info);

        cJSON *root;
        cJSON *attr;
        root = cJSON_CreateObject();
        attr = cJSON_CreateObject();

        cJSON_AddStringToObject(root, "wid", "screen_wifi/label_net");
        cJSON_AddStringToObject(root, "cmd", QMSD_CTRL_CMD_SET_NAME);
        cJSON_AddStringToObject(attr, "action", "set_text");
        cJSON_AddStringToObject(attr, "text", "Connected!");
        cJSON_AddItemToObject(root, "attr", attr);
        char *str = cJSON_PrintUnformatted(root);
        if (str) {
            qmsd_ctrl_str(str);
            free(str);
        }
        cJSON_Delete(root);
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

    qmsd_wifi_init(true);
    qmsd_notifier_register(&g_nb);

    qmsd_set_init_cb(qmsd_ui_init_cb);

    wwe_init_model();
    wwe_init();
    vTaskDelay(pdMS_TO_TICKS(300));
    qmsd_gui_init(0, DIR_INPUT);

    qmsd_control_init();
}
