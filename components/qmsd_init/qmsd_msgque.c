/************************************************************************
**         Message queue manager basic functions
**
** Copyright 2017 Chen Xiangyu(xiangyu.chen@aol.com) 
**
**
** Project website:
** https://github.com/chenxy1988/msgque
**
** This is a mothod for multi-thread communication under linux.
** Should you have any questions, pls. do not hesitate to 
** contact xiangyu.chen@aol.com
**
*************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "qmsd_msgque.h"

static t_qcb g_mainpq;
static t_qcb g_guipq;
static unsigned long mem_alloc_count = 0; //For memory testing

static void *__mem_malloc(unsigned long size)
{
    void *memp = malloc(size);

    if(memp == NULL)
    {
        printf("__mem_malloc: failed, seems out of memory Size %ld \n",size);
		return NULL;
    }

    mem_alloc_count++;

    return (memp);

}

static void __mem_free(void *memp)
{
    if(memp == NULL)
    {
        printf("__mem_free (): NULL memp");
    }
    else
    {
        free(memp);
    	mem_alloc_count--;
    }

}

/*
 *    Creating a message queue,
 *    Success: return a vaild queue id,
 *    Failed : return -1
 *
 */
int qmsd_msgque_init(int msgmax)
{
    g_guipq.xMsgSemaphore = xSemaphoreCreateMutex();
    if(g_guipq.xMsgSemaphore == NULL)
    {
        printf("qmsd_msgque_init(); xSemaphoreCreateMutex() failed \n");
        return (M_RET_FAIL);
    }

    g_guipq.firstp = g_guipq.lastp = NULL;
    g_guipq.msgcount = 0;
    g_guipq.msgmax = msgmax;

    return M_RET_OK;
}

/*  Sending a message to queue,
 *  qid: queue id
 *  msg: data which send to queue
 *  msglen: length of data
 *  Return value:
 *  Success: M_RET_SUCCESS
 *  Failed:  M_RET_FAIL
 *
 */
int qmsd_msgque_send(void *msg,unsigned int msglen, TickType_t xtime)
{
    t_msg_block *pbmsg;

    if (g_guipq.xMsgSemaphore == NULL) {
        return (M_RET_FAIL); 
    }

    if(msg == NULL)
    {
        printf("qmsd_msgque_send(),msg == NULL \n");
        return (M_RET_FAIL);
    }

    pbmsg = (t_msg_block *)__mem_malloc(sizeof(t_msg_block));     //Store message block
    if(pbmsg == NULL)
    {
        printf("qmsd_msgque_send(),mem_malloc pbmsg == NULL \n");
        return (M_RET_FAIL);
    }

    pbmsg->nextp = NULL;
    pbmsg->msg = msg;
    pbmsg->msglen = msglen;

    if (pdTRUE != xSemaphoreTake(g_guipq.xMsgSemaphore, xtime)) {
        free(pbmsg);
        return M_RET_FAIL;
    }

    if (g_guipq.msgcount >= g_guipq.msgmax)
    {
    	xSemaphoreGive(g_guipq.xMsgSemaphore);
    	printf("qmsd_msgque_send();msgcount:%d\n", g_guipq.msgcount);
    	free(pbmsg);
    	return (M_RET_FAIL);
    }
    g_guipq.msgcount++;

    if(g_guipq.lastp != NULL)
    {
        g_guipq.lastp->nextp = pbmsg;
        g_guipq.lastp = pbmsg;
    }
    else
    {
        g_guipq.firstp = g_guipq.lastp = pbmsg;
    }

    xSemaphoreGive(g_guipq.xMsgSemaphore);

    return (M_RET_OK);

}


/** 
 *	Receive a message from queue
 *  Args:
 *  qid: queue id
 *  msg: pointer of message pointer
 *  msglen: length of message
 *  Return value:
 *  Failed: M_RET_FAIL
 *  Success: M_RET_OK
 *
 */
int qmsd_msgque_recv(void **msg,unsigned int *msglen, TickType_t xtime)
{
    t_msg_block *pbmsg = NULL;

    if (g_guipq.xMsgSemaphore == NULL) {
        return (M_RET_FAIL); 
    }

    if (pdTRUE != xSemaphoreTake(g_guipq.xMsgSemaphore, xtime)) {
        return M_RET_FAIL;
    }

    if (g_guipq.msgcount == 0)
    {
    	xSemaphoreGive(g_guipq.xMsgSemaphore);
    	return (M_RET_FAIL);
    }
    g_guipq.msgcount--;

    pbmsg = g_guipq.firstp;
    if(pbmsg == NULL)
    {
        xSemaphoreGive(g_guipq.xMsgSemaphore);
        return (M_RET_FAIL);
    }

    *msg = pbmsg->msg;
    *msglen = pbmsg->msglen;

    if(g_guipq.lastp == pbmsg)
    {
        g_guipq.lastp = NULL;
    }
    g_guipq.firstp = pbmsg->nextp;

    __mem_free(pbmsg);

    xSemaphoreGive(g_guipq.xMsgSemaphore);

    return (M_RET_OK);
}

void qmsd_msgque_deinit(void)
{
    if (g_guipq.xMsgSemaphore) {
        while(1) {
            void *msg;
            unsigned int msglen;
            int ret;

            ret = qmsd_msgque_recv((void **)&msg, &msglen, portMAX_DELAY);

            if (ret < 0) {
                break;
            } else {
                free(msg);
            }
        }
        g_guipq.firstp = g_guipq.lastp = NULL;
        g_guipq.msgcount = 0;
        g_guipq.msgmax = 0;
        vSemaphoreDelete(g_guipq.xMsgSemaphore);
    }
}


/*
 *    Creating a message queue,
 *    Success: return a vaild queue id,
 *    Failed : return -1
 *
 */
int qmsd_main_msgque_init(int msgmax)
{
    g_mainpq.xMsgSemaphore = xSemaphoreCreateMutex();
    if(g_mainpq.xMsgSemaphore == NULL)
    {
        printf("qmsd_main_msgque_init(); xSemaphoreCreateMutex() failed \n");
        return (M_RET_FAIL);
    }

    g_mainpq.firstp = g_mainpq.lastp = NULL;
    g_mainpq.msgcount = 0;
    g_mainpq.msgmax = msgmax;

    return M_RET_OK;
}

/*  Sending a message to queue,
 *  qid: queue id
 *  msg: data which send to queue
 *  msglen: length of data
 *  Return value:
 *  Success: M_RET_SUCCESS
 *  Failed:  M_RET_FAIL
 *
 */
int qmsd_main_msgque_send(void *msg,unsigned int msglen, TickType_t xtime)
{
    t_msg_block *pbmsg;

    if (g_mainpq.xMsgSemaphore == NULL) {
        return (M_RET_FAIL); 
    }

    if(msg == NULL)
    {
        printf("qmsd_main_msgque_send(),msg == NULL \n");
        return (M_RET_FAIL);
    }

    pbmsg = (t_msg_block *)__mem_malloc(sizeof(t_msg_block));     //Store message block
    if(pbmsg == NULL)
    {
        printf("qmsd_msgque_send(),mem_malloc pbmsg == NULL \n");
        return (M_RET_FAIL);
    }

    pbmsg->nextp = NULL;
    pbmsg->msg = msg;
    pbmsg->msglen = msglen;

    if (pdTRUE != xSemaphoreTake(g_mainpq.xMsgSemaphore, xtime)) {
        free(pbmsg);
        return M_RET_FAIL;
    }

    if (g_mainpq.msgcount >= g_mainpq.msgmax)
    {
    	xSemaphoreGive(g_mainpq.xMsgSemaphore);
    	printf("qmsd_msgque_send();msgcount:%d\n", g_mainpq.msgcount);
    	free(pbmsg);
    	return (M_RET_FAIL);
    }
    g_mainpq.msgcount++;

    if(g_mainpq.lastp != NULL)
    {
        g_mainpq.lastp->nextp = pbmsg;
        g_mainpq.lastp = pbmsg;
    }
    else
    {
        g_mainpq.firstp = g_mainpq.lastp = pbmsg;
    }

    xSemaphoreGive(g_mainpq.xMsgSemaphore);

    return (M_RET_OK);

}


/** 
 *	Receive a message from queue
 *  Args:
 *  qid: queue id
 *  msg: pointer of message pointer
 *  msglen: length of message
 *  Return value:
 *  Failed: M_RET_FAIL
 *  Success: M_RET_OK
 *
 */
int qmsd_main_msgque_recv(void **msg,unsigned int *msglen, TickType_t xtime)
{
    t_msg_block *pbmsg = NULL;

    if (g_mainpq.xMsgSemaphore == NULL) {
        return (M_RET_FAIL); 
    }

    if (pdTRUE != xSemaphoreTake(g_mainpq.xMsgSemaphore, xtime)) {
        return M_RET_FAIL;
    }

    if (g_mainpq.msgcount == 0)
    {
    	xSemaphoreGive(g_mainpq.xMsgSemaphore);
    	return (M_RET_FAIL);
    }
    g_mainpq.msgcount--;

    pbmsg = g_mainpq.firstp;
    if(pbmsg == NULL)
    {
        xSemaphoreGive(g_mainpq.xMsgSemaphore);
        return (M_RET_FAIL);
    }

    *msg = pbmsg->msg;
    *msglen = pbmsg->msglen;

    if(g_mainpq.lastp == pbmsg)
    {
        g_mainpq.lastp = NULL;
    }
    g_mainpq.firstp = pbmsg->nextp;

    __mem_free(pbmsg);

    xSemaphoreGive(g_mainpq.xMsgSemaphore);

    return (M_RET_OK);
}

void qmsd_main_msgque_deinit(void)
{
    if (g_mainpq.xMsgSemaphore) {
        while(1) {
            void *msg;
            unsigned int msglen;
            int ret;

            ret = qmsd_msgque_recv((void **)&msg, &msglen, portMAX_DELAY);

            if (ret < 0) {
                break;
            } else {
                free(msg);
            }
        }
        g_mainpq.firstp = g_mainpq.lastp = NULL;
        g_mainpq.msgcount = 0;
        g_mainpq.msgmax = 0;
        vSemaphoreDelete(g_mainpq.xMsgSemaphore);
    }
}
