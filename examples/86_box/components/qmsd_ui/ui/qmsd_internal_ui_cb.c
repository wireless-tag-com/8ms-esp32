#include "qmsd_ui_entry.h"
#include "qmsd_lang.h"
#include "qmsd_api.h"

#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "esp_bt.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_blufi.h"
static wifi_config_t sta_config;
static wifi_config_t ap_config;
#define BLUFI_EXAMPLE_TAG "BLUFI_EXAMPLE"
#define BLUFI_INFO(fmt, ...)   ESP_LOGI(BLUFI_EXAMPLE_TAG, fmt, ##__VA_ARGS__)
#define BLUFI_ERROR(fmt, ...)  ESP_LOGE(BLUFI_EXAMPLE_TAG, fmt, ##__VA_ARGS__)
/* FreeRTOS event group to signal when we are connected & ready to make a request */
static EventGroupHandle_t wifi_event_group;

/* The event group allows multiple bits for each event,
   but we only care about one event - are we connected
   to the AP with an IP? */

/* store the station info for send back to phone */
static bool gl_sta_connected = false;
static bool ble_is_connected = false;
static uint8_t gl_sta_bssid[6];
static uint8_t gl_sta_ssid[32];
static int gl_sta_ssid_len;
int8_t theme_used = 0; 
void redrag_obj(lv_anim_t * a) {
  lv_obj_set_drag(cont_top,true);
  if (((int)lv_obj_get_y(cont_top)) < -100) {
    lv_obj_set_style_local_bg_opa(cont_top,0,0,120);
  } else {
    lv_obj_set_style_local_bg_opa(cont_top,0,0,255);
  }

}

static bool wifi_init = false; 
void set_bar(lv_obj_t* obj,int16_t num) {
  lv_bar_set_value(obj,num,LV_ANIM_OFF);

}

void obj_move(lv_obj_t* obj,int y_start,int y_end) {
  lv_anim_t a;
          lv_anim_init(&a);
          lv_anim_set_var(&a, obj);
          lv_anim_set_values(&a, y_start, y_end);
          lv_anim_set_exec_cb(&a, (lv_anim_exec_xcb_t)lv_obj_set_y);
          lv_anim_set_time(&a, 400);
  lv_anim_set_ready_cb(&a,redrag_obj);
          lv_anim_start(&a);

}

void bar_move(lv_obj_t* obj,int end) {
  lv_anim_t a;
          lv_anim_init(&a);
          lv_anim_set_var(&a, obj);
          lv_anim_set_values(&a, lv_bar_get_value(obj), end);
          lv_anim_set_exec_cb(&a, (lv_anim_exec_xcb_t)set_bar);
          lv_anim_set_time(&a, lv_anim_speed_to_time(66,lv_bar_get_value(obj), end));
          lv_anim_start(&a);

}
    void __qmsd_button_b1_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  if (((int)lv_btn_get_state(obj)) == ((int)LV_BTN_STATE_CHECKED_RELEASED)) {
    lv_label_set_text(label_st_b1, "打开");
  } else {
    lv_label_set_text(label_st_b1, "关闭");
  }
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_button_b2_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  if (((int)lv_btn_get_state(obj)) == ((int)LV_BTN_STATE_CHECKED_RELEASED)) {
    lv_label_set_text(label_st_b2, "打开");
  } else {
    lv_label_set_text(label_st_b2, "关闭");
  }
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_cont_top_cb(lv_obj_t * obj, lv_event_t event) {
  if ((event) == 8) {
    if (((int)lv_obj_get_y(obj)) < -100) {
      obj_move(obj,lv_obj_get_y(obj),0);
      lv_obj_set_style_local_bg_opa(cont_top,0,0,255);
    } else {
      obj_move(obj,lv_obj_get_y(obj),-230);
    }
    lv_obj_set_drag(cont_top,false);
    lv_indev_finish_drag(lv_indev_get_act());
  }
}

void __qmsd_screen_main_init(void) {
  lv_obj_set_ext_click_area(image_b1,-33,-33,-33,-33);
  lv_obj_set_ext_click_area(image_b2,-33,-33,-33,-33);
  lv_obj_set_ext_click_area(image_b3,-33,-33,-33,-33);
  lv_obj_set_ext_click_area(image_b4,-33,-33,-33,-33);
  lv_obj_set_ext_click_area(label_tile_b1,-33,-33,-33,-33);
  lv_obj_set_ext_click_area(label_tile_b2,-33,-33,-33,-33);
  lv_obj_set_ext_click_area(label_tile_b3,-33,-33,-33,-33);
  lv_obj_set_ext_click_area(label_tile_b4,-33,-33,-33,-33);
  lv_obj_set_ext_click_area(label_st_b1,-33,-33,-33,-33);
  lv_obj_set_ext_click_area(label_st_b2,-33,-33,-33,-33);
  lv_obj_set_ext_click_area(label_st_b3,-33,-33,-33,-33);
  lv_obj_set_ext_click_area(label_st_b4,-33,-33,-33,-33);
  lv_obj_set_drag(cont_top,true);
  lv_obj_set_drag_dir(cont_top,LV_DRAG_DIR_VER);
  lv_obj_set_style_local_bg_opa(cont_top,0,0,120);
  lv_obj_set_style_local_radius(cont_top,0,0,0);
  lv_obj_set_style_local_border_width(cont_top,0,0,0);
  lv_obj_set_style_local_bg_opa(label_63b0,0,0,50);
  lv_obj_set_style_local_bg_opa(tileview_2093, 0, 0, 0);
      lv_obj_set_style_local_bg_opa(main_tile_1,0,0,0);
  lv_obj_set_style_local_bg_opa(main_tile_2,0,0,0);
  static bool top_init = true;
  if(top_init)
  {
  lv_obj_set_hidden(image_base,true);
  top_init = false;
  }
}

void __qmsd_image_open_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  bar_move(bar_main,100);
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_image_close_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  bar_move(bar_main,0);
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_image_stop_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  lv_anim_del(bar_main,set_bar);
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_button_b3_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  if (((int)lv_btn_get_state(obj)) == ((int)LV_BTN_STATE_CHECKED_RELEASED)) {
    lv_label_set_text(label_st_b3, "打开");
  } else {
    lv_label_set_text(label_st_b3, "关闭");
  }
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_image_top_set_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  screen_set_show();
  obj_move(cont_top,lv_obj_get_y(cont_top),-230);
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_screen_wifi_init(void) {
  if (((int)wifi_init) == 0) {
    lv_switch_off(switch_wifi,LV_ANIM_OFF);
  } else {
    lv_switch_on(switch_wifi,LV_ANIM_OFF);
  }
  if (lv_switch_get_state(switch_wifi) == true) {
    lv_obj_set_hidden(image_net,false);
    lv_obj_set_hidden(label_net,false);
  } else {
    lv_obj_set_hidden(image_net,true);
    lv_obj_set_hidden(label_net,true);
  }
}

void __qmsd_screen_set_back_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  screen_set_delete();
  screen_main_show();
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_button_b4_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  if (((int)lv_btn_get_state(obj)) == ((int)LV_BTN_STATE_CHECKED_RELEASED)) {
    lv_label_set_text(label_st_b4, "打开");
  } else {
    lv_label_set_text(label_st_b4, "关闭");
  }
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_image_top_home_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  screen_main_show();
  main_tile_1_show();
  obj_move(cont_top,lv_obj_get_y(cont_top),-230);
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}
static void initialise_wifi(void)
{
    ESP_ERROR_CHECK(esp_netif_init());
    wifi_event_group = xEventGroupCreate();
    ESP_ERROR_CHECK(esp_event_loop_create_default());
    esp_netif_t *sta_netif = esp_netif_create_default_wifi_sta();
    assert(sta_netif);

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK( esp_wifi_init(&cfg) );
    ESP_ERROR_CHECK( esp_wifi_set_mode(WIFI_MODE_STA) );
    ESP_ERROR_CHECK( esp_wifi_start() );
}

void __qmsd_switch_wifi_cb(lv_obj_t * obj, lv_event_t event) {
  static int8_t initiliztion=0;
if(event == LV_EVENT_VALUE_CHANGED) {
  if (lv_switch_get_state(switch_wifi) == true) {
    lv_obj_set_hidden(image_net,false);
    lv_obj_set_hidden(label_net,false);
    wifi_init = true;
    if (!initiliztion)
    {
      esp_wifi_set_ps(WIFI_PS_MIN_MODEM);
      qmsd_blufi_start();
      initiliztion++;
    }
  } else {
    lv_obj_set_hidden(image_net,true);
    lv_obj_set_hidden(label_net,true);
    wifi_init = false;
  }
}
}

void __qmsd_list_86ba_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_CLICKED) {
  if ((strcmp(lv_list_get_btn_text(obj),"WIFI")) == 0) {
    screen_wifi_show();
  } else if ((strcmp(lv_list_get_btn_text(obj),"主题设置")) == 0) {
    screen_theme_show();
  }
}
}

void __qmsd_screen_theme_init(void) {
  lv_obj_set_style_local_outline_width(image_theme_1,0,0,0);
  lv_obj_set_style_local_outline_width(image_theme_2,0,0,0);
  lv_obj_set_style_local_outline_width(image_theme_3,0,0,0);
  lv_obj_set_style_local_outline_width(image_theme_1,0,2,2);
  lv_obj_set_style_local_outline_color(image_theme_1,0,0,LV_COLOR_WHITE);
  lv_obj_set_style_local_outline_opa(image_theme_1,0,2,255);
  lv_obj_set_style_local_outline_width(image_theme_2,0,2,2);
  lv_obj_set_style_local_outline_color(image_theme_2,0,0,LV_COLOR_WHITE);
  lv_obj_set_style_local_outline_opa(image_theme_2,0,2,255);
  lv_obj_set_style_local_outline_width(image_theme_3,0,2,2);
  lv_obj_set_style_local_outline_color(image_theme_3,0,0,LV_COLOR_WHITE);
  lv_obj_set_style_local_outline_opa(image_theme_3,0,2,255);
  switch (theme_used)
      {
      case 0:
  lv_obj_set_style_local_outline_width(image_theme_1,0,0,2);
          break;
          case 1:
  lv_obj_set_style_local_outline_width(image_theme_2,0,0,2);
          break;
          case 2:
  lv_obj_set_style_local_outline_width(image_theme_3,0,0,2);
          break;
      default:
          break;
      }
}

void __qmsd_image_wifi_back_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  screen_set_show();
  screen_wifi_delete();
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_image_themeback_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  screen_set_show();
  screen_theme_delete();
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_image_theme_1_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  theme_used = 0;
  lv_obj_set_hidden(image_base,true);
  lv_obj_set_style_local_outline_width(image_theme_1,0,0,2);
  lv_obj_set_style_local_outline_width(image_theme_2,0,0,0);
  lv_obj_set_style_local_outline_width(image_theme_3,0,0,0);
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_image_theme_2_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  theme_used = 1;
  lv_img_set_src(image_base, &imgbase_bg_2_png);
  lv_obj_set_hidden(image_base,false);
  lv_obj_set_style_local_outline_width(image_theme_1,0,0,0);
  lv_obj_set_style_local_outline_width(image_theme_2,0,0,2);
  lv_obj_set_style_local_outline_width(image_theme_3,0,0,0);
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_image_theme_3_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  theme_used = 2;
  lv_img_set_src(image_base, &imgbase_bg_3_png);
  lv_obj_set_hidden(image_base,false);
  lv_obj_set_style_local_outline_width(image_theme_1,0,0,0);
  lv_obj_set_style_local_outline_width(image_theme_2,0,0,0);
  lv_obj_set_style_local_outline_width(image_theme_3,0,0,2);
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}
