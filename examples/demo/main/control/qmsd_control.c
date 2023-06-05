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
#include "qmsd_ctrl.h"
#include "qmsd_control.h"
#include "qmsd_msgque.h"
#include "qmsd_mod.h"

#define TAG "QMSD CTRL"

void qmsd_control_init(void)
{
    while (1) {
        /*
         * TODO: control logic code
         */
        vTaskDelay(pdMS_TO_TICKS(50));
    }
}

