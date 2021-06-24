#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/uart.h"
#include "lv_8ms_uart.h"

#define RD_BUF_SIZE (1024)

static QueueHandle_t g_lv_8ms_uart_queue;
static int g_lv_8ms_uart_num = -1;
extern void lv_8ms_uart_queue_ana(uint8_t* data,int size);

static void __lv_8ms_uart_event_task(void *pvParameters)
{
	uart_event_t event;
	uint8_t *dtmp = (uint8_t*) malloc(RD_BUF_SIZE);
	int ret;

	for (;;) {
		if (xQueueReceive(g_lv_8ms_uart_queue, (void *)&event, (portTickType)portMAX_DELAY)) {
			bzero(dtmp, RD_BUF_SIZE);
			switch(event.type) {
			case UART_DATA:
				ret = lv_8ms_uart_read(g_lv_8ms_uart_num, (char *)dtmp, event.size, portMAX_DELAY);
				if (ret > 0) {
					lv_8ms_uart_write(g_lv_8ms_uart_num, (const char*)dtmp, ret);
				}
				lv_8ms_uart_queue_ana(dtmp,event.size);
				break;
			case UART_BUFFER_FULL:
				uart_flush_input(g_lv_8ms_uart_num);
				xQueueReset(g_lv_8ms_uart_queue);
				break;
			default:
				break;
			}
		}
	}

	free(dtmp);
	dtmp = NULL;
	vTaskDelete(NULL);
}

void lv_8ms_uart_app_init(int uart_num)
{
	g_lv_8ms_uart_num = uart_num;
	lv_8ms_uart_init(g_lv_8ms_uart_num, NULL, &g_lv_8ms_uart_queue);
	lv_8ms_uart_set_settings(g_lv_8ms_uart_num, 115200, 8, 1, LV_8MS_UART_PARITY_NONE, 0, 0);

	xTaskCreatePinnedToCore(__lv_8ms_uart_event_task, "lv_8ms_uart_event_task", 2048, NULL, 12, NULL, 0);
}
