#include "qmsd_ui_entry.h"
#include "qmsd_internal_ui_cb.h"

lv_obj_t* screen_main;
lv_obj_t* image_bg_blue;
lv_obj_t* image_xiaoka;
lv_obj_t* image_s_pon_1;
lv_obj_t* image_un_pon_1;
lv_obj_t* image_un_pon_2;
lv_obj_t* image_un_pon_3;
lv_obj_t* image_title;
lv_obj_t* button_left;
lv_obj_t * __button_left_label;
lv_obj_t* image_left_icn;
lv_obj_t* button_right;
lv_obj_t * __button_right_label;
lv_obj_t* image_right_icn;
lv_obj_t* label_main_left;
lv_obj_t* label_main_rig;
lv_obj_t* image_down;
lv_obj_t* image_menu;
lv_obj_t* image_L_Pod;
lv_obj_t* image_R_Pod;
lv_obj_t* image_L_Pod_g;
lv_obj_t* image_R_Pod_g;
lv_obj_t* image_dw_L;
lv_obj_t* image_dw_R;
lv_obj_t* image_L_or;
lv_obj_t* image_R_or;
lv_obj_t* image_LL_pod;
lv_obj_t* image_RL_pod;

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
    
void qmsd_image_bg_blue_create()
{
    image_bg_blue = lv_img_create(screen_main, NULL);
    lv_img_set_src(image_bg_blue, &imgbg_blue_c_png);
#ifdef BLOCKLY_image_bg_blue_EVENT_HANDLER
    lv_obj_set_event_cb(image_bg_blue, __qmsd_image_bg_blue_cb);
#endif
    lv_obj_set_pos(image_bg_blue, 0, 0);
    qmsd_obj_set_id(image_bg_blue,"image_bg_blue");
}
    
void qmsd_image_xiaoka_create()
{
    image_xiaoka = lv_img_create(screen_main, NULL);
    lv_img_set_src(image_xiaoka, &imgxiaoka_png);
#ifdef BLOCKLY_image_xiaoka_EVENT_HANDLER
    lv_obj_set_event_cb(image_xiaoka, __qmsd_image_xiaoka_cb);
#endif
	lv_obj_set_parent(image_xiaoka,image_bg_blue);
    lv_obj_set_pos(image_xiaoka, 190-image_bg_blue->coords.x1+lv_obj_get_x(screen_main), 16-image_bg_blue->coords.y1+lv_obj_get_y(screen_main));
    qmsd_obj_set_id(image_xiaoka,"image_xiaoka");
}
    
void qmsd_image_s_pon_1_create()
{
    image_s_pon_1 = lv_img_create(screen_main, NULL);
    lv_img_set_src(image_s_pon_1, &imgdown_s_point_png);
#ifdef BLOCKLY_image_s_pon_1_EVENT_HANDLER
    lv_obj_set_event_cb(image_s_pon_1, __qmsd_image_s_pon_1_cb);
#endif
	lv_obj_set_parent(image_s_pon_1,image_bg_blue);
    lv_obj_set_pos(image_s_pon_1, 161-image_bg_blue->coords.x1+lv_obj_get_x(screen_main), 380-image_bg_blue->coords.y1+lv_obj_get_y(screen_main));
    qmsd_obj_set_id(image_s_pon_1,"image_s_pon_1");
}
    
void qmsd_image_un_pon_1_create()
{
    image_un_pon_1 = lv_img_create(screen_main, NULL);
    lv_img_set_src(image_un_pon_1, &imgdown_un_point_png);
#ifdef BLOCKLY_image_un_pon_1_EVENT_HANDLER
    lv_obj_set_event_cb(image_un_pon_1, __qmsd_image_un_pon_1_cb);
#endif
	lv_obj_set_parent(image_un_pon_1,image_bg_blue);
    lv_obj_set_pos(image_un_pon_1, 205-image_bg_blue->coords.x1+lv_obj_get_x(screen_main), 380-image_bg_blue->coords.y1+lv_obj_get_y(screen_main));
    qmsd_obj_set_id(image_un_pon_1,"image_un_pon_1");
}
    
void qmsd_image_un_pon_2_create()
{
    image_un_pon_2 = lv_img_create(screen_main, NULL);
    lv_img_set_src(image_un_pon_2, &imgdown_un_point_png);
#ifdef BLOCKLY_image_un_pon_2_EVENT_HANDLER
    lv_obj_set_event_cb(image_un_pon_2, __qmsd_image_un_pon_2_cb);
#endif
	lv_obj_set_parent(image_un_pon_2,image_bg_blue);
    lv_obj_set_pos(image_un_pon_2, 247-image_bg_blue->coords.x1+lv_obj_get_x(screen_main), 380-image_bg_blue->coords.y1+lv_obj_get_y(screen_main));
    qmsd_obj_set_id(image_un_pon_2,"image_un_pon_2");
}
    
void qmsd_image_un_pon_3_create()
{
    image_un_pon_3 = lv_img_create(screen_main, NULL);
    lv_img_set_src(image_un_pon_3, &imgdown_un_point_png);
#ifdef BLOCKLY_image_un_pon_3_EVENT_HANDLER
    lv_obj_set_event_cb(image_un_pon_3, __qmsd_image_un_pon_3_cb);
#endif
	lv_obj_set_parent(image_un_pon_3,image_bg_blue);
    lv_obj_set_pos(image_un_pon_3, 290-image_bg_blue->coords.x1+lv_obj_get_x(screen_main), 380-image_bg_blue->coords.y1+lv_obj_get_y(screen_main));
    qmsd_obj_set_id(image_un_pon_3,"image_un_pon_3");
}
    
void qmsd_image_title_create()
{
    image_title = lv_img_create(screen_main, NULL);
    lv_img_set_src(image_title, &imgtitle_png);
#ifdef BLOCKLY_image_title_EVENT_HANDLER
    lv_obj_set_event_cb(image_title, __qmsd_image_title_cb);
#endif
	lv_obj_set_parent(image_title,image_bg_blue);
    lv_obj_set_pos(image_title, 112-image_bg_blue->coords.x1+lv_obj_get_x(screen_main), 81-image_bg_blue->coords.y1+lv_obj_get_y(screen_main));
    qmsd_obj_set_id(image_title,"image_title");
}
    void qmsd_button_left_create()
{
    button_left = lv_imgbtn_create(screen_main, NULL);
    LV_IMG_DECLARE(imgbutton_bg_L_png);
    lv_imgbtn_set_src(button_left, LV_BTN_STATE_RELEASED, &imgbutton_bg_L_png);
    lv_imgbtn_set_src(button_left, LV_BTN_STATE_PRESSED, &imgbutton_bg_L_png);
    lv_imgbtn_set_src(button_left, LV_BTN_STATE_DISABLED, &imgbutton_bg_L_png);
    lv_obj_set_size(button_left, 78, 98);
	lv_obj_set_parent(button_left,image_bg_blue);
    lv_obj_set_pos(button_left, 7-image_bg_blue->coords.x1+lv_obj_get_x(screen_main), 198-image_bg_blue->coords.y1+lv_obj_get_y(screen_main));
#ifdef BLOCKLY_button_left_EVENT_HANDLER
    lv_obj_set_event_cb(button_left, __qmsd_button_left_cb);
#endif


    lv_obj_t* obj = button_left;
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
    lv_obj_set_style_local_outline_width(button_left,LV_BTN_PART_MAIN,LV_STATE_DEFAULT,0);
	lv_obj_set_style_local_outline_width(button_left,LV_BTN_PART_MAIN,LV_STATE_FOCUSED,0);
    qmsd_obj_set_id(button_left,"button_left");
}
    
void qmsd_image_left_icn_create()
{
    image_left_icn = lv_img_create(screen_main, NULL);
    lv_img_set_src(image_left_icn, &imgleft_icn_png);
#ifdef BLOCKLY_image_left_icn_EVENT_HANDLER
    lv_obj_set_event_cb(image_left_icn, __qmsd_image_left_icn_cb);
#endif
	lv_obj_set_parent(image_left_icn,button_left);
    lv_obj_set_pos(image_left_icn, 12-button_left->coords.x1+lv_obj_get_x(screen_main), 220-button_left->coords.y1+lv_obj_get_y(screen_main));
    qmsd_obj_set_id(image_left_icn,"image_left_icn");
}
    void qmsd_button_right_create()
{
    button_right = lv_imgbtn_create(screen_main, NULL);
    LV_IMG_DECLARE(imgbutton_bg_L_png);
    lv_imgbtn_set_src(button_right, LV_BTN_STATE_RELEASED, &imgbutton_bg_L_png);
    lv_imgbtn_set_src(button_right, LV_BTN_STATE_PRESSED, &imgbutton_bg_L_png);
    lv_imgbtn_set_src(button_right, LV_BTN_STATE_DISABLED, &imgbutton_bg_L_png);
    lv_obj_set_size(button_right, 78, 98);
	lv_obj_set_parent(button_right,image_bg_blue);
    lv_obj_set_pos(button_right, 398-image_bg_blue->coords.x1+lv_obj_get_x(screen_main), 198-image_bg_blue->coords.y1+lv_obj_get_y(screen_main));
#ifdef BLOCKLY_button_right_EVENT_HANDLER
    lv_obj_set_event_cb(button_right, __qmsd_button_right_cb);
#endif


    lv_obj_t* obj = button_right;
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
    lv_obj_set_style_local_outline_width(button_right,LV_BTN_PART_MAIN,LV_STATE_DEFAULT,0);
	lv_obj_set_style_local_outline_width(button_right,LV_BTN_PART_MAIN,LV_STATE_FOCUSED,0);
    qmsd_obj_set_id(button_right,"button_right");
}
    
void qmsd_image_right_icn_create()
{
    image_right_icn = lv_img_create(screen_main, NULL);
    lv_img_set_src(image_right_icn, &imgright_icn_png);
#ifdef BLOCKLY_image_right_icn_EVENT_HANDLER
    lv_obj_set_event_cb(image_right_icn, __qmsd_image_right_icn_cb);
#endif
	lv_obj_set_parent(image_right_icn,button_right);
    lv_obj_set_pos(image_right_icn, 444-button_right->coords.x1+lv_obj_get_x(screen_main), 220-button_right->coords.y1+lv_obj_get_y(screen_main));
    qmsd_obj_set_id(image_right_icn,"image_right_icn");
}
#define pm2_51 "35"
#define pm2_52 "38"
static uint8_t temp_index = 0;
	void qmsd_label_main_left_create()
{
	label_main_left = lv_label_create(screen_main, NULL);
	lv_label_set_long_mode(label_main_left,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_main_left,true);
	lv_obj_set_size(label_main_left, 100, 40);
	lv_obj_set_parent(label_main_left,image_bg_blue);
//set label style
	lv_obj_set_style_local_bg_color(label_main_left,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x00, 0x70, 0xba));
	lv_obj_set_style_local_bg_opa(label_main_left,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,255);
	lv_obj_set_style_local_text_color(label_main_left,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));


	lv_label_set_text(label_main_left, pm2_51);
	lv_label_set_align(label_main_left, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(label_main_left,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_39);
#ifdef BLOCKLY_label_main_left_EVENT_HANDLER
	lv_obj_set_event_cb(label_main_left, __qmsd_label_main_left_cb);
#endif
	if(label_main_left->coords.x2-label_main_left->coords.x1<100)
	{
		int x_offset=(100-(label_main_left->coords.x2-label_main_left->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_main_left,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_main_left,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_main_left->coords.y2-label_main_left->coords.y1<40)
	{
		int y_offset=(40-(label_main_left->coords.y2-label_main_left->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_main_left,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_main_left,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(label_main_left, 105-image_bg_blue->coords.x1+lv_obj_get_x(screen_main), 117-image_bg_blue->coords.y1+lv_obj_get_y(screen_main));
    qmsd_obj_set_id(label_main_left,"label_main_left");
}
#define harmful_gas1  "0.003"
#define harmful_gas2  "0.016"
    void qmsd_label_main_rig_create()
{
	label_main_rig = lv_label_create(screen_main, NULL);
	lv_label_set_long_mode(label_main_rig,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_main_rig,true);
	lv_obj_set_size(label_main_rig, 100, 40);
	lv_obj_set_parent(label_main_rig,image_bg_blue);
//set label style
	lv_obj_set_style_local_bg_color(label_main_rig,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x00, 0x70, 0xba));
	lv_obj_set_style_local_bg_opa(label_main_rig,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,255);
	lv_obj_set_style_local_text_color(label_main_rig,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	//sprintf(temp_harmful_gas,"%s",);
	if(temp_index){
		lv_label_set_text(label_main_rig, harmful_gas2);
	}else{
		lv_label_set_text(label_main_rig, harmful_gas1);
	}
	lv_label_set_align(label_main_rig, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(label_main_rig,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_38);
#ifdef BLOCKLY_label_main_rig_EVENT_HANDLER
	lv_obj_set_event_cb(label_main_rig, __qmsd_label_main_rig_cb);
#endif
	if(label_main_rig->coords.x2-label_main_rig->coords.x1<100)
	{
		int x_offset=(100-(label_main_rig->coords.x2-label_main_rig->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_main_rig,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_main_rig,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_main_rig->coords.y2-label_main_rig->coords.y1<40)
	{
		int y_offset=(40-(label_main_rig->coords.y2-label_main_rig->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_main_rig,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_main_rig,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(label_main_rig, 265-image_bg_blue->coords.x1+lv_obj_get_x(screen_main), 117-image_bg_blue->coords.y1+lv_obj_get_y(screen_main));
    qmsd_obj_set_id(label_main_rig,"label_main_rig");
}
    
void qmsd_image_down_create()
{
    image_down = lv_img_create(screen_main, NULL);
    lv_img_set_src(image_down, &imgdown_png);
#ifdef BLOCKLY_image_down_EVENT_HANDLER
    lv_obj_set_event_cb(image_down, __qmsd_image_down_cb);
#endif
	lv_obj_set_parent(image_down,image_bg_blue);
    lv_obj_set_pos(image_down, 7-image_bg_blue->coords.x1+lv_obj_get_x(screen_main), 406-image_bg_blue->coords.y1+lv_obj_get_y(screen_main));
    qmsd_obj_set_id(image_down,"image_down");
}
    
void qmsd_image_menu_create()
{
    image_menu = lv_img_create(screen_main, NULL);
    lv_img_set_src(image_menu, &imgmenu_ivn_png);
#ifdef BLOCKLY_image_menu_EVENT_HANDLER
    lv_obj_set_event_cb(image_menu, __qmsd_image_menu_cb);
#endif
	lv_obj_set_parent(image_menu,image_down);
    lv_obj_set_pos(image_menu, 224-image_down->coords.x1+lv_obj_get_x(screen_main), 428-image_down->coords.y1+lv_obj_get_y(screen_main));
    qmsd_obj_set_id(image_menu,"image_menu");
}
    
void qmsd_image_L_Pod_create()
{
    image_L_Pod = lv_img_create(screen_main, NULL);
    lv_img_set_src(image_L_Pod, &imgpodetium_blue_png);
#ifdef BLOCKLY_image_L_Pod_EVENT_HANDLER
    lv_obj_set_event_cb(image_L_Pod, __qmsd_image_L_Pod_cb);
#endif
	lv_obj_set_parent(image_L_Pod,image_bg_blue);
    lv_obj_set_pos(image_L_Pod, 113-image_bg_blue->coords.x1+lv_obj_get_x(screen_main), 198-image_bg_blue->coords.y1+lv_obj_get_y(screen_main));
    qmsd_obj_set_id(image_L_Pod,"image_L_Pod");
}
    
void qmsd_image_R_Pod_create()
{
    image_R_Pod = lv_img_create(screen_main, NULL);
    lv_img_set_src(image_R_Pod, &imgpodetium_blue_png);
#ifdef BLOCKLY_image_R_Pod_EVENT_HANDLER
    lv_obj_set_event_cb(image_R_Pod, __qmsd_image_R_Pod_cb);
#endif
	lv_obj_set_parent(image_R_Pod,image_bg_blue);
    lv_obj_set_pos(image_R_Pod, 276-image_bg_blue->coords.x1+lv_obj_get_x(screen_main), 198-image_bg_blue->coords.y1+lv_obj_get_y(screen_main));
    qmsd_obj_set_id(image_R_Pod,"image_R_Pod");
}
    
void qmsd_image_L_Pod_g_create()
{
    image_L_Pod_g = lv_img_create(screen_main, NULL);
    lv_img_set_src(image_L_Pod_g, &imgpodetium_g_png);
#ifdef BLOCKLY_image_L_Pod_g_EVENT_HANDLER
    lv_obj_set_event_cb(image_L_Pod_g, __qmsd_image_L_Pod_g_cb);
#endif
    lv_obj_set_size(image_L_Pod_g,76,50);
    lv_obj_set_pos(image_L_Pod_g, 122, 284);
    qmsd_obj_set_id(image_L_Pod_g,"image_L_Pod_g");
}
    
void qmsd_image_R_Pod_g_create()
{
    image_R_Pod_g = lv_img_create(screen_main, NULL);
    lv_img_set_src(image_R_Pod_g, &imgpodetium_g_png);
#ifdef BLOCKLY_image_R_Pod_g_EVENT_HANDLER
    lv_obj_set_event_cb(image_R_Pod_g, __qmsd_image_R_Pod_g_cb);
#endif
    lv_obj_set_size(image_R_Pod_g,76,50);
    lv_obj_set_pos(image_R_Pod_g, 286, 284);
    qmsd_obj_set_id(image_R_Pod_g,"image_R_Pod_g");
}
    
void qmsd_image_dw_L_create()
{
    image_dw_L = lv_img_create(screen_main, NULL);
    lv_img_set_src(image_dw_L, &imgdownward_png);
#ifdef BLOCKLY_image_dw_L_EVENT_HANDLER
    lv_obj_set_event_cb(image_dw_L, __qmsd_image_dw_L_cb);
#endif
    lv_obj_set_pos(image_dw_L, 150, 222+50);
    qmsd_obj_set_id(image_dw_L,"image_dw_L");
}
    
void qmsd_image_dw_R_create()
{
    image_dw_R = lv_img_create(screen_main, NULL);
    lv_img_set_src(image_dw_R, &imgupward_png);
#ifdef BLOCKLY_image_dw_R_EVENT_HANDLER
    lv_obj_set_event_cb(image_dw_R, __qmsd_image_dw_R_cb);
#endif
    lv_obj_set_pos(image_dw_R, 315, 222+50);
    qmsd_obj_set_id(image_dw_R,"image_dw_R");
}
    
void qmsd_image_L_or_create()
{
    image_L_or = lv_img_create(screen_main, NULL);
    lv_img_set_src(image_L_or, &imgpodetium_or_png);
#ifdef BLOCKLY_image_L_or_EVENT_HANDLER
    lv_obj_set_event_cb(image_L_or, __qmsd_image_L_or_cb);
#endif
	lv_obj_set_parent(image_L_or,image_L_Pod);
    lv_obj_set_pos(image_L_or, 125-image_L_Pod->coords.x1+lv_obj_get_x(screen_main), 207-image_L_Pod->coords.y1+lv_obj_get_y(screen_main));
    qmsd_obj_set_id(image_L_or,"image_L_or");
}
    
void qmsd_image_R_or_create()
{
    image_R_or = lv_img_create(screen_main, NULL);
    lv_img_set_src(image_R_or, &imgpodetium_or_png);
#ifdef BLOCKLY_image_R_or_EVENT_HANDLER
    lv_obj_set_event_cb(image_R_or, __qmsd_image_R_or_cb);
#endif
	lv_obj_set_parent(image_R_or,image_R_Pod);
    lv_obj_set_pos(image_R_or, 287-image_R_Pod->coords.x1+lv_obj_get_x(screen_main), 207-image_R_Pod->coords.y1+lv_obj_get_y(screen_main));
    qmsd_obj_set_id(image_R_or,"image_R_or");
}
    
void qmsd_image_LL_pod_create()
{
    image_LL_pod = lv_img_create(screen_main, NULL);
    lv_img_set_src(image_LL_pod, &imgpodetium_g_L_png);
#ifdef BLOCKLY_image_LL_pod_EVENT_HANDLER
    lv_obj_set_event_cb(image_LL_pod, __qmsd_image_LL_pod_cb);
#endif
	lv_obj_set_parent(image_LL_pod,image_L_Pod);
    lv_obj_set_pos(image_LL_pod, 122-image_L_Pod->coords.x1+lv_obj_get_x(screen_main), 321-image_L_Pod->coords.y1+lv_obj_get_y(screen_main));
    qmsd_obj_set_id(image_LL_pod,"image_LL_pod");
}
    
void qmsd_image_RL_pod_create()
{
    image_RL_pod = lv_img_create(screen_main, NULL);
    lv_img_set_src(image_RL_pod, &imgpodetium_g_L_png);
#ifdef BLOCKLY_image_RL_pod_EVENT_HANDLER
    lv_obj_set_event_cb(image_RL_pod, __qmsd_image_RL_pod_cb);
#endif
	lv_obj_set_parent(image_RL_pod,image_R_Pod);
    lv_obj_set_pos(image_RL_pod, 286-image_R_Pod->coords.x1+lv_obj_get_x(screen_main), 321-image_R_Pod->coords.y1+lv_obj_get_y(screen_main));
    qmsd_obj_set_id(image_RL_pod,"image_RL_pod");
}
static void poress_task_cb(lv_task_t * t)
{
	if(temp_index == 0){
		temp_index = 1;
	}else{
		temp_index = 0;
	}
	if(temp_index){
		lv_obj_set_size(image_L_Pod_g,76,50);
		lv_obj_set_pos(image_L_Pod_g, 122, 284);
		lv_obj_set_pos(image_dw_L, 150, 222+50);

		lv_obj_set_size(image_R_Pod_g,76,50);
		lv_obj_set_pos(image_R_Pod_g, 286, 284);
		lv_obj_set_pos(image_dw_R, 315, 222+50);
		lv_label_set_text(label_main_left, pm2_52);
		lv_label_set_text(label_main_rig, harmful_gas2);
	}else{
		lv_obj_set_size(image_L_Pod_g,76,30);
		lv_obj_set_pos(image_L_Pod_g, 122, 304);
		lv_obj_set_pos(image_dw_L, 150, 222+70);

		lv_obj_set_size(image_R_Pod_g,76,20);
		lv_obj_set_pos(image_R_Pod_g, 286, 314);
		lv_obj_set_pos(image_dw_R, 315, 222+80);
		lv_label_set_text(label_main_left, pm2_51);
		lv_label_set_text(label_main_rig, harmful_gas1);
	}
}

lv_task_t * my_task = NULL;
static void create_lv_task(void)
{
	lv_obj_t* image_temp = NULL;
	my_task = lv_task_create(poress_task_cb, 1000, LV_TASK_PRIO_HIGH, image_temp);

}
//

static void screen_main_qmsd_cb(lv_obj_t * obj, lv_event_t event, void *data)
{/*
    char *trans;
    lv_label_set_text(label_main_left,qmsd_lang_get_trans("label_main_left","Label"));
    lv_label_set_text(label_main_rig,qmsd_lang_get_trans("label_main_rig","Label"));
*/
#ifdef BLOCKLY_screen_main_SCREEN_INIT
    __qmsd_screen_main_init();
#endif
}

static void screen_main_del_cb(lv_obj_t* obj,lv_event_t event)
{
    if(event == LV_EVENT_DELETE)
    {
        screen_main=NULL;
        qmsd_screen_remove("screen_main");
    }
}

void screen_main_build(void)
{
    if(screen_main) return;
    screen_main = lv_obj_create(NULL, NULL);
    lv_obj_qmsd_set_cb(screen_main, screen_main_qmsd_cb);

    qmsd_image_bg_blue_create();
    qmsd_image_xiaoka_create();
    qmsd_image_s_pon_1_create();
    qmsd_image_un_pon_1_create();
    qmsd_image_un_pon_2_create();
    qmsd_image_un_pon_3_create();
    qmsd_image_title_create();
    qmsd_button_left_create();
    qmsd_image_left_icn_create();
    qmsd_button_right_create();
    qmsd_image_right_icn_create();
    qmsd_label_main_left_create();
    qmsd_label_main_rig_create();
    qmsd_image_down_create();
    qmsd_image_menu_create();
    qmsd_image_L_Pod_create();
    qmsd_image_R_Pod_create();
    qmsd_image_L_Pod_g_create();
    qmsd_image_R_Pod_g_create();
    qmsd_image_dw_L_create();
    qmsd_image_dw_R_create();
    qmsd_image_L_or_create();
    qmsd_image_R_or_create();
    qmsd_image_LL_pod_create();
    qmsd_image_RL_pod_create();
    anim_set(image_xiaoka,lv_img_set_zoom,180,256,1000,0,LV_ANIM_REPEAT_INFINITE,1000);
    create_lv_task();
    lv_obj_set_event_cb(screen_main,screen_main_del_cb);
    qmsd_screen_register(screen_main,"screen_main");
}

void screen_main_show(void)
{
    if(!screen_main)
    {
        screen_main_build();
    }
    lv_scr_load(screen_main);
}

void screen_main_delete(void)
{
	lv_task_del(my_task);
    if(screen_main)
    {
        lv_obj_del(screen_main);
        screen_main = NULL;
    }
}
