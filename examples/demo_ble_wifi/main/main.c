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
#include "sd.h"

#include "mqtt.h"

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

static int __qmsd_nb_func(struct qmsd_notifier_block *nb, unsigned int action, void *data)
{
    if (action == QMSD_WIFI_STA_GOT_IP) {
        ESP_LOGI(TAG, "wifi get ip, start ntp and mqtt");
        qmsd_sntp_start("ntp1.aliyun.com", "cn.pool.ntp.org", "pool.ntp.org");
        qmsd_mqtt_app_start();
    } else if (action == QMSD_WIFI_STA_DISCONNECT) {
        qmsd_mqtt_app_stop();
    } else if (action == QMSD_MQTT_EVENT_CONNECTED) {
        ESP_LOGI(TAG, "mqtt connect");
    } else if (action == QMSD_MQTT_EVENT_DISCONNECTED) {
        ESP_LOGI(TAG, "mqtt disconnect");
    } else if (action == QMSD_MQTT_EVENT_DATA) {
        esp_mqtt_event_handle_t event = data;
        ESP_LOGI(TAG, "mqtt: %s/%s/%d", event->topic, event->data, event->data_len);
    } else if (action == QMSD_SYSTEM_OTA_OK) {
        ESP_LOGI(TAG, "ota ok\n");
    } else if (action == QMSD_SNTP_OK) {
        time_t saver_time;
        struct tm saver_timeinfo;
        qmsd_get_time(&saver_time);
        localtime_r(&saver_time, &saver_timeinfo);
        ESP_LOGI(TAG, "time: %02d:%02d", (saver_timeinfo.tm_hour),saver_timeinfo.tm_min);
    }

    return QMSD_NOTIFY_OK;
}

static struct qmsd_notifier_block g_nb = {
    .notifier_call = __qmsd_nb_func,
};

extern void qmsd_test_init(void);

void app_main(void)
{
    printf("version: %s\n", QMSD_VERSION);
    qmsd_storage_init();

    qmsd_main_msgque_init(16);
    esp_event_loop_create_default();
    qmsd_mod_init();
    qmsd_notifier_register(&g_nb);

    qmsd_set_tz("CST-8");
    qmsd_use_buildtime();

    qmsd_wifi_init(true);

    qmsd_set_init_cb(qmsd_ui_init_cb);

    qmsd_test_init();
#ifdef CONFIG_ZX3D50CE02S_USRC_4832
    sd_card_init();
#endif
    qmsd_gui_init(0, DIR_INPUT);
    qmsd_control_init();
}
