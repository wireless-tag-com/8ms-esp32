#include "qmsd_ui_entry.h"
#include "qmsd_internal_ui_cb.h"

lv_obj_t* scr_curtain_ti1;
lv_obj_t* ima_cur_re;
lv_obj_t* lab_cur_le;
lv_obj_t* lab_cur_ri;
lv_obj_t* but_cur_top;
lv_obj_t * __but_cur_top_label;
lv_obj_t* but_cur_bot;
lv_obj_t * __but_cur_bot_label;
lv_obj_t* ima_cur_;
lv_obj_t* ima_cur_cul;
lv_obj_t* ima_cur_cur;
lv_obj_t* ima_cur_op;
lv_obj_t* ima_cur_st;
lv_obj_t* ima_cur_cl;
lv_obj_t* ima_cur_on;
lv_obj_t* ima_cur_op_;
lv_obj_t* ima_cur_st_;
lv_obj_t* ima_cur_cl_;
lv_obj_t* ima_cur_on_;
lv_obj_t* ima_cur_cle;
lv_obj_t* ima_cur_cri;
lv_obj_t* but_cur_le;
lv_obj_t * __but_cur_le_label;
lv_obj_t* but_cur_ri;
lv_obj_t * __but_cur_ri_label;
lv_obj_t* but_cur_ble;
lv_obj_t * __but_cur_ble_label;
lv_obj_t* but_cur_bri;
lv_obj_t * __but_cur_bri_label;


    
void qmsd_ima_cur_re_create()
{
    ima_cur_re = lv_img_create(scr_curtain_ti1, NULL);
    lv_img_set_src(ima_cur_re, &imgchoice_return_png);
#ifdef BLOCKLY_ima_cur_re_EVENT_HANDLER
    lv_obj_set_event_cb(ima_cur_re, __qmsd_ima_cur_re_cb);
#endif
    lv_obj_set_pos(ima_cur_re, 44, 42);
    lv_obj_set_click(ima_cur_re,true);
    lv_obj_set_style_local_image_recolor(ima_cur_re,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(ima_cur_re,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    qmsd_obj_set_id(ima_cur_re,"ima_cur_re");
}
    void qmsd_lab_cur_le_create()
{
	lab_cur_le = lv_label_create(scr_curtain_ti1, NULL);
	lv_label_set_long_mode(lab_cur_le,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(lab_cur_le,true);
	lv_obj_set_size(lab_cur_le, 48, 23);
//set label style
	lv_obj_set_style_local_text_color(lab_cur_le,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(lab_cur_le, "窗帘");
	lv_label_set_align(lab_cur_le, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(lab_cur_le,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_24);
#ifdef BLOCKLY_lab_cur_le_EVENT_HANDLER
	lv_obj_set_event_cb(lab_cur_le, __qmsd_lab_cur_le_cb);
#endif
    lv_obj_set_click(lab_cur_le,true);    
	if(lab_cur_le->coords.x2-lab_cur_le->coords.x1<48)
	{
		int x_offset=(48-(lab_cur_le->coords.x2-lab_cur_le->coords.x1))/2;
		lv_obj_set_style_local_pad_left(lab_cur_le,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(lab_cur_le,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(lab_cur_le->coords.y2-lab_cur_le->coords.y1<23)
	{
		int y_offset=(23-(lab_cur_le->coords.y2-lab_cur_le->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(lab_cur_le,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(lab_cur_le,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(lab_cur_le, 176, 42);
    qmsd_obj_set_id(lab_cur_le,"lab_cur_le");
}
    void qmsd_lab_cur_ri_create()
{
	lab_cur_ri = lv_label_create(scr_curtain_ti1, NULL);
	lv_label_set_long_mode(lab_cur_ri,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(lab_cur_ri,true);
	lv_obj_set_size(lab_cur_ri, 48, 23);
//set label style
	lv_obj_set_style_local_text_color(lab_cur_ri,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(lab_cur_ri, "纱窗");
	lv_label_set_align(lab_cur_ri, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(lab_cur_ri,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_24);
#ifdef BLOCKLY_lab_cur_ri_EVENT_HANDLER
	lv_obj_set_event_cb(lab_cur_ri, __qmsd_lab_cur_ri_cb);
#endif
    lv_obj_set_click(lab_cur_ri,true);    
	if(lab_cur_ri->coords.x2-lab_cur_ri->coords.x1<48)
	{
		int x_offset=(48-(lab_cur_ri->coords.x2-lab_cur_ri->coords.x1))/2;
		lv_obj_set_style_local_pad_left(lab_cur_ri,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(lab_cur_ri,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(lab_cur_ri->coords.y2-lab_cur_ri->coords.y1<23)
	{
		int y_offset=(23-(lab_cur_ri->coords.y2-lab_cur_ri->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(lab_cur_ri,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(lab_cur_ri,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(lab_cur_ri, 262, 42);
    qmsd_obj_set_id(lab_cur_ri,"lab_cur_ri");
}
    void qmsd_but_cur_top_create()
{
    but_cur_top = lv_btn_create(scr_curtain_ti1, NULL);
    __but_cur_top_label = lv_label_create(but_cur_top, NULL);
    lv_label_set_text(__but_cur_top_label,qmsd_lang_get_trans("but_cur_top",""));

    lv_obj_set_style_local_text_font(__but_cur_top_label,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_16);
    lv_obj_set_size(but_cur_top, 1, 20);
    lv_obj_set_pos(but_cur_top, 240, 43);
#ifdef BLOCKLY_but_cur_top_EVENT_HANDLER
    lv_obj_set_event_cb(but_cur_top, __qmsd_but_cur_top_cb);
#endif


    lv_obj_t* obj = but_cur_top;
    int part = LV_BTN_PART_MAIN;
//设置正常样式
        lv_obj_set_style_local_radius(obj,part,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_bg_opa(obj,part,LV_STATE_DEFAULT,153);
    lv_obj_set_style_local_border_color(obj,part,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
    lv_obj_set_style_local_border_opa(obj,part,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_shadow_width(obj,part,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_text_opa(obj,part,LV_STATE_DEFAULT,0);

//设置正常样式结束

//设置按下样式
        lv_obj_set_style_local_border_color(obj,part,LV_STATE_PRESSED,LV_COLOR_MAKE(0xff, 0xff, 0xff));

//设置按下样式结束

//设置禁用样式
        lv_obj_set_style_local_border_color(obj,part,LV_STATE_DISABLED,LV_COLOR_MAKE(0xff, 0xff, 0xff));

//设置禁用样式结束
    lv_obj_set_style_local_outline_width(but_cur_top,LV_BTN_PART_MAIN,LV_STATE_DEFAULT,0);
	lv_obj_set_style_local_outline_width(but_cur_top,LV_BTN_PART_MAIN,LV_STATE_FOCUSED,0);
    qmsd_obj_set_id(but_cur_top,"but_cur_top");
}
    void qmsd_but_cur_bot_create()
{
    but_cur_bot = lv_btn_create(scr_curtain_ti1, NULL);
    __but_cur_bot_label = lv_label_create(but_cur_bot, NULL);
    lv_label_set_text(__but_cur_bot_label,qmsd_lang_get_trans("but_cur_bot",""));

    lv_obj_set_style_local_text_font(__but_cur_bot_label,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_16);
    lv_obj_set_size(but_cur_bot, 23, 3);
    lv_obj_set_pos(but_cur_bot, 189, 74);
#ifdef BLOCKLY_but_cur_bot_EVENT_HANDLER
    lv_obj_set_event_cb(but_cur_bot, __qmsd_but_cur_bot_cb);
#endif


    lv_obj_t* obj = but_cur_bot;
    int part = LV_BTN_PART_MAIN;
//设置正常样式
        lv_obj_set_style_local_bg_color(obj,part,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x24, 0x13, 0xec));
    lv_obj_set_style_local_bg_grad_color(obj,part,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x24, 0x13, 0xec));
    lv_obj_set_style_local_radius(obj,part,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_border_color(obj,part,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
    lv_obj_set_style_local_border_opa(obj,part,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_shadow_width(obj,part,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_text_opa(obj,part,LV_STATE_DEFAULT,0);

//设置正常样式结束

//设置按下样式
        lv_obj_set_style_local_border_color(obj,part,LV_STATE_PRESSED,LV_COLOR_MAKE(0xff, 0xff, 0xff));

//设置按下样式结束

//设置禁用样式
        lv_obj_set_style_local_border_color(obj,part,LV_STATE_DISABLED,LV_COLOR_MAKE(0xff, 0xff, 0xff));

//设置禁用样式结束
    lv_obj_set_style_local_outline_width(but_cur_bot,LV_BTN_PART_MAIN,LV_STATE_DEFAULT,0);
	lv_obj_set_style_local_outline_width(but_cur_bot,LV_BTN_PART_MAIN,LV_STATE_FOCUSED,0);
    qmsd_obj_set_id(but_cur_bot,"but_cur_bot");
}
    
void qmsd_ima_cur__create()
{
    ima_cur_ = lv_img_create(scr_curtain_ti1, NULL);
    lv_img_set_src(ima_cur_, &imgcurtain_curtain_top_png);
#ifdef BLOCKLY_ima_cur__EVENT_HANDLER
    lv_obj_set_event_cb(ima_cur_, __qmsd_ima_cur__cb);
#endif
    lv_obj_set_pos(ima_cur_, 60, 108);
    qmsd_obj_set_id(ima_cur_,"ima_cur_");
}
    
void qmsd_ima_cur_cul_create()
{
    ima_cur_cul = lv_img_create(scr_curtain_ti1, NULL);
    lv_img_set_src(ima_cur_cul, &imgcurtain_curtain_left_png);
#ifdef BLOCKLY_ima_cur_cul_EVENT_HANDLER
    lv_obj_set_event_cb(ima_cur_cul, __qmsd_ima_cur_cul_cb);
#endif
    lv_obj_set_pos(ima_cur_cul, 60, 119);
    qmsd_obj_set_id(ima_cur_cul,"ima_cur_cul");
}
    
void qmsd_ima_cur_cur_create()
{
    ima_cur_cur = lv_img_create(scr_curtain_ti1, NULL);
    lv_img_set_src(ima_cur_cur, &imgcurtain_curtain_right_png);
#ifdef BLOCKLY_ima_cur_cur_EVENT_HANDLER
    lv_obj_set_event_cb(ima_cur_cur, __qmsd_ima_cur_cur_cb);
#endif
    lv_obj_set_pos(ima_cur_cur, 240, 119);
    qmsd_obj_set_id(ima_cur_cur,"ima_cur_cur");
}
    
void qmsd_ima_cur_op_create()
{
    ima_cur_op = lv_img_create(scr_curtain_ti1, NULL);
    lv_img_set_src(ima_cur_op, &imgcurtain_button_off_png);
#ifdef BLOCKLY_ima_cur_op_EVENT_HANDLER
    lv_obj_set_event_cb(ima_cur_op, __qmsd_ima_cur_op_cb);
#endif
    lv_obj_set_pos(ima_cur_op, 72, 360);
    lv_obj_set_click(ima_cur_op,true);
    lv_obj_set_style_local_image_recolor(ima_cur_op,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(ima_cur_op,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    qmsd_obj_set_id(ima_cur_op,"ima_cur_op");
}
    
void qmsd_ima_cur_st_create()
{
    ima_cur_st = lv_img_create(scr_curtain_ti1, NULL);
    lv_img_set_src(ima_cur_st, &imgcurtain_button_off_png);
#ifdef BLOCKLY_ima_cur_st_EVENT_HANDLER
    lv_obj_set_event_cb(ima_cur_st, __qmsd_ima_cur_st_cb);
#endif
    lv_obj_set_pos(ima_cur_st, 169, 360);
    lv_obj_set_click(ima_cur_st,true);
    lv_obj_set_style_local_image_recolor(ima_cur_st,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(ima_cur_st,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    qmsd_obj_set_id(ima_cur_st,"ima_cur_st");
}
    
void qmsd_ima_cur_cl_create()
{
    ima_cur_cl = lv_img_create(scr_curtain_ti1, NULL);
    lv_img_set_src(ima_cur_cl, &imgcurtain_button_off_png);
#ifdef BLOCKLY_ima_cur_cl_EVENT_HANDLER
    lv_obj_set_event_cb(ima_cur_cl, __qmsd_ima_cur_cl_cb);
#endif
    lv_obj_set_pos(ima_cur_cl, 263, 360);
    lv_obj_set_click(ima_cur_cl,true);
    lv_obj_set_style_local_image_recolor(ima_cur_cl,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(ima_cur_cl,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    qmsd_obj_set_id(ima_cur_cl,"ima_cur_cl");
}
    
void qmsd_ima_cur_on_create()
{
    ima_cur_on = lv_img_create(scr_curtain_ti1, NULL);
    lv_img_set_src(ima_cur_on, &imgcurtain_button_off_png);
#ifdef BLOCKLY_ima_cur_on_EVENT_HANDLER
    lv_obj_set_event_cb(ima_cur_on, __qmsd_ima_cur_on_cb);
#endif
    lv_obj_set_pos(ima_cur_on, 358, 360);
    lv_obj_set_click(ima_cur_on,true);
    lv_obj_set_style_local_image_recolor(ima_cur_on,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(ima_cur_on,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    qmsd_obj_set_id(ima_cur_on,"ima_cur_on");
}
    
void qmsd_ima_cur_op__create()
{
    ima_cur_op_ = lv_img_create(scr_curtain_ti1, NULL);
    lv_img_set_src(ima_cur_op_, &imgcurtain_button_open_png);
#ifdef BLOCKLY_ima_cur_op__EVENT_HANDLER
    lv_obj_set_event_cb(ima_cur_op_, __qmsd_ima_cur_op__cb);
#endif
    lv_obj_set_pos(ima_cur_op_, 88, 379);
    lv_obj_set_click(ima_cur_op_,true);
    lv_obj_set_style_local_image_recolor(ima_cur_op_,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(ima_cur_op_,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    qmsd_obj_set_id(ima_cur_op_,"ima_cur_op_");
}
    
void qmsd_ima_cur_st__create()
{
    ima_cur_st_ = lv_img_create(scr_curtain_ti1, NULL);
    lv_img_set_src(ima_cur_st_, &imgcurtain_button_stop_png);
#ifdef BLOCKLY_ima_cur_st__EVENT_HANDLER
    lv_obj_set_event_cb(ima_cur_st_, __qmsd_ima_cur_st__cb);
#endif
    lv_obj_set_pos(ima_cur_st_, 189, 380);
    lv_obj_set_click(ima_cur_st_,true);
    lv_obj_set_style_local_image_recolor(ima_cur_st_,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(ima_cur_st_,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    qmsd_obj_set_id(ima_cur_st_,"ima_cur_st_");
}
    
void qmsd_ima_cur_cl__create()
{
    ima_cur_cl_ = lv_img_create(scr_curtain_ti1, NULL);
    lv_img_set_src(ima_cur_cl_, &imgcurtain_button_close_png);
#ifdef BLOCKLY_ima_cur_cl__EVENT_HANDLER
    lv_obj_set_event_cb(ima_cur_cl_, __qmsd_ima_cur_cl__cb);
#endif
    lv_obj_set_pos(ima_cur_cl_, 280, 379);
    lv_obj_set_click(ima_cur_cl_,true);
    lv_obj_set_style_local_image_recolor(ima_cur_cl_,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(ima_cur_cl_,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    qmsd_obj_set_id(ima_cur_cl_,"ima_cur_cl_");
}
    
void qmsd_ima_cur_on__create()
{
    ima_cur_on_ = lv_img_create(scr_curtain_ti1, NULL);
    lv_img_set_src(ima_cur_on_, &imgcurtain_button_all_png);
#ifdef BLOCKLY_ima_cur_on__EVENT_HANDLER
    lv_obj_set_event_cb(ima_cur_on_, __qmsd_ima_cur_on__cb);
#endif
    lv_obj_set_pos(ima_cur_on_, 369, 369);
    lv_obj_set_click(ima_cur_on_,true);
    lv_obj_set_style_local_image_recolor(ima_cur_on_,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(ima_cur_on_,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    qmsd_obj_set_id(ima_cur_on_,"ima_cur_on_");
}
    
void qmsd_ima_cur_cle_create()
{
    ima_cur_cle = lv_img_create(scr_curtain_ti1, NULL);
    lv_img_set_src(ima_cur_cle, &imgcurtain_curtain_cloth_png);
#ifdef BLOCKLY_ima_cur_cle_EVENT_HANDLER
    lv_obj_set_event_cb(ima_cur_cle, __qmsd_ima_cur_cle_cb);
#endif
    lv_obj_set_pos(ima_cur_cle, 60, 119);
    qmsd_obj_set_id(ima_cur_cle,"ima_cur_cle");
}
    
void qmsd_ima_cur_cri_create()
{
    ima_cur_cri = lv_img_create(scr_curtain_ti1, NULL);
    lv_img_set_src(ima_cur_cri, &imgcurtain_curtain_cloth_png);
#ifdef BLOCKLY_ima_cur_cri_EVENT_HANDLER
    lv_obj_set_event_cb(ima_cur_cri, __qmsd_ima_cur_cri_cb);
#endif
    lv_obj_set_pos(ima_cur_cri, 257, 119);
    qmsd_obj_set_id(ima_cur_cri,"ima_cur_cri");
}
    void qmsd_but_cur_le_create()
{
    but_cur_le = lv_btn_create(scr_curtain_ti1, NULL);
    __but_cur_le_label = lv_label_create(but_cur_le, NULL);
    lv_label_set_text(__but_cur_le_label,qmsd_lang_get_trans("but_cur_le",""));

    lv_obj_set_style_local_text_font(__but_cur_le_label,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_16);
    lv_obj_set_size(but_cur_le, 9, 9);
    lv_obj_set_pos(but_cur_le, 225, 445);
#ifdef BLOCKLY_but_cur_le_EVENT_HANDLER
    lv_obj_set_event_cb(but_cur_le, __qmsd_but_cur_le_cb);
#endif


    lv_obj_t* obj = but_cur_le;
    int part = LV_BTN_PART_MAIN;
//设置正常样式
        lv_obj_set_style_local_radius(obj,part,LV_STATE_DEFAULT,10);
    lv_obj_set_style_local_border_color(obj,part,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
    lv_obj_set_style_local_border_opa(obj,part,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_shadow_width(obj,part,LV_STATE_DEFAULT,0);

//设置正常样式结束

//设置按下样式
        lv_obj_set_style_local_border_color(obj,part,LV_STATE_PRESSED,LV_COLOR_MAKE(0xff, 0xff, 0xff));
    lv_obj_set_style_local_border_opa(obj,part,LV_STATE_PRESSED,0);
    lv_obj_set_style_local_shadow_width(obj,part,LV_STATE_PRESSED,0);

//设置按下样式结束

//设置禁用样式
        lv_obj_set_style_local_border_color(obj,part,LV_STATE_DISABLED,LV_COLOR_MAKE(0xff, 0xff, 0xff));

//设置禁用样式结束
    lv_obj_set_style_local_outline_width(but_cur_le,LV_BTN_PART_MAIN,LV_STATE_DEFAULT,0);
	lv_obj_set_style_local_outline_width(but_cur_le,LV_BTN_PART_MAIN,LV_STATE_FOCUSED,0);
    qmsd_obj_set_id(but_cur_le,"but_cur_le");
}
    void qmsd_but_cur_ri_create()
{
    but_cur_ri = lv_btn_create(scr_curtain_ti1, NULL);
    __but_cur_ri_label = lv_label_create(but_cur_ri, NULL);
    lv_label_set_text(__but_cur_ri_label,qmsd_lang_get_trans("but_cur_ri",""));

    lv_obj_set_style_local_text_font(__but_cur_ri_label,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_16);
    lv_obj_set_size(but_cur_ri, 9, 9);
    lv_obj_set_pos(but_cur_ri, 247, 445);
#ifdef BLOCKLY_but_cur_ri_EVENT_HANDLER
    lv_obj_set_event_cb(but_cur_ri, __qmsd_but_cur_ri_cb);
#endif


    lv_obj_t* obj = but_cur_ri;
    int part = LV_BTN_PART_MAIN;
//设置正常样式
        lv_obj_set_style_local_radius(obj,part,LV_STATE_DEFAULT,10);
    lv_obj_set_style_local_border_color(obj,part,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
    lv_obj_set_style_local_border_opa(obj,part,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_shadow_width(obj,part,LV_STATE_DEFAULT,0);

//设置正常样式结束

//设置按下样式
        lv_obj_set_style_local_border_color(obj,part,LV_STATE_PRESSED,LV_COLOR_MAKE(0xff, 0xff, 0xff));
    lv_obj_set_style_local_border_opa(obj,part,LV_STATE_PRESSED,0);
    lv_obj_set_style_local_shadow_width(obj,part,LV_STATE_PRESSED,0);

//设置按下样式结束

//设置禁用样式
        lv_obj_set_style_local_border_color(obj,part,LV_STATE_DISABLED,LV_COLOR_MAKE(0xff, 0xff, 0xff));

//设置禁用样式结束
    lv_obj_set_style_local_outline_width(but_cur_ri,LV_BTN_PART_MAIN,LV_STATE_DEFAULT,0);
	lv_obj_set_style_local_outline_width(but_cur_ri,LV_BTN_PART_MAIN,LV_STATE_FOCUSED,0);
    qmsd_obj_set_id(but_cur_ri,"but_cur_ri");
}
    void qmsd_but_cur_ble_create()
{
    but_cur_ble = lv_btn_create(scr_curtain_ti1, NULL);
    __but_cur_ble_label = lv_label_create(but_cur_ble, NULL);
    lv_label_set_text(__but_cur_ble_label,qmsd_lang_get_trans("but_cur_ble",""));

    lv_obj_set_style_local_text_font(__but_cur_ble_label,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_16);
    lv_obj_set_size(but_cur_ble, 60, 250);
    lv_obj_set_pos(but_cur_ble, 0, 108);
#ifdef BLOCKLY_but_cur_ble_EVENT_HANDLER
    lv_obj_set_event_cb(but_cur_ble, __qmsd_but_cur_ble_cb);
#endif


    lv_obj_t* obj = but_cur_ble;
    int part = LV_BTN_PART_MAIN;
//设置正常样式
        lv_obj_set_style_local_bg_color(obj,part,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x20, 0x20, 0x20));
    lv_obj_set_style_local_bg_grad_color(obj,part,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x20, 0x20, 0x20));
    lv_obj_set_style_local_radius(obj,part,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_border_color(obj,part,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
    lv_obj_set_style_local_border_opa(obj,part,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_shadow_width(obj,part,LV_STATE_DEFAULT,0);

//设置正常样式结束

//设置按下样式
        lv_obj_set_style_local_radius(obj,part,LV_STATE_PRESSED,0);
    lv_obj_set_style_local_border_color(obj,part,LV_STATE_PRESSED,LV_COLOR_MAKE(0xff, 0xff, 0xff));
    lv_obj_set_style_local_border_opa(obj,part,LV_STATE_PRESSED,0);
    lv_obj_set_style_local_shadow_width(obj,part,LV_STATE_PRESSED,0);

//设置按下样式结束

//设置禁用样式
        lv_obj_set_style_local_border_color(obj,part,LV_STATE_DISABLED,LV_COLOR_MAKE(0xff, 0xff, 0xff));

//设置禁用样式结束
    lv_obj_set_style_local_outline_width(but_cur_ble,LV_BTN_PART_MAIN,LV_STATE_DEFAULT,0);
	lv_obj_set_style_local_outline_width(but_cur_ble,LV_BTN_PART_MAIN,LV_STATE_FOCUSED,0);
    qmsd_obj_set_id(but_cur_ble,"but_cur_ble");
}
    void qmsd_but_cur_bri_create()
{
    but_cur_bri = lv_btn_create(scr_curtain_ti1, NULL);
    __but_cur_bri_label = lv_label_create(but_cur_bri, NULL);
    lv_label_set_text(__but_cur_bri_label,qmsd_lang_get_trans("but_cur_bri",""));

    lv_obj_set_style_local_text_font(__but_cur_bri_label,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_16);
    lv_obj_set_size(but_cur_bri, 60, 250);
    lv_obj_set_pos(but_cur_bri, 420, 108);
#ifdef BLOCKLY_but_cur_bri_EVENT_HANDLER
    lv_obj_set_event_cb(but_cur_bri, __qmsd_but_cur_bri_cb);
#endif


    lv_obj_t* obj = but_cur_bri;
    int part = LV_BTN_PART_MAIN;
//设置正常样式
        lv_obj_set_style_local_bg_color(obj,part,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x20, 0x20, 0x20));
    lv_obj_set_style_local_bg_grad_color(obj,part,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x20, 0x20, 0x20));
    lv_obj_set_style_local_radius(obj,part,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_border_color(obj,part,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
    lv_obj_set_style_local_border_opa(obj,part,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_shadow_width(obj,part,LV_STATE_DEFAULT,0);

//设置正常样式结束

//设置按下样式
        lv_obj_set_style_local_radius(obj,part,LV_STATE_PRESSED,0);
    lv_obj_set_style_local_border_color(obj,part,LV_STATE_PRESSED,LV_COLOR_MAKE(0xff, 0xff, 0xff));
    lv_obj_set_style_local_border_opa(obj,part,LV_STATE_PRESSED,0);
    lv_obj_set_style_local_shadow_width(obj,part,LV_STATE_PRESSED,0);

//设置按下样式结束

//设置禁用样式
        lv_obj_set_style_local_border_color(obj,part,LV_STATE_DISABLED,LV_COLOR_MAKE(0xff, 0xff, 0xff));

//设置禁用样式结束
    lv_obj_set_style_local_outline_width(but_cur_bri,LV_BTN_PART_MAIN,LV_STATE_DEFAULT,0);
	lv_obj_set_style_local_outline_width(but_cur_bri,LV_BTN_PART_MAIN,LV_STATE_FOCUSED,0);
    qmsd_obj_set_id(but_cur_bri,"but_cur_bri");
}

static void scr_curtain_ti1_qmsd_cb(lv_obj_t * obj, lv_event_t event, void *data)
{/*
    char *trans;
    lv_label_set_text(lab_cur_le,qmsd_lang_get_trans("lab_cur_le","窗帘"));
    lv_label_set_text(lab_cur_ri,qmsd_lang_get_trans("lab_cur_ri","纱窗"));
    lv_label_set_text(__but_cur_top_label,qmsd_lang_get_trans("but_cur_top",""));
    lv_label_set_text(__but_cur_bot_label,qmsd_lang_get_trans("but_cur_bot",""));
    lv_label_set_text(__but_cur_le_label,qmsd_lang_get_trans("but_cur_le",""));
    lv_label_set_text(__but_cur_ri_label,qmsd_lang_get_trans("but_cur_ri",""));
    lv_label_set_text(__but_cur_ble_label,qmsd_lang_get_trans("but_cur_ble",""));
    lv_label_set_text(__but_cur_bri_label,qmsd_lang_get_trans("but_cur_bri",""));
*/
#ifdef BLOCKLY_scr_curtain_ti1_SCREEN_INIT
    __qmsd_scr_curtain_ti1_init();
#endif
}

static void scr_curtain_ti1_del_cb(lv_obj_t* obj,lv_event_t event)
{
    if(event == LV_EVENT_DELETE)
    {
        scr_curtain_ti1=NULL;
        qmsd_screen_remove("scr_curtain_ti1");
    }
}

void scr_curtain_ti1_build(void)
{
    if(scr_curtain_ti1) return;
    scr_curtain_ti1 = lv_obj_create(NULL, NULL);
    lv_obj_qmsd_set_cb(scr_curtain_ti1, scr_curtain_ti1_qmsd_cb);
    lv_obj_set_style_local_bg_color(scr_curtain_ti1,LV_OBJ_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x20, 0x20, 0x20));

    qmsd_ima_cur_re_create();
    qmsd_lab_cur_le_create();
    qmsd_lab_cur_ri_create();
    qmsd_but_cur_top_create();
    qmsd_but_cur_bot_create();
    qmsd_ima_cur__create();
    qmsd_ima_cur_cul_create();
    qmsd_ima_cur_cur_create();
    qmsd_ima_cur_op_create();
    qmsd_ima_cur_st_create();
    qmsd_ima_cur_cl_create();
    qmsd_ima_cur_on_create();
    qmsd_ima_cur_op__create();
    qmsd_ima_cur_st__create();
    qmsd_ima_cur_cl__create();
    qmsd_ima_cur_on__create();
    qmsd_ima_cur_cle_create();
    qmsd_ima_cur_cri_create();
    qmsd_but_cur_le_create();
    qmsd_but_cur_ri_create();
    qmsd_but_cur_ble_create();
    qmsd_but_cur_bri_create();
    lv_obj_set_event_cb(scr_curtain_ti1,scr_curtain_ti1_del_cb);
    qmsd_screen_register(scr_curtain_ti1,"scr_curtain_ti1");
}

void scr_curtain_ti1_show(void)
{
    if(!scr_curtain_ti1)
    {
        scr_curtain_ti1_build();
    }
    lv_scr_load(scr_curtain_ti1);
}

void scr_curtain_ti1_delete(void)
{
    if(scr_curtain_ti1)
    {
        lv_obj_del(scr_curtain_ti1);
        scr_curtain_ti1 = NULL;
    }
}
