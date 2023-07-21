#include "qmsd_ui_entry.h"
#include "qmsd_internal_ui_cb.h"

lv_obj_t* screen_text;
lv_obj_t* label_5a9a;
lv_obj_t* label_dd93;
lv_obj_t* lab_3d4d;


    void qmsd_label_5a9a_create()
{
	label_5a9a = lv_label_create(screen_text, NULL);
	lv_label_set_long_mode(label_5a9a,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_5a9a,true);
	lv_obj_set_size(label_5a9a, 100, 40);
//set label style

	lv_label_set_text(label_5a9a, "无线网络添加设备语音控制显示声音用户指南系统升级关于本机");
	lv_label_set_align(label_5a9a, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(label_5a9a,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_23);
#ifdef BLOCKLY_label_5a9a_EVENT_HANDLER
	lv_obj_set_event_cb(label_5a9a, __qmsd_label_5a9a_cb);
#endif
	if(label_5a9a->coords.x2-label_5a9a->coords.x1<100)
	{
		int x_offset=(100-(label_5a9a->coords.x2-label_5a9a->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_5a9a,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_5a9a,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_5a9a->coords.y2-label_5a9a->coords.y1<40)
	{
		int y_offset=(40-(label_5a9a->coords.y2-label_5a9a->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_5a9a,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_5a9a,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(label_5a9a, -190, 220);
    qmsd_obj_set_id(label_5a9a,"label_5a9a");
}
    void qmsd_label_dd93_create()
{
	label_dd93 = lv_label_create(screen_text, NULL);
	lv_label_set_long_mode(label_dd93,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_dd93,true);
	lv_obj_set_size(label_dd93, 100, 40);
//set label style

	lv_label_set_text(label_dd93, "已开启禁用新版本");
	lv_label_set_align(label_dd93, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(label_dd93,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_19);
#ifdef BLOCKLY_label_dd93_EVENT_HANDLER
	lv_obj_set_event_cb(label_dd93, __qmsd_label_dd93_cb);
#endif
	if(label_dd93->coords.x2-label_dd93->coords.x1<100)
	{
		int x_offset=(100-(label_dd93->coords.x2-label_dd93->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_dd93,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_dd93,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_dd93->coords.y2-label_dd93->coords.y1<40)
	{
		int y_offset=(40-(label_dd93->coords.y2-label_dd93->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_dd93,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_dd93,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(label_dd93, -100, 180);
    qmsd_obj_set_id(label_dd93,"label_dd93");
}
    void qmsd_lab_3d4d_create()
{
	lab_3d4d = lv_label_create(screen_text, NULL);
	lv_label_set_long_mode(lab_3d4d,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(lab_3d4d,true);
	lv_obj_set_size(lab_3d4d, 60, 10);
//set label style
	lv_obj_set_style_local_text_color(lab_3d4d,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(lab_3d4d, "窗帘已打开关闭");
	lv_label_set_align(lab_3d4d, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(lab_3d4d,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_11);
#ifdef BLOCKLY_lab_3d4d_EVENT_HANDLER
	lv_obj_set_event_cb(lab_3d4d, __qmsd_lab_3d4d_cb);
#endif
	if(lab_3d4d->coords.x2-lab_3d4d->coords.x1<60)
	{
		int x_offset=(60-(lab_3d4d->coords.x2-lab_3d4d->coords.x1))/2;
		lv_obj_set_style_local_pad_left(lab_3d4d,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(lab_3d4d,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(lab_3d4d->coords.y2-lab_3d4d->coords.y1<10)
	{
		int y_offset=(10-(lab_3d4d->coords.y2-lab_3d4d->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(lab_3d4d,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(lab_3d4d,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(lab_3d4d, -306, 97);
    qmsd_obj_set_id(lab_3d4d,"lab_3d4d");
}

static void screen_text_qmsd_cb(lv_obj_t * obj, lv_event_t event, void *data)
{/*
    char *trans;
    lv_label_set_text(label_5a9a,qmsd_lang_get_trans("label_5a9a","无线网络添加设备语音控制显示声音用户指南系统升级关于本机"));
    lv_label_set_text(label_dd93,qmsd_lang_get_trans("label_dd93","已开启禁用新版本"));
    lv_label_set_text(lab_3d4d,qmsd_lang_get_trans("lab_3d4d","窗帘已打开关闭"));
*/
#ifdef BLOCKLY_screen_text_SCREEN_INIT
    __qmsd_screen_text_init();
#endif
}

static void screen_text_del_cb(lv_obj_t* obj,lv_event_t event)
{
    if(event == LV_EVENT_DELETE)
    {
        screen_text=NULL;
        qmsd_screen_remove("screen_text");
    }
}

void screen_text_build(void)
{
    if(screen_text) return;
    screen_text = lv_obj_create(NULL, NULL);
    lv_obj_qmsd_set_cb(screen_text, screen_text_qmsd_cb);
    lv_obj_set_style_local_bg_color(screen_text,LV_OBJ_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x00, 0x00, 0x00));

    qmsd_label_5a9a_create();
    qmsd_label_dd93_create();
    qmsd_lab_3d4d_create();
    lv_obj_set_event_cb(screen_text,screen_text_del_cb);
    qmsd_screen_register(screen_text,"screen_text");
}

void screen_text_show(void)
{
    if(!screen_text)
    {
        screen_text_build();
    }
    lv_scr_load(screen_text);
}

void screen_text_delete(void)
{
    if(screen_text)
    {
        lv_obj_del(screen_text);
        screen_text = NULL;
    }
}
