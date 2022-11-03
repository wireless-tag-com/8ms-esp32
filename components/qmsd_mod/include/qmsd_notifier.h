#ifndef __QMSD_NOTIFIER_H
#define __QMSD_NOTIFIER_H

#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"

#ifdef __cplusplus
extern "C"
{
#endif

#define QMSD_NOTIFY_DONE 0x0000		 /* Don't care */
#define QMSD_NOTIFY_OK 0x0001		 /* Suits me */
#define QMSD_NOTIFY_STOP_MASK 0x8000 /* Don't call further */
#define QMSD_NOTIFY_BAD (QMSD_NOTIFY_STOP_MASK | 0x0002)
	/* Bad/Veto action */
/*
 * Clean way to return from the notifier and stop further calls.
 */
#define QMSD_NOTIFY_STOP (QMSD_NOTIFY_OK | QMSD_NOTIFY_STOP_MASK)

struct qmsd_notifier_block;

typedef int (*qmsd_notifier_fn_t)(struct qmsd_notifier_block *nb,
									unsigned int action, void *data);

struct qmsd_notifier_block
{
	qmsd_notifier_fn_t notifier_call;
	struct qmsd_notifier_block *next;
	int priority;
};

struct qmsd_notifier_head
{
	SemaphoreHandle_t rwsem;
	struct qmsd_notifier_block *head;
};

int qmsd_notifier_init(void);
int qmsd_notifier_uninit(void);
int qmsd_notifier_call(unsigned int action, void *v);
int qmsd_notifier_register(struct qmsd_notifier_block *n);
int qmsd_notifier_unregister(struct qmsd_notifier_block *n);
int qmsd_notifier_call_nolock(unsigned int action, void *v);

#ifdef __cplusplus
}
#endif

#endif //__QMSD_NOTIFIER_H