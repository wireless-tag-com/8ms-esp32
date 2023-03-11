#include "qmsd_ui_entry.h"
#include "qmsd_internal_ui_cb.h"

lv_obj_t* main_tile_2;
lv_obj_t* button_b3;
lv_obj_t * __button_b3_label;
lv_obj_t* image_b3;
lv_obj_t* label_tile_b3;
lv_obj_t* label_st_b3;
lv_obj_t* button_b4;
lv_obj_t * __button_b4_label;
lv_obj_t* image_b4;
lv_obj_t* label_tile_b4;
lv_obj_t* label_st_b4;
lv_obj_t* image_6d7d;
lv_obj_t* bar_main;
lv_obj_t* image_close;
lv_obj_t* image_stop;
lv_obj_t* image_open;
lv_obj_t* label_d51e;


    void qmsd_button_b3_create()
{
    button_b3 = lv_imgbtn_create(main_tile_2, NULL);
    LV_IMG_DECLARE(imgbase_off_png);
    lv_imgbtn_set_src(button_b3, LV_BTN_STATE_RELEASED, &imgbase_off_png);
    lv_imgbtn_set_src(button_b3, LV_BTN_STATE_PRESSED, &imgbase_off_png);
    lv_imgbtn_set_src(button_b3, LV_BTN_STATE_DISABLED, &imgbase_off_png);
    LV_IMG_DECLARE(imgbaase_on_png);
    lv_btn_set_checkable(button_b3,true);
    lv_imgbtn_set_src(button_b3, LV_BTN_STATE_CHECKED_RELEASED, &imgbaase_on_png);
    lv_imgbtn_set_src(button_b3, LV_BTN_STATE_CHECKED_PRESSED, &imgbaase_on_png);
    lv_obj_set_size(button_b3, 180, 94);
    lv_obj_set_pos(button_b3, 31, 68);
#ifdef BLOCKLY_button_b3_EVENT_HANDLER
    lv_obj_set_event_cb(button_b3, __qmsd_button_b3_cb);
#endif


    lv_obj_t* obj = button_b3;
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
    lv_obj_set_style_local_outline_width(button_b3,LV_BTN_PART_MAIN,LV_STATE_DEFAULT,0);
	lv_obj_set_style_local_outline_width(button_b3,LV_BTN_PART_MAIN,LV_STATE_FOCUSED,0);
    qmsd_obj_set_id(button_b3,"button_b3");
}
    
void qmsd_image_b3_create()
{
    image_b3 = lv_img_create(main_tile_2, NULL);
    lv_img_set_src(image_b3, &imgbase_light_png);
#ifdef BLOCKLY_image_b3_EVENT_HANDLER
    lv_obj_set_event_cb(image_b3, __qmsd_image_b3_cb);
#endif
    lv_obj_set_pos(image_b3, 50, 83);
    qmsd_obj_set_id(image_b3,"image_b3");
}
    void qmsd_label_tile_b3_create()
{
	label_tile_b3 = lv_label_create(main_tile_2, NULL);
	lv_label_set_long_mode(label_tile_b3,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_tile_b3,true);
	lv_obj_set_size(label_tile_b3, 63, 40);
//set label style
	lv_obj_set_style_local_text_color(label_tile_b3,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(label_tile_b3, "卧室");
	lv_label_set_align(label_tile_b3, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(label_tile_b3,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_23);
#ifdef BLOCKLY_label_tile_b3_EVENT_HANDLER
	lv_obj_set_event_cb(label_tile_b3, __qmsd_label_tile_b3_cb);
#endif
	if(label_tile_b3->coords.x2-label_tile_b3->coords.x1<63)
	{
		int x_offset=(63-(label_tile_b3->coords.x2-label_tile_b3->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_tile_b3,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_tile_b3,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_tile_b3->coords.y2-label_tile_b3->coords.y1<40)
	{
		int y_offset=(40-(label_tile_b3->coords.y2-label_tile_b3->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_tile_b3,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_tile_b3,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(label_tile_b3, 107, 83);
    qmsd_obj_set_id(label_tile_b3,"label_tile_b3");
}
    void qmsd_label_st_b3_create()
{
	label_st_b3 = lv_label_create(main_tile_2, NULL);
	lv_label_set_long_mode(label_st_b3,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_st_b3,true);
	lv_obj_set_size(label_st_b3, 65, 40);
//set label style
	lv_obj_set_style_local_text_color(label_st_b3,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(label_st_b3, "关闭");
	lv_label_set_align(label_st_b3, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(label_st_b3,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_16);
#ifdef BLOCKLY_label_st_b3_EVENT_HANDLER
	lv_obj_set_event_cb(label_st_b3, __qmsd_label_st_b3_cb);
#endif
	if(label_st_b3->coords.x2-label_st_b3->coords.x1<65)
	{
		int x_offset=(65-(label_st_b3->coords.x2-label_st_b3->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_st_b3,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_st_b3,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_st_b3->coords.y2-label_st_b3->coords.y1<40)
	{
		int y_offset=(40-(label_st_b3->coords.y2-label_st_b3->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_st_b3,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_st_b3,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(label_st_b3, 105, 111);
    qmsd_obj_set_id(label_st_b3,"label_st_b3");
}
    void qmsd_button_b4_create()
{
    button_b4 = lv_imgbtn_create(main_tile_2, NULL);
    LV_IMG_DECLARE(imgbase_off_png);
    lv_imgbtn_set_src(button_b4, LV_BTN_STATE_RELEASED, &imgbase_off_png);
    lv_imgbtn_set_src(button_b4, LV_BTN_STATE_PRESSED, &imgbase_off_png);
    lv_imgbtn_set_src(button_b4, LV_BTN_STATE_DISABLED, &imgbase_off_png);
    LV_IMG_DECLARE(imgbaase_on_png);
    lv_btn_set_checkable(button_b4,true);
    lv_imgbtn_set_src(button_b4, LV_BTN_STATE_CHECKED_RELEASED, &imgbaase_on_png);
    lv_imgbtn_set_src(button_b4, LV_BTN_STATE_CHECKED_PRESSED, &imgbaase_on_png);
    lv_obj_set_size(button_b4, 180, 94);
    lv_obj_set_pos(button_b4, 31, 184);
#ifdef BLOCKLY_button_b4_EVENT_HANDLER
    lv_obj_set_event_cb(button_b4, __qmsd_button_b4_cb);
#endif


    lv_obj_t* obj = button_b4;
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
    lv_obj_set_style_local_outline_width(button_b4,LV_BTN_PART_MAIN,LV_STATE_DEFAULT,0);
	lv_obj_set_style_local_outline_width(button_b4,LV_BTN_PART_MAIN,LV_STATE_FOCUSED,0);
    qmsd_obj_set_id(button_b4,"button_b4");
}
    
void qmsd_image_b4_create()
{
    image_b4 = lv_img_create(main_tile_2, NULL);
    lv_img_set_src(image_b4, &imgbase_light_png);
#ifdef BLOCKLY_image_b4_EVENT_HANDLER
    lv_obj_set_event_cb(image_b4, __qmsd_image_b4_cb);
#endif
    lv_obj_set_pos(image_b4, 50, 202);
    qmsd_obj_set_id(image_b4,"image_b4");
}
    void qmsd_label_tile_b4_create()
{
	label_tile_b4 = lv_label_create(main_tile_2, NULL);
	lv_label_set_long_mode(label_tile_b4,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_tile_b4,true);
	lv_obj_set_size(label_tile_b4, 63, 40);
//set label style
	lv_obj_set_style_local_text_color(label_tile_b4,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(label_tile_b4, "厨房");
	lv_label_set_align(label_tile_b4, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(label_tile_b4,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_23);
#ifdef BLOCKLY_label_tile_b4_EVENT_HANDLER
	lv_obj_set_event_cb(label_tile_b4, __qmsd_label_tile_b4_cb);
#endif
	if(label_tile_b4->coords.x2-label_tile_b4->coords.x1<63)
	{
		int x_offset=(63-(label_tile_b4->coords.x2-label_tile_b4->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_tile_b4,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_tile_b4,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_tile_b4->coords.y2-label_tile_b4->coords.y1<40)
	{
		int y_offset=(40-(label_tile_b4->coords.y2-label_tile_b4->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_tile_b4,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_tile_b4,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(label_tile_b4, 107, 199);
    qmsd_obj_set_id(label_tile_b4,"label_tile_b4");
}
    void qmsd_label_st_b4_create()
{
	label_st_b4 = lv_label_create(main_tile_2, NULL);
	lv_label_set_long_mode(label_st_b4,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_st_b4,true);
	lv_obj_set_size(label_st_b4, 65, 40);
//set label style
	lv_obj_set_style_local_text_color(label_st_b4,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(label_st_b4, "关闭");
	lv_label_set_align(label_st_b4, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(label_st_b4,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_16);
#ifdef BLOCKLY_label_st_b4_EVENT_HANDLER
	lv_obj_set_event_cb(label_st_b4, __qmsd_label_st_b4_cb);
#endif
	if(label_st_b4->coords.x2-label_st_b4->coords.x1<65)
	{
		int x_offset=(65-(label_st_b4->coords.x2-label_st_b4->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_st_b4,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_st_b4,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_st_b4->coords.y2-label_st_b4->coords.y1<40)
	{
		int y_offset=(40-(label_st_b4->coords.y2-label_st_b4->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_st_b4,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_st_b4,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(label_st_b4, 105, 229);
    qmsd_obj_set_id(label_st_b4,"label_st_b4");
}
    
void qmsd_image_6d7d_create()
{
    image_6d7d = lv_img_create(main_tile_2, NULL);
    lv_img_set_src(image_6d7d, &imgbase_green_png);
#ifdef BLOCKLY_image_6d7d_EVENT_HANDLER
    lv_obj_set_event_cb(image_6d7d, __qmsd_image_6d7d_cb);
#endif
    lv_obj_set_pos(image_6d7d, 238, 67);
    qmsd_obj_set_id(image_6d7d,"image_6d7d");
}
    void qmsd_bar_main_create()
{
	bar_main = lv_bar_create(main_tile_2, NULL);
	lv_obj_set_size(bar_main, 164, 44);
    lv_obj_set_pos(bar_main, 259, 156);
	lv_bar_set_anim_time(bar_main, 1000);
	lv_bar_set_value(bar_main, 0, LV_ANIM_ON);

/*Create a bar, an indicator and a knob style*/
	//set main part style
    lv_obj_set_style_local_bg_color(bar_main,LV_BAR_PART_BG,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xCC, 0xCC, 0xCC));
	lv_obj_set_style_local_bg_grad_color(bar_main,LV_BAR_PART_BG,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xCC, 0xCC, 0xCC));
    lv_obj_set_style_local_pad_top(bar_main,LV_BAR_PART_BG,LV_STATE_DEFAULT,0);
	lv_obj_set_style_local_pad_bottom(bar_main,LV_BAR_PART_BG,LV_STATE_DEFAULT,0);
	lv_obj_set_style_local_pad_left(bar_main,LV_BAR_PART_BG,LV_STATE_DEFAULT,0);
	lv_obj_set_style_local_pad_right(bar_main,LV_BAR_PART_BG,LV_STATE_DEFAULT,0);
	//set indic style
    lv_obj_set_style_local_bg_color(bar_main, LV_BAR_PART_INDIC,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x00, 0xff, 0x0c));
	lv_obj_set_style_local_bg_grad_color(bar_main, LV_BAR_PART_INDIC,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x00, 0xff, 0x0c));
    lv_obj_set_style_local_radius(bar_main, LV_BAR_PART_INDIC,LV_STATE_DEFAULT,LV_RADIUS_CIRCLE);
    lv_obj_set_style_local_pad_top(bar_main, LV_BAR_PART_INDIC,LV_STATE_DEFAULT,0);
	lv_obj_set_style_local_pad_bottom(bar_main, LV_BAR_PART_INDIC,LV_STATE_DEFAULT,0);
	lv_obj_set_style_local_pad_left(bar_main, LV_BAR_PART_INDIC,LV_STATE_DEFAULT,0);
	lv_obj_set_style_local_pad_right(bar_main, LV_BAR_PART_INDIC,LV_STATE_DEFAULT,0);
    qmsd_obj_set_id(bar_main,"bar_main");
}
    
void qmsd_image_close_create()
{
    image_close = lv_img_create(main_tile_2, NULL);
    lv_img_set_src(image_close, &imgb5_close_png);
#ifdef BLOCKLY_image_close_EVENT_HANDLER
    lv_obj_set_event_cb(image_close, __qmsd_image_close_cb);
#endif
    lv_obj_set_pos(image_close, 267, 230);
    lv_obj_set_click(image_close,true);
    lv_obj_set_style_local_image_recolor(image_close,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(image_close,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    qmsd_obj_set_id(image_close,"image_close");
}
    
void qmsd_image_stop_create()
{
    image_stop = lv_img_create(main_tile_2, NULL);
    lv_img_set_src(image_stop, &imgb5_stop_png);
#ifdef BLOCKLY_image_stop_EVENT_HANDLER
    lv_obj_set_event_cb(image_stop, __qmsd_image_stop_cb);
#endif
    lv_obj_set_pos(image_stop, 320, 213);
    lv_obj_set_click(image_stop,true);
    lv_obj_set_style_local_image_recolor(image_stop,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(image_stop,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    qmsd_obj_set_id(image_stop,"image_stop");
}
    
void qmsd_image_open_create()
{
    image_open = lv_img_create(main_tile_2, NULL);
    lv_img_set_src(image_open, &imgb5_open_png);
#ifdef BLOCKLY_image_open_EVENT_HANDLER
    lv_obj_set_event_cb(image_open, __qmsd_image_open_cb);
#endif
    lv_obj_set_pos(image_open, 398, 230);
    lv_obj_set_click(image_open,true);
    lv_obj_set_style_local_image_recolor(image_open,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(image_open,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    qmsd_obj_set_id(image_open,"image_open");
}
    void qmsd_label_d51e_create()
{
	label_d51e = lv_label_create(main_tile_2, NULL);
	lv_label_set_long_mode(label_d51e,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_d51e,true);
	lv_obj_set_size(label_d51e, 100, 40);
//set label style
	lv_obj_set_style_local_text_color(label_d51e,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(label_d51e, "窗帘");
	lv_label_set_align(label_d51e, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(label_d51e,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_23);
#ifdef BLOCKLY_label_d51e_EVENT_HANDLER
	lv_obj_set_event_cb(label_d51e, __qmsd_label_d51e_cb);
#endif
	if(label_d51e->coords.x2-label_d51e->coords.x1<100)
	{
		int x_offset=(100-(label_d51e->coords.x2-label_d51e->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_d51e,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_d51e,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_d51e->coords.y2-label_d51e->coords.y1<40)
	{
		int y_offset=(40-(label_d51e->coords.y2-label_d51e->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_d51e,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_d51e,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(label_d51e, 238, 67);
    qmsd_obj_set_id(label_d51e,"label_d51e");
}

static void main_tile_2_qmsd_cb(lv_obj_t * obj, lv_event_t event, void *data)
{/*
    char *trans;
    lv_label_set_text(label_tile_b3,qmsd_lang_get_trans("label_tile_b3","卧室"));
    lv_label_set_text(label_st_b3,qmsd_lang_get_trans("label_st_b3","关闭"));
    lv_label_set_text(label_tile_b4,qmsd_lang_get_trans("label_tile_b4","厨房"));
    lv_label_set_text(label_st_b4,qmsd_lang_get_trans("label_st_b4","关闭"));
    lv_label_set_text(label_d51e,qmsd_lang_get_trans("label_d51e","窗帘"));
*/
#ifdef BLOCKLY_main_tile_2_SCREEN_INIT
    __qmsd_main_tile_2_init();
#endif
}

void main_tile_2_tileview_cb(lv_obj_t* obj,lv_event_t event)
{
    if(event == LV_EVENT_DELETE)
    {
        main_tile_2 = NULL;
        qmsd_screen_remove("main_tile_2");
    }
}

void main_tile_2_build(void)
{
    if(main_tile_2) return;
    main_tile_2 = lv_obj_create(tileview_2093,NULL);
    lv_obj_qmsd_set_cb(main_tile_2, main_tile_2_qmsd_cb);
    lv_obj_set_size(main_tile_2,480,480);
    lv_obj_set_pos(main_tile_2,1*LV_HOR_RES,0*LV_VER_RES);
    lv_obj_set_event_cb(main_tile_2,main_tile_2_tileview_cb);
    lv_obj_set_style_local_bg_color(main_tile_2,LV_OBJ_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x00, 0x00, 0x00));
    lv_obj_set_style_local_border_width(main_tile_2,LV_OBJ_PART_MAIN,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_radius(main_tile_2,LV_OBJ_PART_MAIN,LV_STATE_DEFAULT,0);
    qmsd_button_b3_create();
    lv_tileview_add_element(tileview_2093, button_b3);
    qmsd_image_b3_create();
    lv_tileview_add_element(tileview_2093, image_b3);
    qmsd_label_tile_b3_create();
    lv_tileview_add_element(tileview_2093, label_tile_b3);
    qmsd_label_st_b3_create();
    lv_tileview_add_element(tileview_2093, label_st_b3);
    qmsd_button_b4_create();
    lv_tileview_add_element(tileview_2093, button_b4);
    qmsd_image_b4_create();
    lv_tileview_add_element(tileview_2093, image_b4);
    qmsd_label_tile_b4_create();
    lv_tileview_add_element(tileview_2093, label_tile_b4);
    qmsd_label_st_b4_create();
    lv_tileview_add_element(tileview_2093, label_st_b4);
    qmsd_image_6d7d_create();
    lv_tileview_add_element(tileview_2093, image_6d7d);
    qmsd_bar_main_create();
    lv_tileview_add_element(tileview_2093, bar_main);
    qmsd_image_close_create();
    lv_tileview_add_element(tileview_2093, image_close);
    qmsd_image_stop_create();
    lv_tileview_add_element(tileview_2093, image_stop);
    qmsd_image_open_create();
    lv_tileview_add_element(tileview_2093, image_open);
    qmsd_label_d51e_create();
    lv_tileview_add_element(tileview_2093, label_d51e);
    lv_tileview_add_element(tileview_2093, main_tile_2);
    qmsd_screen_register(main_tile_2,"main_tile_2");
}

void main_tile_2_show(void)
{
    lv_tileview_set_tile_act(tileview_2093,1,0,LV_ANIM_ON);
}


void main_tile_2_delete(void)
{

}
