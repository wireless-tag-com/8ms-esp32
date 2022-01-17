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
    if (event == LV_EVENT_SHORT_CLICKED)
    {
        if (!strcmp(name, "button_light"))
        {
            lv_group_remove_all_objs(qmsd_get_group());
            lv_group_add_obj(qmsd_get_group(), button_screen_light);
            screen_light_show();
        }
        else if (!strcmp(name, "button_curtain"))
        {
            lv_group_remove_all_objs(qmsd_get_group());
            lv_group_add_obj(qmsd_get_group(), button_screen_curtain);
            screen_curtain_show();
        }
        else if (!strcmp(name, "button_conditioner"))
        {
            lv_group_remove_all_objs(qmsd_get_group());
            lv_group_add_obj(qmsd_get_group(), button_screen_condition);
            screen_condition_show();
        }
        else if (!strcmp(name, "button_control"))
        {
            lv_group_remove_all_objs(qmsd_get_group());
            lv_group_add_obj(qmsd_get_group(), button_screen_control);
            screen_control_show();
        }
    }

    if (event == LV_EVENT_LONG_PRESSED)
    {
        if ((!strcmp(name, "button_screen_control") || !strcmp(name, "button_screen_condition") || !strcmp(name, "button_screen_curtain") || !strcmp(name, "button_screen_light")))
        {
            lv_group_remove_all_objs(qmsd_get_group());
            lv_group_add_obj(qmsd_get_group(), button_light);
            lv_group_add_obj(qmsd_get_group(), button_curtain);
            lv_group_add_obj(qmsd_get_group(), button_control);
            lv_group_add_obj(qmsd_get_group(), button_conditioner);
            screen_main_show();
            // printf("name: %s\n", name);
        }
    }
}