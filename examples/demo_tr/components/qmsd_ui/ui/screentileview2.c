#include "qmsd_ui_entry.h"
#include "qmsd_internal_ui_cb.h"

lv_obj_t* screentileview2;
lv_obj_t* ima_tile2_lh;
lv_obj_t* ima_tile2_lh_;
lv_obj_t* lab_tile2_lh;
lv_obj_t* ima_tile2_gh;
lv_obj_t* ima_tile2_gh_;
lv_obj_t* lab_tile2_gh;
lv_obj_t* ima_tile2_li;
lv_obj_t* lab_tile2_li;
lv_obj_t* ima_tile2_li_;
lv_obj_t* swi_tile2_li;
lv_obj_t* ima_tile2_res;
lv_obj_t* lab_tile2_res;
lv_obj_t* ima_tile2_res_;
lv_obj_t* swi_tile2_res;
lv_obj_t* ima_tile2_cu;
lv_obj_t* lab_tile2_cu;
lv_obj_t* lab_tile2_cu_;
lv_obj_t* ima_tile2_cu_;
lv_obj_t* bar_tile2_bar;
lv_obj_t* ima_tile2_le;
lv_obj_t* ima_tile2_ri;
lv_obj_t* ima_tile2_ai;
lv_obj_t* swi_tile2_ai;
lv_obj_t* lab_tile2_ai;
lv_obj_t* lab_tile2_ai_;
lv_obj_t* but_tile2_pr;
lv_obj_t * __but_tile2_pr_label;
lv_obj_t* ima_tile2_pr;
lv_obj_t* but_tile2_ne;
lv_obj_t * __but_tile2_ne_label;
lv_obj_t* ima_tile2_ne;
lv_obj_t* lab_tile2_ai__;
lv_obj_t* lab_tile2_ai_c;
lv_obj_t* but_tile2_one;
lv_obj_t * __but_tile2_one_label;
lv_obj_t* but_tile2_two;
lv_obj_t * __but_tile2_two_label;
lv_obj_t* but_tile2_thr;
lv_obj_t * __but_tile2_thr_label;
lv_obj_t* but_tile2_fou;
lv_obj_t * __but_tile2_fou_label;
lv_obj_t* ima_tile2_one;
lv_obj_t* ima_tile2_two;
lv_obj_t* ima_tile2_thr;
lv_obj_t* ima_tile2_fou;
lv_obj_t* ima_tile2_stb;
lv_obj_t* ima_tile2_st;


    
void qmsd_ima_tile2_lh_create()
{
    ima_tile2_lh = lv_img_create(screentileview2, NULL);
    lv_img_set_src(ima_tile2_lh, &imgtileview2_leave_home_png);
#ifdef BLOCKLY_ima_tile2_lh_EVENT_HANDLER
    lv_obj_set_event_cb(ima_tile2_lh, __qmsd_ima_tile2_lh_cb);
#endif
    lv_obj_set_pos(ima_tile2_lh, 32, 42);
    qmsd_obj_set_id(ima_tile2_lh,"ima_tile2_lh");
}
    
void qmsd_ima_tile2_lh__create()
{
    ima_tile2_lh_ = lv_img_create(screentileview2, NULL);
    lv_img_set_src(ima_tile2_lh_, &imgtileview_leave_home_png);
#ifdef BLOCKLY_ima_tile2_lh__EVENT_HANDLER
    lv_obj_set_event_cb(ima_tile2_lh_, __qmsd_ima_tile2_lh__cb);
#endif
    lv_obj_set_pos(ima_tile2_lh_, 70, 70);
    qmsd_obj_set_id(ima_tile2_lh_,"ima_tile2_lh_");
}
    void qmsd_lab_tile2_lh_create()
{
	lab_tile2_lh = lv_label_create(screentileview2, NULL);
	lv_label_set_long_mode(lab_tile2_lh,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(lab_tile2_lh,true);
	lv_obj_set_size(lab_tile2_lh, 32, 16);
//set label style
	lv_obj_set_style_local_text_color(lab_tile2_lh,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(lab_tile2_lh, "离家");
	lv_label_set_align(lab_tile2_lh, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(lab_tile2_lh,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_16);
#ifdef BLOCKLY_lab_tile2_lh_EVENT_HANDLER
	lv_obj_set_event_cb(lab_tile2_lh, __qmsd_lab_tile2_lh_cb);
#endif
	if(lab_tile2_lh->coords.x2-lab_tile2_lh->coords.x1<32)
	{
		int x_offset=(32-(lab_tile2_lh->coords.x2-lab_tile2_lh->coords.x1))/2;
		lv_obj_set_style_local_pad_left(lab_tile2_lh,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(lab_tile2_lh,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(lab_tile2_lh->coords.y2-lab_tile2_lh->coords.y1<16)
	{
		int y_offset=(16-(lab_tile2_lh->coords.y2-lab_tile2_lh->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(lab_tile2_lh,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(lab_tile2_lh,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(lab_tile2_lh, 69, 113);
    qmsd_obj_set_id(lab_tile2_lh,"lab_tile2_lh");
}
    
void qmsd_ima_tile2_gh_create()
{
    ima_tile2_gh = lv_img_create(screentileview2, NULL);
    lv_img_set_src(ima_tile2_gh, &imgtileview2_go_home_png);
#ifdef BLOCKLY_ima_tile2_gh_EVENT_HANDLER
    lv_obj_set_event_cb(ima_tile2_gh, __qmsd_ima_tile2_gh_cb);
#endif
    lv_obj_set_pos(ima_tile2_gh, 148, 42);
    qmsd_obj_set_id(ima_tile2_gh,"ima_tile2_gh");
}
    
void qmsd_ima_tile2_gh__create()
{
    ima_tile2_gh_ = lv_img_create(screentileview2, NULL);
    lv_img_set_src(ima_tile2_gh_, &imgtileview_go_home_png);
#ifdef BLOCKLY_ima_tile2_gh__EVENT_HANDLER
    lv_obj_set_event_cb(ima_tile2_gh_, __qmsd_ima_tile2_gh__cb);
#endif
    lv_obj_set_pos(ima_tile2_gh_, 185, 70);
    qmsd_obj_set_id(ima_tile2_gh_,"ima_tile2_gh_");
}
    void qmsd_lab_tile2_gh_create()
{
	lab_tile2_gh = lv_label_create(screentileview2, NULL);
	lv_label_set_long_mode(lab_tile2_gh,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(lab_tile2_gh,true);
	lv_obj_set_size(lab_tile2_gh, 32, 16);
//set label style
	lv_obj_set_style_local_text_color(lab_tile2_gh,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(lab_tile2_gh, "回家");
	lv_label_set_align(lab_tile2_gh, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(lab_tile2_gh,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_16);
#ifdef BLOCKLY_lab_tile2_gh_EVENT_HANDLER
	lv_obj_set_event_cb(lab_tile2_gh, __qmsd_lab_tile2_gh_cb);
#endif
	if(lab_tile2_gh->coords.x2-lab_tile2_gh->coords.x1<32)
	{
		int x_offset=(32-(lab_tile2_gh->coords.x2-lab_tile2_gh->coords.x1))/2;
		lv_obj_set_style_local_pad_left(lab_tile2_gh,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(lab_tile2_gh,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(lab_tile2_gh->coords.y2-lab_tile2_gh->coords.y1<16)
	{
		int y_offset=(16-(lab_tile2_gh->coords.y2-lab_tile2_gh->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(lab_tile2_gh,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(lab_tile2_gh,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(lab_tile2_gh, 185, 113);
    qmsd_obj_set_id(lab_tile2_gh,"lab_tile2_gh");
}
    
void qmsd_ima_tile2_li_create()
{
    ima_tile2_li = lv_img_create(screentileview2, NULL);
    lv_img_set_src(ima_tile2_li, &imgtileview2_living_room_png);
#ifdef BLOCKLY_ima_tile2_li_EVENT_HANDLER
    lv_obj_set_event_cb(ima_tile2_li, __qmsd_ima_tile2_li_cb);
#endif
    lv_obj_set_pos(ima_tile2_li, 32, 166);
    qmsd_obj_set_id(ima_tile2_li,"ima_tile2_li");
}
    void qmsd_lab_tile2_li_create()
{
	lab_tile2_li = lv_label_create(screentileview2, NULL);
	lv_label_set_long_mode(lab_tile2_li,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(lab_tile2_li,true);
	lv_obj_set_size(lab_tile2_li, 52, 17);
//set label style
	lv_obj_set_style_local_text_color(lab_tile2_li,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(lab_tile2_li, "客厅灯");
	lv_label_set_align(lab_tile2_li, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(lab_tile2_li,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_17);
#ifdef BLOCKLY_lab_tile2_li_EVENT_HANDLER
	lv_obj_set_event_cb(lab_tile2_li, __qmsd_lab_tile2_li_cb);
#endif
	if(lab_tile2_li->coords.x2-lab_tile2_li->coords.x1<52)
	{
		int x_offset=(52-(lab_tile2_li->coords.x2-lab_tile2_li->coords.x1))/2;
		lv_obj_set_style_local_pad_left(lab_tile2_li,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(lab_tile2_li,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(lab_tile2_li->coords.y2-lab_tile2_li->coords.y1<17)
	{
		int y_offset=(17-(lab_tile2_li->coords.y2-lab_tile2_li->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(lab_tile2_li,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(lab_tile2_li,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	// lv_obj_set_pos(lab_tile2_li, 59, 186);
    lv_obj_set_pos(lab_tile2_li, 62, 186);
    qmsd_obj_set_id(lab_tile2_li,"lab_tile2_li");
}
    
void qmsd_ima_tile2_li__create()
{
    ima_tile2_li_ = lv_img_create(screentileview2, NULL);
    lv_img_set_src(ima_tile2_li_, &imgtileview2_living_room_light_png);
#ifdef BLOCKLY_ima_tile2_li__EVENT_HANDLER
    lv_obj_set_event_cb(ima_tile2_li_, __qmsd_ima_tile2_li__cb);
#endif
    lv_obj_set_pos(ima_tile2_li_, 198, 180);
    qmsd_obj_set_id(ima_tile2_li_,"ima_tile2_li_");
}
    void qmsd_swi_tile2_li_create()
{
    swi_tile2_li = lv_switch_create(screentileview2, NULL);
    lv_obj_set_size(swi_tile2_li, 40, 21);
    lv_obj_set_pos(swi_tile2_li, 63, 245);
    if(0 == 0) {
    lv_switch_off(swi_tile2_li, LV_ANIM_OFF);
    } else {
    lv_switch_on(swi_tile2_li, LV_ANIM_OFF);
    }
    //set switch bg style
    lv_obj_set_style_local_bg_color(swi_tile2_li,LV_SWITCH_PART_BG,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xCC, 0xCC, 0xCC));
    lv_obj_set_style_local_bg_grad_color(swi_tile2_li,LV_SWITCH_PART_BG,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xCC, 0xCC, 0xCC));
    lv_obj_set_style_local_pad_top(swi_tile2_li,LV_SWITCH_PART_BG,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_pad_bottom(swi_tile2_li,LV_SWITCH_PART_BG,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_pad_left(swi_tile2_li,LV_SWITCH_PART_BG,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_pad_right(swi_tile2_li,LV_SWITCH_PART_BG,LV_STATE_DEFAULT,0);
    //set switch indic style
    lv_obj_set_style_local_bg_color(swi_tile2_li,LV_SWITCH_PART_INDIC,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x4a, 0x90, 0xe2));
    lv_obj_set_style_local_bg_grad_color(swi_tile2_li,LV_SWITCH_PART_INDIC,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x4a, 0x90, 0xe2));
    lv_obj_set_style_local_radius(swi_tile2_li,LV_SWITCH_PART_INDIC,LV_STATE_DEFAULT,LV_RADIUS_CIRCLE);
    lv_obj_set_style_local_pad_top(swi_tile2_li,LV_SWITCH_PART_INDIC,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_pad_bottom(swi_tile2_li,LV_SWITCH_PART_INDIC,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_pad_left(swi_tile2_li,LV_SWITCH_PART_INDIC,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_pad_right(swi_tile2_li,LV_SWITCH_PART_INDIC,LV_STATE_DEFAULT,0);
    //set switch knob style
    lv_obj_set_style_local_radius(swi_tile2_li,LV_SWITCH_PART_KNOB,LV_STATE_DEFAULT,LV_RADIUS_CIRCLE);
#ifdef BLOCKLY_swi_tile2_li_EVENT_HANDLER
    lv_obj_set_event_cb(swi_tile2_li, __qmsd_swi_tile2_li_cb);
#endif
    qmsd_obj_set_id(swi_tile2_li,"swi_tile2_li");

    lv_obj_set_ext_click_area(swi_tile2_li, 20, 20, 20, 20);
}
    
void qmsd_ima_tile2_res_create()
{
    ima_tile2_res = lv_img_create(screentileview2, NULL);
    lv_img_set_src(ima_tile2_res, &imgtileview2_restaurant_png);
#ifdef BLOCKLY_ima_tile2_res_EVENT_HANDLER
    lv_obj_set_event_cb(ima_tile2_res, __qmsd_ima_tile2_res_cb);
#endif
    lv_obj_set_pos(ima_tile2_res, 32, 304);
    // lv_obj_set_click(ima_tile2_res,true);
    lv_obj_set_click(ima_tile2_res,false);
    lv_obj_set_style_local_image_recolor(ima_tile2_res,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(ima_tile2_res,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    qmsd_obj_set_id(ima_tile2_res,"ima_tile2_res");
}
    void qmsd_lab_tile2_res_create()
{
	lab_tile2_res = lv_label_create(screentileview2, NULL);
	lv_label_set_long_mode(lab_tile2_res,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(lab_tile2_res,true);
	lv_obj_set_size(lab_tile2_res, 52, 17);
//set label style
	lv_obj_set_style_local_text_color(lab_tile2_res,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(lab_tile2_res, "餐厅灯");
	lv_label_set_align(lab_tile2_res, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(lab_tile2_res,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_17);
#ifdef BLOCKLY_lab_tile2_res_EVENT_HANDLER
	lv_obj_set_event_cb(lab_tile2_res, __qmsd_lab_tile2_res_cb);
#endif
	if(lab_tile2_res->coords.x2-lab_tile2_res->coords.x1<52)
	{
		int x_offset=(52-(lab_tile2_res->coords.x2-lab_tile2_res->coords.x1))/2;
		lv_obj_set_style_local_pad_left(lab_tile2_res,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(lab_tile2_res,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(lab_tile2_res->coords.y2-lab_tile2_res->coords.y1<17)
	{
		int y_offset=(17-(lab_tile2_res->coords.y2-lab_tile2_res->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(lab_tile2_res,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(lab_tile2_res,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	// lv_obj_set_pos(lab_tile2_res, 59, 328);
    lv_obj_set_pos(lab_tile2_res, 62, 322);
    qmsd_obj_set_id(lab_tile2_res,"lab_tile2_res");
}
    
void qmsd_ima_tile2_res__create()
{
    ima_tile2_res_ = lv_img_create(screentileview2, NULL);
    lv_img_set_src(ima_tile2_res_, &imgtileview2_living_room_light_png);
#ifdef BLOCKLY_ima_tile2_res__EVENT_HANDLER
    lv_obj_set_event_cb(ima_tile2_res_, __qmsd_ima_tile2_res__cb);
#endif
    lv_obj_set_pos(ima_tile2_res_, 198, 320);
    qmsd_obj_set_id(ima_tile2_res_,"ima_tile2_res_");
}
    void qmsd_swi_tile2_res_create()
{
    swi_tile2_res = lv_switch_create(screentileview2, NULL);
    lv_obj_set_size(swi_tile2_res, 40, 21);
    lv_obj_set_pos(swi_tile2_res, 63, 385);
    if(0 == 0) {
    lv_switch_off(swi_tile2_res, LV_ANIM_OFF);
    } else {
    lv_switch_on(swi_tile2_res, LV_ANIM_OFF);
    }
    //set switch bg style
    lv_obj_set_style_local_bg_color(swi_tile2_res,LV_SWITCH_PART_BG,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xCC, 0xCC, 0xCC));
    lv_obj_set_style_local_bg_grad_color(swi_tile2_res,LV_SWITCH_PART_BG,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xCC, 0xCC, 0xCC));
    lv_obj_set_style_local_pad_top(swi_tile2_res,LV_SWITCH_PART_BG,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_pad_bottom(swi_tile2_res,LV_SWITCH_PART_BG,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_pad_left(swi_tile2_res,LV_SWITCH_PART_BG,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_pad_right(swi_tile2_res,LV_SWITCH_PART_BG,LV_STATE_DEFAULT,0);
    //set switch indic style
    lv_obj_set_style_local_bg_color(swi_tile2_res,LV_SWITCH_PART_INDIC,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x4a, 0x90, 0xe2));
    lv_obj_set_style_local_bg_grad_color(swi_tile2_res,LV_SWITCH_PART_INDIC,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x4a, 0x90, 0xe2));
    lv_obj_set_style_local_radius(swi_tile2_res,LV_SWITCH_PART_INDIC,LV_STATE_DEFAULT,LV_RADIUS_CIRCLE);
    lv_obj_set_style_local_pad_top(swi_tile2_res,LV_SWITCH_PART_INDIC,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_pad_bottom(swi_tile2_res,LV_SWITCH_PART_INDIC,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_pad_left(swi_tile2_res,LV_SWITCH_PART_INDIC,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_pad_right(swi_tile2_res,LV_SWITCH_PART_INDIC,LV_STATE_DEFAULT,0);
    //set switch knob style
    lv_obj_set_style_local_radius(swi_tile2_res,LV_SWITCH_PART_KNOB,LV_STATE_DEFAULT,LV_RADIUS_CIRCLE);
#ifdef BLOCKLY_swi_tile2_res_EVENT_HANDLER
    lv_obj_set_event_cb(swi_tile2_res, __qmsd_swi_tile2_res_cb);
#endif
    qmsd_obj_set_id(swi_tile2_res,"swi_tile2_res");

    lv_obj_set_ext_click_area(swi_tile2_res, 20, 20, 20, 20);
}
    
void qmsd_ima_tile2_cu_create()
{
    ima_tile2_cu = lv_img_create(screentileview2, NULL);
    lv_img_set_src(ima_tile2_cu, &imgtileview2_curtain0_png);
#ifdef BLOCKLY_ima_tile2_cu_EVENT_HANDLER
    lv_obj_set_event_cb(ima_tile2_cu, __qmsd_ima_tile2_cu_cb);
#endif
    lv_obj_set_pos(ima_tile2_cu, 273, 42);
    qmsd_obj_set_id(ima_tile2_cu,"ima_tile2_cu");
}
    void qmsd_lab_tile2_cu_create()
{
	lab_tile2_cu = lv_label_create(screentileview2, NULL);
	lv_label_set_long_mode(lab_tile2_cu,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(lab_tile2_cu,true);
	lv_obj_set_size(lab_tile2_cu, 34, 17);
//set label style
	lv_obj_set_style_local_text_color(lab_tile2_cu,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(lab_tile2_cu, "窗帘");
	lv_label_set_align(lab_tile2_cu, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(lab_tile2_cu,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_17);
#ifdef BLOCKLY_lab_tile2_cu_EVENT_HANDLER
	lv_obj_set_event_cb(lab_tile2_cu, __qmsd_lab_tile2_cu_cb);
#endif
	if(lab_tile2_cu->coords.x2-lab_tile2_cu->coords.x1<34)
	{
		int x_offset=(34-(lab_tile2_cu->coords.x2-lab_tile2_cu->coords.x1))/2;
		lv_obj_set_style_local_pad_left(lab_tile2_cu,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(lab_tile2_cu,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(lab_tile2_cu->coords.y2-lab_tile2_cu->coords.y1<17)
	{
		int y_offset=(17-(lab_tile2_cu->coords.y2-lab_tile2_cu->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(lab_tile2_cu,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(lab_tile2_cu,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(lab_tile2_cu, 297, 64);
    qmsd_obj_set_id(lab_tile2_cu,"lab_tile2_cu");
}
    void qmsd_lab_tile2_cu__create()
{
	lab_tile2_cu_ = lv_label_create(screentileview2, NULL);
	lv_label_set_long_mode(lab_tile2_cu_,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(lab_tile2_cu_,true);
	lv_obj_set_size(lab_tile2_cu_, 60, 10);
//set label style
	lv_obj_set_style_local_text_color(lab_tile2_cu_,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(lab_tile2_cu_, "窗帘已打开");
	lv_label_set_align(lab_tile2_cu_, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(lab_tile2_cu_,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_11);
#ifdef BLOCKLY_lab_tile2_cu__EVENT_HANDLER
	lv_obj_set_event_cb(lab_tile2_cu_, __qmsd_lab_tile2_cu__cb);
#endif
	if(lab_tile2_cu_->coords.x2-lab_tile2_cu_->coords.x1<60)
	{
		int x_offset=(60-(lab_tile2_cu_->coords.x2-lab_tile2_cu_->coords.x1))/2;
		lv_obj_set_style_local_pad_left(lab_tile2_cu_,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(lab_tile2_cu_,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(lab_tile2_cu_->coords.y2-lab_tile2_cu_->coords.y1<10)
	{
		int y_offset=(10-(lab_tile2_cu_->coords.y2-lab_tile2_cu_->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(lab_tile2_cu_,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(lab_tile2_cu_,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(lab_tile2_cu_, 296, 87);
    qmsd_obj_set_id(lab_tile2_cu_,"lab_tile2_cu_");
}
    
void qmsd_ima_tile2_cu__create()
{
    ima_tile2_cu_ = lv_img_create(screentileview2, NULL);
    lv_img_set_src(ima_tile2_cu_, &imgtileview2_curtain_1_png);
#ifdef BLOCKLY_ima_tile2_cu__EVENT_HANDLER
    lv_obj_set_event_cb(ima_tile2_cu_, __qmsd_ima_tile2_cu__cb);
#endif
    lv_obj_set_pos(ima_tile2_cu_, 400, 63);
    qmsd_obj_set_id(ima_tile2_cu_,"ima_tile2_cu_");
}
    void qmsd_bar_tile2_bar_create()
{
	bar_tile2_bar = lv_bar_create(screentileview2, NULL);
	lv_obj_set_size(bar_tile2_bar, 129, 28);
    lv_obj_set_pos(bar_tile2_bar, 295, 109);
	lv_bar_set_anim_time(bar_tile2_bar, 1000);
	lv_bar_set_value(bar_tile2_bar, 0, LV_ANIM_ON);

/*Create a bar, an indicator and a knob style*/
	//set main part style
    lv_obj_set_style_local_bg_color(bar_tile2_bar,LV_BAR_PART_BG,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xCC, 0xCC, 0xCC));
	lv_obj_set_style_local_bg_grad_color(bar_tile2_bar,LV_BAR_PART_BG,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xCC, 0xCC, 0xCC));
    lv_obj_set_style_local_pad_top(bar_tile2_bar,LV_BAR_PART_BG,LV_STATE_DEFAULT,0);
	lv_obj_set_style_local_pad_bottom(bar_tile2_bar,LV_BAR_PART_BG,LV_STATE_DEFAULT,0);
	lv_obj_set_style_local_pad_left(bar_tile2_bar,LV_BAR_PART_BG,LV_STATE_DEFAULT,0);
	lv_obj_set_style_local_pad_right(bar_tile2_bar,LV_BAR_PART_BG,LV_STATE_DEFAULT,0);
	//set indic style
    lv_obj_set_style_local_bg_color(bar_tile2_bar, LV_BAR_PART_INDIC,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x2c, 0x43, 0xac));
	lv_obj_set_style_local_bg_grad_color(bar_tile2_bar, LV_BAR_PART_INDIC,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x2c, 0x43, 0xac));
    lv_obj_set_style_local_radius(bar_tile2_bar, LV_BAR_PART_INDIC,LV_STATE_DEFAULT,LV_RADIUS_CIRCLE);
    lv_obj_set_style_local_pad_top(bar_tile2_bar, LV_BAR_PART_INDIC,LV_STATE_DEFAULT,0);
	lv_obj_set_style_local_pad_bottom(bar_tile2_bar, LV_BAR_PART_INDIC,LV_STATE_DEFAULT,0);
	lv_obj_set_style_local_pad_left(bar_tile2_bar, LV_BAR_PART_INDIC,LV_STATE_DEFAULT,0);
	lv_obj_set_style_local_pad_right(bar_tile2_bar, LV_BAR_PART_INDIC,LV_STATE_DEFAULT,0);
    qmsd_obj_set_id(bar_tile2_bar,"bar_tile2_bar");
}
    
void qmsd_ima_tile2_le_create()
{
    ima_tile2_le = lv_img_create(screentileview2, NULL);
    lv_img_set_src(ima_tile2_le, &imgtileview2_left_png);
#ifdef BLOCKLY_ima_tile2_le_EVENT_HANDLER
    lv_obj_set_event_cb(ima_tile2_le, __qmsd_ima_tile2_le_cb);
#endif
    lv_obj_set_pos(ima_tile2_le, 304, 160);
    qmsd_obj_set_id(ima_tile2_le,"ima_tile2_le");
}
    
void qmsd_ima_tile2_ri_create()
{
    ima_tile2_ri = lv_img_create(screentileview2, NULL);
    lv_img_set_src(ima_tile2_ri, &imgtileview2_right_png);
#ifdef BLOCKLY_ima_tile2_ri_EVENT_HANDLER
    lv_obj_set_event_cb(ima_tile2_ri, __qmsd_ima_tile2_ri_cb);
#endif
    lv_obj_set_pos(ima_tile2_ri, 399, 160);
    qmsd_obj_set_id(ima_tile2_ri,"ima_tile2_ri");
}
    
void qmsd_ima_tile2_ai_create()
{
    ima_tile2_ai = lv_img_create(screentileview2, NULL);
    lv_img_set_src(ima_tile2_ai, &imgtileview2_air_conditioner_bottom_png);
#ifdef BLOCKLY_ima_tile2_ai_EVENT_HANDLER
    lv_obj_set_event_cb(ima_tile2_ai, __qmsd_ima_tile2_ai_cb);
#endif
    lv_obj_set_pos(ima_tile2_ai, 273, 214);
    qmsd_obj_set_id(ima_tile2_ai,"ima_tile2_ai");
}
    void qmsd_swi_tile2_ai_create()
{
    swi_tile2_ai = lv_switch_create(screentileview2, NULL);
    lv_obj_set_size(swi_tile2_ai, 40, 21);
    lv_obj_set_pos(swi_tile2_ai, 394, 236);
    if(0 == 0) {
    lv_switch_off(swi_tile2_ai, LV_ANIM_OFF);
    } else {
    lv_switch_on(swi_tile2_ai, LV_ANIM_OFF);
    }
    //set switch bg style
    lv_obj_set_style_local_bg_color(swi_tile2_ai,LV_SWITCH_PART_BG,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xCC, 0xCC, 0xCC));
    lv_obj_set_style_local_bg_grad_color(swi_tile2_ai,LV_SWITCH_PART_BG,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xCC, 0xCC, 0xCC));
    lv_obj_set_style_local_pad_top(swi_tile2_ai,LV_SWITCH_PART_BG,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_pad_bottom(swi_tile2_ai,LV_SWITCH_PART_BG,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_pad_left(swi_tile2_ai,LV_SWITCH_PART_BG,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_pad_right(swi_tile2_ai,LV_SWITCH_PART_BG,LV_STATE_DEFAULT,0);
    //set switch indic style
    lv_obj_set_style_local_bg_color(swi_tile2_ai,LV_SWITCH_PART_INDIC,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x4a, 0x90, 0xe2));
    lv_obj_set_style_local_bg_grad_color(swi_tile2_ai,LV_SWITCH_PART_INDIC,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x4a, 0x90, 0xe2));
    lv_obj_set_style_local_radius(swi_tile2_ai,LV_SWITCH_PART_INDIC,LV_STATE_DEFAULT,LV_RADIUS_CIRCLE);
    lv_obj_set_style_local_pad_top(swi_tile2_ai,LV_SWITCH_PART_INDIC,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_pad_bottom(swi_tile2_ai,LV_SWITCH_PART_INDIC,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_pad_left(swi_tile2_ai,LV_SWITCH_PART_INDIC,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_pad_right(swi_tile2_ai,LV_SWITCH_PART_INDIC,LV_STATE_DEFAULT,0);
    //set switch knob style
    lv_obj_set_style_local_radius(swi_tile2_ai,LV_SWITCH_PART_KNOB,LV_STATE_DEFAULT,LV_RADIUS_CIRCLE);
#ifdef BLOCKLY_swi_tile2_ai_EVENT_HANDLER
    lv_obj_set_event_cb(swi_tile2_ai, __qmsd_swi_tile2_ai_cb);
#endif
    qmsd_obj_set_id(swi_tile2_ai,"swi_tile2_ai");

    lv_obj_set_ext_click_area(swi_tile2_ai, 20, 20, 20, 20);
}
    void qmsd_lab_tile2_ai_create()
{
	lab_tile2_ai = lv_label_create(screentileview2, NULL);
	lv_label_set_long_mode(lab_tile2_ai,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(lab_tile2_ai,true);
	lv_obj_set_size(lab_tile2_ai, 34, 17);
//set label style
	lv_obj_set_style_local_text_color(lab_tile2_ai,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(lab_tile2_ai, "空调");
	lv_label_set_align(lab_tile2_ai, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(lab_tile2_ai,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_17);
#ifdef BLOCKLY_lab_tile2_ai_EVENT_HANDLER
	lv_obj_set_event_cb(lab_tile2_ai, __qmsd_lab_tile2_ai_cb);
#endif
	if(lab_tile2_ai->coords.x2-lab_tile2_ai->coords.x1<34)
	{
		int x_offset=(34-(lab_tile2_ai->coords.x2-lab_tile2_ai->coords.x1))/2;
		lv_obj_set_style_local_pad_left(lab_tile2_ai,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(lab_tile2_ai,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(lab_tile2_ai->coords.y2-lab_tile2_ai->coords.y1<17)
	{
		int y_offset=(17-(lab_tile2_ai->coords.y2-lab_tile2_ai->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(lab_tile2_ai,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(lab_tile2_ai,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(lab_tile2_ai, 297, 238);
    qmsd_obj_set_id(lab_tile2_ai,"lab_tile2_ai");
}
    void qmsd_lab_tile2_ai__create()
{
	lab_tile2_ai_ = lv_label_create(screentileview2, NULL);
	lv_label_set_long_mode(lab_tile2_ai_,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(lab_tile2_ai_,true);
	lv_obj_set_size(lab_tile2_ai_, 48, 10);
//set label style
	lv_obj_set_style_local_text_color(lab_tile2_ai_,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(lab_tile2_ai_, "正在运行");
	lv_label_set_align(lab_tile2_ai_, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(lab_tile2_ai_,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_11);
#ifdef BLOCKLY_lab_tile2_ai__EVENT_HANDLER
	lv_obj_set_event_cb(lab_tile2_ai_, __qmsd_lab_tile2_ai__cb);
#endif
	if(lab_tile2_ai_->coords.x2-lab_tile2_ai_->coords.x1<48)
	{
		int x_offset=(48-(lab_tile2_ai_->coords.x2-lab_tile2_ai_->coords.x1))/2;
		lv_obj_set_style_local_pad_left(lab_tile2_ai_,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(lab_tile2_ai_,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(lab_tile2_ai_->coords.y2-lab_tile2_ai_->coords.y1<10)
	{
		int y_offset=(10-(lab_tile2_ai_->coords.y2-lab_tile2_ai_->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(lab_tile2_ai_,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(lab_tile2_ai_,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(lab_tile2_ai_, 298, 260);
    qmsd_obj_set_id(lab_tile2_ai_,"lab_tile2_ai_");
}
    void qmsd_but_tile2_pr_create()
{
    but_tile2_pr = lv_btn_create(screentileview2, NULL);
    __but_tile2_pr_label = lv_label_create(but_tile2_pr, NULL);
    lv_label_set_text(__but_tile2_pr_label,qmsd_lang_get_trans("but_tile2_pr",""));

    lv_obj_set_style_local_text_font(__but_tile2_pr_label,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_16);
    lv_obj_set_size(but_tile2_pr, 34, 34);
    lv_obj_set_pos(but_tile2_pr, 289, 298);
#ifdef BLOCKLY_but_tile2_pr_EVENT_HANDLER
    lv_obj_set_event_cb(but_tile2_pr, __qmsd_but_tile2_pr_cb);
#endif


    lv_obj_t* obj = but_tile2_pr;
    int part = LV_BTN_PART_MAIN;
//设置正常样式
        lv_obj_set_style_local_bg_color(obj,part,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x00, 0x00, 0x00));
    lv_obj_set_style_local_bg_grad_color(obj,part,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x00, 0x00, 0x00));
    lv_obj_set_style_local_radius(obj,part,LV_STATE_DEFAULT,5);
    lv_obj_set_style_local_bg_opa(obj,part,LV_STATE_DEFAULT,100);
    lv_obj_set_style_local_border_color(obj,part,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
    lv_obj_set_style_local_border_opa(obj,part,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_shadow_width(obj,part,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_text_opa(obj,part,LV_STATE_DEFAULT,0);

//设置正常样式结束

//设置按下样式
        lv_obj_set_style_local_bg_color(obj,part,LV_STATE_PRESSED,LV_COLOR_MAKE(0x00, 0x00, 0x00));
    lv_obj_set_style_local_bg_grad_color(obj,part,LV_STATE_PRESSED,LV_COLOR_MAKE(0x00, 0x00, 0x00));
    lv_obj_set_style_local_radius(obj,part,LV_STATE_PRESSED,5);
    lv_obj_set_style_local_bg_opa(obj,part,LV_STATE_PRESSED,204);
    lv_obj_set_style_local_border_color(obj,part,LV_STATE_PRESSED,LV_COLOR_MAKE(0xff, 0xff, 0xff));
    lv_obj_set_style_local_border_opa(obj,part,LV_STATE_PRESSED,0);
    lv_obj_set_style_local_shadow_width(obj,part,LV_STATE_PRESSED,0);
    lv_obj_set_style_local_text_opa(obj,part,LV_STATE_PRESSED,0);

//设置按下样式结束

//设置禁用样式
        lv_obj_set_style_local_border_color(obj,part,LV_STATE_DISABLED,LV_COLOR_MAKE(0xff, 0xff, 0xff));

//设置禁用样式结束
    lv_obj_set_style_local_outline_width(but_tile2_pr,LV_BTN_PART_MAIN,LV_STATE_DEFAULT,0);
	lv_obj_set_style_local_outline_width(but_tile2_pr,LV_BTN_PART_MAIN,LV_STATE_FOCUSED,0);
    qmsd_obj_set_id(but_tile2_pr,"but_tile2_pr");
}
    
void qmsd_ima_tile2_pr_create()
{
    ima_tile2_pr = lv_img_create(screentileview2, NULL);
    lv_img_set_src(ima_tile2_pr, &imgtilevwe2_prev_button_png);
#ifdef BLOCKLY_ima_tile2_pr_EVENT_HANDLER
    lv_obj_set_event_cb(ima_tile2_pr, __qmsd_ima_tile2_pr_cb);
#endif
    lv_obj_set_pos(ima_tile2_pr, 299, 306);
    qmsd_obj_set_id(ima_tile2_pr,"ima_tile2_pr");
}
    void qmsd_but_tile2_ne_create()
{
    but_tile2_ne = lv_btn_create(screentileview2, NULL);
    __but_tile2_ne_label = lv_label_create(but_tile2_ne, NULL);
    lv_label_set_text(__but_tile2_ne_label,qmsd_lang_get_trans("but_tile2_ne",""));

    lv_obj_set_style_local_text_font(__but_tile2_ne_label,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_16);
    lv_obj_set_size(but_tile2_ne, 34, 34);
    lv_obj_set_pos(but_tile2_ne, 399, 298);
#ifdef BLOCKLY_but_tile2_ne_EVENT_HANDLER
    lv_obj_set_event_cb(but_tile2_ne, __qmsd_but_tile2_ne_cb);
#endif


    lv_obj_t* obj = but_tile2_ne;
    int part = LV_BTN_PART_MAIN;
//设置正常样式
        lv_obj_set_style_local_bg_color(obj,part,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x00, 0x00, 0x00));
    lv_obj_set_style_local_bg_grad_color(obj,part,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x00, 0x00, 0x00));
    lv_obj_set_style_local_radius(obj,part,LV_STATE_DEFAULT,5);
    lv_obj_set_style_local_bg_opa(obj,part,LV_STATE_DEFAULT,100);
    lv_obj_set_style_local_border_color(obj,part,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
    lv_obj_set_style_local_border_opa(obj,part,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_shadow_width(obj,part,LV_STATE_DEFAULT,0);

//设置正常样式结束

//设置按下样式
        lv_obj_set_style_local_bg_color(obj,part,LV_STATE_PRESSED,LV_COLOR_MAKE(0x00, 0x00, 0x00));
    lv_obj_set_style_local_bg_grad_color(obj,part,LV_STATE_PRESSED,LV_COLOR_MAKE(0x00, 0x00, 0x00));
    lv_obj_set_style_local_radius(obj,part,LV_STATE_PRESSED,5);
    lv_obj_set_style_local_bg_opa(obj,part,LV_STATE_PRESSED,204);
    lv_obj_set_style_local_border_color(obj,part,LV_STATE_PRESSED,LV_COLOR_MAKE(0xff, 0xff, 0xff));
    lv_obj_set_style_local_border_opa(obj,part,LV_STATE_PRESSED,0);
    lv_obj_set_style_local_shadow_width(obj,part,LV_STATE_PRESSED,0);
    lv_obj_set_style_local_text_opa(obj,part,LV_STATE_PRESSED,0);

//设置按下样式结束

//设置禁用样式
        lv_obj_set_style_local_border_color(obj,part,LV_STATE_DISABLED,LV_COLOR_MAKE(0xff, 0xff, 0xff));

//设置禁用样式结束
    lv_obj_set_style_local_outline_width(but_tile2_ne,LV_BTN_PART_MAIN,LV_STATE_DEFAULT,0);
	lv_obj_set_style_local_outline_width(but_tile2_ne,LV_BTN_PART_MAIN,LV_STATE_FOCUSED,0);
    qmsd_obj_set_id(but_tile2_ne,"but_tile2_ne");
}
    
void qmsd_ima_tile2_ne_create()
{
    ima_tile2_ne = lv_img_create(screentileview2, NULL);
    lv_img_set_src(ima_tile2_ne, &imgtileview2_next_png);
#ifdef BLOCKLY_ima_tile2_ne_EVENT_HANDLER
    lv_obj_set_event_cb(ima_tile2_ne, __qmsd_ima_tile2_ne_cb);
#endif
    lv_obj_set_pos(ima_tile2_ne, 411, 306);
    qmsd_obj_set_id(ima_tile2_ne,"ima_tile2_ne");
}
    void qmsd_lab_tile2_ai___create()
{
	lab_tile2_ai__ = lv_label_create(screentileview2, NULL);
	lv_label_set_long_mode(lab_tile2_ai__,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(lab_tile2_ai__,true);
	lv_obj_set_size(lab_tile2_ai__, 34, 25);
//set label style
	lv_obj_set_style_local_text_color(lab_tile2_ai__,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(lab_tile2_ai__, "26");
	lv_label_set_align(lab_tile2_ai__, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(lab_tile2_ai__,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_35);
#ifdef BLOCKLY_lab_tile2_ai___EVENT_HANDLER
	lv_obj_set_event_cb(lab_tile2_ai__, __qmsd_lab_tile2_ai___cb);
#endif
	if(lab_tile2_ai__->coords.x2-lab_tile2_ai__->coords.x1<34)
	{
		int x_offset=(34-(lab_tile2_ai__->coords.x2-lab_tile2_ai__->coords.x1))/2;
		lv_obj_set_style_local_pad_left(lab_tile2_ai__,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(lab_tile2_ai__,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(lab_tile2_ai__->coords.y2-lab_tile2_ai__->coords.y1<25)
	{
		int y_offset=(25-(lab_tile2_ai__->coords.y2-lab_tile2_ai__->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(lab_tile2_ai__,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(lab_tile2_ai__,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(lab_tile2_ai__, 339, 301);
    qmsd_obj_set_id(lab_tile2_ai__,"lab_tile2_ai__");
}
    void qmsd_lab_tile2_ai_c_create()
{
	lab_tile2_ai_c = lv_label_create(screentileview2, NULL);
	lv_label_set_long_mode(lab_tile2_ai_c,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(lab_tile2_ai_c,true);
	lv_obj_set_size(lab_tile2_ai_c, 10, 8);
//set label style
	lv_obj_set_style_local_text_color(lab_tile2_ai_c,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(lab_tile2_ai_c, "℃");
	lv_label_set_align(lab_tile2_ai_c, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(lab_tile2_ai_c,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_16);
#ifdef BLOCKLY_lab_tile2_ai_c_EVENT_HANDLER
	lv_obj_set_event_cb(lab_tile2_ai_c, __qmsd_lab_tile2_ai_c_cb);
#endif
	if(lab_tile2_ai_c->coords.x2-lab_tile2_ai_c->coords.x1<10)
	{
		int x_offset=(10-(lab_tile2_ai_c->coords.x2-lab_tile2_ai_c->coords.x1))/2;
		lv_obj_set_style_local_pad_left(lab_tile2_ai_c,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(lab_tile2_ai_c,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(lab_tile2_ai_c->coords.y2-lab_tile2_ai_c->coords.y1<8)
	{
		int y_offset=(8-(lab_tile2_ai_c->coords.y2-lab_tile2_ai_c->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(lab_tile2_ai_c,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(lab_tile2_ai_c,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(lab_tile2_ai_c, 378, 301);
    qmsd_obj_set_id(lab_tile2_ai_c,"lab_tile2_ai_c");
}
    void qmsd_but_tile2_one_create()
{
    but_tile2_one = lv_btn_create(screentileview2, NULL);
    __but_tile2_one_label = lv_label_create(but_tile2_one, NULL);
    lv_label_set_text(__but_tile2_one_label,qmsd_lang_get_trans("but_tile2_one",""));

    lv_obj_set_style_local_text_font(__but_tile2_one_label,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_16);
    lv_obj_set_size(but_tile2_one, 34, 34);
    lv_obj_set_pos(but_tile2_one, 286, 371);
#ifdef BLOCKLY_but_tile2_one_EVENT_HANDLER
    lv_obj_set_event_cb(but_tile2_one, __qmsd_but_tile2_one_cb);
#endif


    lv_obj_t* obj = but_tile2_one;
    int part = LV_BTN_PART_MAIN;
//设置正常样式
        lv_obj_set_style_local_radius(obj,part,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_bg_opa(obj,part,LV_STATE_DEFAULT,25);
    lv_obj_set_style_local_border_color(obj,part,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
    lv_obj_set_style_local_border_opa(obj,part,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_shadow_width(obj,part,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_text_opa(obj,part,LV_STATE_DEFAULT,0);

//设置正常样式结束

//设置按下样式
        lv_obj_set_style_local_bg_color(obj,part,LV_STATE_PRESSED,LV_COLOR_MAKE(0x7e, 0xd3, 0x21));
    lv_obj_set_style_local_bg_grad_color(obj,part,LV_STATE_PRESSED,LV_COLOR_MAKE(0x7e, 0xd3, 0x21));
    lv_obj_set_style_local_radius(obj,part,LV_STATE_PRESSED,0);
    lv_obj_set_style_local_bg_opa(obj,part,LV_STATE_PRESSED,204);
    lv_obj_set_style_local_border_color(obj,part,LV_STATE_PRESSED,LV_COLOR_MAKE(0xff, 0xff, 0xff));
    lv_obj_set_style_local_border_opa(obj,part,LV_STATE_PRESSED,0);
    lv_obj_set_style_local_shadow_width(obj,part,LV_STATE_PRESSED,0);
    lv_obj_set_style_local_text_opa(obj,part,LV_STATE_PRESSED,0);

//设置按下样式结束

//设置禁用样式
        lv_obj_set_style_local_border_color(obj,part,LV_STATE_DISABLED,LV_COLOR_MAKE(0xff, 0xff, 0xff));

//设置禁用样式结束
    lv_obj_set_style_local_outline_width(but_tile2_one,LV_BTN_PART_MAIN,LV_STATE_DEFAULT,0);
	lv_obj_set_style_local_outline_width(but_tile2_one,LV_BTN_PART_MAIN,LV_STATE_FOCUSED,0);
    qmsd_obj_set_id(but_tile2_one,"but_tile2_one");
}
    void qmsd_but_tile2_two_create()
{
    but_tile2_two = lv_btn_create(screentileview2, NULL);
    __but_tile2_two_label = lv_label_create(but_tile2_two, NULL);
    lv_label_set_text(__but_tile2_two_label,qmsd_lang_get_trans("but_tile2_two",""));

    lv_obj_set_style_local_text_font(__but_tile2_two_label,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_16);
    lv_obj_set_size(but_tile2_two, 34, 34);
    lv_obj_set_pos(but_tile2_two, 324, 371);
#ifdef BLOCKLY_but_tile2_two_EVENT_HANDLER
    lv_obj_set_event_cb(but_tile2_two, __qmsd_but_tile2_two_cb);
#endif


    lv_obj_t* obj = but_tile2_two;
    int part = LV_BTN_PART_MAIN;
//设置正常样式
        lv_obj_set_style_local_radius(obj,part,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_bg_opa(obj,part,LV_STATE_DEFAULT,25);
    lv_obj_set_style_local_border_color(obj,part,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
    lv_obj_set_style_local_border_opa(obj,part,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_shadow_width(obj,part,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_text_opa(obj,part,LV_STATE_DEFAULT,0);

//设置正常样式结束

//设置按下样式
        lv_obj_set_style_local_bg_color(obj,part,LV_STATE_PRESSED,LV_COLOR_MAKE(0x7e, 0xd3, 0x21));
    lv_obj_set_style_local_bg_grad_color(obj,part,LV_STATE_PRESSED,LV_COLOR_MAKE(0x7e, 0xd3, 0x21));
    lv_obj_set_style_local_radius(obj,part,LV_STATE_PRESSED,0);
    lv_obj_set_style_local_bg_opa(obj,part,LV_STATE_PRESSED,204);
    lv_obj_set_style_local_border_color(obj,part,LV_STATE_PRESSED,LV_COLOR_MAKE(0xff, 0xff, 0xff));
    lv_obj_set_style_local_border_opa(obj,part,LV_STATE_PRESSED,0);
    lv_obj_set_style_local_shadow_width(obj,part,LV_STATE_PRESSED,0);
    lv_obj_set_style_local_text_opa(obj,part,LV_STATE_PRESSED,0);

//设置按下样式结束

//设置禁用样式
        lv_obj_set_style_local_border_color(obj,part,LV_STATE_DISABLED,LV_COLOR_MAKE(0xff, 0xff, 0xff));

//设置禁用样式结束
    lv_obj_set_style_local_outline_width(but_tile2_two,LV_BTN_PART_MAIN,LV_STATE_DEFAULT,0);
	lv_obj_set_style_local_outline_width(but_tile2_two,LV_BTN_PART_MAIN,LV_STATE_FOCUSED,0);
    qmsd_obj_set_id(but_tile2_two,"but_tile2_two");
}
    void qmsd_but_tile2_thr_create()
{
    but_tile2_thr = lv_btn_create(screentileview2, NULL);
    __but_tile2_thr_label = lv_label_create(but_tile2_thr, NULL);
    lv_label_set_text(__but_tile2_thr_label,qmsd_lang_get_trans("but_tile2_thr",""));

    lv_obj_set_style_local_text_font(__but_tile2_thr_label,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_16);
    lv_obj_set_size(but_tile2_thr, 34, 34);
    lv_obj_set_pos(but_tile2_thr, 362, 371);
#ifdef BLOCKLY_but_tile2_thr_EVENT_HANDLER
    lv_obj_set_event_cb(but_tile2_thr, __qmsd_but_tile2_thr_cb);
#endif


    lv_obj_t* obj = but_tile2_thr;
    int part = LV_BTN_PART_MAIN;
//设置正常样式
        lv_obj_set_style_local_radius(obj,part,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_bg_opa(obj,part,LV_STATE_DEFAULT,25);
    lv_obj_set_style_local_border_color(obj,part,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
    lv_obj_set_style_local_border_opa(obj,part,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_shadow_width(obj,part,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_text_opa(obj,part,LV_STATE_DEFAULT,0);

//设置正常样式结束

//设置按下样式
        lv_obj_set_style_local_bg_color(obj,part,LV_STATE_PRESSED,LV_COLOR_MAKE(0x7e, 0xd3, 0x21));
    lv_obj_set_style_local_bg_grad_color(obj,part,LV_STATE_PRESSED,LV_COLOR_MAKE(0x7e, 0xd3, 0x21));
    lv_obj_set_style_local_radius(obj,part,LV_STATE_PRESSED,0);
    lv_obj_set_style_local_bg_opa(obj,part,LV_STATE_PRESSED,204);
    lv_obj_set_style_local_border_color(obj,part,LV_STATE_PRESSED,LV_COLOR_MAKE(0xff, 0xff, 0xff));
    lv_obj_set_style_local_border_opa(obj,part,LV_STATE_PRESSED,0);
    lv_obj_set_style_local_shadow_width(obj,part,LV_STATE_PRESSED,0);
    lv_obj_set_style_local_text_opa(obj,part,LV_STATE_PRESSED,0);

//设置按下样式结束

//设置禁用样式
        lv_obj_set_style_local_border_color(obj,part,LV_STATE_DISABLED,LV_COLOR_MAKE(0xff, 0xff, 0xff));

//设置禁用样式结束
    lv_obj_set_style_local_outline_width(but_tile2_thr,LV_BTN_PART_MAIN,LV_STATE_DEFAULT,0);
	lv_obj_set_style_local_outline_width(but_tile2_thr,LV_BTN_PART_MAIN,LV_STATE_FOCUSED,0);
    qmsd_obj_set_id(but_tile2_thr,"but_tile2_thr");
}
    void qmsd_but_tile2_fou_create()
{
    but_tile2_fou = lv_btn_create(screentileview2, NULL);
    __but_tile2_fou_label = lv_label_create(but_tile2_fou, NULL);
    lv_label_set_text(__but_tile2_fou_label,qmsd_lang_get_trans("but_tile2_fou",""));

    lv_obj_set_style_local_text_font(__but_tile2_fou_label,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_16);
    lv_obj_set_size(but_tile2_fou, 34, 34);
    lv_obj_set_pos(but_tile2_fou, 400, 371);
#ifdef BLOCKLY_but_tile2_fou_EVENT_HANDLER
    lv_obj_set_event_cb(but_tile2_fou, __qmsd_but_tile2_fou_cb);
#endif


    lv_obj_t* obj = but_tile2_fou;
    int part = LV_BTN_PART_MAIN;
//设置正常样式
        lv_obj_set_style_local_radius(obj,part,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_bg_opa(obj,part,LV_STATE_DEFAULT,25);
    lv_obj_set_style_local_border_color(obj,part,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
    lv_obj_set_style_local_border_opa(obj,part,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_shadow_width(obj,part,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_text_opa(obj,part,LV_STATE_DEFAULT,0);

//设置正常样式结束

//设置按下样式
        lv_obj_set_style_local_bg_color(obj,part,LV_STATE_PRESSED,LV_COLOR_MAKE(0x7e, 0xd3, 0x21));
    lv_obj_set_style_local_bg_grad_color(obj,part,LV_STATE_PRESSED,LV_COLOR_MAKE(0x7e, 0xd3, 0x21));
    lv_obj_set_style_local_radius(obj,part,LV_STATE_PRESSED,0);
    lv_obj_set_style_local_bg_opa(obj,part,LV_STATE_PRESSED,204);
    lv_obj_set_style_local_border_color(obj,part,LV_STATE_PRESSED,LV_COLOR_MAKE(0xff, 0xff, 0xff));
    lv_obj_set_style_local_border_opa(obj,part,LV_STATE_PRESSED,0);
    lv_obj_set_style_local_shadow_width(obj,part,LV_STATE_PRESSED,0);
    lv_obj_set_style_local_text_opa(obj,part,LV_STATE_PRESSED,0);

//设置按下样式结束

//设置禁用样式
        lv_obj_set_style_local_border_color(obj,part,LV_STATE_DISABLED,LV_COLOR_MAKE(0xff, 0xff, 0xff));

//设置禁用样式结束
    lv_obj_set_style_local_outline_width(but_tile2_fou,LV_BTN_PART_MAIN,LV_STATE_DEFAULT,0);
	lv_obj_set_style_local_outline_width(but_tile2_fou,LV_BTN_PART_MAIN,LV_STATE_FOCUSED,0);
    qmsd_obj_set_id(but_tile2_fou,"but_tile2_fou");
}
    
void qmsd_ima_tile2_one_create()
{
    ima_tile2_one = lv_img_create(screentileview2, NULL);
    lv_img_set_src(ima_tile2_one, &imgtileview2_button_one_png);
#ifdef BLOCKLY_ima_tile2_one_EVENT_HANDLER
    lv_obj_set_event_cb(ima_tile2_one, __qmsd_ima_tile2_one_cb);
#endif
    lv_obj_set_pos(ima_tile2_one, 293, 376);
    qmsd_obj_set_id(ima_tile2_one,"ima_tile2_one");
}
    
void qmsd_ima_tile2_two_create()
{
    ima_tile2_two = lv_img_create(screentileview2, NULL);
    lv_img_set_src(ima_tile2_two, &imgtileview2_button_two_png);
#ifdef BLOCKLY_ima_tile2_two_EVENT_HANDLER
    lv_obj_set_event_cb(ima_tile2_two, __qmsd_ima_tile2_two_cb);
#endif
    lv_obj_set_pos(ima_tile2_two, 334, 376);
    qmsd_obj_set_id(ima_tile2_two,"ima_tile2_two");
}
    
void qmsd_ima_tile2_thr_create()
{
    ima_tile2_thr = lv_img_create(screentileview2, NULL);
    lv_img_set_src(ima_tile2_thr, &imgtileview_button_three_png);
#ifdef BLOCKLY_ima_tile2_thr_EVENT_HANDLER
    lv_obj_set_event_cb(ima_tile2_thr, __qmsd_ima_tile2_thr_cb);
#endif
    lv_obj_set_pos(ima_tile2_thr, 370, 378);
    qmsd_obj_set_id(ima_tile2_thr,"ima_tile2_thr");
}
    
void qmsd_ima_tile2_fou_create()
{
    ima_tile2_fou = lv_img_create(screentileview2, NULL);
    lv_img_set_src(ima_tile2_fou, &imgtileview_button_four_png);
#ifdef BLOCKLY_ima_tile2_fou_EVENT_HANDLER
    lv_obj_set_event_cb(ima_tile2_fou, __qmsd_ima_tile2_fou_cb);
#endif
    lv_obj_set_pos(ima_tile2_fou, 408, 378);
    qmsd_obj_set_id(ima_tile2_fou,"ima_tile2_fou");
}
    
void qmsd_ima_tile2_stb_create()
{
    ima_tile2_stb = lv_img_create(screentileview2, NULL);
    lv_img_set_src(ima_tile2_stb, &imgtileview2_stop_bottom_png);
#ifdef BLOCKLY_ima_tile2_stb_EVENT_HANDLER
    lv_obj_set_event_cb(ima_tile2_stb, __qmsd_ima_tile2_stb_cb);
#endif
    lv_obj_set_pos(ima_tile2_stb, 342, 148);
    qmsd_obj_set_id(ima_tile2_stb,"ima_tile2_stb");
}
    
void qmsd_ima_tile2_st_create()
{
    ima_tile2_st = lv_img_create(screentileview2, NULL);
    lv_img_set_src(ima_tile2_st, &imgtileview2_stop_stop_png);
#ifdef BLOCKLY_ima_tile2_st_EVENT_HANDLER
    lv_obj_set_event_cb(ima_tile2_st, __qmsd_ima_tile2_st_cb);
#endif
    lv_obj_set_pos(ima_tile2_st, 354, 161);
    qmsd_obj_set_id(ima_tile2_st,"ima_tile2_st");
}

static void screentileview2_qmsd_cb(lv_obj_t * obj, lv_event_t event, void *data)
{/*
    char *trans;
    lv_label_set_text(lab_tile2_lh,qmsd_lang_get_trans("lab_tile2_lh","离家"));
    lv_label_set_text(lab_tile2_gh,qmsd_lang_get_trans("lab_tile2_gh","回家"));
    lv_label_set_text(lab_tile2_li,qmsd_lang_get_trans("lab_tile2_li","客厅灯"));
    lv_label_set_text(lab_tile2_res,qmsd_lang_get_trans("lab_tile2_res","餐厅灯"));
    lv_label_set_text(lab_tile2_cu,qmsd_lang_get_trans("lab_tile2_cu","窗帘"));
    lv_label_set_text(lab_tile2_cu_,qmsd_lang_get_trans("lab_tile2_cu_","窗帘已打开"));
    lv_label_set_text(lab_tile2_ai,qmsd_lang_get_trans("lab_tile2_ai","空调"));
    lv_label_set_text(lab_tile2_ai_,qmsd_lang_get_trans("lab_tile2_ai_","正在运行"));
    lv_label_set_text(__but_tile2_pr_label,qmsd_lang_get_trans("but_tile2_pr",""));
    lv_label_set_text(__but_tile2_ne_label,qmsd_lang_get_trans("but_tile2_ne",""));
    lv_label_set_text(lab_tile2_ai__,qmsd_lang_get_trans("lab_tile2_ai__","26"));
    lv_label_set_text(lab_tile2_ai_c,qmsd_lang_get_trans("lab_tile2_ai_c","℃"));
    lv_label_set_text(__but_tile2_one_label,qmsd_lang_get_trans("but_tile2_one",""));
    lv_label_set_text(__but_tile2_two_label,qmsd_lang_get_trans("but_tile2_two",""));
    lv_label_set_text(__but_tile2_thr_label,qmsd_lang_get_trans("but_tile2_thr",""));
    lv_label_set_text(__but_tile2_fou_label,qmsd_lang_get_trans("but_tile2_fou",""));
*/
#ifdef BLOCKLY_screentileview2_SCREEN_INIT
    __qmsd_screentileview2_init();
#endif
}

void screentileview2_tileview_cb(lv_obj_t* obj,lv_event_t event)
{
    if(event == LV_EVENT_DELETE)
    {
        screentileview2 = NULL;
        qmsd_screen_remove("screentileview2");
    }
}

void screentileview2_build(void)
{
    if(screentileview2) return;
    screentileview2 = lv_obj_create(tile_main,NULL);
    lv_obj_qmsd_set_cb(screentileview2, screentileview2_qmsd_cb);
    lv_obj_set_size(screentileview2,480,480);
    lv_obj_set_pos(screentileview2,1*LV_HOR_RES,0*LV_VER_RES);
    lv_obj_set_event_cb(screentileview2,screentileview2_tileview_cb);
    lv_obj_set_style_local_bg_color(screentileview2,LV_OBJ_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x20, 0x20, 0x20));
    lv_obj_set_style_local_border_width(screentileview2,LV_OBJ_PART_MAIN,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_radius(screentileview2,LV_OBJ_PART_MAIN,LV_STATE_DEFAULT,0);
    qmsd_ima_tile2_lh_create();
    lv_tileview_add_element(tile_main, ima_tile2_lh);
    qmsd_ima_tile2_lh__create();
    lv_tileview_add_element(tile_main, ima_tile2_lh_);
    qmsd_lab_tile2_lh_create();
    lv_tileview_add_element(tile_main, lab_tile2_lh);
    qmsd_ima_tile2_gh_create();
    lv_tileview_add_element(tile_main, ima_tile2_gh);
    qmsd_ima_tile2_gh__create();
    lv_tileview_add_element(tile_main, ima_tile2_gh_);
    qmsd_lab_tile2_gh_create();
    lv_tileview_add_element(tile_main, lab_tile2_gh);
    qmsd_ima_tile2_li_create();
    lv_tileview_add_element(tile_main, ima_tile2_li);
    qmsd_lab_tile2_li_create();
    lv_tileview_add_element(tile_main, lab_tile2_li);
    qmsd_ima_tile2_li__create();
    lv_tileview_add_element(tile_main, ima_tile2_li_);
    qmsd_swi_tile2_li_create();
    lv_tileview_add_element(tile_main, swi_tile2_li);
    qmsd_ima_tile2_res_create();
    lv_tileview_add_element(tile_main, ima_tile2_res);
    qmsd_lab_tile2_res_create();
    lv_tileview_add_element(tile_main, lab_tile2_res);
    qmsd_ima_tile2_res__create();
    lv_tileview_add_element(tile_main, ima_tile2_res_);
    qmsd_swi_tile2_res_create();
    lv_tileview_add_element(tile_main, swi_tile2_res);
    qmsd_ima_tile2_cu_create();
    lv_tileview_add_element(tile_main, ima_tile2_cu);
    qmsd_lab_tile2_cu_create();
    lv_tileview_add_element(tile_main, lab_tile2_cu);
    qmsd_lab_tile2_cu__create();
    lv_tileview_add_element(tile_main, lab_tile2_cu_);
    qmsd_ima_tile2_cu__create();
    lv_tileview_add_element(tile_main, ima_tile2_cu_);
    qmsd_bar_tile2_bar_create();
    lv_tileview_add_element(tile_main, bar_tile2_bar);
    qmsd_ima_tile2_le_create();
    lv_tileview_add_element(tile_main, ima_tile2_le);
    qmsd_ima_tile2_ri_create();
    lv_tileview_add_element(tile_main, ima_tile2_ri);
    qmsd_ima_tile2_ai_create();
    lv_tileview_add_element(tile_main, ima_tile2_ai);
    qmsd_swi_tile2_ai_create();
    lv_tileview_add_element(tile_main, swi_tile2_ai);
    qmsd_lab_tile2_ai_create();
    lv_tileview_add_element(tile_main, lab_tile2_ai);
    qmsd_lab_tile2_ai__create();
    lv_tileview_add_element(tile_main, lab_tile2_ai_);
    qmsd_but_tile2_pr_create();
    lv_tileview_add_element(tile_main, but_tile2_pr);
    qmsd_ima_tile2_pr_create();
    lv_tileview_add_element(tile_main, ima_tile2_pr);
    qmsd_but_tile2_ne_create();
    lv_tileview_add_element(tile_main, but_tile2_ne);
    qmsd_ima_tile2_ne_create();
    lv_tileview_add_element(tile_main, ima_tile2_ne);
    qmsd_lab_tile2_ai___create();
    lv_tileview_add_element(tile_main, lab_tile2_ai__);
    qmsd_lab_tile2_ai_c_create();
    lv_tileview_add_element(tile_main, lab_tile2_ai_c);
    qmsd_but_tile2_one_create();
    lv_tileview_add_element(tile_main, but_tile2_one);
    qmsd_but_tile2_two_create();
    lv_tileview_add_element(tile_main, but_tile2_two);
    qmsd_but_tile2_thr_create();
    lv_tileview_add_element(tile_main, but_tile2_thr);
    qmsd_but_tile2_fou_create();
    lv_tileview_add_element(tile_main, but_tile2_fou);
    qmsd_ima_tile2_one_create();
    lv_tileview_add_element(tile_main, ima_tile2_one);
    qmsd_ima_tile2_two_create();
    lv_tileview_add_element(tile_main, ima_tile2_two);
    qmsd_ima_tile2_thr_create();
    lv_tileview_add_element(tile_main, ima_tile2_thr);
    qmsd_ima_tile2_fou_create();
    lv_tileview_add_element(tile_main, ima_tile2_fou);
    qmsd_ima_tile2_stb_create();
    lv_tileview_add_element(tile_main, ima_tile2_stb);
    qmsd_ima_tile2_st_create();
    lv_tileview_add_element(tile_main, ima_tile2_st);
    lv_tileview_add_element(tile_main, screentileview2);
    qmsd_screen_register(screentileview2,"screentileview2");
}

void screentileview2_show(void)
{
    lv_tileview_set_tile_act(tile_main,1,0,LV_ANIM_ON);
}


void screentileview2_delete(void)
{

}
