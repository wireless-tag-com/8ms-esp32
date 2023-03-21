#include <sdkconfig.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "esp_system.h"
#include "esp_log.h"
#include "esp_console.h"
#include "linenoise/linenoise.h"
#include "argtable3/argtable3.h"
#include "esp_heap_caps.h"
#include "lvgl.h"

static lv_obj_t *g_screen_test;

static int qmsd_test_lcdr(int argc, char **argv)
{
    /*
     * start LCD red test
     */

    printf("lcd red start\n");

    if (g_screen_test) {
        lv_obj_del(g_screen_test);
    }
    g_screen_test = lv_obj_create(NULL, NULL);
    lv_scr_load(g_screen_test);
    lv_obj_set_style_local_bg_color(lv_scr_act(),NULL,LV_STATE_DEFAULT,LV_COLOR_RED);

    return 0;
}

static int qmsd_test_lcdg(int argc, char **argv)
{
    /*
     * start LCD green test
     */

    printf("lcd green start\n");

    if (!g_screen_test) {
        g_screen_test = lv_obj_create(NULL, NULL);
    }
    lv_scr_load(g_screen_test);
    lv_obj_set_style_local_bg_color(lv_scr_act(),NULL,LV_STATE_DEFAULT,LV_COLOR_GREEN);

    return 0;
}

static int qmsd_test_lcdb(int argc, char **argv)
{
    /*
     * start LCD black test
     */

    printf("lcd blue start\n");

    if (!g_screen_test) {
        g_screen_test = lv_obj_create(NULL, NULL);
    }

    lv_scr_load(g_screen_test);
    lv_obj_set_style_local_bg_color(lv_scr_act(),NULL,LV_STATE_DEFAULT,LV_COLOR_BLUE);

    return 0;
}

static int16_t scr_width;
static int16_t scr_height;
static lv_point_t* test_point;

bool qmsd_obj_is_near_point(int x,int y,lv_point_t* point)
{
    if((abs(x - point->x)<scr_width/12)&&(abs(y - point->y)<scr_width/12))
        return true;
    else
        return false;
}

static void drag_obj_cb(lv_obj_t* obj,lv_event_t event)
{
    static int process_stage = 0;
    if (event == LV_EVENT_PRESSING)
    {
        int x = (obj->coords.x1 + obj->coords.x2)/2;
        int y = (obj->coords.y1 + obj->coords.y2)/2;
        switch (process_stage)
        {
        case 0:
            if (qmsd_obj_is_near_point(x,y,test_point+1))
            {
                lv_obj_set_drag_dir(obj,LV_DRAG_DIR_VER);
                qmsd_obj_set_pos_ori(obj,(test_point+1)->x,(test_point+1)->y);
                process_stage = 1;
            }
            break;
        case 1:
            if (qmsd_obj_is_near_point(x,y,test_point+2))
            {
                lv_obj_set_drag_dir(obj,LV_DRAG_DIR_HOR);
                qmsd_obj_set_pos_ori(obj,(test_point+2)->x,(test_point+2)->y);
                process_stage = 2;
            }
            break;
        case 2:
            if (qmsd_obj_is_near_point(x,y,test_point+3))
            {
                lv_obj_set_drag_dir(obj,LV_DRAG_DIR_VER);
                qmsd_obj_set_pos_ori(obj,(test_point+3)->x,(test_point+3)->y);
                process_stage = 3;
            }
            break;  
        case 3:
            if (qmsd_obj_is_near_point(x,y,test_point+4))
            {
                lv_obj_set_drag_dir(obj,LV_DRAG_DIR_HOR);
                qmsd_obj_set_pos_ori(obj,(test_point+4)->x,(test_point+4)->y);
                process_stage = 4;
            }
            break;      
        case 4:
            if (qmsd_obj_is_near_point(x,y,test_point+5))
            {
                lv_obj_set_style_local_bg_color(lv_scr_act(),NULL,LV_STATE_DEFAULT,LV_COLOR_GREEN);
                lv_obj_set_drag(obj,false);
                qmsd_obj_set_pos_ori(obj,(test_point+5)->x,(test_point+5)->y);
                process_stage = 0;
                printf("tpok\n");
            }
            break;    
        default:
            break;
        }
    }
    else if (event == LV_EVENT_RELEASED || event == LV_EVENT_PRESS_LOST)
    {
        process_stage = 0;
        lv_obj_set_drag_dir(obj,LV_DRAG_DIR_HOR);
        qmsd_obj_set_pos_ori(obj,test_point->x,test_point->y);
    }
    
}

static void __qmsd_lcd_tp_test(void)
{
    scr_width = lv_disp_get_hor_res(NULL);
    scr_height = lv_disp_get_ver_res(NULL);
    test_point = malloc(6*sizeof(lv_point_t));
    test_point[0].x = scr_width/6;
    test_point[0].y = scr_height/6;
    
    test_point[1].x = scr_width - scr_width/6;
    test_point[1].y = scr_height/6;
    
    test_point[2].x = scr_width -scr_width/6;
    test_point[2].y = scr_height - scr_height/6;
    
    test_point[3].x = scr_width/6;
    test_point[3].y = scr_height - scr_height/6;

    test_point[4].x = scr_width/6;
    test_point[4].y = scr_height - scr_height/2;
    
    test_point[5].x = scr_width/2;
    test_point[5].y = scr_height/2;

    lv_obj_t * line1;
    line1 = lv_line_create(lv_scr_act(), NULL);
    lv_line_set_points(line1, test_point, 6);   
    
    lv_obj_t* drag_obj = lv_btn_create(lv_scr_act(),NULL);
    lv_obj_set_size(drag_obj,60,60);
    qmsd_obj_set_pos_ori(drag_obj,test_point[0].x,test_point[0].y);
    lv_obj_set_click(drag_obj,true);
    lv_obj_set_drag(drag_obj , true);
    lv_obj_set_drag_dir(drag_obj,LV_DRAG_DIR_HOR);
    lv_obj_set_event_cb(drag_obj,drag_obj_cb);
}

int qmsd_lcd_tp_test(int argc, char **argv)
{
    /*
     * start LCD test
     */

    printf("tp start\n");

    if (!g_screen_test) {
        g_screen_test = lv_obj_create(NULL, NULL);
    }

    lv_scr_load(g_screen_test);
    __qmsd_lcd_tp_test();

    return 0;
}

void qmsd_lcd_test_register(void)
{
    const esp_console_cmd_t lcdr_cmd = {
        .command = "lcdr",
        .help = "start lcd red test",
        .hint = NULL,
        .func = &qmsd_test_lcdr,
    };

    const esp_console_cmd_t lcdg_cmd = {
        .command = "lcdg",
        .help = "start lcd green test",
        .hint = NULL,
        .func = &qmsd_test_lcdg,
    };

    const esp_console_cmd_t lcdb_cmd = {
        .command = "lcdb",
        .help = "start lcd blue test",
        .hint = NULL,
        .func = &qmsd_test_lcdb,
    };

    ESP_ERROR_CHECK(esp_console_cmd_register(&lcdr_cmd));
    ESP_ERROR_CHECK(esp_console_cmd_register(&lcdg_cmd));
    ESP_ERROR_CHECK(esp_console_cmd_register(&lcdb_cmd));
}

void qmsd_tp_test_register(void)
{
    const esp_console_cmd_t tp_cmd = {
        .command = "tp",
        .help = "start tp test",
        .hint = NULL,
        .func = &qmsd_lcd_tp_test,
    };

    ESP_ERROR_CHECK(esp_console_cmd_register(&tp_cmd));
}
