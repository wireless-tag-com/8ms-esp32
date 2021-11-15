#include "qm_ui_entry.h"
#include <stdio.h>
#include <stdlib.h>
#include "lv_8ms_blockly.h"
#include "wtctrl.h"

lv_obj_t *main_screen;

#define BLOCKLY_init

typedef struct
{
    char *name;
    lv_obj_t **id;
} lv_widget_t;

typedef struct
{
    char *name;
    lv_obj_t **id;
    lv_widget_t *wids;
    int len;
} lv_screen_t;

/*
* includes
*/
/*
* declear screens
*/
lv_obj_t *main_screen;
lv_obj_t *p1;
lv_obj_t *p2;
lv_obj_t *p3;
lv_obj_t *s1;
lv_obj_t* btn1;
lv_obj_t* btn2;
lv_widget_t g_main_screen_ids[] =
{
    {"p2", &p2},
    {"s1", &s1},
    {"btn1",&btn1},
    {"btn2",&btn2},
};

lv_widget_t g_p1_screen_ids[] =
{
    {"p3", &p3},
};

lv_screen_t g_screens[] =
{
    {"main_screen", &main_screen, g_main_screen_ids, (sizeof(g_main_screen_ids) / sizeof(g_main_screen_ids[0]))},
    {"p1", &p1, g_p1_screen_ids, (sizeof(g_p1_screen_ids) / sizeof(g_p1_screen_ids[0]))},
};


static void
blockly_init()
{
    
}

#define BLOCKLY_loop

static void blockly_loop()
{
    //lv_8ms_uart_write(UART_NUM_1, "hello\n");
}
#define LV_8MS_EVENT

/**
 * @brief 
 * @param 
 * @return 
 */
void show_screen_main_screen()
{
    lv_scr_load(main_screen);
}

/**
 * @brief 
 * @param 
 * @return 
 */
void init_function()
{
#ifdef BLOCKLY_init
    blockly_init();
#endif
#ifdef LV_8MS_EVENT
    lv_8ms_event_handle_init();
#endif
}

/**
 * @brief 
 * @param 
 * @return 
 */
void lv_qm_ui_loop(void)
{
#ifdef BLOCKLY_loop
    blockly_loop();
#endif
}
#ifndef LV_8MS_PRESET_UART_QUEUE_0
void lv_8ms_uart_queue_ana_0(uint8_t* data,int size){   
    printf("UART-0\ndata:%s\nlength:%d\n",data,size);
}
#endif

#ifndef LV_8MS_PRESET_UART_QUEUE_1
void lv_8ms_uart_queue_ana_1(uint8_t* data,int size){   
    printf("UART-1\ndata:%s\nlength:%d\n",data,size);
}
#endif

#ifndef LV_8MS_PRESET_UART_QUEUE_2
void lv_8ms_uart_queue_ana_2(uint8_t* data,int size){   
    printf("UART-2\ndata:%s\nlength:%d\n",data,size);
}
#endif

#ifndef CUSTOM_MQTT_PARSE
void lv_8ms_mqtt_received(const char* data)
{
    printf("custom:%s\n",data);
}
#endif
void s1_test()
{
    printf("%d,%d\n",s1->coords.x1,s1->coords.y1);
}
void lv_qm_ui_entry(void)
{
    LV_FONT_DECLARE(ali_font_16);
    main_screen = lv_obj_create(NULL, NULL);
    lv_scr_load(main_screen);
}
lv_obj_t *lv_8ms_get_screen(char *name)
{
    int i = 0;
    for (i = 0; i < (sizeof(g_screens) / sizeof(g_screens[0])); i++)
    {
        if (!strcmp(name, g_screens[i].name))
        {
            return *(g_screens[i].id);
        }
    }
    return NULL;
}

lv_obj_t *lv_8ms_get_widget(char *w_name)
{
    int i = 0, j = 0;

    for (i = 0; i < (sizeof(g_screens) / sizeof(g_screens[0])); i++)
    {
        for (j = 0; j <  g_screens[i].len; j++)
        {
            if (!strcmp(w_name, g_screens[i].wids[j].name))
            {
                return *(g_screens[i].wids[j].id);
            }
        }
    }

    return NULL;
}

const char *lv_8ms_get_obj_name(lv_obj_t *obj)
{
    if (!obj) {
        return NULL;
    }

    int i = 0, j = 0;
    for (i = 0; i < (sizeof(g_screens) / sizeof(g_screens[0])); i++)
    {
        if (*(g_screens[i].id) == obj) {
            return g_screens[i].name;
        }

        for (j = 0; j <  g_screens[i].len; j++)
        {
            if (*(g_screens[i].wids[j].id) == obj)
            {
                return g_screens[i].wids[j].name;
            }
        }
    }

    return NULL;
}
