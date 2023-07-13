#include "qmsd_ui_entry.h"
#include "qmsd_internal_ui_cb.h"

lv_obj_t* screen_choice;
lv_obj_t* ima_cho_re;
lv_obj_t* lab_cho_re;
lv_obj_t* ima_cho_gh;
lv_obj_t* ima_cho_lh;
lv_obj_t* ima_cho_gb;
lv_obj_t* ima_cho_sl;
lv_obj_t* ima_cho_me;
lv_obj_t* ima_cho_fi;
lv_obj_t* ima_cho_gh_;
lv_obj_t* lab_cho_gh;
lv_obj_t* ima_cho_lh_;
lv_obj_t* lab_cho_lh;
lv_obj_t* ima_cho_gb_;
lv_obj_t* lab_cho_gb;
lv_obj_t* ima_cho_sl_;
lv_obj_t* lab_cho_sl;
lv_obj_t* ima_cho_me_;
lv_obj_t* lab_cho_me;
lv_obj_t* ima_cho_fi_;
lv_obj_t* lab_cho_fi;


    
void qmsd_ima_cho_re_create()
{
    ima_cho_re = lv_img_create(screen_choice, NULL);
    lv_img_set_src(ima_cho_re, &imgchoice_return_png);
#ifdef BLOCKLY_ima_cho_re_EVENT_HANDLER
    lv_obj_set_event_cb(ima_cho_re, __qmsd_ima_cho_re_cb);
#endif
    lv_obj_set_pos(ima_cho_re, 44, 42);
    lv_obj_set_click(ima_cho_re,true);
    lv_obj_set_style_local_image_recolor(ima_cho_re,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(ima_cho_re,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    qmsd_obj_set_id(ima_cho_re,"ima_cho_re");
}
    void qmsd_lab_cho_re_create()
{
	lab_cho_re = lv_label_create(screen_choice, NULL);
	lv_label_set_long_mode(lab_cho_re,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(lab_cho_re,true);
	lv_obj_set_size(lab_cho_re, 98, 23);
//set label style
	lv_obj_set_style_local_text_color(lab_cho_re,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(lab_cho_re, "选择模式");
	lv_label_set_align(lab_cho_re, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(lab_cho_re,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_24);
#ifdef BLOCKLY_lab_cho_re_EVENT_HANDLER
	lv_obj_set_event_cb(lab_cho_re, __qmsd_lab_cho_re_cb);
#endif
    lv_obj_set_click(lab_cho_re,true);    
	if(lab_cho_re->coords.x2-lab_cho_re->coords.x1<98)
	{
		int x_offset=(98-(lab_cho_re->coords.x2-lab_cho_re->coords.x1))/2;
		lv_obj_set_style_local_pad_left(lab_cho_re,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(lab_cho_re,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(lab_cho_re->coords.y2-lab_cho_re->coords.y1<23)
	{
		int y_offset=(23-(lab_cho_re->coords.y2-lab_cho_re->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(lab_cho_re,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(lab_cho_re,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(lab_cho_re, 76, 42);
    qmsd_obj_set_id(lab_cho_re,"lab_cho_re");
}
    
void qmsd_ima_cho_gh_create()
{
    ima_cho_gh = lv_img_create(screen_choice, NULL);
    lv_img_set_src(ima_cho_gh, &imgchoice_go_home_png);
#ifdef BLOCKLY_ima_cho_gh_EVENT_HANDLER
    lv_obj_set_event_cb(ima_cho_gh, __qmsd_ima_cho_gh_cb);
#endif
    lv_obj_set_pos(ima_cho_gh, 35, 94);
    lv_obj_set_click(ima_cho_gh,true);
    lv_obj_set_style_local_image_recolor(ima_cho_gh,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(ima_cho_gh,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    qmsd_obj_set_id(ima_cho_gh,"ima_cho_gh");
}
    
void qmsd_ima_cho_lh_create()
{
    ima_cho_lh = lv_img_create(screen_choice, NULL);
    lv_img_set_src(ima_cho_lh, &imgchoice_leave_home_png);
#ifdef BLOCKLY_ima_cho_lh_EVENT_HANDLER
    lv_obj_set_event_cb(ima_cho_lh, __qmsd_ima_cho_lh_cb);
#endif
    lv_obj_set_pos(ima_cho_lh, 181, 94);
    lv_obj_set_click(ima_cho_lh,true);
    lv_obj_set_style_local_image_recolor(ima_cho_lh,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(ima_cho_lh,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    qmsd_obj_set_id(ima_cho_lh,"ima_cho_lh");
}
    
void qmsd_ima_cho_gb_create()
{
    ima_cho_gb = lv_img_create(screen_choice, NULL);
    lv_img_set_src(ima_cho_gb, &imgchoice_go_bed_png);
#ifdef BLOCKLY_ima_cho_gb_EVENT_HANDLER
    lv_obj_set_event_cb(ima_cho_gb, __qmsd_ima_cho_gb_cb);
#endif
    lv_obj_set_pos(ima_cho_gb, 330, 94);
    lv_obj_set_click(ima_cho_gb,true);
    lv_obj_set_style_local_image_recolor(ima_cho_gb,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(ima_cho_gb,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    qmsd_obj_set_id(ima_cho_gb,"ima_cho_gb");
}
    
void qmsd_ima_cho_sl_create()
{
    ima_cho_sl = lv_img_create(screen_choice, NULL);
    lv_img_set_src(ima_cho_sl, &imgchoice_sleep_png);
#ifdef BLOCKLY_ima_cho_sl_EVENT_HANDLER
    lv_obj_set_event_cb(ima_cho_sl, __qmsd_ima_cho_sl_cb);
#endif
    lv_obj_set_pos(ima_cho_sl, 34, 283);
    lv_obj_set_click(ima_cho_sl,true);
    lv_obj_set_style_local_image_recolor(ima_cho_sl,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(ima_cho_sl,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    qmsd_obj_set_id(ima_cho_sl,"ima_cho_sl");
}
    
void qmsd_ima_cho_me_create()
{
    ima_cho_me = lv_img_create(screen_choice, NULL);
    lv_img_set_src(ima_cho_me, &imgchoice_meet_png);
#ifdef BLOCKLY_ima_cho_me_EVENT_HANDLER
    lv_obj_set_event_cb(ima_cho_me, __qmsd_ima_cho_me_cb);
#endif
    lv_obj_set_pos(ima_cho_me, 182, 283);
    lv_obj_set_click(ima_cho_me,true);
    lv_obj_set_style_local_image_recolor(ima_cho_me,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(ima_cho_me,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    qmsd_obj_set_id(ima_cho_me,"ima_cho_me");
}
    
void qmsd_ima_cho_fi_create()
{
    ima_cho_fi = lv_img_create(screen_choice, NULL);
    lv_img_set_src(ima_cho_fi, &imgchoice_fime_png);
#ifdef BLOCKLY_ima_cho_fi_EVENT_HANDLER
    lv_obj_set_event_cb(ima_cho_fi, __qmsd_ima_cho_fi_cb);
#endif
    lv_obj_set_pos(ima_cho_fi, 330, 283);
    lv_obj_set_click(ima_cho_fi,true);
    lv_obj_set_style_local_image_recolor(ima_cho_fi,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(ima_cho_fi,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    qmsd_obj_set_id(ima_cho_fi,"ima_cho_fi");
}
    
void qmsd_ima_cho_gh__create()
{
    ima_cho_gh_ = lv_img_create(screen_choice, NULL);
    lv_img_set_src(ima_cho_gh_, &imgtileview_go_home_png);
#ifdef BLOCKLY_ima_cho_gh__EVENT_HANDLER
    lv_obj_set_event_cb(ima_cho_gh_, __qmsd_ima_cho_gh__cb);
#endif
    lv_obj_set_pos(ima_cho_gh_, 80, 154);
    lv_obj_set_click(ima_cho_gh_,true);
    lv_obj_set_style_local_image_recolor(ima_cho_gh_,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(ima_cho_gh_,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    qmsd_obj_set_id(ima_cho_gh_,"ima_cho_gh_");
}
    void qmsd_lab_cho_gh_create()
{
	lab_cho_gh = lv_label_create(screen_choice, NULL);
	lv_label_set_long_mode(lab_cho_gh,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(lab_cho_gh,true);
	lv_obj_set_size(lab_cho_gh, 37, 18);
//set label style
	lv_obj_set_style_local_text_color(lab_cho_gh,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(lab_cho_gh, "回家");
	lv_label_set_align(lab_cho_gh, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(lab_cho_gh,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_18);
#ifdef BLOCKLY_lab_cho_gh_EVENT_HANDLER
	lv_obj_set_event_cb(lab_cho_gh, __qmsd_lab_cho_gh_cb);
#endif
    lv_obj_set_click(lab_cho_gh,true);    
	if(lab_cho_gh->coords.x2-lab_cho_gh->coords.x1<37)
	{
		int x_offset=(37-(lab_cho_gh->coords.x2-lab_cho_gh->coords.x1))/2;
		lv_obj_set_style_local_pad_left(lab_cho_gh,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(lab_cho_gh,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(lab_cho_gh->coords.y2-lab_cho_gh->coords.y1<18)
	{
		int y_offset=(18-(lab_cho_gh->coords.y2-lab_cho_gh->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(lab_cho_gh,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(lab_cho_gh,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(lab_cho_gh, 77, 216);
    qmsd_obj_set_id(lab_cho_gh,"lab_cho_gh");
}
    
void qmsd_ima_cho_lh__create()
{
    ima_cho_lh_ = lv_img_create(screen_choice, NULL);
    lv_img_set_src(ima_cho_lh_, &imgtileview_leave_home_png);
#ifdef BLOCKLY_ima_cho_lh__EVENT_HANDLER
    lv_obj_set_event_cb(ima_cho_lh_, __qmsd_ima_cho_lh__cb);
#endif
    lv_obj_set_pos(ima_cho_lh_, 228, 154);
    lv_obj_set_click(ima_cho_lh_,true);
    lv_obj_set_style_local_image_recolor(ima_cho_lh_,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(ima_cho_lh_,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    qmsd_obj_set_id(ima_cho_lh_,"ima_cho_lh_");
}
    void qmsd_lab_cho_lh_create()
{
	lab_cho_lh = lv_label_create(screen_choice, NULL);
	lv_label_set_long_mode(lab_cho_lh,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(lab_cho_lh,true);
	lv_obj_set_size(lab_cho_lh, 37, 18);
//set label style
	lv_obj_set_style_local_text_color(lab_cho_lh,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(lab_cho_lh, "离家");
	lv_label_set_align(lab_cho_lh, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(lab_cho_lh,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_18);
#ifdef BLOCKLY_lab_cho_lh_EVENT_HANDLER
	lv_obj_set_event_cb(lab_cho_lh, __qmsd_lab_cho_lh_cb);
#endif
    lv_obj_set_click(lab_cho_lh,true);    
	if(lab_cho_lh->coords.x2-lab_cho_lh->coords.x1<37)
	{
		int x_offset=(37-(lab_cho_lh->coords.x2-lab_cho_lh->coords.x1))/2;
		lv_obj_set_style_local_pad_left(lab_cho_lh,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(lab_cho_lh,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(lab_cho_lh->coords.y2-lab_cho_lh->coords.y1<18)
	{
		int y_offset=(18-(lab_cho_lh->coords.y2-lab_cho_lh->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(lab_cho_lh,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(lab_cho_lh,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(lab_cho_lh, 225, 216);
    qmsd_obj_set_id(lab_cho_lh,"lab_cho_lh");
}
    
void qmsd_ima_cho_gb__create()
{
    ima_cho_gb_ = lv_img_create(screen_choice, NULL);
    lv_img_set_src(ima_cho_gb_, &imgchoice_go_bed__png);
#ifdef BLOCKLY_ima_cho_gb__EVENT_HANDLER
    lv_obj_set_event_cb(ima_cho_gb_, __qmsd_ima_cho_gb__cb);
#endif
    lv_obj_set_pos(ima_cho_gb_, 378, 154);
    lv_obj_set_click(ima_cho_gb_,true);
    lv_obj_set_style_local_image_recolor(ima_cho_gb_,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(ima_cho_gb_,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    qmsd_obj_set_id(ima_cho_gb_,"ima_cho_gb_");
}
    void qmsd_lab_cho_gb_create()
{
	lab_cho_gb = lv_label_create(screen_choice, NULL);
	lv_label_set_long_mode(lab_cho_gb,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(lab_cho_gb,true);
	lv_obj_set_size(lab_cho_gb, 37, 18);
//set label style
	lv_obj_set_style_local_text_color(lab_cho_gb,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(lab_cho_gb, "起床");
	lv_label_set_align(lab_cho_gb, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(lab_cho_gb,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_18);
#ifdef BLOCKLY_lab_cho_gb_EVENT_HANDLER
	lv_obj_set_event_cb(lab_cho_gb, __qmsd_lab_cho_gb_cb);
#endif
    lv_obj_set_click(lab_cho_gb,true);    
	if(lab_cho_gb->coords.x2-lab_cho_gb->coords.x1<37)
	{
		int x_offset=(37-(lab_cho_gb->coords.x2-lab_cho_gb->coords.x1))/2;
		lv_obj_set_style_local_pad_left(lab_cho_gb,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(lab_cho_gb,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(lab_cho_gb->coords.y2-lab_cho_gb->coords.y1<18)
	{
		int y_offset=(18-(lab_cho_gb->coords.y2-lab_cho_gb->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(lab_cho_gb,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(lab_cho_gb,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(lab_cho_gb, 374, 216);
    qmsd_obj_set_id(lab_cho_gb,"lab_cho_gb");
}
    
void qmsd_ima_cho_sl__create()
{
    ima_cho_sl_ = lv_img_create(screen_choice, NULL);
    lv_img_set_src(ima_cho_sl_, &imgchoice_sleep__png);
#ifdef BLOCKLY_ima_cho_sl__EVENT_HANDLER
    lv_obj_set_event_cb(ima_cho_sl_, __qmsd_ima_cho_sl__cb);
#endif
    lv_obj_set_pos(ima_cho_sl_, 81, 345);
    lv_obj_set_click(ima_cho_sl_,true);
    lv_obj_set_style_local_image_recolor(ima_cho_sl_,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(ima_cho_sl_,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    qmsd_obj_set_id(ima_cho_sl_,"ima_cho_sl_");
}
    void qmsd_lab_cho_sl_create()
{
	lab_cho_sl = lv_label_create(screen_choice, NULL);
	lv_label_set_long_mode(lab_cho_sl,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(lab_cho_sl,true);
	lv_obj_set_size(lab_cho_sl, 37, 18);
//set label style
	lv_obj_set_style_local_text_color(lab_cho_sl,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(lab_cho_sl, "睡眠");
	lv_label_set_align(lab_cho_sl, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(lab_cho_sl,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_18);
#ifdef BLOCKLY_lab_cho_sl_EVENT_HANDLER
	lv_obj_set_event_cb(lab_cho_sl, __qmsd_lab_cho_sl_cb);
#endif
    lv_obj_set_click(lab_cho_sl,true);    
	if(lab_cho_sl->coords.x2-lab_cho_sl->coords.x1<37)
	{
		int x_offset=(37-(lab_cho_sl->coords.x2-lab_cho_sl->coords.x1))/2;
		lv_obj_set_style_local_pad_left(lab_cho_sl,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(lab_cho_sl,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(lab_cho_sl->coords.y2-lab_cho_sl->coords.y1<18)
	{
		int y_offset=(18-(lab_cho_sl->coords.y2-lab_cho_sl->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(lab_cho_sl,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(lab_cho_sl,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(lab_cho_sl, 77, 399);
    qmsd_obj_set_id(lab_cho_sl,"lab_cho_sl");
}
    
void qmsd_ima_cho_me__create()
{
    ima_cho_me_ = lv_img_create(screen_choice, NULL);
    lv_img_set_src(ima_cho_me_, &imgchoice_meet__png);
#ifdef BLOCKLY_ima_cho_me__EVENT_HANDLER
    lv_obj_set_event_cb(ima_cho_me_, __qmsd_ima_cho_me__cb);
#endif
    lv_obj_set_pos(ima_cho_me_, 236, 340);
    lv_obj_set_click(ima_cho_me_,true);
    lv_obj_set_style_local_image_recolor(ima_cho_me_,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(ima_cho_me_,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    qmsd_obj_set_id(ima_cho_me_,"ima_cho_me_");
}
    void qmsd_lab_cho_me_create()
{
	lab_cho_me = lv_label_create(screen_choice, NULL);
	lv_label_set_long_mode(lab_cho_me,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(lab_cho_me,true);
	lv_obj_set_size(lab_cho_me, 37, 18);
//set label style
	lv_obj_set_style_local_text_color(lab_cho_me,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(lab_cho_me, "会客");
	lv_label_set_align(lab_cho_me, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(lab_cho_me,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_18);
#ifdef BLOCKLY_lab_cho_me_EVENT_HANDLER
	lv_obj_set_event_cb(lab_cho_me, __qmsd_lab_cho_me_cb);
#endif
    lv_obj_set_click(lab_cho_me,true);    
	if(lab_cho_me->coords.x2-lab_cho_me->coords.x1<37)
	{
		int x_offset=(37-(lab_cho_me->coords.x2-lab_cho_me->coords.x1))/2;
		lv_obj_set_style_local_pad_left(lab_cho_me,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(lab_cho_me,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(lab_cho_me->coords.y2-lab_cho_me->coords.y1<18)
	{
		int y_offset=(18-(lab_cho_me->coords.y2-lab_cho_me->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(lab_cho_me,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(lab_cho_me,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(lab_cho_me, 225, 398);
    qmsd_obj_set_id(lab_cho_me,"lab_cho_me");
}
    
void qmsd_ima_cho_fi__create()
{
    ima_cho_fi_ = lv_img_create(screen_choice, NULL);
    lv_img_set_src(ima_cho_fi_, &imgchoice_fime__png);
#ifdef BLOCKLY_ima_cho_fi__EVENT_HANDLER
    lv_obj_set_event_cb(ima_cho_fi_, __qmsd_ima_cho_fi__cb);
#endif
    lv_obj_set_pos(ima_cho_fi_, 378, 340);
    lv_obj_set_click(ima_cho_fi_,true);
    lv_obj_set_style_local_image_recolor(ima_cho_fi_,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(ima_cho_fi_,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    qmsd_obj_set_id(ima_cho_fi_,"ima_cho_fi_");
}
    void qmsd_lab_cho_fi_create()
{
	lab_cho_fi = lv_label_create(screen_choice, NULL);
	lv_label_set_long_mode(lab_cho_fi,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(lab_cho_fi,true);
	lv_obj_set_size(lab_cho_fi, 37, 18);
//set label style
	lv_obj_set_style_local_text_color(lab_cho_fi,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(lab_cho_fi, "影院");
	lv_label_set_align(lab_cho_fi, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(lab_cho_fi,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_18);
#ifdef BLOCKLY_lab_cho_fi_EVENT_HANDLER
	lv_obj_set_event_cb(lab_cho_fi, __qmsd_lab_cho_fi_cb);
#endif
    lv_obj_set_click(lab_cho_fi,true);    
	if(lab_cho_fi->coords.x2-lab_cho_fi->coords.x1<37)
	{
		int x_offset=(37-(lab_cho_fi->coords.x2-lab_cho_fi->coords.x1))/2;
		lv_obj_set_style_local_pad_left(lab_cho_fi,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(lab_cho_fi,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(lab_cho_fi->coords.y2-lab_cho_fi->coords.y1<18)
	{
		int y_offset=(18-(lab_cho_fi->coords.y2-lab_cho_fi->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(lab_cho_fi,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(lab_cho_fi,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(lab_cho_fi, 374, 398);
    qmsd_obj_set_id(lab_cho_fi,"lab_cho_fi");
}

static void screen_choice_qmsd_cb(lv_obj_t * obj, lv_event_t event, void *data)
{/*
    char *trans;
    lv_label_set_text(lab_cho_re,qmsd_lang_get_trans("lab_cho_re","选择模式"));
    lv_label_set_text(lab_cho_gh,qmsd_lang_get_trans("lab_cho_gh","回家"));
    lv_label_set_text(lab_cho_lh,qmsd_lang_get_trans("lab_cho_lh","离家"));
    lv_label_set_text(lab_cho_gb,qmsd_lang_get_trans("lab_cho_gb","起床"));
    lv_label_set_text(lab_cho_sl,qmsd_lang_get_trans("lab_cho_sl","睡眠"));
    lv_label_set_text(lab_cho_me,qmsd_lang_get_trans("lab_cho_me","会客"));
    lv_label_set_text(lab_cho_fi,qmsd_lang_get_trans("lab_cho_fi","影院"));
*/
#ifdef BLOCKLY_screen_choice_SCREEN_INIT
    __qmsd_screen_choice_init();
#endif
}

static void screen_choice_del_cb(lv_obj_t* obj,lv_event_t event)
{
    if(event == LV_EVENT_DELETE)
    {
        screen_choice=NULL;
        qmsd_screen_remove("screen_choice");
    }
}

void screen_choice_build(void)
{
    if(screen_choice) return;
    screen_choice = lv_obj_create(NULL, NULL);
    lv_obj_qmsd_set_cb(screen_choice, screen_choice_qmsd_cb);
    lv_obj_set_style_local_bg_color(screen_choice,LV_OBJ_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x20, 0x20, 0x20));

    qmsd_ima_cho_re_create();
    qmsd_lab_cho_re_create();
    qmsd_ima_cho_gh_create();
    qmsd_ima_cho_lh_create();
    qmsd_ima_cho_gb_create();
    qmsd_ima_cho_sl_create();
    qmsd_ima_cho_me_create();
    qmsd_ima_cho_fi_create();
    qmsd_ima_cho_gh__create();
    qmsd_lab_cho_gh_create();
    qmsd_ima_cho_lh__create();
    qmsd_lab_cho_lh_create();
    qmsd_ima_cho_gb__create();
    qmsd_lab_cho_gb_create();
    qmsd_ima_cho_sl__create();
    qmsd_lab_cho_sl_create();
    qmsd_ima_cho_me__create();
    qmsd_lab_cho_me_create();
    qmsd_ima_cho_fi__create();
    qmsd_lab_cho_fi_create();
    lv_obj_set_event_cb(screen_choice,screen_choice_del_cb);
    qmsd_screen_register(screen_choice,"screen_choice");
}

void screen_choice_show(void)
{
    if(!screen_choice)
    {
        screen_choice_build();
    }
    lv_scr_load(screen_choice);
}

void screen_choice_delete(void)
{
    if(screen_choice)
    {
        lv_obj_del(screen_choice);
        screen_choice = NULL;
    }
}
