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
#include "cJSON.h"
#include "qmsd_control.h"
#include "qmsd_ui_entry.h"
#include "qmsd_ui_cb.h"
#include "qmsd_blockly.h"

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

    qmsd_set_ui_event_cb(qmsd_ui_cb);
    qmsd_ui_entry();

    lv_group_add_obj(qmsd_get_group(), button_light);
    lv_group_add_obj(qmsd_get_group(), button_curtain);
    lv_group_add_obj(qmsd_get_group(), button_control);
    lv_group_add_obj(qmsd_get_group(), button_conditioner);
    lv_obj_set_style_local_bg_color(button_light, LV_LABEL_PART_MAIN, LV_STATE_FOCUSED, LV_COLOR_BLUE);
    lv_obj_set_style_local_bg_color(button_curtain, LV_LABEL_PART_MAIN, LV_STATE_FOCUSED, LV_COLOR_BLUE);
    lv_obj_set_style_local_bg_color(button_conditioner, LV_LABEL_PART_MAIN, LV_STATE_FOCUSED, LV_COLOR_BLUE);
    lv_obj_set_style_local_bg_color(button_control, LV_LABEL_PART_MAIN, LV_STATE_FOCUSED, LV_COLOR_BLUE);
}

void app_main(void)
{
    qmsd_storage_init();

    qmsd_set_init_cb(qmsd_ui_init_cb);
    qmsd_gui_init(0);

    qmsd_control_init();
}
