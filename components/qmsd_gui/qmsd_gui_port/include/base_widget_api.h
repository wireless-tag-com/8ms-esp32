/**
 * @file base_widget_api.h
 *
 */

#ifndef BASE_WIDGET_API_H
#define BASE_WIDGET_API_H

#include "qmsd_gui_obj.h"
#include "qmsd_top_gui.h"

#ifdef __cplusplus
extern "C" {
#endif

qmsd_widget_t* qmsd_screen_create();

/**
 * @brief delete a selected widget or screen,node with this wodget won't be removed
 * 
 * @param widget 
 * @return qmsd_err_t 
 */
qmsd_err_t qmsd_widget_del(qmsd_widget_t* widget);

/**
 * @brief Switch to a screen
 * 
 * @param widget 
 * @return qmsd_err_t 
 */
qmsd_err_t qmsd_widget_switch(qmsd_widget_t* widget);

/**
 * @brief set x 
 * 
 * @param widget 
 * @param x 
 * @return qmsd_err_t 
 */
qmsd_err_t qmsd_widget_set_x(qmsd_widget_t* widget,int16_t x);

/**
 * @brief set y
 * 
 * @param widget 
 * @param y 
 * @return qmsd_err_t 
 */
qmsd_err_t qmsd_widget_set_y(qmsd_widget_t* widget,int16_t y);

/**
 * @brief set widget pos
 * 
 * @param widget 
 * @param x 
 * @param y 
 * @return qmsd_err_t 
 */
qmsd_err_t qmsd_widget_set_pos(qmsd_widget_t* widget,int16_t x,int16_t y);

/**
 * @brief set widget width
 * 
 * @param widget 
 * @param w 
 * @return qmsd_err_t 
 */
qmsd_err_t qmsd_widget_set_w(qmsd_widget_t* widget,int16_t w);

/**
 * @brief set widget height
 * 
 * @param widget 
 * @param h 
 * @return qmsd_err_t 
 */
qmsd_err_t qmsd_widget_set_h(qmsd_widget_t* widget,int16_t h);

/**
 * @brief set widget size
 * 
 * @param widget 
 * @param w 
 * @param h 
 * @return qmsd_err_t 
 */
qmsd_err_t qmsd_widget_set_size(qmsd_widget_t* widget,int16_t w,int16_t h);

/**
 * @brief set hidden
 * 
 * @param widget 
 * @param hide true:hide flase:show
 * @return qmsd_err_t 
 */
qmsd_err_t qmsd_widget_set_hidden(qmsd_widget_t* widget,bool hide);

/**
 * @brief Enable widget click
 * 
 * @param widget 
 * @param clickable 
 * @return qmsd_err_t 
 */
qmsd_err_t qmsd_widget_set_clickable(qmsd_widget_t* widget,bool clickable);

/**
 * @brief Enable widget dragable
 * 
 * @param widget 
 * @param dragable 
 * @return qmsd_err_t 
 */
qmsd_err_t qmsd_widget_set_dragable(qmsd_widget_t* widget,bool dragable);

/**
 * @brief set state of widget
 * 
 * @param widget 
 * @param state 
 * @return qmsd_err_t 
 */
qmsd_err_t qmsd_widget_set_state(qmsd_widget_t* widget,qmsd_state_t state);

/**
 * @brief redraw
 * 
 * @param widget 
 * @return qmsd_err_t 
 */
qmsd_err_t qmsd_widget_refresh(qmsd_widget_t* widget);

/**
 * @brief get the x coord of widget's central point

 * 
 * @param obj 
 * @return int 
 */
int16_t qmsd_obj_get_x_ori(lv_obj_t* obj);

/**
 * @brief set the coord of widget
 * 
 * @param obj 
 * @param x 
 * @param y 
 */
void qmsd_obj_set_pos_ori(lv_obj_t* obj,int x,int y);

void qmsd_gui_handle();

/**
 * @brief align start
 * 
 */
#if defined QMSD_GUI_LVGL_V7
    
typedef enum {
    QMSD_ALIGN_CENTER = 0,
    QMSD_ALIGN_IN_TOP_LEFT,
    QMSD_ALIGN_IN_TOP_MID,
    QMSD_ALIGN_IN_TOP_RIGHT,
    QMSD_ALIGN_IN_BOTTOM_LEFT,
    QMSD_ALIGN_IN_BOTTOM_MID,
    QMSD_ALIGN_IN_BOTTOM_RIGHT,
    QMSD_ALIGN_IN_LEFT_MID,
    QMSD_ALIGN_IN_RIGHT_MID,
    QMSD_ALIGN_OUT_TOP_LEFT,
    QMSD_ALIGN_OUT_TOP_MID,
    QMSD_ALIGN_OUT_TOP_RIGHT,
    QMSD_ALIGN_OUT_BOTTOM_LEFT,
    QMSD_ALIGN_OUT_BOTTOM_MID,
    QMSD_ALIGN_OUT_BOTTOM_RIGHT,
    QMSD_ALIGN_OUT_LEFT_TOP,
    QMSD_ALIGN_OUT_LEFT_MID,
    QMSD_ALIGN_OUT_LEFT_BOTTOM,
    QMSD_ALIGN_OUT_RIGHT_TOP,
    QMSD_ALIGN_OUT_RIGHT_MID,
    QMSD_ALIGN_OUT_RIGHT_BOTTOM,
} qmsd_align_t;

#elif defined QMSD_GUI_LVGL_V8
typedef enum {
    QMSD_ALIGN_IN_TOP_LEFT = 1,
    QMSD_ALIGN_IN_TOP_MID,
    QMSD_ALIGN_IN_TOP_RIGHT,
    QMSD_ALIGN_IN_BOTTOM_LEFT,
    QMSD_ALIGN_IN_BOTTOM_MID,
    QMSD_ALIGN_IN_BOTTOM_RIGHT,
    QMSD_ALIGN_IN_LEFT_MID,
    QMSD_ALIGN_IN_RIGHT_MID,
    QMSD_ALIGN_CENTER,
    QMSD_ALIGN_OUT_TOP_LEFT,
    QMSD_ALIGN_OUT_TOP_MID,
    QMSD_ALIGN_OUT_TOP_RIGHT,
    QMSD_ALIGN_OUT_BOTTOM_LEFT,
    QMSD_ALIGN_OUT_BOTTOM_MID,
    QMSD_ALIGN_OUT_BOTTOM_RIGHT,
    QMSD_ALIGN_OUT_LEFT_TOP,
    QMSD_ALIGN_OUT_LEFT_MID,
    QMSD_ALIGN_OUT_LEFT_BOTTOM,
    QMSD_ALIGN_OUT_RIGHT_TOP,
    QMSD_ALIGN_OUT_RIGHT_MID,
    QMSD_ALIGN_OUT_RIGHT_BOTTOM,
} qmsd_align_t;
#endif

void qmsd_widget_align(qmsd_widget_t* obj,qmsd_align_t align,int16_t ofs_x,int16_t osf_y);

void qmsd_widget_align_to(qmsd_widget_t* obj,qmsd_widget_t* base,qmsd_align_t align,int16_t ofs_x,int16_t osf_y);


/**
 * @brief event start
 * 
 */
#if defined QMSD_GUI_LVGL_V7

#define qmsd_def_port_cb( id ) \
void __qmsd_##id##_cb(lv_obj_t* obj,qmsd_event_t event); \
static inline void qmsd_##id##_port_cb(lv_obj_t* obj , lv_event_t event) \
{ \
    __qmsd_##id##_cb(obj,event); \
} 

#define qmsd_widget_set_port_cb(id) lv_obj_set_event_cb(id##_obj.widget,qmsd_##id##_port_cb)

#define qmsd_widget_set_cb(id , cb , event , user_data) lv_obj_set_event_cb(id,cb)

#elif defined QMSD_GUI_LVGL_V8

#define qmsd_def_port_cb( id ) \
void __qmsd_##id##_cb(lv_obj_t* obj,qmsd_event_t event); \
static inline void qmsd_##id##_port_cb(lv_event_t* event) \
{ \
    __qmsd_##id##_cb(event->target,event->code); \
} 

#define qmsd_widget_set_port_cb(id) lv_obj_add_event_cb(id##_obj.widget,qmsd_##id##_port_cb,LV_EVENT_ALL,NULL)

#define qmsd_widget_set_cb(id , cb , event , user_data) lv_obj_set_event_cb(id,cb,event,user_data)

#endif

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*BASE_WIDGET_API_H*/
