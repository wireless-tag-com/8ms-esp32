#include "qmsd_ui_entry.h"
#include "qmsd_internal_ui_cb.h"

lv_obj_t* screen_filter;
lv_obj_t* image_fif_bg;
lv_obj_t* image_f_xiaoka;
lv_obj_t* image_f_u_pon1;
lv_obj_t* image_f_u_pon2;
lv_obj_t* image_f_u_pon3;
lv_obj_t* image_f_s_pon;
lv_obj_t* image_f_down;
lv_obj_t* image_f_menu;
lv_obj_t* button_f_left;
lv_obj_t * __button_f_left_label;
lv_obj_t* image_f_left;
lv_obj_t* button_f_right;
lv_obj_t * __button_f_right_label;
lv_obj_t* image_f_right;
lv_obj_t* image_filter;
lv_obj_t* label_f_title;
lv_obj_t* label_f_title_d;
lv_obj_t* image_f_p_88;

static void anim_set(lv_obj_t* control,lv_anim_exec_xcb_t exec_cb,lv_anim_value_t start, lv_anim_value_t end,uint32_t duration,uint32_t delay,uint16_t cnt,uint32_t time)
 {
 	lv_anim_t a;//定义动画
	lv_anim_init(&a);//初始化动画
	lv_anim_set_var(&a, control);//选择动画对象
	lv_anim_set_exec_cb(&a, exec_cb);//设置动画执行的运动在哪个轴运动
	lv_anim_set_values(&a, start , end);//设置动画的初始位置和结束位置
	lv_anim_set_time(&a, duration);//设置动画所需时间 单位:ms
	lv_anim_set_playback_time(&a,time);
	//lv_anim_set_path(&a, path);//设置动画效果
	//lv_anim_set_delay(&a,100);//设置起始时间点，动画已经执行的时间，单位：ms
	lv_anim_set_repeat_count(&a,cnt);//设置动画执行次数
	lv_anim_set_repeat_delay(&a,100);//每次动画的相隔时间
	//lv_anim_set_path_cb(&a,lv_anim_path_ease_out);
	lv_anim_start(&a);//启动动画
 }
    
void qmsd_image_fif_bg_create()
{
    image_fif_bg = lv_img_create(screen_filter, NULL);
    lv_img_set_src(image_fif_bg, &imgbg_blue_c_png);
#ifdef BLOCKLY_image_fif_bg_EVENT_HANDLER
    lv_obj_set_event_cb(image_fif_bg, __qmsd_image_fif_bg_cb);
#endif
    lv_obj_set_pos(image_fif_bg, 0, 0);
    qmsd_obj_set_id(image_fif_bg,"image_fif_bg");
}
    
void qmsd_image_f_xiaoka_create()
{
    image_f_xiaoka = lv_img_create(screen_filter, NULL);
    lv_img_set_src(image_f_xiaoka, &imgxiaoka_png);
#ifdef BLOCKLY_image_f_xiaoka_EVENT_HANDLER
    lv_obj_set_event_cb(image_f_xiaoka, __qmsd_image_f_xiaoka_cb);
#endif
	lv_obj_set_parent(image_f_xiaoka,image_fif_bg);
    lv_obj_set_pos(image_f_xiaoka, 190-image_fif_bg->coords.x1+lv_obj_get_x(screen_filter), 16-image_fif_bg->coords.y1+lv_obj_get_y(screen_filter));
    qmsd_obj_set_id(image_f_xiaoka,"image_f_xiaoka");
}
    
void qmsd_image_f_u_pon1_create()
{
    image_f_u_pon1 = lv_img_create(screen_filter, NULL);
    lv_img_set_src(image_f_u_pon1, &imgdown_un_point_png);
#ifdef BLOCKLY_image_f_u_pon1_EVENT_HANDLER
    lv_obj_set_event_cb(image_f_u_pon1, __qmsd_image_f_u_pon1_cb);
#endif
	lv_obj_set_parent(image_f_u_pon1,image_fif_bg);
    lv_obj_set_pos(image_f_u_pon1, 161-image_fif_bg->coords.x1+lv_obj_get_x(screen_filter), 380-image_fif_bg->coords.y1+lv_obj_get_y(screen_filter));
    qmsd_obj_set_id(image_f_u_pon1,"image_f_u_pon1");
}
    
void qmsd_image_f_u_pon2_create()
{
    image_f_u_pon2 = lv_img_create(screen_filter, NULL);
    lv_img_set_src(image_f_u_pon2, &imgdown_un_point_png);
#ifdef BLOCKLY_image_f_u_pon2_EVENT_HANDLER
    lv_obj_set_event_cb(image_f_u_pon2, __qmsd_image_f_u_pon2_cb);
#endif
	lv_obj_set_parent(image_f_u_pon2,image_fif_bg);
    lv_obj_set_pos(image_f_u_pon2, 205-image_fif_bg->coords.x1+lv_obj_get_x(screen_filter), 380-image_fif_bg->coords.y1+lv_obj_get_y(screen_filter));
    qmsd_obj_set_id(image_f_u_pon2,"image_f_u_pon2");
}
    
void qmsd_image_f_u_pon3_create()
{
    image_f_u_pon3 = lv_img_create(screen_filter, NULL);
    lv_img_set_src(image_f_u_pon3, &imgdown_un_point_png);
#ifdef BLOCKLY_image_f_u_pon3_EVENT_HANDLER
    lv_obj_set_event_cb(image_f_u_pon3, __qmsd_image_f_u_pon3_cb);
#endif
	lv_obj_set_parent(image_f_u_pon3,image_fif_bg);
    lv_obj_set_pos(image_f_u_pon3, 247-image_fif_bg->coords.x1+lv_obj_get_x(screen_filter), 380-image_fif_bg->coords.y1+lv_obj_get_y(screen_filter));
    qmsd_obj_set_id(image_f_u_pon3,"image_f_u_pon3");
}
    
void qmsd_image_f_s_pon_create()
{
    image_f_s_pon = lv_img_create(screen_filter, NULL);
    lv_img_set_src(image_f_s_pon, &imgdown_s_point_png);
#ifdef BLOCKLY_image_f_s_pon_EVENT_HANDLER
    lv_obj_set_event_cb(image_f_s_pon, __qmsd_image_f_s_pon_cb);
#endif
	lv_obj_set_parent(image_f_s_pon,image_fif_bg);
    lv_obj_set_pos(image_f_s_pon, 290-image_fif_bg->coords.x1+lv_obj_get_x(screen_filter), 380-image_fif_bg->coords.y1+lv_obj_get_y(screen_filter));
    qmsd_obj_set_id(image_f_s_pon,"image_f_s_pon");
}
    
void qmsd_image_f_down_create()
{
    image_f_down = lv_img_create(screen_filter, NULL);
    lv_img_set_src(image_f_down, &imgdown_png);
#ifdef BLOCKLY_image_f_down_EVENT_HANDLER
    lv_obj_set_event_cb(image_f_down, __qmsd_image_f_down_cb);
#endif
	lv_obj_set_parent(image_f_down,image_fif_bg);
    lv_obj_set_pos(image_f_down, 7-image_fif_bg->coords.x1+lv_obj_get_x(screen_filter), 406-image_fif_bg->coords.y1+lv_obj_get_y(screen_filter));
    qmsd_obj_set_id(image_f_down,"image_f_down");
}
    
void qmsd_image_f_menu_create()
{
    image_f_menu = lv_img_create(screen_filter, NULL);
    lv_img_set_src(image_f_menu, &imgmenu_ivn_png);
#ifdef BLOCKLY_image_f_menu_EVENT_HANDLER
    lv_obj_set_event_cb(image_f_menu, __qmsd_image_f_menu_cb);
#endif
	lv_obj_set_parent(image_f_menu,image_f_down);
    lv_obj_set_pos(image_f_menu, 224-image_f_down->coords.x1+lv_obj_get_x(screen_filter), 428-image_f_down->coords.y1+lv_obj_get_y(screen_filter));
    qmsd_obj_set_id(image_f_menu,"image_f_menu");
}
    void qmsd_button_f_left_create()
{
    button_f_left = lv_imgbtn_create(screen_filter, NULL);
    LV_IMG_DECLARE(imgbutton_bg_L_png);
    lv_imgbtn_set_src(button_f_left, LV_BTN_STATE_RELEASED, &imgbutton_bg_L_png);
    lv_imgbtn_set_src(button_f_left, LV_BTN_STATE_PRESSED, &imgbutton_bg_L_png);
    lv_imgbtn_set_src(button_f_left, LV_BTN_STATE_DISABLED, &imgbutton_bg_L_png);
    lv_obj_set_size(button_f_left, 78, 98);
	lv_obj_set_parent(button_f_left,image_fif_bg);
    lv_obj_set_pos(button_f_left, 7-image_fif_bg->coords.x1+lv_obj_get_x(screen_filter), 198-image_fif_bg->coords.y1+lv_obj_get_y(screen_filter));
#ifdef BLOCKLY_button_f_left_EVENT_HANDLER
    lv_obj_set_event_cb(button_f_left, __qmsd_button_f_left_cb);
#endif


    lv_obj_t* obj = button_f_left;
    int part = LV_BTN_PART_MAIN;
//设置正常样式
        lv_obj_set_style_local_border_color(obj,part,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

//设置正常样式结束

//设置按下样式
        lv_obj_set_style_local_border_color(obj,part,LV_STATE_PRESSED,LV_COLOR_MAKE(0xff, 0xff, 0xff));

//设置按下样式结束

//设置禁用样式
        lv_obj_set_style_local_border_color(obj,part,LV_STATE_DISABLED,LV_COLOR_MAKE(0xff, 0xff, 0xff));

//设置禁用样式结束
    lv_obj_set_style_local_outline_width(button_f_left,LV_BTN_PART_MAIN,LV_STATE_DEFAULT,0);
	lv_obj_set_style_local_outline_width(button_f_left,LV_BTN_PART_MAIN,LV_STATE_FOCUSED,0);
    qmsd_obj_set_id(button_f_left,"button_f_left");
}
    
void qmsd_image_f_left_create()
{
    image_f_left = lv_img_create(screen_filter, NULL);
    lv_img_set_src(image_f_left, &imgleft_icn_png);
#ifdef BLOCKLY_image_f_left_EVENT_HANDLER
    lv_obj_set_event_cb(image_f_left, __qmsd_image_f_left_cb);
#endif
	lv_obj_set_parent(image_f_left,button_f_left);
    lv_obj_set_pos(image_f_left, 12-button_f_left->coords.x1+lv_obj_get_x(screen_filter), 220-button_f_left->coords.y1+lv_obj_get_y(screen_filter));
    qmsd_obj_set_id(image_f_left,"image_f_left");
}
    void qmsd_button_f_right_create()
{
    button_f_right = lv_imgbtn_create(screen_filter, NULL);
    LV_IMG_DECLARE(imgbutton_bg_L_png);
    lv_imgbtn_set_src(button_f_right, LV_BTN_STATE_RELEASED, &imgbutton_bg_L_png);
    lv_imgbtn_set_src(button_f_right, LV_BTN_STATE_PRESSED, &imgbutton_bg_L_png);
    lv_imgbtn_set_src(button_f_right, LV_BTN_STATE_DISABLED, &imgbutton_bg_L_png);
    lv_obj_set_size(button_f_right, 78, 98);
	lv_obj_set_parent(button_f_right,image_fif_bg);
    lv_obj_set_pos(button_f_right, 398-image_fif_bg->coords.x1+lv_obj_get_x(screen_filter), 198-image_fif_bg->coords.y1+lv_obj_get_y(screen_filter));
#ifdef BLOCKLY_button_f_right_EVENT_HANDLER
    lv_obj_set_event_cb(button_f_right, __qmsd_button_f_right_cb);
#endif


    lv_obj_t* obj = button_f_right;
    int part = LV_BTN_PART_MAIN;
//设置正常样式
        lv_obj_set_style_local_border_color(obj,part,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

//设置正常样式结束

//设置按下样式
        lv_obj_set_style_local_border_color(obj,part,LV_STATE_PRESSED,LV_COLOR_MAKE(0xff, 0xff, 0xff));

//设置按下样式结束

//设置禁用样式
        lv_obj_set_style_local_border_color(obj,part,LV_STATE_DISABLED,LV_COLOR_MAKE(0xff, 0xff, 0xff));

//设置禁用样式结束
    lv_obj_set_style_local_outline_width(button_f_right,LV_BTN_PART_MAIN,LV_STATE_DEFAULT,0);
	lv_obj_set_style_local_outline_width(button_f_right,LV_BTN_PART_MAIN,LV_STATE_FOCUSED,0);
    qmsd_obj_set_id(button_f_right,"button_f_right");
}
    
void qmsd_image_f_right_create()
{
    image_f_right = lv_img_create(screen_filter, NULL);
    lv_img_set_src(image_f_right, &imgright_icn_png);
#ifdef BLOCKLY_image_f_right_EVENT_HANDLER
    lv_obj_set_event_cb(image_f_right, __qmsd_image_f_right_cb);
#endif
	lv_obj_set_parent(image_f_right,button_f_right);
    lv_obj_set_pos(image_f_right, 444-button_f_right->coords.x1+lv_obj_get_x(screen_filter), 220-button_f_right->coords.y1+lv_obj_get_y(screen_filter));
    qmsd_obj_set_id(image_f_right,"image_f_right");
}
    
void qmsd_image_filter_create()
{
    image_filter = lv_img_create(screen_filter, NULL);
    lv_img_set_src(image_filter, &imgfilter_element_l_png);
#ifdef BLOCKLY_image_filter_EVENT_HANDLER
    lv_obj_set_event_cb(image_filter, __qmsd_image_filter_cb);
#endif
	lv_obj_set_parent(image_filter,image_fif_bg);
    lv_obj_set_pos(image_filter, 149-image_fif_bg->coords.x1+lv_obj_get_x(screen_filter), 175-image_fif_bg->coords.y1+lv_obj_get_y(screen_filter));
    qmsd_obj_set_id(image_filter,"image_filter");
}
    void qmsd_label_f_title_create()
{
	label_f_title = lv_label_create(screen_filter, NULL);
	lv_label_set_long_mode(label_f_title,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_f_title,true);
	lv_obj_set_size(label_f_title, 100, 40);
	lv_obj_set_parent(label_f_title,image_fif_bg);
//set label style
	lv_obj_set_style_local_bg_color(label_f_title,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x00, 0x70, 0xba));
	lv_obj_set_style_local_bg_opa(label_f_title,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,255);
	lv_obj_set_style_local_text_color(label_f_title,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(label_f_title, "滤芯");
	lv_label_set_align(label_f_title, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(label_f_title,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_28);
#ifdef BLOCKLY_label_f_title_EVENT_HANDLER
	lv_obj_set_event_cb(label_f_title, __qmsd_label_f_title_cb);
#endif
	if(label_f_title->coords.x2-label_f_title->coords.x1<100)
	{
		int x_offset=(100-(label_f_title->coords.x2-label_f_title->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_f_title,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_f_title,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_f_title->coords.y2-label_f_title->coords.y1<40)
	{
		int y_offset=(40-(label_f_title->coords.y2-label_f_title->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_f_title,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_f_title,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(label_f_title, 191-image_fif_bg->coords.x1+lv_obj_get_x(screen_filter), 89-image_fif_bg->coords.y1+lv_obj_get_y(screen_filter));
    qmsd_obj_set_id(label_f_title,"label_f_title");
}
    void qmsd_label_f_title_d_create()
{
	label_f_title_d = lv_label_create(screen_filter, NULL);
	lv_label_set_long_mode(label_f_title_d,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_f_title_d,true);
	lv_obj_set_size(label_f_title_d, 242, 40);
	lv_obj_set_parent(label_f_title_d,image_fif_bg);
//set label style
	lv_obj_set_style_local_bg_color(label_f_title_d,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x00, 0x70, 0xba));
	lv_obj_set_style_local_bg_opa(label_f_title_d,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,255);
	lv_obj_set_style_local_text_color(label_f_title_d,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x53, 0xb3, 0xfb));

	lv_label_set_text(label_f_title_d, "上次更换：2023年4月15日");
	lv_label_set_align(label_f_title_d, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(label_f_title_d,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_20);
#ifdef BLOCKLY_label_f_title_d_EVENT_HANDLER
	lv_obj_set_event_cb(label_f_title_d, __qmsd_label_f_title_d_cb);
#endif
	if(label_f_title_d->coords.x2-label_f_title_d->coords.x1<242)
	{
		int x_offset=(242-(label_f_title_d->coords.x2-label_f_title_d->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_f_title_d,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_f_title_d,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_f_title_d->coords.y2-label_f_title_d->coords.y1<40)
	{
		int y_offset=(40-(label_f_title_d->coords.y2-label_f_title_d->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_f_title_d,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_f_title_d,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(label_f_title_d, 109-image_fif_bg->coords.x1+lv_obj_get_x(screen_filter), 134-image_fif_bg->coords.y1+lv_obj_get_y(screen_filter));
    qmsd_obj_set_id(label_f_title_d,"label_f_title_d");
}
    
void qmsd_image_f_p_88_create()
{
    image_f_p_88 = lv_img_create(screen_filter, NULL);
    lv_img_set_src(image_f_p_88, &imgp_88_png);
#ifdef BLOCKLY_image_f_p_88_EVENT_HANDLER
    lv_obj_set_event_cb(image_f_p_88, __qmsd_image_f_p_88_cb);
#endif
	lv_obj_set_parent(image_f_p_88,image_filter);
    lv_obj_set_pos(image_f_p_88, 180-image_filter->coords.x1+lv_obj_get_x(screen_filter), 234-image_filter->coords.y1+lv_obj_get_y(screen_filter));
    qmsd_obj_set_id(image_f_p_88,"image_f_p_88");
}

static void screen_filter_qmsd_cb(lv_obj_t * obj, lv_event_t event, void *data)
{/*
    char *trans;
    lv_label_set_text(label_f_title,qmsd_lang_get_trans("label_f_title","滤芯"));
    lv_label_set_text(label_f_title_d,qmsd_lang_get_trans("label_f_title_d","上次更换：2023年4月15日"));
*/
#ifdef BLOCKLY_screen_filter_SCREEN_INIT
    __qmsd_screen_filter_init();
#endif
}

static void screen_filter_del_cb(lv_obj_t* obj,lv_event_t event)
{
    if(event == LV_EVENT_DELETE)
    {
        screen_filter=NULL;
        qmsd_screen_remove("screen_filter");
    }
}

void screen_filter_build(void)
{
    if(screen_filter) return;
    screen_filter = lv_obj_create(NULL, NULL);
    lv_obj_qmsd_set_cb(screen_filter, screen_filter_qmsd_cb);

    qmsd_image_fif_bg_create();
    qmsd_image_f_xiaoka_create();
    qmsd_image_f_u_pon1_create();
    qmsd_image_f_u_pon2_create();
    qmsd_image_f_u_pon3_create();
    qmsd_image_f_s_pon_create();
    qmsd_image_f_down_create();
    qmsd_image_f_menu_create();
    qmsd_button_f_left_create();
    qmsd_image_f_left_create();
    qmsd_button_f_right_create();
    qmsd_image_f_right_create();
    qmsd_image_filter_create();
    qmsd_label_f_title_create();
    qmsd_label_f_title_d_create();
    qmsd_image_f_p_88_create();

    anim_set(image_f_xiaoka,lv_img_set_zoom,180,256,1000,0,LV_ANIM_REPEAT_INFINITE,1000);
    lv_obj_set_event_cb(screen_filter,screen_filter_del_cb);
    qmsd_screen_register(screen_filter,"screen_filter");
}

void screen_filter_show(void)
{
    if(!screen_filter)
    {
        screen_filter_build();
    }
    lv_scr_load(screen_filter);
}

void screen_filter_delete(void)
{
    if(screen_filter)
    {
        lv_obj_del(screen_filter);
        screen_filter = NULL;
    }
}
