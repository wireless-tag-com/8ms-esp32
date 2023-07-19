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
#include "qmsd_api.h"
#include "qmsd_ctrl.h"


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

extern void qmsd_test_init(void);

static int __qmsd_got_ip_func(struct qmsd_notifier_block *nb, unsigned int action, void *data)
{
    if(action == QMSD_WIFI_STA_GOT_IP)
    {
        wifi_ap_record_t ap_info;
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
        qmsd_ctrl_str(str);
        free(str);
    }
    return 0;
}

static struct qmsd_notifier_block got_ip_event = {
    .notifier_call = __qmsd_got_ip_func,
};

void app_main(void)
{
    printf("version: %s\n", QMSD_VERSION);
    qmsd_storage_init();
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
      ESP_ERROR_CHECK(nvs_flash_erase());
      ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);

    qmsd_main_msgque_init(16);
    esp_event_loop_create_default();
    qmsd_mod_init();

    qmsd_test_init();
    qmsd_wifi_init(true);
    qmsd_wifi_set_mode(WIFI_MODE_STA);
	qmsd_wifi_sta_config("TEST", "12345678", NULL);
    qmsd_set_init_cb(qmsd_ui_init_cb);
    qmsd_notifier_register(&got_ip_event);
    qmsd_gui_init(0,DIR_INPUT);

    qmsd_control_init();
}
