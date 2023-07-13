#include "qmsd_ui_entry.h"
#include "qmsd_internal_ui_cb.h"

lv_obj_t* screen_cont;
lv_obj_t* ima_con_bot;
lv_obj_t* ima_con_re;
lv_obj_t* ima_con_set;
lv_obj_t* ima_con_mor;
lv_obj_t* lab_con_re;
lv_obj_t* lab_con_set;
lv_obj_t* lab_con_mor;
lv_obj_t* ima_con_sign;


    
void qmsd_ima_con_bot_create()
{
    ima_con_bot = lv_img_create(screen_cont, NULL);
    lv_img_set_src(ima_con_bot, &imgcontlink_bottom_png);
#ifdef BLOCKLY_ima_con_bot_EVENT_HANDLER
    lv_obj_set_event_cb(ima_con_bot, __qmsd_ima_con_bot_cb);
#endif
    lv_obj_set_pos(ima_con_bot, 0, 0);
    qmsd_obj_set_id(ima_con_bot,"ima_con_bot");
}
    
void qmsd_ima_con_re_create()
{
    ima_con_re = lv_img_create(screen_cont, NULL);
    lv_img_set_src(ima_con_re, &imgcontlink_main_home_png);
#ifdef BLOCKLY_ima_con_re_EVENT_HANDLER
    lv_obj_set_event_cb(ima_con_re, __qmsd_ima_con_re_cb);
#endif
    lv_obj_set_pos(ima_con_re, 87, 82);
    lv_obj_set_click(ima_con_re,true);
    lv_obj_set_style_local_image_recolor(ima_con_re,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(ima_con_re,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    qmsd_obj_set_id(ima_con_re,"ima_con_re");
}
    
void qmsd_ima_con_set_create()
{
    ima_con_set = lv_img_create(screen_cont, NULL);
    lv_img_set_src(ima_con_set, &imgcontlink_main_set_png);
#ifdef BLOCKLY_ima_con_set_EVENT_HANDLER
    lv_obj_set_event_cb(ima_con_set, __qmsd_ima_con_set_cb);
#endif
    lv_obj_set_pos(ima_con_set, 218, 81);
    lv_obj_set_click(ima_con_set,true);
    lv_obj_set_style_local_image_recolor(ima_con_set,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(ima_con_set,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    qmsd_obj_set_id(ima_con_set,"ima_con_set");
}
    
void qmsd_ima_con_mor_create()
{
    ima_con_mor = lv_img_create(screen_cont, NULL);
    lv_img_set_src(ima_con_mor, &imgcontlink_main_more_png);
#ifdef BLOCKLY_ima_con_mor_EVENT_HANDLER
    lv_obj_set_event_cb(ima_con_mor, __qmsd_ima_con_mor_cb);
#endif
    lv_obj_set_pos(ima_con_mor, 338, 81);
    lv_obj_set_click(ima_con_mor,true);
    lv_obj_set_style_local_image_recolor(ima_con_mor,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(ima_con_mor,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    qmsd_obj_set_id(ima_con_mor,"ima_con_mor");
}
    void qmsd_lab_con_re_create()
{
	lab_con_re = lv_label_create(screen_cont, NULL);
	lv_label_set_long_mode(lab_con_re,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(lab_con_re,true);
	lv_obj_set_size(lab_con_re, 41, 19);
//set label style
	lv_obj_set_style_local_text_color(lab_con_re,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(lab_con_re, "首页");
	lv_label_set_align(lab_con_re, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(lab_con_re,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_20);
#ifdef BLOCKLY_lab_con_re_EVENT_HANDLER
	lv_obj_set_event_cb(lab_con_re, __qmsd_lab_con_re_cb);
#endif
    lv_obj_set_click(lab_con_re,true);    
	if(lab_con_re->coords.x2-lab_con_re->coords.x1<41)
	{
		int x_offset=(41-(lab_con_re->coords.x2-lab_con_re->coords.x1))/2;
		lv_obj_set_style_local_pad_left(lab_con_re,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(lab_con_re,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(lab_con_re->coords.y2-lab_con_re->coords.y1<19)
	{
		int y_offset=(19-(lab_con_re->coords.y2-lab_con_re->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(lab_con_re,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(lab_con_re,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(lab_con_re, 95, 157);
    qmsd_obj_set_id(lab_con_re,"lab_con_re");
}
    void qmsd_lab_con_set_create()
{
	lab_con_set = lv_label_create(screen_cont, NULL);
	lv_label_set_long_mode(lab_con_set,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(lab_con_set,true);
	lv_obj_set_size(lab_con_set, 41, 19);
//set label style
	lv_obj_set_style_local_text_color(lab_con_set,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(lab_con_set, "设置");
	lv_label_set_align(lab_con_set, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(lab_con_set,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_20);
#ifdef BLOCKLY_lab_con_set_EVENT_HANDLER
	lv_obj_set_event_cb(lab_con_set, __qmsd_lab_con_set_cb);
#endif
    lv_obj_set_click(lab_con_set,true);    
	if(lab_con_set->coords.x2-lab_con_set->coords.x1<41)
	{
		int x_offset=(41-(lab_con_set->coords.x2-lab_con_set->coords.x1))/2;
		lv_obj_set_style_local_pad_left(lab_con_set,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(lab_con_set,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(lab_con_set->coords.y2-lab_con_set->coords.y1<19)
	{
		int y_offset=(19-(lab_con_set->coords.y2-lab_con_set->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(lab_con_set,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(lab_con_set,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(lab_con_set, 220, 157);
    qmsd_obj_set_id(lab_con_set,"lab_con_set");
}
    void qmsd_lab_con_mor_create()
{
	lab_con_mor = lv_label_create(screen_cont, NULL);
	lv_label_set_long_mode(lab_con_mor,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(lab_con_mor,true);
	lv_obj_set_size(lab_con_mor, 41, 19);
//set label style
	lv_obj_set_style_local_text_color(lab_con_mor,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(lab_con_mor, "模式");
	lv_label_set_align(lab_con_mor, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(lab_con_mor,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_20);
#ifdef BLOCKLY_lab_con_mor_EVENT_HANDLER
	lv_obj_set_event_cb(lab_con_mor, __qmsd_lab_con_mor_cb);
#endif
    lv_obj_set_click(lab_con_mor,true);    
	if(lab_con_mor->coords.x2-lab_con_mor->coords.x1<41)
	{
		int x_offset=(41-(lab_con_mor->coords.x2-lab_con_mor->coords.x1))/2;
		lv_obj_set_style_local_pad_left(lab_con_mor,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(lab_con_mor,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(lab_con_mor->coords.y2-lab_con_mor->coords.y1<19)
	{
		int y_offset=(19-(lab_con_mor->coords.y2-lab_con_mor->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(lab_con_mor,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(lab_con_mor,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(lab_con_mor, 341, 157);
    qmsd_obj_set_id(lab_con_mor,"lab_con_mor");
}
    
void qmsd_ima_con_sign_create()
{
    ima_con_sign = lv_img_create(screen_cont, NULL);
    lv_img_set_src(ima_con_sign, &imgcontlink_sign_png);
#ifdef BLOCKLY_ima_con_sign_EVENT_HANDLER
    lv_obj_set_event_cb(ima_con_sign, __qmsd_ima_con_sign_cb);
#endif
    lv_obj_set_pos(ima_con_sign, 224, 352);
    qmsd_obj_set_id(ima_con_sign,"ima_con_sign");
}

static void screen_cont_qmsd_cb(lv_obj_t * obj, lv_event_t event, void *data)
{/*
    char *trans;
    lv_label_set_text(lab_con_re,qmsd_lang_get_trans("lab_con_re","首页"));
    lv_label_set_text(lab_con_set,qmsd_lang_get_trans("lab_con_set","设置"));
    lv_label_set_text(lab_con_mor,qmsd_lang_get_trans("lab_con_mor","模式"));
*/
#ifdef BLOCKLY_screen_cont_SCREEN_INIT
    __qmsd_screen_cont_init();
#endif
}

void screen_cont_cont_cb(lv_obj_t* obj,lv_event_t event)
{
    if(event == LV_EVENT_DELETE)
    {
        screen_cont = NULL;
        qmsd_screen_remove("screen_cont");
    }
#ifdef BLOCKLY_screen_cont_EVENT_HANDLER
	__qmsd_screen_cont_cb(obj,event);
#endif
}

lv_obj_t* screen_cont_build(lv_obj_t* parent)
{
    if(!screen_cont)
    {
        screen_cont = lv_cont_create(parent, NULL);
        lv_obj_set_size(screen_cont,480,378);
        lv_obj_set_pos(screen_cont,0,0);
        lv_obj_set_event_cb(screen_cont,screen_cont_cont_cb);
        qmsd_ima_con_bot_create();
        lv_page_glue_obj(ima_con_bot,true);
        qmsd_ima_con_re_create();
        lv_page_glue_obj(ima_con_re,true);
        qmsd_ima_con_set_create();
        lv_page_glue_obj(ima_con_set,true);
        qmsd_ima_con_mor_create();
        lv_page_glue_obj(ima_con_mor,true);
        qmsd_lab_con_re_create();
        lv_page_glue_obj(lab_con_re,true);
        qmsd_lab_con_set_create();
        lv_page_glue_obj(lab_con_set,true);
        qmsd_lab_con_mor_create();
        lv_page_glue_obj(lab_con_mor,true);
        qmsd_ima_con_sign_create();
        lv_page_glue_obj(ima_con_sign,true);
        lv_obj_set_style_local_bg_color(screen_cont,LV_PAGE_PART_BG,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x20, 0x20, 0x20));
        qmsd_screen_register(screen_cont,"screen_cont");
        return screen_cont;
    }
    return NULL;
}

void screen_cont_show(void)
{

}

void screen_cont_delete(void)
{
    if(screen_cont)
    {
        lv_obj_del(screen_cont);
        screen_cont = NULL;
    }
}
