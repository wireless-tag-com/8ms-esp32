#ifndef __QMSD_CTRL_H
#define __QMSD_CTRL_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C"
{
#endif

/*
 * call from other task
 */
int qmsd_ctrl_str(const char *json_str);

/*
 * call from gui task, no need lock
 */
char *qmsd_ctrl_str_sync(const char *json_str);

/*
 * call from other task, sync be false
 * if sync to true, will wait for gui task
 */
int qmsd_ctrl_cjson(const char *wid, qmsd_ctrl_type type, const cJSON *attr, bool sync);

/*
 * call from gui task, no need lock
 */
int qmsd_ctrl_cjson_gui(const char *wid, qmsd_ctrl_type type, const cJSON *attr);

#ifdef __cplusplus
}
#endif

#endif //__QMSD_CTRL_H