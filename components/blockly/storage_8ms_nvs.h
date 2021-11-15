/**
 * @file storage_8ms_nvs.h
 * @author sk (shuke@wireless-tag.com)
 * @brief 
 * @version 0.1
 * @date 2021-10-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef __storage_8MS_NVS_H
#define __storage_8MS_NVS_H

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "nvs_flash.h"
#include "nvs.h"
/**
 * @brief Init NVS storage the project from 8ms has called this function so you don't have to call again in apps
 * 
 */
void storage_8ms_init();

/**
 * @brief Get an unsigned char in NVS flash
 * 
 * @param key Key of the value to be read
 * @return uint8_t return the value in nvs with a default 0
 */
uint8_t storage_8ms_read_u8(const char* key);

/**
 * @brief Storage an uint8 value in NVS
 * 
 * @param key Key of the value to be read in read function
 * @param input Value of the key
 * @return esp_err_t Error number
 */
esp_err_t storage_8ms_write_u8(const char* key,uint8_t input);

/**
 * @brief Read an int8 value from NVS
 * 
 * @param key Key of the value to be read
 * @return int8_t 
 */
int8_t storage_8ms_read_i8(const char* key);

/**
 * @brief Storage an int8 value in NVS
 * 
 * @param key Key of the value to be read in read function
 * @param input Value of the key
 * @return esp_err_t Error number
 */
esp_err_t storage_8ms_write_i8(const char* key,int8_t input);

/**
 * @brief Read an unsigned int value from NVS
 * 
 * @param key Key of the value to be read in read function
 * @return uint32_t 
 */
uint32_t storage_8ms_read_u32(const char* key);

/**
 * @brief Storage an unsigned int value in NVS
 * 
 * @param key Key of the value to be read in read function
 * @param input Value of the key
 * @return esp_err_t Error number
 */
esp_err_t storage_8ms_write_u32(const char* key,uint32_t input);

/**
 * @brief Read an int value from NVS
 * 
 * @param key Key of the value in nvs storage
 * @return int 
 */
int storage_8ms_read_i32(const char* key);

/**
 * @brief Storage an int value in NVS
 * 
 * @param key Key of the value to be read in read function
 * @param input Value of the key
 * @return esp_err_t Error number
 */
esp_err_t storage_8ms_write_i32(const char* key,int input);

/**
 * @brief read a string into the out put buffer
 * 
 * @param key key of the string in nvs
 * @param output out put buffer
 * @return esp_err_t 
 */
esp_err_t storage_8ms_read_str(const char* key,char** output);

/**
 * @brief Storage an unsigned int value in NVS
 * 
 * @param key Key of the value to be read in read function
 * @param input Value of the key
 * @return esp_err_t Error number
 */
esp_err_t storage_8ms_write_str(const char* key,char* input);

/**
 * @brief erase value with the key input
 * 
 * @param key 
 * @param input 
 * @return esp_err_t 
 */
esp_err_t storage_8ms_erase_key(const char* key);

#endif