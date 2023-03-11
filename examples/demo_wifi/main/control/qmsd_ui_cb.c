#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"
#include "lvgl.h"
#include "qmsd_ctrl.h"
#include "qmsd_ui_cb.h"
#include "qmsd_control.h"
#include "qmsd_msgque.h"
#include "qmsd_api.h"

void qmsd_ui_cb(const char *name, lv_obj_t* obj,lv_event_t event)
{
    if (event==LV_EVENT_CLICKED)
    {
        if (!strcmp(name, "test_button_1")) {
		qmsd_blufi_start();
        } else if (!strcmp(name, "main_button_1")) {
		qmsd_blufi_start();
        }
    }
}
