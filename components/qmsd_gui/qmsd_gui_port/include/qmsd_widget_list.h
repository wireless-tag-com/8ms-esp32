/**
 * @file qmsd_widget_list.h
 * @author sk (shuke@wireless-tag.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef _QMSD_WIDGET_LIST_H_
#define _QMSD_WIDGET_LIST_H_

#include "base_widget_type.h"

#ifdef __cplusplus
extern "C" {
#endif
typedef enum{
    QMSD_LIST_IMG_FIRST,
    QMSD_LIST_IMG_LAST,
} qmsd_list_img_pos_t;

qmsd_widget_t* qmsd_widget_list_create(qmsd_widget_t* parent);

qmsd_widget_t* qmsd_widget_list_add_btn(qmsd_widget_t* list,const void* img_src,const char* txt,const void* img_src2);

qmsd_err_t qmsd_widget_list_free(qmsd_widget_t* list);

qmsd_err_t qmsd_widget_list_remove(qmsd_widget_t* list,uint16_t index);

uint16_t qmsd_widget_list_get_size(qmsd_widget_t* list);

uint16_t qmsd_widget_list_get_clicked_index(qmsd_widget_t* list);

char* qmsd_widget_list_get_clicked_text(qmsd_widget_t* list);


#ifdef __cplusplus
} /* extern "C" */
#endif
#endif // _QMSD_WIDGET_LIST_H_