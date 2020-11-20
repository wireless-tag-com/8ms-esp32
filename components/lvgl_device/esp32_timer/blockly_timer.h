#ifndef BLOCKLY_TIMER_H
#define BLOCKLY_TIMER_H

#ifdef __cplusplus
extern "C" {
#endif
/*********************
 *      INCLUDES
 *********************/

#include "esp_timer.h"
#include "../lvgl_device.h"

/*********************
 *      DEFINES
 *********************/

#define TIMER_SEND_NUM  4

/**********************
 *      TYPEDEFS
 **********************/
typedef enum 
{
    once = 0,
    periodic

}timer_mode;

typedef struct 
{
    esp_timer_cb_t callback;
    uint64_t timeout_us;
    timer_mode mode;
}device_timer;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

QueueHandle_t timerQueueSend;

/**********************
 *      MACROS
 **********************/

void timerBegin(uint64_t timeout_us, timer_mode mode, esp_timer_cb_t call_back);
void timerInit(void);
void timerLoop(void);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif