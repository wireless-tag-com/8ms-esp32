#include "qmsd_ui_entry.h"
#include "qmsd_lang.h"

    void __qmsd_button_left_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  screen_filter_show();
  screen_main_delete();
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_button_hu_left_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  screen_main_show();
  screen_humidity_delete();
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_button_right_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  screen_humidity_show();
  screen_main_delete();
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_button_hu_right_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  screen_water_b_show();
  screen_humidity_delete();
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_button_w_left_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  screen_humidity_show();
  screen_water_b_delete();
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_button_f_left_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  screen_water_b_show();
  screen_filter_delete();
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_button_w_right_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  screen_filter_show();
  screen_water_b_delete();
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_button_f_right_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  screen_main_show();
  screen_filter_delete();
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}
