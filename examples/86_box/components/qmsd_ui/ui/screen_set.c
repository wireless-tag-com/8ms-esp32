#include "qmsd_ui_entry.h"
#include "qmsd_internal_ui_cb.h"

lv_obj_t* screen_set;
lv_obj_t* screen_set_back;
lv_obj_t* label_2984;
lv_obj_t* list_86ba;


    
void qmsd_screen_set_back_create()
{
    screen_set_back = lv_img_create(screen_set, NULL);
    lv_img_set_src(screen_set_back, &imgback_png);
#ifdef BLOCKLY_screen_set_back_EVENT_HANDLER
    lv_obj_set_event_cb(screen_set_back, __qmsd_screen_set_back_cb);
#endif
    lv_obj_set_pos(screen_set_back, 30, 34);
    lv_obj_set_click(screen_set_back,true);
    lv_obj_set_style_local_image_recolor(screen_set_back,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(screen_set_back,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    lv_obj_set_ext_click_area(screen_set_back,12,12,9,9);
    qmsd_obj_set_id(screen_set_back,"screen_set_back");
}
    void qmsd_label_2984_create()
{
	label_2984 = lv_label_create(screen_set, NULL);
	lv_label_set_long_mode(label_2984,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_2984,true);
	lv_obj_set_size(label_2984, 70, 40);
//set label style
	lv_obj_set_style_local_text_color(label_2984,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(label_2984, "设置");
	lv_label_set_align(label_2984, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(label_2984,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_24);
#ifdef BLOCKLY_label_2984_EVENT_HANDLER
	lv_obj_set_event_cb(label_2984, __qmsd_label_2984_cb);
#endif
	if(label_2984->coords.x2-label_2984->coords.x1<70)
	{
		int x_offset=(70-(label_2984->coords.x2-label_2984->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_2984,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_2984,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_2984->coords.y2-label_2984->coords.y1<40)
	{
		int y_offset=(40-(label_2984->coords.y2-label_2984->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_2984,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_2984,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(label_2984, 54, 22);
    qmsd_obj_set_id(label_2984,"label_2984");
}
    void qmsd_list_86ba_create()
{
    list_86ba = lv_list_create(screen_set, NULL);
    lv_obj_set_size(list_86ba, 480, 410);
    lv_obj_set_pos(list_86ba, -2, 70);
    lv_obj_set_style_local_text_font(list_86ba,0,0,&ali_font_23);

    lv_obj_set_style_local_text_color(list_86ba,LV_LIST_PART_BG, LV_STATE_DEFAULT, LV_COLOR_MAKE(0xff, 0xff, 0xff));
    lv_obj_set_style_local_bg_color(list_86ba,LV_LIST_PART_BG, LV_STATE_DEFAULT, LV_COLOR_MAKE(0x00, 0x00, 0x00));
    lv_obj_set_style_local_border_width(list_86ba,LV_LIST_PART_BG, LV_STATE_DEFAULT, 0);
    lv_obj_set_style_local_border_color(list_86ba,LV_LIST_PART_BG, LV_STATE_DEFAULT, LV_COLOR_MAKE(0xff, 0xff, 0xff));
    lv_obj_set_style_local_bg_color(list_86ba,LV_LIST_PART_BG, LV_STATE_PRESSED, LV_COLOR_MAKE(0x00, 0x00, 0x00));
    #ifdef BLOCKLY_list_86ba_EVENT_HANDLER
    lv_obj_set_event_cb(list_86ba, __qmsd_list_86ba_cb);
    #endif
    lv_obj_t * list_86ba_btn;
    LV_IMG_DECLARE(imgset_wifi_png);
    list_86ba_btn=lv_list_add_btn(list_86ba, &imgset_wifi_png, "WIFI");
    lv_obj_set_style_local_text_color(list_86ba_btn,LV_BTN_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_MAKE(0xff, 0xff, 0xff));
    lv_obj_set_style_local_bg_color(list_86ba_btn,LV_BTN_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_MAKE(0x00, 0x00, 0x00));
    lv_obj_set_style_local_border_color(list_86ba_btn,LV_BTN_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_MAKE(0xff, 0xff, 0xff));
    lv_obj_set_style_local_bg_color(list_86ba_btn,LV_BTN_PART_MAIN, LV_STATE_PRESSED, LV_COLOR_MAKE(0x00, 0x00, 0x00));
    #ifdef BLOCKLY_list_86ba_EVENT_HANDLER
    lv_obj_set_event_cb(list_86ba_btn, __qmsd_list_86ba_cb);
    #endif
    LV_IMG_DECLARE(imgset_light_png);
    list_86ba_btn=lv_list_add_btn(list_86ba, &imgset_light_png, "灯光设置");
    lv_obj_set_style_local_text_color(list_86ba_btn,LV_BTN_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_MAKE(0xff, 0xff, 0xff));
    lv_obj_set_style_local_bg_color(list_86ba_btn,LV_BTN_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_MAKE(0x00, 0x00, 0x00));
    lv_obj_set_style_local_border_color(list_86ba_btn,LV_BTN_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_MAKE(0xff, 0xff, 0xff));
    lv_obj_set_style_local_bg_color(list_86ba_btn,LV_BTN_PART_MAIN, LV_STATE_PRESSED, LV_COLOR_MAKE(0x00, 0x00, 0x00));
    #ifdef BLOCKLY_list_86ba_EVENT_HANDLER
    lv_obj_set_event_cb(list_86ba_btn, __qmsd_list_86ba_cb);
    #endif
    LV_IMG_DECLARE(imgset_theme_png);
    list_86ba_btn=lv_list_add_btn(list_86ba, &imgset_theme_png, "主题设置");
    lv_obj_set_style_local_text_color(list_86ba_btn,LV_BTN_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_MAKE(0xff, 0xff, 0xff));
    lv_obj_set_style_local_bg_color(list_86ba_btn,LV_BTN_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_MAKE(0x00, 0x00, 0x00));
    lv_obj_set_style_local_border_color(list_86ba_btn,LV_BTN_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_MAKE(0xff, 0xff, 0xff));
    lv_obj_set_style_local_bg_color(list_86ba_btn,LV_BTN_PART_MAIN, LV_STATE_PRESSED, LV_COLOR_MAKE(0x00, 0x00, 0x00));
    #ifdef BLOCKLY_list_86ba_EVENT_HANDLER
    lv_obj_set_event_cb(list_86ba_btn, __qmsd_list_86ba_cb);
    #endif
    LV_IMG_DECLARE(imgset_sound_png);
    list_86ba_btn=lv_list_add_btn(list_86ba, &imgset_sound_png, "语音助手");
    lv_obj_set_style_local_text_color(list_86ba_btn,LV_BTN_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_MAKE(0xff, 0xff, 0xff));
    lv_obj_set_style_local_bg_color(list_86ba_btn,LV_BTN_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_MAKE(0x00, 0x00, 0x00));
    lv_obj_set_style_local_border_color(list_86ba_btn,LV_BTN_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_MAKE(0xff, 0xff, 0xff));
    lv_obj_set_style_local_bg_color(list_86ba_btn,LV_BTN_PART_MAIN, LV_STATE_PRESSED, LV_COLOR_MAKE(0x00, 0x00, 0x00));
    #ifdef BLOCKLY_list_86ba_EVENT_HANDLER
    lv_obj_set_event_cb(list_86ba_btn, __qmsd_list_86ba_cb);
    #endif
    qmsd_obj_set_id(list_86ba,"list_86ba");
}

static void screen_set_qmsd_cb(lv_obj_t * obj, lv_event_t event, void *data)
{/*
    char *trans;
    lv_label_set_text(label_2984,qmsd_lang_get_trans("label_2984","设置"));
    lv_obj_t* base = NULL;
    int list_86ba_refresh_flag=0;
    do
    {
        base = lv_list_get_next_btn(list_86ba,base);
        char* btn_name = malloc((sizeof("list_86ba") + 4) * sizeof(char));
        sprintf(btn_name,"list_86ba_%d",list_86ba_refresh_flag);
        if (base&&qmsd_lang_get_trans(btn_name,NULL))
        {
            lv_label_set_text(lv_list_get_btn_label(base),qmsd_lang_get_trans(btn_name,NULL));
        }
        free(btn_name);
        list_86ba_refresh_flag++;
    } while (base);
*/
#ifdef BLOCKLY_screen_set_SCREEN_INIT
    __qmsd_screen_set_init();
#endif
}

static void screen_set_del_cb(lv_obj_t* obj,lv_event_t event)
{
    if(event == LV_EVENT_DELETE)
    {
        screen_set=NULL;
        qmsd_screen_remove("screen_set");
    }
}

void screen_set_build(void)
{
    if(screen_set) return;
    screen_set = lv_obj_create(NULL, NULL);
    lv_obj_qmsd_set_cb(screen_set, screen_set_qmsd_cb);
    lv_obj_set_style_local_bg_color(screen_set,LV_OBJ_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x00, 0x00, 0x00));

    qmsd_screen_set_back_create();
    qmsd_label_2984_create();
    qmsd_list_86ba_create();
    lv_obj_set_event_cb(screen_set,screen_set_del_cb);
    qmsd_screen_register(screen_set,"screen_set");
}

void screen_set_show(void)
{
    if(!screen_set)
    {
        screen_set_build();
    }
    lv_scr_load(screen_set);
}

void screen_set_delete(void)
{
    if(screen_set)
    {
        lv_obj_del(screen_set);
        screen_set = NULL;
    }
}
