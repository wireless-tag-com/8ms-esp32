#include "qmsd_ui_entry.h"

void __qmsd_main_button_1_cb(lv_obj_t* obj,lv_event_t event)
{
    if (event==LV_EVENT_CLICKED)
    {
        printf("main btn1 pressed\n");
    }

    qmsd_call_ui_event_cb("main_button_1", obj, event);
}

void __qmsd_test_button_1_cb(lv_obj_t* obj,lv_event_t event)
{
    if (event==LV_EVENT_CLICKED)
    {
        printf("test btn1 pressed\n");
    }

    qmsd_call_ui_event_cb("test_button_1", obj, event);
}