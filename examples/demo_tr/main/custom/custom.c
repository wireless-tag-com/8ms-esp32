#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_freertos_hooks.h"
#include "freertos/semphr.h"
#include "esp_system.h"
#include "esp_log.h"
#include "qmsd_api.h"
#include "sht20.h"

#define TAG "QMSD CUSTOM"

extern float get_tem_data;
extern float get_hum_data;

void __sht20_test_task(void* user_data)
{    
    sht20_init(15, 6);
    vTaskDelay(1000/portTICK_RATE_MS);
    while(1){
        get_tem_data = sht20_get_temperature();
        get_hum_data = sht20_get_humidity();
        vTaskDelay(1000/portTICK_RATE_MS);
    }
    vTaskDelete(NULL);
}

void qmsd_custom_init(void)
{
}

void qmsd_custom_start(void)
{
}

void qmsd_custom_start_later(void)
{
    xTaskCreatePinnedToCore(__sht20_test_task, "sht20", 4 * 1024, NULL, 5, NULL, 0);
}

