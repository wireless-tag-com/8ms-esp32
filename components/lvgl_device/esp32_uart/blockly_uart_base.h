#ifndef BLOCKLY_UART_BASE_H
#define BLOCKLY_UART_BASE_H

#ifdef __cplusplus
extern "C" {
#endif
/*********************
 *      INCLUDES
 *********************/

#include "blockly_uart.h"

/*********************
 *      DEFINES
 *********************/



/**********************
 *      TYPEDEFS
 **********************/



/**********************
 * GLOBAL PROTOTYPES
 **********************/



/**********************
 *      MACROS
 **********************/

void __serialBegin(uart_port_t uart_num, int tx_io_num, int rx_io_num, int baud_rate);
char* __serialRead(uart_port_t uart_num);
void __serialWrite(uart_port_t uart_num, char* msg);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif