#include "qmsd_ui_entry.h"
#include "qmsd_internal_ui_cb.h"

lv_obj_t* screen_humidity;
lv_obj_t* image_hu_bg;
lv_obj_t* image_hu_xiaoka;
lv_obj_t* image_hu_u_pon1;
lv_obj_t* image_hu_s_pon;
lv_obj_t* image_hu_u_pon2;
lv_obj_t* image_hu_u_pon3;
lv_obj_t* image_hu_down;
lv_obj_t* image_hu_menu;
lv_obj_t* label_hu_left;
lv_obj_t* label_hu_right;
lv_obj_t* image_hu_L_pod;
lv_obj_t* image_hu_R_pod;
lv_obj_t* image_h_L_podg;
lv_obj_t* image_h_R_podg;
lv_obj_t* button_hu_left;
lv_obj_t * __button_hu_left_label;
lv_obj_t* image_hu_left;
lv_obj_t* button_hu_right;
lv_obj_t * __button_hu_right_label;
lv_obj_t* image_hu_right;
lv_obj_t* image_hu_dw_L;
lv_obj_t* image_hu_dw_R;
lv_obj_t* image_hu_L_or;
lv_obj_t* image_hu_R_or;
lv_obj_t* image_hu_LD_or;
lv_obj_t* image_hu_RD_or;
lv_obj_t* label_title_t;
lv_obj_t* label_title_hu;
lv_obj_t* label_du;
lv_obj_t* label_perc;

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
    
void qmsd_image_hu_bg_create()
{
    image_hu_bg = lv_img_create(screen_humidity, NULL);
    lv_img_set_src(image_hu_bg, &imgbg_blue_c_png);
#ifdef BLOCKLY_image_hu_bg_EVENT_HANDLER
    lv_obj_set_event_cb(image_hu_bg, __qmsd_image_hu_bg_cb);
#endif
    lv_obj_set_pos(image_hu_bg, 0, 0);
    qmsd_obj_set_id(image_hu_bg,"image_hu_bg");
}
    
void qmsd_image_hu_xiaoka_create()
{
    image_hu_xiaoka = lv_img_create(screen_humidity, NULL);
    lv_img_set_src(image_hu_xiaoka, &imgxiaoka_png);
#ifdef BLOCKLY_image_hu_xiaoka_EVENT_HANDLER
    lv_obj_set_event_cb(image_hu_xiaoka, __qmsd_image_hu_xiaoka_cb);
#endif
	lv_obj_set_parent(image_hu_xiaoka,image_hu_bg);
    lv_obj_set_pos(image_hu_xiaoka, 190-image_hu_bg->coords.x1+lv_obj_get_x(screen_humidity), 16-image_hu_bg->coords.y1+lv_obj_get_y(screen_humidity));
    qmsd_obj_set_id(image_hu_xiaoka,"image_hu_xiaoka");
}
    
void qmsd_image_hu_u_pon1_create()
{
    image_hu_u_pon1 = lv_img_create(screen_humidity, NULL);
    lv_img_set_src(image_hu_u_pon1, &imgdown_un_point_png);
#ifdef BLOCKLY_image_hu_u_pon1_EVENT_HANDLER
    lv_obj_set_event_cb(image_hu_u_pon1, __qmsd_image_hu_u_pon1_cb);
#endif
    lv_obj_set_pos(image_hu_u_pon1, 161, 380);
    qmsd_obj_set_id(image_hu_u_pon1,"image_hu_u_pon1");
}
    
void qmsd_image_hu_s_pon_create()
{
    image_hu_s_pon = lv_img_create(screen_humidity, NULL);
    lv_img_set_src(image_hu_s_pon, &imgdown_s_point_png);
#ifdef BLOCKLY_image_hu_s_pon_EVENT_HANDLER
    lv_obj_set_event_cb(image_hu_s_pon, __qmsd_image_hu_s_pon_cb);
#endif
	lv_obj_set_parent(image_hu_s_pon,image_hu_bg);
    lv_obj_set_pos(image_hu_s_pon, 205-image_hu_bg->coords.x1+lv_obj_get_x(screen_humidity), 380-image_hu_bg->coords.y1+lv_obj_get_y(screen_humidity));
    qmsd_obj_set_id(image_hu_s_pon,"image_hu_s_pon");
}
    
void qmsd_image_hu_u_pon2_create()
{
    image_hu_u_pon2 = lv_img_create(screen_humidity, NULL);
    lv_img_set_src(image_hu_u_pon2, &imgdown_un_point_png);
#ifdef BLOCKLY_image_hu_u_pon2_EVENT_HANDLER
    lv_obj_set_event_cb(image_hu_u_pon2, __qmsd_image_hu_u_pon2_cb);
#endif
	lv_obj_set_parent(image_hu_u_pon2,image_hu_bg);
    lv_obj_set_pos(image_hu_u_pon2, 247-image_hu_bg->coords.x1+lv_obj_get_x(screen_humidity), 380-image_hu_bg->coords.y1+lv_obj_get_y(screen_humidity));
    qmsd_obj_set_id(image_hu_u_pon2,"image_hu_u_pon2");
}
    
void qmsd_image_hu_u_pon3_create()
{
    image_hu_u_pon3 = lv_img_create(screen_humidity, NULL);
    lv_img_set_src(image_hu_u_pon3, &imgdown_un_point_png);
#ifdef BLOCKLY_image_hu_u_pon3_EVENT_HANDLER
    lv_obj_set_event_cb(image_hu_u_pon3, __qmsd_image_hu_u_pon3_cb);
#endif
	lv_obj_set_parent(image_hu_u_pon3,image_hu_bg);
    lv_obj_set_pos(image_hu_u_pon3, 290-image_hu_bg->coords.x1+lv_obj_get_x(screen_humidity), 380-image_hu_bg->coords.y1+lv_obj_get_y(screen_humidity));
    qmsd_obj_set_id(image_hu_u_pon3,"image_hu_u_pon3");
}
    
void qmsd_image_hu_down_create()
{
    image_hu_down = lv_img_create(screen_humidity, NULL);
    lv_img_set_src(image_hu_down, &imgdown_png);
#ifdef BLOCKLY_image_hu_down_EVENT_HANDLER
    lv_obj_set_event_cb(image_hu_down, __qmsd_image_hu_down_cb);
#endif
	lv_obj_set_parent(image_hu_down,image_hu_bg);
    lv_obj_set_pos(image_hu_down, 7-image_hu_bg->coords.x1+lv_obj_get_x(screen_humidity), 406-image_hu_bg->coords.y1+lv_obj_get_y(screen_humidity));
    qmsd_obj_set_id(image_hu_down,"image_hu_down");
}
    
void qmsd_image_hu_menu_create()
{
    image_hu_menu = lv_img_create(screen_humidity, NULL);
    lv_img_set_src(image_hu_menu, &imgmenu_ivn_png);
#ifdef BLOCKLY_image_hu_menu_EVENT_HANDLER
    lv_obj_set_event_cb(image_hu_menu, __qmsd_image_hu_menu_cb);
#endif
	lv_obj_set_parent(image_hu_menu,image_hu_down);
    lv_obj_set_pos(image_hu_menu, 224-image_hu_down->coords.x1+lv_obj_get_x(screen_humidity), 428-image_hu_down->coords.y1+lv_obj_get_y(screen_humidity));
    qmsd_obj_set_id(image_hu_menu,"image_hu_menu");
}
#define temperature1 "25.7"
#define temperature2 "33.1"
static uint8_t hu_index = 0;
    void qmsd_label_hu_left_create()
{
	label_hu_left = lv_label_create(screen_humidity, NULL);
	lv_label_set_long_mode(label_hu_left,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_hu_left,true);
	lv_obj_set_size(label_hu_left, 100, 40);
	lv_obj_set_parent(label_hu_left,image_hu_bg);
//set label style
	lv_obj_set_style_local_bg_color(label_hu_left,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x00, 0x70, 0xba));
	lv_obj_set_style_local_bg_opa(label_hu_left,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,255);
	lv_obj_set_style_local_text_color(label_hu_left,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(label_hu_left, temperature1);
	lv_label_set_align(label_hu_left, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(label_hu_left,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_39);
#ifdef BLOCKLY_label_hu_left_EVENT_HANDLER
	lv_obj_set_event_cb(label_hu_left, __qmsd_label_hu_left_cb);
#endif
	if(label_hu_left->coords.x2-label_hu_left->coords.x1<100)
	{
		int x_offset=(100-(label_hu_left->coords.x2-label_hu_left->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_hu_left,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_hu_left,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_hu_left->coords.y2-label_hu_left->coords.y1<40)
	{
		int y_offset=(40-(label_hu_left->coords.y2-label_hu_left->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_hu_left,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_hu_left,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(label_hu_left, 115-image_hu_bg->coords.x1+lv_obj_get_x(screen_humidity), 127-image_hu_bg->coords.y1+lv_obj_get_y(screen_humidity));
    qmsd_obj_set_id(label_hu_left,"label_hu_left");
}
#define humidity1  "40"
#define humidity2  "50"
    void qmsd_label_hu_right_create()
{
	label_hu_right = lv_label_create(screen_humidity, NULL);
	lv_label_set_long_mode(label_hu_right,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_hu_right,true);
	lv_obj_set_size(label_hu_right, 100, 40);
	lv_obj_set_parent(label_hu_right,image_hu_bg);
//set label style
	lv_obj_set_style_local_bg_color(label_hu_right,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x00, 0x70, 0xba));
	lv_obj_set_style_local_bg_opa(label_hu_right,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,255);
	lv_obj_set_style_local_text_color(label_hu_right,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(label_hu_right, humidity1);
	lv_label_set_align(label_hu_right, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(label_hu_right,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_38);
#ifdef BLOCKLY_label_hu_right_EVENT_HANDLER
	lv_obj_set_event_cb(label_hu_right, __qmsd_label_hu_right_cb);
#endif
	if(label_hu_right->coords.x2-label_hu_right->coords.x1<100)
	{
		int x_offset=(100-(label_hu_right->coords.x2-label_hu_right->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_hu_right,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_hu_right,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_hu_right->coords.y2-label_hu_right->coords.y1<40)
	{
		int y_offset=(40-(label_hu_right->coords.y2-label_hu_right->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_hu_right,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_hu_right,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(label_hu_right, 275-image_hu_bg->coords.x1+lv_obj_get_x(screen_humidity), 127-image_hu_bg->coords.y1+lv_obj_get_y(screen_humidity));
    qmsd_obj_set_id(label_hu_right,"label_hu_right");
}
    
void qmsd_image_hu_L_pod_create()
{
    image_hu_L_pod = lv_img_create(screen_humidity, NULL);
    lv_img_set_src(image_hu_L_pod, &imgpodetium_blue_png);
#ifdef BLOCKLY_image_hu_L_pod_EVENT_HANDLER
    lv_obj_set_event_cb(image_hu_L_pod, __qmsd_image_hu_L_pod_cb);
#endif
	lv_obj_set_parent(image_hu_L_pod,image_hu_bg);
    lv_obj_set_pos(image_hu_L_pod, 113-image_hu_bg->coords.x1+lv_obj_get_x(screen_humidity), 198-image_hu_bg->coords.y1+lv_obj_get_y(screen_humidity));
    qmsd_obj_set_id(image_hu_L_pod,"image_hu_L_pod");
}
    
void qmsd_image_hu_R_pod_create()
{
    image_hu_R_pod = lv_img_create(screen_humidity, NULL);
    lv_img_set_src(image_hu_R_pod, &imgpodetium_blue_png);
#ifdef BLOCKLY_image_hu_R_pod_EVENT_HANDLER
    lv_obj_set_event_cb(image_hu_R_pod, __qmsd_image_hu_R_pod_cb);
#endif
	lv_obj_set_parent(image_hu_R_pod,image_hu_bg);
    lv_obj_set_pos(image_hu_R_pod, 276-image_hu_bg->coords.x1+lv_obj_get_x(screen_humidity), 198-image_hu_bg->coords.y1+lv_obj_get_y(screen_humidity));
    qmsd_obj_set_id(image_hu_R_pod,"image_hu_R_pod");
}
    
void qmsd_image_h_L_podg_create()
{
    image_h_L_podg = lv_img_create(screen_humidity, NULL);
    lv_img_set_src(image_h_L_podg, &imgpodetium_g_png);
#ifdef BLOCKLY_image_h_L_podg_EVENT_HANDLER
    lv_obj_set_event_cb(image_h_L_podg, __qmsd_image_h_L_podg_cb);
#endif
    lv_obj_set_pos(image_h_L_podg, 122, 235);
    qmsd_obj_set_id(image_h_L_podg,"image_h_L_podg");
}
    
void qmsd_image_h_R_podg_create()
{
    image_h_R_podg = lv_img_create(screen_humidity, NULL);
    lv_img_set_src(image_h_R_podg, &imgpodetium_g_png);
#ifdef BLOCKLY_image_h_R_podg_EVENT_HANDLER
    lv_obj_set_event_cb(image_h_R_podg, __qmsd_image_h_R_podg_cb);
#endif
    lv_obj_set_pos(image_h_R_podg, 286, 235);
    qmsd_obj_set_id(image_h_R_podg,"image_h_R_podg");
}
    void qmsd_button_hu_left_create()
{
    button_hu_left = lv_imgbtn_create(screen_humidity, NULL);
    LV_IMG_DECLARE(imgbutton_bg_L_png);
    lv_imgbtn_set_src(button_hu_left, LV_BTN_STATE_RELEASED, &imgbutton_bg_L_png);
    lv_imgbtn_set_src(button_hu_left, LV_BTN_STATE_PRESSED, &imgbutton_bg_L_png);
    lv_imgbtn_set_src(button_hu_left, LV_BTN_STATE_DISABLED, &imgbutton_bg_L_png);
    lv_obj_set_size(button_hu_left, 78, 98);
	lv_obj_set_parent(button_hu_left,image_hu_bg);
    lv_obj_set_pos(button_hu_left, 7-image_hu_bg->coords.x1+lv_obj_get_x(screen_humidity), 198-image_hu_bg->coords.y1+lv_obj_get_y(screen_humidity));
#ifdef BLOCKLY_button_hu_left_EVENT_HANDLER
    lv_obj_set_event_cb(button_hu_left, __qmsd_button_hu_left_cb);
#endif


    lv_obj_t* obj = button_hu_left;
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
    lv_obj_set_style_local_outline_width(button_hu_left,LV_BTN_PART_MAIN,LV_STATE_DEFAULT,0);
	lv_obj_set_style_local_outline_width(button_hu_left,LV_BTN_PART_MAIN,LV_STATE_FOCUSED,0);
    qmsd_obj_set_id(button_hu_left,"button_hu_left");
}
    
void qmsd_image_hu_left_create()
{
    image_hu_left = lv_img_create(screen_humidity, NULL);
    lv_img_set_src(image_hu_left, &imgleft_icn_png);
#ifdef BLOCKLY_image_hu_left_EVENT_HANDLER
    lv_obj_set_event_cb(image_hu_left, __qmsd_image_hu_left_cb);
#endif
	lv_obj_set_parent(image_hu_left,button_hu_left);
    lv_obj_set_pos(image_hu_left, 12-button_hu_left->coords.x1+lv_obj_get_x(screen_humidity), 220-button_hu_left->coords.y1+lv_obj_get_y(screen_humidity));
    qmsd_obj_set_id(image_hu_left,"image_hu_left");
}
    void qmsd_button_hu_right_create()
{
    button_hu_right = lv_imgbtn_create(screen_humidity, NULL);
    LV_IMG_DECLARE(imgbutton_bg_L_png);
    lv_imgbtn_set_src(button_hu_right, LV_BTN_STATE_RELEASED, &imgbutton_bg_L_png);
    lv_imgbtn_set_src(button_hu_right, LV_BTN_STATE_PRESSED, &imgbutton_bg_L_png);
    lv_imgbtn_set_src(button_hu_right, LV_BTN_STATE_DISABLED, &imgbutton_bg_L_png);
    lv_obj_set_size(button_hu_right, 78, 98);
	lv_obj_set_parent(button_hu_right,image_hu_bg);
    lv_obj_set_pos(button_hu_right, 398-image_hu_bg->coords.x1+lv_obj_get_x(screen_humidity), 198-image_hu_bg->coords.y1+lv_obj_get_y(screen_humidity));
#ifdef BLOCKLY_button_hu_right_EVENT_HANDLER
    lv_obj_set_event_cb(button_hu_right, __qmsd_button_hu_right_cb);
#endif


    lv_obj_t* obj = button_hu_right;
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
    lv_obj_set_style_local_outline_width(button_hu_right,LV_BTN_PART_MAIN,LV_STATE_DEFAULT,0);
	lv_obj_set_style_local_outline_width(button_hu_right,LV_BTN_PART_MAIN,LV_STATE_FOCUSED,0);
    qmsd_obj_set_id(button_hu_right,"button_hu_right");
}
    
void qmsd_image_hu_right_create()
{
    image_hu_right = lv_img_create(screen_humidity, NULL);
    lv_img_set_src(image_hu_right, &imgright_icn_png);
#ifdef BLOCKLY_image_hu_right_EVENT_HANDLER
    lv_obj_set_event_cb(image_hu_right, __qmsd_image_hu_right_cb);
#endif
	lv_obj_set_parent(image_hu_right,button_hu_right);
    lv_obj_set_pos(image_hu_right, 444-button_hu_right->coords.x1+lv_obj_get_x(screen_humidity), 220-button_hu_right->coords.y1+lv_obj_get_y(screen_humidity));
    qmsd_obj_set_id(image_hu_right,"image_hu_right");
}
    
void qmsd_image_hu_dw_L_create()
{
    image_hu_dw_L = lv_img_create(screen_humidity, NULL);
    lv_img_set_src(image_hu_dw_L, &imgdownward_png);
#ifdef BLOCKLY_image_hu_dw_L_EVENT_HANDLER
    lv_obj_set_event_cb(image_hu_dw_L, __qmsd_image_hu_dw_L_cb);
#endif
    lv_obj_set_pos(image_hu_dw_L, 150, 222);
    qmsd_obj_set_id(image_hu_dw_L,"image_hu_dw_L");
}
    
void qmsd_image_hu_dw_R_create()
{
    image_hu_dw_R = lv_img_create(screen_humidity, NULL);
    lv_img_set_src(image_hu_dw_R, &imgupward_png);
#ifdef BLOCKLY_image_hu_dw_R_EVENT_HANDLER
    lv_obj_set_event_cb(image_hu_dw_R, __qmsd_image_hu_dw_R_cb);
#endif
    lv_obj_set_pos(image_hu_dw_R, 315, 222);
    qmsd_obj_set_id(image_hu_dw_R,"image_hu_dw_R");
}
    
void qmsd_image_hu_L_or_create()
{
    image_hu_L_or = lv_img_create(screen_humidity, NULL);
    lv_img_set_src(image_hu_L_or, &imgpodetium_or_png);
#ifdef BLOCKLY_image_hu_L_or_EVENT_HANDLER
    lv_obj_set_event_cb(image_hu_L_or, __qmsd_image_hu_L_or_cb);
#endif
	lv_obj_set_parent(image_hu_L_or,image_hu_L_pod);
    lv_obj_set_pos(image_hu_L_or, 125-image_hu_L_pod->coords.x1+lv_obj_get_x(screen_humidity), 207-image_hu_L_pod->coords.y1+lv_obj_get_y(screen_humidity));
    qmsd_obj_set_id(image_hu_L_or,"image_hu_L_or");
}
    
void qmsd_image_hu_R_or_create()
{
    image_hu_R_or = lv_img_create(screen_humidity, NULL);
    lv_img_set_src(image_hu_R_or, &imgpodetium_or_png);
#ifdef BLOCKLY_image_hu_R_or_EVENT_HANDLER
    lv_obj_set_event_cb(image_hu_R_or, __qmsd_image_hu_R_or_cb);
#endif
	lv_obj_set_parent(image_hu_R_or,image_hu_R_pod);
    lv_obj_set_pos(image_hu_R_or, 287-image_hu_R_pod->coords.x1+lv_obj_get_x(screen_humidity), 207-image_hu_R_pod->coords.y1+lv_obj_get_y(screen_humidity));
    qmsd_obj_set_id(image_hu_R_or,"image_hu_R_or");
}
    
void qmsd_image_hu_LD_or_create()
{
    image_hu_LD_or = lv_img_create(screen_humidity, NULL);
    lv_img_set_src(image_hu_LD_or, &imgpodetium_or_png);
#ifdef BLOCKLY_image_hu_LD_or_EVENT_HANDLER
    lv_obj_set_event_cb(image_hu_LD_or, __qmsd_image_hu_LD_or_cb);
#endif
	lv_obj_set_parent(image_hu_LD_or,image_hu_L_pod);
    lv_obj_set_pos(image_hu_LD_or, 121-image_hu_L_pod->coords.x1+lv_obj_get_x(screen_humidity), 338-image_hu_L_pod->coords.y1+lv_obj_get_y(screen_humidity));
    qmsd_obj_set_id(image_hu_LD_or,"image_hu_LD_or");
}
    
void qmsd_image_hu_RD_or_create()
{
    image_hu_RD_or = lv_img_create(screen_humidity, NULL);
    lv_img_set_src(image_hu_RD_or, &imgpodetium_or_png);
#ifdef BLOCKLY_image_hu_RD_or_EVENT_HANDLER
    lv_obj_set_event_cb(image_hu_RD_or, __qmsd_image_hu_RD_or_cb);
#endif
	lv_obj_set_parent(image_hu_RD_or,image_hu_R_pod);
    lv_obj_set_pos(image_hu_RD_or, 285-image_hu_R_pod->coords.x1+lv_obj_get_x(screen_humidity), 338-image_hu_R_pod->coords.y1+lv_obj_get_y(screen_humidity));
    qmsd_obj_set_id(image_hu_RD_or,"image_hu_RD_or");
}
    void qmsd_label_title_t_create()
{
	label_title_t = lv_label_create(screen_humidity, NULL);
	lv_label_set_long_mode(label_title_t,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_title_t,true);
	lv_obj_set_size(label_title_t, 100, 51);
	lv_obj_set_parent(label_title_t,image_hu_bg);
//set label style
	lv_obj_set_style_local_bg_color(label_title_t,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x00, 0x70, 0xba));
	lv_obj_set_style_local_bg_opa(label_title_t,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,255);
	lv_obj_set_style_local_text_color(label_title_t,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(label_title_t, "温度");
	lv_label_set_align(label_title_t, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(label_title_t,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_41);
#ifdef BLOCKLY_label_title_t_EVENT_HANDLER
	lv_obj_set_event_cb(label_title_t, __qmsd_label_title_t_cb);
#endif
	if(label_title_t->coords.x2-label_title_t->coords.x1<100)
	{
		int x_offset=(100-(label_title_t->coords.x2-label_title_t->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_title_t,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_title_t,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_title_t->coords.y2-label_title_t->coords.y1<51)
	{
		int y_offset=(51-(label_title_t->coords.y2-label_title_t->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_title_t,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_title_t,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(label_title_t, 119-image_hu_bg->coords.x1+lv_obj_get_x(screen_humidity), 76-image_hu_bg->coords.y1+lv_obj_get_y(screen_humidity));
    qmsd_obj_set_id(label_title_t,"label_title_t");
}
    void qmsd_label_title_hu_create()
{
	label_title_hu = lv_label_create(screen_humidity, NULL);
	lv_label_set_long_mode(label_title_hu,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_title_hu,true);
	lv_obj_set_size(label_title_hu, 100, 51);
	lv_obj_set_parent(label_title_hu,image_hu_bg);
//set label style
	lv_obj_set_style_local_bg_color(label_title_hu,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x00, 0x70, 0xba));
	lv_obj_set_style_local_bg_opa(label_title_hu,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,255);
	lv_obj_set_style_local_text_color(label_title_hu,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(label_title_hu, "湿度");
	lv_label_set_align(label_title_hu, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(label_title_hu,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_41);
#ifdef BLOCKLY_label_title_hu_EVENT_HANDLER
	lv_obj_set_event_cb(label_title_hu, __qmsd_label_title_hu_cb);
#endif
	if(label_title_hu->coords.x2-label_title_hu->coords.x1<100)
	{
		int x_offset=(100-(label_title_hu->coords.x2-label_title_hu->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_title_hu,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_title_hu,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_title_hu->coords.y2-label_title_hu->coords.y1<51)
	{
		int y_offset=(51-(label_title_hu->coords.y2-label_title_hu->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_title_hu,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_title_hu,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(label_title_hu, 272-image_hu_bg->coords.x1+lv_obj_get_x(screen_humidity), 76-image_hu_bg->coords.y1+lv_obj_get_y(screen_humidity));
    qmsd_obj_set_id(label_title_hu,"label_title_hu");
}
    void qmsd_label_du_create()
{
	label_du = lv_label_create(screen_humidity, NULL);
	lv_label_set_long_mode(label_du,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_du,true);
	lv_obj_set_size(label_du, 68, 31);
	lv_obj_set_parent(label_du,image_hu_bg);
//set label style
	lv_obj_set_style_local_bg_color(label_du,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x00, 0x70, 0xba));
	lv_obj_set_style_local_bg_opa(label_du,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,255);
	lv_obj_set_style_local_text_color(label_du,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x53, 0xb3, 0xf9));

	lv_label_set_text(label_du, "℃");
	lv_label_set_align(label_du, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(label_du,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_22);
#ifdef BLOCKLY_label_du_EVENT_HANDLER
	lv_obj_set_event_cb(label_du, __qmsd_label_du_cb);
#endif
	if(label_du->coords.x2-label_du->coords.x1<68)
	{
		int x_offset=(68-(label_du->coords.x2-label_du->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_du,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_du,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_du->coords.y2-label_du->coords.y1<31)
	{
		int y_offset=(31-(label_du->coords.y2-label_du->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_du,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_du,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(label_du, 125-image_hu_bg->coords.x1+lv_obj_get_x(screen_humidity), 167-image_hu_bg->coords.y1+lv_obj_get_y(screen_humidity));
    qmsd_obj_set_id(label_du,"label_du");
}
    void qmsd_label_perc_create()
{
	label_perc = lv_label_create(screen_humidity, NULL);
	lv_label_set_long_mode(label_perc,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_perc,true);
	lv_obj_set_size(label_perc, 77, 23);
	lv_obj_set_parent(label_perc,image_hu_bg);
//set label style
	lv_obj_set_style_local_bg_color(label_perc,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x00, 0x70, 0xba));
	lv_obj_set_style_local_bg_opa(label_perc,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,255);
	lv_obj_set_style_local_text_color(label_perc,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x53, 0xb0, 0xf6));

	lv_label_set_text(label_perc, "%");
	lv_label_set_align(label_perc, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(label_perc,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_24);
#ifdef BLOCKLY_label_perc_EVENT_HANDLER
	lv_obj_set_event_cb(label_perc, __qmsd_label_perc_cb);
#endif
	if(label_perc->coords.x2-label_perc->coords.x1<77)
	{
		int x_offset=(77-(label_perc->coords.x2-label_perc->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_perc,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_perc,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_perc->coords.y2-label_perc->coords.y1<23)
	{
		int y_offset=(23-(label_perc->coords.y2-label_perc->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_perc,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_perc,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(label_perc, 285-image_hu_bg->coords.x1+lv_obj_get_x(screen_humidity), 167-image_hu_bg->coords.y1+lv_obj_get_y(screen_humidity));
    qmsd_obj_set_id(label_perc,"label_perc");
}

static void screen_humidity_qmsd_cb(lv_obj_t * obj, lv_event_t event, void *data)
{/*
    char *trans;
    lv_label_set_text(label_hu_left,qmsd_lang_get_trans("label_hu_left","Label"));
    lv_label_set_text(label_hu_right,qmsd_lang_get_trans("label_hu_right","Label"));
    lv_label_set_text(label_title_t,qmsd_lang_get_trans("label_title_t","温度"));
    lv_label_set_text(label_title_hu,qmsd_lang_get_trans("label_title_hu","湿度"));
    lv_label_set_text(label_du,qmsd_lang_get_trans("label_du","℃"));
    lv_label_set_text(label_perc,qmsd_lang_get_trans("label_perc","%"));
*/
#ifdef BLOCKLY_screen_humidity_SCREEN_INIT
    __qmsd_screen_humidity_init();
#endif
}

static void hu_poress_task_cb(lv_task_t * t)
{
	if(hu_index == 0){
		hu_index = 1;
	}else{
		hu_index = 0;
	}
	if(hu_index){
		lv_obj_set_size(image_h_L_podg,76,50);
		lv_obj_set_pos(image_h_L_podg, 122, 284);
		lv_obj_set_pos(image_hu_dw_L, 150, 222+50);

		lv_obj_set_size(image_h_R_podg,76,50);
		lv_obj_set_pos(image_h_R_podg, 286, 284);
		lv_obj_set_pos(image_hu_dw_R, 315, 222+50);

		lv_label_set_text(label_hu_left, temperature2);
		lv_label_set_text(label_hu_right, humidity2);
	}else{
		lv_obj_set_size(image_h_L_podg,76,30);
		lv_obj_set_pos(image_h_L_podg, 122, 304);
		lv_obj_set_pos(image_hu_dw_L, 150, 222+70);

		lv_obj_set_size(image_h_R_podg,76,20);
		lv_obj_set_pos(image_h_R_podg, 286, 314);
		lv_obj_set_pos(image_hu_dw_R, 315, 222+80);

		lv_label_set_text(label_hu_left, temperature1);
		lv_label_set_text(label_hu_right, humidity1);
	}
}
lv_task_t * hu_my_task = NULL;
static void hu_create_lv_task(void)
{
	lv_obj_t* image_temp = NULL;
	hu_my_task = lv_task_create(hu_poress_task_cb, 1000, LV_TASK_PRIO_HIGH, image_temp);

}
static void screen_humidity_del_cb(lv_obj_t* obj,lv_event_t event)
{
    if(event == LV_EVENT_DELETE)
    {
        screen_humidity=NULL;
        qmsd_screen_remove("screen_humidity");
    }
}

void screen_humidity_build(void)
{
    if(screen_humidity) return;
    screen_humidity = lv_obj_create(NULL, NULL);
    lv_obj_qmsd_set_cb(screen_humidity, screen_humidity_qmsd_cb);

    qmsd_image_hu_bg_create();
    qmsd_image_hu_xiaoka_create();
    qmsd_image_hu_u_pon1_create();
    qmsd_image_hu_s_pon_create();
    qmsd_image_hu_u_pon2_create();
    qmsd_image_hu_u_pon3_create();
    qmsd_image_hu_down_create();
    qmsd_image_hu_menu_create();
    qmsd_label_hu_left_create();
    qmsd_label_hu_right_create();
    qmsd_image_hu_L_pod_create();
    qmsd_image_hu_R_pod_create();
    qmsd_image_h_L_podg_create();
    qmsd_image_h_R_podg_create();
    qmsd_button_hu_left_create();
    qmsd_image_hu_left_create();
    qmsd_button_hu_right_create();
    qmsd_image_hu_right_create();
    qmsd_image_hu_dw_L_create();
    qmsd_image_hu_dw_R_create();
    qmsd_image_hu_L_or_create();
    qmsd_image_hu_R_or_create();
    qmsd_image_hu_LD_or_create();
    qmsd_image_hu_RD_or_create();
    qmsd_label_title_t_create();
    qmsd_label_title_hu_create();
    qmsd_label_du_create();
    qmsd_label_perc_create();
	anim_set(image_hu_xiaoka,lv_img_set_zoom,180,256,1000,0,LV_ANIM_REPEAT_INFINITE,1000);
	hu_create_lv_task();
    lv_obj_set_event_cb(screen_humidity,screen_humidity_del_cb);
    qmsd_screen_register(screen_humidity,"screen_humidity");
}

void screen_humidity_show(void)
{
    if(!screen_humidity)
    {
        screen_humidity_build();
    }
    lv_scr_load(screen_humidity);
}

void screen_humidity_delete(void)
{
	lv_task_del(hu_my_task);
    if(screen_humidity)
    {
        lv_obj_del(screen_humidity);
        screen_humidity = NULL;
    }
}
