#include "qmsd_ui_entry.h"
#include "qmsd_internal_ui_cb.h"

lv_obj_t* main_tile_1;
lv_obj_t* label_main_time;
lv_obj_t* label_main_date;
lv_obj_t* image_0284;
lv_obj_t* image_c40b;
lv_obj_t* label_63b0;
lv_obj_t* image_ad04;
lv_obj_t* button_b1;
lv_obj_t * __button_b1_label;
lv_obj_t* button_b2;
lv_obj_t * __button_b2_label;
lv_obj_t* image_b1;
lv_obj_t* image_b2;
lv_obj_t* label_tile_b1;
lv_obj_t* label_tile_b2;
lv_obj_t* label_st_b1;
lv_obj_t* label_st_b2;


    void qmsd_label_main_time_create()
{
	label_main_time = lv_label_create(main_tile_1, NULL);
	lv_label_set_long_mode(label_main_time,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_main_time,true);
	lv_obj_set_size(label_main_time, 217, 66);
//set label style
	lv_obj_set_style_local_text_color(label_main_time,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(label_main_time, "10：58");
	lv_label_set_align(label_main_time, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(label_main_time,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_54);
#ifdef BLOCKLY_label_main_time_EVENT_HANDLER
	lv_obj_set_event_cb(label_main_time, __qmsd_label_main_time_cb);
#endif
	if(label_main_time->coords.x2-label_main_time->coords.x1<217)
	{
		int x_offset=(217-(label_main_time->coords.x2-label_main_time->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_main_time,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_main_time,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_main_time->coords.y2-label_main_time->coords.y1<66)
	{
		int y_offset=(66-(label_main_time->coords.y2-label_main_time->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_main_time,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_main_time,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(label_main_time, 40, 87);
    qmsd_obj_set_id(label_main_time,"label_main_time");
}
    void qmsd_label_main_date_create()
{
	label_main_date = lv_label_create(main_tile_1, NULL);
	lv_label_set_long_mode(label_main_date,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_main_date,true);
	lv_obj_set_size(label_main_date, 181, 40);
//set label style
	lv_obj_set_style_local_text_color(label_main_date,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(label_main_date, "星期三  8月26日");
	lv_label_set_align(label_main_date, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(label_main_date,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_22);
#ifdef BLOCKLY_label_main_date_EVENT_HANDLER
	lv_obj_set_event_cb(label_main_date, __qmsd_label_main_date_cb);
#endif
	if(label_main_date->coords.x2-label_main_date->coords.x1<181)
	{
		int x_offset=(181-(label_main_date->coords.x2-label_main_date->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_main_date,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_main_date,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_main_date->coords.y2-label_main_date->coords.y1<40)
	{
		int y_offset=(40-(label_main_date->coords.y2-label_main_date->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_main_date,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_main_date,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(label_main_date, 58, 153);
    qmsd_obj_set_id(label_main_date,"label_main_date");
}
    
void qmsd_image_0284_create()
{
    image_0284 = lv_img_create(main_tile_1, NULL);
    lv_img_set_src(image_0284, &imgwea_lighting_png);
#ifdef BLOCKLY_image_0284_EVENT_HANDLER
    lv_obj_set_event_cb(image_0284, __qmsd_image_0284_cb);
#endif
    lv_obj_set_pos(image_0284, 354, 94);
    qmsd_obj_set_id(image_0284,"image_0284");
}
    
void qmsd_image_c40b_create()
{
    image_c40b = lv_img_create(main_tile_1, NULL);
    lv_img_set_src(image_c40b, &imgdesktop1_png);
#ifdef BLOCKLY_image_c40b_EVENT_HANDLER
    lv_obj_set_event_cb(image_c40b, __qmsd_image_c40b_cb);
#endif
    lv_obj_set_pos(image_c40b, 34, 213);
    qmsd_obj_set_id(image_c40b,"image_c40b");
}
    void qmsd_label_63b0_create()
{
	label_63b0 = lv_label_create(main_tile_1, NULL);
	lv_label_set_long_mode(label_63b0,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_63b0,true);
	lv_obj_set_size(label_63b0, 214, 68);
//set label style
	lv_obj_set_style_local_bg_color(label_63b0,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x00, 0x00, 0x00));
	lv_obj_set_style_local_bg_opa(label_63b0,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,255);
	lv_obj_set_style_local_text_color(label_63b0,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(label_63b0, "日间模式");
	lv_label_set_align(label_63b0, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(label_63b0,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_27);
#ifdef BLOCKLY_label_63b0_EVENT_HANDLER
	lv_obj_set_event_cb(label_63b0, __qmsd_label_63b0_cb);
#endif
	if(label_63b0->coords.x2-label_63b0->coords.x1<214)
	{
		int x_offset=(214-(label_63b0->coords.x2-label_63b0->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_63b0,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_63b0,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_63b0->coords.y2-label_63b0->coords.y1<68)
	{
		int y_offset=(68-(label_63b0->coords.y2-label_63b0->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_63b0,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_63b0,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(label_63b0, 34, 356);
    qmsd_obj_set_id(label_63b0,"label_63b0");
}
    
void qmsd_image_ad04_create()
{
    image_ad04 = lv_img_create(main_tile_1, NULL);
    lv_img_set_src(image_ad04, &imgsun_png);
#ifdef BLOCKLY_image_ad04_EVENT_HANDLER
    lv_obj_set_event_cb(image_ad04, __qmsd_image_ad04_cb);
#endif
    lv_obj_set_pos(image_ad04, 51, 376);
    qmsd_obj_set_id(image_ad04,"image_ad04");
}
    void qmsd_button_b1_create()
{
    button_b1 = lv_imgbtn_create(main_tile_1, NULL);
    LV_IMG_DECLARE(imgbase_off_png);
    lv_imgbtn_set_src(button_b1, LV_BTN_STATE_RELEASED, &imgbase_off_png);
    lv_imgbtn_set_src(button_b1, LV_BTN_STATE_PRESSED, &imgbase_off_png);
    lv_imgbtn_set_src(button_b1, LV_BTN_STATE_DISABLED, &imgbase_off_png);
    LV_IMG_DECLARE(imgbaase_on_png);
    lv_btn_set_checkable(button_b1,true);
    lv_imgbtn_set_src(button_b1, LV_BTN_STATE_CHECKED_RELEASED, &imgbaase_on_png);
    lv_imgbtn_set_src(button_b1, LV_BTN_STATE_CHECKED_PRESSED, &imgbaase_on_png);
    lv_obj_set_size(button_b1, 180, 94);
    lv_obj_set_pos(button_b1, 267, 213);
#ifdef BLOCKLY_button_b1_EVENT_HANDLER
    lv_obj_set_event_cb(button_b1, __qmsd_button_b1_cb);
#endif


    lv_obj_t* obj = button_b1;
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
    lv_obj_set_style_local_outline_width(button_b1,LV_BTN_PART_MAIN,LV_STATE_DEFAULT,0);
	lv_obj_set_style_local_outline_width(button_b1,LV_BTN_PART_MAIN,LV_STATE_FOCUSED,0);
    qmsd_obj_set_id(button_b1,"button_b1");
}
    void qmsd_button_b2_create()
{
    button_b2 = lv_imgbtn_create(main_tile_1, NULL);
    LV_IMG_DECLARE(imgbase_off_png);
    lv_imgbtn_set_src(button_b2, LV_BTN_STATE_RELEASED, &imgbase_off_png);
    lv_imgbtn_set_src(button_b2, LV_BTN_STATE_PRESSED, &imgbase_off_png);
    lv_imgbtn_set_src(button_b2, LV_BTN_STATE_DISABLED, &imgbase_off_png);
    LV_IMG_DECLARE(imgbaase_on_png);
    lv_btn_set_checkable(button_b2,true);
    lv_imgbtn_set_src(button_b2, LV_BTN_STATE_CHECKED_RELEASED, &imgbaase_on_png);
    lv_imgbtn_set_src(button_b2, LV_BTN_STATE_CHECKED_PRESSED, &imgbaase_on_png);
    lv_obj_set_size(button_b2, 180, 94);
    lv_obj_set_pos(button_b2, 267, 329);
#ifdef BLOCKLY_button_b2_EVENT_HANDLER
    lv_obj_set_event_cb(button_b2, __qmsd_button_b2_cb);
#endif


    lv_obj_t* obj = button_b2;
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
    lv_obj_set_style_local_outline_width(button_b2,LV_BTN_PART_MAIN,LV_STATE_DEFAULT,0);
	lv_obj_set_style_local_outline_width(button_b2,LV_BTN_PART_MAIN,LV_STATE_FOCUSED,0);
    qmsd_obj_set_id(button_b2,"button_b2");
}
    
void qmsd_image_b1_create()
{
    image_b1 = lv_img_create(main_tile_1, NULL);
    lv_img_set_src(image_b1, &imgbase_light_png);
#ifdef BLOCKLY_image_b1_EVENT_HANDLER
    lv_obj_set_event_cb(image_b1, __qmsd_image_b1_cb);
#endif
    lv_obj_set_pos(image_b1, 286, 228);
    qmsd_obj_set_id(image_b1,"image_b1");
}
    
void qmsd_image_b2_create()
{
    image_b2 = lv_img_create(main_tile_1, NULL);
    lv_img_set_src(image_b2, &imgbase_light_png);
#ifdef BLOCKLY_image_b2_EVENT_HANDLER
    lv_obj_set_event_cb(image_b2, __qmsd_image_b2_cb);
#endif
    lv_obj_set_pos(image_b2, 286, 346);
    qmsd_obj_set_id(image_b2,"image_b2");
}
    void qmsd_label_tile_b1_create()
{
	label_tile_b1 = lv_label_create(main_tile_1, NULL);
	lv_label_set_long_mode(label_tile_b1,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_tile_b1,true);
	lv_obj_set_size(label_tile_b1, 63, 40);
//set label style
	lv_obj_set_style_local_text_color(label_tile_b1,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(label_tile_b1, "客厅");
	lv_label_set_align(label_tile_b1, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(label_tile_b1,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_23);
#ifdef BLOCKLY_label_tile_b1_EVENT_HANDLER
	lv_obj_set_event_cb(label_tile_b1, __qmsd_label_tile_b1_cb);
#endif
	if(label_tile_b1->coords.x2-label_tile_b1->coords.x1<63)
	{
		int x_offset=(63-(label_tile_b1->coords.x2-label_tile_b1->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_tile_b1,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_tile_b1,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_tile_b1->coords.y2-label_tile_b1->coords.y1<40)
	{
		int y_offset=(40-(label_tile_b1->coords.y2-label_tile_b1->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_tile_b1,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_tile_b1,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(label_tile_b1, 341, 228);
    qmsd_obj_set_id(label_tile_b1,"label_tile_b1");
}
    void qmsd_label_tile_b2_create()
{
	label_tile_b2 = lv_label_create(main_tile_1, NULL);
	lv_label_set_long_mode(label_tile_b2,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_tile_b2,true);
	lv_obj_set_size(label_tile_b2, 66, 40);
//set label style
	lv_obj_set_style_local_text_color(label_tile_b2,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(label_tile_b2, "走廊");
	lv_label_set_align(label_tile_b2, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(label_tile_b2,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_23);
#ifdef BLOCKLY_label_tile_b2_EVENT_HANDLER
	lv_obj_set_event_cb(label_tile_b2, __qmsd_label_tile_b2_cb);
#endif
	if(label_tile_b2->coords.x2-label_tile_b2->coords.x1<66)
	{
		int x_offset=(66-(label_tile_b2->coords.x2-label_tile_b2->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_tile_b2,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_tile_b2,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_tile_b2->coords.y2-label_tile_b2->coords.y1<40)
	{
		int y_offset=(40-(label_tile_b2->coords.y2-label_tile_b2->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_tile_b2,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_tile_b2,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(label_tile_b2, 338, 345);
    qmsd_obj_set_id(label_tile_b2,"label_tile_b2");
}
    void qmsd_label_st_b1_create()
{
	label_st_b1 = lv_label_create(main_tile_1, NULL);
	lv_label_set_long_mode(label_st_b1,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_st_b1,true);
	lv_obj_set_size(label_st_b1, 65, 40);
//set label style
	lv_obj_set_style_local_text_color(label_st_b1,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(label_st_b1, "关闭");
	lv_label_set_align(label_st_b1, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(label_st_b1,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_16);
#ifdef BLOCKLY_label_st_b1_EVENT_HANDLER
	lv_obj_set_event_cb(label_st_b1, __qmsd_label_st_b1_cb);
#endif
	if(label_st_b1->coords.x2-label_st_b1->coords.x1<65)
	{
		int x_offset=(65-(label_st_b1->coords.x2-label_st_b1->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_st_b1,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_st_b1,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_st_b1->coords.y2-label_st_b1->coords.y1<40)
	{
		int y_offset=(40-(label_st_b1->coords.y2-label_st_b1->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_st_b1,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_st_b1,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(label_st_b1, 341, 260);
    qmsd_obj_set_id(label_st_b1,"label_st_b1");
}
    void qmsd_label_st_b2_create()
{
	label_st_b2 = lv_label_create(main_tile_1, NULL);
	lv_label_set_long_mode(label_st_b2,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_st_b2,true);
	lv_obj_set_size(label_st_b2, 65, 40);
//set label style
	lv_obj_set_style_local_text_color(label_st_b2,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(label_st_b2, "关闭");
	lv_label_set_align(label_st_b2, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(label_st_b2,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_16);
#ifdef BLOCKLY_label_st_b2_EVENT_HANDLER
	lv_obj_set_event_cb(label_st_b2, __qmsd_label_st_b2_cb);
#endif
	if(label_st_b2->coords.x2-label_st_b2->coords.x1<65)
	{
		int x_offset=(65-(label_st_b2->coords.x2-label_st_b2->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_st_b2,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_st_b2,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_st_b2->coords.y2-label_st_b2->coords.y1<40)
	{
		int y_offset=(40-(label_st_b2->coords.y2-label_st_b2->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_st_b2,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_st_b2,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(label_st_b2, 341, 376);
    qmsd_obj_set_id(label_st_b2,"label_st_b2");
}

static void main_tile_1_qmsd_cb(lv_obj_t * obj, lv_event_t event, void *data)
{/*
    char *trans;
    lv_label_set_text(label_main_time,qmsd_lang_get_trans("label_main_time","10：58"));
    lv_label_set_text(label_main_date,qmsd_lang_get_trans("label_main_date","星期三  8月26日"));
    lv_label_set_text(label_63b0,qmsd_lang_get_trans("label_63b0","日间模式"));
    lv_label_set_text(label_tile_b1,qmsd_lang_get_trans("label_tile_b1","客厅"));
    lv_label_set_text(label_tile_b2,qmsd_lang_get_trans("label_tile_b2","走廊"));
    lv_label_set_text(label_st_b1,qmsd_lang_get_trans("label_st_b1","关闭"));
    lv_label_set_text(label_st_b2,qmsd_lang_get_trans("label_st_b2","关闭"));
*/
#ifdef BLOCKLY_main_tile_1_SCREEN_INIT
    __qmsd_main_tile_1_init();
#endif
}

void main_tile_1_tileview_cb(lv_obj_t* obj,lv_event_t event)
{
    if(event == LV_EVENT_DELETE)
    {
        main_tile_1 = NULL;
        qmsd_screen_remove("main_tile_1");
    }
}

void main_tile_1_build(void)
{
    if(main_tile_1) return;
    main_tile_1 = lv_obj_create(tileview_2093,NULL);
    lv_obj_qmsd_set_cb(main_tile_1, main_tile_1_qmsd_cb);
    lv_obj_set_size(main_tile_1,480,480);
    lv_obj_set_pos(main_tile_1,0*LV_HOR_RES,0*LV_VER_RES);
    lv_obj_set_event_cb(main_tile_1,main_tile_1_tileview_cb);
    lv_obj_set_style_local_bg_color(main_tile_1,LV_OBJ_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x00, 0x00, 0x00));
    lv_obj_set_style_local_border_width(main_tile_1,LV_OBJ_PART_MAIN,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_radius(main_tile_1,LV_OBJ_PART_MAIN,LV_STATE_DEFAULT,0);
    qmsd_label_main_time_create();
    lv_tileview_add_element(tileview_2093, label_main_time);
    qmsd_label_main_date_create();
    lv_tileview_add_element(tileview_2093, label_main_date);
    qmsd_image_0284_create();
    lv_tileview_add_element(tileview_2093, image_0284);
    qmsd_image_c40b_create();
    lv_tileview_add_element(tileview_2093, image_c40b);
    qmsd_label_63b0_create();
    lv_tileview_add_element(tileview_2093, label_63b0);
    qmsd_image_ad04_create();
    lv_tileview_add_element(tileview_2093, image_ad04);
    qmsd_button_b1_create();
    lv_tileview_add_element(tileview_2093, button_b1);
    qmsd_button_b2_create();
    lv_tileview_add_element(tileview_2093, button_b2);
    qmsd_image_b1_create();
    lv_tileview_add_element(tileview_2093, image_b1);
    qmsd_image_b2_create();
    lv_tileview_add_element(tileview_2093, image_b2);
    qmsd_label_tile_b1_create();
    lv_tileview_add_element(tileview_2093, label_tile_b1);
    qmsd_label_tile_b2_create();
    lv_tileview_add_element(tileview_2093, label_tile_b2);
    qmsd_label_st_b1_create();
    lv_tileview_add_element(tileview_2093, label_st_b1);
    qmsd_label_st_b2_create();
    lv_tileview_add_element(tileview_2093, label_st_b2);
    lv_tileview_add_element(tileview_2093, main_tile_1);
    qmsd_screen_register(main_tile_1,"main_tile_1");
}

void main_tile_1_show(void)
{
    lv_tileview_set_tile_act(tileview_2093,0,0,LV_ANIM_ON);
}


void main_tile_1_delete(void)
{

}
