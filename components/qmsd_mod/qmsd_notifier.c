#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "qmsd_notifier.h"
#include "esp_log.h"

#define TAG "QMSD NOTIFIER"

static struct qmsd_notifier_head g_qmsd_notifier;

static int __qmsd_notifier_register(struct qmsd_notifier_block **nl,
									struct qmsd_notifier_block *n)
{
	while ((*nl) != NULL)
	{
		if (n->priority > (*nl)->priority)
			break;
		nl = &((*nl)->next);
	}
	n->next = *nl;
	*nl = n;
	return 0;
}

static int __qmsd_notifier_unregister(struct qmsd_notifier_block **nl,
									  struct qmsd_notifier_block *n)
{
	while ((*nl) != NULL)
	{
		if ((*nl) == n)
		{
			*nl = n->next;
			return 0;
		}
		nl = &((*nl)->next);
	}
	return -1;
}

static int __qmsd_notifier_call(struct qmsd_notifier_block **nl,
								unsigned int val, void *v,
								int nr_to_call, int *nr_calls)
{
	int ret = QMSD_NOTIFY_DONE;
	struct qmsd_notifier_block *nb, *next_nb;

	nb = *nl;

	while (nb && nr_to_call)
	{
		next_nb = nb->next;

		ret = nb->notifier_call(nb, val, v);

		if (nr_calls)
			(*nr_calls)++;

		if ((ret & QMSD_NOTIFY_STOP_MASK) == QMSD_NOTIFY_STOP_MASK)
			break;
		nb = next_nb;
		nr_to_call--;
	}
	return ret;
}

int qmsd_notifier_register(struct qmsd_notifier_block *n)
{
	int ret;

	xSemaphoreTake(g_qmsd_notifier.rwsem, portMAX_DELAY);
	ret = __qmsd_notifier_register(&g_qmsd_notifier.head, n);
	xSemaphoreGive(g_qmsd_notifier.rwsem);
	return ret;
}

int qmsd_notifier_unregister(struct qmsd_notifier_block *n)
{
	int ret;
	xSemaphoreTake(g_qmsd_notifier.rwsem, portMAX_DELAY);
	ret = __qmsd_notifier_unregister(&g_qmsd_notifier.head, n);
	xSemaphoreGive(g_qmsd_notifier.rwsem);
	return ret;
}

int qmsd_notifier_call_nolock(unsigned int action, void *v)
{
	int ret = QMSD_NOTIFY_DONE;

	ret = __qmsd_notifier_call(&g_qmsd_notifier.head, action, v, -1, NULL);

	return ret;
}

int qmsd_notifier_call(unsigned int action, void *v)
{
	int ret = QMSD_NOTIFY_DONE;

	xSemaphoreTake(g_qmsd_notifier.rwsem, portMAX_DELAY);
	ret = __qmsd_notifier_call(&g_qmsd_notifier.head, action, v, -1, NULL);
	xSemaphoreGive(g_qmsd_notifier.rwsem);

	return ret;
}

int qmsd_notifier_init(void)
{
	g_qmsd_notifier.rwsem = xSemaphoreCreateMutex();
	g_qmsd_notifier.head = NULL;

	return 0;
}

int qmsd_notifier_uninit(void)
{
	vSemaphoreDelete(g_qmsd_notifier.rwsem);
	g_qmsd_notifier.head = NULL;

	return 0;
}