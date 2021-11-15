#ifndef __LV_8MS_UART_H
#define __LV_8MS_UART_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/uart.h"
typedef enum {
    LV_8MS_UART_PARITY_NONE = 0,
    LV_8MS_UART_PARITY_EVEN = 1,
    LV_8MS_UART_PARITY_ODD = 2,
    LV_8MS_UART_PARITY_MARK = 3,
    LV_8MS_UART_PARITY_SPACE = 4
} lv_8ms_uart_parity_t;

typedef struct {
    int uart_no;
    int uart_bauds;
    int tx_pin;
    int rx_pin;
    QueueHandle_t* queue;
    void (*cb)(uint8_t* data,int len);
    } dev_8ms_uart_config;

int lv_8ms_uart_init(int unum, const char *devname, const void *param);
int lv_8ms_uart_set_settings(int fd, int baudrate, int tx,int rx,int databits, int stopbits, lv_8ms_uart_parity_t parity, unsigned int ctsrts, unsigned int xonxoff);
int lv_8ms_uart_get_settings(int fd, int* baudrate, int* databits, int* stopbits, lv_8ms_uart_parity_t* parity, unsigned int* ctsrts, unsigned int* xonxoff);
int lv_8ms_uart_flush(int fd);
int lv_8ms_uart_flush_input(int fd);
int lv_8ms_uart_flush_output(int fd);
int lv_8ms_uart_set_baudrate(int fd, unsigned int baud);
int lv_8ms_uart_set_mode(int fd, int bytesize, lv_8ms_uart_parity_t parity, int stopbits);
int lv_8ms_uart_set_flowcontrol(int fd, int xonxoff, int rtscts);
void lv_8ms_uart_uninit(int fd);
int lv_8ms_uart_write(int fd, const char* buf, size_t len);
int lv_8ms_uart_read(int fd, char* buf, size_t len, int timeout);
void lv_8ms_uart_app_init(int uart_num,int bauds,int tx,int rx);
#endif
