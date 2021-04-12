#include "blockly_uart_base.h"
#include <string.h>

#define TAG "UART_BASE" // log输出的标签

#define BUF_SIZE (1024) //注册字符大小
#define RD_BUF_SIZE (BUF_SIZE)

uart_event_t uart0_event, uart1_event, uart2_event;  // 串口事件句柄
QueueHandle_t uart0_queue, uart1_queue, uart2_queue; // 串口消息句柄

/**
* @brief 打开串口
* @param uart_num 设置打开的串口号，详见 @ref uart_port_t
* @param tx_io_num 设置发送引脚
* @param rx_io_num 设置接收引脚
* @param baud_rate 设置波特率
*/
void __lv_8ms_uart_init(uart_port_t uart_num, int tx_io_num, int rx_io_num, int baud_rate)
{
    uart_config_t uart_config =
        {
            .baud_rate = baud_rate,
            .data_bits = UART_DATA_8_BITS,
            .parity = UART_PARITY_DISABLE,
            .stop_bits = UART_STOP_BITS_1,
            .flow_ctrl = UART_HW_FLOWCTRL_DISABLE};
    ESP_ERROR_CHECK(uart_param_config(uart_num, &uart_config));
    ESP_ERROR_CHECK(uart_set_pin(uart_num, tx_io_num, rx_io_num, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE));
    switch (uart_num)
    {
    case UART_NUM_0:
        ESP_ERROR_CHECK(uart_driver_install(uart_num, BUF_SIZE * 2, BUF_SIZE * 2, 20, &uart0_queue, 0));
        break;
    case UART_NUM_1:
        ESP_ERROR_CHECK(uart_driver_install(uart_num, BUF_SIZE * 2, BUF_SIZE * 2, 20, &uart1_queue, 0));
        break;
    case UART_NUM_2:
        ESP_ERROR_CHECK(uart_driver_install(uart_num, BUF_SIZE * 2, BUF_SIZE * 2, 20, &uart2_queue, 0));
        break;

    default:
        ESP_LOGI(TAG, "error not have this serial\n");
    }
    ESP_ERROR_CHECK(uart_pattern_queue_reset(uart_num, 20));
}

/**
* @brief 读串口处理函数（内部函数禁止外部直接调用）
* @param uart_num 设置打开的串口号，详见 @ref uart_port_t
* @param queue 设置该串口的消息
* @param event 设置该串口的事件
* @param msg 该串口接收的文本
*/
static void __uart_read_handle(uart_port_t uart_num, QueueHandle_t queue, uart_event_t *event, uint8_t *msg)
{
    if (xQueueReceive(queue, (uint32_t *)event, 0))
    {
        switch (event->type)
        {
        case UART_DATA:
            uart_read_bytes(uart_num, msg, event->size, portMAX_DELAY);
            break;
        case UART_FIFO_OVF:
            uart_flush_input(uart_num);
            xQueueReset(queue);
            break;
        case UART_BUFFER_FULL:
            uart_flush_input(uart_num);
            xQueueReset(queue);
            break;
        default:
            break;
        }
    }
}

/**
* @brief 读取串口数据
* @param uart_num 设置串口号
* @return 读取的字符串
*/
uint8_t data[RD_BUF_SIZE]; // 读取的字符串先存储在全局数组里
char *__lv_8ms_uart_read(uart_port_t uart_num)
{
    bzero(data, RD_BUF_SIZE);
    switch (uart_num)
    {
    case UART_NUM_0:
        __uart_read_handle(UART_NUM_0, uart0_queue, &uart0_event, data);
        break;
    case UART_NUM_1:
        __uart_read_handle(UART_NUM_1, uart1_queue, &uart1_event, data);
        break;
    case UART_NUM_2:
        __uart_read_handle(UART_NUM_2, uart2_queue, &uart2_event, data);
        break;
    default:
        break;
    }
    return (char *)data;
}

/**
* @brief 写串口处理函数（内部函数禁止外部直接调用）
* @param uart_num 设置打开的串口号，详见 @ref uart_port_t
* @param queue 设置该串口的消息
* @param event 设置该串口的事件
* @param msg 设置该串口传输的文本
*/

static void __uart_write_handle(uart_port_t uart_num, QueueHandle_t queue, uart_event_t *event, uint8_t *msg)
{
    switch (event->type)
    {
    case UART_DATA:
        uart_write_bytes(uart_num, (const char *)msg, strlen((char *)msg));
        break;
    case UART_FIFO_OVF:
        uart_flush_input(uart_num);
        xQueueReset(queue);
        break;
    case UART_BUFFER_FULL:
        uart_flush_input(uart_num);
        xQueueReset(queue);
        break;
    default:
        break;
    }
}

/**
* @brief 写串口函数
* @param uart_num 设置打开的串口号，详见 @ref uart_port_t
* @param msg 设置该串口传输的文本
*/

void __lv_8ms_uart_write(uart_port_t uart_num, char *msg)
{
    ESP_LOGI(TAG, "__lv_8ms_uart_write is ok:%s,%d", msg, uart_num);
    switch (uart_num)
    {
    case UART_NUM_0:
        __uart_write_handle(UART_NUM_0, uart0_queue, &uart0_event, (uint8_t *)msg);
        break;
    case UART_NUM_1:
        __uart_write_handle(UART_NUM_1, uart1_queue, &uart1_event, (uint8_t *)msg);
        break;
    case UART_NUM_2:
        __uart_write_handle(UART_NUM_2, uart2_queue, &uart2_event, (uint8_t *)msg);
        break;
    default:
        break;
    }
}
