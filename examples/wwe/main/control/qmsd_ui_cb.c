#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"
#include "lvgl.h"
#include "qmsd_ctrl.h"
#include "qmsd_ui_cb.h"
#include "qmsd_control.h"
#include "qmsd_msgque.h"

void qmsd_ui_cb(const char *name, lv_obj_t* obj,lv_event_t event)
{
    if (event==LV_EVENT_CLICKED)
    {
        if (!strcmp(name, "test_button_1")) {
            cJSON *attr;

            attr = cJSON_CreateObject();

            if (attr) {
                char *j_str;
                cJSON_AddStringToObject(attr, "action", "switch");
                qmsd_ctrl_cjson_gui("screen_main", QMSD_CTRL_SET_STATUS, attr);

                j_str = cJSON_PrintUnformatted(attr);
                qmsd_main_msgque_send(j_str, strlen(j_str), portMAX_DELAY);
                cJSON_Delete(attr);
            }
        } else if (!strcmp(name, "main_button_1")) {
            cJSON *attr;


            attr = cJSON_CreateObject();

            if (attr) {
                char *j_str;
                cJSON_AddStringToObject(attr, "action", "switch");
                qmsd_ctrl_cjson_gui("screen_test", QMSD_CTRL_SET_STATUS, attr);

                j_str = cJSON_PrintUnformatted(attr);
                qmsd_main_msgque_send(j_str, strlen(j_str), portMAX_DELAY);
                cJSON_Delete(attr);
            }            
        }
    }
}