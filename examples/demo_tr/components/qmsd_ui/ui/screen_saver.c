#include "qmsd_ui_entry.h"
#include "qmsd_internal_ui_cb.h"

lv_obj_t* screen_saver;
lv_obj_t* image_saver_bot;
lv_obj_t* lab_sa_hour;
lv_obj_t* lab_sa_min;
lv_obj_t* lab_sa_scr;
lv_obj_t* lab_sa_data;
lv_obj_t* lab_sa_week;
lv_obj_t* but_sa_but_deep;
lv_obj_t * __but_sa_but_deep_label;
lv_obj_t* ima_sa_ima;
lv_obj_t* lab_sa_tips;


    
void qmsd_image_saver_bot_create()
{
    image_saver_bot = lv_img_create(screen_saver, NULL);
    lv_img_set_src(image_saver_bot, &imgsaver_button_png);
#ifdef BLOCKLY_image_saver_bot_EVENT_HANDLER
    lv_obj_set_event_cb(image_saver_bot, __qmsd_image_saver_bot_cb);
#endif
    lv_obj_set_pos(image_saver_bot, 0, 0);
    lv_obj_set_click(image_saver_bot,true);
    lv_obj_set_style_local_image_recolor(image_saver_bot,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(image_saver_bot,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    qmsd_obj_set_id(image_saver_bot,"image_saver_bot");
}
    void qmsd_lab_sa_hour_create()
{
	lab_sa_hour = lv_label_create(screen_saver, NULL);
	lv_label_set_long_mode(lab_sa_hour,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(lab_sa_hour,true);
	lv_obj_set_size(lab_sa_hour, 104, 76);
//set label style
	lv_obj_set_style_local_text_color(lab_sa_hour,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(lab_sa_hour, "10");
	lv_label_set_align(lab_sa_hour, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(lab_sa_hour,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_104);
#ifdef BLOCKLY_lab_sa_hour_EVENT_HANDLER
	lv_obj_set_event_cb(lab_sa_hour, __qmsd_lab_sa_hour_cb);
#endif
	if(lab_sa_hour->coords.x2-lab_sa_hour->coords.x1<104)
	{
		int x_offset=(104-(lab_sa_hour->coords.x2-lab_sa_hour->coords.x1))/2;
		lv_obj_set_style_local_pad_left(lab_sa_hour,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(lab_sa_hour,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(lab_sa_hour->coords.y2-lab_sa_hour->coords.y1<76)
	{
		int y_offset=(76-(lab_sa_hour->coords.y2-lab_sa_hour->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(lab_sa_hour,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(lab_sa_hour,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(lab_sa_hour, 102, 105);
    qmsd_obj_set_id(lab_sa_hour,"lab_sa_hour");
}
    void qmsd_lab_sa_min_create()
{
	lab_sa_min = lv_label_create(screen_saver, NULL);
	lv_label_set_long_mode(lab_sa_min,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(lab_sa_min,true);
	lv_obj_set_size(lab_sa_min, 104, 76);
//set label style
	lv_obj_set_style_local_text_color(lab_sa_min,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(lab_sa_min, "12");
	lv_label_set_align(lab_sa_min, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(lab_sa_min,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_104);
#ifdef BLOCKLY_lab_sa_min_EVENT_HANDLER
	lv_obj_set_event_cb(lab_sa_min, __qmsd_lab_sa_min_cb);
#endif
	if(lab_sa_min->coords.x2-lab_sa_min->coords.x1<104)
	{
		int x_offset=(104-(lab_sa_min->coords.x2-lab_sa_min->coords.x1))/2;
		lv_obj_set_style_local_pad_left(lab_sa_min,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(lab_sa_min,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(lab_sa_min->coords.y2-lab_sa_min->coords.y1<76)
	{
		int y_offset=(76-(lab_sa_min->coords.y2-lab_sa_min->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(lab_sa_min,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(lab_sa_min,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(lab_sa_min, 238, 105);
    qmsd_obj_set_id(lab_sa_min,"lab_sa_min");
}
    void qmsd_lab_sa_scr_create()
{
	lab_sa_scr = lv_label_create(screen_saver, NULL);
	lv_label_set_long_mode(lab_sa_scr,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(lab_sa_scr,true);
	lv_obj_set_size(lab_sa_scr, 12, 76);
//set label style
	lv_obj_set_style_local_text_color(lab_sa_scr,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(lab_sa_scr, ":");
	lv_label_set_align(lab_sa_scr, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(lab_sa_scr,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_104);
#ifdef BLOCKLY_lab_sa_scr_EVENT_HANDLER
	lv_obj_set_event_cb(lab_sa_scr, __qmsd_lab_sa_scr_cb);
#endif
	if(lab_sa_scr->coords.x2-lab_sa_scr->coords.x1<12)
	{
		int x_offset=(12-(lab_sa_scr->coords.x2-lab_sa_scr->coords.x1))/2;
		lv_obj_set_style_local_pad_left(lab_sa_scr,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(lab_sa_scr,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(lab_sa_scr->coords.y2-lab_sa_scr->coords.y1<76)
	{
		int y_offset=(76-(lab_sa_scr->coords.y2-lab_sa_scr->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(lab_sa_scr,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(lab_sa_scr,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(lab_sa_scr, 215, 105);
    qmsd_obj_set_id(lab_sa_scr,"lab_sa_scr");
}
    void qmsd_lab_sa_data_create()
{
	lab_sa_data = lv_label_create(screen_saver, NULL);
	lv_label_set_long_mode(lab_sa_data,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(lab_sa_data,true);
	lv_obj_set_size(lab_sa_data, 120, 23);
//set label style
	lv_obj_set_style_local_text_color(lab_sa_data,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(lab_sa_data, "8月12日");
	lv_label_set_align(lab_sa_data, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(lab_sa_data,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_32);
#ifdef BLOCKLY_lab_sa_data_EVENT_HANDLER
	lv_obj_set_event_cb(lab_sa_data, __qmsd_lab_sa_data_cb);
#endif
	if(lab_sa_data->coords.x2-lab_sa_data->coords.x1<120)
	{
		int x_offset=(120-(lab_sa_data->coords.x2-lab_sa_data->coords.x1))/2;
		lv_obj_set_style_local_pad_left(lab_sa_data,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(lab_sa_data,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(lab_sa_data->coords.y2-lab_sa_data->coords.y1<23)
	{
		int y_offset=(23-(lab_sa_data->coords.y2-lab_sa_data->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(lab_sa_data,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(lab_sa_data,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(lab_sa_data, 138, 212);
    qmsd_obj_set_id(lab_sa_data,"lab_sa_data");
}
    void qmsd_lab_sa_week_create()
{
	lab_sa_week = lv_label_create(screen_saver, NULL);
	lv_label_set_long_mode(lab_sa_week,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(lab_sa_week,true);
	lv_obj_set_size(lab_sa_week, 90, 23);
//set label style
	lv_obj_set_style_local_text_color(lab_sa_week,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(lab_sa_week, "星期二");
	lv_label_set_align(lab_sa_week, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(lab_sa_week,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_24);
#ifdef BLOCKLY_lab_sa_week_EVENT_HANDLER
	lv_obj_set_event_cb(lab_sa_week, __qmsd_lab_sa_week_cb);
#endif
	if(lab_sa_week->coords.x2-lab_sa_week->coords.x1<90)
	{
		int x_offset=(90-(lab_sa_week->coords.x2-lab_sa_week->coords.x1))/2;
		lv_obj_set_style_local_pad_left(lab_sa_week,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(lab_sa_week,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(lab_sa_week->coords.y2-lab_sa_week->coords.y1<23)
	{
		int y_offset=(23-(lab_sa_week->coords.y2-lab_sa_week->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(lab_sa_week,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(lab_sa_week,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(lab_sa_week, 281, 211);
    qmsd_obj_set_id(lab_sa_week,"lab_sa_week");
}
    void qmsd_but_sa_but_deep_create()
{
    but_sa_but_deep = lv_btn_create(screen_saver, NULL);
    __but_sa_but_deep_label = lv_label_create(but_sa_but_deep, NULL);
    lv_label_set_text(__but_sa_but_deep_label,qmsd_lang_get_trans("but_sa_but_deep",""));

    lv_obj_set_style_local_text_font(__but_sa_but_deep_label,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_16);
    lv_obj_set_size(but_sa_but_deep, 320, 52);
    lv_obj_set_pos(but_sa_but_deep, 80, 370);
#ifdef BLOCKLY_but_sa_but_deep_EVENT_HANDLER
    lv_obj_set_event_cb(but_sa_but_deep, __qmsd_but_sa_but_deep_cb);
#endif


    lv_obj_t* obj = but_sa_but_deep;
    int part = LV_BTN_PART_MAIN;
//设置正常样式
        lv_obj_set_style_local_bg_color(obj,part,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x00, 0x00, 0x00));
    lv_obj_set_style_local_bg_grad_color(obj,part,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x00, 0x00, 0x00));
    lv_obj_set_style_local_radius(obj,part,LV_STATE_DEFAULT,26);
    lv_obj_set_style_local_bg_opa(obj,part,LV_STATE_DEFAULT,153);
    lv_obj_set_style_local_border_color(obj,part,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
    lv_obj_set_style_local_border_opa(obj,part,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_shadow_width(obj,part,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_text_opa(obj,part,LV_STATE_DEFAULT,153);

//设置正常样式结束

//设置按下样式
        lv_obj_set_style_local_border_color(obj,part,LV_STATE_PRESSED,LV_COLOR_MAKE(0xff, 0xff, 0xff));

//设置按下样式结束

//设置禁用样式
        lv_obj_set_style_local_border_color(obj,part,LV_STATE_DISABLED,LV_COLOR_MAKE(0xff, 0xff, 0xff));

//设置禁用样式结束
    lv_obj_set_style_local_outline_width(but_sa_but_deep,LV_BTN_PART_MAIN,LV_STATE_DEFAULT,0);
	lv_obj_set_style_local_outline_width(but_sa_but_deep,LV_BTN_PART_MAIN,LV_STATE_FOCUSED,0);
    qmsd_obj_set_id(but_sa_but_deep,"but_sa_but_deep");

	lv_obj_set_click(but_sa_but_deep, false);
}

void qmsd_ima_sa_ima_create()
{
    ima_sa_ima = lv_img_create(screen_saver, NULL);
    lv_img_set_src(ima_sa_ima, &imgsaver_image_png);
#ifdef BLOCKLY_ima_sa_ima_EVENT_HANDLER
    lv_obj_set_event_cb(ima_sa_ima, __qmsd_ima_sa_ima_cb);
#endif
    lv_obj_set_pos(ima_sa_ima, 75, 364);
    qmsd_obj_set_id(ima_sa_ima,"ima_sa_ima");
}
    void qmsd_lab_sa_tips_create()
{
	lab_sa_tips = lv_label_create(screen_saver, NULL);
	lv_label_set_long_mode(lab_sa_tips,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(lab_sa_tips,true);
	lv_obj_set_size(lab_sa_tips, 200, 19);
//set label style
	lv_obj_set_style_local_text_color(lab_sa_tips,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(lab_sa_tips, "试试“小明，打开空调”");
	lv_label_set_align(lab_sa_tips, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(lab_sa_tips,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_20);
#ifdef BLOCKLY_lab_sa_tips_EVENT_HANDLER
	lv_obj_set_event_cb(lab_sa_tips, __qmsd_lab_sa_tips_cb);
#endif
	if(lab_sa_tips->coords.x2-lab_sa_tips->coords.x1<200)
	{
		int x_offset=(200-(lab_sa_tips->coords.x2-lab_sa_tips->coords.x1))/2;
		lv_obj_set_style_local_pad_left(lab_sa_tips,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(lab_sa_tips,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(lab_sa_tips->coords.y2-lab_sa_tips->coords.y1<19)
	{
		int y_offset=(19-(lab_sa_tips->coords.y2-lab_sa_tips->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(lab_sa_tips,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(lab_sa_tips,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(lab_sa_tips, 162, 388);
    qmsd_obj_set_id(lab_sa_tips,"lab_sa_tips");
}

static void screen_saver_qmsd_cb(lv_obj_t * obj, lv_event_t event, void *data)
{/*
    char *trans;
    lv_label_set_text(lab_sa_hour,qmsd_lang_get_trans("lab_sa_hour","10"));
    lv_label_set_text(lab_sa_min,qmsd_lang_get_trans("lab_sa_min","12"));
    lv_label_set_text(lab_sa_scr,qmsd_lang_get_trans("lab_sa_scr",":"));
    lv_label_set_text(lab_sa_data,qmsd_lang_get_trans("lab_sa_data","8月12日"));
    lv_label_set_text(lab_sa_week,qmsd_lang_get_trans("lab_sa_week","星期二"));
    lv_label_set_text(__but_sa_but_deep_label,qmsd_lang_get_trans("but_sa_but_deep",""));
    lv_label_set_text(lab_sa_tips,qmsd_lang_get_trans("lab_sa_tips","试试“小明，打开空调”"));
*/
#ifdef BLOCKLY_screen_saver_SCREEN_INIT
    __qmsd_screen_saver_init();
#endif
}

static void screen_saver_del_cb(lv_obj_t* obj,lv_event_t event)
{
    if(event == LV_EVENT_DELETE)
    {
        screen_saver=NULL;
        qmsd_screen_remove("screen_saver");
    }
}

void screen_saver_build(void)
{
    if(screen_saver) return;
    screen_saver = lv_obj_create(NULL, NULL);
    lv_obj_qmsd_set_cb(screen_saver, screen_saver_qmsd_cb);

    qmsd_image_saver_bot_create();
    qmsd_lab_sa_hour_create();
    qmsd_lab_sa_min_create();
    qmsd_lab_sa_scr_create();
    qmsd_lab_sa_data_create();
    qmsd_lab_sa_week_create();
    qmsd_but_sa_but_deep_create();
    qmsd_ima_sa_ima_create();
    qmsd_lab_sa_tips_create();
    lv_obj_set_event_cb(screen_saver,screen_saver_del_cb);
    qmsd_screen_register(screen_saver,"screen_saver");
}

void screen_saver_show(void)
{
    if(!screen_saver)
    {
        screen_saver_build();
    }
    lv_scr_load(screen_saver);
}

void screen_saver_delete(void)
{
    if(screen_saver)
    {
        lv_obj_del(screen_saver);
        screen_saver = NULL;
    }
}
