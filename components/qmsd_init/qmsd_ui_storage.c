
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#include "cJSON.h"
#include "esp_log.h"
#include "esp_system.h"
#include "esp_partition.h"
#include "esp_log.h"
#include "qmsd_ui_storage.h"

#define TAG "qmsd_ui_storage"

static cJSON *__qmsd_ui_storage_load(char *filename)
{
    cJSON *ui_data = NULL;
    const esp_partition_t *data_partition;
    data_partition = esp_partition_find_first(ESP_PARTITION_TYPE_DATA, ESP_PARTITION_SUBTYPE_ANY, filename);
    if (!data_partition)
    {
        ESP_LOGI(TAG,"Find partition fail.");
        return NULL;
    }

    unsigned char* out = malloc(3);
    esp_partition_read(data_partition,0,out,3);

    uint32_t res_len=(out[0]<<16)+(out[1]<<8)+out[2];
    if(res_len >= 0xfffffc)
    {
        free(out);
        return NULL;
    }

    char* data=malloc(res_len+1);
	if (data) {
    esp_partition_read(data_partition,3,data,res_len);
    data[res_len]='\0';

    ui_data = cJSON_Parse(data);
    free(data);
    free(out);
	}

    return ui_data;
}

cJSON *qmsd_ui_storage_init(const char *filename, bool create)
{
    cJSON *json = NULL;
    if (filename) {
        json = __qmsd_ui_storage_load(filename);
    }

    if (json == NULL) {
        if (create)
            json = cJSON_CreateObject();
    }

    return json;
}

int qmsd_ui_storage_set_int(const cJSON *json, const char *key, const int val)
{
    if (json) {
        cJSON * item = cJSON_GetObjectItem(json, key);
        if (item) {
            cJSON_DeleteItemFromObject(json ,key);
            cJSON_AddNumberToObject(json, key, val);
        } else {
            cJSON_AddNumberToObject(json, key, val);
        }

        return 0;
    }

    return -1;
}

int qmsd_ui_storage_set_int_array(const cJSON *json, const char *key, const int *val, int count)
{
    if (json) {
        cJSON * item = cJSON_GetObjectItem(json, key);
        if (item) {
            cJSON_DeleteItemFromObject(json ,key);
            item = cJSON_CreateIntArray(val, count);
            cJSON_AddItemToObject(json, key, item);
        } else {
            item = cJSON_CreateIntArray(val, count);
            cJSON_AddItemToObject(json, key, item);
        }

        return 0;
    }

    return -1;
}

int qmsd_ui_storage_set_double_array(const cJSON *json, const char *key, const double *val, int count)
{
    if (json) {
        cJSON * item = cJSON_GetObjectItem(json, key);
        if (item) {
            cJSON_DeleteItemFromObject(json ,key);
            item = cJSON_CreateDoubleArray(val, count);
            cJSON_AddItemToObject(json, key, item);
        } else {
            item = cJSON_CreateDoubleArray(val, count);
            cJSON_AddItemToObject(json, key, item);
        }

        return 0;
    }

    return -1;
}

int qmsd_ui_storage_set_str_array(const cJSON *json, const char *key, const char **val, int count)
{
    if (json) {
        cJSON * item = cJSON_GetObjectItem(json, key);
        if (item) {
            cJSON_DeleteItemFromObject(json ,key);
            item = cJSON_CreateStringArray(val, count);
            cJSON_AddItemToObject(json, key, item);
        } else {
            item = cJSON_CreateStringArray(val, count);
            cJSON_AddItemToObject(json, key, item);
        }

        return 0;
    }

    return -1;
}

int qmsd_ui_storage_get_array_size(const cJSON *json, const char *key, int *size)
{
    if (json) {
        cJSON * array = cJSON_GetObjectItem(json, key);
        if (array == NULL)
            return -1;

        if (array->type == cJSON_Array) {
            *size = cJSON_GetArraySize(array);

            return 0;
        }
        return -1;
    }

    return -1;
}

int qmsd_ui_storage_list_int_array(const cJSON *json, const char *key, qmsd_ui_storage_list_cb cb)
{
    if (json) {
        cJSON * array = cJSON_GetObjectItem(json, key);
        if (array == NULL)
            return -1;

        if (array->type == cJSON_Array) {
            int size = cJSON_GetArraySize(array);
            int i;

            for (i = 0; i < size; i++) {
                cJSON *item = cJSON_GetArrayItem(array, i);
                if (item) {
                    if (item && (item->type == cJSON_Number))
                        cb((void *)&item->valueint, i);
                }
            }

            return 0;
        }
        return -1;
    }

    return -1;
}

int qmsd_ui_storage_list_double_array(const cJSON *json, const char *key, qmsd_ui_storage_list_cb cb)
{
    if (json) {
        cJSON * array = cJSON_GetObjectItem(json, key);
        if (array == NULL)
            return -1;

        if (array->type == cJSON_Array) {
            int size = cJSON_GetArraySize(array);
            int i;

            for (i = 0; i < size; i++) {
                cJSON *item = cJSON_GetArrayItem(array, i);
                if (item && (item->type == cJSON_Number))
                    cb((void *)&item->valuedouble, i);
            }

            return 0;
        }
        return -1;
    }

    return -1;
}

int qmsd_ui_storage_list_str_array(const cJSON *json, const char *key, qmsd_ui_storage_list_cb cb)
{
    if (json) {
        cJSON * array = cJSON_GetObjectItem(json, key);
        if (array == NULL)
            return -1;

        if (array->type == cJSON_Array) {
            int size = cJSON_GetArraySize(array);
            int i;

            for (i = 0; i < size; i++) {
                cJSON *item = cJSON_GetArrayItem(array, i);
                if (item && (item->type == cJSON_String))
                    cb((void *)item->valuestring, i);
            }

            return 0;
        }
        return -1;
    }

    return -1;
}

int qmsd_ui_storage_get_int(const cJSON *json, const char *key, int *val)
{
    if (json) {
        cJSON *item = cJSON_GetObjectItem(json, key);
        if (item) {
            if (item->type == cJSON_Number) {
                *val = item->valueint;
                return 0;
            }
        }

        return -1;
    }

    return -1;
}

int qmsd_ui_storage_set_double(const cJSON *json, const char *key, const double val)
{
    if (json) {
        cJSON * item = cJSON_GetObjectItem(json, key);
        if (item) {
            cJSON_DeleteItemFromObject(json ,key);
            cJSON_AddNumberToObject(json, key, val);
        } else {
            cJSON_AddNumberToObject(json, key, val);
        }

        return 0;
    }

    return -1;
}

int qmsd_ui_storage_get_double(const cJSON *json, const char *key, double *val)
{
    if (json) {
        cJSON *item = cJSON_GetObjectItem(json, key);
        if (item) {
            if (item->type == cJSON_Number) {
                *val = item->valuedouble;
                return 0;
            }
        }

        return -1;
    }

    return -1;
}

int qmsd_ui_storage_set_bool(const cJSON *json, const char *key, const bool val)
{
    if (json) {
        cJSON * item = cJSON_GetObjectItem(json, key);
        if (item) {
            cJSON_DeleteItemFromObject(json ,key);
            cJSON_AddBoolToObject(json, key, val);
        } else {
            cJSON_AddBoolToObject(json, key, val);
        }

        return 0;
    }

    return -1;
}

int qmsd_ui_storage_get_bool(const cJSON *json, const char *key, bool *val)
{
    if (json) {
        cJSON *item = cJSON_GetObjectItem(json, key);
        if (item) {
            if (item->type == cJSON_True) {
                *val = true;
                return 0;
            } else if (item->type == cJSON_False) {
                *val = false;
                return 0;
            }
        }

        return -1;
    }

    return -1;
}

int qmsd_ui_storage_set_str(const cJSON *json, const char *key, const char *val)
{
    if (json) {
        cJSON * item = cJSON_GetObjectItem(json, key);
        if (item) {
            cJSON_DeleteItemFromObject(json ,key);
            cJSON_AddStringToObject(json, key, val);
        } else {
            cJSON_AddStringToObject(json, key, val);
        }

        return 0;
    }

    return -1;
}

char *qmsd_ui_storage_get_str(const cJSON *json, const char *key)
{
    if (json) {
        cJSON *item = cJSON_GetObjectItem(json, key);
        if (item) {
            if (item->type == cJSON_String) {
                return item->valuestring;
            }
        }

        return NULL;
    }

    return NULL;
}

int qmsd_ui_storage_save(cJSON *json, const char *filename)
{
    if (filename && json) {
        const esp_partition_t *data_partition;
        data_partition = esp_partition_find_first(ESP_PARTITION_TYPE_DATA, ESP_PARTITION_SUBTYPE_ANY, filename);
        if (!data_partition)
        {
            ESP_LOGI(TAG,"Find partition fail.");
            return -1;
        }

        esp_partition_erase_range(data_partition,0,0x1000);
        unsigned char head[3];
        char* data=cJSON_PrintUnformatted(json);
        uint32_t data_len= strlen(data);
        head[0]=(data_len&0xff0000)>>16;
        head[1]=(data_len&0x00ff00)>>8;
        head[2]=(data_len&0x0000ff);
        esp_partition_write(data_partition,0,head,3);
        esp_partition_write(data_partition,3,data,data_len);
        free(data);

        return 0;
    }

    return -1;
}

void qmsd_ui_storage_deinit(cJSON *json)
{
    if (json) {
        cJSON_Delete(json);
        json = NULL;
    }
}
