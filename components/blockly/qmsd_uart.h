#ifndef __QMSD_UART_H
#define __QMSD_UART_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/uart.h"

typedef enum {
    QMSD_UART_PARITY_NONE = 0,
    QMSD_UART_PARITY_EVEN = 1,
    QMSD_UART_PARITY_ODD = 2,
    QMSD_UART_PARITY_MARK = 3,
    QMSD_UART_PARITY_SPACE = 4
} qmsd_uart_parity_t;

typedef struct {
    int uart_no;
    int uart_bauds;
    int tx_pin;
    int rx_pin;
    QueueHandle_t* queue;
    void (*cb)(uint8_t* data,int len);
    } dev_qmsd_uart_config;

int qmsd_uart_init(int unum, const char *devname, const void *param);
int qmsd_uart_set_settings(int fd, int baudrate, int tx,int rx,int databits, int stopbits, qmsd_uart_parity_t parity, unsigned int ctsrts, unsigned int xonxoff);
int qmsd_uart_get_settings(int fd, int* baudrate, int* databits, int* stopbits, qmsd_uart_parity_t* parity, unsigned int* ctsrts, unsigned int* xonxoff);
int qmsd_uart_flush(int fd);
int qmsd_uart_flush_input(int fd);
int qmsd_uart_flush_output(int fd);
int qmsd_uart_set_baudrate(int fd, unsigned int baud);
int qmsd_uart_set_mode(int fd, int bytesize, qmsd_uart_parity_t parity, int stopbits);
int qmsd_uart_set_flowcontrol(int fd, int xonxoff, int rtscts);
void qmsd_uart_uninit(int fd);
int qmsd_uart_write(int fd, const char* buf, size_t len);
int qmsd_uart_read(int fd, char* buf, size_t len, int timeout);
void qmsd_uart_app_init(int uart_num,int bauds,int tx,int rx);

#endif
