#ifndef BLOCKLY_GPIO_H
#define BLOCKLY_GPIO_H

#ifdef __cplusplus
extern "C" {
#endif
/*********************
 *      INCLUDES
 *********************/

#include "driver/gpio.h"
#include "../lvgl_device.h"

/*********************
 *      DEFINES
 *********************/

#define GPIO_SEND_NUM 12
#define GPIO_RECV_NUM 4

/**********************
 *      TYPEDEFS
 **********************/

typedef enum
{
    LOW = 0,
    HIGH
}gpio_action_t;

typedef enum
{ 
    OUTPUT = 0,
    OUTPUT_OD,
    INPUT_PULLUP,
    INPUT_PULLDOWN,
    INPUT_FLOATING
}gpio_pinmode_t;

typedef enum
{
    PINMODE = 0,
    DIGITALREAD,
    DIGITALWRITE
}gpio_func;

typedef struct 
{
    unsigned char ID;
    gpio_num_t gpio_num;
    gpio_pinmode_t mode;
    gpio_action_t level;
}device_gpio;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

QueueHandle_t gpioQueueSend;
QueueHandle_t gpioQueueReceive;

/**********************
 *      MACROS
 **********************/

void pinMode(gpio_num_t gpio_num, gpio_pinmode_t mode);
char digitalRead(gpio_num_t gpio_num);
void digitalWrite(gpio_num_t gpio_num, gpio_action_t level);
void pinInit(void);
void pinLoop(void);


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*LV_TUTORIAL_HELLO_WORLD_H*/
