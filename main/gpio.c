#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_freertos_hooks.h"
#include "freertos/semphr.h"
#include "esp_system.h"
#include "driver/gpio.h"
#include "lv_8ms_event.h"
#include "lv_8ms_gpio.h"

#define TAG "lv_8ms_gpio"

static xQueueHandle g_lv_8ms_gpio_evt_queue = NULL;

static void __lv_8ms_gpio_queue_setup(void)
{
    g_lv_8ms_gpio_evt_queue = xQueueCreate(10, sizeof(uint32_t));
}

static void IRAM_ATTR __lv_8ms_gpio_isr_handler(void* arg)
{
    uint32_t gpio_num = (uint32_t) arg;
    xQueueSendFromISR(g_lv_8ms_gpio_evt_queue, &gpio_num, NULL);
}

static void __lv_8ms_gpio_to_event(void* arg)
{
    uint32_t io_num;

    for(;;) {
        if(xQueueReceive(g_lv_8ms_gpio_evt_queue, &io_num, portMAX_DELAY)) {
            if (lv_8ms_gpio_read(io_num))
            {
                lv_8ms_event_post_to(LV_8MS_GPIO_PULL_UP,  &io_num, sizeof(io_num), 0);
            }
            else
            {
                lv_8ms_event_post_to(LV_8MS_GPIO_PULL_DOWN,  &io_num, sizeof(io_num), 0);
            }
        }
    }
}

static void __lv_8ms_event_handel(void* handler_args, esp_event_base_t base, int32_t id, void* event_data)
{
    uint32_t *gpio_num = (uint32_t *)event_data;
    char* id_gpio;

    if (id == LV_8MS_GPIO_PULL_DOWN) {
        id_gpio = "Fall edge";
    } else {
        id_gpio = "Raise edge";
    }

    ESP_LOGI(TAG, "handling %s:%s from %s, which [ID:%d,%d]", base, "8MS_EVENT_HANDLE", id_gpio,id, *gpio_num);
}

void lv_8ms_gpio_app_init(void)
{
    lv_8ms_gpio_init(5,LV_8MS_GPIO_IN,0,1);
    lv_8ms_gpio_intr_enable(5);
    lv_8ms_gpio_set_intr_type(5, 3);
    lv_8ms_gpio_isr_handler_add(5, __lv_8ms_gpio_isr_handler, (void*)5);

    lv_8ms_gpio_init(4,LV_8MS_GPIO_IN,0,1);
    lv_8ms_gpio_intr_enable(4);
    lv_8ms_gpio_set_intr_type(4, 2);
    lv_8ms_gpio_isr_handler_add(4, __lv_8ms_gpio_isr_handler, (void*)4);

    lv_8ms_event_handler_register(LV_8MS_GPIO_PULL_DOWN, __lv_8ms_event_handel);
    lv_8ms_event_handler_register(LV_8MS_GPIO_PULL_UP, __lv_8ms_event_handel);
    lv_8ms_gpio_isr_init(0);
    __lv_8ms_gpio_queue_setup();
    #ifndef CONFIG_IDF_TARGET_ESP32C3
    xTaskCreate(__lv_8ms_gpio_to_event, "lv_8ms_gpio_to_event", 512, NULL, 10, NULL);
    #else
    xTaskCreate(__lv_8ms_gpio_to_event, "lv_8ms_gpio_to_event", 1024, NULL, 10, NULL);
    #endif
}