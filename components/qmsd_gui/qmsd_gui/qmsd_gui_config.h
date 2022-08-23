/**
 * @file qmsd_gui_config.h
 *
 */
#ifndef QMSD_GUI_CONFIG_H
#define QMSD_GUI_CONFIG_H
#include "sdkconfig.h"
#ifdef __cplusplus
extern "C" {
#endif

#define QMSD_LVGL_ADDON_VERSION "2.0" 

#ifdef CONFIG_QMSD_GUI_LVGL_V7
#define QMSD_GUI_LVGL_V7
#elif defined CONFIG_QMSD_GUI_LVGL_V8
#define QMSD_GUI_LVGL_V8
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*QMSD_GUI_CONFIG_H*/
