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
#include "cJSON.h"
#include "qmsd_storage.h"
#include "qmsd_lang.h"

#define QMSD_LANG_NS   "lang"
#define QMSD_LANG_KEY   "lang"

static char *g_qmsd_lang;
static char *g_trans_entry;
static size_t g_trans_entry_size;

int qmsd_lang_init(const char *def_lang)
{
    char lang[16];
    esp_err_t ret;
    ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND)
    {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);

    esp_err_t err = nvs_flash_init_partition(QMSD_LANG_PARTITION);
    if (err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        err = nvs_flash_init_partition(QMSD_LANG_PARTITION);
    }

    if (err != ESP_OK) {
        return -1;
    }

    memset(lang, 0, sizeof(lang));
    ret = qmsd_storage_get_str(QMSD_LANG_NS, QMSD_LANG_KEY, lang, sizeof(lang) - 1);
    if (ret == ESP_OK) {
        qmsd_lang_set(lang);
    } else {
        qmsd_lang_set(def_lang);
    }

    return 0;
}

int qmsd_lang_set(const char *lang)
{
    int ret = -1;

    if (lang) {
        if (g_qmsd_lang) {
            free(g_qmsd_lang);
            g_qmsd_lang = NULL;
        }
        g_qmsd_lang = strdup(lang);

        if (g_qmsd_lang)
            ret = 0;
    }

    return ret;
}

int qmsd_lang_save(const char *lang)
{
    int ret;
    ret = qmsd_lang_set(lang);
    qmsd_storage_set_str(QMSD_LANG_NS, QMSD_LANG_KEY, lang);

    return ret;
}

char *qmsd_lang_get(void)
{
    return g_qmsd_lang;
}

char *qmsd_lang_get_trans(const char *key, char *def_val)
{
    esp_err_t err = ESP_FAIL;

    if (key && g_qmsd_lang) {
        nvs_handle_t my_handle;

        err = nvs_open_from_partition(QMSD_LANG_PARTITION, g_qmsd_lang, NVS_READONLY, &my_handle);
        if (err == ESP_OK) {
            size_t tmp_size;
            err = nvs_get_str(my_handle, key, NULL, &tmp_size);
            if (err == ESP_OK) {
                if ((tmp_size + 1) < g_trans_entry_size) {
                    memset(g_trans_entry, 0, g_trans_entry_size);
                    nvs_get_str(my_handle, key, g_trans_entry, &tmp_size);
                } else {
                    if (g_trans_entry) {
                        free(g_trans_entry);
                        g_trans_entry_size = 0;
                    }
                    g_trans_entry = malloc(tmp_size + 1);
                    if (g_trans_entry) {
                        g_trans_entry_size = tmp_size + 1;
                        memset(g_trans_entry, 0, g_trans_entry_size);
                        nvs_get_str(my_handle, key, g_trans_entry, &tmp_size);
                    }
                }
            }

            nvs_close(my_handle);

            if (g_trans_entry)
                return g_trans_entry;
        }
    }

    return def_val;
}

void qmsd_lang_deinit(void)
{
    if (g_qmsd_lang) {
        free(g_qmsd_lang);
        free(g_trans_entry);
        g_trans_entry_size = 0;
        g_trans_entry = NULL;
        g_qmsd_lang = NULL;
    }
}
