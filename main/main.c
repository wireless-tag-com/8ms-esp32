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
#include "qmsd_board_init.h"

#ifndef CUSTOM_DISPLAY_BUFFER_BYTES
#define QMSD_BOARD_INIT_BUF_SIZE 0
#else
#define QMSD_BOARD_INIT_BUF_SIZE CUSTOM_DISPLAY_BUFFER_BYTES
#endif

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
}

void app_main(void)
{
    printf("MEM%d\n",heap_caps_get_free_size(MALLOC_CAP_INTERNAL | MALLOC_CAP_8BIT));
    qmsd_storage_init();

    qmsd_set_init_cb(qmsd_ui_init_cb);

    scr_driver_t* driver = qmsd_board_init(QMSD_BOARD_INIT_BUF_SIZE);
    qmsd_gui_init(driver,QMSD_BOARD_INIT_BUF_SIZE);

    qmsd_control_init();
}
