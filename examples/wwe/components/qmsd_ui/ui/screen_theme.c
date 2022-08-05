#include "qmsd_ui_entry.h"
#include "qmsd_internal_ui_cb.h"

lv_obj_t* screen_theme;
lv_obj_t* image_themeback;
lv_obj_t* image_theme_1;
lv_obj_t* image_theme_2;
lv_obj_t* image_theme_3;
lv_obj_t* label_226a;
lv_obj_t* label_a4ee;
lv_obj_t* label_e877;
lv_obj_t* label_adfc;


    
void qmsd_image_themeback_create()
{
    image_themeback = lv_img_create(screen_theme, NULL);
    lv_img_set_src(image_themeback, &imgback_png);
#ifdef BLOCKLY_image_themeback_EVENT_HANDLER
    lv_obj_set_event_cb(image_themeback, __qmsd_image_themeback_cb);
#endif
    lv_obj_set_pos(image_themeback, 37, 34);
    lv_obj_set_click(image_themeback,true);
    lv_obj_set_style_local_image_recolor(image_themeback,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(image_themeback,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    lv_obj_set_ext_click_area(image_themeback,20,20,20,20);
    qmsd_obj_set_id(image_themeback,"image_themeback");
}
    
void qmsd_image_theme_1_create()
{
    image_theme_1 = lv_img_create(screen_theme, NULL);
    lv_img_set_src(image_theme_1, &imgtheme_4_png);
#ifdef BLOCKLY_image_theme_1_EVENT_HANDLER
    lv_obj_set_event_cb(image_theme_1, __qmsd_image_theme_1_cb);
#endif
    lv_obj_set_pos(image_theme_1, 51, 114);
    lv_obj_set_click(image_theme_1,true);
    lv_obj_set_style_local_image_recolor(image_theme_1,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(image_theme_1,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    qmsd_obj_set_id(image_theme_1,"image_theme_1");
}
    
void qmsd_image_theme_2_create()
{
    image_theme_2 = lv_img_create(screen_theme, NULL);
    lv_img_set_src(image_theme_2, &imgtheme_2_png);
#ifdef BLOCKLY_image_theme_2_EVENT_HANDLER
    lv_obj_set_event_cb(image_theme_2, __qmsd_image_theme_2_cb);
#endif
    lv_obj_set_pos(image_theme_2, 265, 114);
    lv_obj_set_click(image_theme_2,true);
    lv_obj_set_style_local_image_recolor(image_theme_2,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(image_theme_2,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    qmsd_obj_set_id(image_theme_2,"image_theme_2");
}
    
void qmsd_image_theme_3_create()
{
    image_theme_3 = lv_img_create(screen_theme, NULL);
    lv_img_set_src(image_theme_3, &imgtheme_3_png);
#ifdef BLOCKLY_image_theme_3_EVENT_HANDLER
    lv_obj_set_event_cb(image_theme_3, __qmsd_image_theme_3_cb);
#endif
    lv_obj_set_pos(image_theme_3, 50, 295);
    lv_obj_set_click(image_theme_3,true);
    lv_obj_set_style_local_image_recolor(image_theme_3,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(image_theme_3,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    qmsd_obj_set_id(image_theme_3,"image_theme_3");
}
    void qmsd_label_226a_create()
{
	label_226a = lv_label_create(screen_theme, NULL);
	lv_label_set_long_mode(label_226a,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_226a,true);
	lv_obj_set_size(label_226a, 100, 40);
//set label style
	lv_obj_set_style_local_bg_color(label_226a,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x00, 0x00, 0x00));
	lv_obj_set_style_local_bg_opa(label_226a,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,255);
	lv_obj_set_style_local_text_color(label_226a,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(label_226a, "时尚黑");
	lv_label_set_align(label_226a, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(label_226a,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_23);
#ifdef BLOCKLY_label_226a_EVENT_HANDLER
	lv_obj_set_event_cb(label_226a, __qmsd_label_226a_cb);
#endif
	if(label_226a->coords.x2-label_226a->coords.x1<100)
	{
		int x_offset=(100-(label_226a->coords.x2-label_226a->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_226a,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_226a,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_226a->coords.y2-label_226a->coords.y1<40)
	{
		int y_offset=(40-(label_226a->coords.y2-label_226a->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_226a,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_226a,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(label_226a, 83, 244);
    qmsd_obj_set_id(label_226a,"label_226a");
}
    void qmsd_label_a4ee_create()
{
	label_a4ee = lv_label_create(screen_theme, NULL);
	lv_label_set_long_mode(label_a4ee,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_a4ee,true);
	lv_obj_set_size(label_a4ee, 100, 40);
//set label style
	lv_obj_set_style_local_text_color(label_a4ee,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(label_a4ee, "科技蓝");
	lv_label_set_align(label_a4ee, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(label_a4ee,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_23);
#ifdef BLOCKLY_label_a4ee_EVENT_HANDLER
	lv_obj_set_event_cb(label_a4ee, __qmsd_label_a4ee_cb);
#endif
	if(label_a4ee->coords.x2-label_a4ee->coords.x1<100)
	{
		int x_offset=(100-(label_a4ee->coords.x2-label_a4ee->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_a4ee,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_a4ee,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_a4ee->coords.y2-label_a4ee->coords.y1<40)
	{
		int y_offset=(40-(label_a4ee->coords.y2-label_a4ee->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_a4ee,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_a4ee,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(label_a4ee, 297, 244);
    qmsd_obj_set_id(label_a4ee,"label_a4ee");
}
    void qmsd_label_e877_create()
{
	label_e877 = lv_label_create(screen_theme, NULL);
	lv_label_set_long_mode(label_e877,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_e877,true);
	lv_obj_set_size(label_e877, 100, 40);
//set label style
	lv_obj_set_style_local_text_color(label_e877,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(label_e877, "活力橙");
	lv_label_set_align(label_e877, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(label_e877,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_23);
#ifdef BLOCKLY_label_e877_EVENT_HANDLER
	lv_obj_set_event_cb(label_e877, __qmsd_label_e877_cb);
#endif
	if(label_e877->coords.x2-label_e877->coords.x1<100)
	{
		int x_offset=(100-(label_e877->coords.x2-label_e877->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_e877,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_e877,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_e877->coords.y2-label_e877->coords.y1<40)
	{
		int y_offset=(40-(label_e877->coords.y2-label_e877->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_e877,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_e877,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(label_e877, 83, 427);
    qmsd_obj_set_id(label_e877,"label_e877");
}
    void qmsd_label_adfc_create()
{
	label_adfc = lv_label_create(screen_theme, NULL);
	lv_label_set_long_mode(label_adfc,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_adfc,true);
	lv_obj_set_size(label_adfc, 118, 40);
//set label style
	lv_obj_set_style_local_text_color(label_adfc,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(label_adfc, "主题设置");
	lv_label_set_align(label_adfc, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(label_adfc,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_23);
#ifdef BLOCKLY_label_adfc_EVENT_HANDLER
	lv_obj_set_event_cb(label_adfc, __qmsd_label_adfc_cb);
#endif
	if(label_adfc->coords.x2-label_adfc->coords.x1<118)
	{
		int x_offset=(118-(label_adfc->coords.x2-label_adfc->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_adfc,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_adfc,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_adfc->coords.y2-label_adfc->coords.y1<40)
	{
		int y_offset=(40-(label_adfc->coords.y2-label_adfc->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_adfc,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_adfc,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(label_adfc, 76, 24);
    qmsd_obj_set_id(label_adfc,"label_adfc");
}

static void screen_theme_qmsd_cb(lv_obj_t * obj, lv_event_t event, void *data)
{/*
    char *trans;
    lv_label_set_text(label_226a,qmsd_lang_get_trans("label_226a","时尚黑"));
    lv_label_set_text(label_a4ee,qmsd_lang_get_trans("label_a4ee","科技蓝"));
    lv_label_set_text(label_e877,qmsd_lang_get_trans("label_e877","活力橙"));
    lv_label_set_text(label_adfc,qmsd_lang_get_trans("label_adfc","主题设置"));
*/
#ifdef BLOCKLY_screen_theme_SCREEN_INIT
    __qmsd_screen_theme_init();
#endif
}

static void screen_theme_del_cb(lv_obj_t* obj,lv_event_t event)
{
    if(event == LV_EVENT_DELETE)
    {
        screen_theme=NULL;
        qmsd_screen_remove("screen_theme");
    }
}

void screen_theme_build(void)
{
    if(screen_theme) return;
    screen_theme = lv_obj_create(NULL, NULL);
    lv_obj_qmsd_set_cb(screen_theme, screen_theme_qmsd_cb);
    lv_obj_set_style_local_bg_color(screen_theme,LV_OBJ_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x00, 0x00, 0x00));

    qmsd_image_themeback_create();
    qmsd_image_theme_1_create();
    qmsd_image_theme_2_create();
    qmsd_image_theme_3_create();
    qmsd_label_226a_create();
    qmsd_label_a4ee_create();
    qmsd_label_e877_create();
    qmsd_label_adfc_create();
    lv_obj_set_event_cb(screen_theme,screen_theme_del_cb);
    qmsd_screen_register(screen_theme,"screen_theme");
}

void screen_theme_show(void)
{
    if(!screen_theme)
    {
        screen_theme_build();
    }
    lv_scr_load(screen_theme);
}

void screen_theme_delete(void)
{
    if(screen_theme)
    {
        lv_obj_del(screen_theme);
        screen_theme = NULL;
    }
}
