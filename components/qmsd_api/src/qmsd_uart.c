#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/uart.h"
#include "esp_log.h"
#include "qmsd_notifier.h"
#include "qmsd_api.h"

static const char *TAG = "QMSD_UART";

#define PATTERN_CHR_NUM    (3)         /*!< Set the number of consecutive and identical characters received by receiver which defines a UART pattern*/

struct qmsd_uart_desc {
    uint8_t num;
    uint8_t *rx_buf;
    uint32_t rx_size;
    QueueHandle_t queue;
    uint32_t queue_size;
    TaskHandle_t handle;
};

static struct qmsd_uart_desc g_qmsd_uart_desc[UART_NUM_MAX];

int qmsd_uart_flush(int unum)
{
    esp_err_t ret;
    ret = uart_flush(unum);

    if (ret != ESP_OK)
        return -1;
    else
        return 0;
}

int qmsd_uart_flush_input(int unum)
{
    esp_err_t ret;
    ret = uart_flush_input(unum);

    if (ret != ESP_OK)
        return -1;
    else
        return 0;
}

int qmsd_uart_flush_output(int unum)
{
    esp_err_t ret;
    ret = uart_flush(unum);

    if (ret != ESP_OK)
        return -1;
    else
        return 0;
}

int qmsd_uart_write(int unum, const char* buf, size_t len)
{
	return uart_write_bytes(unum, buf, len);
}

int qmsd_uart_read(int unum, char *buf, size_t len, int timeout)
{
	return uart_read_bytes(unum, (uint8_t *)buf, len, timeout);
}

static void __qmsd_uart_event_task(void *pvParameters)
{
	uart_event_t event;
    struct qmsd_uart_desc *desc = (struct qmsd_uart_desc*)pvParameters;
    int ret;
    size_t buffered_size;

    if (desc->rx_buf == NULL) {
        goto err_out;
    }

	for (;;) {
		if (xQueueReceive(desc->queue, (void *)&event, (portTickType)portMAX_DELAY)) {
			bzero(desc->rx_buf, desc->rx_size);
			switch(event.type) {
			case UART_DATA:
				ret = qmsd_uart_read(desc->num, (char *)desc->rx_buf, event.size, portMAX_DELAY);
                if (ret < 0) {
                   ESP_LOGI(TAG, "qmsd_uart_read error"); 
                } else {
                    struct qmsd_uart_rx_data data;
                    data.uart_num = desc->num;
                    data.data = (char *)desc->rx_buf;
                    data.size = ret;
                    qmsd_notifier_call_nolock(QMSD_UART_EVENT_DATA, &data);
                }
				break;
            case UART_FIFO_OVF:
                ESP_LOGI(TAG, "hw fifo overflow");
                // If fifo overflow happened, you should consider adding flow control for your application.
                // The ISR has already reset the rx FIFO,
                // As an example, we directly flush the rx buffer here in order to read more data.
                uart_flush_input(desc->num);
                xQueueReset(desc->queue);
                break;
            case UART_BUFFER_FULL:
                ESP_LOGI(TAG, "ring buffer full");
                // If buffer full happened, you should consider encreasing your buffer size
                // As an example, we directly flush the rx buffer here in order to read more data.
                uart_flush_input(desc->num);
                xQueueReset(desc->queue);
                break;
            case UART_PATTERN_DET:
                uart_get_buffered_data_len(desc->num, &buffered_size);
                int pos = uart_pattern_pop_pos(desc->num);
                ESP_LOGI(TAG, "[UART PATTERN DETECTED] pos: %d, buffered size: %d", pos, buffered_size);
                if (pos == -1) {
                    // There used to be a UART_PATTERN_DET event, but the pattern position queue is full so that it can not
                    // record the position. We should set a larger queue size.
                    // As an example, we directly flush the rx buffer here.
                    uart_flush_input(desc->num);
                } else {
                    uart_read_bytes(desc->num, (char *)desc->rx_buf, pos, 100 / portTICK_PERIOD_MS);
                    uint8_t pat[PATTERN_CHR_NUM + 1];
                    memset(pat, 0, sizeof(pat));
                    uart_read_bytes(desc->num, pat, PATTERN_CHR_NUM, 100 / portTICK_PERIOD_MS);
                    ESP_LOGI(TAG, "read data: %s", desc->rx_buf);
                    ESP_LOGI(TAG, "read pat : %s", pat);
                }
                break;
			default:
				break;
			}
		}
	}

err_out:
	vTaskDelete(NULL);

    desc->handle = NULL;
}

int qmsd_uart_start(int unum, qmsd_uart_config_t *uart_config)
{
    esp_err_t ret;

    uart_config_t uart_native_config = {
        .baud_rate = uart_config->uart_native_config.baud_rate,
        .data_bits = uart_config->uart_native_config.data_bits,
        .parity = uart_config->uart_native_config.parity,
        .stop_bits = uart_config->uart_native_config.stop_bits,
        .flow_ctrl = uart_config->uart_native_config.flow_ctrl,
        .rx_flow_ctrl_thresh = uart_config->uart_native_config.rx_flow_ctrl_thresh,
        .source_clk = uart_config->uart_native_config.source_clk,
    };

    ret = uart_driver_install(unum, uart_config->uart_buffer_size * 2, uart_config->uart_buffer_size * 2, uart_config->queue_size, &g_qmsd_uart_desc[unum].queue, 0);

    if (ret != ESP_OK)
        return -1;
    else {
        char task_name[128];

        uart_param_config(unum, &uart_native_config);
        uart_set_pin(unum, uart_config->uart_tx_pin, uart_config->uart_rx_pin, uart_config->uart_rts_pin, uart_config->uart_cts_pin);
        uart_set_mode(unum, uart_config->uart_mode);
        uart_enable_pattern_det_baud_intr(unum, '+', 3, 9, 0, 0);
        uart_pattern_queue_reset(unum, uart_config->queue_size);
        g_qmsd_uart_desc[unum].rx_buf = (u_int8_t *)malloc(uart_config->uart_buffer_size);
        g_qmsd_uart_desc[unum].rx_size = 0;
        g_qmsd_uart_desc[unum].num = unum;
        g_qmsd_uart_desc[unum].queue_size = uart_config->queue_size;

        if (!g_qmsd_uart_desc[unum].rx_buf) {
            ESP_LOGI(TAG, "NO memory(%d) for uart %d\n", uart_config->uart_buffer_size, unum);
            return -1;
        }

        g_qmsd_uart_desc[unum].rx_size = uart_config->uart_buffer_size;
        memset(task_name, 0, sizeof(task_name));
        sprintf(task_name, "qmsd_uart_task%d", unum);
        ret = xTaskCreatePinnedToCore(__qmsd_uart_event_task, task_name, 2048, &g_qmsd_uart_desc[unum], 12, &g_qmsd_uart_desc[unum].handle , 0);
        if (ret == pdPASS)
            return 0;
        else {
            ESP_LOGI(TAG, "creat uart(%d) thread failed", unum); 
            return -1;
        }
    }
}

void qmsd_uart_stop(int unum)
{
    if (g_qmsd_uart_desc[unum].handle != NULL) {
        vTaskDelete(g_qmsd_uart_desc[unum].handle);
    }
    uart_pattern_queue_reset(unum, g_qmsd_uart_desc[unum].queue_size);
    uart_driver_delete(unum);
    if (g_qmsd_uart_desc[unum].rx_buf) {
        free(g_qmsd_uart_desc[unum].rx_buf);
    }
}