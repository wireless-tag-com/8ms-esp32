#include <sys/time.h>

#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"
#include "freertos/task.h"
#include "esp_heap_caps.h"
#include "esp_log.h"

#define TAG "qmsd_utils"
#define REF_TIME        1577808000 /* 2020-01-01 00:00:00 */

uint64_t qmsd_get_time_ms() {
    struct timeval tv = { 0 };
    gettimeofday(&tv, NULL);
    if (tv.tv_sec < REF_TIME) {
        return 0;
    }

    return (uint64_t)tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

uint32_t qmsd_get_time_sec() {
    struct timeval tv = { 0 };
    gettimeofday(&tv, NULL);
    if (tv.tv_sec < REF_TIME) {
        return 0;
    }

    return (uint32_t)tv.tv_sec;
}

static void esp_mem_print_task() {
    TaskStatus_t *pxTaskStatusArray = NULL;
    volatile UBaseType_t uxArraySize = 0;
    uint32_t ulTotalRunTime = 0, ulStatsAsPercentage = 0, ulRunTimeCounte = 0;
    const char task_status_char[] = {'r', 'R', 'B', 'S', 'D'};

    /* Take a snapshot of the number of tasks in case it changes while this
    function is executing. */
    uxArraySize = uxTaskGetNumberOfTasks();
    pxTaskStatusArray = malloc(uxTaskGetNumberOfTasks() * sizeof(TaskStatus_t));

    if (!pxTaskStatusArray) {
        return ;
    }

    /* Generate the (binary) data. */
    uxArraySize = uxTaskGetSystemState(pxTaskStatusArray, uxArraySize, &ulTotalRunTime);
    ulTotalRunTime /= 100UL;

    ESP_LOGI(TAG, "---------------- The State Of Tasks ----------------");
    ESP_LOGI(TAG, "- HWM   : usage high water mark (Byte)");
    ESP_LOGI(TAG, "- Status: blocked ('B'), ready ('R'), deleted ('D') or suspended ('S')\n");
    ESP_LOGI(TAG, "TaskName\t\tStatus\tPrio\tHWM\tTaskNum\tCoreID\tRunTimeCounter\tPercentage");

    for (int i = 0; i < uxArraySize; i++) {
#if( configGENERATE_RUN_TIME_STATS == 1 )
        ulRunTimeCounte = pxTaskStatusArray[i].ulRunTimeCounter;
        ulStatsAsPercentage = ulRunTimeCounte / ulTotalRunTime;
#endif


        int core_id = -1;
        char precentage_char[4] = {0};

#if ( configTASKLIST_INCLUDE_COREID == 1 )
        core_id = (int) pxTaskStatusArray[ i ].xCoreID;
#endif

        /* Write the rest of the string. */
        ESP_LOGI(TAG, "%-16s\t%c\t%u\t%u\t%u\t%hd\t%-16u%-s%%",
                 pxTaskStatusArray[i].pcTaskName, task_status_char[pxTaskStatusArray[i].eCurrentState],
                 (uint32_t) pxTaskStatusArray[i].uxCurrentPriority,
                 (uint32_t) pxTaskStatusArray[i].usStackHighWaterMark,
                 (uint32_t) pxTaskStatusArray[i].xTaskNumber, core_id,
                 ulRunTimeCounte, (ulStatsAsPercentage <= 0) ? "<1" : itoa(ulStatsAsPercentage, precentage_char, 10));
    }

    free(pxTaskStatusArray);
}

void qmsd_debug_task_print(uint32_t interval_time) {
    static uint32_t time_last = 0;
    if (xTaskGetTickCount() - time_last > interval_time) {
        time_last = xTaskGetTickCount();
        esp_mem_print_task();
    }
}

void qmsd_debug_heap_print(uint32_t caps, uint32_t interval_time) {
    static uint32_t time_last = 0;
    if (xTaskGetTickCount() - time_last > interval_time) {
        time_last = xTaskGetTickCount();
        multi_heap_info_t info;
        heap_caps_get_info(&info, caps);
        ESP_LOGI(TAG, "------------- ಥ_ಥ Memory ಥ_ಥ ------------- ");
        ESP_LOGI(TAG, "ಥ_ಥ total_free_bytes -> %d", info.total_free_bytes);
        ESP_LOGI(TAG, "ಥ_ಥ total_allocated_bytes -> %d", info.total_allocated_bytes);
        ESP_LOGI(TAG, "ಥ_ಥ largest_free_block -> %d", info.largest_free_block);
        ESP_LOGI(TAG, "ಥ_ಥ minimum_free_bytes -> %d", info.minimum_free_bytes);
        ESP_LOGI(TAG, "ಥ_ಥ allocated_blocks -> %d", info.allocated_blocks);
        ESP_LOGI(TAG, "ಥ_ಥ free_blocks -> %d", info.free_blocks);
        ESP_LOGI(TAG, "ಥ_ಥ total_blocks -> %d", info.total_blocks);
    }
}

static int __malloc_cont =0;

void* qmsd_malloc(size_t size)
{
    void* mem = malloc(size);
    __malloc_cont++;
    printf("malloc: %d\n", __malloc_cont);
    return mem;
}

void qmsd_free(void* p)
{
    free(p);
    __malloc_cont--;
    printf("free: %d\n", __malloc_cont);
}