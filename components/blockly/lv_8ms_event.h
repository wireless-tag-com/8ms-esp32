#ifndef EVENT_SOURCE_H_
#define EVENT_SOURCE_H_

#include "esp_event.h"
#include "esp_timer.h"
#include "esp_event_base.h"
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
#ifdef __cplusplus
extern "C" {
#endif

void lv_8ms_event_handle_init(void);
int lv_8ms_event_handler_register(int32_t event_id, esp_event_handler_t event_handler);
int lv_8ms_event_post_to(int32_t event_id, void *event_data, size_t event_data_size, TickType_t ticks_to_wait);

enum {
    LV_8MS_GPIO_PULL_UP,
    LV_8MS_GPIO_PULL_DOWN
};

#ifdef __cplusplus
}
#endif

#endif // #ifndef EVENT_SOURCE_H_