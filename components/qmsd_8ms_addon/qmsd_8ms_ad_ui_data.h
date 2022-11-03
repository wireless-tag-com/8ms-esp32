#ifndef QMSD_EXC_8MS_UI_DATA_H
#define QMSD_EXC_8MS_UI_DATA_H

#include "qmsd_ui_storage.h"

#ifdef __cplusplus
extern "C"
{
#endif

void qmsd_8ms_ui_storage_init(void);

int qmsd_8ms_ui_storage_set_int(const char* key,int value);
int qmsd_8ms_ui_storage_get_int(const char* key,int def_val);

int qmsd_8ms_ui_storage_set_str(const char* key,const char* value);
char* qmsd_8ms_ui_storage_get_str(const char* key,const char* def_val);

int qmsd_8ms_ui_storage_set_bool(const char* key,bool value);
bool qmsd_8ms_ui_storage_get_bool(const char* key,bool def_val);

int qmsd_8ms_ui_storage_save();
void qmsd_8ms_ui_storage_deinit();
#ifdef __cplusplus
}
#endif

#endif