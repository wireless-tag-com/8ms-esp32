#include "qmsd_ui_entry.h"
#include "qmsd_internal_ui_cb.h"

lv_obj_t* screen_air;
lv_obj_t* ima_air_re;
lv_obj_t* lab_air_re;
lv_obj_t* swi_air_swi;
lv_obj_t* lab_air_text;
lv_obj_t* lab_air_tem;
lv_obj_t* lab_air_tem_;
lv_obj_t* ima_air_co;
lv_obj_t* ima_air_sun;
lv_obj_t* ima_air_lo;
lv_obj_t* ima_air_mi;
lv_obj_t* ima_air_hi;
lv_obj_t* lab_air_pat;
lv_obj_t* lab_air_pow;
lv_obj_t* ima_air_4;
lv_obj_t* ima_air_5;
lv_obj_t* ima_air_6;
lv_obj_t* ima_air_7;
lv_obj_t* ima_air_8;
lv_obj_t* ima_air_9;
lv_obj_t* ima_air_10;
lv_obj_t* ima_air_11;
lv_obj_t* ima_air_12;
lv_obj_t* ima_air_13;
lv_obj_t* ima_air_14;
lv_obj_t* ima_air_15;
lv_obj_t* ima_air_16;
lv_obj_t* ima_air_17;
lv_obj_t* ima_air_18;
lv_obj_t* ima_air_sign;


    
void qmsd_ima_air_re_create()
{
    ima_air_re = lv_img_create(screen_air, NULL);
    lv_img_set_src(ima_air_re, &imgchoice_return_png);
#ifdef BLOCKLY_ima_air_re_EVENT_HANDLER
    lv_obj_set_event_cb(ima_air_re, __qmsd_ima_air_re_cb);
#endif
    lv_obj_set_pos(ima_air_re, 44, 42);
    lv_obj_set_click(ima_air_re,true);
    lv_obj_set_style_local_image_recolor(ima_air_re,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(ima_air_re,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    qmsd_obj_set_id(ima_air_re,"ima_air_re");
}
    void qmsd_lab_air_re_create()
{
	lab_air_re = lv_label_create(screen_air, NULL);
	lv_label_set_long_mode(lab_air_re,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(lab_air_re,true);
	lv_obj_set_size(lab_air_re, 49, 23);
//set label style
	lv_obj_set_style_local_text_color(lab_air_re,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(lab_air_re, "空调");
	lv_label_set_align(lab_air_re, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(lab_air_re,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_24);
#ifdef BLOCKLY_lab_air_re_EVENT_HANDLER
	lv_obj_set_event_cb(lab_air_re, __qmsd_lab_air_re_cb);
#endif
    lv_obj_set_click(lab_air_re,true);    
	if(lab_air_re->coords.x2-lab_air_re->coords.x1<49)
	{
		int x_offset=(49-(lab_air_re->coords.x2-lab_air_re->coords.x1))/2;
		lv_obj_set_style_local_pad_left(lab_air_re,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(lab_air_re,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(lab_air_re->coords.y2-lab_air_re->coords.y1<23)
	{
		int y_offset=(23-(lab_air_re->coords.y2-lab_air_re->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(lab_air_re,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(lab_air_re,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(lab_air_re, 76, 42);
    qmsd_obj_set_id(lab_air_re,"lab_air_re");
}
    void qmsd_swi_air_swi_create()
{
    swi_air_swi = lv_switch_create(screen_air, NULL);
    lv_obj_set_size(swi_air_swi, 59, 31);
    lv_obj_set_pos(swi_air_swi, 372, 38);
    if(0 == 0) {
    lv_switch_off(swi_air_swi, LV_ANIM_OFF);
    } else {
    lv_switch_on(swi_air_swi, LV_ANIM_OFF);
    }
    //set switch bg style
    lv_obj_set_style_local_bg_color(swi_air_swi,LV_SWITCH_PART_BG,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xCC, 0xCC, 0xCC));
    lv_obj_set_style_local_bg_grad_color(swi_air_swi,LV_SWITCH_PART_BG,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xCC, 0xCC, 0xCC));
    lv_obj_set_style_local_pad_top(swi_air_swi,LV_SWITCH_PART_BG,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_pad_bottom(swi_air_swi,LV_SWITCH_PART_BG,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_pad_left(swi_air_swi,LV_SWITCH_PART_BG,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_pad_right(swi_air_swi,LV_SWITCH_PART_BG,LV_STATE_DEFAULT,0);
    //set switch indic style
    lv_obj_set_style_local_bg_color(swi_air_swi,LV_SWITCH_PART_INDIC,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x4a, 0x90, 0xe2));
    lv_obj_set_style_local_bg_grad_color(swi_air_swi,LV_SWITCH_PART_INDIC,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x4a, 0x90, 0xe2));
    lv_obj_set_style_local_radius(swi_air_swi,LV_SWITCH_PART_INDIC,LV_STATE_DEFAULT,LV_RADIUS_CIRCLE);
    lv_obj_set_style_local_pad_top(swi_air_swi,LV_SWITCH_PART_INDIC,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_pad_bottom(swi_air_swi,LV_SWITCH_PART_INDIC,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_pad_left(swi_air_swi,LV_SWITCH_PART_INDIC,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_pad_right(swi_air_swi,LV_SWITCH_PART_INDIC,LV_STATE_DEFAULT,0);
    //set switch knob style
    lv_obj_set_style_local_radius(swi_air_swi,LV_SWITCH_PART_KNOB,LV_STATE_DEFAULT,LV_RADIUS_CIRCLE);
#ifdef BLOCKLY_swi_air_swi_EVENT_HANDLER
    lv_obj_set_event_cb(swi_air_swi, __qmsd_swi_air_swi_cb);
#endif
    qmsd_obj_set_id(swi_air_swi,"swi_air_swi");
}
    void qmsd_lab_air_text_create()
{
	lab_air_text = lv_label_create(screen_air, NULL);
	lv_label_set_long_mode(lab_air_text,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(lab_air_text,true);
	lv_obj_set_size(lab_air_text, 97, 23);
//set label style
	lv_obj_set_style_local_text_color(lab_air_text,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(lab_air_text, "当前温度");
	lv_label_set_align(lab_air_text, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(lab_air_text,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_24);
#ifdef BLOCKLY_lab_air_text_EVENT_HANDLER
	lv_obj_set_event_cb(lab_air_text, __qmsd_lab_air_text_cb);
#endif
	if(lab_air_text->coords.x2-lab_air_text->coords.x1<97)
	{
		int x_offset=(97-(lab_air_text->coords.x2-lab_air_text->coords.x1))/2;
		lv_obj_set_style_local_pad_left(lab_air_text,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(lab_air_text,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(lab_air_text->coords.y2-lab_air_text->coords.y1<23)
	{
		int y_offset=(23-(lab_air_text->coords.y2-lab_air_text->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(lab_air_text,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(lab_air_text,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(lab_air_text, 194, 122);
    qmsd_obj_set_id(lab_air_text,"lab_air_text");
}
    void qmsd_lab_air_tem_create()
{
	lab_air_tem = lv_label_create(screen_air, NULL);
	lv_label_set_long_mode(lab_air_tem,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(lab_air_tem,true);
	lv_obj_set_size(lab_air_tem, 98, 78);
//set label style
	lv_obj_set_style_local_text_color(lab_air_tem,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(lab_air_tem, "28");
	lv_label_set_align(lab_air_tem, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(lab_air_tem,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_107);
#ifdef BLOCKLY_lab_air_tem_EVENT_HANDLER
	lv_obj_set_event_cb(lab_air_tem, __qmsd_lab_air_tem_cb);
#endif
	if(lab_air_tem->coords.x2-lab_air_tem->coords.x1<98)
	{
		int x_offset=(98-(lab_air_tem->coords.x2-lab_air_tem->coords.x1))/2;
		lv_obj_set_style_local_pad_left(lab_air_tem,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(lab_air_tem,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(lab_air_tem->coords.y2-lab_air_tem->coords.y1<78)
	{
		int y_offset=(78-(lab_air_tem->coords.y2-lab_air_tem->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(lab_air_tem,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(lab_air_tem,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(lab_air_tem, 180, 190);
    qmsd_obj_set_id(lab_air_tem,"lab_air_tem");
}
    void qmsd_lab_air_tem__create()
{
	lab_air_tem_ = lv_label_create(screen_air, NULL);
	lv_label_set_long_mode(lab_air_tem_,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(lab_air_tem_,true);
	lv_obj_set_size(lab_air_tem_, 34, 34);
//set label style
	lv_obj_set_style_local_text_color(lab_air_tem_,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(lab_air_tem_, "℃");
	lv_label_set_align(lab_air_tem_, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(lab_air_tem_,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_40);
#ifdef BLOCKLY_lab_air_tem__EVENT_HANDLER
	lv_obj_set_event_cb(lab_air_tem_, __qmsd_lab_air_tem__cb);
#endif
	if(lab_air_tem_->coords.x2-lab_air_tem_->coords.x1<34)
	{
		int x_offset=(34-(lab_air_tem_->coords.x2-lab_air_tem_->coords.x1))/2;
		lv_obj_set_style_local_pad_left(lab_air_tem_,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(lab_air_tem_,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(lab_air_tem_->coords.y2-lab_air_tem_->coords.y1<34)
	{
		int y_offset=(34-(lab_air_tem_->coords.y2-lab_air_tem_->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(lab_air_tem_,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(lab_air_tem_,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(lab_air_tem_, 303, 234);
    qmsd_obj_set_id(lab_air_tem_,"lab_air_tem_");
}
    
void qmsd_ima_air_co_create()
{
    ima_air_co = lv_img_create(screen_air, NULL);
    lv_img_set_src(ima_air_co, &imgair_curditioner_cold_png);
#ifdef BLOCKLY_ima_air_co_EVENT_HANDLER
    lv_obj_set_event_cb(ima_air_co, __qmsd_ima_air_co_cb);
#endif
    lv_obj_set_pos(ima_air_co, 54, 384);
    lv_obj_set_click(ima_air_co,true);
    lv_obj_set_style_local_image_recolor(ima_air_co,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(ima_air_co,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    qmsd_obj_set_id(ima_air_co,"ima_air_co");
}
    
void qmsd_ima_air_sun_create()
{
    ima_air_sun = lv_img_create(screen_air, NULL);
    lv_img_set_src(ima_air_sun, &imgair_curditioner_sun_png);
#ifdef BLOCKLY_ima_air_sun_EVENT_HANDLER
    lv_obj_set_event_cb(ima_air_sun, __qmsd_ima_air_sun_cb);
#endif
    lv_obj_set_pos(ima_air_sun, 147, 384);
    lv_obj_set_click(ima_air_sun,true);
    lv_obj_set_style_local_image_recolor(ima_air_sun,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(ima_air_sun,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    qmsd_obj_set_id(ima_air_sun,"ima_air_sun");
}
    
void qmsd_ima_air_lo_create()
{
    ima_air_lo = lv_img_create(screen_air, NULL);
    lv_img_set_src(ima_air_lo, &imgair_curditioner_low_png);
#ifdef BLOCKLY_ima_air_lo_EVENT_HANDLER
    lv_obj_set_event_cb(ima_air_lo, __qmsd_ima_air_lo_cb);
#endif
    lv_obj_set_pos(ima_air_lo, 284, 384);
    lv_obj_set_click(ima_air_lo,true);
    lv_obj_set_style_local_image_recolor(ima_air_lo,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(ima_air_lo,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    qmsd_obj_set_id(ima_air_lo,"ima_air_lo");
}
    
void qmsd_ima_air_mi_create()
{
    ima_air_mi = lv_img_create(screen_air, NULL);
    lv_img_set_src(ima_air_mi, &imgair_curditioner_middle_png);
#ifdef BLOCKLY_ima_air_mi_EVENT_HANDLER
    lv_obj_set_event_cb(ima_air_mi, __qmsd_ima_air_mi_cb);
#endif
    lv_obj_set_pos(ima_air_mi, 346, 384);
    lv_obj_set_click(ima_air_mi,true);
    lv_obj_set_style_local_image_recolor(ima_air_mi,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(ima_air_mi,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    qmsd_obj_set_id(ima_air_mi,"ima_air_mi");
}
    
void qmsd_ima_air_hi_create()
{
    ima_air_hi = lv_img_create(screen_air, NULL);
    lv_img_set_src(ima_air_hi, &imgair_curditioner_high_png);
#ifdef BLOCKLY_ima_air_hi_EVENT_HANDLER
    lv_obj_set_event_cb(ima_air_hi, __qmsd_ima_air_hi_cb);
#endif
    lv_obj_set_pos(ima_air_hi, 408, 384);
    lv_obj_set_click(ima_air_hi,true);
    lv_obj_set_style_local_image_recolor(ima_air_hi,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(ima_air_hi,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    qmsd_obj_set_id(ima_air_hi,"ima_air_hi");
}
    void qmsd_lab_air_pat_create()
{
	lab_air_pat = lv_label_create(screen_air, NULL);
	lv_label_set_long_mode(lab_air_pat,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(lab_air_pat,true);
	lv_obj_set_size(lab_air_pat, 33, 15);
//set label style
	lv_obj_set_style_local_text_color(lab_air_pat,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(lab_air_pat, "模式");
	lv_label_set_align(lab_air_pat, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(lab_air_pat,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_16);
#ifdef BLOCKLY_lab_air_pat_EVENT_HANDLER
	lv_obj_set_event_cb(lab_air_pat, __qmsd_lab_air_pat_cb);
#endif
	if(lab_air_pat->coords.x2-lab_air_pat->coords.x1<33)
	{
		int x_offset=(33-(lab_air_pat->coords.x2-lab_air_pat->coords.x1))/2;
		lv_obj_set_style_local_pad_left(lab_air_pat,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(lab_air_pat,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(lab_air_pat->coords.y2-lab_air_pat->coords.y1<15)
	{
		int y_offset=(15-(lab_air_pat->coords.y2-lab_air_pat->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(lab_air_pat,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(lab_air_pat,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(lab_air_pat, 154, 441);
    qmsd_obj_set_id(lab_air_pat,"lab_air_pat");
}
    void qmsd_lab_air_pow_create()
{
	lab_air_pow = lv_label_create(screen_air, NULL);
	lv_label_set_long_mode(lab_air_pow,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(lab_air_pow,true);
	lv_obj_set_size(lab_air_pow, 33, 15);
//set label style
	lv_obj_set_style_local_text_color(lab_air_pow,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(lab_air_pow, "风力");
	lv_label_set_align(lab_air_pow, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(lab_air_pow,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_16);
#ifdef BLOCKLY_lab_air_pow_EVENT_HANDLER
	lv_obj_set_event_cb(lab_air_pow, __qmsd_lab_air_pow_cb);
#endif
	if(lab_air_pow->coords.x2-lab_air_pow->coords.x1<33)
	{
		int x_offset=(33-(lab_air_pow->coords.x2-lab_air_pow->coords.x1))/2;
		lv_obj_set_style_local_pad_left(lab_air_pow,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(lab_air_pow,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(lab_air_pow->coords.y2-lab_air_pow->coords.y1<15)
	{
		int y_offset=(15-(lab_air_pow->coords.y2-lab_air_pow->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(lab_air_pow,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(lab_air_pow,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(lab_air_pow, 292, 441);
    qmsd_obj_set_id(lab_air_pow,"lab_air_pow");
}
    
void qmsd_ima_air_4_create()
{
    ima_air_4 = lv_img_create(screen_air, NULL);
    lv_img_set_src(ima_air_4, &imgair_conditioner_off_png);
#ifdef BLOCKLY_ima_air_4_EVENT_HANDLER
    lv_obj_set_event_cb(ima_air_4, __qmsd_ima_air_4_cb);
#endif
    lv_obj_set_pos(ima_air_4, 128, 320);
    qmsd_obj_set_id(ima_air_4,"ima_air_4");
}
    
void qmsd_ima_air_5_create()
{
    ima_air_5 = lv_img_create(screen_air, NULL);
    lv_img_set_src(ima_air_5, &imgair_conditioner_off_png);
#ifdef BLOCKLY_ima_air_5_EVENT_HANDLER
    lv_obj_set_event_cb(ima_air_5, __qmsd_ima_air_5_cb);
#endif
    lv_obj_set_pos(ima_air_5, 144, 320);
    qmsd_obj_set_id(ima_air_5,"ima_air_5");
}
    
void qmsd_ima_air_6_create()
{
    ima_air_6 = lv_img_create(screen_air, NULL);
    lv_img_set_src(ima_air_6, &imgair_conditioner_off_png);
#ifdef BLOCKLY_ima_air_6_EVENT_HANDLER
    lv_obj_set_event_cb(ima_air_6, __qmsd_ima_air_6_cb);
#endif
    lv_obj_set_pos(ima_air_6, 160, 320);
    qmsd_obj_set_id(ima_air_6,"ima_air_6");
}
    
void qmsd_ima_air_7_create()
{
    ima_air_7 = lv_img_create(screen_air, NULL);
    lv_img_set_src(ima_air_7, &imgair_conditioner_off_png);
#ifdef BLOCKLY_ima_air_7_EVENT_HANDLER
    lv_obj_set_event_cb(ima_air_7, __qmsd_ima_air_7_cb);
#endif
    lv_obj_set_pos(ima_air_7, 176, 320);
    qmsd_obj_set_id(ima_air_7,"ima_air_7");
}
    
void qmsd_ima_air_8_create()
{
    ima_air_8 = lv_img_create(screen_air, NULL);
    lv_img_set_src(ima_air_8, &imgair_conditioner_off_png);
#ifdef BLOCKLY_ima_air_8_EVENT_HANDLER
    lv_obj_set_event_cb(ima_air_8, __qmsd_ima_air_8_cb);
#endif
    lv_obj_set_pos(ima_air_8, 192, 320);
    qmsd_obj_set_id(ima_air_8,"ima_air_8");
}
    
void qmsd_ima_air_9_create()
{
    ima_air_9 = lv_img_create(screen_air, NULL);
    lv_img_set_src(ima_air_9, &imgair_conditioner_off_png);
#ifdef BLOCKLY_ima_air_9_EVENT_HANDLER
    lv_obj_set_event_cb(ima_air_9, __qmsd_ima_air_9_cb);
#endif
    lv_obj_set_pos(ima_air_9, 208, 320);
    qmsd_obj_set_id(ima_air_9,"ima_air_9");
}
    
void qmsd_ima_air_10_create()
{
    ima_air_10 = lv_img_create(screen_air, NULL);
    lv_img_set_src(ima_air_10, &imgair_conditioner_off_png);
#ifdef BLOCKLY_ima_air_10_EVENT_HANDLER
    lv_obj_set_event_cb(ima_air_10, __qmsd_ima_air_10_cb);
#endif
    lv_obj_set_pos(ima_air_10, 224, 320);
    qmsd_obj_set_id(ima_air_10,"ima_air_10");
}
    
void qmsd_ima_air_11_create()
{
    ima_air_11 = lv_img_create(screen_air, NULL);
    lv_img_set_src(ima_air_11, &imgair_conditioner_off_png);
#ifdef BLOCKLY_ima_air_11_EVENT_HANDLER
    lv_obj_set_event_cb(ima_air_11, __qmsd_ima_air_11_cb);
#endif
    lv_obj_set_pos(ima_air_11, 240, 320);
    qmsd_obj_set_id(ima_air_11,"ima_air_11");
}
    
void qmsd_ima_air_12_create()
{
    ima_air_12 = lv_img_create(screen_air, NULL);
    lv_img_set_src(ima_air_12, &imgair_conditioner_off_png);
#ifdef BLOCKLY_ima_air_12_EVENT_HANDLER
    lv_obj_set_event_cb(ima_air_12, __qmsd_ima_air_12_cb);
#endif
    lv_obj_set_pos(ima_air_12, 256, 320);
    qmsd_obj_set_id(ima_air_12,"ima_air_12");
}
    
void qmsd_ima_air_13_create()
{
    ima_air_13 = lv_img_create(screen_air, NULL);
    lv_img_set_src(ima_air_13, &imgair_conditioner_off_png);
#ifdef BLOCKLY_ima_air_13_EVENT_HANDLER
    lv_obj_set_event_cb(ima_air_13, __qmsd_ima_air_13_cb);
#endif
    lv_obj_set_pos(ima_air_13, 272, 320);
    qmsd_obj_set_id(ima_air_13,"ima_air_13");
}
    
void qmsd_ima_air_14_create()
{
    ima_air_14 = lv_img_create(screen_air, NULL);
    lv_img_set_src(ima_air_14, &imgair_conditioner_off_png);
#ifdef BLOCKLY_ima_air_14_EVENT_HANDLER
    lv_obj_set_event_cb(ima_air_14, __qmsd_ima_air_14_cb);
#endif
    lv_obj_set_pos(ima_air_14, 288, 320);
    qmsd_obj_set_id(ima_air_14,"ima_air_14");
}
    
void qmsd_ima_air_15_create()
{
    ima_air_15 = lv_img_create(screen_air, NULL);
    lv_img_set_src(ima_air_15, &imgair_conditioner_off_png);
#ifdef BLOCKLY_ima_air_15_EVENT_HANDLER
    lv_obj_set_event_cb(ima_air_15, __qmsd_ima_air_15_cb);
#endif
    lv_obj_set_pos(ima_air_15, 304, 320);
    qmsd_obj_set_id(ima_air_15,"ima_air_15");
}
    
void qmsd_ima_air_16_create()
{
    ima_air_16 = lv_img_create(screen_air, NULL);
    lv_img_set_src(ima_air_16, &imgair_conditioner_off_png);
#ifdef BLOCKLY_ima_air_16_EVENT_HANDLER
    lv_obj_set_event_cb(ima_air_16, __qmsd_ima_air_16_cb);
#endif
    lv_obj_set_pos(ima_air_16, 320, 320);
    qmsd_obj_set_id(ima_air_16,"ima_air_16");
}
    
void qmsd_ima_air_17_create()
{
    ima_air_17 = lv_img_create(screen_air, NULL);
    lv_img_set_src(ima_air_17, &imgair_conditioner_off_png);
#ifdef BLOCKLY_ima_air_17_EVENT_HANDLER
    lv_obj_set_event_cb(ima_air_17, __qmsd_ima_air_17_cb);
#endif
    lv_obj_set_pos(ima_air_17, 336, 320);
    qmsd_obj_set_id(ima_air_17,"ima_air_17");
}
    
void qmsd_ima_air_18_create()
{
    ima_air_18 = lv_img_create(screen_air, NULL);
    lv_img_set_src(ima_air_18, &imgair_conditioner_off_png);
#ifdef BLOCKLY_ima_air_18_EVENT_HANDLER
    lv_obj_set_event_cb(ima_air_18, __qmsd_ima_air_18_cb);
#endif
    lv_obj_set_pos(ima_air_18, 352, 320);
    qmsd_obj_set_id(ima_air_18,"ima_air_18");
}
    
void qmsd_ima_air_sign_create()
{
    ima_air_sign = lv_img_create(screen_air, NULL);
    lv_img_set_src(ima_air_sign, &imgair_conditioner_sign_png);
#ifdef BLOCKLY_ima_air_sign_EVENT_HANDLER
    lv_obj_set_event_cb(ima_air_sign, __qmsd_ima_air_sign_cb);
#endif
    lv_obj_set_pos(ima_air_sign, 124, 305);
    qmsd_obj_set_id(ima_air_sign,"ima_air_sign");
}

static void screen_air_qmsd_cb(lv_obj_t * obj, lv_event_t event, void *data)
{/*
    char *trans;
    lv_label_set_text(lab_air_re,qmsd_lang_get_trans("lab_air_re","空调"));
    lv_label_set_text(lab_air_text,qmsd_lang_get_trans("lab_air_text","当前温度"));
    lv_label_set_text(lab_air_tem,qmsd_lang_get_trans("lab_air_tem","28"));
    lv_label_set_text(lab_air_tem_,qmsd_lang_get_trans("lab_air_tem_","℃"));
    lv_label_set_text(lab_air_pat,qmsd_lang_get_trans("lab_air_pat","模式"));
    lv_label_set_text(lab_air_pow,qmsd_lang_get_trans("lab_air_pow","风力"));
*/
#ifdef BLOCKLY_screen_air_SCREEN_INIT
    __qmsd_screen_air_init();
#endif
}

static void screen_air_del_cb(lv_obj_t* obj,lv_event_t event)
{
    if(event == LV_EVENT_DELETE)
    {
        screen_air=NULL;
        qmsd_screen_remove("screen_air");
    }
}

void screen_air_build(void)
{
    if(screen_air) return;
    screen_air = lv_obj_create(NULL, NULL);
    lv_obj_qmsd_set_cb(screen_air, screen_air_qmsd_cb);
    lv_obj_set_style_local_bg_color(screen_air,LV_OBJ_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x20, 0x20, 0x20));

    qmsd_ima_air_re_create();
    qmsd_lab_air_re_create();
    qmsd_swi_air_swi_create();
    qmsd_lab_air_text_create();
    qmsd_lab_air_tem_create();
    qmsd_lab_air_tem__create();
    qmsd_ima_air_co_create();
    qmsd_ima_air_sun_create();
    qmsd_ima_air_lo_create();
    qmsd_ima_air_mi_create();
    qmsd_ima_air_hi_create();
    qmsd_lab_air_pat_create();
    qmsd_lab_air_pow_create();
    qmsd_ima_air_4_create();
    qmsd_ima_air_5_create();
    qmsd_ima_air_6_create();
    qmsd_ima_air_7_create();
    qmsd_ima_air_8_create();
    qmsd_ima_air_9_create();
    qmsd_ima_air_10_create();
    qmsd_ima_air_11_create();
    qmsd_ima_air_12_create();
    qmsd_ima_air_13_create();
    qmsd_ima_air_14_create();
    qmsd_ima_air_15_create();
    qmsd_ima_air_16_create();
    qmsd_ima_air_17_create();
    qmsd_ima_air_18_create();
    qmsd_ima_air_sign_create();
    lv_obj_set_event_cb(screen_air,screen_air_del_cb);
    qmsd_screen_register(screen_air,"screen_air");
}

void screen_air_show(void)
{
    if(!screen_air)
    {
        screen_air_build();
    }
    lv_scr_load(screen_air);
}

void screen_air_delete(void)
{
    if(screen_air)
    {
        lv_obj_del(screen_air);
        screen_air = NULL;
    }
}
