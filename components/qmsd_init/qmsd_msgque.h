#ifndef __QMSD_MSGQUE_H__
#define __QMSD_MSGQUE_H__

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"

#ifdef __cplusplus
extern "C"
{
#endif

#ifndef TRUE
#define TRUE    (1 == 1)
#define FALSE   (0 == 1)
#endif

#define MAX_MSG_COUNT 128

#define M_RET_OK	0
#define M_RET_FAIL	-1

typedef void * t_msg;
typedef void * (*t_malloc_handler)(unsigned long size);
typedef void (*t_free_handler)(void *mem_p);

typedef struct t_msg_block
{
    struct t_msg_block *nextp;
    t_msg   msg;
    unsigned short msglen;
}t_msg_block;

typedef struct
{
    SemaphoreHandle_t xMsgSemaphore;
    t_msg_block *firstp;
    t_msg_block *lastp;
    int msgcount;
    int msgmax;
}t_qcb;

int qmsd_msgque_init(int msgmax);
int qmsd_msgque_send(void *msg,unsigned int msglen, TickType_t xtime);
int qmsd_msgque_recv(void **msg,unsigned int *msglen, TickType_t xtime);
void qmsd_msgque_deinit(void);

int qmsd_main_msgque_init(int msgmax);
int qmsd_main_msgque_send(void *msg,unsigned int msglen, TickType_t xtime);
int qmsd_main_msgque_recv(void **msg,unsigned int *msglen, TickType_t xtime);
void qmsd_main_msgque_deinit(void);

#ifdef __cplusplus
}
#endif

#endif
