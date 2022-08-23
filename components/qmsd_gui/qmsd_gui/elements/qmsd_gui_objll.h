/**
 * @file qmsd_gui_objll.h
 *
 */

#ifndef qmsd_gui_objll_H
#define qmsd_gui_objll_H

#include "qmsd_err.h"
#include "qmsd_gui_obj.h"
#include "base_widget_type.h"
#ifdef __cplusplus
extern "C" {
#endif

typedef struct _qmsd_widget_node
{
    struct _qmsd_ui_widget_t* widget;
    struct _qmsd_widget_node* next;
} qmsd_widget_node;

typedef struct _qmsd_screen_node
{
    struct _qmsd_ui_screen_t* screen;
    struct _qmsd_screen_node* next;
    struct _qmsd_screen_node* previous;
} qmsd_screen_node;

extern qmsd_screen_node* g_screen_head;
/**
 * @brief init screen ll 
 * 
 * @return qmsd_err_t 
 */
qmsd_err_t qmsd_screen_ll_init(void);

/**
 * @brief confirm if the screen exist
 * 
 * @param screen 
 * @return qmsd_err_t 
 */
qmsd_err_t _qmsd_screen_node_confirm(qmsd_gui_screen_t* screen);

/**
 * @brief insert a screen into one new node
 * 
 * @param screen pointer to the qmsd_gui_screen_t screen
 * @return qmsd_err_t 
 */
qmsd_err_t qmsd_screen_ll_insert(qmsd_gui_screen_t* screen);

/**
 * @brief remove node with this screen from screen ll
 * 
 * @param screen pointer to the qmsd_gui_screen_t screen
 * @return qmsd_err_t 
 */
qmsd_err_t qmsd_screen_ll_remove(qmsd_gui_screen_t* screen);

/**
 * @brief insert widget to screens' child list or widgets' ext list
 * 
 * @param widget_node 
 * @param child 
 * @return qmsd_err_t 
 */
qmsd_err_t qmsd_widget_ll_insert(qmsd_widget_node** widget_node,qmsd_gui_widget_t* child);

qmsd_err_t _qmsd_widget_ll_build(qmsd_widget_node* widget_node);
#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*qmsd_gui_objll_H*/
