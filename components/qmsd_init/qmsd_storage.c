#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_freertos_hooks.h"
#include "freertos/semphr.h"
#include "qmsd_storage.h"

static SemaphoreHandle_t g_qmsd_storage_sem = NULL;

/**
 * @brief Init NVS storage the project from qmsd has called this function so you don't have to call again in apps
 * 
 */
void qmsd_storage_init(void)
{
    esp_err_t ret;
    ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND)
    {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);

    const esp_partition_t *data_partition;
    data_partition = esp_partition_find_first(ESP_PARTITION_TYPE_DATA, ESP_PARTITION_SUBTYPE_ANY, QMSD_STORAGE_PARTITION);
    if (!data_partition)
    {
        return;
    }

    esp_err_t err = nvs_flash_init_partition(QMSD_STORAGE_PARTITION);
    if (err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        err = nvs_flash_init_partition(QMSD_STORAGE_PARTITION);
    }
    ESP_ERROR_CHECK(err);

    g_qmsd_storage_sem = xSemaphoreCreateMutex();
}

esp_err_t qmsd_storage_set_blob(const char *name, const char *key, void *data, size_t length)
{
    nvs_handle handle;
    esp_err_t res = ESP_FAIL;
    res = nvs_open_from_partition(QMSD_STORAGE_PARTITION, name, NVS_READWRITE, &handle);
    if (res != ESP_OK)
    {
        printf("nvs open fail %s", esp_err_to_name(res));
        return res;
    }

    if (g_qmsd_storage_sem) {
        if (pdTRUE == xSemaphoreTake(g_qmsd_storage_sem, portMAX_DELAY)) {
            res = nvs_set_blob(handle, key, data, length);
            if (res != ESP_OK)
            {
                printf("nvs set blob fail %s\n", esp_err_to_name(res));
                xSemaphoreGive(g_qmsd_storage_sem);
                return res;
            }

            res = nvs_commit(handle);
            if (res != ESP_OK)
            {
                printf("nvs commit fail %s", esp_err_to_name(res));
                xSemaphoreGive(g_qmsd_storage_sem);
                return res;
            }

            nvs_close(handle);
            xSemaphoreGive(g_qmsd_storage_sem);
        }
    }

    return res;
}

esp_err_t qmsd_storage_get_blob(const char *name, const char *key, void *data, size_t length)
{
    nvs_handle handle;
    esp_err_t res = ESP_FAIL;
    res = nvs_open_from_partition(QMSD_STORAGE_PARTITION, name, NVS_READONLY, &handle);
    if (res != ESP_OK)
    {
        printf("nvs open fail %s", esp_err_to_name(res));
        return res;
    }

    if (g_qmsd_storage_sem) {
        if (pdTRUE == xSemaphoreTake(g_qmsd_storage_sem, portMAX_DELAY)) {
            res = nvs_get_blob(handle, key, data, &length);
            if (res != ESP_OK)
            {
                printf("size %d\n", length);
                printf("nvs get blob fail %s\n", esp_err_to_name(res));
                xSemaphoreGive(g_qmsd_storage_sem);
                return res;
            }

            nvs_close(handle);
            xSemaphoreGive(g_qmsd_storage_sem);
        }
    }

    return res;
}

/**
 * @brief Get an unsigned char in NVS flash
 * 
 * @param namespace Namespace of the value to read
 * @param key Key of the value to be read
 * @return uint8_t return the value in nvs with a default 0
 */
esp_err_t qmsd_storage_get_u8(const char *namespace, const char *key, uint8_t *value)
{
    nvs_handle_t my_handle;
    esp_err_t err = ESP_FAIL;

    if (g_qmsd_storage_sem) {
        if (pdTRUE == xSemaphoreTake(g_qmsd_storage_sem, portMAX_DELAY)) {
            err = nvs_open_from_partition(QMSD_STORAGE_PARTITION, namespace, NVS_READONLY, &my_handle);
            if (err != ESP_OK) {
                printf("Error (%s) opening NVS handle!\n", esp_err_to_name(err));
                xSemaphoreGive(g_qmsd_storage_sem);
                return err;
            } else {
                uint8_t u8_res = 0; // value will default to 0, if not set yet in NVS
                err = nvs_get_u8(my_handle, key, &u8_res);
                switch (err) {
                    case ESP_OK:
                        break;
                    case ESP_ERR_NVS_NOT_FOUND:
                        printf("The value is not initialized yet!\n");
                        break;
                    default :
                        printf("Error (%s) reading!\n", esp_err_to_name(err));
                }
                *value = u8_res;
                nvs_close(my_handle);
                xSemaphoreGive(g_qmsd_storage_sem);
                return err;
            }
        }
    }

    return err;
}

/**
 * @brief Storage an uint8 value in NVS
 * 
 * @param namespace Namespace of the value to read
 * @param key Key of the value to be read in read function
 * @param input Value of the key
 * @return esp_err_t Error number
 */
esp_err_t qmsd_storage_set_u8(const char *namespace, const char* key,uint8_t input)
{
    nvs_handle_t my_handle;
    esp_err_t err = ESP_FAIL;

    if (g_qmsd_storage_sem) {
        if (pdTRUE == xSemaphoreTake(g_qmsd_storage_sem, portMAX_DELAY)) {
            err = nvs_open_from_partition(QMSD_STORAGE_PARTITION, namespace, NVS_READWRITE, &my_handle);
            if (err != ESP_OK) {
                printf("Error (%s) opening NVS handle!\n", esp_err_to_name(err));
                xSemaphoreGive(g_qmsd_storage_sem);
                return err;
            } else {
                err = nvs_set_u8(my_handle, key,input);
                switch (err) {
                    case ESP_OK:
                        err = nvs_commit(my_handle);
                        break;
                    default :
                        printf("Error (%s) reading!\n", esp_err_to_name(err));
                        return err;
                }
                nvs_close(my_handle);
            }

            xSemaphoreGive(g_qmsd_storage_sem);
            return err;
        }
    }

    return err;
}

/**
 * @brief Read an int8 value from NVS
 * 
 * @param key Key of the value to be read
 * @return int8_t 
 */
esp_err_t qmsd_storage_get_i8(const char *namespace, const char *key, int8_t *value)
{
    nvs_handle_t my_handle;
    esp_err_t err = ESP_FAIL;

    if (g_qmsd_storage_sem) {
        if (pdTRUE == xSemaphoreTake(g_qmsd_storage_sem, portMAX_DELAY)) {
            err = nvs_open_from_partition(QMSD_STORAGE_PARTITION, namespace, NVS_READWRITE, &my_handle);
            if (err != ESP_OK) {
                printf("Error (%s) opening NVS handle!\n", esp_err_to_name(err));
                xSemaphoreGive(g_qmsd_storage_sem);
                return 0;
            } else {
                int8_t i8_res = 0; // value will default to 0, if not set yet in NVS
                err = nvs_get_i8(my_handle, key, &i8_res);
                switch (err) {
                    case ESP_OK:
                        break;
                    case ESP_ERR_NVS_NOT_FOUND:
                        printf("The value is not initialized yet!\n");
                        break;
                    default :
                        printf("Error (%s) reading!\n", esp_err_to_name(err));
                }
                *value = i8_res;
                nvs_close(my_handle);
                xSemaphoreGive(g_qmsd_storage_sem);
                return err;
            }
        }
    }

    return err;
}

/**
 * @brief Storage an int8 value in NVS
 * 
 * @param key Key of the value to be read in read function
 * @param input Value of the key
 * @return esp_err_t Error number
 */
esp_err_t qmsd_storage_set_i8(const char *namespace, const char* key,int8_t input)
{
    nvs_handle_t my_handle;
    esp_err_t err = ESP_FAIL;

    if (g_qmsd_storage_sem) {
        if (pdTRUE == xSemaphoreTake(g_qmsd_storage_sem, portMAX_DELAY)) {
            err = nvs_open_from_partition(QMSD_STORAGE_PARTITION, namespace, NVS_READWRITE, &my_handle);
            if (err != ESP_OK) {
                printf("Error (%s) opening NVS handle!\n", esp_err_to_name(err));
                xSemaphoreGive(g_qmsd_storage_sem);
                return err;
            } else {
                err = nvs_set_i8(my_handle, key,input);
                switch (err) {
                    case ESP_OK:
                        err = nvs_commit(my_handle);
                        break;
                    default :
                        printf("Error (%s) reading!\n", esp_err_to_name(err));
                        return err;
                }

                nvs_close(my_handle);
            }
            xSemaphoreGive(g_qmsd_storage_sem);
        }
    }

    return err;
}

/**
 * @brief Read an int8 value from NVS
 * 
 * @param key Key of the value to be read
 * @return int8_t 
 */
esp_err_t qmsd_storage_get_u16(const char *namespace, const char *key, uint16_t *value)
{
    nvs_handle_t my_handle;
    esp_err_t err = ESP_FAIL;

    if (g_qmsd_storage_sem) {
        if (pdTRUE == xSemaphoreTake(g_qmsd_storage_sem, portMAX_DELAY)) {
            err = nvs_open_from_partition(QMSD_STORAGE_PARTITION, namespace, NVS_READWRITE, &my_handle);
            if (err != ESP_OK) {
                printf("Error (%s) opening NVS handle!\n", esp_err_to_name(err));
                xSemaphoreGive(g_qmsd_storage_sem);
                return err;
            } else {
                uint16_t tmp_res = 0; // value will default to 0, if not set yet in NVS
                err = nvs_get_u16(my_handle, key, &tmp_res);
                switch (err) {
                    case ESP_OK:
                        break;
                    case ESP_ERR_NVS_NOT_FOUND:
                        printf("The value is not initialized yet!\n");
                        break;
                    default :
                        printf("Error (%s) reading!\n", esp_err_to_name(err));
                }
                *value = tmp_res;
                nvs_close(my_handle);
                xSemaphoreGive(g_qmsd_storage_sem);
                return err;
            }
        }
    }

    return err;
}

/**
 * @brief Storage an int8 value in NVS
 * 
 * @param key Key of the value to be read in read function
 * @param input Value of the key
 * @return esp_err_t Error number
 */
esp_err_t qmsd_storage_set_u16(const char *namespace, const char* key,uint16_t input)
{
    nvs_handle_t my_handle;
    esp_err_t err = ESP_FAIL;

    if (g_qmsd_storage_sem) {
        if (pdTRUE == xSemaphoreTake(g_qmsd_storage_sem, portMAX_DELAY)) {
            err = nvs_open_from_partition(QMSD_STORAGE_PARTITION, namespace, NVS_READWRITE, &my_handle);
            if (err != ESP_OK) {
                printf("Error (%s) opening NVS handle!\n", esp_err_to_name(err));
                xSemaphoreGive(g_qmsd_storage_sem);
                return err;
            } else {
                err = nvs_set_u16(my_handle, key,input);
                switch (err) {
                    case ESP_OK:
                        err = nvs_commit(my_handle);
                        break;
                    default :
                        printf("Error (%s) reading!\n", esp_err_to_name(err));
                        return err;
                }

                nvs_close(my_handle);
            }
            xSemaphoreGive(g_qmsd_storage_sem);
        }
    }

    return err;
}

/**
 * @brief Read an int16 value from NVS
 * 
 * @param key Key of the value to be read
 * @return int8_t 
 */
esp_err_t qmsd_storage_get_i16(const char *namespace, const char *key, int16_t *value)
{
    nvs_handle_t my_handle;
    esp_err_t err = ESP_FAIL;

    if (g_qmsd_storage_sem) {
        if (pdTRUE == xSemaphoreTake(g_qmsd_storage_sem, portMAX_DELAY)) {
            err = nvs_open_from_partition(QMSD_STORAGE_PARTITION, namespace, NVS_READWRITE, &my_handle);
            if (err != ESP_OK) {
                printf("Error (%s) opening NVS handle!\n", esp_err_to_name(err));
                xSemaphoreGive(g_qmsd_storage_sem);
                return err;
            } else {
                int16_t tmp_res = 0; // value will default to 0, if not set yet in NVS
                err = nvs_get_i16(my_handle, key, &tmp_res);
                switch (err) {
                    case ESP_OK:
                        break;
                    case ESP_ERR_NVS_NOT_FOUND:
                        printf("The value is not initialized yet!\n");
                        break;
                    default :
                        printf("Error (%s) reading!\n", esp_err_to_name(err));
                }
                *value = tmp_res;
                nvs_close(my_handle);
                xSemaphoreGive(g_qmsd_storage_sem);
                return err;
            }
        }
    }

    return err;
}

/**
 * @brief Storage an int16 value in NVS
 * 
 * @param key Key of the value to be read in read function
 * @param input Value of the key
 * @return esp_err_t Error number
 */
esp_err_t qmsd_storage_set_i16(const char *namespace, const char* key,int16_t input)
{
    nvs_handle_t my_handle;
    esp_err_t err = ESP_FAIL;

    if (g_qmsd_storage_sem) {
        if (pdTRUE == xSemaphoreTake(g_qmsd_storage_sem, portMAX_DELAY)) {
            err = nvs_open_from_partition(QMSD_STORAGE_PARTITION, namespace, NVS_READWRITE, &my_handle);
            if (err != ESP_OK) {
                printf("Error (%s) opening NVS handle!\n", esp_err_to_name(err));
                xSemaphoreGive(g_qmsd_storage_sem);
                return err;
            } else {
                err = nvs_set_i16(my_handle, key,input);
                switch (err) {
                    case ESP_OK:
                        err = nvs_commit(my_handle);
                        break;
                    default :
                        printf("Error (%s) reading!\n", esp_err_to_name(err));
                        return err;
                }

                nvs_close(my_handle);
            }
            xSemaphoreGive(g_qmsd_storage_sem);
        }
    }

    return err;
}

/**
 * @brief 
 * 
 * @param key Key of the value to be read in read function
 * @return uint32_t 
 */
esp_err_t qmsd_storage_get_u32(const char*namespace, const char* key, uint32_t *value)
{
    nvs_handle_t my_handle;
    esp_err_t err = ESP_FAIL;

    if (g_qmsd_storage_sem) {
        if (pdTRUE == xSemaphoreTake(g_qmsd_storage_sem, portMAX_DELAY)) {
            err = nvs_open_from_partition(QMSD_STORAGE_PARTITION, namespace, NVS_READWRITE, &my_handle);
            if (err != ESP_OK) {
                printf("Error (%s) opening NVS handle!\n", esp_err_to_name(err));
                xSemaphoreGive(g_qmsd_storage_sem);
                return err;
            } else {
                uint32_t i32_res = 0; // value will default to 0, if not set yet in NVS
                err = nvs_get_u32(my_handle, key, &i32_res);
                switch (err) {
                    case ESP_OK:
                        break;
                    case ESP_ERR_NVS_NOT_FOUND:
                        printf("The value is not initialized yet!\n");
                        break;
                    default :
                        printf("Error (%s) reading!\n", esp_err_to_name(err));
                }
                *value = i32_res;
                nvs_close(my_handle);
                xSemaphoreGive(g_qmsd_storage_sem);
                return err;
            }
        }
    }

    return err;
}

/**
 * @brief Storage an unsigned int value in NVS
 * 
 * @param key Key of the value to be read in read function
 * @param input Value of the key
 * @return esp_err_t Error number
 */
esp_err_t qmsd_storage_set_u32(const char*namespace, const char* key, uint32_t input)
{
    nvs_handle_t my_handle;
    esp_err_t err = ESP_FAIL;

    if (g_qmsd_storage_sem) {
        if (pdTRUE == xSemaphoreTake(g_qmsd_storage_sem, portMAX_DELAY)) {
            err = nvs_open_from_partition(QMSD_STORAGE_PARTITION, namespace, NVS_READWRITE, &my_handle);
            if (err != ESP_OK) {
                printf("Error (%s) opening NVS handle!\n", esp_err_to_name(err));
                xSemaphoreGive(g_qmsd_storage_sem);
                return err;
            } else {
                err = nvs_set_u32(my_handle, key,input);
                switch (err) {
                    case ESP_OK:
                        err = nvs_commit(my_handle);
                        break;
                    default :
                        printf("Error (%s) reading!\n", esp_err_to_name(err));
                        return err;
                }

                nvs_close(my_handle);
            }
            xSemaphoreGive(g_qmsd_storage_sem);
        }
    }

    return err;
}

esp_err_t qmsd_storage_get_i32(const char*namespace, const char* key, int32_t *value)
{
    nvs_handle_t my_handle;
    esp_err_t err = ESP_FAIL;

    if (g_qmsd_storage_sem) {
        if (pdTRUE == xSemaphoreTake(g_qmsd_storage_sem, portMAX_DELAY)) {
            err = nvs_open_from_partition(QMSD_STORAGE_PARTITION, namespace, NVS_READWRITE, &my_handle);
            if (err != ESP_OK) {
                printf("Error (%s) opening NVS handle!\n", esp_err_to_name(err));
                xSemaphoreGive(g_qmsd_storage_sem);
                return err;
            } else {
                int32_t i32_res = 0; // value will default to 0, if not set yet in NVS
                err = nvs_get_i32(my_handle, key, &i32_res);
                switch (err) {
                    case ESP_OK:
                        break;
                    case ESP_ERR_NVS_NOT_FOUND:
                        printf("The value is not initialized yet!\n");
                        break;
                    default :
                        printf("Error (%s) reading!\n", esp_err_to_name(err));
                }
                *value = i32_res;
                nvs_close(my_handle);
                xSemaphoreGive(g_qmsd_storage_sem);
                return err;
            }
        }
    }

    return err;
}

/**
 * @brief Storage an int value in NVS
 * 
 * @param key Key of the value to be read in read function
 * @param input Value of the key
 * @return esp_err_t Error number
 */
esp_err_t qmsd_storage_set_i32(const char*namespace, const char* key,int32_t input)
{
    nvs_handle_t my_handle;
    esp_err_t err = ESP_FAIL;

    if (g_qmsd_storage_sem) {
        if (pdTRUE == xSemaphoreTake(g_qmsd_storage_sem, portMAX_DELAY)) {
            err = nvs_open_from_partition(QMSD_STORAGE_PARTITION, namespace, NVS_READWRITE, &my_handle);
            if (err != ESP_OK) {
                printf("Error (%s) opening NVS handle!\n", esp_err_to_name(err));
                xSemaphoreGive(g_qmsd_storage_sem);
                return err;
            } else {
                err = nvs_set_i32(my_handle, key,input);
                switch (err) {
                    case ESP_OK:
                        err = nvs_commit(my_handle);
                        break;
                    default :
                        printf("Error (%s) reading!\n", esp_err_to_name(err));
                        return err;
                }

                nvs_close(my_handle);
            }
            xSemaphoreGive(g_qmsd_storage_sem);
        }
    }

    return err;
}

/**
 * @brief 
 * 
 * @param key Key of the value to be read in read function
 * @return uint32_t 
 */
esp_err_t qmsd_storage_get_u64(const char*namespace, const char* key, uint64_t *value)
{
    nvs_handle_t my_handle;
    esp_err_t err = ESP_FAIL;

    if (g_qmsd_storage_sem) {
        if (pdTRUE == xSemaphoreTake(g_qmsd_storage_sem, portMAX_DELAY)) {
            err = nvs_open_from_partition(QMSD_STORAGE_PARTITION, namespace, NVS_READWRITE, &my_handle);
            if (err != ESP_OK) {
                printf("Error (%s) opening NVS handle!\n", esp_err_to_name(err));
                xSemaphoreGive(g_qmsd_storage_sem);
                return err;
            } else {
                uint64_t tmp_res = 0; // value will default to 0, if not set yet in NVS
                err = nvs_get_u64(my_handle, key, &tmp_res);
                switch (err) {
                    case ESP_OK:
                        break;
                    case ESP_ERR_NVS_NOT_FOUND:
                        printf("The value is not initialized yet!\n");
                        break;
                    default :
                        printf("Error (%s) reading!\n", esp_err_to_name(err));
                }
                *value = tmp_res;
                nvs_close(my_handle);
                xSemaphoreGive(g_qmsd_storage_sem);
                return err;
            }
        }
    }

    return err;
}

/**
 * @brief Storage an unsigned int value in NVS
 * 
 * @param key Key of the value to be read in read function
 * @param input Value of the key
 * @return esp_err_t Error number
 */
esp_err_t qmsd_storage_set_u64(const char*namespace, const char* key, uint64_t input)
{
    nvs_handle_t my_handle;
    esp_err_t err = ESP_FAIL;

    if (g_qmsd_storage_sem) {
        if (pdTRUE == xSemaphoreTake(g_qmsd_storage_sem, portMAX_DELAY)) {
            err = nvs_open_from_partition(QMSD_STORAGE_PARTITION, namespace, NVS_READWRITE, &my_handle);
            if (err != ESP_OK) {
                printf("Error (%s) opening NVS handle!\n", esp_err_to_name(err));
                xSemaphoreGive(g_qmsd_storage_sem);
                return err;
            } else {
                err = nvs_set_u64(my_handle, key,input);
                switch (err) {
                    case ESP_OK:
                        err = nvs_commit(my_handle);
                        break;
                    default :
                        printf("Error (%s) reading!\n", esp_err_to_name(err));
                        return err;
                }

                nvs_close(my_handle);
            }
            xSemaphoreGive(g_qmsd_storage_sem);
        }
    }

    return err;
}

esp_err_t qmsd_storage_get_i64(const char*namespace, const char* key, int64_t *value)
{
    nvs_handle_t my_handle;
    esp_err_t err = ESP_FAIL;

    if (g_qmsd_storage_sem) {
        if (pdTRUE == xSemaphoreTake(g_qmsd_storage_sem, portMAX_DELAY)) {
            err = nvs_open_from_partition(QMSD_STORAGE_PARTITION, namespace, NVS_READWRITE, &my_handle);
            if (err != ESP_OK) {
                printf("Error (%s) opening NVS handle!\n", esp_err_to_name(err));
                xSemaphoreGive(g_qmsd_storage_sem);
                return err;
            } else {
                int64_t tmp_res = 0; // value will default to 0, if not set yet in NVS
                err = nvs_get_i64(my_handle, key, &tmp_res);
                switch (err) {
                    case ESP_OK:
                        break;
                    case ESP_ERR_NVS_NOT_FOUND:
                        printf("The value is not initialized yet!\n");
                        break;
                    default :
                        printf("Error (%s) reading!\n", esp_err_to_name(err));
                }
                *value = tmp_res;
                nvs_close(my_handle);
                xSemaphoreGive(g_qmsd_storage_sem);
                return err;
            }
        }
    }

    return err;
}

/**
 * @brief Storage an int64 value in NVS
 * 
 * @param key Key of the value to be read in read function
 * @param input Value of the key
 * @return esp_err_t Error number
 */
esp_err_t qmsd_storage_set_i64(const char*namespace, const char* key,int64_t input)
{
    nvs_handle_t my_handle;
    esp_err_t err = ESP_FAIL;

    if (g_qmsd_storage_sem) {
        if (pdTRUE == xSemaphoreTake(g_qmsd_storage_sem, portMAX_DELAY)) {
            err = nvs_open_from_partition(QMSD_STORAGE_PARTITION, namespace, NVS_READWRITE, &my_handle);
            if (err != ESP_OK) {
                printf("Error (%s) opening NVS handle!\n", esp_err_to_name(err));
                xSemaphoreGive(g_qmsd_storage_sem);
                return err;
            } else {
                err = nvs_set_i64(my_handle, key,input);
                switch (err) {
                    case ESP_OK:
                        err = nvs_commit(my_handle);
                        break;
                    default :
                        printf("Error (%s) reading!\n", esp_err_to_name(err));
                        return err;
                }

                nvs_close(my_handle);
            }
            xSemaphoreGive(g_qmsd_storage_sem);
        }
    }

    return err;
}

esp_err_t qmsd_storage_get_str_size(const char*namespace, const char* key, size_t *str_size)
{
    nvs_handle_t my_handle;
    esp_err_t err = ESP_FAIL;

    if (g_qmsd_storage_sem) {
        if (pdTRUE == xSemaphoreTake(g_qmsd_storage_sem, portMAX_DELAY)) {
            err = nvs_open_from_partition(QMSD_STORAGE_PARTITION, namespace, NVS_READWRITE, &my_handle);
            if (err != ESP_OK) {
                printf("Error (%s) opening NVS handle!\n", esp_err_to_name(err));
                xSemaphoreGive(g_qmsd_storage_sem);
                return err;
            } else {
                size_t tmp_size;
                err = nvs_get_str(my_handle, key, NULL, &tmp_size);
                nvs_close(my_handle);
                if (err == ESP_OK) {
                    *str_size = tmp_size;
                } else {
                    *str_size = 0;
                }
                xSemaphoreGive(g_qmsd_storage_sem);
                return err;
            }   
        }
    }

    return err;
}

esp_err_t qmsd_storage_get_str(const char*namespace, const char* key,char *output, size_t size)
{
    nvs_handle_t my_handle;
    esp_err_t err = ESP_FAIL;

    if (g_qmsd_storage_sem) {
        if (pdTRUE == xSemaphoreTake(g_qmsd_storage_sem, portMAX_DELAY)) {
            err = nvs_open_from_partition(QMSD_STORAGE_PARTITION, namespace, NVS_READWRITE, &my_handle);
            if (err != ESP_OK) {
                printf("Error (%s) opening NVS handle!\n", esp_err_to_name(err));
                xSemaphoreGive(g_qmsd_storage_sem);
                return err;
            } else {
                err = nvs_get_str(my_handle, key, output, &size);
                nvs_close(my_handle);
                xSemaphoreGive(g_qmsd_storage_sem);
                return err;
            }
        }
    }

    return err;
}

/**
 * @brief Storage an unsigned int value in NVS
 * 
 * @param key Key of the value to be read in read function
 * @param input Value of the key
 * @return esp_err_t Error number
 */
esp_err_t qmsd_storage_set_str(const char*namespace, const char* key,char* input)
{
    nvs_handle_t my_handle;
    esp_err_t err = ESP_FAIL;

    if (g_qmsd_storage_sem) {
        if (pdTRUE == xSemaphoreTake(g_qmsd_storage_sem, portMAX_DELAY)) {
            err = nvs_open_from_partition(QMSD_STORAGE_PARTITION, namespace, NVS_READWRITE, &my_handle);
            if (err != ESP_OK) {
                printf("Error (%s) opening NVS handle!\n", esp_err_to_name(err));
                xSemaphoreGive(g_qmsd_storage_sem);
                return err;
            } else {
                err = nvs_set_str(my_handle, key,input);
                switch (err) {
                    case ESP_OK:
                        err = nvs_commit(my_handle);
                        
                        break;
                    default :
                        printf("Error (%s) reading!\n", esp_err_to_name(err));
                        return err;
                }
                nvs_close(my_handle);  
            }
            xSemaphoreGive(g_qmsd_storage_sem);
        }
    }

    return err;
}

esp_err_t qmsd_storage_clear_key(const char*namespace, const char* key)
{
    nvs_handle_t my_handle;
    esp_err_t err = ESP_FAIL;

    if (g_qmsd_storage_sem) {
        if (pdTRUE == xSemaphoreTake(g_qmsd_storage_sem, portMAX_DELAY)) {
            err = nvs_open_from_partition(QMSD_STORAGE_PARTITION, namespace, NVS_READWRITE, &my_handle);
            if (err != ESP_OK) {
                printf("Error (%s) opening NVS handle!\n", esp_err_to_name(err));
                xSemaphoreGive(g_qmsd_storage_sem);
                return err;
            } else {
                err = nvs_erase_key(my_handle, key);
                switch (err) {
                    case ESP_OK:
                        err = nvs_commit(my_handle);
                        break;
                    default :
                        printf("Error (%s) reading!\n", esp_err_to_name(err));
                        return err;
                }
                nvs_close(my_handle);
            }
            xSemaphoreGive(g_qmsd_storage_sem);
        }
    }

    return err;
}

esp_err_t qmsd_storage_clear_namespace(const char*namespace)
{
    nvs_handle_t my_handle;
    esp_err_t err = ESP_FAIL;

    if (g_qmsd_storage_sem) {
        if (pdTRUE == xSemaphoreTake(g_qmsd_storage_sem, portMAX_DELAY)) {
            err = nvs_open_from_partition(QMSD_STORAGE_PARTITION, namespace, NVS_READWRITE, &my_handle);
            if (err != ESP_OK) {
                printf("Error (%s) opening NVS handle!\n", esp_err_to_name(err));
                xSemaphoreGive(g_qmsd_storage_sem);
                return err;
            } else {
                err = nvs_erase_all(my_handle);
                switch (err) {
                    case ESP_OK:
                        err = nvs_commit(my_handle);
                        break;
                    default :
                        printf("Error (%s) reading!\n", esp_err_to_name(err));
                        return err;
                }
                nvs_close(my_handle);
            }
            xSemaphoreGive(g_qmsd_storage_sem);
        }
    }

    return err;
}

esp_err_t qmsd_storage_clear_all(void)
{
    esp_err_t err = ESP_FAIL;

    if (g_qmsd_storage_sem) {
        if (pdTRUE == xSemaphoreTake(g_qmsd_storage_sem, portMAX_DELAY)) {
            err = nvs_flash_erase_partition(QMSD_STORAGE_PARTITION);
            xSemaphoreGive(g_qmsd_storage_sem);
        }
    }

    return err;
}
