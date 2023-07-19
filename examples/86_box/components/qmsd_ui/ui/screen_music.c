#include "qmsd_ui_entry.h"
#include "qmsd_internal_ui_cb.h"

lv_obj_t* screen_music;
lv_obj_t* image_mu_return;
lv_obj_t* label_mu_return;
lv_obj_t* image_mu_line;
lv_obj_t* label_mu_singer;
lv_obj_t* label_mu_song;
lv_obj_t* slider_mu;
lv_obj_t* label_mu_begin;
lv_obj_t* label_mu_end;
lv_obj_t* image_mu_list;
lv_obj_t* image_mu_prev;
lv_obj_t* image_mu_stop;
lv_obj_t* image_mu_next;
lv_obj_t* image_mu_mode;
lv_obj_t* image_mu_bottom;
lv_obj_t* image_mu_s_r;
lv_obj_t* image_mu_s_l;
lv_obj_t* image_mu_s_m;
lv_obj_t* image_play_bo;
lv_obj_t* image_play_sign;
lv_obj_t* image_play_line;
lv_obj_t* label_play_sign;
lv_obj_t* image_play_re;


    
void qmsd_image_mu_return_create()
{
    image_mu_return = lv_img_create(screen_music, NULL);
    lv_img_set_src(image_mu_return, &imgreturn_png);
#ifdef BLOCKLY_image_mu_return_EVENT_HANDLER
    lv_obj_set_event_cb(image_mu_return, __qmsd_image_mu_return_cb);
#endif
    lv_obj_set_pos(image_mu_return, 31.5, 32.5);
    lv_obj_set_click(image_mu_return,true);
    lv_obj_set_style_local_image_recolor(image_mu_return,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(image_mu_return,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    qmsd_obj_set_id(image_mu_return,"image_mu_return");
}
    void qmsd_label_mu_return_create()
{
	label_mu_return = lv_label_create(screen_music, NULL);
	lv_label_set_long_mode(label_mu_return,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_mu_return,true);
	lv_obj_set_size(label_mu_return, 60, 33);
//set label style
	lv_obj_set_style_local_text_color(label_mu_return,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(label_mu_return, "返回");
	lv_label_set_align(label_mu_return, LV_LABEL_ALIGN_LEFT);
	lv_obj_set_style_local_text_font(label_mu_return,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_22);
#ifdef BLOCKLY_label_mu_return_EVENT_HANDLER
	lv_obj_set_event_cb(label_mu_return, __qmsd_label_mu_return_cb);
#endif
    lv_obj_set_click(label_mu_return,true);    
	if(label_mu_return->coords.x2-label_mu_return->coords.x1<60)
	{
		int x_offset=(60-(label_mu_return->coords.x2-label_mu_return->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_mu_return,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_mu_return,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_mu_return->coords.y2-label_mu_return->coords.y1<33)
	{
		int y_offset=(33-(label_mu_return->coords.y2-label_mu_return->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_mu_return,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_mu_return,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(label_mu_return, 58, 24);
    qmsd_obj_set_id(label_mu_return,"label_mu_return");
}
    
void qmsd_image_mu_line_create()
{
    image_mu_line = lv_img_create(screen_music, NULL);
    lv_img_set_src(image_mu_line, &imgline_png);
#ifdef BLOCKLY_image_mu_line_EVENT_HANDLER
    lv_obj_set_event_cb(image_mu_line, __qmsd_image_mu_line_cb);
#endif
    lv_obj_set_pos(image_mu_line, 0, 70);
    qmsd_obj_set_id(image_mu_line,"image_mu_line");
}
    void qmsd_label_mu_singer_create()
{
	label_mu_singer = lv_label_create(screen_music, NULL);
	lv_label_set_long_mode(label_mu_singer,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_mu_singer,true);
	lv_obj_set_size(label_mu_singer, 359, 30);
//set label style
	lv_obj_set_style_local_text_color(label_mu_singer,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(label_mu_singer, "Havana");
	lv_label_set_align(label_mu_singer, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(label_mu_singer,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_29);
#ifdef BLOCKLY_label_mu_singer_EVENT_HANDLER
	lv_obj_set_event_cb(label_mu_singer, __qmsd_label_mu_singer_cb);
#endif
	if(label_mu_singer->coords.x2-label_mu_singer->coords.x1<359)
	{
		int x_offset=(359-(label_mu_singer->coords.x2-label_mu_singer->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_mu_singer,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_mu_singer,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_mu_singer->coords.y2-label_mu_singer->coords.y1<30)
	{
		int y_offset=(30-(label_mu_singer->coords.y2-label_mu_singer->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_mu_singer,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_mu_singer,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(label_mu_singer, 65, 306);
    qmsd_obj_set_id(label_mu_singer,"label_mu_singer");
}
    void qmsd_label_mu_song_create()
{
	label_mu_song = lv_label_create(screen_music, NULL);
	lv_label_set_long_mode(label_mu_song,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_mu_song,true);
	lv_obj_set_size(label_mu_song, 359, 25);
//set label style
	lv_obj_set_style_local_text_color(label_mu_song,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(label_mu_song, "Cabello feat Young");
	lv_label_set_align(label_mu_song, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(label_mu_song,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_18);
#ifdef BLOCKLY_label_mu_song_EVENT_HANDLER
	lv_obj_set_event_cb(label_mu_song, __qmsd_label_mu_song_cb);
#endif
	if(label_mu_song->coords.x2-label_mu_song->coords.x1<359)
	{
		int x_offset=(359-(label_mu_song->coords.x2-label_mu_song->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_mu_song,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_mu_song,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_mu_song->coords.y2-label_mu_song->coords.y1<25)
	{
		int y_offset=(25-(label_mu_song->coords.y2-label_mu_song->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_mu_song,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_mu_song,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(label_mu_song, 65, 338);
    qmsd_obj_set_id(label_mu_song,"label_mu_song");
}
    void qmsd_slider_mu_create()
{
	slider_mu = lv_slider_create(screen_music, NULL);
	lv_obj_set_size(slider_mu, 360, 4);
    lv_obj_set_pos(slider_mu, 60, 375);
	lv_slider_set_value(slider_mu, 43, LV_ANIM_OFF);

	//set slider bg style
	lv_obj_set_style_local_bg_color(slider_mu,LV_SLIDER_PART_BG,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xd4, 0xd7, 0xd9));
	lv_obj_set_style_local_bg_grad_color(slider_mu,LV_SLIDER_PART_BG,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xd4, 0xd7, 0xd9));
	lv_obj_set_style_local_border_color(slider_mu,LV_SLIDER_PART_BG,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xd4, 0xd7, 0xd9));
	lv_obj_set_style_local_radius(slider_mu,LV_SLIDER_PART_BG,LV_STATE_DEFAULT,LV_RADIUS_CIRCLE);

	//set slider indic style
    lv_obj_set_style_local_bg_color(slider_mu,LV_SLIDER_PART_INDIC,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
	lv_obj_set_style_local_bg_grad_color(slider_mu,LV_SLIDER_PART_INDIC,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
	lv_obj_set_style_local_radius(slider_mu,LV_SLIDER_PART_INDIC,LV_STATE_DEFAULT,LV_RADIUS_CIRCLE);
    lv_obj_set_style_local_shadow_color(slider_mu,LV_SLIDER_PART_INDIC,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
	lv_obj_set_style_local_shadow_width(slider_mu,LV_SLIDER_PART_INDIC,LV_STATE_DEFAULT,5);

	//set slider knob style
    lv_obj_set_style_local_bg_color(slider_mu,LV_SLIDER_PART_KNOB,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
	lv_obj_set_style_local_bg_grad_color(slider_mu,LV_SLIDER_PART_KNOB,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
	lv_obj_set_style_local_radius(slider_mu,LV_SLIDER_PART_KNOB,LV_STATE_DEFAULT,LV_RADIUS_CIRCLE);
//! fix here
    lv_obj_set_style_local_bg_opa(slider_mu,LV_SLIDER_PART_KNOB,LV_STATE_DEFAULT,LV_OPA_100);

	lv_obj_set_style_local_outline_width(slider_mu,LV_SLIDER_PART_BG,LV_STATE_DEFAULT,0);
	lv_obj_set_style_local_outline_width(slider_mu,LV_SLIDER_PART_BG,LV_STATE_FOCUSED,0);
#ifdef BLOCKLY_slider_mu_EVENT_HANDLER
	lv_obj_set_event_cb(slider_mu, __qmsd_slider_mu_cb);
#endif
    qmsd_obj_set_id(slider_mu,"slider_mu");
}
    void qmsd_label_mu_begin_create()
{
	label_mu_begin = lv_label_create(screen_music, NULL);
	lv_label_set_long_mode(label_mu_begin,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_mu_begin,true);
	lv_obj_set_size(label_mu_begin, 100, 19);
//set label style
	lv_obj_set_style_local_text_color(label_mu_begin,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(label_mu_begin, "1:87");
	lv_label_set_align(label_mu_begin, LV_LABEL_ALIGN_LEFT);
	lv_obj_set_style_local_text_font(label_mu_begin,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_14);
#ifdef BLOCKLY_label_mu_begin_EVENT_HANDLER
	lv_obj_set_event_cb(label_mu_begin, __qmsd_label_mu_begin_cb);
#endif
	if(label_mu_begin->coords.x2-label_mu_begin->coords.x1<100)
	{
		int x_offset=(100-(label_mu_begin->coords.x2-label_mu_begin->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_mu_begin,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_mu_begin,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_mu_begin->coords.y2-label_mu_begin->coords.y1<19)
	{
		int y_offset=(19-(label_mu_begin->coords.y2-label_mu_begin->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_mu_begin,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_mu_begin,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(label_mu_begin, 59, 387);
    qmsd_obj_set_id(label_mu_begin,"label_mu_begin");
}
    void qmsd_label_mu_end_create()
{
	label_mu_end = lv_label_create(screen_music, NULL);
	lv_label_set_long_mode(label_mu_end,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_mu_end,true);
	lv_obj_set_size(label_mu_end, 60, 20);
//set label style
	lv_obj_set_style_local_text_color(label_mu_end,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(label_mu_end, "-2:26");
	lv_label_set_align(label_mu_end, LV_LABEL_ALIGN_RIGHT);
	lv_obj_set_style_local_text_font(label_mu_end,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_14);
#ifdef BLOCKLY_label_mu_end_EVENT_HANDLER
	lv_obj_set_event_cb(label_mu_end, __qmsd_label_mu_end_cb);
#endif
	if(label_mu_end->coords.x2-label_mu_end->coords.x1<60)
	{
		int x_offset=(60-(label_mu_end->coords.x2-label_mu_end->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_mu_end,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_mu_end,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_mu_end->coords.y2-label_mu_end->coords.y1<20)
	{
		int y_offset=(20-(label_mu_end->coords.y2-label_mu_end->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_mu_end,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_mu_end,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(label_mu_end, 360, 387);
    qmsd_obj_set_id(label_mu_end,"label_mu_end");
}
    
void qmsd_image_mu_list_create()
{
    image_mu_list = lv_img_create(screen_music, NULL);
    lv_img_set_src(image_mu_list, &imgmu_list_png);
//! add here 增加点击区域
    lv_obj_set_click(image_mu_list,true);
    lv_obj_set_ext_click_area(image_mu_list,40,40,40,30);
#ifdef BLOCKLY_image_mu_list_EVENT_HANDLER
    lv_obj_set_event_cb(image_mu_list, __qmsd_image_mu_list_cb);
#endif
    lv_obj_set_pos(image_mu_list, 61, 423);
    lv_obj_set_click(image_mu_list,true);
    lv_obj_set_style_local_image_recolor(image_mu_list,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(image_mu_list,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    qmsd_obj_set_id(image_mu_list,"image_mu_list");
}
    
void qmsd_image_mu_prev_create()
{
    image_mu_prev = lv_img_create(screen_music, NULL);
    lv_img_set_src(image_mu_prev, &imgmu_prev_png);
//! fix here
    lv_obj_set_click(image_mu_prev, true);
    lv_obj_set_ext_click_area(image_mu_prev, 20,20,20,20);
#ifdef BLOCKLY_image_mu_prev_EVENT_HANDLER
    lv_obj_set_event_cb(image_mu_prev, __qmsd_image_mu_prev_cb);
#endif
    lv_obj_set_pos(image_mu_prev, 149, 421);
    qmsd_obj_set_id(image_mu_prev,"image_mu_prev");
}
    
void qmsd_image_mu_stop_create()
{
    image_mu_stop = lv_img_create(screen_music, NULL);
    lv_img_set_src(image_mu_stop, &imgmu_stop_png);
#ifdef BLOCKLY_image_mu_stop_EVENT_HANDLER
    lv_obj_set_event_cb(image_mu_stop, __qmsd_image_mu_stop_cb);
#endif
    lv_obj_set_pos(image_mu_stop, 221, 405);
    qmsd_obj_set_id(image_mu_stop,"image_mu_stop");
}
    
void qmsd_image_mu_next_create()
{
    image_mu_next = lv_img_create(screen_music, NULL);
    lv_img_set_src(image_mu_next, &imgmu_next_png);
//! fix here
    lv_obj_set_click(image_mu_next, true);
    lv_obj_set_ext_click_area(image_mu_next, 20,20,20,20);
#ifdef BLOCKLY_image_mu_next_EVENT_HANDLER
    lv_obj_set_event_cb(image_mu_next, __qmsd_image_mu_next_cb);
#endif
    lv_obj_set_pos(image_mu_next, 331, 421);
    qmsd_obj_set_id(image_mu_next,"image_mu_next");
}
    
void qmsd_image_mu_mode_create()
{
    image_mu_mode = lv_img_create(screen_music, NULL);
    lv_img_set_src(image_mu_mode, &imgmu_mode_png);
#ifdef BLOCKLY_image_mu_mode_EVENT_HANDLER
    lv_obj_set_event_cb(image_mu_mode, __qmsd_image_mu_mode_cb);
#endif
    lv_obj_set_pos(image_mu_mode, 404, 423);
    qmsd_obj_set_id(image_mu_mode,"image_mu_mode");
}
    
void qmsd_image_mu_bottom_create()
{
    image_mu_bottom = lv_img_create(screen_music, NULL);
    lv_img_set_src(image_mu_bottom, &imgmu_bottom_png);
#ifdef BLOCKLY_image_mu_bottom_EVENT_HANDLER
    lv_obj_set_event_cb(image_mu_bottom, __qmsd_image_mu_bottom_cb);
#endif
    lv_obj_set_pos(image_mu_bottom, 65, 254);
    qmsd_obj_set_id(image_mu_bottom,"image_mu_bottom");
}
    
void qmsd_image_mu_s_r_create()
{
    image_mu_s_r = lv_img_create(screen_music, NULL);
    lv_img_set_src(image_mu_s_r, &imgimg_mu_2_png);
    lv_obj_set_style_local_image_opa(image_mu_s_r,LV_IMG_PART_MAIN,LV_STATE_DEFAULT,55);
#ifdef BLOCKLY_image_mu_s_r_EVENT_HANDLER
    lv_obj_set_event_cb(image_mu_s_r, __qmsd_image_mu_s_r_cb);
#endif
    lv_obj_set_pos(image_mu_s_r, 258, 81);
    lv_obj_set_click(image_mu_s_r,true);
    lv_obj_set_style_local_image_recolor(image_mu_s_r,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(image_mu_s_r,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    qmsd_obj_set_id(image_mu_s_r,"image_mu_s_r");
}
    
void qmsd_image_mu_s_l_create()
{
    image_mu_s_l = lv_img_create(screen_music, NULL);
    lv_img_set_src(image_mu_s_l, &imgimg_mu_3_png);
    lv_obj_set_style_local_image_opa(image_mu_s_l,LV_IMG_PART_MAIN,LV_STATE_DEFAULT,55);
#ifdef BLOCKLY_image_mu_s_l_EVENT_HANDLER
    lv_obj_set_event_cb(image_mu_s_l, __qmsd_image_mu_s_l_cb);
#endif
    lv_obj_set_pos(image_mu_s_l, 47, 82);
    lv_obj_set_click(image_mu_s_l,true);
    lv_obj_set_style_local_image_recolor(image_mu_s_l,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(image_mu_s_l,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    qmsd_obj_set_id(image_mu_s_l,"image_mu_s_l");
}
    
void qmsd_image_mu_s_m_create()
{
    image_mu_s_m = lv_img_create(screen_music, NULL);
    lv_img_set_src(image_mu_s_m, &imgimg_mu_1_png);
#ifdef BLOCKLY_image_mu_s_m_EVENT_HANDLER
    lv_obj_set_event_cb(image_mu_s_m, __qmsd_image_mu_s_m_cb);
#endif
    lv_obj_set_pos(image_mu_s_m, 156, 112);
    lv_obj_set_click(image_mu_s_m,true);
    lv_obj_set_style_local_image_recolor(image_mu_s_m,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(image_mu_s_m,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    qmsd_obj_set_id(image_mu_s_m,"image_mu_s_m");
}
    
void qmsd_image_play_bo_create()
{
    image_play_bo = lv_img_create(screen_music, NULL);
    lv_img_set_src(image_play_bo, &imgimg_play_bt_png);
#ifdef BLOCKLY_image_play_bo_EVENT_HANDLER
    lv_obj_set_event_cb(image_play_bo, __qmsd_image_play_bo_cb);
#endif
    lv_obj_set_pos(image_play_bo, 0, 133);
    qmsd_obj_set_id(image_play_bo,"image_play_bo");
}
    
void qmsd_image_play_sign_create()
{
    image_play_sign = lv_img_create(screen_music, NULL);
    lv_img_set_src(image_play_sign, &imgimg_play_sign_png);
#ifdef BLOCKLY_image_play_sign_EVENT_HANDLER
    lv_obj_set_event_cb(image_play_sign, __qmsd_image_play_sign_cb);
#endif
	lv_obj_set_parent(image_play_sign,image_play_bo);
    lv_obj_set_pos(image_play_sign, 25-image_play_bo->coords.x1+lv_obj_get_x(screen_music), 160-image_play_bo->coords.y1+lv_obj_get_y(screen_music));
    lv_obj_set_click(image_play_sign,true);
    lv_obj_set_style_local_image_recolor(image_play_sign,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(image_play_sign,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    qmsd_obj_set_id(image_play_sign,"image_play_sign");
}
    
void qmsd_image_play_line_create()
{
    image_play_line = lv_img_create(screen_music, NULL);
    lv_img_set_src(image_play_line, &imgimg_play_line_png);
#ifdef BLOCKLY_image_play_line_EVENT_HANDLER
    lv_obj_set_event_cb(image_play_line, __qmsd_image_play_line_cb);
#endif
	lv_obj_set_parent(image_play_line,image_play_bo);
    lv_obj_set_pos(image_play_line, 20-image_play_bo->coords.x1+lv_obj_get_x(screen_music), 193-image_play_bo->coords.y1+lv_obj_get_y(screen_music));
    qmsd_obj_set_id(image_play_line,"image_play_line");
}
    void qmsd_label_play_sign_create()
{
	label_play_sign = lv_label_create(screen_music, NULL);
	lv_label_set_long_mode(label_play_sign,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_play_sign,true);
	lv_obj_set_size(label_play_sign, 130, 30);
	lv_obj_set_parent(label_play_sign,image_play_bo);
//set label style
	lv_obj_set_style_local_text_color(label_play_sign,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(label_play_sign, "播放列表（58）");
	lv_label_set_align(label_play_sign, LV_LABEL_ALIGN_LEFT);
	lv_obj_set_style_local_text_font(label_play_sign,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_16);
#ifdef BLOCKLY_label_play_sign_EVENT_HANDLER
	lv_obj_set_event_cb(label_play_sign, __qmsd_label_play_sign_cb);
#endif
	if(label_play_sign->coords.x2-label_play_sign->coords.x1<130)
	{
		int x_offset=(130-(label_play_sign->coords.x2-label_play_sign->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_play_sign,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_play_sign,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_play_sign->coords.y2-label_play_sign->coords.y1<30)
	{
		int y_offset=(30-(label_play_sign->coords.y2-label_play_sign->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_play_sign,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_play_sign,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(label_play_sign, 48-image_play_bo->coords.x1+lv_obj_get_x(screen_music), 153-image_play_bo->coords.y1+lv_obj_get_y(screen_music));
    qmsd_obj_set_id(label_play_sign,"label_play_sign");
}
    
void qmsd_image_play_re_create()
{
    image_play_re = lv_img_create(screen_music, NULL);
    lv_img_set_src(image_play_re, &imgimg_play_return_png);
//! add here 增加点击区域
    lv_obj_set_click(image_play_re,true);
    lv_obj_set_ext_click_area(image_play_re,40,40,40,5); 
#ifdef BLOCKLY_image_play_re_EVENT_HANDLER
    lv_obj_set_event_cb(image_play_re, __qmsd_image_play_re_cb);
#endif
	lv_obj_set_parent(image_play_re,image_play_bo);
    lv_obj_set_pos(image_play_re, 433-image_play_bo->coords.x1+lv_obj_get_x(screen_music), 159-image_play_bo->coords.y1+lv_obj_get_y(screen_music));
    lv_obj_set_click(image_play_re,true);
    lv_obj_set_style_local_image_recolor(image_play_re,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(image_play_re,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    qmsd_obj_set_id(image_play_re,"image_play_re");
}

static void screen_music_qmsd_cb(lv_obj_t * obj, lv_event_t event, void *data)
{/*
    char *trans;
    lv_label_set_text(label_mu_return,qmsd_lang_get_trans("label_mu_return","返回"));
    lv_label_set_text(label_mu_singer,qmsd_lang_get_trans("label_mu_singer","Havana"));
    lv_label_set_text(label_mu_song,qmsd_lang_get_trans("label_mu_song","Cabello feat Young"));
    lv_label_set_text(label_mu_begin,qmsd_lang_get_trans("label_mu_begin","1:87"));
    lv_label_set_text(label_mu_end,qmsd_lang_get_trans("label_mu_end","-2:26"));
    lv_label_set_text(label_play_sign,qmsd_lang_get_trans("label_play_sign","播放列表（58）"));
*/
#ifdef BLOCKLY_screen_music_SCREEN_INIT
    __qmsd_screen_music_init();
#endif
}

static void screen_music_del_cb(lv_obj_t* obj,lv_event_t event)
{
    if(event == LV_EVENT_DELETE)
    {
        screen_music=NULL;
        qmsd_screen_remove("screen_music");
    }
}

void screen_music_build(void)
{
    printf("===5===\n");
    if(screen_music) return;
    screen_music = lv_obj_create(NULL, NULL);
    lv_obj_qmsd_set_cb(screen_music, screen_music_qmsd_cb);
    lv_obj_set_style_local_bg_color(screen_music,LV_OBJ_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x31, 0x04, 0x58));

    qmsd_image_mu_return_create();
    qmsd_label_mu_return_create();
    qmsd_image_mu_line_create();
    qmsd_label_mu_singer_create();
    qmsd_label_mu_song_create();
    qmsd_slider_mu_create();
    qmsd_label_mu_begin_create();
    qmsd_label_mu_end_create();
    qmsd_image_mu_list_create();
    qmsd_image_mu_prev_create();
    qmsd_image_mu_stop_create();
    qmsd_image_mu_next_create();
    qmsd_image_mu_mode_create();
    qmsd_image_mu_bottom_create();
    qmsd_image_mu_s_r_create();
    qmsd_image_mu_s_l_create();
    qmsd_image_mu_s_m_create();
    qmsd_image_play_bo_create();
    qmsd_image_play_sign_create();
    qmsd_image_play_line_create();
    qmsd_label_play_sign_create();
    qmsd_image_play_re_create();
    lv_obj_set_event_cb(screen_music,screen_music_del_cb);
    qmsd_screen_register(screen_music,"screen_music");
}

void screen_music_show(void)
{
    if(!screen_music)
    {
        screen_music_build();
    }
    lv_scr_load(screen_music);
}

void screen_music_delete(void)
{
    if(screen_music)
    {
        lv_obj_del(screen_music);
        screen_music = NULL;
    }
}
