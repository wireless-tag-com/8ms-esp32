#include "qmsd_ui_entry.h"
#include "qmsd_internal_ui_cb.h"
bool my_sign_main = false;
int num = 0;
lv_indev_t* get_point;
lv_indev_data_t my_data;

lv_obj_t* screen_main;
lv_obj_t* label_main_time;
lv_obj_t* label_main_min;
lv_obj_t* label_main_day;
lv_obj_t* image_main_wifi;
lv_obj_t* image_buletooth;
lv_obj_t* button_ma_music;
lv_obj_t * __button_ma_music_label;
lv_obj_t* button_ma_tem;
lv_obj_t * __button_ma_tem_label;
lv_obj_t* button_ma_light;
lv_obj_t * __button_ma_light_label;
lv_obj_t* label_ma_music;
lv_obj_t* image_singer;
lv_obj_t* label_ma_singer;
lv_obj_t* label_ma_song;
lv_obj_t* image_ma_prev;
lv_obj_t* image_ma_stop;
lv_obj_t* image_ma_next;
lv_obj_t* label_ma_windy;
lv_obj_t* label_ma_centig;
lv_obj_t* image_ma_high;
lv_obj_t* image_ma_low;
lv_obj_t* image_ma_light;
lv_obj_t* label_ma_light;
lv_obj_t* switch_ma;
lv_obj_t* button_ma_bott;
lv_obj_t * __button_ma_bott_label;
lv_obj_t* label_ma_label;
lv_obj_t* image_ma_sun;
lv_obj_t* label_ma_sun;
lv_obj_t* label_ma_sun_c;
lv_obj_t* label_ma_morn;
lv_obj_t* image_ma_smile;
lv_obj_t* slider_ma;
lv_obj_t* button_ma_color;
lv_obj_t * __button_ma_color_label;
lv_obj_t* label_ma_temper;
lv_obj_t* button_ma_barbt;
lv_obj_t * __button_ma_barbt_label;
lv_obj_t* button_ma_barra;
lv_obj_t * __button_ma_barra_label;
lv_obj_t* image_ma_fan;

// todo add here
lv_obj_t* line_ma_music;
lv_obj_t* line_ma_te;
    void qmsd_line_ma_music_create()
{
	line_ma_music = lv_line_create(screen_main, NULL);
	
	lv_obj_set_style_local_line_color(line_ma_music,LV_LINE_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
	lv_obj_set_style_local_line_width(line_ma_music,LV_LINE_PART_MAIN,LV_STATE_DEFAULT,1);
	lv_obj_set_style_local_line_rounded(line_ma_music,LV_LINE_PART_MAIN,LV_STATE_DEFAULT,1);
    lv_obj_set_style_local_line_opa(line_ma_music,LV_LINE_PART_MAIN,LV_STATE_DEFAULT,LV_OPA_20);
    

	static lv_point_t line_ma_music_points[] = {
{38, 121},
{215, 121},
};
	lv_line_set_points(line_ma_music, line_ma_music_points, 2);

}
    void qmsd_line_ma_te_create()
{
	line_ma_te = lv_line_create(screen_main, NULL);
	
	lv_obj_set_style_local_line_color(line_ma_te,LV_LINE_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
	lv_obj_set_style_local_line_width(line_ma_te,LV_LINE_PART_MAIN,LV_STATE_DEFAULT,1);
	lv_obj_set_style_local_line_rounded(line_ma_te,LV_LINE_PART_MAIN,LV_STATE_DEFAULT,1);
    lv_obj_set_style_local_line_opa(line_ma_te,LV_LINE_PART_MAIN,LV_STATE_DEFAULT,LV_OPA_20);

	static lv_point_t line_ma_te_points[] = {
{266, 121},
{443, 121},
};
	lv_line_set_points(line_ma_te, line_ma_te_points, 2);

}
// todo

    void qmsd_label_main_time_create()
{
	label_main_time = lv_label_create(screen_main, NULL);
	lv_label_set_long_mode(label_main_time,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_main_time,true);
	lv_obj_set_size(label_main_time, 100, 20);
//set label style
	lv_obj_set_style_local_text_color(label_main_time,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(label_main_time, "10:50");
	lv_label_set_align(label_main_time, LV_LABEL_ALIGN_LEFT);
	lv_obj_set_style_local_text_font(label_main_time,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_27);
#ifdef BLOCKLY_label_main_time_EVENT_HANDLER
	lv_obj_set_event_cb(label_main_time, __qmsd_label_main_time_cb);
#endif
	if(label_main_time->coords.x2-label_main_time->coords.x1<100)
	{
		int x_offset=(100-(label_main_time->coords.x2-label_main_time->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_main_time,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_main_time,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_main_time->coords.y2-label_main_time->coords.y1<20)
	{
		int y_offset=(20-(label_main_time->coords.y2-label_main_time->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_main_time,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_main_time,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(label_main_time, 27, 31);
    qmsd_obj_set_id(label_main_time,"label_main_time");
}
//!add object here
    void qmsd_label_main_min_create()
{
	label_main_min = lv_label_create(screen_main, NULL);
	lv_label_set_long_mode(label_main_min,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_main_min,true);
	lv_obj_set_size(label_main_min, 100, 20);
//set label style
	lv_obj_set_style_local_text_color(label_main_min,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(label_main_min, "50");
	lv_label_set_align(label_main_min, LV_LABEL_ALIGN_LEFT);
	lv_obj_set_style_local_text_font(label_main_min,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_27);
#ifdef BLOCKLY_label_main_min_EVENT_HANDLER
	lv_obj_set_event_cb(label_main_min, __qmsd_label_main_min_cb);
#endif
	// if(label_main_min->coords.x2-label_main_min->coords.x1<100)
	// {
	// 	int x_offset=(100-(label_main_min->coords.x2-label_main_min->coords.x1))/2;
	// 	lv_obj_set_style_local_pad_left(label_main_min,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	// 	lv_obj_set_style_local_pad_right(label_main_min,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	// }
	// if(label_main_min->coords.y2-label_main_min->coords.y1<20)
	// {
	// 	int y_offset=(20-(label_main_min->coords.y2-label_main_min->coords.y1))/2;
	// 	lv_obj_set_style_local_pad_bottom(label_main_min,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	// 	lv_obj_set_style_local_pad_top(label_main_min,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	// }
	lv_obj_set_pos(label_main_min, 80, 31);
}

    void qmsd_label_main_day_create()
{
	label_main_day = lv_label_create(screen_main, NULL);
	lv_label_set_long_mode(label_main_day,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_main_day,true);
	lv_obj_set_size(label_main_day, 100, 20);
//set label style
	lv_obj_set_style_local_text_color(label_main_day,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(label_main_day, "PM");
	lv_label_set_align(label_main_day, LV_LABEL_ALIGN_LEFT);
	lv_obj_set_style_local_text_font(label_main_day,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_26);
#ifdef BLOCKLY_label_main_day_EVENT_HANDLER
	lv_obj_set_event_cb(label_main_day, __qmsd_label_main_day_cb);
#endif
	if(label_main_day->coords.x2-label_main_day->coords.x1<100)
	{
		int x_offset=(100-(label_main_day->coords.x2-label_main_day->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_main_day,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_main_day,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_main_day->coords.y2-label_main_day->coords.y1<20)
	{
		int y_offset=(20-(label_main_day->coords.y2-label_main_day->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_main_day,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_main_day,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(label_main_day, 103, 31);
    qmsd_obj_set_id(label_main_day,"label_main_day");
}
    
void qmsd_image_main_wifi_create()
{
    image_main_wifi = lv_img_create(screen_main, NULL);
    lv_img_set_src(image_main_wifi, &imgwifi_png);
#ifdef BLOCKLY_image_main_wifi_EVENT_HANDLER
    lv_obj_set_event_cb(image_main_wifi, __qmsd_image_main_wifi_cb);
#endif
    lv_obj_set_pos(image_main_wifi, 379, 26);
    qmsd_obj_set_id(image_main_wifi,"image_main_wifi");
}
    
void qmsd_image_buletooth_create()
{
    image_buletooth = lv_img_create(screen_main, NULL);
    lv_img_set_src(image_buletooth, &imgbuletooth_png);
#ifdef BLOCKLY_image_buletooth_EVENT_HANDLER
    lv_obj_set_event_cb(image_buletooth, __qmsd_image_buletooth_cb);
#endif
    lv_obj_set_pos(image_buletooth, 429, 26);
    qmsd_obj_set_id(image_buletooth,"image_buletooth");
}
    void qmsd_button_ma_music_create()
{
    button_ma_music = lv_btn_create(screen_main, NULL);
    __button_ma_music_label = lv_label_create(button_ma_music, NULL);
    lv_label_set_text(__button_ma_music_label,qmsd_lang_get_trans("button_ma_music",""));

    lv_obj_set_style_local_text_font(__button_ma_music_label,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_16);
    lv_obj_set_size(button_ma_music, 206, 316);
    lv_obj_set_pos(button_ma_music, 24, 81);
#ifdef BLOCKLY_button_ma_music_EVENT_HANDLER
    lv_obj_set_event_cb(button_ma_music, __qmsd_button_ma_music_cb);
#endif


    lv_obj_t* obj = button_ma_music;
    int part = LV_BTN_PART_MAIN;
//设置正常样式
        lv_obj_set_style_local_bg_color(obj,part,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x8b, 0x98, 0xd1));
    lv_obj_set_style_local_radius(obj,part,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_bg_opa(obj,part,LV_STATE_DEFAULT,71);
    lv_obj_set_style_local_border_opa(obj,part,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_text_color(obj,part,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x31, 0x40, 0x4f));

//设置正常样式结束

//设置按下样式
        lv_obj_set_style_local_bg_color(obj,part,LV_STATE_PRESSED,LV_COLOR_MAKE(0x8b, 0x98, 0xd1));
    lv_obj_set_style_local_bg_opa(obj,part,LV_STATE_PRESSED,132);
    lv_obj_set_style_local_border_opa(obj,part,LV_STATE_PRESSED,0);
    lv_obj_set_style_local_text_color(obj,part,LV_STATE_PRESSED,LV_COLOR_MAKE(0x31, 0x40, 0x4f));

//设置按下样式结束

//设置禁用样式
        lv_obj_set_style_local_text_color(obj,part,LV_STATE_DISABLED,LV_COLOR_MAKE(0x88, 0x88, 0x88));

//设置禁用样式结束
    lv_obj_set_style_local_outline_width(button_ma_music,LV_BTN_PART_MAIN,LV_STATE_DEFAULT,0);
	lv_obj_set_style_local_outline_width(button_ma_music,LV_BTN_PART_MAIN,LV_STATE_FOCUSED,0);
    qmsd_obj_set_id(button_ma_music,"button_ma_music");
}
    void qmsd_button_ma_tem_create()
{
    button_ma_tem = lv_btn_create(screen_main, NULL);
    __button_ma_tem_label = lv_label_create(button_ma_tem, NULL);
    lv_label_set_text(__button_ma_tem_label,qmsd_lang_get_trans("button_ma_tem",""));

    lv_obj_set_style_local_text_font(__button_ma_tem_label,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_16);
    lv_obj_set_size(button_ma_tem, 206, 206);
    lv_obj_set_pos(button_ma_tem, 253, 81);
#ifdef BLOCKLY_button_ma_tem_EVENT_HANDLER
    lv_obj_set_event_cb(button_ma_tem, __qmsd_button_ma_tem_cb);
#endif


    lv_obj_t* obj = button_ma_tem;
    int part = LV_BTN_PART_MAIN;
//设置正常样式
        lv_obj_set_style_local_bg_color(obj,part,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x8b, 0x98, 0xd1));
    lv_obj_set_style_local_radius(obj,part,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_bg_opa(obj,part,LV_STATE_DEFAULT,78);
    lv_obj_set_style_local_border_opa(obj,part,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_shadow_width(obj,part,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_text_color(obj,part,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x31, 0x40, 0x4f));

//设置正常样式结束

//设置按下样式
        lv_obj_set_style_local_bg_color(obj,part,LV_STATE_PRESSED,LV_COLOR_MAKE(0x8b, 0x98, 0xd1));
    lv_obj_set_style_local_bg_opa(obj,part,LV_STATE_PRESSED,132);
    lv_obj_set_style_local_border_opa(obj,part,LV_STATE_PRESSED,0);
    lv_obj_set_style_local_text_color(obj,part,LV_STATE_PRESSED,LV_COLOR_MAKE(0x31, 0x40, 0x4f));

//设置按下样式结束

//设置禁用样式
        lv_obj_set_style_local_text_color(obj,part,LV_STATE_DISABLED,LV_COLOR_MAKE(0x88, 0x88, 0x88));

//设置禁用样式结束
    lv_obj_set_style_local_outline_width(button_ma_tem,LV_BTN_PART_MAIN,LV_STATE_DEFAULT,0);
	lv_obj_set_style_local_outline_width(button_ma_tem,LV_BTN_PART_MAIN,LV_STATE_FOCUSED,0);
    qmsd_obj_set_id(button_ma_tem,"button_ma_tem");
}
    void qmsd_button_ma_light_create()
{
    button_ma_light = lv_btn_create(screen_main, NULL);
    __button_ma_light_label = lv_label_create(button_ma_light, NULL);
    lv_label_set_text(__button_ma_light_label,qmsd_lang_get_trans("button_ma_light",""));

    lv_obj_set_style_local_text_color(__button_ma_light_label,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xf8, 0xe7, 0x1c));
    lv_obj_set_style_local_text_font(__button_ma_light_label,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_16);
    lv_obj_set_size(button_ma_light, 206, 83);
    lv_obj_set_pos(button_ma_light, 253, 314);
#ifdef BLOCKLY_button_ma_light_EVENT_HANDLER
    lv_obj_set_event_cb(button_ma_light, __qmsd_button_ma_light_cb);
#endif


    lv_obj_t* obj = button_ma_light;
    int part = LV_BTN_PART_MAIN;
//设置正常样式
        lv_obj_set_style_local_bg_color(obj,part,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x8b, 0x98, 0xd1));
    lv_obj_set_style_local_radius(obj,part,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_bg_opa(obj,part,LV_STATE_DEFAULT,71);
    lv_obj_set_style_local_border_opa(obj,part,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_text_color(obj,part,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x31, 0x40, 0x4f));

//设置正常样式结束

//设置按下样式
        lv_obj_set_style_local_bg_color(obj,part,LV_STATE_PRESSED,LV_COLOR_MAKE(0x8b, 0x98, 0xd1));
    lv_obj_set_style_local_bg_opa(obj,part,LV_STATE_PRESSED,132);
    lv_obj_set_style_local_border_opa(obj,part,LV_STATE_PRESSED,0);
    lv_obj_set_style_local_text_color(obj,part,LV_STATE_PRESSED,LV_COLOR_MAKE(0x31, 0x40, 0x4f));

//设置按下样式结束

//设置禁用样式
        lv_obj_set_style_local_text_color(obj,part,LV_STATE_DISABLED,LV_COLOR_MAKE(0x88, 0x88, 0x88));

//设置禁用样式结束
    lv_obj_set_style_local_outline_width(button_ma_light,LV_BTN_PART_MAIN,LV_STATE_DEFAULT,0);
	lv_obj_set_style_local_outline_width(button_ma_light,LV_BTN_PART_MAIN,LV_STATE_FOCUSED,0);
    qmsd_obj_set_id(button_ma_light,"button_ma_light");
}
    void qmsd_label_ma_music_create()
{
	label_ma_music = lv_label_create(screen_main, NULL);
	lv_label_set_long_mode(label_ma_music,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_ma_music,true);
	lv_obj_set_size(label_ma_music, 200, 26);
//set label style
	lv_obj_set_style_local_text_color(label_ma_music,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(label_ma_music, "音乐");
	lv_label_set_align(label_ma_music, LV_LABEL_ALIGN_LEFT);
	lv_obj_set_style_local_text_font(label_ma_music,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_22);
#ifdef BLOCKLY_label_ma_music_EVENT_HANDLER
	lv_obj_set_event_cb(label_ma_music, __qmsd_label_ma_music_cb);
#endif
	if(label_ma_music->coords.x2-label_ma_music->coords.x1<200)
	{
		int x_offset=(200-(label_ma_music->coords.x2-label_ma_music->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_ma_music,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_ma_music,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_ma_music->coords.y2-label_ma_music->coords.y1<26)
	{
		int y_offset=(26-(label_ma_music->coords.y2-label_ma_music->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_ma_music,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_ma_music,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
//! fix here
	// lv_obj_set_pos(label_ma_music, 43, 87);
    lv_obj_set_pos(label_ma_music, -40, 87);
    qmsd_obj_set_id(label_ma_music,"label_ma_music");
}
    
void qmsd_image_singer_create()
{
    image_singer = lv_img_create(screen_main, NULL);
    lv_img_set_src(image_singer, &imgimg_ma_singer_png);
#ifdef BLOCKLY_image_singer_EVENT_HANDLER
    lv_obj_set_event_cb(image_singer, __qmsd_image_singer_cb);
#endif
    lv_obj_set_pos(image_singer, 70, 142);
    qmsd_obj_set_id(image_singer,"image_singer");
}
    void qmsd_label_ma_singer_create()
{
	label_ma_singer = lv_label_create(screen_main, NULL);
	lv_label_set_long_mode(label_ma_singer,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_ma_singer,true);
	lv_obj_set_size(label_ma_singer, 118, 30);
//set label style
	lv_obj_set_style_local_text_color(label_ma_singer,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(label_ma_singer, "Havana");
	lv_label_set_align(label_ma_singer, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(label_ma_singer,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_24);
#ifdef BLOCKLY_label_ma_singer_EVENT_HANDLER
	lv_obj_set_event_cb(label_ma_singer, __qmsd_label_ma_singer_cb);
#endif
	if(label_ma_singer->coords.x2-label_ma_singer->coords.x1<118)
	{
		int x_offset=(118-(label_ma_singer->coords.x2-label_ma_singer->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_ma_singer,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_ma_singer,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_ma_singer->coords.y2-label_ma_singer->coords.y1<30)
	{
		int y_offset=(30-(label_ma_singer->coords.y2-label_ma_singer->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_ma_singer,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_ma_singer,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(label_ma_singer, 70, 270);
    qmsd_obj_set_id(label_ma_singer,"label_ma_singer");
}
    void qmsd_label_ma_song_create()
{
	label_ma_song = lv_label_create(screen_main, NULL);
	lv_label_set_long_mode(label_ma_song,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_ma_song,true);
	lv_obj_set_size(label_ma_song, 118, 13);
//set label style
	lv_obj_set_style_local_text_color(label_ma_song,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(label_ma_song, "Cabello feat Young");
	lv_label_set_align(label_ma_song, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(label_ma_song,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_10);
#ifdef BLOCKLY_label_ma_song_EVENT_HANDLER
	lv_obj_set_event_cb(label_ma_song, __qmsd_label_ma_song_cb);
#endif
	if(label_ma_song->coords.x2-label_ma_song->coords.x1<118)
	{
		int x_offset=(118-(label_ma_song->coords.x2-label_ma_song->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_ma_song,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_ma_song,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_ma_song->coords.y2-label_ma_song->coords.y1<13)
	{
		int y_offset=(13-(label_ma_song->coords.y2-label_ma_song->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_ma_song,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_ma_song,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(label_ma_song, 70, 300);
    qmsd_obj_set_id(label_ma_song,"label_ma_song");
}
    
void qmsd_image_ma_prev_create()
{
    image_ma_prev = lv_img_create(screen_main, NULL);
    lv_img_set_src(image_ma_prev, &imgma_prev_png);
#ifdef BLOCKLY_image_ma_prev_EVENT_HANDLER
    lv_obj_set_event_cb(image_ma_prev, __qmsd_image_ma_prev_cb);
#endif
    lv_obj_set_pos(image_ma_prev, 63, 354);
    qmsd_obj_set_id(image_ma_prev,"image_ma_prev");
}
    
void qmsd_image_ma_stop_create()
{
    image_ma_stop = lv_img_create(screen_main, NULL);
    lv_img_set_src(image_ma_stop, &imgma_stop_png);
#ifdef BLOCKLY_image_ma_stop_EVENT_HANDLER
    lv_obj_set_event_cb(image_ma_stop, __qmsd_image_ma_stop_cb);
#endif
    lv_obj_set_pos(image_ma_stop, 111, 343);
    qmsd_obj_set_id(image_ma_stop,"image_ma_stop");
}
    
void qmsd_image_ma_next_create()
{
    image_ma_next = lv_img_create(screen_main, NULL);
    lv_img_set_src(image_ma_next, &imgma_next_png);
#ifdef BLOCKLY_image_ma_next_EVENT_HANDLER
    lv_obj_set_event_cb(image_ma_next, __qmsd_image_ma_next_cb);
#endif
    lv_obj_set_pos(image_ma_next, 186, 355);
    qmsd_obj_set_id(image_ma_next,"image_ma_next");
}
    void qmsd_label_ma_windy_create()
{
	label_ma_windy = lv_label_create(screen_main, NULL);
	lv_label_set_long_mode(label_ma_windy,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_ma_windy,true);
	lv_obj_set_size(label_ma_windy, 100, 71);
//set label style
	lv_obj_set_style_local_text_color(label_ma_windy,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(label_ma_windy, "26");
	lv_label_set_align(label_ma_windy, LV_LABEL_ALIGN_LEFT);
	lv_obj_set_style_local_text_font(label_ma_windy,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_75);
#ifdef BLOCKLY_label_ma_windy_EVENT_HANDLER
	lv_obj_set_event_cb(label_ma_windy, __qmsd_label_ma_windy_cb);
#endif
	if(label_ma_windy->coords.x2-label_ma_windy->coords.x1<100)
	{
		int x_offset=(100-(label_ma_windy->coords.x2-label_ma_windy->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_ma_windy,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_ma_windy,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_ma_windy->coords.y2-label_ma_windy->coords.y1<71)
	{
		int y_offset=(71-(label_ma_windy->coords.y2-label_ma_windy->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_ma_windy,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_ma_windy,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	// lv_obj_set_pos(label_ma_windy, 281, 136);
    lv_obj_set_pos(label_ma_windy, 271, 136);
    qmsd_obj_set_id(label_ma_windy,"label_ma_windy");
}
    void qmsd_label_ma_centig_create()
{
	label_ma_centig = lv_label_create(screen_main, NULL);
	lv_label_set_long_mode(label_ma_centig,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_ma_centig,true);
	lv_obj_set_size(label_ma_centig, 20, 19);
//set label style
	lv_obj_set_style_local_text_color(label_ma_centig,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(label_ma_centig, "℃");
	lv_label_set_align(label_ma_centig, LV_LABEL_ALIGN_LEFT);
	lv_obj_set_style_local_text_font(label_ma_centig,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_22);
#ifdef BLOCKLY_label_ma_centig_EVENT_HANDLER
	lv_obj_set_event_cb(label_ma_centig, __qmsd_label_ma_centig_cb);
#endif
	if(label_ma_centig->coords.x2-label_ma_centig->coords.x1<20)
	{
		int x_offset=(20-(label_ma_centig->coords.x2-label_ma_centig->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_ma_centig,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_ma_centig,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_ma_centig->coords.y2-label_ma_centig->coords.y1<19)
	{
		int y_offset=(19-(label_ma_centig->coords.y2-label_ma_centig->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_ma_centig,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_ma_centig,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(label_ma_centig, 365, 148);
    qmsd_obj_set_id(label_ma_centig,"label_ma_centig");
}
    
void qmsd_image_ma_high_create()
{
    image_ma_high = lv_img_create(screen_main, NULL);
    lv_img_set_src(image_ma_high, &imgma_high_png);
//! add here 增加点击区域
    lv_obj_set_ext_click_area(image_ma_high,40,5,40,40);
#ifdef BLOCKLY_image_ma_high_EVENT_HANDLER
    lv_obj_set_event_cb(image_ma_high, __qmsd_image_ma_high_cb);
#endif
    lv_obj_set_pos(image_ma_high, 280, 240);
    lv_obj_set_click(image_ma_high,true);
    lv_obj_set_style_local_image_recolor(image_ma_high,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(image_ma_high,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    qmsd_obj_set_id(image_ma_high,"image_ma_high");
}
    
void qmsd_image_ma_low_create()
{
    image_ma_low = lv_img_create(screen_main, NULL);
    lv_img_set_src(image_ma_low, &imgma_low_png);
//! add here 增加点击区域
    lv_obj_set_ext_click_area(image_ma_low,5,40,40,40);
#ifdef BLOCKLY_image_ma_low_EVENT_HANDLER
    lv_obj_set_event_cb(image_ma_low, __qmsd_image_ma_low_cb);
#endif
    lv_obj_set_pos(image_ma_low, 329, 240);
    lv_obj_set_click(image_ma_low,true);
    lv_obj_set_style_local_image_recolor(image_ma_low,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(image_ma_low,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    qmsd_obj_set_id(image_ma_low,"image_ma_low");
}
    
void qmsd_image_ma_light_create()
{
    image_ma_light = lv_img_create(screen_main, NULL);
    lv_img_set_src(image_ma_light, &imgma_light_png);
#ifdef BLOCKLY_image_ma_light_EVENT_HANDLER
    lv_obj_set_event_cb(image_ma_light, __qmsd_image_ma_light_cb);
#endif
    lv_obj_set_pos(image_ma_light, 272, 333);
    qmsd_obj_set_id(image_ma_light,"image_ma_light");
}
    void qmsd_label_ma_light_create()
{
	label_ma_light = lv_label_create(screen_main, NULL);
	lv_label_set_long_mode(label_ma_light,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_ma_light,true);
	lv_obj_set_size(label_ma_light, 42, 33);
//set label style
	lv_obj_set_style_local_text_color(label_ma_light,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(label_ma_light, "灯光");
	lv_label_set_align(label_ma_light, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(label_ma_light,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_19);
#ifdef BLOCKLY_label_ma_light_EVENT_HANDLER
	lv_obj_set_event_cb(label_ma_light, __qmsd_label_ma_light_cb);
#endif
	if(label_ma_light->coords.x2-label_ma_light->coords.x1<42)
	{
		int x_offset=(42-(label_ma_light->coords.x2-label_ma_light->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_ma_light,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_ma_light,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_ma_light->coords.y2-label_ma_light->coords.y1<33)
	{
		int y_offset=(33-(label_ma_light->coords.y2-label_ma_light->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_ma_light,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_ma_light,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(label_ma_light, 324, 322);
    qmsd_obj_set_id(label_ma_light,"label_ma_light");
}
    void qmsd_switch_ma_create()
{
    switch_ma = lv_switch_create(screen_main, NULL);
    lv_obj_set_size(switch_ma, 50, 32);
    lv_obj_set_pos(switch_ma, 395, 342);
    if(0 == 0) {
    lv_switch_off(switch_ma, LV_ANIM_OFF);
    } else {
    lv_switch_on(switch_ma, LV_ANIM_OFF);
    }
//! add here 增加点击区域
    lv_obj_set_ext_click_area(switch_ma,20,40,40,40);
    //set switch bg style
    lv_obj_set_style_local_bg_color(switch_ma,LV_SWITCH_PART_BG,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x9b, 0x9b, 0x9b));
    lv_obj_set_style_local_bg_grad_color(switch_ma,LV_SWITCH_PART_BG,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x9b, 0x9b, 0x9b));
    lv_obj_set_style_local_pad_top(switch_ma,LV_SWITCH_PART_BG,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_pad_bottom(switch_ma,LV_SWITCH_PART_BG,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_pad_left(switch_ma,LV_SWITCH_PART_BG,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_pad_right(switch_ma,LV_SWITCH_PART_BG,LV_STATE_DEFAULT,0);
    //set switch indic style
    lv_obj_set_style_local_bg_color(switch_ma,LV_SWITCH_PART_INDIC,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xf8, 0xe7, 0x1c));
    lv_obj_set_style_local_bg_grad_color(switch_ma,LV_SWITCH_PART_INDIC,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xf8, 0xe7, 0x1c));
    lv_obj_set_style_local_radius(switch_ma,LV_SWITCH_PART_INDIC,LV_STATE_DEFAULT,LV_RADIUS_CIRCLE);
    lv_obj_set_style_local_pad_top(switch_ma,LV_SWITCH_PART_INDIC,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_pad_bottom(switch_ma,LV_SWITCH_PART_INDIC,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_pad_left(switch_ma,LV_SWITCH_PART_INDIC,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_pad_right(switch_ma,LV_SWITCH_PART_INDIC,LV_STATE_DEFAULT,0);
    //set switch knob style
    lv_obj_set_style_local_radius(switch_ma,LV_SWITCH_PART_KNOB,LV_STATE_DEFAULT,LV_RADIUS_CIRCLE);

    lv_obj_set_style_local_border_opa(switch_ma, LV_SWITCH_PART_BG, LV_STATE_DEFAULT, 0);
    lv_obj_set_style_local_border_opa(switch_ma, LV_SWITCH_PART_BG, LV_STATE_FOCUSED, 0);
    lv_obj_set_style_local_outline_width(switch_ma, LV_SWITCH_PART_BG, LV_STATE_DEFAULT, 0);
    lv_obj_set_style_local_outline_width(switch_ma, LV_SWITCH_PART_BG, LV_STATE_FOCUSED, 0);
#ifdef BLOCKLY_switch_ma_EVENT_HANDLER
    lv_obj_set_event_cb(switch_ma, __qmsd_switch_ma_cb);
#endif
    qmsd_obj_set_id(switch_ma,"switch_ma");
}
    void qmsd_button_ma_bott_create()
{
    button_ma_bott = lv_btn_create(screen_main, NULL);
    __button_ma_bott_label = lv_label_create(button_ma_bott, NULL);
    lv_label_set_text(__button_ma_bott_label,qmsd_lang_get_trans("button_ma_bott",""));

    lv_obj_set_style_local_text_font(__button_ma_bott_label,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_16);
    lv_obj_set_size(button_ma_bott, 52, 20);
    lv_obj_set_pos(button_ma_bott, 322, 360);
#ifdef BLOCKLY_button_ma_bott_EVENT_HANDLER
    lv_obj_set_event_cb(button_ma_bott, __qmsd_button_ma_bott_cb);
#endif


    lv_obj_t* obj = button_ma_bott;
    int part = LV_BTN_PART_MAIN;
//设置正常样式
        lv_obj_set_style_local_bg_color(obj,part,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x9b, 0x9b, 0x9b));
    lv_obj_set_style_local_radius(obj,part,LV_STATE_DEFAULT,9);
    lv_obj_set_style_local_bg_opa(obj,part,LV_STATE_DEFAULT,111);
    lv_obj_set_style_local_border_opa(obj,part,LV_STATE_DEFAULT,18);
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
    lv_obj_set_style_local_outline_width(button_ma_bott,LV_BTN_PART_MAIN,LV_STATE_DEFAULT,0);
	lv_obj_set_style_local_outline_width(button_ma_bott,LV_BTN_PART_MAIN,LV_STATE_FOCUSED,0);
    qmsd_obj_set_id(button_ma_bott,"button_ma_bott");
}
    void qmsd_label_ma_label_create()
{
	label_ma_label = lv_label_create(screen_main, NULL);
	lv_label_set_long_mode(label_ma_label,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_ma_label,true);
	lv_obj_set_size(label_ma_label, 12, 12);
//set label style
	lv_obj_set_style_local_text_color(label_ma_label,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(label_ma_label, "开");
	lv_label_set_align(label_ma_label, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(label_ma_label,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_10);
#ifdef BLOCKLY_label_ma_label_EVENT_HANDLER
	lv_obj_set_event_cb(label_ma_label, __qmsd_label_ma_label_cb);
#endif
	if(label_ma_label->coords.x2-label_ma_label->coords.x1<12)
	{
		int x_offset=(12-(label_ma_label->coords.x2-label_ma_label->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_ma_label,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_ma_label,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_ma_label->coords.y2-label_ma_label->coords.y1<12)
	{
		int y_offset=(12-(label_ma_label->coords.y2-label_ma_label->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_ma_label,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_ma_label,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(label_ma_label, 353, 364);
    qmsd_obj_set_id(label_ma_label,"label_ma_label");
}
    
void qmsd_image_ma_sun_create()
{
    image_ma_sun = lv_img_create(screen_main, NULL);
    lv_img_set_src(image_ma_sun, &imgma_sun_png);
#ifdef BLOCKLY_image_ma_sun_EVENT_HANDLER
    lv_obj_set_event_cb(image_ma_sun, __qmsd_image_ma_sun_cb);
#endif
    lv_obj_set_pos(image_ma_sun, 27, 424);
    qmsd_obj_set_id(image_ma_sun,"image_ma_sun");
}
    void qmsd_label_ma_sun_create()
{
	label_ma_sun = lv_label_create(screen_main, NULL);
	lv_label_set_long_mode(label_ma_sun,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_ma_sun,true);
	lv_obj_set_size(label_ma_sun, 50, 20);
//set label style
	lv_obj_set_style_local_text_color(label_ma_sun,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(label_ma_sun, "25");
	lv_label_set_align(label_ma_sun, LV_LABEL_ALIGN_LEFT);
	lv_obj_set_style_local_text_font(label_ma_sun,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_26);
#ifdef BLOCKLY_label_ma_sun_EVENT_HANDLER
	lv_obj_set_event_cb(label_ma_sun, __qmsd_label_ma_sun_cb);
#endif
	if(label_ma_sun->coords.x2-label_ma_sun->coords.x1<50)
	{
		int x_offset=(50-(label_ma_sun->coords.x2-label_ma_sun->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_ma_sun,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_ma_sun,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_ma_sun->coords.y2-label_ma_sun->coords.y1<20)
	{
		int y_offset=(20-(label_ma_sun->coords.y2-label_ma_sun->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_ma_sun,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_ma_sun,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	// lv_obj_set_pos(label_ma_sun, 68, 430);
    lv_obj_set_pos(label_ma_sun, 48, 430);
    qmsd_obj_set_id(label_ma_sun,"label_ma_sun");
}
    void qmsd_label_ma_sun_c_create()
{
	label_ma_sun_c = lv_label_create(screen_main, NULL);
	lv_label_set_long_mode(label_ma_sun_c,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_ma_sun_c,true);
	lv_obj_set_size(label_ma_sun_c, 100, 15);
//set label style
	lv_obj_set_style_local_text_color(label_ma_sun_c,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(label_ma_sun_c, "℃");
	lv_label_set_align(label_ma_sun_c, LV_LABEL_ALIGN_LEFT);
	lv_obj_set_style_local_text_font(label_ma_sun_c,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_16);
#ifdef BLOCKLY_label_ma_sun_c_EVENT_HANDLER
	lv_obj_set_event_cb(label_ma_sun_c, __qmsd_label_ma_sun_c_cb);
#endif
	if(label_ma_sun_c->coords.x2-label_ma_sun_c->coords.x1<100)
	{
		int x_offset=(100-(label_ma_sun_c->coords.x2-label_ma_sun_c->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_ma_sun_c,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_ma_sun_c,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_ma_sun_c->coords.y2-label_ma_sun_c->coords.y1<15)
	{
		int y_offset=(15-(label_ma_sun_c->coords.y2-label_ma_sun_c->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_ma_sun_c,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_ma_sun_c,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	// lv_obj_set_pos(label_ma_sun_c, 95, 430);
    lv_obj_set_pos(label_ma_sun_c, 45, 430);
    qmsd_obj_set_id(label_ma_sun_c,"label_ma_sun_c");
}
    void qmsd_label_ma_morn_create()
{
	label_ma_morn = lv_label_create(screen_main, NULL);
	lv_label_set_long_mode(label_ma_morn,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_ma_morn,true);
	lv_obj_set_size(label_ma_morn, 150, 25);
//set label style
	lv_obj_set_style_local_text_color(label_ma_morn,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(label_ma_morn, "早上好!");
	lv_label_set_align(label_ma_morn, LV_LABEL_ALIGN_LEFT);
	lv_obj_set_style_local_text_font(label_ma_morn,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_26);
#ifdef BLOCKLY_label_ma_morn_EVENT_HANDLER
	lv_obj_set_event_cb(label_ma_morn, __qmsd_label_ma_morn_cb);
#endif
	if(label_ma_morn->coords.x2-label_ma_morn->coords.x1<150)
	{
		int x_offset=(150-(label_ma_morn->coords.x2-label_ma_morn->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_ma_morn,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_ma_morn,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_ma_morn->coords.y2-label_ma_morn->coords.y1<25)
	{
		int y_offset=(25-(label_ma_morn->coords.y2-label_ma_morn->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_ma_morn,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_ma_morn,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	// lv_obj_set_pos(label_ma_morn, 304, 430);
    lv_obj_set_pos(label_ma_morn, 294, 430);
    qmsd_obj_set_id(label_ma_morn,"label_ma_morn");
}
    
void qmsd_image_ma_smile_create()
{
    image_ma_smile = lv_img_create(screen_main, NULL);
    lv_img_set_src(image_ma_smile, &imgma_smile_png);
#ifdef BLOCKLY_image_ma_smile_EVENT_HANDLER
    lv_obj_set_event_cb(image_ma_smile, __qmsd_image_ma_smile_cb);
#endif
    lv_obj_set_pos(image_ma_smile, 416, 426);
    qmsd_obj_set_id(image_ma_smile,"image_ma_smile");
}
    void qmsd_slider_ma_create()
{
	slider_ma = lv_slider_create(screen_main, NULL);
	lv_obj_set_size(slider_ma, 156, 3);
    lv_obj_set_pos(slider_ma, 51, 322);
	lv_slider_set_value(slider_ma, 36, LV_ANIM_OFF);

	//set slider bg style
	lv_obj_set_style_local_bg_color(slider_ma,LV_SLIDER_PART_BG,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x9b, 0x9b, 0x9b));
	lv_obj_set_style_local_bg_grad_color(slider_ma,LV_SLIDER_PART_BG,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x9b, 0x9b, 0x9b));
	lv_obj_set_style_local_border_color(slider_ma,LV_SLIDER_PART_BG,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x9b, 0x9b, 0x9b));
	lv_obj_set_style_local_radius(slider_ma,LV_SLIDER_PART_BG,LV_STATE_DEFAULT,LV_RADIUS_CIRCLE);

	//set slider indic style
    lv_obj_set_style_local_bg_color(slider_ma,LV_SLIDER_PART_INDIC,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
	lv_obj_set_style_local_bg_grad_color(slider_ma,LV_SLIDER_PART_INDIC,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
	lv_obj_set_style_local_radius(slider_ma,LV_SLIDER_PART_INDIC,LV_STATE_DEFAULT,LV_RADIUS_CIRCLE);
    lv_obj_set_style_local_shadow_color(slider_ma,LV_SLIDER_PART_INDIC,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
	lv_obj_set_style_local_shadow_width(slider_ma,LV_SLIDER_PART_INDIC,LV_STATE_DEFAULT,5);

	//set slider knob style
    lv_obj_set_style_local_bg_color(slider_ma,LV_SLIDER_PART_KNOB,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
	lv_obj_set_style_local_bg_grad_color(slider_ma,LV_SLIDER_PART_KNOB,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
	lv_obj_set_style_local_radius(slider_ma,LV_SLIDER_PART_KNOB,LV_STATE_DEFAULT,LV_RADIUS_CIRCLE);
//! fix here
    lv_obj_set_style_local_bg_opa(slider_ma,LV_SLIDER_PART_KNOB,LV_STATE_DEFAULT,LV_OPA_100);

	lv_obj_set_style_local_outline_width(slider_ma,LV_SLIDER_PART_BG,LV_STATE_DEFAULT,0);
	lv_obj_set_style_local_outline_width(slider_ma,LV_SLIDER_PART_BG,LV_STATE_FOCUSED,0);
#ifdef BLOCKLY_slider_ma_EVENT_HANDLER
	lv_obj_set_event_cb(slider_ma, __qmsd_slider_ma_cb);
#endif
    qmsd_obj_set_id(slider_ma,"slider_ma");
}
    void qmsd_button_ma_color_create()
{
    button_ma_color = lv_btn_create(screen_main, NULL);
    __button_ma_color_label = lv_label_create(button_ma_color, NULL);
    lv_label_set_text(__button_ma_color_label,qmsd_lang_get_trans("button_ma_color",""));

    lv_obj_set_style_local_text_font(__button_ma_color_label,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_16);
    lv_obj_set_size(button_ma_color, 10, 10);
    lv_obj_set_pos(button_ma_color, 329, 365);
#ifdef BLOCKLY_button_ma_color_EVENT_HANDLER
    lv_obj_set_event_cb(button_ma_color, __qmsd_button_ma_color_cb);
#endif


    lv_obj_t* obj = button_ma_color;
    int part = LV_BTN_PART_MAIN;
//设置正常样式
    lv_obj_set_style_local_bg_color(obj,part,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xf8, 0xe7, 0x1c));
    lv_obj_set_style_local_radius(obj,part,LV_STATE_DEFAULT,10);
    lv_obj_set_style_local_border_opa(obj,part,LV_STATE_DEFAULT,20);
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
    lv_obj_set_style_local_outline_width(button_ma_color,LV_BTN_PART_MAIN,LV_STATE_DEFAULT,0);
	lv_obj_set_style_local_outline_width(button_ma_color,LV_BTN_PART_MAIN,LV_STATE_FOCUSED,0);
    qmsd_obj_set_id(button_ma_color,"button_ma_color");
}
    void qmsd_label_ma_temper_create()
{
	label_ma_temper = lv_label_create(screen_main, NULL);
	lv_label_set_long_mode(label_ma_temper,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_ma_temper,true);
	lv_obj_set_size(label_ma_temper, 172, 26);
//set label style
	lv_obj_set_style_local_text_color(label_ma_temper,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(label_ma_temper, "温控器");
	lv_label_set_align(label_ma_temper, LV_LABEL_ALIGN_LEFT);
	lv_obj_set_style_local_text_font(label_ma_temper,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_22);
#ifdef BLOCKLY_label_ma_temper_EVENT_HANDLER
	lv_obj_set_event_cb(label_ma_temper, __qmsd_label_ma_temper_cb);
#endif
	if(label_ma_temper->coords.x2-label_ma_temper->coords.x1<172)
	{
		int x_offset=(172-(label_ma_temper->coords.x2-label_ma_temper->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_ma_temper,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_ma_temper,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_ma_temper->coords.y2-label_ma_temper->coords.y1<26)
	{
		int y_offset=(26-(label_ma_temper->coords.y2-label_ma_temper->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_ma_temper,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_ma_temper,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	// lv_obj_set_pos(label_ma_temper, 274, 87);
    lv_obj_set_pos(label_ma_temper, 214, 87);
    qmsd_obj_set_id(label_ma_temper,"label_ma_temper");
}
    void qmsd_button_ma_barbt_create()
{
    button_ma_barbt = lv_btn_create(screen_main, NULL);
    __button_ma_barbt_label = lv_label_create(button_ma_barbt, NULL);
    lv_label_set_text(__button_ma_barbt_label,qmsd_lang_get_trans("button_ma_barbt",""));

    lv_obj_set_style_local_text_font(__button_ma_barbt_label,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_16);
    lv_obj_set_size(button_ma_barbt, 36, 124);
    lv_obj_set_pos(button_ma_barbt, 405, 146);
#ifdef BLOCKLY_button_ma_barbt_EVENT_HANDLER
    lv_obj_set_event_cb(button_ma_barbt, __qmsd_button_ma_barbt_cb);
#endif


    lv_obj_t* obj = button_ma_barbt;
    int part = LV_BTN_PART_MAIN;
//设置正常样式
        lv_obj_set_style_local_radius(obj,part,LV_STATE_DEFAULT,10);
    lv_obj_set_style_local_bg_opa(obj,part,LV_STATE_DEFAULT,58);
    lv_obj_set_style_local_border_opa(obj,part,LV_STATE_DEFAULT,0);
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
    lv_obj_set_style_local_outline_width(button_ma_barbt,LV_BTN_PART_MAIN,LV_STATE_DEFAULT,0);
	lv_obj_set_style_local_outline_width(button_ma_barbt,LV_BTN_PART_MAIN,LV_STATE_FOCUSED,0);
    qmsd_obj_set_id(button_ma_barbt,"button_ma_barbt");
}
    void qmsd_button_ma_barra_create()
{
    button_ma_barra = lv_btn_create(screen_main, NULL);
    __button_ma_barra_label = lv_label_create(button_ma_barra, NULL);
    lv_label_set_text(__button_ma_barra_label,qmsd_lang_get_trans("button_ma_barra",""));

    lv_obj_set_style_local_text_font(__button_ma_barra_label,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_16);
    lv_obj_set_size(button_ma_barra, 36, 70);
    lv_obj_set_pos(button_ma_barra, 405, 200);
#ifdef BLOCKLY_button_ma_barra_EVENT_HANDLER
    lv_obj_set_event_cb(button_ma_barra, __qmsd_button_ma_barra_cb);
#endif


    lv_obj_t* obj = button_ma_barra;
    int part = LV_BTN_PART_MAIN;
//设置正常样式
        lv_obj_set_style_local_bg_color(obj,part,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x50, 0xe3, 0xc2));
    lv_obj_set_style_local_radius(obj,part,LV_STATE_DEFAULT,10);
    lv_obj_set_style_local_border_opa(obj,part,LV_STATE_DEFAULT,0);
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
    lv_obj_set_style_local_outline_width(button_ma_barra,LV_BTN_PART_MAIN,LV_STATE_DEFAULT,0);
	lv_obj_set_style_local_outline_width(button_ma_barra,LV_BTN_PART_MAIN,LV_STATE_FOCUSED,0);
    qmsd_obj_set_id(button_ma_barra,"button_ma_barra");
}
    
void qmsd_image_ma_fan_create()
{
    image_ma_fan = lv_img_create(screen_main, NULL);
    lv_img_set_src(image_ma_fan, &imgma_fan_png);
#ifdef BLOCKLY_image_ma_fan_EVENT_HANDLER
    lv_obj_set_event_cb(image_ma_fan, __qmsd_image_ma_fan_cb);
#endif
    lv_obj_set_pos(image_ma_fan, 415, 155);
    qmsd_obj_set_id(image_ma_fan,"image_ma_fan");
}

static void screen_main_qmsd_cb(lv_obj_t * obj, lv_event_t event, void *data)
{/*
    char *trans;
    lv_label_set_text(label_main_time,qmsd_lang_get_trans("label_main_time","10:50"));
    lv_label_set_text(label_main_day,qmsd_lang_get_trans("label_main_day","PM"));
    lv_label_set_text(__button_ma_music_label,qmsd_lang_get_trans("button_ma_music",""));
    lv_label_set_text(__button_ma_tem_label,qmsd_lang_get_trans("button_ma_tem",""));
    lv_label_set_text(__button_ma_light_label,qmsd_lang_get_trans("button_ma_light",""));
    lv_label_set_text(label_ma_music,qmsd_lang_get_trans("label_ma_music","音乐"));
    lv_label_set_text(label_ma_singer,qmsd_lang_get_trans("label_ma_singer","Havana"));
    lv_label_set_text(label_ma_song,qmsd_lang_get_trans("label_ma_song","Cabello feat Young"));
    lv_label_set_text(label_ma_windy,qmsd_lang_get_trans("label_ma_windy","26"));
    lv_label_set_text(label_ma_centig,qmsd_lang_get_trans("label_ma_centig","℃"));
    lv_label_set_text(label_ma_light,qmsd_lang_get_trans("label_ma_light","灯光"));
    lv_label_set_text(__button_ma_bott_label,qmsd_lang_get_trans("button_ma_bott",""));
    lv_label_set_text(label_ma_label,qmsd_lang_get_trans("label_ma_label","开"));
    lv_label_set_text(label_ma_sun,qmsd_lang_get_trans("label_ma_sun","25"));
    lv_label_set_text(label_ma_sun_c,qmsd_lang_get_trans("label_ma_sun_c","℃"));
    lv_label_set_text(label_ma_morn,qmsd_lang_get_trans("label_ma_morn","早上好!"));
    lv_label_set_text(__button_ma_color_label,qmsd_lang_get_trans("button_ma_color",""));
    lv_label_set_text(label_ma_temper,qmsd_lang_get_trans("label_ma_temper","温控器"));
    lv_label_set_text(__button_ma_barbt_label,qmsd_lang_get_trans("button_ma_barbt",""));
    lv_label_set_text(__button_ma_barra_label,qmsd_lang_get_trans("button_ma_barra",""));
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
    printf("===4===\n");
    if(screen_main) return;
    screen_main = lv_obj_create(NULL, NULL);
    lv_obj_qmsd_set_cb(screen_main, screen_main_qmsd_cb);
    lv_obj_set_style_local_bg_color(screen_main,LV_OBJ_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x31, 0x04, 0x58));

    qmsd_label_main_time_create();
    qmsd_label_main_day_create();
    qmsd_image_main_wifi_create();
    qmsd_image_buletooth_create();
    qmsd_button_ma_music_create();
    qmsd_button_ma_tem_create();
    qmsd_button_ma_light_create();
    qmsd_label_ma_music_create();
    qmsd_image_singer_create();
    qmsd_label_ma_singer_create();
    qmsd_label_ma_song_create();
    qmsd_image_ma_prev_create();
    qmsd_image_ma_stop_create();
    qmsd_image_ma_next_create();
    qmsd_label_ma_windy_create();
    qmsd_label_ma_centig_create();
    qmsd_image_ma_high_create();
    qmsd_image_ma_low_create();
    qmsd_image_ma_light_create();
    qmsd_label_ma_light_create();
    qmsd_switch_ma_create();
    qmsd_button_ma_bott_create();
    qmsd_label_ma_label_create();
    qmsd_image_ma_sun_create();
    qmsd_label_ma_sun_create();
    qmsd_label_ma_sun_c_create();
    qmsd_label_ma_morn_create();
    qmsd_image_ma_smile_create();
    qmsd_slider_ma_create();
    qmsd_button_ma_color_create();
    qmsd_label_ma_temper_create();
    qmsd_button_ma_barbt_create();
    qmsd_button_ma_barra_create();
    qmsd_image_ma_fan_create();
    qmsd_label_main_min_create();

    qmsd_line_ma_music_create();
    qmsd_line_ma_te_create();

    //======================
    get_point = lv_indev_get_next(NULL);
    for(; (int)my_sign_main < 0;) {        
        num = lv_indev_get_type((const lv_indev_t*)get_point);
        if(num != LV_INDEV_TYPE_POINTER) {
        get_point = lv_indev_get_next(get_point);
        my_sign_main = true;
        }
    }
    _lv_indev_read(get_point, &my_data);
    //======================
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
