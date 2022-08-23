/**
 * @file storage_qmsd_nvs.h
 * @author sk (shuke@wireless-tag.com)
 * @brief 
 * @version 0.1
 * @date 2021-10-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef __QMSD_STORAGE_NVS_H
#define __QMSD_STORAGE_NVS_H

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "nvs_flash.h"
#include "nvs.h"

#define QMSD_STORAGE_PARTITION  "qmsd_storage"

void qmsd_storage_init(void);
esp_err_t qmsd_storage_get_blob(const char *name, const char *key, void *data, size_t length);
esp_err_t qmsd_storage_set_blob(const char *name, const char *key, void *data, size_t length);
esp_err_t qmsd_storage_get_u8(const char *namespace, const char *key, uint8_t *value);
esp_err_t qmsd_storage_set_u8(const char *namespace, const char* key,uint8_t input);
esp_err_t qmsd_storage_get_i8(const char *namespace, const char *key, int8_t *value);
esp_err_t qmsd_storage_set_i8(const char *namespace, const char* key,int8_t input);
esp_err_t qmsd_storage_get_u16(const char *namespace, const char *key, uint16_t *value);
esp_err_t qmsd_storage_set_u16(const char *namespace, const char* key,uint16_t input);
esp_err_t qmsd_storage_get_i16(const char *namespace, const char *key, int16_t *value);
esp_err_t qmsd_storage_set_i16(const char *namespace, const char* key,int16_t input);
esp_err_t qmsd_storage_get_u32(const char*namespace, const char* key, uint32_t *value);
esp_err_t qmsd_storage_set_u32(const char*namespace, const char* key,uint32_t input);
esp_err_t qmsd_storage_get_i32(const char*namespace, const char* key, int32_t *value);
esp_err_t qmsd_storage_set_i32(const char*namespace, const char* key,int32_t input);
esp_err_t qmsd_storage_get_i64(const char*namespace, const char* key, int64_t *value);
esp_err_t qmsd_storage_set_i64(const char*namespace, const char* key,int64_t input);
esp_err_t qmsd_storage_get_u64(const char*namespace, const char* key, uint64_t *value);
esp_err_t qmsd_storage_set_u64(const char*namespace, const char* key,uint64_t input);
esp_err_t qmsd_storage_get_str_size(const char*namespace, const char* key, size_t *str_size);
esp_err_t qmsd_storage_get_str(const char*namespace, const char* key,char *output, size_t size);
esp_err_t qmsd_storage_set_str(const char*namespace, const char* key,char* input);

esp_err_t qmsd_storage_clear_key(const char*namespace, const char* key);
esp_err_t qmsd_storage_clear_namespace(const char*namespace);
esp_err_t qmsd_storage_clear_all(void);

#endif