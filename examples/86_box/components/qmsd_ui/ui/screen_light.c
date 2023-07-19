#include "qmsd_ui_entry.h"
#include "qmsd_internal_ui_cb.h"

lv_obj_t* screen_light;
lv_obj_t* image_li_bottom;
lv_obj_t* image_li_return;
lv_obj_t* label_li_return;
lv_obj_t* image_li_line;
lv_obj_t* image_li_light;
lv_obj_t* image_li_setb;
lv_obj_t* image_li_set;
lv_obj_t* label_li_light;
lv_obj_t* label_li_color;
lv_obj_t* button_li_l_bt;
lv_obj_t * __button_li_l_bt_label;
lv_obj_t* button_li_l_ra;
lv_obj_t * __button_li_l_ra_label;
lv_obj_t* image_li_barl;
lv_obj_t* button_li_c_bt;
lv_obj_t * __button_li_c_bt_label;
lv_obj_t* button_li_c_ra;
lv_obj_t * __button_li_c_ra_label;
lv_obj_t* image_li_barc;


    
void qmsd_image_li_bottom_create()
{
    image_li_bottom = lv_img_create(screen_light, NULL);
    lv_img_set_src(image_li_bottom, &imgli_bottom_png);
#ifdef BLOCKLY_image_li_bottom_EVENT_HANDLER
    lv_obj_set_event_cb(image_li_bottom, __qmsd_image_li_bottom_cb);
#endif
    lv_obj_set_pos(image_li_bottom, -1, 127);
    qmsd_obj_set_id(image_li_bottom,"image_li_bottom");
}
    
void qmsd_image_li_return_create()
{
    image_li_return = lv_img_create(screen_light, NULL);
    lv_img_set_src(image_li_return, &imgreturn_png);
#ifdef BLOCKLY_image_li_return_EVENT_HANDLER
    lv_obj_set_event_cb(image_li_return, __qmsd_image_li_return_cb);
#endif
    lv_obj_set_pos(image_li_return, 31.5, 32.5);
    lv_obj_set_click(image_li_return,true);
    lv_obj_set_style_local_image_recolor(image_li_return,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(image_li_return,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    qmsd_obj_set_id(image_li_return,"image_li_return");
}
    void qmsd_label_li_return_create()
{
	label_li_return = lv_label_create(screen_light, NULL);
	lv_label_set_long_mode(label_li_return,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_li_return,true);
	lv_obj_set_size(label_li_return, 60, 33);
//set label style
	lv_obj_set_style_local_text_color(label_li_return,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(label_li_return, "返回");
	lv_label_set_align(label_li_return, LV_LABEL_ALIGN_LEFT);
	lv_obj_set_style_local_text_font(label_li_return,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_22);
#ifdef BLOCKLY_label_li_return_EVENT_HANDLER
	lv_obj_set_event_cb(label_li_return, __qmsd_label_li_return_cb);
#endif
    lv_obj_set_click(label_li_return,true);    
	if(label_li_return->coords.x2-label_li_return->coords.x1<60)
	{
		int x_offset=(60-(label_li_return->coords.x2-label_li_return->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_li_return,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_li_return,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_li_return->coords.y2-label_li_return->coords.y1<33)
	{
		int y_offset=(33-(label_li_return->coords.y2-label_li_return->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_li_return,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_li_return,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(label_li_return, 58, 24);
    qmsd_obj_set_id(label_li_return,"label_li_return");
}
    
void qmsd_image_li_line_create()
{
    image_li_line = lv_img_create(screen_light, NULL);
    lv_img_set_src(image_li_line, &imgline_png);
#ifdef BLOCKLY_image_li_line_EVENT_HANDLER
    lv_obj_set_event_cb(image_li_line, __qmsd_image_li_line_cb);
#endif
    lv_obj_set_pos(image_li_line, 0, 70);
    qmsd_obj_set_id(image_li_line,"image_li_line");
}
    
void qmsd_image_li_light_create()
{
    image_li_light = lv_img_create(screen_light, NULL);
    lv_img_set_src(image_li_light, &imgli_light_png);
#ifdef BLOCKLY_image_li_light_EVENT_HANDLER
    lv_obj_set_event_cb(image_li_light, __qmsd_image_li_light_cb);
#endif
    lv_obj_set_pos(image_li_light, 59, 133);
    qmsd_obj_set_id(image_li_light,"image_li_light");
}
    
void qmsd_image_li_setb_create()
{
    image_li_setb = lv_img_create(screen_light, NULL);
    lv_img_set_src(image_li_setb, &imgli_setb_png);
#ifdef BLOCKLY_image_li_setb_EVENT_HANDLER
    lv_obj_set_event_cb(image_li_setb, __qmsd_image_li_setb_cb);
#endif
    lv_obj_set_pos(image_li_setb, 202, 396);
    qmsd_obj_set_id(image_li_setb,"image_li_setb");
}
    
void qmsd_image_li_set_create()
{
    image_li_set = lv_img_create(screen_light, NULL);
    lv_img_set_src(image_li_set, &imgli_set_png);
#ifdef BLOCKLY_image_li_set_EVENT_HANDLER
    lv_obj_set_event_cb(image_li_set, __qmsd_image_li_set_cb);
#endif
    lv_obj_set_pos(image_li_set, 160, 356);
    lv_obj_set_click(image_li_set,true);
    lv_obj_set_style_local_image_recolor(image_li_set,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(image_li_set,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    qmsd_obj_set_id(image_li_set,"image_li_set");
}
    void qmsd_label_li_light_create()
{
	label_li_light = lv_label_create(screen_light, NULL);
	lv_label_set_long_mode(label_li_light,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_li_light,true);
	lv_obj_set_size(label_li_light, 64, 40);
//set label style
	lv_obj_set_style_local_text_color(label_li_light,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(label_li_light, "亮度");
	lv_label_set_align(label_li_light, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(label_li_light,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_21);
#ifdef BLOCKLY_label_li_light_EVENT_HANDLER
	lv_obj_set_event_cb(label_li_light, __qmsd_label_li_light_cb);
#endif
	if(label_li_light->coords.x2-label_li_light->coords.x1<64)
	{
		int x_offset=(64-(label_li_light->coords.x2-label_li_light->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_li_light,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_li_light,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_li_light->coords.y2-label_li_light->coords.y1<40)
	{
		int y_offset=(40-(label_li_light->coords.y2-label_li_light->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_li_light,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_li_light,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(label_li_light, 275, 315);
    qmsd_obj_set_id(label_li_light,"label_li_light");
}
    void qmsd_label_li_color_create()
{
	label_li_color = lv_label_create(screen_light, NULL);
	lv_label_set_long_mode(label_li_color,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_li_color,true);
	lv_obj_set_size(label_li_color, 64, 40);
//set label style
	lv_obj_set_style_local_text_color(label_li_color,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(label_li_color, "色温");
	lv_label_set_align(label_li_color, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(label_li_color,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_21);
#ifdef BLOCKLY_label_li_color_EVENT_HANDLER
	lv_obj_set_event_cb(label_li_color, __qmsd_label_li_color_cb);
#endif
	if(label_li_color->coords.x2-label_li_color->coords.x1<64)
	{
		int x_offset=(64-(label_li_color->coords.x2-label_li_color->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_li_color,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_li_color,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_li_color->coords.y2-label_li_color->coords.y1<40)
	{
		int y_offset=(40-(label_li_color->coords.y2-label_li_color->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_li_color,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_li_color,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(label_li_color, 369, 316);
    qmsd_obj_set_id(label_li_color,"label_li_color");
}
    void qmsd_button_li_l_bt_create()
{
    button_li_l_bt = lv_btn_create(screen_light, NULL);
    __button_li_l_bt_label = lv_label_create(button_li_l_bt, NULL);
    lv_label_set_text(__button_li_l_bt_label,qmsd_lang_get_trans("button_li_l_bt",""));

    lv_obj_set_style_local_text_font(__button_li_l_bt_label,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_16);
    lv_obj_set_size(button_li_l_bt, 60, 180);
    lv_obj_set_pos(button_li_l_bt, 275, 134);
#ifdef BLOCKLY_button_li_l_bt_EVENT_HANDLER
    lv_obj_set_event_cb(button_li_l_bt, __qmsd_button_li_l_bt_cb);
#endif


    lv_obj_t* obj = button_li_l_bt;
    int part = LV_BTN_PART_MAIN;
//设置正常样式
        lv_obj_set_style_local_radius(obj,part,LV_STATE_DEFAULT,20);
    lv_obj_set_style_local_bg_opa(obj,part,LV_STATE_DEFAULT,61);
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
    lv_obj_set_style_local_outline_width(button_li_l_bt,LV_BTN_PART_MAIN,LV_STATE_DEFAULT,0);
	lv_obj_set_style_local_outline_width(button_li_l_bt,LV_BTN_PART_MAIN,LV_STATE_FOCUSED,0);
    qmsd_obj_set_id(button_li_l_bt,"button_li_l_bt");
}
    void qmsd_button_li_l_ra_create()
{
    button_li_l_ra = lv_btn_create(screen_light, NULL);
    __button_li_l_ra_label = lv_label_create(button_li_l_ra, NULL);
    lv_label_set_text(__button_li_l_ra_label,qmsd_lang_get_trans("button_li_l_ra",""));

    lv_obj_set_style_local_text_font(__button_li_l_ra_label,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_16);
    lv_obj_set_size(button_li_l_ra, 60, 20);
    lv_obj_set_pos(button_li_l_ra, 275, 294);
#ifdef BLOCKLY_button_li_l_ra_EVENT_HANDLER
    lv_obj_set_event_cb(button_li_l_ra, __qmsd_button_li_l_ra_cb);
#endif


    lv_obj_t* obj = button_li_l_ra;
    int part = LV_BTN_PART_MAIN;
//设置正常样式
        lv_obj_set_style_local_radius(obj,part,LV_STATE_DEFAULT,20);
    lv_obj_set_style_local_border_opa(obj,part,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_text_color(obj,part,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x31, 0x40, 0x4f));

//设置正常样式结束

//设置按下样式
        lv_obj_set_style_local_bg_color(obj,part,LV_STATE_PRESSED,LV_COLOR_MAKE(0x01, 0xa2, 0xb1));
    lv_obj_set_style_local_text_color(obj,part,LV_STATE_PRESSED,LV_COLOR_MAKE(0x31, 0x40, 0x4f));

//设置按下样式结束

//设置禁用样式
        lv_obj_set_style_local_text_color(obj,part,LV_STATE_DISABLED,LV_COLOR_MAKE(0x88, 0x88, 0x88));

//设置禁用样式结束
    lv_obj_set_style_local_outline_width(button_li_l_ra,LV_BTN_PART_MAIN,LV_STATE_DEFAULT,0);
	lv_obj_set_style_local_outline_width(button_li_l_ra,LV_BTN_PART_MAIN,LV_STATE_FOCUSED,0);
    qmsd_obj_set_id(button_li_l_ra,"button_li_l_ra");
}

void my_image_li_barl_cb(lv_obj_t * obj, lv_event_t event)
{
    if(event == LV_EVENT_PRESSING) {
        _lv_indev_read(get_point, &my_data);
        if((my_data.point.y >= 123 && my_data.point.y <= 287)) {
            lv_obj_set_y(obj, my_data.point.y);
            lv_obj_set_height(button_li_l_ra, 314-(my_data.point.y)-10);
            lv_obj_set_y(button_li_l_ra, my_data.point.y+10); 
        }        
    }
}
    
void qmsd_image_li_barl_create()
{
    image_li_barl = lv_img_create(screen_light, NULL);
    lv_img_set_src(image_li_barl, &imgli_bar_png);
//! 增加点击区域
    lv_obj_set_ext_click_area(image_li_barl,40,40,40,40);
    lv_obj_set_click(image_li_barl,true);
#ifdef BLOCKLY_image_li_barl_EVENT_HANDLER
    lv_obj_set_event_cb(image_li_barl, __qmsd_image_li_barl_cb);
#endif
    lv_obj_set_pos(image_li_barl, 285, 279);
    qmsd_obj_set_id(image_li_barl,"image_li_barl");

    lv_obj_set_event_cb(image_li_barl, my_image_li_barl_cb);
}
    void qmsd_button_li_c_bt_create()
{
    button_li_c_bt = lv_btn_create(screen_light, NULL);
    __button_li_c_bt_label = lv_label_create(button_li_c_bt, NULL);
    lv_label_set_text(__button_li_c_bt_label,qmsd_lang_get_trans("button_li_c_bt",""));

    lv_obj_set_style_local_text_font(__button_li_c_bt_label,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_16);
    lv_obj_set_size(button_li_c_bt, 60, 180);
    lv_obj_set_pos(button_li_c_bt, 373, 134);
#ifdef BLOCKLY_button_li_c_bt_EVENT_HANDLER
    lv_obj_set_event_cb(button_li_c_bt, __qmsd_button_li_c_bt_cb);
#endif


    lv_obj_t* obj = button_li_c_bt;
    int part = LV_BTN_PART_MAIN;
//设置正常样式
        lv_obj_set_style_local_radius(obj,part,LV_STATE_DEFAULT,20);
    lv_obj_set_style_local_bg_opa(obj,part,LV_STATE_DEFAULT,61);
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
    lv_obj_set_style_local_outline_width(button_li_c_bt,LV_BTN_PART_MAIN,LV_STATE_DEFAULT,0);
	lv_obj_set_style_local_outline_width(button_li_c_bt,LV_BTN_PART_MAIN,LV_STATE_FOCUSED,0);
    qmsd_obj_set_id(button_li_c_bt,"button_li_c_bt");
}
    void qmsd_button_li_c_ra_create()
{
    button_li_c_ra = lv_btn_create(screen_light, NULL);
    __button_li_c_ra_label = lv_label_create(button_li_c_ra, NULL);
    lv_label_set_text(__button_li_c_ra_label,qmsd_lang_get_trans("button_li_c_ra",""));

    lv_obj_set_style_local_text_font(__button_li_c_ra_label,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_16);
    lv_obj_set_size(button_li_c_ra, 60, 50);
    lv_obj_set_pos(button_li_c_ra, 373, 264);
#ifdef BLOCKLY_button_li_c_ra_EVENT_HANDLER
    lv_obj_set_event_cb(button_li_c_ra, __qmsd_button_li_c_ra_cb);
#endif


    lv_obj_t* obj = button_li_c_ra;
    int part = LV_BTN_PART_MAIN;
//设置正常样式
        lv_obj_set_style_local_bg_color(obj,part,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xf8, 0xe7, 0x1c));
    lv_obj_set_style_local_radius(obj,part,LV_STATE_DEFAULT,20);
    lv_obj_set_style_local_border_opa(obj,part,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_text_color(obj,part,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x31, 0x40, 0x4f));

//设置正常样式结束

//设置按下样式
        lv_obj_set_style_local_bg_color(obj,part,LV_STATE_PRESSED,LV_COLOR_MAKE(0x01, 0xa2, 0xb1));
    lv_obj_set_style_local_text_color(obj,part,LV_STATE_PRESSED,LV_COLOR_MAKE(0x31, 0x40, 0x4f));

//设置按下样式结束

//设置禁用样式
        lv_obj_set_style_local_text_color(obj,part,LV_STATE_DISABLED,LV_COLOR_MAKE(0x88, 0x88, 0x88));

//设置禁用样式结束
    lv_obj_set_style_local_outline_width(button_li_c_ra,LV_BTN_PART_MAIN,LV_STATE_DEFAULT,0);
	lv_obj_set_style_local_outline_width(button_li_c_ra,LV_BTN_PART_MAIN,LV_STATE_FOCUSED,0);
    qmsd_obj_set_id(button_li_c_ra,"button_li_c_ra");
}

void my_image_li_barc_cb(lv_obj_t * obj, lv_event_t event)
{
    if(event == LV_EVENT_PRESSING) {
        _lv_indev_read(get_point, &my_data);
        if((my_data.point.y >= 123 && my_data.point.y <= 287)) {
            lv_obj_set_y(obj, my_data.point.y);
            lv_obj_set_height(button_li_c_ra, 314-(my_data.point.y)-10);
            lv_obj_set_y(button_li_c_ra, my_data.point.y+10); 
        }        
    }
}
    
void qmsd_image_li_barc_create()
{
    image_li_barc = lv_img_create(screen_light, NULL);
    lv_img_set_src(image_li_barc, &imgli_bar_png);
//! 增加点击区域
    lv_obj_set_ext_click_area(image_li_barc,40,40,40,40);
    lv_obj_set_click(image_li_barc,true);
#ifdef BLOCKLY_image_li_barc_EVENT_HANDLER
    lv_obj_set_event_cb(image_li_barc, __qmsd_image_li_barc_cb);
#endif
    lv_obj_set_pos(image_li_barc, 381, 249);
    qmsd_obj_set_id(image_li_barc,"image_li_barc");

    lv_obj_set_event_cb(image_li_barc, my_image_li_barc_cb);
}

static void screen_light_qmsd_cb(lv_obj_t * obj, lv_event_t event, void *data)
{/*
    char *trans;
    lv_label_set_text(label_li_return,qmsd_lang_get_trans("label_li_return","返回"));
    lv_label_set_text(label_li_light,qmsd_lang_get_trans("label_li_light","亮度"));
    lv_label_set_text(label_li_color,qmsd_lang_get_trans("label_li_color","色温"));
    lv_label_set_text(__button_li_l_bt_label,qmsd_lang_get_trans("button_li_l_bt",""));
    lv_label_set_text(__button_li_l_ra_label,qmsd_lang_get_trans("button_li_l_ra",""));
    lv_label_set_text(__button_li_c_bt_label,qmsd_lang_get_trans("button_li_c_bt",""));
    lv_label_set_text(__button_li_c_ra_label,qmsd_lang_get_trans("button_li_c_ra",""));
*/
#ifdef BLOCKLY_screen_light_SCREEN_INIT
    __qmsd_screen_light_init();
#endif
}

static void screen_light_del_cb(lv_obj_t* obj,lv_event_t event)
{
    if(event == LV_EVENT_DELETE)
    {
        screen_light=NULL;
        qmsd_screen_remove("screen_light");
    }
}

void screen_light_build(void)
{
    if(screen_light) return;
    screen_light = lv_obj_create(NULL, NULL);
    lv_obj_qmsd_set_cb(screen_light, screen_light_qmsd_cb);
    lv_obj_set_style_local_bg_color(screen_light,LV_OBJ_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x31, 0x04, 0x58));

    qmsd_image_li_bottom_create();
    qmsd_image_li_return_create();
    qmsd_label_li_return_create();
    qmsd_image_li_line_create();
    qmsd_image_li_light_create();
    qmsd_image_li_setb_create();
    qmsd_image_li_set_create();
    qmsd_label_li_light_create();
    qmsd_label_li_color_create();
    qmsd_button_li_l_bt_create();
    qmsd_button_li_l_ra_create();
    qmsd_image_li_barl_create();
    qmsd_button_li_c_bt_create();
    qmsd_button_li_c_ra_create();
    qmsd_image_li_barc_create();
    lv_obj_set_event_cb(screen_light,screen_light_del_cb);
    qmsd_screen_register(screen_light,"screen_light");
}

void screen_light_show(void)
{
    if(!screen_light)
    {
        screen_light_build();
    }
    lv_scr_load(screen_light);
}

void screen_light_delete(void)
{
    if(screen_light)
    {
        lv_obj_del(screen_light);
        screen_light = NULL;
    }
}
