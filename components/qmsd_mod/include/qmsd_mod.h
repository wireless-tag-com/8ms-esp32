#ifndef __QMSD_MOD_H__
#define __QMSD_MOD_H__
#include <cJSON.h>
#include "qmsd_notifier.h"

/*---------------------------------------------------------------------------------------------*/
/*!< qmsd error code */
#define QMSD_OK 0    /*!< success */
#define QMSD_FAIL -1 /*!< fail */

/*!< qmsd cmd handle error code */
#define QMSD_PARA_PARSE_ERROR 0x01 /*!< Json parameter parse error*/
#define QMSD_NO_CMD_NAME 0x02      /*!< Json not found cmd_name*/
#define QMSD_CMD_NOT_FOUND 0x03    /*!< CMD not found*/

#define QMSD_NO_INIT 0x101      /*!< qm-mod not init */
#define QMSD_NO_MEM_ERROR 0x102 /*!< Out of memory */

#define QMSD_SCAN_NO_FOUND 0x201 /*!< WiFi scan no found ap */

typedef struct qmsd_cmd_struct
{
    char *qmsd_cmd_name;                      /*!< Command name */
    cJSON *(*qmsd_cmd_func)(cJSON *cmd_data); /*!< Command function pointer */
} qmsd_cmd_struct_t;

/**
 * @brief QMSD module init
 *
 * @param sync_callback Command sync callback
 * @param asyn_callback Command asyn callback
 * @return int Error code
 */
int qmsd_mod_init(void);

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

#endif
