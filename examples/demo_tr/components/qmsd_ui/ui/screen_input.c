#include "qmsd_ui_entry.h"
#include "qmsd_internal_ui_cb.h"

lv_obj_t* screen_input;
lv_obj_t* ima_inp_re;
lv_obj_t* lab_inp_lab;
lv_obj_t* but_inp_inp;
lv_obj_t * __but_inp_inp_label;
lv_obj_t* tex_inp_tex;


    
void qmsd_ima_inp_re_create()
{
    ima_inp_re = lv_img_create(screen_input, NULL);
    lv_img_set_src(ima_inp_re, &imgchoice_return_png);
#ifdef BLOCKLY_ima_inp_re_EVENT_HANDLER
    lv_obj_set_event_cb(ima_inp_re, __qmsd_ima_inp_re_cb);
#endif
    lv_obj_set_pos(ima_inp_re, 44, 42);
    qmsd_obj_set_id(ima_inp_re,"ima_inp_re");
}
    void qmsd_lab_inp_lab_create()
{
	lab_inp_lab = lv_label_create(screen_input, NULL);
	lv_label_set_long_mode(lab_inp_lab,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(lab_inp_lab,true);
	lv_obj_set_size(lab_inp_lab, 153, 23);
//set label style
	lv_obj_set_style_local_text_color(lab_inp_lab,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(lab_inp_lab, "连接WIFI网络");
	lv_label_set_align(lab_inp_lab, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(lab_inp_lab,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_24);
#ifdef BLOCKLY_lab_inp_lab_EVENT_HANDLER
	lv_obj_set_event_cb(lab_inp_lab, __qmsd_lab_inp_lab_cb);
#endif
	if(lab_inp_lab->coords.x2-lab_inp_lab->coords.x1<153)
	{
		int x_offset=(153-(lab_inp_lab->coords.x2-lab_inp_lab->coords.x1))/2;
		lv_obj_set_style_local_pad_left(lab_inp_lab,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(lab_inp_lab,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(lab_inp_lab->coords.y2-lab_inp_lab->coords.y1<23)
	{
		int y_offset=(23-(lab_inp_lab->coords.y2-lab_inp_lab->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(lab_inp_lab,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(lab_inp_lab,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(lab_inp_lab, 168, 32);
    qmsd_obj_set_id(lab_inp_lab,"lab_inp_lab");
}
    void qmsd_but_inp_inp_create()
{
    but_inp_inp = lv_btn_create(screen_input, NULL);
    __but_inp_inp_label = lv_label_create(but_inp_inp, NULL);
    lv_label_set_text(__but_inp_inp_label,qmsd_lang_get_trans("but_inp_inp","加入"));

    lv_obj_set_style_local_text_color(__but_inp_inp_label,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
    lv_obj_set_style_local_text_font(__but_inp_inp_label,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_16);
    lv_obj_set_size(but_inp_inp, 63, 30);
    lv_obj_set_pos(but_inp_inp, 395, 30);
#ifdef BLOCKLY_but_inp_inp_EVENT_HANDLER
    lv_obj_set_event_cb(but_inp_inp, __qmsd_but_inp_inp_cb);
#endif


    lv_obj_t* obj = but_inp_inp;
    int part = LV_BTN_PART_MAIN;
//设置正常样式
        lv_obj_set_style_local_bg_color(obj,part,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x9b, 0x9b, 0x9b));
    lv_obj_set_style_local_bg_grad_color(obj,part,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x9b, 0x9b, 0x9b));
    lv_obj_set_style_local_radius(obj,part,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_border_color(obj,part,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
    lv_obj_set_style_local_border_opa(obj,part,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_shadow_width(obj,part,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_bg_color(obj,part,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x00, 0x00, 0x00));
    lv_obj_set_style_local_text_font(obj,part,LV_STATE_DEFAULT,&ali_font_16);

//设置正常样式结束

//设置按下样式
        lv_obj_set_style_local_bg_color(obj,part,LV_STATE_PRESSED,LV_COLOR_MAKE(0xf5, 0xa6, 0x23));
    lv_obj_set_style_local_bg_grad_color(obj,part,LV_STATE_PRESSED,LV_COLOR_MAKE(0xf5, 0xa6, 0x23));
    lv_obj_set_style_local_radius(obj,part,LV_STATE_PRESSED,0);
    lv_obj_set_style_local_border_color(obj,part,LV_STATE_PRESSED,LV_COLOR_MAKE(0xff, 0xff, 0xff));
    lv_obj_set_style_local_border_opa(obj,part,LV_STATE_PRESSED,0);
    lv_obj_set_style_local_shadow_width(obj,part,LV_STATE_PRESSED,0);
    lv_obj_set_style_local_bg_color(obj,part,LV_STATE_PRESSED,LV_COLOR_MAKE(0x00, 0x00, 0x00));
    lv_obj_set_style_local_text_font(obj,part,LV_STATE_PRESSED,&ali_font_16);

//设置按下样式结束

//设置禁用样式
        lv_obj_set_style_local_border_color(obj,part,LV_STATE_DISABLED,LV_COLOR_MAKE(0xff, 0xff, 0xff));

//设置禁用样式结束
    lv_obj_set_style_local_outline_width(but_inp_inp,LV_BTN_PART_MAIN,LV_STATE_DEFAULT,0);
	lv_obj_set_style_local_outline_width(but_inp_inp,LV_BTN_PART_MAIN,LV_STATE_FOCUSED,0);
    qmsd_obj_set_id(but_inp_inp,"but_inp_inp");
}
    void qmsd_tex_inp_tex_create()
{
	tex_inp_tex = lv_textarea_create(screen_input, NULL);
	lv_textarea_set_text(tex_inp_tex, "");
	lv_textarea_set_placeholder_text(tex_inp_tex, "输入密码...");
	lv_textarea_set_pwd_mode(tex_inp_tex, false);
	lv_textarea_set_one_line(tex_inp_tex, false);
	lv_obj_set_style_local_bg_color(tex_inp_tex,LV_TEXTAREA_PART_BG,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x14, 0x14, 0x14));
	lv_obj_set_style_local_text_color(tex_inp_tex,LV_TEXTAREA_PART_BG,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
	lv_obj_set_size(tex_inp_tex, 403, 53);
    lv_obj_set_pos(tex_inp_tex, 45, 140);
#ifdef BLOCKLY_tex_inp_tex_EVENT_HANDLER
	lv_obj_set_event_cb(tex_inp_tex, __qmsd_tex_inp_tex_cb);
#endif
	g_create_kb_ifneeded();
    qmsd_obj_set_id(tex_inp_tex,"tex_inp_tex");
}

static void screen_input_qmsd_cb(lv_obj_t * obj, lv_event_t event, void *data)
{/*
    char *trans;
    lv_label_set_text(lab_inp_lab,qmsd_lang_get_trans("lab_inp_lab","连接WIFI网络"));
    lv_label_set_text(__but_inp_inp_label,qmsd_lang_get_trans("but_inp_inp","加入"));
*/
#ifdef BLOCKLY_screen_input_SCREEN_INIT
    __qmsd_screen_input_init();
#endif
}

static void screen_input_del_cb(lv_obj_t* obj,lv_event_t event)
{
    if(event == LV_EVENT_DELETE)
    {
        screen_input=NULL;
        qmsd_screen_remove("screen_input");
    }
}

void screen_input_build(void)
{
    if(screen_input) return;
    screen_input = lv_obj_create(NULL, NULL);
    lv_obj_qmsd_set_cb(screen_input, screen_input_qmsd_cb);
    lv_obj_set_style_local_bg_color(screen_input,LV_OBJ_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x20, 0x20, 0x20));

    qmsd_ima_inp_re_create();
    qmsd_lab_inp_lab_create();
    qmsd_but_inp_inp_create();
    qmsd_tex_inp_tex_create();
    lv_obj_set_event_cb(screen_input,screen_input_del_cb);
    qmsd_screen_register(screen_input,"screen_input");
}

void screen_input_show(void)
{
    if(!screen_input)
    {
        screen_input_build();
    }
    lv_scr_load(screen_input);
}

void screen_input_delete(void)
{
    if(screen_input)
    {
        lv_obj_del(screen_input);
        screen_input = NULL;
    }
}
