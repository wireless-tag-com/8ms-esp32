#ifndef __QMSD_MOD_H__
#define __QMSD_MOD_H__
#include <cJSON.h>

#define CONFIG_QMSD_WIFI_COMMAND_SUPPORT 1
#define CONFIG_QMSD_HTTP_COMMAND_SUPPORT 1
#define CONFIG_QMSD_MQTT_COMMAND_SUPPORT 1
#define CONFIG_QMSD_SOCKET_COMMAND_SUPPORT 1

#define QMSD_STORAGE_PARTITION "qmsd_storage"

typedef int qmsd_err_t;

/*---------------------------------------------------------------------------------------------*/
/*!< qmsd error code */
#define QMSD_OK 0    /*!< success */
#define QMSD_FAIL -1 /*!< fail */

/*!< qmsd cmd handle error code */
#define QMSD_PARA_PARSE_ERROR 0x01 /*!< Json parameter parse error*/
#define QMSD_NO_CMD_NAME 0x02      /*!< Json not found cmd_name*/
#define QMSD_CMD_NOT_FOUND 0x03    /*!< CMD not found*/

#define QMSD_NO_MEM_ERROR 0x101  /*!< Out of memory */
#define QMSD_SCAN_NO_FOUND 0x201 /*!< Out of memory */

/*---------------------------------------------------------------------------------------------*/
typedef enum
{
    ASYN_EVENT_WIFI_SCAN = 0, /*!< WiFi finish scanning AP */
    ASYN_EVENT_WIFI_CONNECT,  /*!< WiFi connect to AP  */
    ASYN_EVENT_UDP_DATA,      /*!< Socket UDP receive data */
    ASYN_EVENT_TCP_CLIENT,    /*!< Socket TCP CLIENT receive data */
    ASYN_EVENT_TCP_SERVER,    /*!< Socket TCP SERVER receive data */
    ASYN_EVENT_MQTT_DATA,     /*!< MQTT receive data */
} asyn_handler_event_t;

typedef struct qmsd_cmd_struct
{
    char *qmsd_cmd_name;                      /*!< Command name */
    cJSON *(*qmsd_cmd_func)(cJSON *cmd_data); /*!< Command function pointer */
} qmsd_cmd_struct_t;

typedef void (*qmsd_mod_sync_handler)(cJSON *data);
typedef void (*qmsd_mod_asyn_handler)(cJSON *data, asyn_handler_event_t event_id);

/**
 * @brief QMSD module init
 *
 * @param call_back   Command result callback function
 * @return qmsd_err_t Error code
 */
qmsd_err_t qmsd_mod_init();

/**
 * @brief QMSD module register
 *
 * @param cmd_array  Command array
 * @param cmd_num    Command number
 * @return true      Register success
 * @return false     Register fail
 */
bool qmsd_mod_register(const qmsd_cmd_struct_t *cmd_array, uint32_t cmd_num);

/**
 * @brief QMSD module command processing entry
 *
 * @param root cJSON object
 * @return int success or fail
 */
int qmsd_mod_call(cJSON *root);

/**
 * @brief QMSD respone callback register
 *
 * @param sync_callback
 * @param asyn_callback
 * @return qmsd_err_t error code
 */
qmsd_err_t qmsd_mod_callback_register(qmsd_mod_sync_handler sync_callback, qmsd_mod_asyn_handler asyn_callback);

#endif
