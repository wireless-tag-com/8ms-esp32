#include "blockly_data_analysis.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_event.h"
#include "esp_log.h"


static const char *TAG = "blockly_data_analysis_main";

cJSON* cjson;

void json_init( const char* jsonStr)
{
    cjson = cJSON_Parse(jsonStr);
    if(cjson == NULL)
        ESP_LOGI(TAG,"cjson error…");
}

static void _get_data(char *output, char* key, unsigned char *layer)
{
    unsigned char i, num=0, temp_key_len=0 ;
    for (i = 0; i < strlen(key); i++)
    {
        if ((key[i] == '.') || (i == strlen(key)) || (key[i] == '\0'))
        {
            num++;
            ESP_LOGI(TAG, "temp_key_len = %d", temp_key_len);
            if (num==(*layer)+1)
            {
                ESP_LOGI(TAG, "K = [%s]--", output);
                break;
            }
            temp_key_len = 0;   
        }
        else
        {
            if (num == (*layer))
            {
                output[temp_key_len] = key[i];
            }
            temp_key_len++;
            
        }
    }// 取第layer层键
}

static void  _find_num(char *pcBuf, char *pcRes, const char* begBuf, const char* endBuf)
{
	char *pcBegin ;
	char *pcEnd ;
 
	pcBegin = strstr(pcBuf, begBuf);
	pcEnd = strstr(pcBuf, endBuf);
    if(pcBegin == NULL || pcEnd == NULL || pcBegin > pcEnd)
	{
        strcpy(pcRes, pcBuf);
	}
	else
	{
	    if(strcmp(begBuf, ""))
            pcBegin += 1;
        memcpy(pcRes, pcBegin, pcEnd-pcBegin);
    }
}

char jsonValue[VLAUE_LEN] = {0};
static void _json_parse(cJSON *json, char *key, unsigned char layer)
{
    char i,K[VLAUE_LEN]={0};
    char Key[VLAUE_LEN]={0};
    static cJSON *p_parent = NULL;
    memset(jsonValue,0,sizeof(char)*VLAUE_LEN);
    _get_data(Key, key, &layer);
    printf("%s\n",Key);
    _find_num(Key, K, "", "[");
    printf("%s\n",K);
    if (json != NULL)
    {
        if (cJSON_HasObjectItem(json, K) == true)
        {
            p_parent = cJSON_GetObjectItem(json, K);
            ESP_LOGI(TAG,"warning\n");
            ESP_LOGI(TAG, "p_parent=\n--p_parent->type = %d--", p_parent->type);
            ESP_LOGI(TAG, "%s", cJSON_Print(p_parent));
            if (!p_parent)
            {
                ESP_LOGI(TAG, "p_parent not found\n");
            }
            else
            {
                switch (p_parent->type)
                {
                case cJSON_False:
                    ESP_LOGI(TAG, "cJSON_False\n");
                    break;
                case cJSON_NULL:
                    ESP_LOGI(TAG, "cJSON_NULL\n");
                    break;
                case cJSON_Number:
                    sprintf(jsonValue, "%d", p_parent->valueint);
                    memcpy(jsonValue, p_parent->valuestring, strlen(p_parent->valuestring));
                    ESP_LOGI(TAG, "value = [%s]\n", jsonValue);
                    break;
                case cJSON_String:
                    memcpy(jsonValue, p_parent->valuestring, strlen(p_parent->valuestring));
                    ESP_LOGI(TAG, "value = [%s]\n", jsonValue);
                    break;
                case cJSON_Array:
                    ESP_LOGI(TAG, "cJSON_Array\n");
                    _find_num(Key, K, "[", "]");
                    int arr_size = atoi(K);
                    printf("arr_size:%d\n",arr_size);
                    // 切换对象
                    cJSON* arr_item = p_parent->child;//子对象
                    for(i = 0;i < arr_size/*0*/;++i){
                        arr_item = arr_item->next;//下一个子对象
                    }
                    layer++;
                    _json_parse(arr_item,key,layer);//递归
                    break;
                case cJSON_Object:
                    ESP_LOGI(TAG, "cJSON_Object\n");
                    break;
                default:
                    break;
                }
            }  
        }      
    }
}


char* json_getValue(char* key)
{
    unsigned char layer = 0;
    if (cjson != NULL)
    {
        _json_parse(cjson, key, layer);
        return jsonValue;
    }
    memset(jsonValue,0,sizeof(jsonValue));
    return jsonValue;
}

void json_delete()
{
    memset(jsonValue,0,sizeof(jsonValue));
    cJSON_Delete(cjson);
}