#ifndef BLOCK_GPIO_BASE_H
#define BLOCK_GPIO_BASE_H

#ifdef __cplusplus
extern "C"
{
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

    void __lv_8ms_gpio_init(gpio_num_t gpio_num, lv_8ms_gpio_dir_t mode);
    lv_8ms_gpio_level_t __lv_8ms_gpio_read(gpio_num_t gpio_num);
    void __lv_8ms_gpio_write(gpio_num_t gpio_num, lv_8ms_gpio_level_t level);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif