#include "qmsd_ui_entry.h"
#include "qmsd_lang.h"
#include "qmsd_api.h"
#include "qmsd_storage.h"

void __qmsd_button_5cb9_cb(lv_obj_t* obj,lv_event_t event)
{
    if (event == LV_EVENT_CLICKED)
    {
	    // 开启 blufi
        qmsd_blufi_start();
    }
}

void __qmsd_button_e490_cb(lv_obj_t* obj,lv_event_t event)
{
    if (event==LV_EVENT_CLICKED)
    {
	    // 开启 smartconfig
        qmsd_wifi_sc_start(SC_TYPE_ESPTOUCH_V2);
    }
}

void __qmsd_button_d2c4_cb(lv_obj_t* obj,lv_event_t event)
{
    if (event==LV_EVENT_CLICKED)
    {
        // 恢复出厂
	    qmsd_storage_clear_all();
	    esp_restart();
    }
}

