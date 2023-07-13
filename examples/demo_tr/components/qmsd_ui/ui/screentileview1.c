#include "qmsd_ui_entry.h"
#include "qmsd_internal_ui_cb.h"

lv_obj_t* screentileview1;
lv_obj_t* lab_tile1_time;
lv_obj_t* lab_tile1_data;
lv_obj_t* lab_tile1_week;
lv_obj_t* ima_tile1_wea;
lv_obj_t* lab_tile1_tem;
lv_obj_t* lab_tile1_com;
lv_obj_t* but_tile1_bot;
lv_obj_t * __but_tile1_bot_label;
lv_obj_t* ima_tile1_hum;
lv_obj_t* lab_tile1_hum;
lv_obj_t* lab_tile1_hum_;
lv_obj_t* lab_tile1_humc;
lv_obj_t* ima_tile1_air;
lv_obj_t* lab_tile1_air;
lv_obj_t* lab_tile1_air_;
lv_obj_t* ima_tile1_le;
lv_obj_t* ima_tile1_mi;
lv_obj_t* ima_tile1_ri;
lv_obj_t* ima_tile1_le_;
lv_obj_t* lab_tile1_le;
lv_obj_t* ima_tile1_mi_;
lv_obj_t* lab_tile1_mi;
lv_obj_t* ima_tile1_ri_;
lv_obj_t* lab_tile1_ri;
lv_obj_t* lab_tile1_hour;
lv_obj_t* lab_tile1_min;


    void qmsd_lab_tile1_time_create()
{
	lab_tile1_time = lv_label_create(screentileview1, NULL);
	lv_label_set_long_mode(lab_tile1_time,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(lab_tile1_time,true);
	lv_obj_set_size(lab_tile1_time, 10, 76);
//set label style
	lv_obj_set_style_local_text_color(lab_tile1_time,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(lab_tile1_time, ":");
	lv_label_set_align(lab_tile1_time, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(lab_tile1_time,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_104);
#ifdef BLOCKLY_lab_tile1_time_EVENT_HANDLER
	lv_obj_set_event_cb(lab_tile1_time, __qmsd_lab_tile1_time_cb);
#endif
	if(lab_tile1_time->coords.x2-lab_tile1_time->coords.x1<10)
	{
		int x_offset=(10-(lab_tile1_time->coords.x2-lab_tile1_time->coords.x1))/2;
		lv_obj_set_style_local_pad_left(lab_tile1_time,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(lab_tile1_time,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(lab_tile1_time->coords.y2-lab_tile1_time->coords.y1<76)
	{
		int y_offset=(76-(lab_tile1_time->coords.y2-lab_tile1_time->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(lab_tile1_time,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(lab_tile1_time,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(lab_tile1_time, 164, 78);
    qmsd_obj_set_id(lab_tile1_time,"lab_tile1_time");
}
    void qmsd_lab_tile1_data_create()
{
	lab_tile1_data = lv_label_create(screentileview1, NULL);
	lv_label_set_long_mode(lab_tile1_data,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(lab_tile1_data,true);
	lv_obj_set_size(lab_tile1_data, 120, 23);
//set label style
	lv_obj_set_style_local_text_color(lab_tile1_data,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(lab_tile1_data, "8月12日");
	lv_label_set_align(lab_tile1_data, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(lab_tile1_data,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_32);
#ifdef BLOCKLY_lab_tile1_data_EVENT_HANDLER
	lv_obj_set_event_cb(lab_tile1_data, __qmsd_lab_tile1_data_cb);
#endif
	if(lab_tile1_data->coords.x2-lab_tile1_data->coords.x1<120)
	{
		int x_offset=(120-(lab_tile1_data->coords.x2-lab_tile1_data->coords.x1))/2;
		lv_obj_set_style_local_pad_left(lab_tile1_data,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(lab_tile1_data,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(lab_tile1_data->coords.y2-lab_tile1_data->coords.y1<23)
	{
		int y_offset=(23-(lab_tile1_data->coords.y2-lab_tile1_data->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(lab_tile1_data,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(lab_tile1_data,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(lab_tile1_data, 57, 178);
    qmsd_obj_set_id(lab_tile1_data,"lab_tile1_data");
}
    void qmsd_lab_tile1_week_create()
{
	lab_tile1_week = lv_label_create(screentileview1, NULL);
	lv_label_set_long_mode(lab_tile1_week,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(lab_tile1_week,true);
	lv_obj_set_size(lab_tile1_week, 90, 23);
//set label style
	lv_obj_set_style_local_text_color(lab_tile1_week,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(lab_tile1_week, "星期二");
	lv_label_set_align(lab_tile1_week, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(lab_tile1_week,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_24);
#ifdef BLOCKLY_lab_tile1_week_EVENT_HANDLER
	lv_obj_set_event_cb(lab_tile1_week, __qmsd_lab_tile1_week_cb);
#endif
	if(lab_tile1_week->coords.x2-lab_tile1_week->coords.x1<90)
	{
		int x_offset=(90-(lab_tile1_week->coords.x2-lab_tile1_week->coords.x1))/2;
		lv_obj_set_style_local_pad_left(lab_tile1_week,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(lab_tile1_week,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(lab_tile1_week->coords.y2-lab_tile1_week->coords.y1<23)
	{
		int y_offset=(23-(lab_tile1_week->coords.y2-lab_tile1_week->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(lab_tile1_week,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(lab_tile1_week,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(lab_tile1_week, 201, 178);
    qmsd_obj_set_id(lab_tile1_week,"lab_tile1_week");
}
    
void qmsd_ima_tile1_wea_create()
{
    ima_tile1_wea = lv_img_create(screentileview1, NULL);
    lv_img_set_src(ima_tile1_wea, &imgweather_png);
#ifdef BLOCKLY_ima_tile1_wea_EVENT_HANDLER
    lv_obj_set_event_cb(ima_tile1_wea, __qmsd_ima_tile1_wea_cb);
#endif
    lv_obj_set_pos(ima_tile1_wea, 353, 79);
    qmsd_obj_set_id(ima_tile1_wea,"ima_tile1_wea");
}
    void qmsd_lab_tile1_tem_create()
{
	lab_tile1_tem = lv_label_create(screentileview1, NULL);
	lv_label_set_long_mode(lab_tile1_tem,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(lab_tile1_tem,true);
	lv_obj_set_size(lab_tile1_tem, 29, 21);
//set label style
	lv_obj_set_style_local_text_color(lab_tile1_tem,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(lab_tile1_tem, "00");
	lv_label_set_align(lab_tile1_tem, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(lab_tile1_tem,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_30);
#ifdef BLOCKLY_lab_tile1_tem_EVENT_HANDLER
	lv_obj_set_event_cb(lab_tile1_tem, __qmsd_lab_tile1_tem_cb);
#endif
	if(lab_tile1_tem->coords.x2-lab_tile1_tem->coords.x1<29)
	{
		int x_offset=(29-(lab_tile1_tem->coords.x2-lab_tile1_tem->coords.x1))/2;
		lv_obj_set_style_local_pad_left(lab_tile1_tem,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(lab_tile1_tem,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(lab_tile1_tem->coords.y2-lab_tile1_tem->coords.y1<21)
	{
		int y_offset=(21-(lab_tile1_tem->coords.y2-lab_tile1_tem->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(lab_tile1_tem,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(lab_tile1_tem,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(lab_tile1_tem, 372, 141);
    qmsd_obj_set_id(lab_tile1_tem,"lab_tile1_tem");
}
    void qmsd_lab_tile1_com_create()
{
	lab_tile1_com = lv_label_create(screentileview1, NULL);
	lv_label_set_long_mode(lab_tile1_com,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(lab_tile1_com,true);
	lv_obj_set_size(lab_tile1_com, 7, 7);
//set label style
	lv_obj_set_style_local_text_color(lab_tile1_com,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(lab_tile1_com, "℃");
	lv_label_set_align(lab_tile1_com, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(lab_tile1_com,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_16);
#ifdef BLOCKLY_lab_tile1_com_EVENT_HANDLER
	lv_obj_set_event_cb(lab_tile1_com, __qmsd_lab_tile1_com_cb);
#endif
	if(lab_tile1_com->coords.x2-lab_tile1_com->coords.x1<7)
	{
		int x_offset=(7-(lab_tile1_com->coords.x2-lab_tile1_com->coords.x1))/2;
		lv_obj_set_style_local_pad_left(lab_tile1_com,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(lab_tile1_com,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(lab_tile1_com->coords.y2-lab_tile1_com->coords.y1<7)
	{
		int y_offset=(7-(lab_tile1_com->coords.y2-lab_tile1_com->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(lab_tile1_com,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(lab_tile1_com,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(lab_tile1_com, 405, 141);
    qmsd_obj_set_id(lab_tile1_com,"lab_tile1_com");
}
    void qmsd_but_tile1_bot_create()
{
    but_tile1_bot = lv_btn_create(screentileview1, NULL);
    __but_tile1_bot_label = lv_label_create(but_tile1_bot, NULL);
    lv_label_set_text(__but_tile1_bot_label,qmsd_lang_get_trans("but_tile1_bot",""));

    lv_obj_set_style_local_text_font(__but_tile1_bot_label,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_16);
    lv_obj_set_size(but_tile1_bot, 293, 35);
    lv_obj_set_pos(but_tile1_bot, 48, 242);
#ifdef BLOCKLY_but_tile1_bot_EVENT_HANDLER
    lv_obj_set_event_cb(but_tile1_bot, __qmsd_but_tile1_bot_cb);
#endif


    lv_obj_t* obj = but_tile1_bot;
    int part = LV_BTN_PART_MAIN;
//设置正常样式
        lv_obj_set_style_local_bg_color(obj,part,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x00, 0x00, 0x00));
    lv_obj_set_style_local_bg_grad_color(obj,part,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x00, 0x00, 0x00));
    lv_obj_set_style_local_radius(obj,part,LV_STATE_DEFAULT,17);
    lv_obj_set_style_local_bg_opa(obj,part,LV_STATE_DEFAULT,204);
    lv_obj_set_style_local_border_color(obj,part,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
    lv_obj_set_style_local_border_opa(obj,part,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_shadow_width(obj,part,LV_STATE_DEFAULT,0);

//设置正常样式结束

//设置按下样式
        lv_obj_set_style_local_radius(obj,part,LV_STATE_PRESSED,0);
    lv_obj_set_style_local_border_color(obj,part,LV_STATE_PRESSED,LV_COLOR_MAKE(0xff, 0xff, 0xff));

//设置按下样式结束

//设置禁用样式
        lv_obj_set_style_local_border_color(obj,part,LV_STATE_DISABLED,LV_COLOR_MAKE(0xff, 0xff, 0xff));

//设置禁用样式结束
    lv_obj_set_style_local_outline_width(but_tile1_bot,LV_BTN_PART_MAIN,LV_STATE_DEFAULT,0);
	lv_obj_set_style_local_outline_width(but_tile1_bot,LV_BTN_PART_MAIN,LV_STATE_FOCUSED,0);
    qmsd_obj_set_id(but_tile1_bot,"but_tile1_bot");
}
    
void qmsd_ima_tile1_hum_create()
{
    ima_tile1_hum = lv_img_create(screentileview1, NULL);
    lv_img_set_src(ima_tile1_hum, &imghumidity_png);
#ifdef BLOCKLY_ima_tile1_hum_EVENT_HANDLER
    lv_obj_set_event_cb(ima_tile1_hum, __qmsd_ima_tile1_hum_cb);
#endif
    lv_obj_set_pos(ima_tile1_hum, 64, 252);
    qmsd_obj_set_id(ima_tile1_hum,"ima_tile1_hum");
}
    void qmsd_lab_tile1_hum_create()
{
	lab_tile1_hum = lv_label_create(screentileview1, NULL);
	lv_label_set_long_mode(lab_tile1_hum,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(lab_tile1_hum,true);
	lv_obj_set_size(lab_tile1_hum, 30, 14);
//set label style
	lv_obj_set_style_local_text_color(lab_tile1_hum,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(lab_tile1_hum, "湿度");
	lv_label_set_align(lab_tile1_hum, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(lab_tile1_hum,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_14);
#ifdef BLOCKLY_lab_tile1_hum_EVENT_HANDLER
	lv_obj_set_event_cb(lab_tile1_hum, __qmsd_lab_tile1_hum_cb);
#endif
	if(lab_tile1_hum->coords.x2-lab_tile1_hum->coords.x1<30)
	{
		int x_offset=(30-(lab_tile1_hum->coords.x2-lab_tile1_hum->coords.x1))/2;
		lv_obj_set_style_local_pad_left(lab_tile1_hum,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(lab_tile1_hum,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(lab_tile1_hum->coords.y2-lab_tile1_hum->coords.y1<14)
	{
		int y_offset=(14-(lab_tile1_hum->coords.y2-lab_tile1_hum->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(lab_tile1_hum,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(lab_tile1_hum,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(lab_tile1_hum, 85, 253);
    qmsd_obj_set_id(lab_tile1_hum,"lab_tile1_hum");
}
    void qmsd_lab_tile1_hum__create()
{
	lab_tile1_hum_ = lv_label_create(screentileview1, NULL);
	lv_label_set_long_mode(lab_tile1_hum_,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(lab_tile1_hum_,true);
	lv_obj_set_size(lab_tile1_hum_, 20, 15);
//set label style
	lv_obj_set_style_local_text_color(lab_tile1_hum_,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(lab_tile1_hum_, "00");
	lv_label_set_align(lab_tile1_hum_, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(lab_tile1_hum_,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_21);
#ifdef BLOCKLY_lab_tile1_hum__EVENT_HANDLER
	lv_obj_set_event_cb(lab_tile1_hum_, __qmsd_lab_tile1_hum__cb);
#endif
	if(lab_tile1_hum_->coords.x2-lab_tile1_hum_->coords.x1<20)
	{
		int x_offset=(20-(lab_tile1_hum_->coords.x2-lab_tile1_hum_->coords.x1))/2;
		lv_obj_set_style_local_pad_left(lab_tile1_hum_,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(lab_tile1_hum_,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(lab_tile1_hum_->coords.y2-lab_tile1_hum_->coords.y1<15)
	{
		int y_offset=(15-(lab_tile1_hum_->coords.y2-lab_tile1_hum_->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(lab_tile1_hum_,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(lab_tile1_hum_,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(lab_tile1_hum_, 122, 252);
    qmsd_obj_set_id(lab_tile1_hum_,"lab_tile1_hum_");
}
    void qmsd_lab_tile1_humc_create()
{
	lab_tile1_humc = lv_label_create(screentileview1, NULL);
	lv_label_set_long_mode(lab_tile1_humc,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(lab_tile1_humc,true);
	lv_obj_set_size(lab_tile1_humc, 20, 15);
//set label style
	lv_obj_set_style_local_text_color(lab_tile1_humc,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(lab_tile1_humc, "％");
	lv_label_set_align(lab_tile1_humc, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(lab_tile1_humc,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_21);
#ifdef BLOCKLY_lab_tile1_humc_EVENT_HANDLER
	lv_obj_set_event_cb(lab_tile1_humc, __qmsd_lab_tile1_humc_cb);
#endif
	if(lab_tile1_humc->coords.x2-lab_tile1_humc->coords.x1<20)
	{
		int x_offset=(20-(lab_tile1_humc->coords.x2-lab_tile1_humc->coords.x1))/2;
		lv_obj_set_style_local_pad_left(lab_tile1_humc,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(lab_tile1_humc,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(lab_tile1_humc->coords.y2-lab_tile1_humc->coords.y1<15)
	{
		int y_offset=(15-(lab_tile1_humc->coords.y2-lab_tile1_humc->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(lab_tile1_humc,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(lab_tile1_humc,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(lab_tile1_humc, 144, 252);
    qmsd_obj_set_id(lab_tile1_humc,"lab_tile1_humc");
}
    
void qmsd_ima_tile1_air_create()
{
    ima_tile1_air = lv_img_create(screentileview1, NULL);
    lv_img_set_src(ima_tile1_air, &imgair_png);
#ifdef BLOCKLY_ima_tile1_air_EVENT_HANDLER
    lv_obj_set_event_cb(ima_tile1_air, __qmsd_ima_tile1_air_cb);
#endif
    lv_obj_set_pos(ima_tile1_air, 212, 252);
    qmsd_obj_set_id(ima_tile1_air,"ima_tile1_air");
}
    void qmsd_lab_tile1_air_create()
{
	lab_tile1_air = lv_label_create(screentileview1, NULL);
	lv_label_set_long_mode(lab_tile1_air,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(lab_tile1_air,true);
	lv_obj_set_size(lab_tile1_air, 58, 14);
//set label style
	lv_obj_set_style_local_text_color(lab_tile1_air,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(lab_tile1_air, "空气质量");
	lv_label_set_align(lab_tile1_air, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(lab_tile1_air,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_14);
#ifdef BLOCKLY_lab_tile1_air_EVENT_HANDLER
	lv_obj_set_event_cb(lab_tile1_air, __qmsd_lab_tile1_air_cb);
#endif
	if(lab_tile1_air->coords.x2-lab_tile1_air->coords.x1<58)
	{
		int x_offset=(58-(lab_tile1_air->coords.x2-lab_tile1_air->coords.x1))/2;
		lv_obj_set_style_local_pad_left(lab_tile1_air,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(lab_tile1_air,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(lab_tile1_air->coords.y2-lab_tile1_air->coords.y1<14)
	{
		int y_offset=(14-(lab_tile1_air->coords.y2-lab_tile1_air->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(lab_tile1_air,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(lab_tile1_air,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(lab_tile1_air, 235, 253);
    qmsd_obj_set_id(lab_tile1_air,"lab_tile1_air");
}
    void qmsd_lab_tile1_air__create()
{
	lab_tile1_air_ = lv_label_create(screentileview1, NULL);
	lv_label_set_long_mode(lab_tile1_air_,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(lab_tile1_air_,true);
	lv_obj_set_size(lab_tile1_air_, 22, 15);
//set label style
	lv_obj_set_style_local_text_color(lab_tile1_air_,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(lab_tile1_air_, "33");
	lv_label_set_align(lab_tile1_air_, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(lab_tile1_air_,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_21);
#ifdef BLOCKLY_lab_tile1_air__EVENT_HANDLER
	lv_obj_set_event_cb(lab_tile1_air_, __qmsd_lab_tile1_air__cb);
#endif
	if(lab_tile1_air_->coords.x2-lab_tile1_air_->coords.x1<22)
	{
		int x_offset=(22-(lab_tile1_air_->coords.x2-lab_tile1_air_->coords.x1))/2;
		lv_obj_set_style_local_pad_left(lab_tile1_air_,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(lab_tile1_air_,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(lab_tile1_air_->coords.y2-lab_tile1_air_->coords.y1<15)
	{
		int y_offset=(15-(lab_tile1_air_->coords.y2-lab_tile1_air_->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(lab_tile1_air_,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(lab_tile1_air_,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(lab_tile1_air_, 304, 252);
    qmsd_obj_set_id(lab_tile1_air_,"lab_tile1_air_");
}
    
void qmsd_ima_tile1_le_create()
{
    ima_tile1_le = lv_img_create(screentileview1, NULL);
    lv_img_set_src(ima_tile1_le, &imgtileview_1_png);
#ifdef BLOCKLY_ima_tile1_le_EVENT_HANDLER
    lv_obj_set_event_cb(ima_tile1_le, __qmsd_ima_tile1_le_cb);
#endif
    lv_obj_set_pos(ima_tile1_le, 50, 311);
    lv_obj_set_click(ima_tile1_le,true);
    lv_obj_set_style_local_image_recolor(ima_tile1_le,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(ima_tile1_le,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    qmsd_obj_set_id(ima_tile1_le,"ima_tile1_le");
}
    
void qmsd_ima_tile1_mi_create()
{
    ima_tile1_mi = lv_img_create(screentileview1, NULL);
    lv_img_set_src(ima_tile1_mi, &imgtileview_2_png);
#ifdef BLOCKLY_ima_tile1_mi_EVENT_HANDLER
    lv_obj_set_event_cb(ima_tile1_mi, __qmsd_ima_tile1_mi_cb);
#endif
    lv_obj_set_pos(ima_tile1_mi, 184, 311);
    lv_obj_set_click(ima_tile1_mi,true);
    lv_obj_set_style_local_image_recolor(ima_tile1_mi,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(ima_tile1_mi,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    qmsd_obj_set_id(ima_tile1_mi,"ima_tile1_mi");
}
    
void qmsd_ima_tile1_ri_create()
{
    ima_tile1_ri = lv_img_create(screentileview1, NULL);
    lv_img_set_src(ima_tile1_ri, &imgtileview_3_png);
#ifdef BLOCKLY_ima_tile1_ri_EVENT_HANDLER
    lv_obj_set_event_cb(ima_tile1_ri, __qmsd_ima_tile1_ri_cb);
#endif
    lv_obj_set_pos(ima_tile1_ri, 318, 311);
    lv_obj_set_click(ima_tile1_ri,true);
    lv_obj_set_style_local_image_recolor(ima_tile1_ri,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(ima_tile1_ri,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    qmsd_obj_set_id(ima_tile1_ri,"ima_tile1_ri");
}
    
void qmsd_ima_tile1_le__create()
{
    ima_tile1_le_ = lv_img_create(screentileview1, NULL);
    lv_img_set_src(ima_tile1_le_, &imgtileview_go_home_png);
#ifdef BLOCKLY_ima_tile1_le__EVENT_HANDLER
    lv_obj_set_event_cb(ima_tile1_le_, __qmsd_ima_tile1_le__cb);
#endif
    lv_obj_set_pos(ima_tile1_le_, 92, 339);
    lv_obj_set_click(ima_tile1_le_,true);
    lv_obj_set_style_local_image_recolor(ima_tile1_le_,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(ima_tile1_le_,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    qmsd_obj_set_id(ima_tile1_le_,"ima_tile1_le_");
}
    void qmsd_lab_tile1_le_create()
{
	lab_tile1_le = lv_label_create(screentileview1, NULL);
	lv_label_set_long_mode(lab_tile1_le,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(lab_tile1_le,true);
	lv_obj_set_size(lab_tile1_le, 35, 17);
//set label style
	lv_obj_set_style_local_text_color(lab_tile1_le,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(lab_tile1_le, "回家");
	lv_label_set_align(lab_tile1_le, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(lab_tile1_le,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_17);
#ifdef BLOCKLY_lab_tile1_le_EVENT_HANDLER
	lv_obj_set_event_cb(lab_tile1_le, __qmsd_lab_tile1_le_cb);
#endif
    lv_obj_set_click(lab_tile1_le,true);    
	if(lab_tile1_le->coords.x2-lab_tile1_le->coords.x1<35)
	{
		int x_offset=(35-(lab_tile1_le->coords.x2-lab_tile1_le->coords.x1))/2;
		lv_obj_set_style_local_pad_left(lab_tile1_le,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(lab_tile1_le,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(lab_tile1_le->coords.y2-lab_tile1_le->coords.y1<17)
	{
		int y_offset=(17-(lab_tile1_le->coords.y2-lab_tile1_le->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(lab_tile1_le,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(lab_tile1_le,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(lab_tile1_le, 89, 389);
    qmsd_obj_set_id(lab_tile1_le,"lab_tile1_le");
}
    
void qmsd_ima_tile1_mi__create()
{
    ima_tile1_mi_ = lv_img_create(screentileview1, NULL);
    lv_img_set_src(ima_tile1_mi_, &imgtileview_leave_home_png);
#ifdef BLOCKLY_ima_tile1_mi__EVENT_HANDLER
    lv_obj_set_event_cb(ima_tile1_mi_, __qmsd_ima_tile1_mi__cb);
#endif
    lv_obj_set_pos(ima_tile1_mi_, 226, 339);
    lv_obj_set_click(ima_tile1_mi_,true);
    lv_obj_set_style_local_image_recolor(ima_tile1_mi_,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(ima_tile1_mi_,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    qmsd_obj_set_id(ima_tile1_mi_,"ima_tile1_mi_");
}
    void qmsd_lab_tile1_mi_create()
{
	lab_tile1_mi = lv_label_create(screentileview1, NULL);
	lv_label_set_long_mode(lab_tile1_mi,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(lab_tile1_mi,true);
	lv_obj_set_size(lab_tile1_mi, 35, 17);
//set label style
	lv_obj_set_style_local_text_color(lab_tile1_mi,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(lab_tile1_mi, "离家");
	lv_label_set_align(lab_tile1_mi, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(lab_tile1_mi,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_17);
#ifdef BLOCKLY_lab_tile1_mi_EVENT_HANDLER
	lv_obj_set_event_cb(lab_tile1_mi, __qmsd_lab_tile1_mi_cb);
#endif
    lv_obj_set_click(lab_tile1_mi,true);    
	if(lab_tile1_mi->coords.x2-lab_tile1_mi->coords.x1<35)
	{
		int x_offset=(35-(lab_tile1_mi->coords.x2-lab_tile1_mi->coords.x1))/2;
		lv_obj_set_style_local_pad_left(lab_tile1_mi,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(lab_tile1_mi,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(lab_tile1_mi->coords.y2-lab_tile1_mi->coords.y1<17)
	{
		int y_offset=(17-(lab_tile1_mi->coords.y2-lab_tile1_mi->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(lab_tile1_mi,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(lab_tile1_mi,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(lab_tile1_mi, 224, 389);
    qmsd_obj_set_id(lab_tile1_mi,"lab_tile1_mi");
}
    
void qmsd_ima_tile1_ri__create()
{
    ima_tile1_ri_ = lv_img_create(screentileview1, NULL);
    lv_img_set_src(ima_tile1_ri_, &imgtileview_more_png);
#ifdef BLOCKLY_ima_tile1_ri__EVENT_HANDLER
    lv_obj_set_event_cb(ima_tile1_ri_, __qmsd_ima_tile1_ri__cb);
#endif
    lv_obj_set_pos(ima_tile1_ri_, 362, 339);
    lv_obj_set_click(ima_tile1_ri_,true);
    lv_obj_set_style_local_image_recolor(ima_tile1_ri_,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(ima_tile1_ri_,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    qmsd_obj_set_id(ima_tile1_ri_,"ima_tile1_ri_");
}
    void qmsd_lab_tile1_ri_create()
{
	lab_tile1_ri = lv_label_create(screentileview1, NULL);
	lv_label_set_long_mode(lab_tile1_ri,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(lab_tile1_ri,true);
	lv_obj_set_size(lab_tile1_ri, 35, 17);
//set label style
	lv_obj_set_style_local_text_color(lab_tile1_ri,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(lab_tile1_ri, "更多");
	lv_label_set_align(lab_tile1_ri, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(lab_tile1_ri,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_17);
#ifdef BLOCKLY_lab_tile1_ri_EVENT_HANDLER
	lv_obj_set_event_cb(lab_tile1_ri, __qmsd_lab_tile1_ri_cb);
#endif
    lv_obj_set_click(lab_tile1_ri,true);    
	if(lab_tile1_ri->coords.x2-lab_tile1_ri->coords.x1<35)
	{
		int x_offset=(35-(lab_tile1_ri->coords.x2-lab_tile1_ri->coords.x1))/2;
		lv_obj_set_style_local_pad_left(lab_tile1_ri,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(lab_tile1_ri,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(lab_tile1_ri->coords.y2-lab_tile1_ri->coords.y1<17)
	{
		int y_offset=(17-(lab_tile1_ri->coords.y2-lab_tile1_ri->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(lab_tile1_ri,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(lab_tile1_ri,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(lab_tile1_ri, 362, 389);
    qmsd_obj_set_id(lab_tile1_ri,"lab_tile1_ri");
}
    void qmsd_lab_tile1_hour_create()
{
	lab_tile1_hour = lv_label_create(screentileview1, NULL);
	lv_label_set_long_mode(lab_tile1_hour,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(lab_tile1_hour,true);
	lv_obj_set_size(lab_tile1_hour, 100, 76);
//set label style
	lv_obj_set_style_local_text_color(lab_tile1_hour,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(lab_tile1_hour, "10");
	lv_label_set_align(lab_tile1_hour, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(lab_tile1_hour,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_104);
#ifdef BLOCKLY_lab_tile1_hour_EVENT_HANDLER
	lv_obj_set_event_cb(lab_tile1_hour, __qmsd_lab_tile1_hour_cb);
#endif
	if(lab_tile1_hour->coords.x2-lab_tile1_hour->coords.x1<100)
	{
		int x_offset=(100-(lab_tile1_hour->coords.x2-lab_tile1_hour->coords.x1))/2;
		lv_obj_set_style_local_pad_left(lab_tile1_hour,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(lab_tile1_hour,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(lab_tile1_hour->coords.y2-lab_tile1_hour->coords.y1<76)
	{
		int y_offset=(76-(lab_tile1_hour->coords.y2-lab_tile1_hour->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(lab_tile1_hour,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(lab_tile1_hour,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(lab_tile1_hour, 48, 78);
    qmsd_obj_set_id(lab_tile1_hour,"lab_tile1_hour");
}
    void qmsd_lab_tile1_min_create()
{
	lab_tile1_min = lv_label_create(screentileview1, NULL);
	lv_label_set_long_mode(lab_tile1_min,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(lab_tile1_min,true);
	lv_obj_set_size(lab_tile1_min, 100, 76);
//set label style
	lv_obj_set_style_local_text_color(lab_tile1_min,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(lab_tile1_min, "12");
	lv_label_set_align(lab_tile1_min, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(lab_tile1_min,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_104);
#ifdef BLOCKLY_lab_tile1_min_EVENT_HANDLER
	lv_obj_set_event_cb(lab_tile1_min, __qmsd_lab_tile1_min_cb);
#endif
	if(lab_tile1_min->coords.x2-lab_tile1_min->coords.x1<100)
	{
		int x_offset=(100-(lab_tile1_min->coords.x2-lab_tile1_min->coords.x1))/2;
		lv_obj_set_style_local_pad_left(lab_tile1_min,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(lab_tile1_min,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(lab_tile1_min->coords.y2-lab_tile1_min->coords.y1<76)
	{
		int y_offset=(76-(lab_tile1_min->coords.y2-lab_tile1_min->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(lab_tile1_min,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(lab_tile1_min,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(lab_tile1_min, 194, 78);
    qmsd_obj_set_id(lab_tile1_min,"lab_tile1_min");
}

static void screentileview1_qmsd_cb(lv_obj_t * obj, lv_event_t event, void *data)
{/*
    char *trans;
    lv_label_set_text(lab_tile1_time,qmsd_lang_get_trans("lab_tile1_time",":"));
    lv_label_set_text(lab_tile1_data,qmsd_lang_get_trans("lab_tile1_data","8月12日"));
    lv_label_set_text(lab_tile1_week,qmsd_lang_get_trans("lab_tile1_week","星期二"));
    lv_label_set_text(lab_tile1_tem,qmsd_lang_get_trans("lab_tile1_tem","26"));
    lv_label_set_text(lab_tile1_com,qmsd_lang_get_trans("lab_tile1_com","℃"));
    lv_label_set_text(__but_tile1_bot_label,qmsd_lang_get_trans("but_tile1_bot",""));
    lv_label_set_text(lab_tile1_hum,qmsd_lang_get_trans("lab_tile1_hum","湿度"));
    lv_label_set_text(lab_tile1_hum_,qmsd_lang_get_trans("lab_tile1_hum_","60"));
    lv_label_set_text(lab_tile1_humc,qmsd_lang_get_trans("lab_tile1_humc","％"));
    lv_label_set_text(lab_tile1_air,qmsd_lang_get_trans("lab_tile1_air","空气质量"));
    lv_label_set_text(lab_tile1_air_,qmsd_lang_get_trans("lab_tile1_air_","33"));
    lv_label_set_text(lab_tile1_le,qmsd_lang_get_trans("lab_tile1_le","回家"));
    lv_label_set_text(lab_tile1_mi,qmsd_lang_get_trans("lab_tile1_mi","离家"));
    lv_label_set_text(lab_tile1_ri,qmsd_lang_get_trans("lab_tile1_ri","更多"));
    lv_label_set_text(lab_tile1_hour,qmsd_lang_get_trans("lab_tile1_hour","10"));
    lv_label_set_text(lab_tile1_min,qmsd_lang_get_trans("lab_tile1_min","12"));
*/
#ifdef BLOCKLY_screentileview1_SCREEN_INIT
    __qmsd_screentileview1_init();
#endif
}

void screentileview1_tileview_cb(lv_obj_t* obj,lv_event_t event)
{
    if(event == LV_EVENT_DELETE)
    {
        screentileview1 = NULL;
        qmsd_screen_remove("screentileview1");
    }
}

void screentileview1_build(void)
{
    if(screentileview1) return;
    screentileview1 = lv_obj_create(tile_main,NULL);
    lv_obj_qmsd_set_cb(screentileview1, screentileview1_qmsd_cb);
    lv_obj_set_size(screentileview1,480,480);
    lv_obj_set_pos(screentileview1,0*LV_HOR_RES,0*LV_VER_RES);
    lv_obj_set_event_cb(screentileview1,screentileview1_tileview_cb);
    lv_obj_set_style_local_bg_color(screentileview1,LV_OBJ_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x20, 0x20, 0x20));
    lv_obj_set_style_local_border_width(screentileview1,LV_OBJ_PART_MAIN,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_radius(screentileview1,LV_OBJ_PART_MAIN,LV_STATE_DEFAULT,0);
    qmsd_lab_tile1_time_create();
    lv_tileview_add_element(tile_main, lab_tile1_time);
    qmsd_lab_tile1_data_create();
    lv_tileview_add_element(tile_main, lab_tile1_data);
    qmsd_lab_tile1_week_create();
    lv_tileview_add_element(tile_main, lab_tile1_week);
    qmsd_ima_tile1_wea_create();
    lv_tileview_add_element(tile_main, ima_tile1_wea);
    qmsd_lab_tile1_tem_create();
    lv_tileview_add_element(tile_main, lab_tile1_tem);
    qmsd_lab_tile1_com_create();
    lv_tileview_add_element(tile_main, lab_tile1_com);
    qmsd_but_tile1_bot_create();
    lv_tileview_add_element(tile_main, but_tile1_bot);
    qmsd_ima_tile1_hum_create();
    lv_tileview_add_element(tile_main, ima_tile1_hum);
    qmsd_lab_tile1_hum_create();
    lv_tileview_add_element(tile_main, lab_tile1_hum);
    qmsd_lab_tile1_hum__create();
    lv_tileview_add_element(tile_main, lab_tile1_hum_);
    qmsd_lab_tile1_humc_create();
    lv_tileview_add_element(tile_main, lab_tile1_humc);
    qmsd_ima_tile1_air_create();
    lv_tileview_add_element(tile_main, ima_tile1_air);
    qmsd_lab_tile1_air_create();
    lv_tileview_add_element(tile_main, lab_tile1_air);
    qmsd_lab_tile1_air__create();
    lv_tileview_add_element(tile_main, lab_tile1_air_);
    qmsd_ima_tile1_le_create();
    lv_tileview_add_element(tile_main, ima_tile1_le);
    qmsd_ima_tile1_mi_create();
    lv_tileview_add_element(tile_main, ima_tile1_mi);
    qmsd_ima_tile1_ri_create();
    lv_tileview_add_element(tile_main, ima_tile1_ri);
    qmsd_ima_tile1_le__create();
    lv_tileview_add_element(tile_main, ima_tile1_le_);
    qmsd_lab_tile1_le_create();
    lv_tileview_add_element(tile_main, lab_tile1_le);
    qmsd_ima_tile1_mi__create();
    lv_tileview_add_element(tile_main, ima_tile1_mi_);
    qmsd_lab_tile1_mi_create();
    lv_tileview_add_element(tile_main, lab_tile1_mi);
    qmsd_ima_tile1_ri__create();
    lv_tileview_add_element(tile_main, ima_tile1_ri_);
    qmsd_lab_tile1_ri_create();
    lv_tileview_add_element(tile_main, lab_tile1_ri);
    qmsd_lab_tile1_hour_create();
    lv_tileview_add_element(tile_main, lab_tile1_hour);
    qmsd_lab_tile1_min_create();
    lv_tileview_add_element(tile_main, lab_tile1_min);
    lv_tileview_add_element(tile_main, screentileview1);
    qmsd_screen_register(screentileview1,"screentileview1");
}

void screentileview1_show(void)
{
    lv_tileview_set_tile_act(tile_main,0,0,LV_ANIM_ON);
}


void screentileview1_delete(void)
{

}
