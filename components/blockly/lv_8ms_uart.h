#ifndef __LV_8MS_UART_H
#define __LV_8MS_UART_H

typedef enum {
    LV_8MS_UART_PARITY_NONE = 0,
    LV_8MS_UART_PARITY_EVEN = 1,
    LV_8MS_UART_PARITY_ODD = 2,
    LV_8MS_UART_PARITY_MARK = 3,
    LV_8MS_UART_PARITY_SPACE = 4
} lv_8ms_uart_parity_t;

int lv_8ms_uart_init(int unum, const char *devname, const void *param);
int lv_8ms_uart_set_settings(int fd, int baudrate, int databits, int stopbits, lv_8ms_uart_parity_t parity, unsigned int ctsrts, unsigned int xonxoff);
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

#endif
