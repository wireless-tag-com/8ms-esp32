#include "qmsd_ui_entry.h"
#include "qmsd_internal_ui_cb.h"

lv_obj_t* screen_main;
lv_obj_t* label_554e;
lv_obj_t* button_5cb9;
lv_obj_t * __button_5cb9_label;
lv_obj_t* button_e490;
lv_obj_t * __button_e490_label;
lv_obj_t* label_b6b4;
lv_obj_t* button_d2c4;
lv_obj_t * __button_d2c4_label;


    void qmsd_label_554e_create()
{
	label_554e = lv_label_create(screen_main, NULL);
	lv_label_set_long_mode(label_554e,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_554e,true);
	lv_obj_set_size(label_554e, 100, 50);
//set label style

	lv_label_set_text(label_554e, "wifi");
	lv_label_set_align(label_554e, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(label_554e,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_16);
#ifdef BLOCKLY_label_554e_EVENT_HANDLER
	lv_obj_set_event_cb(label_554e, __qmsd_label_554e_cb);
#endif
	if(label_554e->coords.x2-label_554e->coords.x1<100)
	{
		int x_offset=(100-(label_554e->coords.x2-label_554e->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_554e,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_554e,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_554e->coords.y2-label_554e->coords.y1<50)
	{
		int y_offset=(50-(label_554e->coords.y2-label_554e->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_554e,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_554e,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(label_554e, 110, 31);
    qmsd_obj_set_id(label_554e,"label_554e");
}
    void qmsd_button_5cb9_create()
{
    button_5cb9 = lv_btn_create(screen_main, NULL);
    __button_5cb9_label = lv_label_create(button_5cb9, NULL);
    lv_label_set_text(__button_5cb9_label,qmsd_lang_get_trans("button_5cb9","BLUFI"));

    lv_obj_set_style_local_text_font(__button_5cb9_label,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_16);
    lv_obj_set_size(button_5cb9, 100, 40);
    lv_obj_set_pos(button_5cb9, 33, 95);
    lv_obj_set_event_cb(button_5cb9, __qmsd_button_5cb9_cb);


    lv_obj_t* obj = button_5cb9;
    int part = LV_BTN_PART_MAIN;
//设置正常样式
        lv_obj_set_style_local_border_color(obj,part,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

//设置正常样式结束

//设置按下样式
        lv_obj_set_style_local_border_color(obj,part,LV_STATE_PRESSED,LV_COLOR_MAKE(0xff, 0xff, 0xff));

//设置按下样式结束

//设置禁用样式
        lv_obj_set_style_local_border_color(obj,part,LV_STATE_DISABLED,LV_COLOR_MAKE(0xff, 0xff, 0xff));

//设置禁用样式结束
    lv_obj_set_style_local_outline_width(button_5cb9,LV_BTN_PART_MAIN,LV_STATE_DEFAULT,0);
	lv_obj_set_style_local_outline_width(button_5cb9,LV_BTN_PART_MAIN,LV_STATE_FOCUSED,0);
    qmsd_obj_set_id(button_5cb9,"button_5cb9");
}
    void qmsd_button_e490_create()
{
    button_e490 = lv_btn_create(screen_main, NULL);
    __button_e490_label = lv_label_create(button_e490, NULL);
    lv_label_set_text(__button_e490_label,qmsd_lang_get_trans("button_e490","SMARTCONFIG"));

    lv_obj_set_style_local_text_font(__button_e490_label,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_12);
    lv_obj_set_size(button_e490, 100, 40);
    lv_obj_set_pos(button_e490, 33, 162);
    lv_obj_set_event_cb(button_e490, __qmsd_button_e490_cb);

    lv_obj_t* obj = button_e490;
    int part = LV_BTN_PART_MAIN;
//设置正常样式
        lv_obj_set_style_local_border_color(obj,part,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

//设置正常样式结束

//设置按下样式
        lv_obj_set_style_local_border_color(obj,part,LV_STATE_PRESSED,LV_COLOR_MAKE(0xff, 0xff, 0xff));

//设置按下样式结束

//设置禁用样式
        lv_obj_set_style_local_border_color(obj,part,LV_STATE_DISABLED,LV_COLOR_MAKE(0xff, 0xff, 0xff));

//设置禁用样式结束
    lv_obj_set_style_local_outline_width(button_e490,LV_BTN_PART_MAIN,LV_STATE_DEFAULT,0);
	lv_obj_set_style_local_outline_width(button_e490,LV_BTN_PART_MAIN,LV_STATE_FOCUSED,0);
    qmsd_obj_set_id(button_e490,"button_e490");
}

void qmsd_lable_ip_set(const char *ip)
{
    lv_label_set_text(label_b6b4, ip);
}

    void qmsd_label_b6b4_create()
{
	label_b6b4 = lv_label_create(screen_main, NULL);
	lv_label_set_long_mode(label_b6b4,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_b6b4,true);
	lv_obj_set_size(label_b6b4, 100, 40);
//set label style

	lv_label_set_text(label_b6b4, "IP");
	lv_label_set_align(label_b6b4, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(label_b6b4,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_16);
#ifdef BLOCKLY_label_b6b4_EVENT_HANDLER
	lv_obj_set_event_cb(label_b6b4, __qmsd_label_b6b4_cb);
#endif
	if(label_b6b4->coords.x2-label_b6b4->coords.x1<100)
	{
		int x_offset=(100-(label_b6b4->coords.x2-label_b6b4->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_b6b4,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_b6b4,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_b6b4->coords.y2-label_b6b4->coords.y1<40)
	{
		int y_offset=(40-(label_b6b4->coords.y2-label_b6b4->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_b6b4,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_b6b4,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(label_b6b4, 110, 229);
    qmsd_obj_set_id(label_b6b4,"label_b6b4");
}
    void qmsd_button_d2c4_create()
{
    button_d2c4 = lv_btn_create(screen_main, NULL);
    __button_d2c4_label = lv_label_create(button_d2c4, NULL);
    lv_label_set_text(__button_d2c4_label,qmsd_lang_get_trans("button_d2c4","恢复出厂设置"));

    lv_obj_set_style_local_text_font(__button_d2c4_label,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_12);
    lv_obj_set_size(button_d2c4, 100, 40);
    lv_obj_set_pos(button_d2c4, 188, 122);
    lv_obj_set_event_cb(button_d2c4, __qmsd_button_d2c4_cb);


    lv_obj_t* obj = button_d2c4;
    int part = LV_BTN_PART_MAIN;
//设置正常样式
        lv_obj_set_style_local_border_color(obj,part,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

//设置正常样式结束

//设置按下样式
        lv_obj_set_style_local_border_color(obj,part,LV_STATE_PRESSED,LV_COLOR_MAKE(0xff, 0xff, 0xff));

//设置按下样式结束

//设置禁用样式
        lv_obj_set_style_local_border_color(obj,part,LV_STATE_DISABLED,LV_COLOR_MAKE(0xff, 0xff, 0xff));

//设置禁用样式结束
    lv_obj_set_style_local_outline_width(button_d2c4,LV_BTN_PART_MAIN,LV_STATE_DEFAULT,0);
	lv_obj_set_style_local_outline_width(button_d2c4,LV_BTN_PART_MAIN,LV_STATE_FOCUSED,0);
    qmsd_obj_set_id(button_d2c4,"button_d2c4");
}

static void screen_main_qmsd_cb(lv_obj_t * obj, lv_event_t event, void *data)
{/*
    char *trans;
    lv_label_set_text(label_554e,qmsd_lang_get_trans("label_554e","wifi"));
    lv_label_set_text(__button_5cb9_label,qmsd_lang_get_trans("button_5cb9","BLUFI"));
    lv_label_set_text(__button_e490_label,qmsd_lang_get_trans("button_e490","SMARTCONFIG"));
    lv_label_set_text(label_b6b4,qmsd_lang_get_trans("label_b6b4","IP"));
    lv_label_set_text(__button_d2c4_label,qmsd_lang_get_trans("button_d2c4","恢复出厂设置"));
*/
#ifdef BLOCKLY_screen_main_SCREEN_INIT
    __qmsd_screen_main_init();
#endif
}

static void screen_main_del_cb(lv_obj_t* obj,lv_event_t event)
{
    if(event == LV_EVENT_DELETE)
    {
        screen_main=NULL;
        qmsd_screen_remove("screen_main");
    }
}

void screen_main_build(void)
{
    if(screen_main) return;
    screen_main = lv_obj_create(NULL, NULL);
    lv_obj_qmsd_set_cb(screen_main, screen_main_qmsd_cb);

    qmsd_label_554e_create();
    qmsd_button_5cb9_create();
    qmsd_button_e490_create();
    qmsd_label_b6b4_create();
    qmsd_button_d2c4_create();
    lv_obj_set_event_cb(screen_main,screen_main_del_cb);
    qmsd_screen_register(screen_main,"screen_main");
}

void screen_main_show(void)
{
    if(!screen_main)
    {
        screen_main_build();
    }
    lv_scr_load(screen_main);
}

void screen_main_delete(void)
{
    if(screen_main)
    {
        lv_obj_del(screen_main);
        screen_main = NULL;
    }
}
