#ifndef BLOCKLY_GPIO_H
#define BLOCKLY_GPIO_H

#ifdef __cplusplus
extern "C"
{
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
        LV_8MS_GPIO_LOW = 0,
        LV_8MS_GPIO_HIGH
    } lv_8ms_gpio_level_t;

    typedef enum
    {
        LV_8MS_GPIO_OUT = 0,
        LV_8MS_GPIO_OUT_OD,
        LV_8MS_GPIO_IN_UP,
        LV_8MS_GPIO_IN_DOWN,
        LV_8MS_GPIO_IN_FLOATING
    } lv_8ms_gpio_dir_t;

    typedef enum
    {
        PINMODE = 0,
        DIGITALREAD,
        DIGITALWRITE
    } gpio_func;

    typedef struct
    {
        unsigned char ID;
        gpio_num_t gpio_num;
        lv_8ms_gpio_dir_t mode;
        lv_8ms_gpio_level_t level;
    } device_gpio;

    /**********************
     * GLOBAL PROTOTYPES
     **********************/

    QueueHandle_t gpioQueueSend;
    QueueHandle_t gpioQueueReceive;

    /**********************
     *      MACROS
     **********************/

    void lv_8ms_gpio_init(gpio_num_t gpio_num, lv_8ms_gpio_dir_t mode);
    char lv_8ms_gpio_read(gpio_num_t gpio_num);
    void lv_8ms_gpio_write(gpio_num_t gpio_num, lv_8ms_gpio_level_t level);
    void lv_8ms_gpio_setup(void);
    void lv_8ms_gpio_loop(void);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*LV_TUTORIAL_HELLO_WORLD_H*/
