#ifndef ESP32_DEVICE_H
#define ESP32_DEVICE_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      DEFINES
 *********************/

#include "RTE.h"

#include "esp_log.h"            // log库
#include "esp_err.h"
#include "freertos/FreeRTOS.h"  // freeRTOS库
#include "freertos/task.h"
#include "freertos/queue.h"
#include "freertos/semphr.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




#ifdef ESP32_GPIO
#include "esp32_gpio/blockly_gpio.h"
#endif

#ifdef ESP32_TIMER
#include "esp32_timer/blockly_timer.h"
#endif

#ifdef ESP32_UART
#include "esp32_uart/blockly_uart.h"
#endif

#endif



#ifdef __cplusplus
} /* extern "C" */
#endif
