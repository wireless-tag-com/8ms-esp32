#include "qmsd_ui_entry.h"
#include "qmsd_internal_ui_cb.h"
#include "esp_system.h"
#include "esp_wifi.h"

lv_obj_t* screen_wifi;
lv_obj_t* image_wifi_back;
lv_obj_t* switch_wifi;
lv_obj_t* label_0c49;
lv_obj_t* image_net;
lv_obj_t* label_net;


    
void qmsd_image_wifi_back_create()
{
    image_wifi_back = lv_img_create(screen_wifi, NULL);
    lv_img_set_src(image_wifi_back, &imgback_png);
#ifdef BLOCKLY_image_wifi_back_EVENT_HANDLER
    lv_obj_set_event_cb(image_wifi_back, __qmsd_image_wifi_back_cb);
#endif
    lv_obj_set_pos(image_wifi_back, 33, 34);
    lv_obj_set_click(image_wifi_back,true);
    lv_obj_set_style_local_image_recolor(image_wifi_back,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(image_wifi_back,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    lv_obj_set_ext_click_area(image_wifi_back,12,12,12,12);
    qmsd_obj_set_id(image_wifi_back,"image_wifi_back");
}
    void qmsd_switch_wifi_create()
{
    switch_wifi = lv_switch_create(screen_wifi, NULL);
    lv_obj_set_size(switch_wifi, 91, 34);
    lv_obj_set_pos(switch_wifi, 345, 34);
    if(0 == 0) {
    lv_switch_off(switch_wifi, LV_ANIM_OFF);
    } else {
    lv_switch_on(switch_wifi, LV_ANIM_OFF);
    }
    //set switch bg style
    lv_obj_set_style_local_bg_color(switch_wifi,LV_SWITCH_PART_BG,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xCC, 0xCC, 0xCC));
    lv_obj_set_style_local_bg_grad_color(switch_wifi,LV_SWITCH_PART_BG,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xCC, 0xCC, 0xCC));
    lv_obj_set_style_local_pad_top(switch_wifi,LV_SWITCH_PART_BG,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_pad_bottom(switch_wifi,LV_SWITCH_PART_BG,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_pad_left(switch_wifi,LV_SWITCH_PART_BG,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_pad_right(switch_wifi,LV_SWITCH_PART_BG,LV_STATE_DEFAULT,0);
    //set switch indic style
    lv_obj_set_style_local_bg_color(switch_wifi,LV_SWITCH_PART_INDIC,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x02, 0x88, 0xFB));
    lv_obj_set_style_local_bg_grad_color(switch_wifi,LV_SWITCH_PART_INDIC,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x02, 0x88, 0xFB));
    lv_obj_set_style_local_radius(switch_wifi,LV_SWITCH_PART_INDIC,LV_STATE_DEFAULT,LV_RADIUS_CIRCLE);
    lv_obj_set_style_local_pad_top(switch_wifi,LV_SWITCH_PART_INDIC,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_pad_bottom(switch_wifi,LV_SWITCH_PART_INDIC,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_pad_left(switch_wifi,LV_SWITCH_PART_INDIC,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_pad_right(switch_wifi,LV_SWITCH_PART_INDIC,LV_STATE_DEFAULT,0);
    //set switch knob style
    lv_obj_set_style_local_radius(switch_wifi,LV_SWITCH_PART_KNOB,LV_STATE_DEFAULT,LV_RADIUS_CIRCLE);
#ifdef BLOCKLY_switch_wifi_EVENT_HANDLER
    lv_obj_set_event_cb(switch_wifi, __qmsd_switch_wifi_cb);
#endif
    qmsd_obj_set_id(switch_wifi,"switch_wifi");
}
    void qmsd_label_0c49_create()
{
	label_0c49 = lv_label_create(screen_wifi, NULL);
	lv_label_set_long_mode(label_0c49,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_0c49,true);
	lv_obj_set_size(label_0c49, 69, 40);
//set label style
	lv_obj_set_style_local_text_color(label_0c49,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(label_0c49, "WIFI");
	lv_label_set_align(label_0c49, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(label_0c49,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_23);
#ifdef BLOCKLY_label_0c49_EVENT_HANDLER
	lv_obj_set_event_cb(label_0c49, __qmsd_label_0c49_cb);
#endif
	if(label_0c49->coords.x2-label_0c49->coords.x1<69)
	{
		int x_offset=(69-(label_0c49->coords.x2-label_0c49->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_0c49,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_0c49,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_0c49->coords.y2-label_0c49->coords.y1<40)
	{
		int y_offset=(40-(label_0c49->coords.y2-label_0c49->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_0c49,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_0c49,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(label_0c49, 60, 22);
    qmsd_obj_set_id(label_0c49,"label_0c49");
}
    
void qmsd_image_net_create()
{
    image_net = lv_img_create(screen_wifi, NULL);
    lv_img_set_src(image_net, &imgrobot_png);
#ifdef BLOCKLY_image_net_EVENT_HANDLER
    lv_obj_set_event_cb(image_net, __qmsd_image_net_cb);
#endif
    lv_obj_set_pos(image_net, 54, 82);
    qmsd_obj_set_id(image_net,"image_net");
}
    void qmsd_label_net_create()
{
    wifi_ap_record_t ap_info;
	label_net = lv_label_create(screen_wifi, NULL);
	lv_label_set_long_mode(label_net,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_net,true);
	lv_obj_set_size(label_net, 170, 47);
	lv_obj_set_parent(label_net,image_net);
//set label style
	lv_obj_set_style_local_text_color(label_net,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
    if (esp_wifi_sta_get_ap_info(&ap_info)==ESP_OK)
    {
        lv_label_set_text(label_net, "Connected!");
    }
    else
	    lv_label_set_text(label_net, "等待配网");
	lv_label_set_align(label_net, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(label_net,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_29);
#ifdef BLOCKLY_label_net_EVENT_HANDLER
	lv_obj_set_event_cb(label_net, __qmsd_label_net_cb);
#endif
	if(label_net->coords.x2-label_net->coords.x1<170)
	{
		int x_offset=(170-(label_net->coords.x2-label_net->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_net,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_net,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_net->coords.y2-label_net->coords.y1<47)
	{
		int y_offset=(47-(label_net->coords.y2-label_net->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_net,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_net,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(label_net, 153-image_net->coords.x1+lv_obj_get_x(screen_wifi), 388-image_net->coords.y1+lv_obj_get_y(screen_wifi));
    qmsd_obj_set_id(label_net,"label_net");
}

static void screen_wifi_qmsd_cb(lv_obj_t * obj, lv_event_t event, void *data)
{/*
    char *trans;
    lv_label_set_text(label_0c49,qmsd_lang_get_trans("label_0c49","WIFI"));
    lv_label_set_text(label_net,qmsd_lang_get_trans("label_net","等待配网"));
*/
#ifdef BLOCKLY_screen_wifi_SCREEN_INIT
    __qmsd_screen_wifi_init();
#endif
}

static void screen_wifi_del_cb(lv_obj_t* obj,lv_event_t event)
{
    if(event == LV_EVENT_DELETE)
    {
        screen_wifi=NULL;
        qmsd_screen_remove("screen_wifi");
    }
}

void screen_wifi_build(void)
{
    if(screen_wifi) return;
    screen_wifi = lv_obj_create(NULL, NULL);
    lv_obj_qmsd_set_cb(screen_wifi, screen_wifi_qmsd_cb);
    lv_obj_set_style_local_bg_color(screen_wifi,LV_OBJ_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x00, 0x00, 0x00));

    qmsd_image_wifi_back_create();
    qmsd_switch_wifi_create();
    qmsd_label_0c49_create();
    qmsd_image_net_create();
    qmsd_label_net_create();
    lv_obj_set_event_cb(screen_wifi,screen_wifi_del_cb);
    qmsd_screen_register(screen_wifi,"screen_wifi");
}

void screen_wifi_show(void)
{
    if(!screen_wifi)
    {
        screen_wifi_build();
    }
    lv_scr_load(screen_wifi);
}

void screen_wifi_delete(void)
{
    if(screen_wifi)
    {
        lv_obj_del(screen_wifi);
        screen_wifi = NULL;
    }
}
