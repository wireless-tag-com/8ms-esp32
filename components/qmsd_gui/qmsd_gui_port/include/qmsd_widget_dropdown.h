/**
 * @file qmsd_widget_dropdown.h
 * @author sk (shuke@wireless-tag.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef _QMSD_WIDGET_DROPDOWN_H_
#define _QMSD_WIDGET_DROPDOWN_H_

#include "base_widget_type.h"

#ifdef __cplusplus
extern "C" {
#endif

qmsd_widget_t* qmsd_widget_dropdown_create(qmsd_widget_t* parent);

qmsd_err_t qmsd_widget_dropdown_set_options(qmsd_widget_t* dropdown , const char* options);

qmsd_err_t qmsd_widget_dropdown_set_text(qmsd_widget_t* dropdown,const char* txt);

qmsd_err_t qmsd_widget_dropdown_set_height(qmsd_widget_t* dropdown,uint16_t height);

qmsd_err_t qmsd_widget_dropdown_set_selected(qmsd_widget_t* dropdown,uint16_t index);

uint16_t qmsd_widget_dropdown_get_selected(qmsd_widget_t* dropdown);

uint16_t qmsd_widget_dropdown_get_selected_str(qmsd_widget_t* dropdown , char * buf, uint32_t buf_size);

#ifdef __cplusplus
} /* extern "C" */
#endif
#endif // _QMSD_WIDGET_DROPDOWN_H_