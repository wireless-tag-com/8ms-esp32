#include "qmsd_ui_entry.h"
#include "qmsd_ctrl.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char *name;
    lv_img_src_t* img;
} qmsd_img_t;

typedef struct
{
    char *name;
    lv_font_t* font;
} qmsd_font_t;

/*
* includes
*/

/*
* declear screens
*/

lv_obj_t * g_kb = NULL;

static void g_kb_event_cb(lv_obj_t * event_kb, lv_event_t event)
{
    /* Just call the regular event handler */
    if(event == LV_EVENT_APPLY) {
        lv_obj_set_hidden(event_kb, true);
    } else if(event == LV_EVENT_CANCEL) {
        lv_obj_set_hidden(event_kb, true);
    }
    else if (event==LV_EVENT_DELETE){
        g_kb=NULL;
    } else {
        lv_keyboard_def_event_cb(event_kb, event);
    }
}
void g_create_kb_ifneeded() {
    if(g_kb == NULL) {
        g_kb = lv_keyboard_create(screen_main, NULL);
        lv_obj_set_pos(g_kb, 5, 90);
        lv_obj_set_event_cb(g_kb, g_kb_event_cb); /* Setting a custom event handler stops the keyboard from closing automatically */
        lv_obj_set_size(g_kb,  LV_HOR_RES - 10, 140);
        lv_keyboard_set_cursor_manage(g_kb, true); /* Automatically show/hide cursors on text areas */
        lv_obj_set_hidden(g_kb, true);
    }
}
void g_show_kb() 
{
    g_create_kb_ifneeded();
    lv_obj_set_parent(g_kb, lv_scr_act());
    lv_obj_set_hidden(g_kb, false);
    lv_obj_align(g_kb,NULL,LV_ALIGN_IN_BOTTOM_MID,0,0);
}

qmsd_img_t g_qmsd_img[] = 
{
        {"imgtips_png",&imgtips_png},
    {"imgair_conditioner_off_png",&imgair_conditioner_off_png},
    {"imgair_conditioner_on_png",&imgair_conditioner_on_png},
    {"imgair_conditioner_sign_png",&imgair_conditioner_sign_png},
    {"imgtileview2_next_png",&imgtileview2_next_png},
    {"imgtileview3_robot_png",&imgtileview3_robot_png},
    {"imgtileview2_stop_bottom_png",&imgtileview2_stop_bottom_png},
    {"imgtileview2_stop_open_png",&imgtileview2_stop_open_png},
    {"imgcontlink_bottom_png",&imgcontlink_bottom_png},
    {"imgcontlink_sign_png",&imgcontlink_sign_png},
    {"imgtileview1_press_png",&imgtileview1_press_png},
    {"imgcurtain_button_on_png",&imgcurtain_button_on_png},
    {"imgtileview2_stop_stop_png",&imgtileview2_stop_stop_png},
    {"imglist_equipment_png",&imglist_equipment_png},
    {"imglist_wifi_png",&imglist_wifi_png},
    {"imgcontlink_main_more_png",&imgcontlink_main_more_png},
    {"imgcontlink_main_set_png",&imgcontlink_main_set_png},
    {"imgcontlink_main_home_png",&imgcontlink_main_home_png},
    {"imgcurtain_curtain_cloth_png",&imgcurtain_curtain_cloth_png},
    {"imgcurtain_button_all_png",&imgcurtain_button_all_png},
    {"imgcurtain_button_close_png",&imgcurtain_button_close_png},
    {"imgcurtain_button_stop_png",&imgcurtain_button_stop_png},
    {"imgcurtain_button_open_png",&imgcurtain_button_open_png},
    {"imgcurtain_button_off_png",&imgcurtain_button_off_png},
    {"imgcurtain_curtain_right_png",&imgcurtain_curtain_right_png},
    {"imgcurtain_curtain_left_png",&imgcurtain_curtain_left_png},
    {"imglist_return_png",&imglist_return_png},
    {"imglist_voice_png",&imglist_voice_png},
    {"imglist_show_png",&imglist_show_png},
    {"imglist_song_png",&imglist_song_png},
    {"imglist_user_png",&imglist_user_png},
    {"imglist_ota_png",&imglist_ota_png},
    {"imglist_about_png",&imglist_about_png},
    {"imglist_delete_png",&imglist_delete_png},
    {"imgequipment_load_png",&imgequipment_load_png},
    {"imgequipment_smile_png",&imgequipment_smile_png},
    {"imgwifi_lock_png",&imgwifi_lock_png},
    {"imgwifi_load_png",&imgwifi_load_png},
    {"imgwifi_choice_png",&imgwifi_choice_png},
    {"imgwifi_error_png",&imgwifi_error_png},
    {"imgair_curditioner_middle_png",&imgair_curditioner_middle_png},
    {"imgcurtain_curtain_top_png",&imgcurtain_curtain_top_png},
    {"imgair_curditioner_high_png",&imgair_curditioner_high_png},
    {"imgair_curditioner_low_png",&imgair_curditioner_low_png},
    {"imgtileview2_curtain0_png",&imgtileview2_curtain0_png},
    {"imgtileview2_left_png",&imgtileview2_left_png},
    {"imgtileview2_right_png",&imgtileview2_right_png},
    {"imgtileview2_air_conditioner_bottom_png",&imgtileview2_air_conditioner_bottom_png},
    {"imgtilevwe2_prev_button_png",&imgtilevwe2_prev_button_png},
    {"imgtileview2_button_one_png",&imgtileview2_button_one_png},
    {"imgtileview2_button_two_png",&imgtileview2_button_two_png},
    {"imgtileview_button_three_png",&imgtileview_button_three_png},
    {"imgtileview_button_four_png",&imgtileview_button_four_png},
    {"imgtileview3_button_more_png",&imgtileview3_button_more_png},
    {"imgtileview3_more_png",&imgtileview3_more_png},
    {"imgchoice_return_png",&imgchoice_return_png},
    {"imgchoice_leave_home_png",&imgchoice_leave_home_png},
    {"imgchoice_go_home_png",&imgchoice_go_home_png},
    {"imgair_curditioner_sun_png",&imgair_curditioner_sun_png},
    {"imgair_curditioner_cold_png",&imgair_curditioner_cold_png},
    {"imgchoice_fime__png",&imgchoice_fime__png},
    {"imgchoice_fime_png",&imgchoice_fime_png},
    {"imgchoice_meet__png",&imgchoice_meet__png},
    {"imgchoice_meet_png",&imgchoice_meet_png},
    {"imgchoice_sleep__png",&imgchoice_sleep__png},
    {"imgchoice_sleep_png",&imgchoice_sleep_png},
    {"imgchoice_go_bed__png",&imgchoice_go_bed__png},
    {"imgchoice_go_bed_png",&imgchoice_go_bed_png},
    {"imgsaver_button_png",&imgsaver_button_png},
    {"imgsaver_image_png",&imgsaver_image_png},
    {"imgweather_png",&imgweather_png},
    {"imghumidity_png",&imghumidity_png},
    {"imgair_png",&imgair_png},
    {"imgtileview_1_png",&imgtileview_1_png},
    {"imgtileview_2_png",&imgtileview_2_png},
    {"imgtileview_3_png",&imgtileview_3_png},
    {"imgtileview_go_home_png",&imgtileview_go_home_png},
    {"imgtileview_leave_home_png",&imgtileview_leave_home_png},
    {"imgtileview_more_png",&imgtileview_more_png},
    {"imgtileview2_leave_home_png",&imgtileview2_leave_home_png},
    {"imgtileview2_go_home_png",&imgtileview2_go_home_png},
    {"imgtileview2_living_room_png",&imgtileview2_living_room_png},
    {"imgtileview2_living_room_light_png",&imgtileview2_living_room_light_png},
    {"imgtileview2_restaurant_png",&imgtileview2_restaurant_png},
    {"imgtileview2_curtain_1_png",&imgtileview2_curtain_1_png},
    {"imglogo_png",&imglogo_png},
};

qmsd_font_t g_qmsd_font[] =
{
    {"ali_font_32",&ali_font_32},
    {"ali_font_35",&ali_font_35},
    {"ali_font_104",&ali_font_104},
    {"ali_font_40",&ali_font_40},
    {"ali_font_11",&ali_font_11},
    {"ali_font_107",&ali_font_107},
    {"ali_font_13",&ali_font_13},
    {"ali_font_14",&ali_font_14},
    {"ali_font_16",&ali_font_16},
    {"ali_font_17",&ali_font_17},
    {"ali_font_18",&ali_font_18},
    {"ali_font_19",&ali_font_19},
    {"ali_font_20",&ali_font_20},
    {"ali_font_21",&ali_font_21},
    {"ali_font_23",&ali_font_23},
    {"ali_font_24",&ali_font_24},
    {"ali_font_30",&ali_font_30},
};

void qmsd_ui_entry(void)
{
    qmsd_screen_list_init(16);
    qmsd_set_screen(qmsd_search_screen);
    qmsd_set_widget(qmsd_search_widget);
    qmsd_set_img(qmsd_get_img);
    qmsd_set_font(qmsd_get_font);
    
    screen_main_build();
    screen_set_build();
    screen_text_build();

    screen_main_show();
}

lv_img_src_t *qmsd_get_img(const char *w_name)
{
    int i = 0;

    for (i = 0; i < (sizeof(g_qmsd_img) / sizeof(g_qmsd_img[0])); i++)
    {
        if (!strcmp(w_name, g_qmsd_img[i].name))
        {
            if (g_qmsd_img[i].img) {
                return g_qmsd_img[i].img;
            } else {
                return NULL;
            }
        }
    }

    return NULL;
}

lv_font_t *qmsd_get_font(const char *w_name)
{
    int i = 0;

    for (i = 0; i < (sizeof(g_qmsd_font) / sizeof(g_qmsd_font[0])); i++)
    {
        if (!strcmp(w_name, g_qmsd_font[i].name))
        {
            if (g_qmsd_font[i].font) {
                return g_qmsd_font[i].font;
            } else {
                return NULL;
            }
        }
    }

    return NULL;
}