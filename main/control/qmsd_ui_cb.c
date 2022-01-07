#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"
#include "lvgl.h"
#include "qmsd_ctrl.h"
#include "qmsd_ui_cb.h"
#include "qmsd_control.h"
#include "qmsd_ui_entry.h"

void qmsd_ui_cb(const char *name, lv_obj_t* obj,lv_event_t event)
{
    printf("%s %d\n", name, event);
    if (event==LV_EVENT_CLICKED)
    {
        if (!strcmp(name, "test_button_1")) {
            cJSON *attr;

            attr = cJSON_CreateObject();

            if (attr) {
                cJSON_AddStringToObject(attr, "action", "switch");
                qmsd_ctrl_cjson_gui("main", QMSD_CTRL_SET_STATUS, attr);

                cJSON_Delete(attr);
            }
        } else if (!strcmp(name, "main_button_1")) {
            cJSON *attr;

            attr = cJSON_CreateObject();

            if (attr) {
                cJSON_AddStringToObject(attr, "action", "switch");
                qmsd_ctrl_cjson_gui("test", QMSD_CTRL_SET_STATUS, attr);

                cJSON_Delete(attr);
            }            
        }
    }
}