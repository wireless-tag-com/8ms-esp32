// #include <stdio.h>
// #include <stdint.h>
#include <string.h>
#include "esp_log.h"
#include "esp_system.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "include/qmsd_mod.h"
#include "include/qmsd_avl.h"
#include "qmsd_notifier.h"

static const char *TAG = "QMSD_MOD";

typedef struct qmsd_node
{
    struct avl_node avl;
    qmsd_cmd_struct_t cmd;
} cmd_node;

static struct avl_tree qmsd_tree;

/**
 * tree init state
 * 0 : no init
 * 1 : inited
 * 2 : register callback
 */
static uint8_t tree_init = 0;

static int __cmp_func(struct avl_node *a, struct avl_node *b, void *aux)
{
    cmd_node *aa, *bb;
    aa = _get_entry(a, cmd_node, avl);
    bb = _get_entry(b, cmd_node, avl);
    int cmp = strcmp(aa->cmd.qmsd_cmd_name, bb->cmd.qmsd_cmd_name);
    if (cmp < 0)
        return -1;
    else if (cmp > 0)
        return 1;
    else
        return 0;
}

static int __qmsd_cmd_err(cJSON *root, int err)
{
    cJSON *respone = cJSON_CreateObject();
    cJSON_AddItemToObject(respone, "code", cJSON_CreateNumber(err));
    cJSON_AddItemToObject(root, "respone", respone);
    return QMSD_FAIL;
}

bool qmsd_mod_register(const qmsd_cmd_struct_t *cmd_array, uint32_t cmd_num)
{
    if (tree_init != 1)
        return false;

    cmd_node *node;
    for (int i = 0; i < cmd_num; i++)
    {
        node = (cmd_node *)malloc(sizeof(cmd_node));
        if (node == NULL)
        {
            ESP_LOGE(TAG, "no memory to register cmd %s", cmd_array[i].qmsd_cmd_name);
            return false;
        }
        node->cmd.qmsd_cmd_name = cmd_array[i].qmsd_cmd_name;
        node->cmd.qmsd_cmd_func = cmd_array[i].qmsd_cmd_func;
        avl_insert(&qmsd_tree, &node->avl, __cmp_func);
    }
    return true;
}

int qmsd_mod_init(void)
{
    avl_init(&qmsd_tree, NULL);
    int ret = qmsd_notifier_init();
    tree_init = 1;

    return ret;
}

void __qmsd_preorder(struct avl_node *root, cJSON *cmd_list)
{
    struct avl_node *p = root;
    if (p == NULL)
    {
        p = qmsd_tree.root;
    }

    cmd_node *node;
    node = _get_entry(p, cmd_node, avl);
    cJSON *item = cJSON_CreateObject();
    cJSON_AddItemToObject(item, "cmd_name", cJSON_CreateString(node->cmd.qmsd_cmd_name));
    cJSON_AddItemToArray(cmd_list, item);

    if (p->left)
        __qmsd_preorder(p->left, cmd_list);

    if (p->right)
        __qmsd_preorder(p->right, cmd_list);
}

int qmsd_mod_call(cJSON *root)
{
    if (tree_init != 1)
        return QMSD_NO_INIT;

    if (root == NULL)
    {
        ESP_LOGE(TAG, "cmd is NULL");
        return QMSD_FAIL;
    }

    cJSON *cmd_name = cJSON_GetObjectItem(root, "cmd_name");
    if (cmd_name == NULL)
    {
        ESP_LOGE(TAG, "not found cmd_name in json");
        return __qmsd_cmd_err(root, QMSD_NO_CMD_NAME);
    }

    struct avl_node *cur;
    cmd_node *node, query;
    query.cmd.qmsd_cmd_name = cmd_name->valuestring;
    cur = avl_search(&qmsd_tree, &query.avl, __cmp_func);
    if (cur == NULL)
    {
        ESP_LOGE(TAG, "not found cmd %s", cmd_name->valuestring);
        return __qmsd_cmd_err(root, QMSD_CMD_NOT_FOUND);
    }
    node = _get_entry(cur, cmd_node, avl);
    node->cmd.qmsd_cmd_func(root);
    return QMSD_OK;
}
