/**
 * @file qmsd_gui_obj.h
 *
 */

#ifndef QMSD_OBJ_H
#define QMSD_OBJ_H

#include "lvgl.h"
#include "qmsd_err.h"
#include "qmsd_gui_objll.h"
#include "base_widget_type.h"
#include "qmsd_widget_style.h"

#ifdef __cplusplus
extern "C" {
#endif

bool qmsd_widget_is_screen(void * obj);

/**
 * @brief create a screen 
 * 
 * @param screen qmsd screen object
 * @param load need to be loaded right now or not
 * @return qmsd_err_t 
 */
qmsd_err_t qmsd_screen_build(qmsd_gui_screen_t* screen,bool load);

/**
 * @brief delete screen in struct struct will not be free
 * 
 * @param screen 
 * @return qmsd_err_t 
 */
qmsd_err_t qmsd_screen_delete(qmsd_gui_screen_t* screen);
qmsd_gui_screen_t* qmsd_gui_search_screen(char* screen_id);
qmsd_gui_widget_t* qmsd_gui_search_widget(char* id);
bool qmsd_gui_is_screen_built(qmsd_gui_screen_t* screen);
qmsd_err_t _qmsd_screen_build_core(qmsd_gui_screen_t* screen);
#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*QMSD_OBJ_H*/
