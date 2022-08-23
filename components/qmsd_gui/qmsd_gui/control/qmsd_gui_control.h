/**
 * @file qmsd_gui_control.h
 *
 */

#ifndef QMSD_GUI_CONTROL_H
#define QMSD_GUI_CONTROL_H

#include "qmsd_err.h"
#include "base_widget_type.h"
#include "cJSON.h"
#ifdef __cplusplus
extern "C" {
#endif

#define QMSD_CTRL_WID_NAME		"wid"
#define QMSD_CTRL_CMD_NAME		"cmd"
#define QMSD_CTRL_ATTR_NAME	    "attr"

#define QMSD_GUI_CTRL_CMD_SET_PUBLIC        "set_public"
#define QMSD_GUI_CTRL_CMD_SET_PRIVATE       "set_private"
#define QMSD_GUI_CTRL_CMD_SET_STYLE         "set_style"
#define QMSD_GUI_CTRL_CMD_SEND_EVENT        "send_event"
#define QMSD_GUI_CTRL_CMD_CALL_UPDATE       "call_update"
#define QMSD_GUI_CTRL_CMD_GET               "get"

//action list of set_public
#define QMSD_GUI_ACTION_SET_X                   "set_x"
#define QMSD_GUI_ACTION_SET_Y                   "set_y"
#define QMSD_GUI_ACTION_SET_POS                 "set_pos"
#define QMSD_GUI_ACTION_SET_W                   "set_w"
#define QMSD_GUI_ACTION_SET_H                   "set_h"
#define QMSD_GUI_ACTION_SET_SIZE                "set_size"
#define QMSD_GUI_ACTION_SET_HIDDEN              "set_hidden"
#define QMSD_GUI_ACTION_SET_CLICK               "set_click"
#define QMSD_GUI_ACTION_SET_DRAG                "set_drag"
#define QMSD_GUI_ACTION_SET_STATE               "set_state"
#define QMSD_GUI_ACTION_REFRESH                 "refresh"
#define QMSD_GUI_ACTION_UPDATE                  "update"

//action list of set_public

#define QMSD_GUI_ACTION_SET_BG_COLOR            "bg_color"
#define QMSD_GUI_ACTION_SET_BG_OPA              "bg_opa"
#define QMSD_GUI_ACTION_SET_LINE_COLOR          "line_color"
#define QMSD_GUI_ACTION_SET_LINE_OPA            "line_opa"
#define QMSD_GUI_ACTION_SET_LINE_WIDTH          "line_width"
#define QMSD_GUI_ACTION_SET_TEXT_COLOR          "text_color"
#define QMSD_GUI_ACTION_SET_TEXT_OPA            "text_opa"
#define QMSD_GUI_ACTION_SET_TEXT_FONT           "text_font"
#define QMSD_GUI_ACTION_SET_BORDER_COLOR        "border_color"
#define QMSD_GUI_ACTION_SET_BORDER_OPA          "border_opa"
#define QMSD_GUI_ACTION_SET_BORDER_WIDTH        "border_width"
#define QMSD_GUI_ACTION_SET_OUTLINE_COLOR       "outline_color"
#define QMSD_GUI_ACTION_SET_OUTLINE_OPA         "outline_opa"
#define QMSD_GUI_ACTION_SET_OUTLINE_WIDTH       "outline_width"
#define QMSD_GUI_ACTION_SET_IMAGE_OPA           "image_opa"
#define QMSD_GUI_ACTION_SET_IMAGE_RECOLOR       "image_recolor"
#define QMSD_GUI_ACTION_SET_IMAGE_RECOLOR_OPA   "image_recolor_opa"
#define QMSD_GUI_ACTION_SET_PAD_LEFT            "pad_left"
#define QMSD_GUI_ACTION_SET_PAD_RIGHT           "pad_right"
#define QMSD_GUI_ACTION_SET_PAD_TOP             "pad_top"
#define QMSD_GUI_ACTION_SET_PAD_BOTTOM          "pad_bottom"

//private action list
//SCREEN 
#define QMSD_GUI_ACTION_SCREEN_SWITCH           "switch"
#define QMSD_GUI_ACTION_SCREEN_REMOVE           "remove"
//ARC
#define QMSD_GUI_ACTION_ARC_SET_ANGLES          "set_angles"
#define QMSD_GUI_ACTION_ARC_SET_OFFSET          "set_offset"
#define QMSD_GUI_ACTION_ARC_SET_VALUE           "set_value"
#define QMSD_GUI_ACTION_ARC_SET_RANGE           "set_range"
//BAR
#define QMSD_GUI_ACTION_BAR_SET_VALUE           "set_value"
#define QMSD_GUI_ACTION_BAR_SET_RANGE           "set_range"
//BUTTON

//CALENDAR
#define QMSD_GUI_ACTION_CALENDAR_SET_DATE       "set_date"
#define QMSD_GUI_ACTION_CALENDAR_FOCUS_DATA     "focus_date"
//CHART

//CHECKBOX
#define QMSD_GUI_ACTION_CHECKBOX_TOGGLE        "toggle"
#define QMSD_GUI_ACTION_CHECKBOX_SET_TEXT       "set_text"
//CONTAINER

//DROPDOWN
#define QMSD_GUI_ACTION_DROPDOWN_SET_SELECTED   "set_selected"
//GAUGE
#define QMSD_GUI_ACTION_GAUGE_SET_VALUE         "set_value"
//IMAGE
#define QMSD_GUI_ACTION_IMAGE_SET_SRC           "set_src"
#define QMSD_GUI_ACTION_IMAGE_SET_ROTATION      "set_rotation"
#define QMSD_GUI_ACTION_IMAGE_SET_ZOOM          "set_zoom"
//LABEL
#define QMSD_GUI_ACTION_LABEL_SET_TEXT          "set_text"
//LED
#define QMSD_GUI_ACTION_LED_TOGGLE              "toggle"
#define QMSD_GUI_ACTION_LED_SET_BRIGHT          "set_bright"
//LINE

//LIST

//MSGBOX

//PRELOADER

//ROLLER

//SLIDER
#define QMSD_GUI_ACTION_SLIDER_SET_VALUE        "set_value"
#define QMSD_GUI_ACTION_SLIDER_SET_RANGE        "set_range"
//SWITCH
#define QMSD_GUI_ACTION_SWITCH_TOGGLE           "toggle"
//TABVIEW
#define QMSD_GUI_ACTION_TABVIEW_SWITCH          "switch"
#define QMSD_GUI_ACTION_TABVIEW_SWITCH_NEXT     "switch_next"
#define QMSD_GUI_ACTION_TABVIEW_SWITCH_PREVIOUS "switch_previous"
//TEXTAREA
#define QMSD_GUI_ACTION_TEXTAREA_SET_TEXT       "set_text"
//TILEVIEW
#define QMSD_GUI_ACTION_TILEVIEW_SWITCH         "switch"



typedef enum{
    QMSD_GUI_CTRL_DIRECTLY,     // Can only be called in gui own task
    QMSD_GUI_CTRL_QUEUE,    //Send a msg from other task into gui task which will get handled in next period   
    QMSD_GUI_CTRL_FORCED,   //Force task keep waiting and make the changes right now
} qmsd_gui_ctrl_mode_t;

qmsd_err_t qmsd_gui_notifer_valuechange_cb(char* key,void* data);

qmsd_err_t qmsd_gui_ctrl_entry(char* json_str,qmsd_gui_ctrl_mode_t mode);

qmsd_err_t qmsd_gui_ctrl_core(cJSON* root);

/**
 * @brief def screen cb start
 * 
 */
qmsd_err_t qmsd_ctrl_screen_def_cb(qmsd_gui_screen_t* screen,void* user_data);

qmsd_err_t qmsd_ctrl_tilescreen_def_cb(qmsd_gui_screen_t* screen,void* user_data);

qmsd_err_t qmsd_ctrl_tabscreen_def_cb(qmsd_gui_screen_t* screen,void* user_data);

qmsd_err_t qmsd_ctrl_subscreen_def_cb(qmsd_gui_screen_t* screen,void* user_data);

/**
 * @brief default widget cb start
 * 
 */

qmsd_err_t qmsd_ctrl_tabview_def_cb(qmsd_gui_widget_t* widget,void* user_data);

qmsd_err_t qmsd_ctrl_tileview_def_cb(qmsd_gui_widget_t* widget,void* user_data);

qmsd_err_t qmsd_ctrl_contlink_def_cb(qmsd_gui_widget_t* widget,void* user_data);

qmsd_err_t qmsd_ctrl_label_def_cb(qmsd_gui_widget_t* widget,void* user_data);

qmsd_err_t qmsd_ctrl_button_def_cb(qmsd_gui_widget_t* widget,void* user_data);

qmsd_err_t qmsd_ctrl_image_def_cb(qmsd_gui_widget_t* widget,void* user_data);

qmsd_err_t qmsd_ctrl_image_button_def_cb(qmsd_gui_widget_t* widget,void* user_data);

qmsd_err_t qmsd_ctrl_slider_def_cb(qmsd_gui_widget_t* widget,void* user_data);

qmsd_err_t qmsd_ctrl_checkbox_def_cb(qmsd_gui_widget_t* widget,void* user_data);

qmsd_err_t qmsd_ctrl_switch_def_cb(qmsd_gui_widget_t* widget,void* user_data);

qmsd_err_t qmsd_ctrl_bar_def_cb(qmsd_gui_widget_t* widget,void* user_data);

qmsd_err_t qmsd_ctrl_list_def_cb(qmsd_gui_widget_t* widget,void* user_data);

qmsd_err_t qmsd_ctrl_arc_def_cb(qmsd_gui_widget_t* widget,void* user_data);

qmsd_err_t qmsd_ctrl_calendar_def_cb(qmsd_gui_widget_t* widget,void* user_data);

qmsd_err_t qmsd_ctrl_dropdown_def_cb(qmsd_gui_widget_t* widget,void* user_data);

qmsd_err_t qmsd_ctrl_gauge_def_cb(qmsd_gui_widget_t* widget,void* user_data);

qmsd_err_t qmsd_ctrl_led_def_cb(qmsd_gui_widget_t* widget,void* user_data);

qmsd_err_t qmsd_ctrl_msgbox_def_cb(qmsd_gui_widget_t* widget,void* user_data);

qmsd_err_t qmsd_ctrl_preloader_def_cb(qmsd_gui_widget_t* widget,void* user_data);

qmsd_err_t qmsd_ctrl_rollselector_def_cb(qmsd_gui_widget_t* widget,void* user_data);

qmsd_err_t qmsd_ctrl_textarea_def_cb(qmsd_gui_widget_t* widget,void* user_data);

qmsd_err_t qmsd_ctrl_line_def_cb(qmsd_gui_widget_t* widget,void* user_data);

qmsd_err_t qmsd_ctrl_page_def_cb(qmsd_gui_widget_t* widget,void* user_data);

qmsd_err_t qmsd_ctrl_clock_def_cb(qmsd_gui_widget_t* widget,void* user_data);

qmsd_err_t qmsd_ctrl_chart_def_cb(qmsd_gui_widget_t* widget,void* user_data);

qmsd_err_t qmsd_ctrl_tapboard_def_cb(qmsd_gui_widget_t* widget,void* user_data);

qmsd_err_t qmsd_ctrl_container_def_cb(qmsd_gui_widget_t* widget,void* user_data);
#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*QMSD_GUI_CONTROL_H*/
