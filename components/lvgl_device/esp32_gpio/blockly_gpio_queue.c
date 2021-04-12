#include "blockly_gpio_base.h"
#include "../gc/gc.h"

#define TAG "GPIO_QUEUE" // log输出的标签

/**
* @brief 初始化外设线程用到的消息，此函数位于外设事件线程
*/

void lv_8ms_gpio_setup(void)
{
    void *bos = __builtin_frame_address(0);
    gc_start(&gc, bos);
    gpioQueueSend = xQueueCreate(GPIO_SEND_NUM, sizeof(device_gpio));
    gpioQueueReceive = xQueueCreate(GPIO_RECV_NUM, sizeof(device_gpio));
}

/**
* @brief 设置修改模式的消息
* @param gpio_num 引脚编号，注意有些引脚功能不完全，详见 @ref gpio_num_t
* @param mode 引脚模式，有输出两种，输入三种，详见 @ref lv_8ms_gpio_dir_t
*/

void lv_8ms_gpio_init(gpio_num_t gpio_num, lv_8ms_gpio_dir_t mode)
{
    device_gpio *send = (device_gpio *)gc_malloc(&gc, sizeof(device_gpio));
    send->mode = mode;
    send->gpio_num = gpio_num;
    send->ID = PINMODE;
    if (gpioQueueSend != 0)
    {
        ESP_LOGI(TAG, "lv_8ms_gpio_init gpioQueueSend is ok!\n");
        xQueueSend(gpioQueueSend, (void *)&send, (TickType_t)0);
    }
}

/** 
* @brief 设置读取引脚电平的消息
* @param gpio_num 引脚编号，注意有些引脚功能不完全，详见 @ref gpio_num_t
* @return 返回高低电平，LOW 或者 HIGH，如果错误会返回-1
*/

char lv_8ms_gpio_read(gpio_num_t gpio_num)
{
    device_gpio *send = (device_gpio *)gc_malloc(&gc, sizeof(device_gpio));
    send->gpio_num = gpio_num;
    send->ID = DIGITALREAD;
    if (gpioQueueSend != 0)
    {
        ESP_LOGI(TAG, "Read gpioQueueSend is ok!\n");
        xQueueSend(gpioQueueSend, (void *)&send, (TickType_t)0);
    }
    /***************************************************
     *                      读取消息
     **************************************************/
    device_gpio *receive;
    if (gpioQueueReceive != 0)
    {
        if (xQueueReceive(gpioQueueReceive, (void *)&receive, (TickType_t)20))
        {
            ESP_LOGI(TAG, "Read gpioQueueReceive is ok!\n");
            if (receive->ID == DIGITALREAD)
            {
                ESP_LOGI(TAG, "receive is %d\n", receive->level);
                char pinLevel = receive->level;
                gc_free(&gc, receive);
                return pinLevel;
            }
            gc_free(&gc, receive);
        }
    }
    return -1;
}

/**
* @brief 设置写入电平的消息
* @param gpio_num 引脚编号，注意有些引脚功能不完全，详见 @ref gpio_num_t 
* @param level 引脚电平的高低，LOW或者HIGH，详见 @ref lv_8ms_gpio_level_t
*/
void lv_8ms_gpio_write(gpio_num_t gpio_num, lv_8ms_gpio_level_t level)
{
    ESP_LOGI(TAG, "Write gpioQueueSend is begin!\n");
    device_gpio *send = (device_gpio *)gc_malloc(&gc, sizeof(device_gpio));
    send->level = level;
    send->gpio_num = gpio_num;
    send->ID = DIGITALWRITE;
    if (gpioQueueSend != 0)
    {
        ESP_LOGI(TAG, "Write gpioQueueSend is ok!\n");
        xQueueSend(gpioQueueSend, (void *)&send, (TickType_t)0);
    }
}

/**
* @brief 轮询接受消息，当接收到消息后，完成相应的函数响应，此函数位于外设事件线程
*/

void lv_8ms_gpio_loop(void)
{
    char pinLevel;
    device_gpio *receive;
    if (gpioQueueSend != 0)
    {
        if (xQueueReceive(gpioQueueSend, (void *)&receive, (TickType_t)10))
        {
            ESP_LOGI(TAG, "lv_8ms_gpio_loop gpioQueueSend is ok!\n");
            switch (receive->ID)
            {
            case PINMODE:
                ESP_LOGI(TAG, "PIN_MODE_OUTPUT!\n");
                __lv_8ms_gpio_init(receive->gpio_num, receive->mode);
                break;
            case DIGITALREAD:
                ESP_LOGI(TAG, "DIGITALREAD!\n");
                pinLevel = __lv_8ms_gpio_read(receive->gpio_num);
                device_gpio *recv = (device_gpio *)gc_malloc(&gc, sizeof(device_gpio));
                recv->level = pinLevel;
                recv->ID = DIGITALREAD;
                if (gpioQueueReceive != 0)
                {
                    ESP_LOGI(TAG, "lv_8ms_gpio_loop gpioQueueReceive is ok!\n");
                    xQueueSend(gpioQueueReceive, (void *)&recv, (TickType_t)0);
                }
                break;
            case DIGITALWRITE:
                ESP_LOGI(TAG, "DIGITALWRITE!\n");
                __lv_8ms_gpio_write(receive->gpio_num, receive->level);
                break;
            default:
                ESP_LOGI(TAG, "default!\n");
                break;
            }
            gc_free(&gc, receive);
        }
    }
}
