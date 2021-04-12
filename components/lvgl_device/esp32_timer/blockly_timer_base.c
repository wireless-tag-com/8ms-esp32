#include "blockly_timer.h"
#include "../gc/gc.h"

#define TAG "TIMER_BASE" // 日志标签

/**
* @brief 定时器初始化
* @param name 定时器名称
* @param call_back 定时器回调函数
* @return 定时器句柄
*/

esp_timer_handle_t *__lv_8ms_timer_init(char *name, esp_timer_cb_t call_back)
{
    esp_timer_handle_t *timer_handle;
    esp_timer_create_args_t timer_config =
        {
            .callback = call_back, //设置回调函数
            .arg = NULL,           //不携带参数
            .name = name           //定时器名字
        };
    ESP_LOGI(TAG, "TIMERBEGIN!%d", xPortGetFreeHeapSize());
    timer_handle = (esp_timer_handle_t *)gc_malloc(&gc, sizeof(esp_timer_handle_t));
    ESP_LOGI(TAG, "TIMERBEGIN!");
    esp_timer_create(&timer_config, timer_handle);
    ESP_LOGI(TAG, "TIMERBEGIN!");
    return timer_handle;
}

/**
* @brief 定时器开始
* @param timer_handle 定时器句柄
* @param timeout_us 定时器定时时长，单位为微秒
* @param mode 定时器模式，有周期和单次，详见 @ref timer_mode
*/

void __lv_8ms_timer_start(esp_timer_handle_t *timer_handle, uint64_t timeout_us, timer_mode mode)
{
    if (mode)
        ESP_ERROR_CHECK(esp_timer_start_periodic(*timer_handle, timeout_us));
    else
        ESP_ERROR_CHECK(esp_timer_start_once(*timer_handle, timeout_us));
    gc_free(&gc, timer_handle);
}