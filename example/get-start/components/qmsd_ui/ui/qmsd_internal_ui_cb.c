#include "qmsd_ui_entry.h"

void __qmsd_screen_main_button_1_cb(lv_obj_t* obj,qmsd_event_t event)
{
    if (event==LV_EVENT_CLICKED)
    {
        printf("main btn1 pressed\np1:%p\np2:%p\np3:%p\np4:%p\n",qmsd_gui_search_screen("screen_main"),qmsd_gui_search_screen("screen_test"),qmsd_gui_search_widget("screen_main/screen_main_button_1"),qmsd_gui_search_widget("screen_main/screen_test_button_1_label"));
        qmsd_screen_build(&screen_test_obj,true);
        printf("main btn1 handled\np1:%p\np2:%p\np3:%p\np4:%p\n",qmsd_gui_search_screen("screen_main"),qmsd_gui_search_screen("screen_test"),qmsd_gui_search_widget("screen_test/screen_test_button_1"),qmsd_gui_search_widget("screen_test/screen_test_button_1_label"));

    }

}

void __qmsd_screen_test_button_1_cb(lv_obj_t* obj,qmsd_event_t event)
{
    if (event==LV_EVENT_CLICKED)
    {
        printf("test btn1 pressed\np1:%p\np2:%p\np3:%p\np4:%p\n",qmsd_gui_search_screen("screen_main"),qmsd_gui_search_screen("screen_test"),qmsd_gui_search_widget("screen_main/screen_main_button_1"),qmsd_gui_search_widget("screen_main/screen_test_button_1_label"));
        qmsd_screen_build(&screen_main_obj,true);
        qmsd_screen_delete(&screen_test_obj);
        printf("test btn1 handled\np1:%p\np2:%p\np3:%p\np4:%p\n",qmsd_gui_search_screen("screen_main"),qmsd_gui_search_screen("screen_test"),qmsd_gui_search_widget("screen_test/screen_test_button_1"),qmsd_gui_search_widget("screen_test/screen_test_button_1_label"));
    }
}