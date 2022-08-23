/**
 * @file base_widget_api.h
 *
 */

#ifndef QMSD_WIDGET_TYPE_H
#define QMSD_WIDGET_TYPE_H

#include "qmsd_err.h"
#include "lvgl.h"
#include "qmsd_gui_config.h"
#ifdef __cplusplus
extern "C" {
#endif

typedef enum 
{
    QMSD_WIDGET_UNKNOWN,
    QMSD_WIDGET_TABVIEW,
    QMSD_WIDGET_TILEVIEW,
    QMSD_WIDGET_CONTLINK,
    __QMSD_WIDGET_WITH_EXT_SCREEN,
    QMSD_WIDGET_LABEL,
    QMSD_WIDGET_BUTTON,
    QMSD_WIDGET_IMAGE,
    QMSD_WIDGET_IMAGE_BUTTON,
    QMSD_WIDGET_SLIDER,
    QMSD_WIDGET_CHECKBOX,
    QMSD_WIDGET_SWITCH,
    QMSD_WIDGET_BAR,
    QMSD_WIDGET_LIST,
    QMSD_WIDGET_ARC,
    QMSD_WIDGET_CALENDAR,
    QMSD_WIDGET_DROPDOWN,
    QMSD_WIDGET_GAUGE,
    QMSD_WIDGET_LED,
    QMSD_WIDGET_MSGBOX,
    QMSD_WIDGET_PRELOADER,
    QMSD_WIDGET_ROLLSELECTER,
    QMSD_WIDGET_TEXTAREA,
    QMSD_WIDGET_LINE,
    QMSD_WIDGET_PAGE,
    QMSD_WIDGET_CLOCK,
    QMSD_WIDGET_CHART,
    QMSD_WIDGET_TAPBOARD,
    QMSD_WIDGET_CONTAINER,
} qmsd_widget_type_t;

typedef enum 
{
    QMSD_SCREEN_TYPE_SCREEN = 0x80,
    QMSD_SCREEN_TYPE_TILE,
    QMSD_SCREEN_TYPE_TAB,
    QMSD_SCREEN_TYPE_SUBSCREEN,
} qmsd_screen_type_t;

typedef lv_obj_t qmsd_widget_t;
typedef struct _qmsd_ui_widget_t qmsd_gui_widget_t;
typedef struct _qmsd_ui_screen_t qmsd_gui_screen_t;

typedef int (*qmsd_widget_func)( qmsd_gui_widget_t* widget,void* data);
typedef int (*qmsd_screen_func)( qmsd_gui_screen_t* screen,void* data);

typedef struct _qmsd_ui_widget_t
{
    qmsd_widget_t* widget;
    char* name;
    qmsd_widget_type_t type;
    qmsd_widget_func build;
    qmsd_widget_func ctrl_cb;
    struct _qmsd_widget_node* child;
    struct _qmsd_widget_node* ext_element;

    char* value_subscribe;
} qmsd_gui_widget_t;

typedef struct _qmsd_ui_screen_t
{
    qmsd_widget_t* screen;
    char* name;
    qmsd_screen_type_t type;
    qmsd_screen_func build;
    qmsd_screen_func ctrl_cb;
    struct _qmsd_widget_node* child;

    qmsd_screen_func prebuild_cb;
    qmsd_screen_func built_cb;
    qmsd_screen_func show;
    qmsd_screen_func remove;
} qmsd_gui_screen_t;

typedef lv_color_t qmsd_color_t;

typedef lv_img_dsc_t qmsd_img_bitmap_t;
typedef lv_font_t qmsd_font_bitmap_t;

typedef struct
{
    char *name;
    const qmsd_img_bitmap_t* img;
} qmsd_img_t;

typedef struct
{
    char *name;
    const qmsd_font_bitmap_t* font;
} qmsd_font_t;


enum {
    QMSD_PART_MAIN         = 0x000000,   /**< A background like rectangle*/
    QMSD_PART_SCROLLBAR    = 0x010000,   /**< The scrollbar(s)*/
    QMSD_PART_INDICATOR    = 0x020000,   /**< Indicator, e.g. for slider, bar, switch, or the tick box of the checkbox*/
    QMSD_PART_KNOB         = 0x030000,   /**< Like handle to grab to adjust the value*/
    QMSD_PART_SELECTED     = 0x040000,   /**< Indicate the currently selected option or section*/
    QMSD_PART_ITEMS        = 0x050000,   /**< Used if the widget has multiple similar elements (e.g. table cells)*/
    QMSD_PART_TICKS        = 0x060000,   /**< Ticks on scale e.g. for a chart or meter*/
    QMSD_PART_CURSOR       = 0x070000,   /**< Mark a specific place e.g. for text area's cursor or on a chart*/

    QMSD_PART_CUSTOM_FIRST = 0x080000,    /**< Extension point for custom widgets*/

    QMSD_PART_ANY          = 0x0F0000,    /**< Special value can be used in some functions to target all parts*/
};

typedef int16_t qmsd_event_t;

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*QMSD_WIDGET_TYPE_H*/
