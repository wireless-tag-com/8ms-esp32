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
#include "qmsd_notifier.h"

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

static int __qmsd_got_encoder_func(struct qmsd_notifier_block *nb, unsigned int action, void *data)
{
    switch(action) {
    case ENCODER_LEFT:
        qmsd_gui_lock(portMAX_DELAY);
        screen_main_load();
        qmsd_gui_unlock();
        break;
    case ENCODER_RIGHT:
        qmsd_gui_lock(portMAX_DELAY);
        screen_test_load();
        qmsd_gui_unlock();
        break; 
    case ENCODER_SHORT_CLICK:
        qmsd_gui_lock(portMAX_DELAY);
        lv_obj_t *scr = lv_scr_act();
        if (scr == screen_main) {
            screen_test_load();
        } else if (scr == screen_test) {
            screen_main_load();
        }
        qmsd_gui_unlock();
    }

    return QMSD_NOTIFY_OK;
}

static struct qmsd_notifier_block got_encoder_event = {
    .notifier_call = __qmsd_got_encoder_func,
};

void app_main(void)
{
    printf("version: %s\n", QMSD_VERSION);
    qmsd_storage_init();

    qmsd_main_msgque_init(16);
    esp_event_loop_create_default();
    qmsd_mod_init();
    qmsd_notifier_register(&got_encoder_event);

    qmsd_set_init_cb(qmsd_ui_init_cb);

    qmsd_gui_init(0, DIR_INPUT);

    qmsd_control_init();
}
