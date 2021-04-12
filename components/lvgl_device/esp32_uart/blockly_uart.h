#ifndef BLOCKLY_UART_H
#define BLOCKLY_UART_H

#ifdef __cplusplus
extern "C"
{
#endif
    /*********************
     *      INCLUDES
     *********************/

#include "driver/uart.h"
#include "../lvgl_device.h"

    /*********************
     *      DEFINES
     *********************/

#define TIMER_SEND_NUM 4
#define TIMER_RECV_NUM 4

    /**********************
     *      TYPEDEFS
     **********************/

    typedef enum
    {
        SERIALBEGIN = 0,
        SERIALREAD,
        SERIALWRITE,
    } uart_func;

    typedef struct
    {
        uart_func ID;
        uart_port_t uart_num;
        int tx_io_num;
        int rx_io_num;
        int baud_rate;
        char *msg;
    } device_uart;

    /**********************
     * GLOBAL PROTOTYPES
     **********************/

    QueueHandle_t uartQueueSend;
    QueueHandle_t uartQueueReceive;

    /**********************
     *      MACROS
     **********************/

    void lv_8ms_uart_init(uart_port_t uart_num, int tx_io_num, int rx_io_num, int baud_rate);
    char *lv_8ms_uart_read(uart_port_t uart_num);
    void lv_8ms_uart_write(uart_port_t uart_num, char *msg);
    void lv_8ms_uart_printf(uart_port_t uart_num, char *msg, ...);
    void lv_8ms_uart_setup(void);
    void lv_8ms_uart_loop(void);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif