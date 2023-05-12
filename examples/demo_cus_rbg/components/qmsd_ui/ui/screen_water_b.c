#include "qmsd_ui_entry.h"
#include "qmsd_internal_ui_cb.h"

lv_obj_t* screen_water_b;
lv_obj_t* image_w_bg;
lv_obj_t* image_w_xiaoka;
lv_obj_t* image_w_u_pon1;
lv_obj_t* image_w_u_pon2;
lv_obj_t* image_w_s_pon;
lv_obj_t* image_w_u_pon3;
lv_obj_t* image_w_down;
lv_obj_t* image_w_menu;
lv_obj_t* button_w_left;
lv_obj_t * __button_w_left_label;
lv_obj_t* image_w_left;
lv_obj_t* button_w_right;
lv_obj_t * __button_w_right_label;
lv_obj_t* image_w_right;
lv_obj_t* image_w_box;
lv_obj_t* label_w_title;
lv_obj_t* label_w_title_d;
lv_obj_t* image_w_p_80;
lv_obj_t * img;
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
    
void qmsd_image_w_bg_create()
{
    image_w_bg = lv_img_create(screen_water_b, NULL);
    lv_img_set_src(image_w_bg, &imgbg_blue_c_png);
#ifdef BLOCKLY_image_w_bg_EVENT_HANDLER
    lv_obj_set_event_cb(image_w_bg, __qmsd_image_w_bg_cb);
#endif
    lv_obj_set_pos(image_w_bg, 0, 0);
    qmsd_obj_set_id(image_w_bg,"image_w_bg");
}
    
void qmsd_image_w_xiaoka_create()
{
    image_w_xiaoka = lv_img_create(screen_water_b, NULL);
    lv_img_set_src(image_w_xiaoka, &imgxiaoka_png);
#ifdef BLOCKLY_image_w_xiaoka_EVENT_HANDLER
    lv_obj_set_event_cb(image_w_xiaoka, __qmsd_image_w_xiaoka_cb);
#endif
	lv_obj_set_parent(image_w_xiaoka,image_w_bg);
    lv_obj_set_pos(image_w_xiaoka, 190-image_w_bg->coords.x1+lv_obj_get_x(screen_water_b), 16-image_w_bg->coords.y1+lv_obj_get_y(screen_water_b));
    qmsd_obj_set_id(image_w_xiaoka,"image_w_xiaoka");
}
    
void qmsd_image_w_u_pon1_create()
{
    image_w_u_pon1 = lv_img_create(screen_water_b, NULL);
    lv_img_set_src(image_w_u_pon1, &imgdown_un_point_png);
#ifdef BLOCKLY_image_w_u_pon1_EVENT_HANDLER
    lv_obj_set_event_cb(image_w_u_pon1, __qmsd_image_w_u_pon1_cb);
#endif
	lv_obj_set_parent(image_w_u_pon1,image_w_bg);
    lv_obj_set_pos(image_w_u_pon1, 161-image_w_bg->coords.x1+lv_obj_get_x(screen_water_b), 380-image_w_bg->coords.y1+lv_obj_get_y(screen_water_b));
    qmsd_obj_set_id(image_w_u_pon1,"image_w_u_pon1");
}
    
void qmsd_image_w_u_pon2_create()
{
    image_w_u_pon2 = lv_img_create(screen_water_b, NULL);
    lv_img_set_src(image_w_u_pon2, &imgdown_un_point_png);
#ifdef BLOCKLY_image_w_u_pon2_EVENT_HANDLER
    lv_obj_set_event_cb(image_w_u_pon2, __qmsd_image_w_u_pon2_cb);
#endif
	lv_obj_set_parent(image_w_u_pon2,image_w_bg);
    lv_obj_set_pos(image_w_u_pon2, 205-image_w_bg->coords.x1+lv_obj_get_x(screen_water_b), 380-image_w_bg->coords.y1+lv_obj_get_y(screen_water_b));
    qmsd_obj_set_id(image_w_u_pon2,"image_w_u_pon2");
}
    
void qmsd_image_w_s_pon_create()
{
    image_w_s_pon = lv_img_create(screen_water_b, NULL);
    lv_img_set_src(image_w_s_pon, &imgdown_s_point_png);
#ifdef BLOCKLY_image_w_s_pon_EVENT_HANDLER
    lv_obj_set_event_cb(image_w_s_pon, __qmsd_image_w_s_pon_cb);
#endif
	lv_obj_set_parent(image_w_s_pon,image_w_bg);
    lv_obj_set_pos(image_w_s_pon, 247-image_w_bg->coords.x1+lv_obj_get_x(screen_water_b), 380-image_w_bg->coords.y1+lv_obj_get_y(screen_water_b));
    qmsd_obj_set_id(image_w_s_pon,"image_w_s_pon");
}
    
void qmsd_image_w_u_pon3_create()
{
    image_w_u_pon3 = lv_img_create(screen_water_b, NULL);
    lv_img_set_src(image_w_u_pon3, &imgdown_un_point_png);
#ifdef BLOCKLY_image_w_u_pon3_EVENT_HANDLER
    lv_obj_set_event_cb(image_w_u_pon3, __qmsd_image_w_u_pon3_cb);
#endif
	lv_obj_set_parent(image_w_u_pon3,image_w_bg);
    lv_obj_set_pos(image_w_u_pon3, 290-image_w_bg->coords.x1+lv_obj_get_x(screen_water_b), 380-image_w_bg->coords.y1+lv_obj_get_y(screen_water_b));
    qmsd_obj_set_id(image_w_u_pon3,"image_w_u_pon3");
}
    
void qmsd_image_w_down_create()
{
    image_w_down = lv_img_create(screen_water_b, NULL);
    lv_img_set_src(image_w_down, &imgdown_png);
#ifdef BLOCKLY_image_w_down_EVENT_HANDLER
    lv_obj_set_event_cb(image_w_down, __qmsd_image_w_down_cb);
#endif
	lv_obj_set_parent(image_w_down,image_w_bg);
    lv_obj_set_pos(image_w_down, 7-image_w_bg->coords.x1+lv_obj_get_x(screen_water_b), 406-image_w_bg->coords.y1+lv_obj_get_y(screen_water_b));
    qmsd_obj_set_id(image_w_down,"image_w_down");
}
    
void qmsd_image_w_menu_create()
{
    image_w_menu = lv_img_create(screen_water_b, NULL);
    lv_img_set_src(image_w_menu, &imgmenu_ivn_png);
#ifdef BLOCKLY_image_w_menu_EVENT_HANDLER
    lv_obj_set_event_cb(image_w_menu, __qmsd_image_w_menu_cb);
#endif
	lv_obj_set_parent(image_w_menu,image_w_down);
    lv_obj_set_pos(image_w_menu, 224-image_w_down->coords.x1+lv_obj_get_x(screen_water_b), 428-image_w_down->coords.y1+lv_obj_get_y(screen_water_b));
    qmsd_obj_set_id(image_w_menu,"image_w_menu");
}
    void qmsd_button_w_left_create()
{
    button_w_left = lv_imgbtn_create(screen_water_b, NULL);
    LV_IMG_DECLARE(imgbutton_bg_L_png);
    lv_imgbtn_set_src(button_w_left, LV_BTN_STATE_RELEASED, &imgbutton_bg_L_png);
    lv_imgbtn_set_src(button_w_left, LV_BTN_STATE_PRESSED, &imgbutton_bg_L_png);
    lv_imgbtn_set_src(button_w_left, LV_BTN_STATE_DISABLED, &imgbutton_bg_L_png);
    lv_obj_set_size(button_w_left, 78, 98);
	lv_obj_set_parent(button_w_left,image_w_bg);
    lv_obj_set_pos(button_w_left, 7-image_w_bg->coords.x1+lv_obj_get_x(screen_water_b), 198-image_w_bg->coords.y1+lv_obj_get_y(screen_water_b));
#ifdef BLOCKLY_button_w_left_EVENT_HANDLER
    lv_obj_set_event_cb(button_w_left, __qmsd_button_w_left_cb);
#endif


    lv_obj_t* obj = button_w_left;
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
    lv_obj_set_style_local_outline_width(button_w_left,LV_BTN_PART_MAIN,LV_STATE_DEFAULT,0);
	lv_obj_set_style_local_outline_width(button_w_left,LV_BTN_PART_MAIN,LV_STATE_FOCUSED,0);
    qmsd_obj_set_id(button_w_left,"button_w_left");
}
    
void qmsd_image_w_left_create()
{
    image_w_left = lv_img_create(screen_water_b, NULL);
    lv_img_set_src(image_w_left, &imgleft_icn_png);
#ifdef BLOCKLY_image_w_left_EVENT_HANDLER
    lv_obj_set_event_cb(image_w_left, __qmsd_image_w_left_cb);
#endif
	lv_obj_set_parent(image_w_left,button_w_left);
    lv_obj_set_pos(image_w_left, 12-button_w_left->coords.x1+lv_obj_get_x(screen_water_b), 220-button_w_left->coords.y1+lv_obj_get_y(screen_water_b));
    qmsd_obj_set_id(image_w_left,"image_w_left");
}
    void qmsd_button_w_right_create()
{
    button_w_right = lv_imgbtn_create(screen_water_b, NULL);
    LV_IMG_DECLARE(imgbutton_bg_L_png);
    lv_imgbtn_set_src(button_w_right, LV_BTN_STATE_RELEASED, &imgbutton_bg_L_png);
    lv_imgbtn_set_src(button_w_right, LV_BTN_STATE_PRESSED, &imgbutton_bg_L_png);
    lv_imgbtn_set_src(button_w_right, LV_BTN_STATE_DISABLED, &imgbutton_bg_L_png);
    lv_obj_set_size(button_w_right, 78, 98);
	lv_obj_set_parent(button_w_right,image_w_bg);
    lv_obj_set_pos(button_w_right, 398-image_w_bg->coords.x1+lv_obj_get_x(screen_water_b), 198-image_w_bg->coords.y1+lv_obj_get_y(screen_water_b));
#ifdef BLOCKLY_button_w_right_EVENT_HANDLER
    lv_obj_set_event_cb(button_w_right, __qmsd_button_w_right_cb);
#endif


    lv_obj_t* obj = button_w_right;
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
    lv_obj_set_style_local_outline_width(button_w_right,LV_BTN_PART_MAIN,LV_STATE_DEFAULT,0);
	lv_obj_set_style_local_outline_width(button_w_right,LV_BTN_PART_MAIN,LV_STATE_FOCUSED,0);
    qmsd_obj_set_id(button_w_right,"button_w_right");
}
    
void qmsd_image_w_right_create()
{
    image_w_right = lv_img_create(screen_water_b, NULL);
    lv_img_set_src(image_w_right, &imgright_icn_png);
#ifdef BLOCKLY_image_w_right_EVENT_HANDLER
    lv_obj_set_event_cb(image_w_right, __qmsd_image_w_right_cb);
#endif
	lv_obj_set_parent(image_w_right,button_w_right);
    lv_obj_set_pos(image_w_right, 444-button_w_right->coords.x1+lv_obj_get_x(screen_water_b), 220-button_w_right->coords.y1+lv_obj_get_y(screen_water_b));
    qmsd_obj_set_id(image_w_right,"image_w_right");
}
void qmsd_image_w_box_create()
{
    image_w_box = lv_img_create(screen_water_b, NULL);
    lv_img_set_src(image_w_box, &imgwater_box_n_png);
#ifdef BLOCKLY_image_w_box_EVENT_HANDLER
    lv_obj_set_event_cb(image_w_box, __qmsd_image_w_box_cb);
#endif
	lv_obj_set_parent(image_w_box,image_w_bg);
    lv_obj_set_pos(image_w_box, 109-image_w_bg->coords.x1+lv_obj_get_x(screen_water_b), 180-image_w_bg->coords.y1+lv_obj_get_y(screen_water_b));
    qmsd_obj_set_id(image_w_box,"image_w_box");
}
#if 0
extern const uint8_t box_water_map[];  /*Use the example gif*/
void Mai_gif_create(void)
{
	img = lv_gif_create_from_data(image_w_bg, box_water_map);
	//*lv_gif_get_repeat_flag() = true;
	//img->user_data = lv_gif_get_repeat_flag();
	lv_obj_set_parent(img,image_w_bg);
	lv_gif_set_repeat_flag(true);
	lv_obj_set_pos(image_w_box, 109-image_w_bg->coords.x1+lv_obj_get_x(screen_water_b), 180-image_w_bg->coords.y1+lv_obj_get_y(screen_water_b));
	//lv_obj_set_pos(img, 0, 0);
	lv_obj_set_size(img, 262, 149);

}
#endif
    void qmsd_label_w_title_create()
{
	label_w_title = lv_label_create(screen_water_b, NULL);
	lv_label_set_long_mode(label_w_title,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_w_title,true);
	lv_obj_set_size(label_w_title, 100, 40);
	lv_obj_set_parent(label_w_title,image_w_bg);
//set label style
	lv_obj_set_style_local_bg_color(label_w_title,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x00, 0x70, 0xba));
	lv_obj_set_style_local_bg_opa(label_w_title,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,255);
	lv_obj_set_style_local_text_color(label_w_title,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(label_w_title, "水箱");
	lv_label_set_align(label_w_title, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(label_w_title,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_28);
#ifdef BLOCKLY_label_w_title_EVENT_HANDLER
	lv_obj_set_event_cb(label_w_title, __qmsd_label_w_title_cb);
#endif
	if(label_w_title->coords.x2-label_w_title->coords.x1<100)
	{
		int x_offset=(100-(label_w_title->coords.x2-label_w_title->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_w_title,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_w_title,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_w_title->coords.y2-label_w_title->coords.y1<40)
	{
		int y_offset=(40-(label_w_title->coords.y2-label_w_title->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_w_title,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_w_title,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(label_w_title, 191-image_w_bg->coords.x1+lv_obj_get_x(screen_water_b), 89-image_w_bg->coords.y1+lv_obj_get_y(screen_water_b));
    qmsd_obj_set_id(label_w_title,"label_w_title");
}
    void qmsd_label_w_title_d_create()
{
	label_w_title_d = lv_label_create(screen_water_b, NULL);
	lv_label_set_long_mode(label_w_title_d,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_w_title_d,true);
	lv_obj_set_size(label_w_title_d, 242, 40);
	lv_obj_set_parent(label_w_title_d,image_w_bg);
//set label style
	lv_obj_set_style_local_bg_color(label_w_title_d,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x00, 0x70, 0xba));
	lv_obj_set_style_local_bg_opa(label_w_title_d,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,255);
	lv_obj_set_style_local_text_color(label_w_title_d,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x53, 0xb3, 0xfb));

	lv_label_set_text(label_w_title_d, "预计工作时间：33小时");
	lv_label_set_align(label_w_title_d, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(label_w_title_d,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_20);
#ifdef BLOCKLY_label_w_title_d_EVENT_HANDLER
	lv_obj_set_event_cb(label_w_title_d, __qmsd_label_w_title_d_cb);
#endif
	if(label_w_title_d->coords.x2-label_w_title_d->coords.x1<242)
	{
		int x_offset=(242-(label_w_title_d->coords.x2-label_w_title_d->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_w_title_d,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_w_title_d,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_w_title_d->coords.y2-label_w_title_d->coords.y1<40)
	{
		int y_offset=(40-(label_w_title_d->coords.y2-label_w_title_d->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_w_title_d,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_w_title_d,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(label_w_title_d, 109-image_w_bg->coords.x1+lv_obj_get_x(screen_water_b), 134-image_w_bg->coords.y1+lv_obj_get_y(screen_water_b));
    qmsd_obj_set_id(label_w_title_d,"label_w_title_d");
}
    
void qmsd_image_w_p_80_create()
{
    image_w_p_80 = lv_img_create(screen_water_b, NULL);
    lv_img_set_src(image_w_p_80, &imgp_80_png);
#ifdef BLOCKLY_image_w_p_80_EVENT_HANDLER
    lv_obj_set_event_cb(image_w_p_80, __qmsd_image_w_p_80_cb);
#endif
	lv_obj_set_parent(image_w_p_80,image_w_box);
    lv_obj_set_pos(image_w_p_80, 146-image_w_box->coords.x1+lv_obj_get_x(screen_water_b), 226-image_w_box->coords.y1+lv_obj_get_y(screen_water_b));
    qmsd_obj_set_id(image_w_p_80,"image_w_p_80");
}

static void screen_water_b_qmsd_cb(lv_obj_t * obj, lv_event_t event, void *data)
{/*
    char *trans;
    lv_label_set_text(label_w_title,qmsd_lang_get_trans("label_w_title","水箱"));
    lv_label_set_text(label_w_title_d,qmsd_lang_get_trans("label_w_title_d","预计工作时间：33小时"));
*/
#ifdef BLOCKLY_screen_water_b_SCREEN_INIT
    __qmsd_screen_water_b_init();
#endif
}

static void screen_water_b_del_cb(lv_obj_t* obj,lv_event_t event)
{
    if(event == LV_EVENT_DELETE)
    {
        screen_water_b=NULL;
        qmsd_screen_remove("screen_water_b");
    }
}

void screen_water_b_build(void)
{
    if(screen_water_b) return;
    screen_water_b = lv_obj_create(NULL, NULL);
    lv_obj_qmsd_set_cb(screen_water_b, screen_water_b_qmsd_cb);

    qmsd_image_w_bg_create();
    qmsd_image_w_xiaoka_create();
    qmsd_image_w_u_pon1_create();
    qmsd_image_w_u_pon2_create();
    qmsd_image_w_s_pon_create();
    qmsd_image_w_u_pon3_create();
    qmsd_image_w_down_create();
    qmsd_image_w_menu_create();
    qmsd_button_w_left_create();
    qmsd_image_w_left_create();
    qmsd_button_w_right_create();
    qmsd_image_w_right_create();
    qmsd_image_w_box_create();
    qmsd_label_w_title_create();
    qmsd_label_w_title_d_create();
    qmsd_image_w_p_80_create();
    anim_set(image_w_xiaoka,lv_img_set_zoom,180,256,1000,0,LV_ANIM_REPEAT_INFINITE,1000);
    //Mai_gif_create();
    lv_obj_set_event_cb(screen_water_b,screen_water_b_del_cb);
    qmsd_screen_register(screen_water_b,"screen_water_b");
}

void screen_water_b_show(void)
{
    if(!screen_water_b)
    {
        screen_water_b_build();
    }
    lv_scr_load(screen_water_b);
}

void screen_water_b_delete(void)
{
    if(screen_water_b)
    {
        lv_obj_del(screen_water_b);
        screen_water_b = NULL;
    }
}
