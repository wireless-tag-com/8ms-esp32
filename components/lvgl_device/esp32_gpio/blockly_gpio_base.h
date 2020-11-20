#ifndef BLOCK_GPIO_BASE_H
#define BLOCK_GPIO_BASE_H

#ifdef __cplusplus
extern "C" {
#endif
/*********************
 *      INCLUDES
 *********************/

#include "blockly_gpio.h"


/*********************
 *      DEFINES
 *********************/



/**********************
 *      TYPEDEFS
 **********************/



/**********************
 * GLOBAL PROTOTYPES
 **********************/



/**********************
 *      MACROS
 **********************/

void __pinMode(gpio_num_t gpio_num, gpio_pinmode_t mode);
gpio_action_t __digitalRead(gpio_num_t gpio_num);
void __digitalWrite(gpio_num_t gpio_num, gpio_action_t level);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif