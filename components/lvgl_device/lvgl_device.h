#ifndef LVGL_DEVICE_H
#define LVGL_DEVICE_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      DEFINES
 *********************/

#include "RTE.h"                // 宏定义裁剪库

#ifdef ESP32_DEVICE
#include "esp32_device.h"       // esp32库
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif