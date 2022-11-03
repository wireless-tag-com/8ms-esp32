#ifndef __QMSD_MOD_INTERNAL_H__
#define __QMSD_MOD_INTERNAL_H__
#include "qmsd_mod.h"
#include "qmsd_avl.h"
#include "qmsd_notifier.h"

/**
 * @brief
 *
 * @param root
 * @param cmd_list
 */
void __qmsd_preorder(struct avl_node *root, cJSON *cmd_list);
#endif
