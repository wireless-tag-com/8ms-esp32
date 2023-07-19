#include "qmsd_ui_entry.h"
#include "qmsd_internal_ui_cb.h"

lv_obj_t* screen_test;
lv_obj_t* label_4617;
lv_obj_t* label_b020;
lv_obj_t* label_1db1;
lv_obj_t* label_b558;
lv_obj_t* label_019e;
lv_obj_t* label_d5af;
lv_obj_t* label_a4c0;


    void qmsd_label_4617_create()
{
	label_4617 = lv_label_create(screen_test, NULL);
	lv_label_set_long_mode(label_4617,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_4617,true);
	lv_obj_set_size(label_4617, 350, 40);
//set label style

	lv_label_set_text(label_4617, "无路用的人  张震岳");
	lv_label_set_align(label_4617, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(label_4617,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_29);
#ifdef BLOCKLY_label_4617_EVENT_HANDLER
	lv_obj_set_event_cb(label_4617, __qmsd_label_4617_cb);
#endif
	if(label_4617->coords.x2-label_4617->coords.x1<350)
	{
		int x_offset=(350-(label_4617->coords.x2-label_4617->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_4617,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_4617,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_4617->coords.y2-label_4617->coords.y1<40)
	{
		int y_offset=(40-(label_4617->coords.y2-label_4617->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_4617,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_4617,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(label_4617, 63, 81);
    qmsd_obj_set_id(label_4617,"label_4617");
}
    void qmsd_label_b020_create()
{
	label_b020 = lv_label_create(screen_test, NULL);
	lv_label_set_long_mode(label_b020,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_b020,true);
	lv_obj_set_size(label_b020, 357, 40);
//set label style

	lv_label_set_text(label_b020, "Stay Tonight 金请夏");
	lv_label_set_align(label_b020, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(label_b020,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_18);
#ifdef BLOCKLY_label_b020_EVENT_HANDLER
	lv_obj_set_event_cb(label_b020, __qmsd_label_b020_cb);
#endif
	if(label_b020->coords.x2-label_b020->coords.x1<357)
	{
		int x_offset=(357-(label_b020->coords.x2-label_b020->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_b020,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_b020,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_b020->coords.y2-label_b020->coords.y1<40)
	{
		int y_offset=(40-(label_b020->coords.y2-label_b020->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_b020,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_b020,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(label_b020, 63, 181);
    qmsd_obj_set_id(label_b020,"label_b020");
}
    void qmsd_label_1db1_create()
{
	label_1db1 = lv_label_create(screen_test, NULL);
	lv_label_set_long_mode(label_1db1,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_1db1,true);
	lv_obj_set_size(label_1db1, 350, 40);
//set label style

	lv_label_set_text(label_1db1, "无路用的人  张震岳");
	lv_label_set_align(label_1db1, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(label_1db1,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_18);
#ifdef BLOCKLY_label_1db1_EVENT_HANDLER
	lv_obj_set_event_cb(label_1db1, __qmsd_label_1db1_cb);
#endif
	if(label_1db1->coords.x2-label_1db1->coords.x1<350)
	{
		int x_offset=(350-(label_1db1->coords.x2-label_1db1->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_1db1,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_1db1,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_1db1->coords.y2-label_1db1->coords.y1<40)
	{
		int y_offset=(40-(label_1db1->coords.y2-label_1db1->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_1db1,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_1db1,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(label_1db1, 63, 131);
    qmsd_obj_set_id(label_1db1,"label_1db1");
}
    void qmsd_label_b558_create()
{
	label_b558 = lv_label_create(screen_test, NULL);
	lv_label_set_long_mode(label_b558,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_b558,true);
	lv_obj_set_size(label_b558, 350, 40);
//set label style

	lv_label_set_text(label_b558, "Stay Tonight 金请夏");
	lv_label_set_align(label_b558, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(label_b558,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_29);
#ifdef BLOCKLY_label_b558_EVENT_HANDLER
	lv_obj_set_event_cb(label_b558, __qmsd_label_b558_cb);
#endif
	if(label_b558->coords.x2-label_b558->coords.x1<350)
	{
		int x_offset=(350-(label_b558->coords.x2-label_b558->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_b558,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_b558,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_b558->coords.y2-label_b558->coords.y1<40)
	{
		int y_offset=(40-(label_b558->coords.y2-label_b558->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_b558,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_b558,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(label_b558, 63, 237);
    qmsd_obj_set_id(label_b558,"label_b558");
}
    void qmsd_label_019e_create()
{
	label_019e = lv_label_create(screen_test, NULL);
	lv_label_set_long_mode(label_019e,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_019e,true);
	lv_obj_set_size(label_019e, 350, 40);
//set label style

	lv_label_set_text(label_019e, "关");
	lv_label_set_align(label_019e, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(label_019e,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_10);
#ifdef BLOCKLY_label_019e_EVENT_HANDLER
	lv_obj_set_event_cb(label_019e, __qmsd_label_019e_cb);
#endif
	if(label_019e->coords.x2-label_019e->coords.x1<350)
	{
		int x_offset=(350-(label_019e->coords.x2-label_019e->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_019e,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_019e,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_019e->coords.y2-label_019e->coords.y1<40)
	{
		int y_offset=(40-(label_019e->coords.y2-label_019e->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_019e,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_019e,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(label_019e, 63, 287);
    qmsd_obj_set_id(label_019e,"label_019e");
}
    void qmsd_label_d5af_create()
{
	label_d5af = lv_label_create(screen_test, NULL);
	lv_label_set_long_mode(label_d5af,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_d5af,true);
	lv_obj_set_size(label_d5af, 350, 40);
//set label style

	lv_label_set_text(label_d5af, "两只蝴蝶庞龙宝贝对不起梁龙初恋回春丹梦特别娇回忆的沙漏邓紫棋铁血丹心罗文甄妮");
	lv_label_set_align(label_d5af, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(label_d5af,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_13);
#ifdef BLOCKLY_label_d5af_EVENT_HANDLER
	lv_obj_set_event_cb(label_d5af, __qmsd_label_d5af_cb);
#endif
	if(label_d5af->coords.x2-label_d5af->coords.x1<350)
	{
		int x_offset=(350-(label_d5af->coords.x2-label_d5af->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_d5af,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_d5af,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_d5af->coords.y2-label_d5af->coords.y1<40)
	{
		int y_offset=(40-(label_d5af->coords.y2-label_d5af->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_d5af,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_d5af,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(label_d5af, 63, 332);
    qmsd_obj_set_id(label_d5af,"label_d5af");
}
    void qmsd_label_a4c0_create()
{
	label_a4c0 = lv_label_create(screen_test, NULL);
	lv_label_set_long_mode(label_a4c0,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_a4c0,true);
	lv_obj_set_size(label_a4c0, 350, 87);
//set label style

	lv_label_set_text(label_a4c0, "两只蝴蝶庞龙宝贝对不起梁龙初恋回春丹梦特别娇回忆的沙漏邓紫棋铁血丹心罗文甄妮");
	lv_label_set_align(label_a4c0, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(label_a4c0,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_22);
#ifdef BLOCKLY_label_a4c0_EVENT_HANDLER
	lv_obj_set_event_cb(label_a4c0, __qmsd_label_a4c0_cb);
#endif
	if(label_a4c0->coords.x2-label_a4c0->coords.x1<350)
	{
		int x_offset=(350-(label_a4c0->coords.x2-label_a4c0->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_a4c0,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_a4c0,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_a4c0->coords.y2-label_a4c0->coords.y1<87)
	{
		int y_offset=(87-(label_a4c0->coords.y2-label_a4c0->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_a4c0,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_a4c0,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(label_a4c0, 63, 377);
    qmsd_obj_set_id(label_a4c0,"label_a4c0");
}

static void screen_test_qmsd_cb(lv_obj_t * obj, lv_event_t event, void *data)
{/*
    char *trans;
    lv_label_set_text(label_4617,qmsd_lang_get_trans("label_4617","无路用的人  张震岳"));
    lv_label_set_text(label_b020,qmsd_lang_get_trans("label_b020","Stay Tonight 金请夏"));
    lv_label_set_text(label_1db1,qmsd_lang_get_trans("label_1db1","无路用的人  张震岳"));
    lv_label_set_text(label_b558,qmsd_lang_get_trans("label_b558","Stay Tonight 金请夏"));
    lv_label_set_text(label_019e,qmsd_lang_get_trans("label_019e","关"));
    lv_label_set_text(label_d5af,qmsd_lang_get_trans("label_d5af","两只蝴蝶庞龙宝贝对不起梁龙初恋回春丹梦特别娇回忆的沙漏邓紫棋铁血丹心罗文甄妮"));
    lv_label_set_text(label_a4c0,qmsd_lang_get_trans("label_a4c0","两只蝴蝶庞龙宝贝对不起梁龙初恋回春丹梦特别娇回忆的沙漏邓紫棋铁血丹心罗文甄妮"));
*/
#ifdef BLOCKLY_screen_test_SCREEN_INIT
    __qmsd_screen_test_init();
#endif
}

static void screen_test_del_cb(lv_obj_t* obj,lv_event_t event)
{
    if(event == LV_EVENT_DELETE)
    {
        screen_test=NULL;
        qmsd_screen_remove("screen_test");
    }
}

void screen_test_build(void)
{
    if(screen_test) return;
    screen_test = lv_obj_create(NULL, NULL);
    lv_obj_qmsd_set_cb(screen_test, screen_test_qmsd_cb);
    lv_obj_set_style_local_bg_color(screen_test,LV_OBJ_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x31, 0x04, 0x58));

    qmsd_label_4617_create();
    qmsd_label_b020_create();
    qmsd_label_1db1_create();
    qmsd_label_b558_create();
    qmsd_label_019e_create();
    qmsd_label_d5af_create();
    qmsd_label_a4c0_create();
    lv_obj_set_event_cb(screen_test,screen_test_del_cb);
    qmsd_screen_register(screen_test,"screen_test");
}

void screen_test_show(void)
{
    if(!screen_test)
    {
        screen_test_build();
    }
    lv_scr_load(screen_test);
}

void screen_test_delete(void)
{
    if(screen_test)
    {
        lv_obj_del(screen_test);
        screen_test = NULL;
    }
}
