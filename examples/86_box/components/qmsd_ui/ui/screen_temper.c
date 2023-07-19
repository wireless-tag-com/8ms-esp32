#include "qmsd_ui_entry.h"
#include "qmsd_internal_ui_cb.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

lv_obj_t* screen_temper;
lv_obj_t* image_te_bottom;
lv_obj_t* image_te_return;
lv_obj_t* label_te_return;
lv_obj_t* image_te_line;
lv_obj_t* switch_te;
lv_obj_t* label_te_temper;
lv_obj_t* label_te_curent;
lv_obj_t* label_te_centig;
lv_obj_t* image_te_up;
lv_obj_t* button_te_bott;
lv_obj_t * __button_te_bott_label;
lv_obj_t* label_te_set1;
lv_obj_t* label_te_set2;
lv_obj_t* label_te_windy;
lv_obj_t* image_te_slider;
lv_obj_t* image_te_light;
lv_obj_t* image_te_set;
lv_obj_t* button_te_barbt;
lv_obj_t * __button_te_barbt_label;
lv_obj_t* button_te_barra;
lv_obj_t * __button_te_barra_label;
lv_obj_t* image_te_fan;
lv_obj_t* image_te_bar;
lv_obj_t* bar_my_add;


    
void qmsd_image_te_bottom_create()
{
    image_te_bottom = lv_img_create(screen_temper, NULL);
    lv_img_set_src(image_te_bottom, &imgte_new_bottom_png);
#ifdef BLOCKLY_image_te_bottom_EVENT_HANDLER
    lv_obj_set_event_cb(image_te_bottom, __qmsd_image_te_bottom_cb);
#endif
    lv_obj_set_pos(image_te_bottom, 0, 127);
    qmsd_obj_set_id(image_te_bottom,"image_te_bottom");
}
    
void qmsd_image_te_return_create()
{
    image_te_return = lv_img_create(screen_temper, NULL);
    lv_img_set_src(image_te_return, &imgreturn_png);
#ifdef BLOCKLY_image_te_return_EVENT_HANDLER
    lv_obj_set_event_cb(image_te_return, __qmsd_image_te_return_cb);
#endif
    lv_obj_set_pos(image_te_return, 31.5, 32.5);
    lv_obj_set_click(image_te_return,true);
    lv_obj_set_style_local_image_recolor(image_te_return,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(image_te_return,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    qmsd_obj_set_id(image_te_return,"image_te_return");
}
    void qmsd_label_te_return_create()
{
	label_te_return = lv_label_create(screen_temper, NULL);
	lv_label_set_long_mode(label_te_return,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_te_return,true);
	lv_obj_set_size(label_te_return, 60, 33);
//set label style
	lv_obj_set_style_local_text_color(label_te_return,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(label_te_return, "返回");
	lv_label_set_align(label_te_return, LV_LABEL_ALIGN_LEFT);
	lv_obj_set_style_local_text_font(label_te_return,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_22);
#ifdef BLOCKLY_label_te_return_EVENT_HANDLER
	lv_obj_set_event_cb(label_te_return, __qmsd_label_te_return_cb);
#endif
    lv_obj_set_click(label_te_return,true);    
	if(label_te_return->coords.x2-label_te_return->coords.x1<60)
	{
		int x_offset=(60-(label_te_return->coords.x2-label_te_return->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_te_return,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_te_return,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_te_return->coords.y2-label_te_return->coords.y1<33)
	{
		int y_offset=(33-(label_te_return->coords.y2-label_te_return->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_te_return,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_te_return,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(label_te_return, 58, 24);
    qmsd_obj_set_id(label_te_return,"label_te_return");
}
    
void qmsd_image_te_line_create()
{
    image_te_line = lv_img_create(screen_temper, NULL);
    lv_img_set_src(image_te_line, &imgline_png);
#ifdef BLOCKLY_image_te_line_EVENT_HANDLER
    lv_obj_set_event_cb(image_te_line, __qmsd_image_te_line_cb);
#endif
    lv_obj_set_pos(image_te_line, 0, 70);
    qmsd_obj_set_id(image_te_line,"image_te_line");
}
    void qmsd_switch_te_create()
{
    switch_te = lv_switch_create(screen_temper, NULL);
    lv_obj_set_size(switch_te, 48, 32);
    lv_obj_set_pos(switch_te, 406, 19);
    if(0 == 0) {
    lv_switch_off(switch_te, LV_ANIM_OFF);
    } else {
    lv_switch_on(switch_te, LV_ANIM_OFF);
    }
//! add here 增加点击区域
    lv_obj_set_ext_click_area(switch_te,40,40,30,30);
    //set switch bg style
    lv_obj_set_style_local_bg_color(switch_te,LV_SWITCH_PART_BG,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xd4, 0xd7, 0xd9));
    lv_obj_set_style_local_bg_grad_color(switch_te,LV_SWITCH_PART_BG,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xd4, 0xd7, 0xd9));
    lv_obj_set_style_local_pad_top(switch_te,LV_SWITCH_PART_BG,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_pad_bottom(switch_te,LV_SWITCH_PART_BG,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_pad_left(switch_te,LV_SWITCH_PART_BG,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_pad_right(switch_te,LV_SWITCH_PART_BG,LV_STATE_DEFAULT,0);
    //set switch indic style
    lv_obj_set_style_local_bg_color(switch_te,LV_SWITCH_PART_INDIC,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x50, 0xe3, 0xc2));
    lv_obj_set_style_local_bg_grad_color(switch_te,LV_SWITCH_PART_INDIC,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x50, 0xe3, 0xc2));
    lv_obj_set_style_local_radius(switch_te,LV_SWITCH_PART_INDIC,LV_STATE_DEFAULT,LV_RADIUS_CIRCLE);
    lv_obj_set_style_local_pad_top(switch_te,LV_SWITCH_PART_INDIC,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_pad_bottom(switch_te,LV_SWITCH_PART_INDIC,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_pad_left(switch_te,LV_SWITCH_PART_INDIC,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_pad_right(switch_te,LV_SWITCH_PART_INDIC,LV_STATE_DEFAULT,0);
    //set switch knob style
    lv_obj_set_style_local_radius(switch_te,LV_SWITCH_PART_KNOB,LV_STATE_DEFAULT,LV_RADIUS_CIRCLE);

    lv_obj_set_style_local_border_opa(switch_te, LV_SWITCH_PART_BG, LV_STATE_DEFAULT, 0);
    lv_obj_set_style_local_border_opa(switch_te, LV_SWITCH_PART_BG, LV_STATE_FOCUSED, 0);
    lv_obj_set_style_local_outline_width(switch_te, LV_SWITCH_PART_BG, LV_STATE_DEFAULT, 0);
    lv_obj_set_style_local_outline_width(switch_te, LV_SWITCH_PART_BG, LV_STATE_FOCUSED, 0);
#ifdef BLOCKLY_switch_te_EVENT_HANDLER
    lv_obj_set_event_cb(switch_te, __qmsd_switch_te_cb);
#endif
    qmsd_obj_set_id(switch_te,"switch_te");
}
    void qmsd_label_te_temper_create()
{
	label_te_temper = lv_label_create(screen_temper, NULL);
	lv_label_set_long_mode(label_te_temper,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_te_temper,true);
	lv_obj_set_size(label_te_temper, 245, 44);
//set label style
	lv_obj_set_style_local_text_color(label_te_temper,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(label_te_temper, "CURRENT TEMPERATURE");
	lv_label_set_align(label_te_temper, LV_LABEL_ALIGN_LEFT);
	lv_obj_set_style_local_text_font(label_te_temper,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_20);
#ifdef BLOCKLY_label_te_temper_EVENT_HANDLER
	lv_obj_set_event_cb(label_te_temper, __qmsd_label_te_temper_cb);
#endif
	if(label_te_temper->coords.x2-label_te_temper->coords.x1<245)
	{
		int x_offset=(245-(label_te_temper->coords.x2-label_te_temper->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_te_temper,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_te_temper,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_te_temper->coords.y2-label_te_temper->coords.y1<44)
	{
		int y_offset=(44-(label_te_temper->coords.y2-label_te_temper->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_te_temper,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_te_temper,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(label_te_temper, 65, 116);
    qmsd_obj_set_id(label_te_temper,"label_te_temper");
}
    void qmsd_label_te_curent_create()
{
	label_te_curent = lv_label_create(screen_temper, NULL);
	lv_label_set_long_mode(label_te_curent,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_te_curent,true);
	lv_obj_set_size(label_te_curent, 169, 145);
//set label style
	lv_obj_set_style_local_text_color(label_te_curent,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(label_te_curent, "26");
	lv_label_set_align(label_te_curent, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(label_te_curent,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_124);
#ifdef BLOCKLY_label_te_curent_EVENT_HANDLER
	lv_obj_set_event_cb(label_te_curent, __qmsd_label_te_curent_cb);
#endif
	if(label_te_curent->coords.x2-label_te_curent->coords.x1<169)
	{
		int x_offset=(169-(label_te_curent->coords.x2-label_te_curent->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_te_curent,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_te_curent,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_te_curent->coords.y2-label_te_curent->coords.y1<145)
	{
		int y_offset=(145-(label_te_curent->coords.y2-label_te_curent->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_te_curent,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_te_curent,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(label_te_curent, 44, 159);
    qmsd_obj_set_id(label_te_curent,"label_te_curent");
}
    void qmsd_label_te_centig_create()
{
	label_te_centig = lv_label_create(screen_temper, NULL);
	lv_label_set_long_mode(label_te_centig,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_te_centig,true);
	lv_obj_set_size(label_te_centig, 42, 42);
//set label style
	lv_obj_set_style_local_text_color(label_te_centig,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(label_te_centig, "℃");
	lv_label_set_align(label_te_centig, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(label_te_centig,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_30);
#ifdef BLOCKLY_label_te_centig_EVENT_HANDLER
	lv_obj_set_event_cb(label_te_centig, __qmsd_label_te_centig_cb);
#endif
	if(label_te_centig->coords.x2-label_te_centig->coords.x1<42)
	{
		int x_offset=(42-(label_te_centig->coords.x2-label_te_centig->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_te_centig,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_te_centig,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_te_centig->coords.y2-label_te_centig->coords.y1<42)
	{
		int y_offset=(42-(label_te_centig->coords.y2-label_te_centig->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_te_centig,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_te_centig,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(label_te_centig, 211, 166);
    qmsd_obj_set_id(label_te_centig,"label_te_centig");
}
    
void qmsd_image_te_up_create()
{
    image_te_up = lv_img_create(screen_temper, NULL);
    lv_img_set_src(image_te_up, &imgte_up_png);
#ifdef BLOCKLY_image_te_up_EVENT_HANDLER
    lv_obj_set_event_cb(image_te_up, __qmsd_image_te_up_cb);
#endif
    lv_obj_set_pos(image_te_up, 223, 272);
    lv_obj_set_click(image_te_up,true);
    lv_obj_set_style_local_image_recolor(image_te_up,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(image_te_up,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    qmsd_obj_set_id(image_te_up,"image_te_up");
}
    void qmsd_button_te_bott_create()
{
    button_te_bott = lv_btn_create(screen_temper, NULL);
    __button_te_bott_label = lv_label_create(button_te_bott, NULL);
    lv_label_set_text(__button_te_bott_label,qmsd_lang_get_trans("button_te_bott",""));

    lv_obj_set_style_local_text_font(__button_te_bott_label,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_16);
    lv_obj_set_size(button_te_bott, 62, 38);
    // lv_obj_set_pos(button_te_bott, 129, 304);
    lv_obj_set_pos(button_te_bott, 134, 304);
#ifdef BLOCKLY_button_te_bott_EVENT_HANDLER
    lv_obj_set_event_cb(button_te_bott, __qmsd_button_te_bott_cb);
#endif


    lv_obj_t* obj = button_te_bott;
    int part = LV_BTN_PART_MAIN;
//设置正常样式
        lv_obj_set_style_local_bg_color(obj,part,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x90, 0x13, 0xfe));
    lv_obj_set_style_local_radius(obj,part,LV_STATE_DEFAULT,6);
    lv_obj_set_style_local_border_color(obj,part,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x9b, 0x9b, 0x9b));
    lv_obj_set_style_local_border_width(obj,part,LV_STATE_DEFAULT,2);
    lv_obj_set_style_local_shadow_width(obj,part,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_text_color(obj,part,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x31, 0x40, 0x4f));

//设置正常样式结束

//设置按下样式
        lv_obj_set_style_local_bg_color(obj,part,LV_STATE_PRESSED,LV_COLOR_MAKE(0x01, 0xa2, 0xb1));
    lv_obj_set_style_local_text_color(obj,part,LV_STATE_PRESSED,LV_COLOR_MAKE(0x31, 0x40, 0x4f));

//设置按下样式结束

//设置禁用样式
        lv_obj_set_style_local_text_color(obj,part,LV_STATE_DISABLED,LV_COLOR_MAKE(0x88, 0x88, 0x88));

//设置禁用样式结束
    lv_obj_set_style_local_outline_width(button_te_bott,LV_BTN_PART_MAIN,LV_STATE_DEFAULT,0);
	lv_obj_set_style_local_outline_width(button_te_bott,LV_BTN_PART_MAIN,LV_STATE_FOCUSED,0);
    qmsd_obj_set_id(button_te_bott,"button_te_bott");
}
    void qmsd_label_te_set1_create()
{
	label_te_set1 = lv_label_create(screen_temper, NULL);
	lv_label_set_long_mode(label_te_set1,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_te_set1,true);
	lv_obj_set_size(label_te_set1, 78, 40);
//set label style
	lv_obj_set_style_local_text_color(label_te_set1,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(label_te_set1, "设置");
	lv_label_set_align(label_te_set1, LV_LABEL_ALIGN_LEFT);
	lv_obj_set_style_local_text_font(label_te_set1,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_23);
#ifdef BLOCKLY_label_te_set1_EVENT_HANDLER
	lv_obj_set_event_cb(label_te_set1, __qmsd_label_te_set1_cb);
#endif
	if(label_te_set1->coords.x2-label_te_set1->coords.x1<78)
	{
		int x_offset=(78-(label_te_set1->coords.x2-label_te_set1->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_te_set1,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_te_set1,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_te_set1->coords.y2-label_te_set1->coords.y1<40)
	{
		int y_offset=(40-(label_te_set1->coords.y2-label_te_set1->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_te_set1,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_te_set1,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(label_te_set1, 64, 302);
    qmsd_obj_set_id(label_te_set1,"label_te_set1");
}
    void qmsd_label_te_set2_create()
{
	label_te_set2 = lv_label_create(screen_temper, NULL);
	lv_label_set_long_mode(label_te_set2,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_te_set2,true);
	lv_obj_set_size(label_te_set2, 59, 40);
//set label style
	lv_obj_set_style_local_text_color(label_te_set2,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(label_te_set2, "温度");
	lv_label_set_align(label_te_set2, LV_LABEL_ALIGN_RIGHT);
	lv_obj_set_style_local_text_font(label_te_set2,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_23);
#ifdef BLOCKLY_label_te_set2_EVENT_HANDLER
	lv_obj_set_event_cb(label_te_set2, __qmsd_label_te_set2_cb);
#endif
	if(label_te_set2->coords.x2-label_te_set2->coords.x1<59)
	{
		int x_offset=(59-(label_te_set2->coords.x2-label_te_set2->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_te_set2,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_te_set2,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_te_set2->coords.y2-label_te_set2->coords.y1<40)
	{
		int y_offset=(40-(label_te_set2->coords.y2-label_te_set2->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_te_set2,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_te_set2,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(label_te_set2, 200, 302);
    qmsd_obj_set_id(label_te_set2,"label_te_set2");
}
    void qmsd_label_te_windy_create()
{
	label_te_windy = lv_label_create(screen_temper, NULL);
	lv_label_set_long_mode(label_te_windy,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_te_windy,true);
	lv_obj_set_size(label_te_windy, 62, 38);
//set label style
	lv_obj_set_style_local_text_color(label_te_windy,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(label_te_windy, "28");
	lv_label_set_align(label_te_windy, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(label_te_windy,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_23);
#ifdef BLOCKLY_label_te_windy_EVENT_HANDLER
	lv_obj_set_event_cb(label_te_windy, __qmsd_label_te_windy_cb);
#endif
	if(label_te_windy->coords.x2-label_te_windy->coords.x1<62)
	{
		int x_offset=(62-(label_te_windy->coords.x2-label_te_windy->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_te_windy,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_te_windy,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_te_windy->coords.y2-label_te_windy->coords.y1<38)
	{
		int y_offset=(38-(label_te_windy->coords.y2-label_te_windy->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_te_windy,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_te_windy,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	// lv_obj_set_pos(label_te_windy, 129, 304);
    lv_obj_set_pos(label_te_windy, 134, 304);
    qmsd_obj_set_id(label_te_windy,"label_te_windy");
}
    
void qmsd_image_te_slider_create()
{
    image_te_slider = lv_img_create(screen_temper, NULL);
    lv_img_set_src(image_te_slider, &imgte_silder_png);
#ifdef BLOCKLY_image_te_slider_EVENT_HANDLER
    lv_obj_set_event_cb(image_te_slider, __qmsd_image_te_slider_cb);
#endif
    lv_obj_set_pos(image_te_slider, 47, 419);
    qmsd_obj_set_id(image_te_slider,"image_te_slider");
}
    
void qmsd_image_te_light_create()
{
    image_te_light = lv_img_create(screen_temper, NULL);
    lv_img_set_src(image_te_light, &imgte_light_png);
    // lv_obj_set_ext_click_area();
#ifdef BLOCKLY_image_te_light_EVENT_HANDLER
    lv_obj_set_event_cb(image_te_light, __qmsd_image_te_light_cb);
#endif
    lv_obj_set_pos(image_te_light, 6, 378);
    qmsd_obj_set_id(image_te_light,"image_te_light");
}

lv_obj_t* my_image_te_light;
void qmsd_my_image_te_light_create()
{
    my_image_te_light = lv_img_create(screen_temper, NULL);
    lv_img_set_src(my_image_te_light, &imgte_light_png);
#ifdef BLOCKLY_my_image_te_light_EVENT_HANDLER
    lv_obj_set_event_cb(my_image_te_light, __qmsd_my_image_te_light_cb);
#endif
    lv_obj_set_pos(my_image_te_light, 160, 378);
}

extern int set_windy;

void my_image_te_set_cb(lv_obj_t * obj, lv_event_t event)
{
    if(event == LV_EVENT_PRESSING) {
        _lv_indev_read(get_point, &my_data);
        if((my_data.point.x >= 36 && my_data.point.x <= 410)) {
            lv_obj_set_x(obj, my_data.point.x); 
            // lv_label_set_text_fmt(label_te_windy,"%d", 30-(((430-(my_data.point.x))/374)*14));
            lv_label_set_text_fmt(label_te_windy,"%d", 15+((14*my_data.point.x)/410));

            set_windy = 15+((14*my_data.point.x)/410);
        }        
    }
}
    
void qmsd_image_te_set_create()
{
    image_te_set = lv_img_create(screen_temper, NULL);
    lv_img_set_src(image_te_set, &imgte_set_png);
//! 增加点击区域
    // lv_obj_set_ext_click_area(image_te_set,40,40,40,40);
    lv_obj_set_ext_click_area(image_te_set,20,20,20,20);
    lv_obj_set_click(image_te_set,true);
#ifdef BLOCKLY_image_te_set_EVENT_HANDLER
    lv_obj_set_event_cb(image_te_set, __qmsd_image_te_set_cb);
#endif
    lv_obj_set_pos(image_te_set, 247, 411);
    qmsd_obj_set_id(image_te_set,"image_te_set");

    // lv_obj_set_event_cb(image_te_set, my_image_te_set_cb);
}
    void qmsd_button_te_barbt_create()
{
    button_te_barbt = lv_btn_create(screen_temper, NULL);
    __button_te_barbt_label = lv_label_create(button_te_barbt, NULL);
    lv_label_set_text(__button_te_barbt_label,qmsd_lang_get_trans("button_te_barbt",""));

    lv_obj_set_style_local_text_font(__button_te_barbt_label,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_16);
    lv_obj_set_size(button_te_barbt, 60, 214);
    lv_obj_set_pos(button_te_barbt, 355, 123);
#ifdef BLOCKLY_button_te_barbt_EVENT_HANDLER
    lv_obj_set_event_cb(button_te_barbt, __qmsd_button_te_barbt_cb);
#endif


    lv_obj_t* obj = button_te_barbt;
    int part = LV_BTN_PART_MAIN;
//设置正常样式
        lv_obj_set_style_local_radius(obj,part,LV_STATE_DEFAULT,20);
    lv_obj_set_style_local_bg_opa(obj,part,LV_STATE_DEFAULT,60);
    lv_obj_set_style_local_border_opa(obj,part,LV_STATE_DEFAULT,10);
    lv_obj_set_style_local_shadow_width(obj,part,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_text_color(obj,part,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x31, 0x40, 0x4f));

//设置正常样式结束

//设置按下样式
        lv_obj_set_style_local_bg_color(obj,part,LV_STATE_PRESSED,LV_COLOR_MAKE(0x01, 0xa2, 0xb1));
    lv_obj_set_style_local_text_color(obj,part,LV_STATE_PRESSED,LV_COLOR_MAKE(0x31, 0x40, 0x4f));

//设置按下样式结束

//设置禁用样式
        lv_obj_set_style_local_text_color(obj,part,LV_STATE_DISABLED,LV_COLOR_MAKE(0x88, 0x88, 0x88));

//设置禁用样式结束
    lv_obj_set_style_local_outline_width(button_te_barbt,LV_BTN_PART_MAIN,LV_STATE_DEFAULT,0);
	lv_obj_set_style_local_outline_width(button_te_barbt,LV_BTN_PART_MAIN,LV_STATE_FOCUSED,0);

    lv_obj_set_style_local_border_opa(button_te_barbt, LV_BTN_PART_MAIN, 0, LV_OPA_0);
    lv_obj_set_style_local_outline_width(button_te_barbt, 0, 0, 0);

    qmsd_obj_set_id(button_te_barbt,"button_te_barbt");
}
    void qmsd_button_te_barra_create()
{
    button_te_barra = lv_btn_create(screen_temper, NULL);
    __button_te_barra_label = lv_label_create(button_te_barra, NULL);
    lv_label_set_text(__button_te_barra_label,qmsd_lang_get_trans("button_te_barra",""));

    lv_obj_set_style_local_text_font(__button_te_barra_label,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_16);
    lv_obj_set_size(button_te_barra, 60, 87);
    lv_obj_set_pos(button_te_barra, 355, 250);
#ifdef BLOCKLY_button_te_barra_EVENT_HANDLER
    lv_obj_set_event_cb(button_te_barra, __qmsd_button_te_barra_cb);
#endif


    lv_obj_t* obj = button_te_barra;
    int part = LV_BTN_PART_MAIN;
//设置正常样式
        lv_obj_set_style_local_bg_color(obj,part,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x50, 0xe3, 0xc2));
    lv_obj_set_style_local_radius(obj,part,LV_STATE_DEFAULT,20);
    lv_obj_set_style_local_border_opa(obj,part,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_text_color(obj,part,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x31, 0x40, 0x4f));

//设置正常样式结束lv_obj_set_style_local_border_opa(obj,LV_BTN_PART_MAIN,LV_STATE_DEFAULT,LV_OPA_60);

//设置按下样式
        lv_obj_set_style_local_bg_color(obj,part,LV_STATE_PRESSED,LV_COLOR_MAKE(0x01, 0xa2, 0xb1));
    lv_obj_set_style_local_text_color(obj,part,LV_STATE_PRESSED,LV_COLOR_MAKE(0x31, 0x40, 0x4f));

//设置按下样式结束

//设置禁用样式
        lv_obj_set_style_local_text_color(obj,part,LV_STATE_DISABLED,LV_COLOR_MAKE(0x88, 0x88, 0x88));

//设置禁用样式结束
    lv_obj_set_style_local_outline_width(button_te_barra,LV_BTN_PART_MAIN,LV_STATE_DEFAULT,0);
	lv_obj_set_style_local_outline_width(button_te_barra,LV_BTN_PART_MAIN,LV_STATE_FOCUSED,0);
    qmsd_obj_set_id(button_te_barra,"button_te_barra");
}

void bar_my_add_create()
{
    bar_my_add = lv_bar_create(screen_temper, NULL);

    lv_obj_set_pos(bar_my_add, 58, 429);
    lv_obj_set_size(bar_my_add, 370, 13);
    lv_bar_set_value(bar_my_add, 56, LV_ANIM_OFF);

    lv_obj_set_style_local_bg_opa(bar_my_add, LV_BAR_PART_BG, LV_STATE_DEFAULT, 0);
    lv_obj_set_style_local_bg_opa(bar_my_add, LV_BAR_PART_INDIC, LV_STATE_DEFAULT, 255);

    lv_obj_set_style_local_border_opa(bar_my_add, 0, 0, 0);

    lv_obj_set_style_local_shadow_opa(bar_my_add, 0, 0, 0);

    lv_obj_set_style_local_bg_color(bar_my_add, LV_BAR_PART_INDIC, LV_STATE_DEFAULT, lv_color_hex(0x03cbfe));
}

void qmsd_image_te_fan_create()
{
    image_te_fan = lv_img_create(screen_temper, NULL);
    lv_img_set_src(image_te_fan, &imgte_fan_png);
#ifdef BLOCKLY_image_te_fan_EVENT_HANDLER
    lv_obj_set_event_cb(image_te_fan, __qmsd_image_te_fan_cb);
#endif
    lv_obj_set_pos(image_te_fan, 374, 137);
    qmsd_obj_set_id(image_te_fan,"image_te_fan");
}
 
void my_image_te_bar_cb(lv_obj_t * obj, lv_event_t event)
{
    if(event == LV_EVENT_PRESSING) {
        _lv_indev_read(get_point, &my_data);
        if((my_data.point.y >= 113 && my_data.point.y <= 307)) {
            lv_obj_set_y(obj, my_data.point.y);
            lv_obj_set_height(button_te_barra, 337-(my_data.point.y)-10);
            lv_obj_set_y(button_te_barra, my_data.point.y+10); 
        }        
    }
}
    
void qmsd_image_te_bar_create()
{
    image_te_bar = lv_img_create(screen_temper, NULL);
    lv_img_set_src(image_te_bar, &imgte_bar_png);
//! 增加点击区域
    lv_obj_set_ext_click_area(image_te_bar,40,40,40,40);
    lv_obj_set_click(image_te_bar,true);
#ifdef BLOCKLY_image_te_bar_EVENT_HANDLER
    lv_obj_set_event_cb(image_te_bar, __qmsd_image_te_bar_cb);
#endif
    lv_obj_set_pos(image_te_bar, 364, 235);
    qmsd_obj_set_id(image_te_bar,"image_te_bar");

    lv_obj_set_event_cb(image_te_bar, my_image_te_bar_cb);
}

static void screen_temper_qmsd_cb(lv_obj_t * obj, lv_event_t event, void *data)
{/*
    char *trans;
    lv_label_set_text(label_te_return,qmsd_lang_get_trans("label_te_return","返回"));
    lv_label_set_text(label_te_temper,qmsd_lang_get_trans("label_te_temper","CURRENT TEMPERATURE"));
    lv_label_set_text(label_te_curent,qmsd_lang_get_trans("label_te_curent","26"));
    lv_label_set_text(label_te_centig,qmsd_lang_get_trans("label_te_centig","℃"));
    lv_label_set_text(__button_te_bott_label,qmsd_lang_get_trans("button_te_bott",""));
    lv_label_set_text(label_te_set1,qmsd_lang_get_trans("label_te_set1","设置"));
    lv_label_set_text(label_te_set2,qmsd_lang_get_trans("label_te_set2","温度"));
    lv_label_set_text(label_te_windy,qmsd_lang_get_trans("label_te_windy","28"));
    lv_label_set_text(__button_te_barbt_label,qmsd_lang_get_trans("button_te_barbt",""));
    lv_label_set_text(__button_te_barra_label,qmsd_lang_get_trans("button_te_barra",""));
*/
#ifdef BLOCKLY_screen_temper_SCREEN_INIT
    __qmsd_screen_temper_init();
#endif
}

static void screen_temper_del_cb(lv_obj_t* obj,lv_event_t event)
{
    if(event == LV_EVENT_DELETE)
    {
        screen_temper=NULL;
        qmsd_screen_remove("screen_temper");
    }
}

#define QUEUE_LEN  8
#define QUEUE_SIZE 16
QueueHandle_t Test_Queue = NULL;


void touch_task_cb(lv_task_t * task)
{
    int event_num = 1;
    xQueueSend(Test_Queue, /* 消息队列的句柄 */ 
                &event_num,/* 发送的消息内容 */ 
                50); /* 等待时间 0 */
}

void touch_listen_cb(lv_task_t * task)
{
    int event_num = 0;
    xQueueReceive(Test_Queue, /* 消息队列的句柄 */ 
            &event_num, /* 发送的消息内容 */ 
            5 / portTICK_PERIOD_MS); /* 等待时间 一直等 */
    
    if(event_num == 1){
        _lv_indev_read(get_point, &my_data);
        if((my_data.point.x >= 36 && my_data.point.x <= 416) && (my_data.point.y >= 400 && my_data.point.y <= 480)) {
            lv_obj_set_x(image_te_set, my_data.point.x); 
            // lv_label_set_text_fmt(label_te_windy,"%d", 30-(((430-(my_data.point.x))/374)*14));
            lv_label_set_text_fmt(label_te_windy,"%d", 15+((14*my_data.point.x)/410));

            int index_x = my_data.point.x;
            // set_windy = 15+((14*my_data.point.x)/410);
            set_windy = 16+(14*(index_x-36)/380);
            lv_bar_set_value(bar_my_add, (100*(index_x-36)/380), LV_ANIM_OFF);

            // printf("x的坐标为: %d\n", index_x);
        }
    }

}

void screen_temper_build(void)
{
    if(screen_temper) return;
    screen_temper = lv_obj_create(NULL, NULL);
    lv_obj_qmsd_set_cb(screen_temper, screen_temper_qmsd_cb);
    lv_obj_set_style_local_bg_color(screen_temper,LV_OBJ_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x31, 0x04, 0x58));

    qmsd_image_te_bottom_create();
    qmsd_image_te_return_create();
    qmsd_label_te_return_create();
    qmsd_image_te_line_create();
    qmsd_switch_te_create();
    qmsd_label_te_temper_create();
    qmsd_label_te_curent_create();
    qmsd_label_te_centig_create();
    qmsd_image_te_up_create();
    qmsd_button_te_bott_create();
    qmsd_label_te_set1_create();
    qmsd_label_te_set2_create();
    qmsd_label_te_windy_create();
    qmsd_image_te_slider_create();
    // qmsd_my_image_te_light_create();
    // qmsd_image_te_light_create();
    bar_my_add_create();
    qmsd_image_te_set_create();
    qmsd_button_te_barbt_create();
    qmsd_button_te_barra_create();
    qmsd_image_te_fan_create();
    qmsd_image_te_bar_create();
    lv_obj_set_event_cb(screen_temper,screen_temper_del_cb);

    Test_Queue = xQueueCreate((UBaseType_t ) QUEUE_LEN, (UBaseType_t ) QUEUE_SIZE);

    lv_task_t * touch_task = lv_task_create(touch_task_cb, 5, LV_TASK_PRIO_MID, NULL);
    lv_task_t * touch_listen_task = lv_task_create(touch_listen_cb, 10, LV_TASK_PRIO_MID, NULL);

    qmsd_screen_register(screen_temper,"screen_temper");
}

void screen_temper_show(void)
{
    if(!screen_temper)
    {
        screen_temper_build();
    }
    lv_scr_load(screen_temper);
}

void screen_temper_delete(void)
{
    if(screen_temper)
    {
        lv_obj_del(screen_temper);
        screen_temper = NULL;
    }
}
