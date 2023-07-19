#include "qmsd_ui_entry.h"
#include "qmsd_lang.h"

lv_anim_t awe_li_bar; lv_anim_path_t awe_li_path;  static void li_l_anim_y_size_cb(void* var, int32_t v)  {          lv_obj_set_y(var, v);     lv_obj_set_height(var, (314-(lv_obj_get_y(var))));      lv_obj_set_y(image_li_barl, (v-15)); }  static void lv_example_anim_li_l(void)  {          
  lv_anim_path_init(&awe_li_path);     lv_anim_path_set_cb(&awe_li_path, lv_anim_path_ease_in_out);           lv_anim_init(&awe_li_bar);      /*lv_anim_set_var(&a, obj);*/          lv_anim_set_var(&awe_li_bar, button_li_l_ra);          lv_anim_set_values(&awe_li_bar, 294, 134); /*设置动画start,end初值*/          lv_anim_set_time(&awe_li_bar, 3000); /*设置动画持续时间*/          lv_anim_set_playback_delay(&awe_li_bar, 100); /* 设置动画延迟回播时间 */          lv_anim_set_playback_time(&awe_li_bar, 3000);  /* 设置动画回播时间 */          lv_anim_set_repeat_delay(&awe_li_bar, 100); /* 设置重复播放延时时间 */          lv_anim_set_repeat_count(&awe_li_bar, LV_ANIM_REPEAT_INFINITE); /* 设置重播次数为重复播放 */          /*lv_anim_set_path_cb(&awe_li_bar, lv_anim_path_ease_in_out);*/          /*lv_anim_set_exec_cb(&awe_li_bar, my_anim_size_cb);*/ /* 设置播放回调函数 */          lv_anim_set_path(&awe_li_bar, &awe_li_path); /* 设置动画path处理方式 */          /*lv_anim_start(&a);*/          lv_anim_set_exec_cb(&awe_li_bar, (lv_anim_exec_xcb_t)li_l_anim_y_size_cb);          /*lv_anim_set_values(&awe_li_bar, -104, 240);*/          lv_anim_set_values(&awe_li_bar, 294, 134);          
  lv_anim_start(&awe_li_bar);  }  static void li_c_anim_y_size_cb(void* var, int32_t v)  {          lv_obj_set_y(var, v);     lv_obj_set_height(var, (314-(lv_obj_get_y(var))));      lv_obj_set_y(image_li_barc, (v-15)); }  static void lv_example_anim_li_c(void)  {          lv_anim_path_init(&awe_li_path);     lv_anim_path_set_cb(&awe_li_path, lv_anim_path_ease_in_out);           lv_anim_init(&awe_li_bar);      /*lv_anim_set_var(&a, obj);*/          lv_anim_set_var(&awe_li_bar, button_li_c_ra);          lv_anim_set_values(&awe_li_bar, 264, 134); /*设置动画start,end初值*/          lv_anim_set_time(&awe_li_bar, 5000); /*设置动画持续时间*/          lv_anim_set_playback_delay(&awe_li_bar, 100); /* 设置动画延迟回播时间 */          lv_anim_set_playback_time(&awe_li_bar, 5000);  /* 设置动画回播时间 */          lv_anim_set_repeat_delay(&awe_li_bar, 100); /* 设置重复播放延时时间 */          lv_anim_set_repeat_count(&awe_li_bar, LV_ANIM_REPEAT_INFINITE); /* 设置重播次数为重复播放 */          /*lv_anim_set_path_cb(&awe_li_bar, lv_anim_path_ease_in_out);*/          /*lv_anim_set_exec_cb(&awe_li_bar, my_anim_size_cb);*/ /* 设置播放回调函数 */          lv_anim_set_path(&awe_li_bar, &awe_li_path); /* 设置动画path处理方式 */          /*lv_anim_start(&a);*/          lv_anim_set_exec_cb(&awe_li_bar, (lv_anim_exec_xcb_t)li_c_anim_y_size_cb);          /*lv_anim_set_values(&awe_li_bar, -104, 240);*/          lv_anim_set_values(&awe_li_bar, 264, 134);          lv_anim_start(&awe_li_bar);  } 
//======te=======
lv_anim_t awe_te_bar; 
lv_anim_path_t awe_te_path;  
static void te_anim_y_size_cb(void* var, int32_t v)  
{          
  lv_obj_set_y(var, v);     
  lv_obj_set_height(var, (337-(lv_obj_get_y(var))));      
  lv_obj_set_y(image_te_bar, (v-15)); 
}  
static void lv_example_anim_te(void)  
{          
  lv_anim_path_init(&awe_te_path);     
  lv_anim_path_set_cb(&awe_te_path, lv_anim_path_ease_in_out);           
  lv_anim_init(&awe_te_bar);      /*lv_anim_set_var(&a, obj);*/          
  lv_anim_set_var(&awe_te_bar, button_te_barra);          
  lv_anim_set_values(&awe_te_bar, 250, 123); /*设置动画start,end初值*/          
  lv_anim_set_time(&awe_te_bar, 3000); /*设置动画持续时间*/          
  lv_anim_set_playback_delay(&awe_te_bar, 100); /* 设置动画延迟回播时间 */          
  lv_anim_set_playback_time(&awe_te_bar, 3000);  /* 设置动画回播时间 */          
  lv_anim_set_repeat_delay(&awe_te_bar, 100); /* 设置重复播放延时时间 */          
  lv_anim_set_repeat_count(&awe_te_bar, LV_ANIM_REPEAT_INFINITE); /* 设置重播次数为重复播放 */          
  /*lv_anim_set_path_cb(&awe_te_bar, lv_anim_path_ease_in_out);*/          
  /*lv_anim_set_exec_cb(&awe_te_bar, my_anim_size_cb);*/ /* 设置播放回调函数 */          
  lv_anim_set_path(&awe_te_bar, &awe_te_path); /* 设置动画path处理方式 */          
  /*lv_anim_start(&a);*/          
  lv_anim_set_exec_cb(&awe_te_bar, (lv_anim_exec_xcb_t)te_anim_y_size_cb);          
  /*lv_anim_set_values(&awe_te_bar, -104, 240);*/          
  lv_anim_set_values(&awe_te_bar, 250, 123);          
  lv_anim_start(&awe_te_bar);  
} 
//======te=======
lv_anim_t awe_ma_bar; lv_anim_path_t awe_ma_path;  static void anim_y_size_cb(void* var, int32_t v)  {          lv_obj_set_y(var, v);     lv_obj_set_height(var, (270-(lv_obj_get_y(var))));  }  static void lv_example_anim_bar(void)  {          lv_anim_path_init(&awe_ma_path);     lv_anim_path_set_cb(&awe_ma_path, lv_anim_path_ease_in_out);           lv_anim_init(&awe_ma_bar);      /*lv_anim_set_var(&a, obj);*/          lv_anim_set_var(&awe_ma_bar, button_ma_barra);          lv_anim_set_values(&awe_ma_bar, 200, 146); /*设置动画start,end初值*/          lv_anim_set_time(&awe_ma_bar, 3000); /*设置动画持续时间*/          lv_anim_set_playback_delay(&awe_ma_bar, 100); /* 设置动画延迟回播时间 */          lv_anim_set_playback_time(&awe_ma_bar, 3000);  /* 设置动画回播时间 */          lv_anim_set_repeat_delay(&awe_ma_bar, 100); /* 设置重复播放延时时间 */          lv_anim_set_repeat_count(&awe_ma_bar, LV_ANIM_REPEAT_INFINITE); /* 设置重播次数为重复播放 */          /*lv_anim_set_path_cb(&awe_ma_bar, lv_anim_path_ease_in_out);*/          /*lv_anim_set_exec_cb(&awe_ma_bar, my_anim_size_cb);*/ /* 设置播放回调函数 */          lv_anim_set_path(&awe_ma_bar, &awe_ma_path); /* 设置动画path处理方式 */          /*lv_anim_start(&a);*/          lv_anim_set_exec_cb(&awe_ma_bar, (lv_anim_exec_xcb_t)anim_y_size_cb);          /*lv_anim_set_values(&awe_ma_bar, -104, 240);*/          lv_anim_set_values(&awe_ma_bar, 200, 146);          lv_anim_start(&awe_ma_bar);  } 
lv_anim_t a; lv_anim_path_t path;  static void my_anim_y_cb(void* var, int32_t v)  {          lv_obj_set_y(var, v);  }  static void lv_example_anim_world(void)  {          lv_anim_path_init(&path);     lv_anim_path_set_cb(&path, lv_anim_path_ease_in_out);           lv_anim_init(&a);      /*lv_anim_set_var(&a, obj);*/          lv_anim_set_var(&a, image_ma_smile);          lv_anim_set_values(&a, 426, 416); /*设置动画start,end初值*/          lv_anim_set_time(&a, 1000); /*设置动画持续时间*/          lv_anim_set_playback_delay(&a, 100); /* 设置动画延迟回播时间 */          lv_anim_set_playback_time(&a, 1000);  /* 设置动画回播时间 */          lv_anim_set_repeat_delay(&a, 100); /* 设置重复播放延时时间 */          lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE); /* ========设置重播次数为一次======== */          /*lv_anim_set_path_cb(&a, lv_anim_path_ease_in_out);*/          /*lv_anim_set_exec_cb(&a, my_anim_size_cb);*/ /* 设置播放回调函数 */          lv_anim_set_path(&a, &path); /* 设置动画path处理方式 */          /*lv_anim_start(&a);*/          lv_anim_set_exec_cb(&a, (lv_anim_exec_xcb_t)my_anim_y_cb);          /*lv_anim_set_values(&a, -104, 240);*/          lv_anim_set_values(&a, 426, 416);          lv_anim_start(&a);  } 

int set_windy = 26; 
// set_windy = 26;
static int img_l = 3;static int img_r = 2;static int img_m = 1; 
static bool sign = false; 
static bool screen_main_sign = true; 
static bool te_bar_sign = false;static bool screen_temperatrue = true; 
static bool li_bar_sign = false;static bool screen_light_sign = true; 
static int mu_l_sign = 3; static int mu_r_sign = 1; 
static int mu_min_sign = 1; 
lv_anim_t awe_mu_bar; lv_anim_path_t awe_mu_path;  static void anim_min_img1_x_cb(void* var, int32_t v)  {          lv_obj_set_x(var, v); }  static void anim_min_img1_y_cb(void* var, int32_t v)  {          lv_obj_set_y(var, v); }  

static void anim_min_img_m(void)  {
  lv_label_set_text(label_mu_singer, "Havana");
  lv_label_set_text(label_mu_song, "Cabello feat Young");
  lv_label_set_align(label_mu_singer, LV_LABEL_ALIGN_CENTER);
  lv_label_set_align(label_mu_song, LV_LABEL_ALIGN_CENTER);

  lv_obj_move_foreground(image_mu_s_m);     
  lv_obj_move_background(image_mu_s_l);     
  lv_obj_move_background(image_mu_s_r);     
  lv_obj_set_style_local_image_opa(image_mu_s_m,LV_IMG_PART_MAIN,LV_STATE_DEFAULT,255);
  lv_obj_set_style_local_image_opa(image_mu_s_r,LV_IMG_PART_MAIN,LV_STATE_DEFAULT,55);
  lv_obj_set_style_local_image_opa(image_mu_s_l,LV_IMG_PART_MAIN,LV_STATE_DEFAULT,55);      
  lv_anim_path_init(&awe_mu_path);     
  lv_anim_path_set_cb(&awe_mu_path, lv_anim_path_ease_in_out);           
  lv_anim_init(&awe_mu_bar);      /*lv_anim_set_var(&a, obj);*/                 
  lv_anim_set_time(&awe_mu_bar, 500); /*设置动画持续时间*/             
  lv_anim_set_repeat_count(&awe_mu_bar, 1); /* 设置重播次数为播放1次 */           
  lv_anim_set_path(&awe_mu_bar, &awe_mu_path); /* 设置动画path处理方式 */      
  if((lv_obj_get_x(image_mu_s_m)) == 47) {         /*=====image min=====*/         
  lv_anim_set_var(&awe_mu_bar, image_mu_s_m);          
  lv_anim_set_values(&awe_mu_bar, 47, 156); /*设置动画start,end初值*/            
  lv_anim_set_exec_cb(&awe_mu_bar, (lv_anim_exec_xcb_t)anim_min_img1_x_cb);         
  lv_anim_start(&awe_mu_bar);          
  lv_anim_set_var(&awe_mu_bar, image_mu_s_m);          
  lv_anim_set_values(&awe_mu_bar, 82, 112); /*设置动画start,end初值*/            
  lv_anim_set_exec_cb(&awe_mu_bar, (lv_anim_exec_xcb_t)anim_min_img1_y_cb);         
  lv_anim_start(&awe_mu_bar);         /*=====image right=====*/         
  lv_anim_set_var(&awe_mu_bar, image_mu_s_r);          
  lv_anim_set_values(&awe_mu_bar, 156, 258); /*设置动画start,end初值*/            
  lv_anim_set_exec_cb(&awe_mu_bar, (lv_anim_exec_xcb_t)anim_min_img1_x_cb);         
  lv_anim_start(&awe_mu_bar);         
  lv_anim_set_var(&awe_mu_bar, image_mu_s_r);          
  lv_anim_set_values(&awe_mu_bar, 112, 82); /*设置动画start,end初值*/           
  lv_anim_set_exec_cb(&awe_mu_bar, (lv_anim_exec_xcb_t)anim_min_img1_y_cb);         
  lv_anim_start(&awe_mu_bar);         /*=====image left=====*/         
  lv_anim_set_var(&awe_mu_bar, image_mu_s_l);          
  lv_anim_set_values(&awe_mu_bar, 258, 47); /*设置动画start,end初值*/            
  lv_anim_set_exec_cb(&awe_mu_bar, (lv_anim_exec_xcb_t)anim_min_img1_x_cb);         
  lv_anim_start(&awe_mu_bar);         
  lv_anim_set_var(&awe_mu_bar, image_mu_s_l);          
  lv_anim_set_values(&awe_mu_bar, 82, 82); /*设置动画start,end初值*/            
  lv_anim_set_exec_cb(&awe_mu_bar, (lv_anim_exec_xcb_t)anim_min_img1_y_cb);         
  lv_anim_start(&awe_mu_bar);     
  } else if((lv_obj_get_x(image_mu_s_m)) == 258) {         /*=====image min=====*/         
  lv_anim_set_var(&awe_mu_bar, image_mu_s_m);          
  lv_anim_set_values(&awe_mu_bar, 258, 156); /*设置动画start,end初值*/            
  lv_anim_set_exec_cb(&awe_mu_bar, (lv_anim_exec_xcb_t)anim_min_img1_x_cb);         
  lv_anim_start(&awe_mu_bar);          
  lv_anim_set_var(&awe_mu_bar, image_mu_s_m);          
  lv_anim_set_values(&awe_mu_bar, 82, 112); /*设置动画start,end初值*/            
  lv_anim_set_exec_cb(&awe_mu_bar, (lv_anim_exec_xcb_t)anim_min_img1_y_cb);         
  lv_anim_start(&awe_mu_bar);         /*=====image right=====*/         
  lv_anim_set_var(&awe_mu_bar, image_mu_s_r);          
  lv_anim_set_values(&awe_mu_bar, 47, 258); /*设置动画start,end初值*/            
  lv_anim_set_exec_cb(&awe_mu_bar, (lv_anim_exec_xcb_t)anim_min_img1_x_cb);         
  lv_anim_start(&awe_mu_bar);         
  lv_anim_set_var(&awe_mu_bar, image_mu_s_r);          
  lv_anim_set_values(&awe_mu_bar, 82, 82); /*设置动画start,end初值*/            
  lv_anim_set_exec_cb(&awe_mu_bar, (lv_anim_exec_xcb_t)anim_min_img1_y_cb);         
  lv_anim_start(&awe_mu_bar);         /*=====image left=====*/         
  lv_anim_set_var(&awe_mu_bar, image_mu_s_l);          
  lv_anim_set_values(&awe_mu_bar, 156, 47); /*设置动画start,end初值*/            
  lv_anim_set_exec_cb(&awe_mu_bar, (lv_anim_exec_xcb_t)anim_min_img1_x_cb);         
  lv_anim_start(&awe_mu_bar);         
  lv_anim_set_var(&awe_mu_bar, image_mu_s_l);          
  lv_anim_set_values(&awe_mu_bar, 112, 82); /*设置动画start,end初值*/            
  lv_anim_set_exec_cb(&awe_mu_bar, (lv_anim_exec_xcb_t)anim_min_img1_y_cb);         
  lv_anim_start(&awe_mu_bar);     
  }  
}  

static void anim_min_img_r(void)  { 
  lv_label_set_text(label_mu_singer, "Rose");
  lv_label_set_text(label_mu_song, "Stay Tonight");
  lv_label_set_align(label_mu_singer, LV_LABEL_ALIGN_CENTER);
  lv_label_set_align(label_mu_song, LV_LABEL_ALIGN_CENTER);

  lv_obj_move_foreground(image_mu_s_r);     
  lv_obj_move_background(image_mu_s_l);     
  lv_obj_move_background(image_mu_s_m);     
  lv_obj_set_style_local_image_opa(image_mu_s_r,LV_IMG_PART_MAIN,LV_STATE_DEFAULT,255);  
  lv_obj_set_style_local_image_opa(image_mu_s_m,LV_IMG_PART_MAIN,LV_STATE_DEFAULT,55);
  lv_obj_set_style_local_image_opa(image_mu_s_l,LV_IMG_PART_MAIN,LV_STATE_DEFAULT,55);      
  lv_anim_path_init(&awe_mu_path);     lv_anim_path_set_cb(&awe_mu_path, lv_anim_path_ease_in_out);           lv_anim_init(&awe_mu_bar);      /*lv_anim_set_var(&a, obj);*/                 lv_anim_set_time(&awe_mu_bar, 500); /*设置动画持续时间*/             lv_anim_set_repeat_count(&awe_mu_bar, 1); /* 设置重播次数为播放1次 */           lv_anim_set_path(&awe_mu_bar, &awe_mu_path); /* 设置动画path处理方式 */        if((lv_obj_get_x(image_mu_s_r)) == 47) {         /*=====image min=====*/         lv_anim_set_var(&awe_mu_bar, image_mu_s_m);          lv_anim_set_values(&awe_mu_bar, 258, 47); /*设置动画start,end初值*/            lv_anim_set_exec_cb(&awe_mu_bar, (lv_anim_exec_xcb_t)anim_min_img1_x_cb);         lv_anim_start(&awe_mu_bar);          lv_anim_set_var(&awe_mu_bar, image_mu_s_m);          lv_anim_set_values(&awe_mu_bar, 82, 82); /*设置动画start,end初值*/            lv_anim_set_exec_cb(&awe_mu_bar, (lv_anim_exec_xcb_t)anim_min_img1_y_cb);         lv_anim_start(&awe_mu_bar);         /*=====image right=====*/         lv_anim_set_var(&awe_mu_bar, image_mu_s_r);          lv_anim_set_values(&awe_mu_bar, 47, 156); /*设置动画start,end初值*/            lv_anim_set_exec_cb(&awe_mu_bar, (lv_anim_exec_xcb_t)anim_min_img1_x_cb);         lv_anim_start(&awe_mu_bar);         lv_anim_set_var(&awe_mu_bar, image_mu_s_r);          lv_anim_set_values(&awe_mu_bar, 82, 112); /*设置动画start,end初值*/            lv_anim_set_exec_cb(&awe_mu_bar, (lv_anim_exec_xcb_t)anim_min_img1_y_cb);         lv_anim_start(&awe_mu_bar);         /*=====image left=====*/         lv_anim_set_var(&awe_mu_bar, image_mu_s_l);          lv_anim_set_values(&awe_mu_bar, 156, 258); /*设置动画start,end初值*/            lv_anim_set_exec_cb(&awe_mu_bar, (lv_anim_exec_xcb_t)anim_min_img1_x_cb);         lv_anim_start(&awe_mu_bar);         lv_anim_set_var(&awe_mu_bar, image_mu_s_l);          lv_anim_set_values(&awe_mu_bar, 112, 82); /*设置动画start,end初值*/            lv_anim_set_exec_cb(&awe_mu_bar, (lv_anim_exec_xcb_t)anim_min_img1_y_cb);         lv_anim_start(&awe_mu_bar);     } else if((lv_obj_get_x(image_mu_s_r)) == 258) {         /*=====image min=====*/         lv_anim_set_var(&awe_mu_bar, image_mu_s_m);          lv_anim_set_values(&awe_mu_bar, 156, 47); /*设置动画start,end初值*/            lv_anim_set_exec_cb(&awe_mu_bar, (lv_anim_exec_xcb_t)anim_min_img1_x_cb);         lv_anim_start(&awe_mu_bar);          lv_anim_set_var(&awe_mu_bar, image_mu_s_m);          lv_anim_set_values(&awe_mu_bar, 112, 82); /*设置动画start,end初值*/            lv_anim_set_exec_cb(&awe_mu_bar, (lv_anim_exec_xcb_t)anim_min_img1_y_cb);         lv_anim_start(&awe_mu_bar);         /*=====image right=====*/         lv_anim_set_var(&awe_mu_bar, image_mu_s_r);          lv_anim_set_values(&awe_mu_bar, 258, 156); /*设置动画start,end初值*/            lv_anim_set_exec_cb(&awe_mu_bar, (lv_anim_exec_xcb_t)anim_min_img1_x_cb);         lv_anim_start(&awe_mu_bar);         lv_anim_set_var(&awe_mu_bar, image_mu_s_r);          lv_anim_set_values(&awe_mu_bar, 82, 112); /*设置动画start,end初值*/            lv_anim_set_exec_cb(&awe_mu_bar, (lv_anim_exec_xcb_t)anim_min_img1_y_cb);         lv_anim_start(&awe_mu_bar);         /*=====image left=====*/         lv_anim_set_var(&awe_mu_bar, image_mu_s_l);          lv_anim_set_values(&awe_mu_bar, 47, 258); /*设置动画start,end初值*/            lv_anim_set_exec_cb(&awe_mu_bar, (lv_anim_exec_xcb_t)anim_min_img1_x_cb);         lv_anim_start(&awe_mu_bar);         lv_anim_set_var(&awe_mu_bar, image_mu_s_l);          lv_anim_set_values(&awe_mu_bar, 82, 82); /*设置动画start,end初值*/            lv_anim_set_exec_cb(&awe_mu_bar, (lv_anim_exec_xcb_t)anim_min_img1_y_cb);         lv_anim_start(&awe_mu_bar);     } }  

static void anim_min_img_l(void)  {  
  lv_label_set_text(label_mu_singer, "张震岳");
  lv_label_set_text(label_mu_song, "无路用的人");
  lv_label_set_align(label_mu_singer, LV_LABEL_ALIGN_CENTER);
  lv_label_set_align(label_mu_song, LV_LABEL_ALIGN_CENTER);

  lv_obj_move_foreground(image_mu_s_l);     
  lv_obj_move_background(image_mu_s_r);     
  lv_obj_move_background(image_mu_s_m);     
  lv_obj_set_style_local_image_opa(image_mu_s_l,LV_IMG_PART_MAIN,LV_STATE_DEFAULT,255); 
  lv_obj_set_style_local_image_opa(image_mu_s_m,LV_IMG_PART_MAIN,LV_STATE_DEFAULT,55);
  lv_obj_set_style_local_image_opa(image_mu_s_r,LV_IMG_PART_MAIN,LV_STATE_DEFAULT,55);     
  lv_anim_path_init(&awe_mu_path);     
  lv_anim_path_set_cb(&awe_mu_path, lv_anim_path_ease_in_out);           lv_anim_init(&awe_mu_bar);      /*lv_anim_set_var(&a, obj);*/                 lv_anim_set_time(&awe_mu_bar, 500); /*设置动画持续时间*/             lv_anim_set_repeat_count(&awe_mu_bar, 1); /* 设置重播次数为播放1次 */           lv_anim_set_path(&awe_mu_bar, &awe_mu_path); /* 设置动画path处理方式 */       if((lv_obj_get_x(image_mu_s_l)) == 47) {         /*=====image min=====*/         lv_anim_set_var(&awe_mu_bar, image_mu_s_m);          lv_anim_set_values(&awe_mu_bar, 156, 258); /*设置动画start,end初值*/            lv_anim_set_exec_cb(&awe_mu_bar, (lv_anim_exec_xcb_t)anim_min_img1_x_cb);         lv_anim_start(&awe_mu_bar);          lv_anim_set_var(&awe_mu_bar, image_mu_s_m);          lv_anim_set_values(&awe_mu_bar, 112, 82); /*设置动画start,end初值*/            lv_anim_set_exec_cb(&awe_mu_bar, (lv_anim_exec_xcb_t)anim_min_img1_y_cb);         lv_anim_start(&awe_mu_bar);         /*=====image right=====*/         lv_anim_set_var(&awe_mu_bar, image_mu_s_r);          lv_anim_set_values(&awe_mu_bar, 258, 47); /*设置动画start,end初值*/            lv_anim_set_exec_cb(&awe_mu_bar, (lv_anim_exec_xcb_t)anim_min_img1_x_cb);         lv_anim_start(&awe_mu_bar);         lv_anim_set_var(&awe_mu_bar, image_mu_s_r);          lv_anim_set_values(&awe_mu_bar, 82, 82); /*设置动画start,end初值*/            lv_anim_set_exec_cb(&awe_mu_bar, (lv_anim_exec_xcb_t)anim_min_img1_y_cb);         lv_anim_start(&awe_mu_bar);         /*=====image left=====*/         lv_anim_set_var(&awe_mu_bar, image_mu_s_l);          lv_anim_set_values(&awe_mu_bar, 47, 156); /*设置动画start,end初值*/            lv_anim_set_exec_cb(&awe_mu_bar, (lv_anim_exec_xcb_t)anim_min_img1_x_cb);         lv_anim_start(&awe_mu_bar);         lv_anim_set_var(&awe_mu_bar, image_mu_s_l);          lv_anim_set_values(&awe_mu_bar, 82, 112); /*设置动画start,end初值*/            lv_anim_set_exec_cb(&awe_mu_bar, (lv_anim_exec_xcb_t)anim_min_img1_y_cb);         lv_anim_start(&awe_mu_bar);     } else if((lv_obj_get_x(image_mu_s_l)) == 258) {         /*=====image min=====*/         lv_anim_set_var(&awe_mu_bar, image_mu_s_m);          lv_anim_set_values(&awe_mu_bar, 47, 258); /*设置动画start,end初值*/            lv_anim_set_exec_cb(&awe_mu_bar, (lv_anim_exec_xcb_t)anim_min_img1_x_cb);         lv_anim_start(&awe_mu_bar);          lv_anim_set_var(&awe_mu_bar, image_mu_s_m);          lv_anim_set_values(&awe_mu_bar, 82, 82); /*设置动画start,end初值*/            lv_anim_set_exec_cb(&awe_mu_bar, (lv_anim_exec_xcb_t)anim_min_img1_y_cb);         lv_anim_start(&awe_mu_bar);         /*=====image right=====*/         lv_anim_set_var(&awe_mu_bar, image_mu_s_r);          lv_anim_set_values(&awe_mu_bar, 156, 47); /*设置动画start,end初值*/            lv_anim_set_exec_cb(&awe_mu_bar, (lv_anim_exec_xcb_t)anim_min_img1_x_cb);         lv_anim_start(&awe_mu_bar);         lv_anim_set_var(&awe_mu_bar, image_mu_s_r);          lv_anim_set_values(&awe_mu_bar, 112, 82); /*设置动画start,end初值*/            lv_anim_set_exec_cb(&awe_mu_bar, (lv_anim_exec_xcb_t)anim_min_img1_y_cb);         lv_anim_start(&awe_mu_bar);         /*=====image left=====*/         lv_anim_set_var(&awe_mu_bar, image_mu_s_l);          lv_anim_set_values(&awe_mu_bar, 258, 156); /*设置动画start,end初值*/            lv_anim_set_exec_cb(&awe_mu_bar, (lv_anim_exec_xcb_t)anim_min_img1_x_cb);         lv_anim_start(&awe_mu_bar);         lv_anim_set_var(&awe_mu_bar, image_mu_s_l);          lv_anim_set_values(&awe_mu_bar, 82, 112); /*设置动画start,end初值*/            lv_anim_set_exec_cb(&awe_mu_bar, (lv_anim_exec_xcb_t)anim_min_img1_y_cb);         lv_anim_start(&awe_mu_bar);     } } 

static lv_obj_t* label_top_1; 
static lv_obj_t* label_top_2; 
static lv_obj_t* label_top_3; 
static lv_obj_t* label_top_4; 
static lv_obj_t* label_top_5; 
static lv_obj_t* label_top_6; 
static lv_obj_t* label_top_7; 
static lv_obj_t* label_top_8; 
static lv_obj_t* label_top_9; 
static lv_obj_t* label_top_10; 
static lv_obj_t* label_top_11; 
static lv_obj_t* label_top_12; 
static lv_obj_t* label_top_13; 
static lv_obj_t* label_top_14; 
static lv_obj_t* label_top_15;
static lv_obj_t* image_0;  
static lv_obj_t* image_1; 
static lv_obj_t* image_2; 
static lv_obj_t* image_3; 
static lv_obj_t* image_4; 
static lv_obj_t* image_5; 
static lv_obj_t* image_6; 
static lv_obj_t* image_7;   
static lv_obj_t* button_list_play_one; 
static lv_obj_t* list_play_list; 
static lv_obj_t* list_play_list_btn[12]; 
static lv_style_t* style; 
static lv_style_t* style_label;  
LV_FONT_DECLARE(ali_font_13); 
LV_FONT_DECLARE(ali_font_22); 
/*LV_IMG_DECLARE(imghcd_png); 
LV_IMG_DECLARE(imgll_png); 
LV_IMG_DECLARE(imgpl_png); 
LV_IMG_DECLARE(imgtxdx_png);*/  
void* label_top_1_b; 
void* label_top_2_b; 
void* label_top_3_b; 
void* label_top_4_b; 
void* label_top_5_b; 
void* label_top_6_b; 
void* label_top_7_b; 
void* label_top_8_b; 
void* label_top_9_b; 
void* label_top_10_b; 
void* label_top_11_b; 
void* label_top_12_b; 
void* label_top_13_b; 
void* label_top_14_b; 
void* label_top_15_b; 
void* image_0_b;  
void* image_1_b; 
void* image_2_b; 
void* image_3_b; 
void* image_4_b;
void* awe_top_add(lv_obj_t* obj, const char* text, lv_obj_t* obj_parent); 
void* awe_right_add(lv_obj_t* obj, const char* text, lv_obj_t* obj_parent); 
void* awe_bot_add(lv_obj_t* obj, const char* text, lv_obj_t* obj_parent);
void* awe_image_create(lv_obj_t* obj_image, lv_obj_t* obj_parent, const void * src_img); 
void list_btn_cb(lv_obj_t* obj, lv_event_t* event);  
/*!======音乐列表======*/
void qmsd_list_play_list_create() 
{     
  lv_style_set_text_opa(&style_label,LV_STATE_DEFAULT,LV_OPA_60);     /* list */     
  list_play_list = lv_list_create(screen_main, NULL);     
  lv_obj_set_size(list_play_list, 412, 230); 	
  lv_obj_set_parent(list_play_list,image_play_bo);     
  lv_obj_set_pos(list_play_list, 25-image_play_bo->coords.x1, 220-image_play_bo->coords.y1);      
  lv_obj_set_style_local_text_color(list_play_list,LV_LIST_PART_BG, LV_STATE_DEFAULT, LV_COLOR_MAKE(0xff, 0xff, 0xff));     
  lv_obj_set_style_local_bg_color(list_play_list,LV_LIST_PART_BG, LV_STATE_DEFAULT, LV_COLOR_MAKE(0xff, 0xff, 0xff));     
  lv_obj_set_style_local_border_width(list_play_list,LV_LIST_PART_BG, LV_STATE_DEFAULT, 0);     
  lv_obj_set_style_local_border_color(list_play_list,LV_LIST_PART_BG, LV_STATE_DEFAULT, LV_COLOR_MAKE(0xd6, 0xdd, 0xe3));     
  lv_obj_set_style_local_bg_color(list_play_list,LV_LIST_PART_BG, LV_STATE_PRESSED, LV_COLOR_MAKE(0xee, 0xee, 0xee));     
  lv_obj_set_style_local_bg_opa(list_play_list,LV_LIST_PART_BG, LV_STATE_DEFAULT, 0);     /* list btn */ 
  lv_obj_set_style_local_border_width(list_play_list,LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 0);/* 正常边沿 */
  lv_obj_set_style_local_border_width(list_play_list,LV_BTN_PART_MAIN, LV_STATE_PRESSED, 0);/* 按下边沿 */
  lv_obj_set_style_local_border_width(list_play_list,LV_BTN_PART_MAIN, LV_STATE_FOCUSED, 0);/* 聚焦边沿 */

  list_play_list_btn[0]=lv_list_add_btn(list_play_list, NULL, NULL);     
  lv_obj_set_style_local_bg_opa(list_play_list_btn[0],LV_LIST_PART_BG, LV_STATE_DEFAULT, 0);  
  lv_obj_set_style_local_border_opa(list_play_list_btn[0],LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 0);
  lv_obj_set_style_local_border_opa(list_play_list_btn[0],LV_BTN_PART_MAIN, LV_STATE_PRESSED, 0);
  lv_obj_set_style_local_border_opa(list_play_list_btn[0],LV_BTN_PART_MAIN, LV_STATE_FOCUSED, 0);  
  lv_obj_set_size(list_play_list_btn[0], 412, 60);     
  lv_btn_set_layout(list_play_list_btn[0], LV_LAYOUT_OFF);     
  lv_btn_set_fit2(list_play_list_btn[0], LV_FIT_NONE, LV_FIT_NONE); /*add label to button*/     
  label_top_1_b = awe_top_add(label_top_1, "两只蝴蝶", list_play_list_btn[0]);     
  label_top_2_b = awe_bot_add(label_top_2, "庞龙", list_play_list_btn[0]);     
  label_top_3_b = awe_right_add(label_top_3, "2:30", list_play_list_btn[0]);     /* list btn */   

  list_play_list_btn[1]=lv_list_add_btn(list_play_list, NULL, NULL);     
  lv_obj_set_style_local_bg_opa(list_play_list_btn[1],LV_LIST_PART_BG, LV_STATE_DEFAULT, 0); 
  lv_obj_set_style_local_border_opa(list_play_list_btn[1],LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 0);
  lv_obj_set_style_local_border_opa(list_play_list_btn[1],LV_BTN_PART_MAIN, LV_STATE_PRESSED, 0);
  lv_obj_set_style_local_border_opa(list_play_list_btn[1],LV_BTN_PART_MAIN, LV_STATE_FOCUSED, 0);    
  lv_obj_set_size(list_play_list_btn[1], 412, 60);     
  lv_btn_set_layout(list_play_list_btn[1], LV_LAYOUT_OFF);     
  lv_btn_set_fit2(list_play_list_btn[1], LV_FIT_NONE, LV_FIT_NONE); /*add label to button*/     
  label_top_4_b = awe_top_add(label_top_4, "宝贝对不起", list_play_list_btn[1]);     
  label_top_5_b = awe_bot_add(label_top_5, "梁龙", list_play_list_btn[1]);     
  label_top_6_b = awe_right_add(label_top_6, "2:25", list_play_list_btn[1]);     /* list btn */     

  list_play_list_btn[2]=lv_list_add_btn(list_play_list, NULL, NULL);     
  lv_obj_set_style_local_bg_opa(list_play_list_btn[2],LV_LIST_PART_BG, LV_STATE_DEFAULT, 0);  
  lv_obj_set_style_local_border_opa(list_play_list_btn[2],LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 0);
  lv_obj_set_style_local_border_opa(list_play_list_btn[2],LV_BTN_PART_MAIN, LV_STATE_PRESSED, 0);
  lv_obj_set_style_local_border_opa(list_play_list_btn[2],LV_BTN_PART_MAIN, LV_STATE_FOCUSED, 0);   
  lv_obj_set_size(list_play_list_btn[2], 412, 60);     
  lv_btn_set_layout(list_play_list_btn[2], LV_LAYOUT_OFF);     
  lv_btn_set_fit2(list_play_list_btn[2], LV_FIT_NONE, LV_FIT_NONE); /*add label to button*/     
  label_top_7_b = awe_top_add(label_top_7, "初恋", list_play_list_btn[2]);     
  label_top_8_b = awe_bot_add(label_top_8, "回春丹乐队", list_play_list_btn[2]);     
  label_top_9_b = awe_right_add(label_top_9, "3:26", list_play_list_btn[2]);     /* list btn */    

  list_play_list_btn[3]=lv_list_add_btn(list_play_list, NULL, NULL);     
  lv_obj_set_style_local_bg_opa(list_play_list_btn[3],LV_LIST_PART_BG, LV_STATE_DEFAULT, 0); 
  lv_obj_set_style_local_border_opa(list_play_list_btn[3],LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 0);
  lv_obj_set_style_local_border_opa(list_play_list_btn[3],LV_BTN_PART_MAIN, LV_STATE_PRESSED, 0);
  lv_obj_set_style_local_border_opa(list_play_list_btn[3],LV_BTN_PART_MAIN, LV_STATE_FOCUSED, 0);    
  lv_obj_set_size(list_play_list_btn[3], 412, 60);     
  lv_btn_set_layout(list_play_list_btn[3], LV_LAYOUT_OFF);     
  lv_btn_set_fit2(list_play_list_btn[3], LV_FIT_NONE, LV_FIT_NONE); /*add label to button*/     
  label_top_10_b = awe_top_add(label_top_10, "梦特别娇", list_play_list_btn[3]);     
  label_top_11_b = awe_bot_add(label_top_11, "回春丹乐队", list_play_list_btn[3]);     
  label_top_12_b = awe_right_add(label_top_12, "4:21", list_play_list_btn[3]);     /* list btn */  

  list_play_list_btn[4]=lv_list_add_btn(list_play_list, NULL, NULL);     
  lv_obj_set_style_local_bg_opa(list_play_list_btn[4],LV_LIST_PART_BG, LV_STATE_DEFAULT, 0);   
  lv_obj_set_style_local_border_opa(list_play_list_btn[4],LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 0);
  lv_obj_set_style_local_border_opa(list_play_list_btn[4],LV_BTN_PART_MAIN, LV_STATE_PRESSED, 0);
  lv_obj_set_style_local_border_opa(list_play_list_btn[4],LV_BTN_PART_MAIN, LV_STATE_FOCUSED, 0);  
  lv_obj_set_size(list_play_list_btn[4], 412, 60);     
  lv_btn_set_layout(list_play_list_btn[4], LV_LAYOUT_OFF);     
  lv_btn_set_fit2(list_play_list_btn[4], LV_FIT_NONE, LV_FIT_NONE); /*add label to button*/     
  label_top_13_b = awe_top_add(label_top_13, "铁血丹心", list_play_list_btn[4]);     
  label_top_14_b = awe_bot_add(label_top_14, "罗文 甄妮", list_play_list_btn[4]);     
  label_top_15_b = awe_right_add(label_top_15, "2:54", list_play_list_btn[4]);       
     
  lv_obj_set_event_cb(list_play_list_btn[4], list_btn_cb);     
  lv_obj_set_event_cb(list_play_list_btn[3], list_btn_cb);     
  lv_obj_set_event_cb(list_play_list_btn[2], list_btn_cb);     
  lv_obj_set_event_cb(list_play_list_btn[1], list_btn_cb);     
  lv_obj_set_event_cb(list_play_list_btn[0], list_btn_cb); 

  image_0_b = awe_image_create(image_0, list_play_list_btn[0], &imgpl_png);/* 70*70 */     
  image_1_b = awe_image_create(image_1, list_play_list_btn[1], &imgll_png);     
  image_2_b = awe_image_create(image_2, list_play_list_btn[2], &imghcd_png);     
  image_3_b = awe_image_create(image_3, list_play_list_btn[3], &imghcd_png);     
  image_4_b = awe_image_create(image_4, list_play_list_btn[4], &imgtxdx_png); 

  lv_obj_set_style_local_border_opa(list_play_list_btn[0],LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 0);
  lv_obj_set_style_local_border_opa(list_play_list_btn[1],LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 0);
  lv_obj_set_style_local_border_opa(list_play_list_btn[2],LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 0);
  lv_obj_set_style_local_border_opa(list_play_list_btn[3],LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 0);
  lv_obj_set_style_local_border_opa(list_play_list_btn[4],LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 0);

  lv_obj_set_style_local_border_opa(list_play_list_btn[0],LV_BTN_PART_MAIN, LV_STATE_PRESSED, 0);
  lv_obj_set_style_local_border_opa(list_play_list_btn[1],LV_BTN_PART_MAIN, LV_STATE_PRESSED, 0);
  lv_obj_set_style_local_border_opa(list_play_list_btn[2],LV_BTN_PART_MAIN, LV_STATE_PRESSED, 0);
  lv_obj_set_style_local_border_opa(list_play_list_btn[3],LV_BTN_PART_MAIN, LV_STATE_PRESSED, 0);
  lv_obj_set_style_local_border_opa(list_play_list_btn[4],LV_BTN_PART_MAIN, LV_STATE_PRESSED, 0);

  lv_obj_set_style_local_border_opa(list_play_list_btn[0],LV_BTN_PART_MAIN, LV_STATE_FOCUSED, 0);
  lv_obj_set_style_local_border_opa(list_play_list_btn[1],LV_BTN_PART_MAIN, LV_STATE_FOCUSED, 0);
  lv_obj_set_style_local_border_opa(list_play_list_btn[2],LV_BTN_PART_MAIN, LV_STATE_FOCUSED, 0);
  lv_obj_set_style_local_border_opa(list_play_list_btn[3],LV_BTN_PART_MAIN, LV_STATE_FOCUSED, 0);
  lv_obj_set_style_local_border_opa(list_play_list_btn[4],LV_BTN_PART_MAIN, LV_STATE_FOCUSED, 0);

  lv_obj_set_style_local_border_width(list_play_list_btn[0],LV_BTN_PART_MAIN, LV_STATE_PRESSED, 0);/* 按下边沿 */
  lv_obj_set_style_local_border_width(list_play_list_btn[1],LV_BTN_PART_MAIN, LV_STATE_PRESSED, 0);/* 按下边沿 */
  lv_obj_set_style_local_border_width(list_play_list_btn[2],LV_BTN_PART_MAIN, LV_STATE_PRESSED, 0);/* 按下边沿 */
  lv_obj_set_style_local_border_width(list_play_list_btn[3],LV_BTN_PART_MAIN, LV_STATE_PRESSED, 0);/* 按下边沿 */
  lv_obj_set_style_local_border_width(list_play_list_btn[4],LV_BTN_PART_MAIN, LV_STATE_PRESSED, 0);/* 按下边沿 */

  lv_obj_set_style_local_border_width(list_play_list_btn[0],LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 0);/* 正常边沿 */
  lv_obj_set_style_local_border_width(list_play_list_btn[1],LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 0);/* 正常边沿 */
  lv_obj_set_style_local_border_width(list_play_list_btn[2],LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 0);/* 正常边沿 */
  lv_obj_set_style_local_border_width(list_play_list_btn[3],LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 0);/* 正常边沿 */
  lv_obj_set_style_local_border_width(list_play_list_btn[4],LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 0);/* 正常边沿 */

  lv_obj_set_style_local_border_width(list_play_list_btn[0],LV_BTN_PART_MAIN, LV_STATE_FOCUSED, 0);/* 聚焦边沿 */
  lv_obj_set_style_local_border_width(list_play_list_btn[1],LV_BTN_PART_MAIN, LV_STATE_FOCUSED, 0);/* 聚焦边沿 */
  lv_obj_set_style_local_border_width(list_play_list_btn[2],LV_BTN_PART_MAIN, LV_STATE_FOCUSED, 0);/* 聚焦边沿 */
  lv_obj_set_style_local_border_width(list_play_list_btn[3],LV_BTN_PART_MAIN, LV_STATE_FOCUSED, 0);/* 聚焦边沿 */
  lv_obj_set_style_local_border_width(list_play_list_btn[4],LV_BTN_PART_MAIN, LV_STATE_FOCUSED, 0);/* 聚焦边沿 */

  lv_obj_set_style_local_border_width(list_play_list,LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 0);/* 正常边沿 */
  lv_obj_set_style_local_border_width(list_play_list,LV_BTN_PART_MAIN, LV_STATE_PRESSED, 0);/* 按下边沿 */
  lv_obj_set_style_local_border_width(list_play_list,LV_BTN_PART_MAIN, LV_STATE_FOCUSED, 0);/* 聚焦边沿 */

  // lv_obj_set_style_local_border_width((lv_obj_t*)(&(list_play_list->child_ll.head)),LV_BTN_PART_MAIN, LV_STATE_PRESSED, 0);/* 按下边沿 */

}  
void* awe_image_create(lv_obj_t* obj_image, lv_obj_t* obj_parent, const void * src_img) 
{     
  obj_image = lv_img_create(obj_parent, NULL);     
  /*lv_obj_set_parent(obj_image, obj_parent);*/     
  lv_img_set_src(obj_image, src_img);     
  lv_obj_set_pos(obj_image, 25, 10);     
  lv_obj_set_hidden(obj_image, false); 

  return obj_parent->child_ll.head;
}  
void* awe_top_add(lv_obj_t* obj, const char* text, lv_obj_t* obj_parent) 
{     
  obj = lv_label_create(obj_parent, NULL); 	
  lv_obj_set_size(obj, 100, 20);     
  /*lv_obj_set_parent(obj, obj_parent);*/     
  /*lv_obj_set_pos(button_ffaf_label, list_play_list_btn->coords.x1+100, list_play_list_btn->coords.y1);*/     
  lv_obj_set_pos(obj, 70, 10); 	
  lv_obj_set_style_local_text_color(obj,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));     
  lv_obj_set_style_local_text_font(obj,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_22);     
  lv_obj_set_style_local_bg_opa(obj,LV_LIST_PART_BG, LV_STATE_DEFAULT, 0);     
  lv_label_set_text(obj, text); 

  return obj_parent->child_ll.head;
}  
void* awe_bot_add(lv_obj_t* obj, const char* text, lv_obj_t* obj_parent) 
{     
  obj = lv_label_create(obj_parent, NULL);     
  lv_obj_set_pos(obj, 70, 35);      
  /*lv_obj_set_parent(obj, list_play_list_btn);*/     
  lv_obj_set_size(obj, 60, 25); 	
  lv_obj_set_style_local_text_color(obj,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));     
  lv_obj_set_style_local_text_font(obj,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_13);     
  lv_obj_set_style_local_bg_opa(obj,LV_LIST_PART_BG, LV_STATE_DEFAULT, 0);     
  lv_obj_add_style(obj, LV_BTN_PART_MAIN, &style_label);     
  lv_label_set_text(obj, text); 

  return obj_parent->child_ll.head;
}  
void* awe_right_add(lv_obj_t* obj, const char* text, lv_obj_t* obj_parent) 
{     
  obj = lv_label_create(obj_parent, NULL);     
  lv_obj_set_pos(obj, 360, 25);     
  /*lv_obj_set_parent(obj, obj_parent);*/     
  /*lv_obj_set_pos(button_ffaf_label, list_play_list_btn->coords.x1+200, list_play_list_btn->coords.y1);*/ 	
  lv_obj_set_size(obj, 60, 20);     
  lv_obj_set_style_local_text_color(obj,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));     
  lv_obj_set_style_local_text_font(obj,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_13);     
  lv_obj_set_style_local_bg_opa(obj,LV_LIST_PART_BG, LV_STATE_DEFAULT, 0);     
  lv_obj_add_style(obj, LV_BTN_PART_MAIN, &style_label);     
  lv_label_set_text(obj, text); 

  return obj_parent->child_ll.head;
}  
void list_btn_cb(lv_obj_t* obj, lv_event_t* event) 
{     
  if ((event) == (LV_EVENT_SHORT_CLICKED)) {         
    if(obj == list_play_list_btn[0]) {
      # if 1
      lv_img_set_src(image_0_b, &imgimg_play_ing_png);
      lv_img_set_src(image_1_b, &imgll_png);
      lv_img_set_src(image_2_b, &imghcd_png);
      lv_img_set_src(image_3_b, &imghcd_png);
      lv_img_set_src(image_4_b, &imgtxdx_png);

      lv_obj_set_pos(image_0_b, 25, 20);
      lv_obj_set_pos(image_1_b, 25, 10);
      lv_obj_set_pos(image_2_b, 25, 10);
      lv_obj_set_pos(image_3_b, 25, 10);
      lv_obj_set_pos(image_4_b, 25, 10);

      lv_obj_set_style_local_text_color(label_top_1_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x4a, 0x90, 0xe2));
      lv_obj_set_style_local_text_color(label_top_2_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x4a, 0x90, 0xe2));
      lv_obj_set_style_local_text_color(label_top_3_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x4a, 0x90, 0xe2));
      lv_obj_set_style_local_text_color(label_top_4_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_5_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_6_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_7_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_8_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_9_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_10_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_11_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_12_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_13_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_14_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_15_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      #endif
    }else if(obj == list_play_list_btn[1]) {
      # if 1
      lv_img_set_src(image_0_b, &imgpl_png);
      lv_img_set_src(image_1_b, &imgimg_play_ing_png);
      lv_img_set_src(image_2_b, &imghcd_png);
      lv_img_set_src(image_3_b, &imghcd_png);
      lv_img_set_src(image_4_b, &imgtxdx_png);

      lv_obj_set_pos(image_1_b, 25, 20);
      lv_obj_set_pos(image_0_b, 25, 10);
      lv_obj_set_pos(image_2_b, 25, 10);
      lv_obj_set_pos(image_3_b, 25, 10);
      lv_obj_set_pos(image_4_b, 25, 10);

      lv_obj_set_style_local_text_color(label_top_4_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x4a, 0x90, 0xe2));
      lv_obj_set_style_local_text_color(label_top_5_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x4a, 0x90, 0xe2));
      lv_obj_set_style_local_text_color(label_top_6_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x4a, 0x90, 0xe2));
      lv_obj_set_style_local_text_color(label_top_1_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_2_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_3_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_7_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_8_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_9_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_10_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_11_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_12_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_13_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_14_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_15_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      #endif
    }else if(obj == list_play_list_btn[2]) {
      # if 1
      lv_img_set_src(image_0_b, &imgpl_png);
      lv_img_set_src(image_1_b, &imgll_png);
      lv_img_set_src(image_2_b, &imgimg_play_ing_png);
      lv_img_set_src(image_3_b, &imghcd_png);
      lv_img_set_src(image_4_b, &imgtxdx_png);

      lv_obj_set_pos(image_2_b, 25, 20);
      lv_obj_set_pos(image_0_b, 25, 10);
      lv_obj_set_pos(image_1_b, 25, 10);
      lv_obj_set_pos(image_3_b, 25, 10);
      lv_obj_set_pos(image_4_b, 25, 10);

      lv_obj_set_style_local_text_color(label_top_7_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x4a, 0x90, 0xe2));
      lv_obj_set_style_local_text_color(label_top_8_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x4a, 0x90, 0xe2));
      lv_obj_set_style_local_text_color(label_top_9_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x4a, 0x90, 0xe2));
      lv_obj_set_style_local_text_color(label_top_1_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_2_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_3_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_4_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_5_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_6_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_10_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_11_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_12_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_13_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_14_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_15_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      #endif
    }else if(obj == list_play_list_btn[3]) {
      #if 1
      lv_img_set_src(image_0_b, &imgpl_png);
      lv_img_set_src(image_1_b, &imgll_png);
      lv_img_set_src(image_2_b, &imghcd_png);
      lv_img_set_src(image_3_b, &imgimg_play_ing_png);
      lv_img_set_src(image_4_b, &imgtxdx_png);

      lv_obj_set_pos(image_3_b, 25, 20);
      lv_obj_set_pos(image_0_b, 25, 10);
      lv_obj_set_pos(image_1_b, 25, 10);
      lv_obj_set_pos(image_2_b, 25, 10);
      lv_obj_set_pos(image_4_b, 25, 10);

      lv_obj_set_style_local_text_color(label_top_10_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x4a, 0x90, 0xe2));
      lv_obj_set_style_local_text_color(label_top_11_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x4a, 0x90, 0xe2));
      lv_obj_set_style_local_text_color(label_top_12_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x4a, 0x90, 0xe2));
      lv_obj_set_style_local_text_color(label_top_1_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_2_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_3_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_4_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_5_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_6_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_7_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_8_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_9_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_13_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_14_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_15_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      #endif
    }else if(obj == list_play_list_btn[4]) {
      #if 1
      lv_img_set_src(image_0_b, &imgpl_png);
      lv_img_set_src(image_1_b, &imgll_png);
      lv_img_set_src(image_2_b, &imghcd_png);
      lv_img_set_src(image_3_b, &imghcd_png);
      lv_img_set_src(image_4_b, &imgimg_play_ing_png);

      lv_obj_set_pos(image_4_b, 25, 20);
      lv_obj_set_pos(image_0_b, 25, 10);
      lv_obj_set_pos(image_1_b, 25, 10);
      lv_obj_set_pos(image_3_b, 25, 10);
      lv_obj_set_pos(image_2_b, 25, 10);

      lv_obj_set_style_local_text_color(label_top_13_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x4a, 0x90, 0xe2));
      lv_obj_set_style_local_text_color(label_top_14_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x4a, 0x90, 0xe2));
      lv_obj_set_style_local_text_color(label_top_15_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x4a, 0x90, 0xe2));
      lv_obj_set_style_local_text_color(label_top_1_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_2_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_3_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_4_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_5_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_6_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_7_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_8_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_9_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_10_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_11_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_12_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      #endif
    }
    // lv_obj_set_hidden((lv_obj_t*)label_top_1_b, true); 
    // lv_obj_set_hidden((lv_obj_t*)label_top_2_b, true); 
    // lv_obj_set_hidden((lv_obj_t*)label_top_3_b, true); 
    // lv_obj_set_hidden((lv_obj_t*)image_0_b, true); 

  }else if ((event) == (LV_EVENT_LONG_PRESSED)) {         
    /*lv_obj_set_hidden(image_0, false);         
    lv_obj_set_hidden(image_1, false);         
    lv_obj_set_hidden(image_2, false);         
    lv_obj_set_hidden(image_3, false);         
    lv_obj_set_hidden(image_4, false);         
    lv_obj_set_hidden(image_5, false);         
    lv_obj_set_hidden(image_test,false);*/         
    /*_lv_obj_set_style_local_opa(label_top_9,LV_LIST_PART_BG, LV_STATE_DEFAULT, 0);*/
    // lv_obj_set_hidden((lv_obj_t*)label_top_1_b, false); 
    // lv_obj_set_hidden((lv_obj_t*)label_top_2_b, false); 
    // lv_obj_set_hidden((lv_obj_t*)label_top_3_b, false); 
    // lv_obj_set_hidden((lv_obj_t*)image_0_b, false); 
      #if 1
      lv_img_set_src(image_0_b, &imgpl_png);
      lv_img_set_src(image_1_b, &imgll_png);
      lv_img_set_src(image_2_b, &imghcd_png);
      lv_img_set_src(image_3_b, &imghcd_png);
      lv_img_set_src(image_4_b, &imgtxdx_png);

      lv_obj_set_pos(image_4_b, 25, 10);
      lv_obj_set_pos(image_0_b, 25, 10);
      lv_obj_set_pos(image_1_b, 25, 10);
      lv_obj_set_pos(image_3_b, 25, 10);
      lv_obj_set_pos(image_2_b, 25, 10);

      lv_obj_set_style_local_text_color(label_top_13_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_14_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_15_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_1_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_2_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_3_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_4_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_5_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_6_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_7_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_8_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_9_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_10_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_11_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      lv_obj_set_style_local_text_color(label_top_12_b,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
      #endif
    } 
}
//======音乐列表====== 
//!fix here ======fan动画=======
lv_anim_t awe_te_fan; 
lv_anim_path_t awe_fan_path;  
void te_fan_anim_cb(void* var, int32_t v) 
{     
  lv_img_set_angle(var, v); 
}  
static void lv_te_fan_anim(void)   
{             
  lv_anim_path_init(&awe_fan_path);        
  lv_anim_path_set_cb(&awe_fan_path, lv_anim_path_ease_in_out);              
  lv_anim_init(&awe_te_fan);      /*lv_anim_set_var(&a, obj);*/             
  lv_anim_set_var(&awe_te_fan, image_te_fan); /* 给设置动画的控件绑定动画标识符 */             
  lv_anim_set_time(&awe_te_fan, 12000); /*设置动画持续时间*/             
  lv_anim_set_playback_delay(&awe_te_fan, 100); /* 设置动画延迟回播时间 */             
  lv_anim_set_playback_time(&awe_te_fan, 12000);  /* 设置动画回播时间 */             
  lv_anim_set_repeat_delay(&awe_te_fan, 100); /* 设置重复播放延时时间 */             
  lv_anim_set_repeat_count(&awe_te_fan, LV_ANIM_REPEAT_INFINITE); /* 设置重播次数为重复播放 */            
  lv_anim_set_path(&awe_te_fan, &awe_fan_path); /* 设置动画path处理方式 */                       
  lv_anim_set_exec_cb(&awe_te_fan, (lv_anim_exec_xcb_t)te_fan_anim_cb);                        
  lv_anim_set_values(&awe_te_fan, 0, 360000);            
  lv_anim_start(&awe_te_fan);   
} 
//======fan动画 end=======
//======灯光界面控制标志位======
// static bool light_sign = true;
//======灯光界面控制标志位 end======

static bool screen_music_sign = true; 

lv_task_t* task_callback_81leqa;
void callback_81leqa(lv_task_t* t){

  lv_img_set_pivot(image_ma_fan, 8.5, 8.5);

  static int ma_timer_index=1;
  if(ma_timer_index<1)
    ma_timer_index=1;
  lv_img_set_angle(image_ma_fan,ma_timer_index*25);

  ma_timer_index++;
}


lv_task_t* _task_callback_c3ewkq;
void callback_c3ewkq(lv_task_t* t){
  static int _timer_index=1;
  if(_timer_index<1)
    _timer_index=1;
  if ((_timer_index) == 1) {
    lv_label_set_text(label_main_time, "10:");
  } else if ((_timer_index) > 1) {
    _timer_index = 0;
    lv_label_set_text(label_main_time, "10 ");
  }

  _timer_index++;
}
    void __qmsd_screen_main_init(void) {
  lv_obj_set_style_local_border_opa(switch_ma, LV_CONT_PART_MAIN, LV_STATE_DEFAULT, LV_OPA_TRANSP);
  lv_obj_set_click(button_ma_bott,false);
  lv_obj_set_click(button_ma_color,false);
  lv_obj_set_click(button_ma_barra,false);
  lv_obj_set_click(button_ma_barbt,false);
  lv_label_set_text_fmt(label_ma_windy,"%d",(int)set_windy);
  if (((int)screen_main_sign) > 0) {
    lv_example_anim_world();
    lv_example_anim_bar();
    lv_switch_toggle(switch_ma,LV_ANIM_ON);
    screen_main_sign = !screen_main_sign;
    sign = !sign;
    // task_callback_81leqa=lv_task_create(callback_81leqa,1 , LV_TASK_PRIO_HIGH , NULL);
    _task_callback_c3ewkq=lv_task_create(callback_c3ewkq,1000 , LV_TASK_PRIO_HIGH , NULL);
  }
  if (((int)sign) > 0) {
    lv_label_set_text(label_ma_label, "开");
    lv_obj_set_style_local_bg_color(button_ma_color,LV_BTN_PART_MAIN,LV_STATE_DEFAULT,(LV_COLOR_MAKE(248,231,28)));
  } else {
    lv_label_set_text(label_ma_label, "关");
    lv_obj_set_style_local_bg_color(button_ma_color,LV_BTN_PART_MAIN,LV_STATE_DEFAULT,(LV_COLOR_MAKE(155,155,155)));
  }
}

void __qmsd_screen_temper_init(void) {
  te_bar_sign = false;
  lv_obj_set_click(button_te_barbt,false);
  lv_obj_set_click(button_te_barra,false);
  lv_obj_set_click(button_te_bott,false);
  lv_obj_set_click(image_te_bar,true);
  lv_label_set_text_fmt(label_te_windy,"%d",(int)set_windy);
  lv_te_fan_anim();
}

void __qmsd_image_mu_list_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  lv_obj_set_click(image_mu_s_m,false);
  lv_obj_set_click(image_mu_s_l,false);
  lv_obj_set_click(image_mu_s_r,false);
  lv_obj_set_hidden(image_play_bo,false);
  lv_obj_move_foreground(image_play_bo);
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_image_play_re_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  lv_obj_set_click(image_mu_s_m,true);
  lv_obj_set_click(image_mu_s_l,true);
  lv_obj_set_click(image_mu_s_r,true);
  lv_obj_move_background(image_play_bo);
  lv_obj_set_hidden(image_play_bo,true);
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_screen_music_init(void) {
  lv_obj_set_hidden(image_play_bo,true);
  if (((int)screen_music_sign) > 0) {
    qmsd_list_play_list_create();
  }
}

void __qmsd_button_ma_music_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  screen_music_show();
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_button_ma_tem_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  screen_temper_show();
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_button_ma_light_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  screen_light_show();
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_image_mu_return_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  screen_main_show();
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_screen_light_init(void) {
  lv_obj_set_click(button_li_l_bt,false);
  lv_obj_set_click(button_li_l_ra,false);
  lv_obj_set_click(button_li_c_bt,false);
  lv_obj_set_click(button_li_c_ra,false);
  if (((int)screen_light_sign) > 0) {
    screen_light_sign = !screen_light_sign;
  }

  if(sign) {
    lv_obj_set_style_local_image_opa(image_li_light,LV_IMG_PART_MAIN,LV_STATE_DEFAULT,255);
    lv_obj_set_style_local_image_opa(image_li_set,LV_IMG_PART_MAIN,LV_STATE_DEFAULT,255);

  //   lv_example_anim_li_l();
  //   lv_example_anim_li_c();
  }else {
    lv_obj_set_style_local_image_opa(image_li_light,LV_IMG_PART_MAIN,LV_STATE_DEFAULT,155);
    // lv_obj_set_style_local_image_opa(image_li_set,LV_IMG_PART_MAIN,LV_STATE_DEFAULT,155);

  //   lv_anim_del(button_li_l_ra,li_l_anim_y_size_cb);
  //   lv_anim_del(button_li_c_ra,li_c_anim_y_size_cb);
  }
}

void __qmsd_image_te_return_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  // printf("add here\n");
  screen_temper_delete();
  screen_main_show();
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_label_mu_return_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  screen_main_show();
  screen_music_delete();
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_image_li_return_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  // printf("add here timer\n");
  screen_light_delete();
  screen_main_show();
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_label_te_return_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  // printf("add here\n");
  screen_temper_delete();
  screen_main_show();
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_label_li_return_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  // printf("add here timer\n");
  screen_light_delete();
  screen_main_show();
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_image_ma_high_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  set_windy++;
  if (((int)set_windy) >= 30) {
    set_windy = 30;
  }
  lv_label_set_text_fmt(label_ma_windy,"%d",(int)set_windy);
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_image_te_up_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  set_windy++;
  if (((int)set_windy) >= 30) {
    set_windy = 30;
  }
  lv_label_set_text_fmt(label_te_windy,"%d",(int)set_windy);
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_image_ma_low_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  set_windy--;
  if (((int)set_windy) <= 16) {
    set_windy = 16;
  }
  lv_label_set_text_fmt(label_ma_windy,"%d",(int)set_windy);
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_image_mu_prev_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
#if 0
  img_l--;img_m--;img_r--;
  if(img_l == 0)
  {
      img_l = 3;
  }
  if(img_m == 0)
  {
      img_m = 3;
  }
  if(img_r == 0)
  {
      img_r = 3;
  }
  if (((int)img_l) == 1) {
    lv_img_set_src(image_mu_s_l, &imgimg_mu_1_png);
  } else if (((int)img_l) == 2) {
    lv_img_set_src(image_mu_s_l, &imgimg_mu_2_png);
  } else if (((int)img_l) == 3) {
    lv_img_set_src(image_mu_s_l, &imgimg_mu_3_png);
  }
  if (((int)img_m) == 1) {
    lv_img_set_src(image_mu_s_m, &imgimg_mu_1_png);
    lv_label_set_text(label_mu_singer, "Havana");
    lv_label_set_text(label_mu_song, "Cabello feat Young");
  } else if (((int)img_m) == 2) {
    lv_img_set_src(image_mu_s_m, &imgimg_mu_2_png);
    lv_label_set_text(label_mu_singer, "Rose");
    lv_label_set_text(label_mu_song, "Stay Tonight ");
  } else if (((int)img_m) == 3) {
    lv_img_set_src(image_mu_s_m, &imgimg_mu_3_png);
    lv_label_set_text(label_mu_singer, "张震岳");
    lv_label_set_text(label_mu_song, "无路用的人");
  }
  if (((int)img_r) == 1) {
    lv_img_set_src(image_mu_s_r, &imgimg_mu_1_png);
  } else if (((int)img_r) == 2) {
    lv_img_set_src(image_mu_s_r, &imgimg_mu_2_png);
  } else if (((int)img_r) == 3) {
    lv_img_set_src(image_mu_s_r, &imgimg_mu_3_png);
  }
#endif
//! fix here
  if(lv_obj_get_x(image_mu_s_m) == 47) {
    anim_min_img_m();
  } else if(lv_obj_get_x(image_mu_s_l) == 47) {
    anim_min_img_l();
  } else if(lv_obj_get_x(image_mu_s_r) == 47) {
    anim_min_img_r();
  }
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_image_mu_next_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
#if 0
  img_l++;img_m++;img_r++;
  if(img_l == 4)
  {
      img_l = 1;
  }
  if(img_m == 4)
  {
      img_m = 1;
  }
  if(img_r == 4)
  {
      img_r = 1;
  }
  if (((int)img_l) == 1) {
    lv_img_set_src(image_mu_s_l, &imgimg_mu_1_png);
  } else if (((int)img_l) == 2) {
    lv_img_set_src(image_mu_s_l, &imgimg_mu_2_png);
  } else if (((int)img_l) == 3) {
    lv_img_set_src(image_mu_s_l, &imgimg_mu_3_png);
  }
  if (((int)img_m) == 1) {
    lv_img_set_src(image_mu_s_m, &imgimg_mu_1_png);
    lv_label_set_text(label_mu_singer, "Havana");
    lv_label_set_text(label_mu_song, "Cabello feat Young");
  } else if (((int)img_m) == 2) {
    lv_img_set_src(image_mu_s_m, &imgimg_mu_2_png);
    lv_label_set_text(label_mu_singer, "Rose");
    lv_label_set_text(label_mu_song, "Stay Tonight ");
  } else if (((int)img_m) == 3) {
    lv_img_set_src(image_mu_s_m, &imgimg_mu_3_png);
    lv_label_set_text(label_mu_singer, "张震岳");
    lv_label_set_text(label_mu_song, "无路用的人");
  }
  if (((int)img_r) == 1) {
    lv_img_set_src(image_mu_s_r, &imgimg_mu_1_png);
  } else if (((int)img_r) == 2) {
    lv_img_set_src(image_mu_s_r, &imgimg_mu_2_png);
  } else if (((int)img_r) == 3) {
    lv_img_set_src(image_mu_s_r, &imgimg_mu_3_png);
  }
#endif
//! fix here
  if(lv_obj_get_x(image_mu_s_m) == 258) {
    anim_min_img_m();
  } else if(lv_obj_get_x(image_mu_s_l) == 258) {
    anim_min_img_l();
  } else if(lv_obj_get_x(image_mu_s_r) == 258) {
    anim_min_img_r();
  }

} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_switch_ma_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_VALUE_CHANGED) {
  sign = !sign;
  if (((int)sign) > 0) {
    lv_label_set_text(label_ma_label, "开");
    lv_obj_set_style_local_bg_color(button_ma_color,LV_BTN_PART_MAIN,LV_STATE_DEFAULT,(LV_COLOR_MAKE(248,231,28)));
    lv_obj_set_style_local_image_opa(image_ma_light,LV_IMG_PART_MAIN,LV_STATE_DEFAULT,255);
  } else {
    lv_label_set_text(label_ma_label, "关");
    lv_obj_set_style_local_bg_color(button_ma_color,LV_BTN_PART_MAIN,LV_STATE_DEFAULT,(LV_COLOR_MAKE(155,155,155)));
    lv_obj_set_style_local_image_opa(image_ma_light,LV_IMG_PART_MAIN,LV_STATE_DEFAULT,155);
  }
}
}

void __qmsd_switch_te_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_VALUE_CHANGED) {
  te_bar_sign = !te_bar_sign;
  if (((int)te_bar_sign) > 0) {
    lv_example_anim_te();
  } else {
    lv_anim_del(button_te_barra,te_anim_y_size_cb);
  }
}
}

void __qmsd_image_mu_s_l_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  anim_min_img_l();
  lv_label_set_text(label_mu_singer, "张震岳");
  lv_label_set_text(label_mu_song, "无路用的人");
  lv_label_set_align(label_mu_singer, LV_LABEL_ALIGN_CENTER);
  lv_label_set_align(label_mu_song, LV_LABEL_ALIGN_CENTER);
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_image_mu_s_r_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  anim_min_img_r();
  lv_label_set_text(label_mu_singer, "Rose");
  lv_label_set_text(label_mu_song, "Stay Tonight");
  lv_label_set_align(label_mu_singer, LV_LABEL_ALIGN_CENTER);
  lv_label_set_align(label_mu_song, LV_LABEL_ALIGN_CENTER);
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}


void __qmsd_image_li_set_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  li_bar_sign = !li_bar_sign;
  // if (((int)li_bar_sign) > 0) {
  //   lv_example_anim_li_l();
  //   lv_example_anim_li_c();
  // } else {
  //   lv_anim_del(button_li_l_ra,li_l_anim_y_size_cb);
  //   lv_anim_del(button_li_c_ra,li_c_anim_y_size_cb);
  // }

  sign = !sign;
  if(sign) {
    lv_obj_set_style_local_image_opa(image_li_light,LV_IMG_PART_MAIN,LV_STATE_DEFAULT,255);

  //   lv_example_anim_li_l();
  //   lv_example_anim_li_c();
  }else if(!sign) {
    lv_obj_set_style_local_image_opa(image_li_light,LV_IMG_PART_MAIN,LV_STATE_DEFAULT,155);

  //   lv_anim_del(button_li_l_ra,li_l_anim_y_size_cb);
  //   lv_anim_del(button_li_c_ra,li_c_anim_y_size_cb);
  }
  if (((int)sign) > 0) {
    lv_label_set_text(label_ma_label, "开");
    lv_switch_toggle(switch_ma, LV_ANIM_OFF);
    lv_obj_set_style_local_bg_color(button_ma_color,LV_BTN_PART_MAIN,LV_STATE_DEFAULT,(LV_COLOR_MAKE(248,231,28)));
    lv_obj_set_style_local_image_opa(image_ma_light,LV_IMG_PART_MAIN,LV_STATE_DEFAULT,255);
    lv_obj_set_style_local_image_opa(image_li_set,LV_IMG_PART_MAIN,LV_STATE_DEFAULT,255);
  } else {
    lv_label_set_text(label_ma_label, "关");
    lv_switch_toggle(switch_ma, LV_ANIM_OFF);
    lv_obj_set_style_local_bg_color(button_ma_color,LV_BTN_PART_MAIN,LV_STATE_DEFAULT,(LV_COLOR_MAKE(155,155,155)));
    lv_obj_set_style_local_image_opa(image_ma_light,LV_IMG_PART_MAIN,LV_STATE_DEFAULT,155);
    // lv_obj_set_style_local_image_opa(image_li_set,LV_IMG_PART_MAIN,LV_STATE_DEFAULT,155);
  }
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}

void __qmsd_image_mu_s_m_cb(lv_obj_t * obj, lv_event_t event) {
if(event == LV_EVENT_SHORT_CLICKED) {
  anim_min_img_m();
  lv_label_set_text(label_mu_singer, "Havana");
  lv_label_set_text(label_mu_song, "Cabello feat Young");
  lv_label_set_align(label_mu_singer, LV_LABEL_ALIGN_CENTER);
  lv_label_set_align(label_mu_song, LV_LABEL_ALIGN_CENTER);
} else if (event == LV_EVENT_LONG_PRESSED||event == LV_EVENT_LONG_PRESSED_REPEAT) {
}
}
