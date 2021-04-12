#include "blockly_uart_base.h"
#include "../gc/gc.h"

#define TAG "UART_QUEUE" // log输出的标签

/**
* @brief 初始化外设线程用到的消息，此函数位于外设事件线程
*/

void lv_8ms_uart_setup(void)
{
    uartQueueSend = xQueueCreate(TIMER_SEND_NUM, sizeof(device_uart));
    uartQueueReceive = xQueueCreate(TIMER_RECV_NUM, sizeof(device_uart));
    void *bos = __builtin_frame_address(0);
    gc_start(&gc, bos);
}

/**
* @brief 设置串口初始化的消息
* @param uart_nun 需要初始化的串口号，详见 @ref uart_port_t
* @param tx_io_num 设置发送引脚
* @param rx_io_num 设置接收引脚
* @param baud_rate 初始化串口的波特率
*/

void lv_8ms_uart_init(uart_port_t uart_num, int tx_io_num, int rx_io_num, int baud_rate)
{
    device_uart *send = (device_uart *)gc_malloc(&gc, sizeof(device_uart));
    send->uart_num = uart_num;
    send->baud_rate = baud_rate;
    send->rx_io_num = rx_io_num;
    send->tx_io_num = tx_io_num;
    send->ID = SERIALBEGIN;
    if (uartQueueSend != 0)
    {
        ESP_LOGI(TAG, "lv_8ms_uart_init uartQueueSend is ok!\n");
        xQueueSend(uartQueueSend, (void *)&send, (TickType_t)0);
    }
}

/**
* @brief 设置读取串口的消息
* @param uart_nun 需要初始化的串口号，详见 @ref uart_port_t
* @return 读取的字符串（会创建内存外面只需要一个字符串指针接收就行）
*/
char *lv_8ms_uart_read(uart_port_t uart_num)
{
    device_uart *send = (device_uart *)gc_malloc(&gc, sizeof(device_uart));
    send->ID = SERIALREAD;
    send->uart_num = uart_num;
    if (uartQueueSend != 0)
    {
        ESP_LOGI(TAG, "lv_8ms_uart_read uartQueueSend is ok!\n");
        xQueueSend(uartQueueSend, (void *)&send, (TickType_t)0);
    }
    /***************************************************
     *                      读取消息
     **************************************************/
    device_uart *receive;
    if (uartQueueReceive != 0)
    {
        if (xQueueReceive(uartQueueReceive, (void *)&receive, (TickType_t)10))
        {
            ESP_LOGI(TAG, "Read gpioQueueReceive is ok!\n");
            if (receive->ID == SERIALREAD)
            {
                ESP_LOGI(TAG, "receive is %s\n", receive->msg);
                char *result = (char *)gc_malloc(&gc, strlen(receive->msg) + 1);
                strcpy(result, receive->msg);
                gc_free(&gc, receive->msg);
                gc_free(&gc, receive);
                return result;
            }
            gc_free(&gc, receive);
        }
    }
    char *end = (char *)gc_malloc(&gc, 2 * sizeof(char));
    strcpy(end, "");
    return end;
}

/**
* @brief 设置串口写入消息
* @param uart_num 要写入的串口号
* @param msg 要写入的信息 
*/

void lv_8ms_uart_write(uart_port_t uart_num, char *msg)
{
    device_uart *send = (device_uart *)gc_malloc(&gc, sizeof(device_uart));
    send->ID = SERIALWRITE;
    send->uart_num = uart_num;
    send->msg = (char *)gc_malloc(&gc, strlen(msg) + 1);
    strcpy(send->msg, msg);
    ESP_LOGI(TAG, "msg:%s!\n", send->msg);
    if (uartQueueSend != 0)
    {
        ESP_LOGI(TAG, "serialwrite uartQueueSend is ok!\n");
        xQueueSend(uartQueueSend, (void *)&send, (TickType_t)0);
    }
}

/**
* @brief 设置格式化写入的消息（用法同printf）
* @param uart_num 要写入的串口号
* @param msg 写入的格式化信息
* @param ... 格式化内容（不定参数） 
*/

void lv_8ms_uart_printf(uart_port_t uart_num, char *msg, ...)
{
    char text[1024];
    va_list ap;
    va_start(ap, msg);
    vsprintf(text, msg, ap);
    va_end(ap);
    lv_8ms_uart_write(uart_num, text);
}

/**
* @brief 轮询接受消息，当接收到消息后，完成相应的函数响应，此函数位于外设事件线程
*/

void lv_8ms_uart_loop(void)
{
    device_uart *receive;
    char *message;
    if (uartQueueSend != 0)
    {
        if (xQueueReceive(uartQueueSend, (void *)&receive, (TickType_t)10))
        {
            ESP_LOGI(TAG, "lv_8ms_uart_loop uartQueueSend is ok!\n");
            switch (receive->ID)
            {
            case SERIALBEGIN:
                ESP_LOGI(TAG, "SERIALBEGIN!\n");
                __lv_8ms_uart_init(receive->uart_num, receive->tx_io_num, receive->rx_io_num, receive->baud_rate);
                break;
            case SERIALREAD:
                ESP_LOGI(TAG, "SERIALREAD!\n");
                message = __lv_8ms_uart_read(receive->uart_num);
                ESP_LOGI(TAG, "SERIALREAD!\n");
                device_uart *recv = (device_uart *)gc_malloc(&gc, sizeof(device_uart));
                if (message[0]) // 如果接收到返回的数据则把数据拷贝到新内存空间
                {
                    recv->msg = (char *)gc_malloc(&gc, strlen(message) + 1);
                    strcpy(recv->msg, message);
                }
                else // 如果没有则给个字符串尾
                {
                    recv->msg = (char *)gc_malloc(&gc, sizeof(char) * 2);
                    strcpy(recv->msg, "");
                }
                recv->ID = SERIALREAD;
                if (uartQueueReceive != 0)
                {
                    ESP_LOGI(TAG, "lv_8ms_uart_loop uartQueueReceive is ok!\n");
                    xQueueSend(uartQueueReceive, (void *)&recv, (TickType_t)0);
                }
                break;
            case SERIALWRITE:
                ESP_LOGI(TAG, "SERIALWRITE!:%s\n", receive->msg);
                __lv_8ms_uart_write(receive->uart_num, receive->msg);
                gc_free(&gc, receive->msg);
                break;
            default:
                break;
            }
            gc_free(&gc, receive);
        }
    }
}