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

#define TAG "QMSD CUSTOM"

void qmsd_custom_init(void)
{
    /*
     * TODO: custom init code
     */
    ESP_LOGI(TAG, "custom init");
}

