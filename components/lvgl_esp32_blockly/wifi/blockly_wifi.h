/**
 * @file blockly_wifi.h
 */

#ifndef BLOCKLY_WIFI_H
#define BLOCKLY_WIFI_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event.h"

/**********************
 *      TYPEDEFS
 **********************/
extern bool gl_sta_connected;

/**********************
 * GLOBAL PROTOTYPES
 **********************/
void blockly_wifi_init();
void blockly_wifi_loop();
void wifi_callback_again();

/**********************
 *      MACROS
 **********************/


#ifdef __cplusplus
} /* extern "C" */

#endif /* BLOCKLY_WIFI_H */

#endif