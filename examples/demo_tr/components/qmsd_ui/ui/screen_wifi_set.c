#include "qmsd_ui_entry.h"
#include "qmsd_internal_ui_cb.h"

lv_obj_t* screen_wifi_set;
lv_obj_t* lab_wif_lab;
lv_obj_t* lab_wif_re;
lv_obj_t* lab_wif_tip;
lv_obj_t* swi_wif_swi;


    void qmsd_lab_wif_lab_create()
{
	lab_wif_lab = lv_label_create(screen_wifi_set, NULL);
	lv_label_set_long_mode(lab_wif_lab,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(lab_wif_lab,true);
	lv_obj_set_size(lab_wif_lab, 153, 23);
//set label style
	lv_obj_set_style_local_text_color(lab_wif_lab,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(lab_wif_lab, "连接WIFI网络");
	lv_label_set_align(lab_wif_lab, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(lab_wif_lab,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_24);
#ifdef BLOCKLY_lab_wif_lab_EVENT_HANDLER
	lv_obj_set_event_cb(lab_wif_lab, __qmsd_lab_wif_lab_cb);
#endif
	if(lab_wif_lab->coords.x2-lab_wif_lab->coords.x1<153)
	{
		int x_offset=(153-(lab_wif_lab->coords.x2-lab_wif_lab->coords.x1))/2;
		lv_obj_set_style_local_pad_left(lab_wif_lab,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(lab_wif_lab,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(lab_wif_lab->coords.y2-lab_wif_lab->coords.y1<23)
	{
		int y_offset=(23-(lab_wif_lab->coords.y2-lab_wif_lab->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(lab_wif_lab,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(lab_wif_lab,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(lab_wif_lab, 168, 32);
    qmsd_obj_set_id(lab_wif_lab,"lab_wif_lab");
}
    void qmsd_lab_wif_re_create()
{
	lab_wif_re = lv_label_create(screen_wifi_set, NULL);
	lv_label_set_long_mode(lab_wif_re,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(lab_wif_re,true);
	lv_obj_set_size(lab_wif_re, 41, 19);
//set label style
	lv_obj_set_style_local_text_color(lab_wif_re,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(lab_wif_re, "跳过");
	lv_label_set_align(lab_wif_re, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(lab_wif_re,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_20);
#ifdef BLOCKLY_lab_wif_re_EVENT_HANDLER
	lv_obj_set_event_cb(lab_wif_re, __qmsd_lab_wif_re_cb);
#endif
    lv_obj_set_click(lab_wif_re,true);    
	if(lab_wif_re->coords.x2-lab_wif_re->coords.x1<41)
	{
		int x_offset=(41-(lab_wif_re->coords.x2-lab_wif_re->coords.x1))/2;
		lv_obj_set_style_local_pad_left(lab_wif_re,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(lab_wif_re,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(lab_wif_re->coords.y2-lab_wif_re->coords.y1<19)
	{
		int y_offset=(19-(lab_wif_re->coords.y2-lab_wif_re->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(lab_wif_re,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(lab_wif_re,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(lab_wif_re, 390, 34);
    qmsd_obj_set_id(lab_wif_re,"lab_wif_re");

	lv_obj_set_ext_click_area(lab_wif_re, 20, 20, 20, 20);
}
    void qmsd_lab_wif_tip_create()
{
	lab_wif_tip = lv_label_create(screen_wifi_set, NULL);
	lv_label_set_long_mode(lab_wif_tip,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(lab_wif_tip,true);
	lv_obj_set_size(lab_wif_tip, 99, 23);
//set label style
	lv_obj_set_style_local_text_color(lab_wif_tip,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(lab_wif_tip, "无线网络");
	lv_label_set_align(lab_wif_tip, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(lab_wif_tip,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_24);
#ifdef BLOCKLY_lab_wif_tip_EVENT_HANDLER
	lv_obj_set_event_cb(lab_wif_tip, __qmsd_lab_wif_tip_cb);
#endif
	if(lab_wif_tip->coords.x2-lab_wif_tip->coords.x1<99)
	{
		int x_offset=(99-(lab_wif_tip->coords.x2-lab_wif_tip->coords.x1))/2;
		lv_obj_set_style_local_pad_left(lab_wif_tip,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(lab_wif_tip,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(lab_wif_tip->coords.y2-lab_wif_tip->coords.y1<23)
	{
		int y_offset=(23-(lab_wif_tip->coords.y2-lab_wif_tip->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(lab_wif_tip,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(lab_wif_tip,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(lab_wif_tip, 48, 111);
    qmsd_obj_set_id(lab_wif_tip,"lab_wif_tip");
}
    void qmsd_swi_wif_swi_create()
{
    swi_wif_swi = lv_switch_create(screen_wifi_set, NULL);
    lv_obj_set_size(swi_wif_swi, 53, 26);
    lv_obj_set_pos(swi_wif_swi, 385, 109);
    if(0 == 0) {
    lv_switch_off(swi_wif_swi, LV_ANIM_OFF);
    } else {
    lv_switch_on(swi_wif_swi, LV_ANIM_OFF);
    }
    //set switch bg style
    lv_obj_set_style_local_bg_color(swi_wif_swi,LV_SWITCH_PART_BG,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
    lv_obj_set_style_local_bg_grad_color(swi_wif_swi,LV_SWITCH_PART_BG,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
    lv_obj_set_style_local_pad_top(swi_wif_swi,LV_SWITCH_PART_BG,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_pad_bottom(swi_wif_swi,LV_SWITCH_PART_BG,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_pad_left(swi_wif_swi,LV_SWITCH_PART_BG,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_pad_right(swi_wif_swi,LV_SWITCH_PART_BG,LV_STATE_DEFAULT,0);
    //set switch indic style
    lv_obj_set_style_local_bg_color(swi_wif_swi,LV_SWITCH_PART_INDIC,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x02, 0x88, 0xFB));
    lv_obj_set_style_local_bg_grad_color(swi_wif_swi,LV_SWITCH_PART_INDIC,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x02, 0x88, 0xFB));
    lv_obj_set_style_local_radius(swi_wif_swi,LV_SWITCH_PART_INDIC,LV_STATE_DEFAULT,LV_RADIUS_CIRCLE);
    lv_obj_set_style_local_pad_top(swi_wif_swi,LV_SWITCH_PART_INDIC,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_pad_bottom(swi_wif_swi,LV_SWITCH_PART_INDIC,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_pad_left(swi_wif_swi,LV_SWITCH_PART_INDIC,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_pad_right(swi_wif_swi,LV_SWITCH_PART_INDIC,LV_STATE_DEFAULT,0);
    //set switch knob style
    lv_obj_set_style_local_radius(swi_wif_swi,LV_SWITCH_PART_KNOB,LV_STATE_DEFAULT,LV_RADIUS_CIRCLE);
#ifdef BLOCKLY_swi_wif_swi_EVENT_HANDLER
    lv_obj_set_event_cb(swi_wif_swi, __qmsd_swi_wif_swi_cb);
#endif
    qmsd_obj_set_id(swi_wif_swi,"swi_wif_swi");
}

static void screen_wifi_set_qmsd_cb(lv_obj_t * obj, lv_event_t event, void *data)
{/*
    char *trans;
    lv_label_set_text(lab_wif_lab,qmsd_lang_get_trans("lab_wif_lab","连接WIFI网络"));
    lv_label_set_text(lab_wif_re,qmsd_lang_get_trans("lab_wif_re","跳过"));
    lv_label_set_text(lab_wif_tip,qmsd_lang_get_trans("lab_wif_tip","无线网络"));
*/
#ifdef BLOCKLY_screen_wifi_set_SCREEN_INIT
    __qmsd_screen_wifi_set_init();
#endif
}

static void screen_wifi_set_del_cb(lv_obj_t* obj,lv_event_t event)
{
    if(event == LV_EVENT_DELETE)
    {
        screen_wifi_set=NULL;
        qmsd_screen_remove("screen_wifi_set");
    }
}

void screen_wifi_set_build(void)
{
    if(screen_wifi_set) return;
    screen_wifi_set = lv_obj_create(NULL, NULL);
    lv_obj_qmsd_set_cb(screen_wifi_set, screen_wifi_set_qmsd_cb);
    lv_obj_set_style_local_bg_color(screen_wifi_set,LV_OBJ_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x20, 0x20, 0x20));

    qmsd_lab_wif_lab_create();
    qmsd_lab_wif_re_create();
    qmsd_lab_wif_tip_create();
    qmsd_swi_wif_swi_create();
    lv_obj_set_event_cb(screen_wifi_set,screen_wifi_set_del_cb);
    qmsd_screen_register(screen_wifi_set,"screen_wifi_set");
}

void screen_wifi_set_show(void)
{
    if(!screen_wifi_set)
    {
        screen_wifi_set_build();
    }
    lv_scr_load(screen_wifi_set);
}

void screen_wifi_set_delete(void)
{
    if(screen_wifi_set)
    {
        lv_obj_del(screen_wifi_set);
        screen_wifi_set = NULL;
    }
}
