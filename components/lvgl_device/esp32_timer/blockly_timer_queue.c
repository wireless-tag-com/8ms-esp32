#include "blockly_timer_base.h"
#include "../gc/gc.h"

#define TAG "TIMER_QUEUE" // log输出的标签

/**
* @brief 初始化外设线程用到的消息，此函数位于外设事件线程
*/
void lv_8ms_timer_setup(void)
{
    timerQueueSend = xQueueCreate(TIMER_SEND_NUM, sizeof(device_timer));
}

/**
* @brief 设置定时器消息
* @param timeout_us 定时器的延时时长单位为微秒
* @param mode 定时器模式，有单次和循环两种，详见 @ref timer_mode
* @param call_back 回调函数，传入回调函数名字的地址
*/

void lv_8ms_timer_init(uint64_t timeout_us, timer_mode mode, esp_timer_cb_t call_back)
{
    device_timer *send = (device_timer *)gc_malloc(&gc, sizeof(device_timer));
    send->mode = mode;
    send->timeout_us = timeout_us;
    send->callback = call_back;
    if (timerQueueSend != 0)
    {
        ESP_LOGI(TAG, "Begin timerQueueSend is ok!\n");
        xQueueSend(timerQueueSend, (void *)&send, (TickType_t)0);
    }
}

/**
* @brief 轮询接受消息，当接收到消息后，完成相应的函数响应，此函数位于外设事件线程
*/

void lv_8ms_timer_loop(void)
{
    device_timer *receive;
    if (timerQueueSend != 0)
    {
        if (xQueueReceive(timerQueueSend, (void *)&receive, (TickType_t)10))
        {
            ESP_LOGI(TAG, "timerLoop timerQueueSend is ok!\n");
            char name[20];
            sprintf(name, "%d_%lld", receive->mode, receive->timeout_us);
            esp_timer_handle_t *test_handle = __lv_8ms_timer_init(name, receive->callback);
            __lv_8ms_timer_start(test_handle, receive->timeout_us, receive->mode);
            gc_free(&gc, receive);
        }
    }
}