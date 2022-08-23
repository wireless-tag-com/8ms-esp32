#pragma once

#include "stdint.h"
#include "qmsd_err.h"

#ifdef __cplusplus
extern "C" {
#endif

#define KEY_MAX_LENGTH 20

typedef enum {
    QMSD_TYPE_U8,
    QMSD_TYPE_U16,
    QMSD_TYPE_U32,
    QMSD_TYPE_I8,
    QMSD_TYPE_I16,
    QMSD_TYPE_I32,
    QMSD_TYPE_FLOAT,
    QMSD_TYPE_STR,
    QMSD_TYPE_BLOB,
    QMSD_TYPE_ANY,
} qmsd_vmm_item_type_t;

typedef union {
    uint8_t u8;
    uint16_t u16;
    uint32_t u32;
    int8_t i8;
    int16_t i16;
    int32_t i32;
    float f32;
    void* point;
    const void* point_const;
} storage_data_t;

typedef struct {
    qmsd_err_t (*init)(uint8_t arg);
    qmsd_err_t (*set_value)(qmsd_vmm_item_type_t type, int32_t key, storage_data_t value, uint32_t length);
    qmsd_err_t (*get_value)(qmsd_vmm_item_type_t type, int32_t key, storage_data_t* out_value, uint32_t* out_length);
    qmsd_err_t (*delete_key)(int32_t key);
    qmsd_err_t (*delete_all)();
    qmsd_err_t (*take_lock)(uint32_t timeout_ticks);
    void       (*release_lock)();
} qmsd_vmm_panel_driver_t;

typedef enum {
    QMSD_VMM_MEM = 0x0,
    QMSD_VMM_MAX,
    QMSD_VMM_NVS,
    QMSD_VMM_RTC_MEM,
} qmsd_vmm_panel_t;

typedef qmsd_err_t (*qmsd_vmm_cb_t)(int32_t key, void* data, uint32_t length, uint32_t timeout_ticks);

qmsd_err_t qmsd_vmm_init(qmsd_vmm_panel_t panel, uint8_t mem_in_psram);

qmsd_err_t qmsd_vmm_delete(qmsd_vmm_panel_t panel, int32_t key);

qmsd_err_t qmsd_vmm_delete_all(qmsd_vmm_panel_t panel);

qmsd_err_t qmsd_vmm_set_update_callback(qmsd_vmm_cb_t cb);

qmsd_err_t qmsd_vmm_set_i8(qmsd_vmm_panel_t panel, int32_t key, int8_t value);

qmsd_err_t qmsd_vmm_set_i16(qmsd_vmm_panel_t panel, int32_t key, int16_t value);

qmsd_err_t qmsd_vmm_set_i32(qmsd_vmm_panel_t panel, int32_t key, int32_t value);

qmsd_err_t qmsd_vmm_set_u8(qmsd_vmm_panel_t panel, int32_t key, uint8_t value);

qmsd_err_t qmsd_vmm_set_u16(qmsd_vmm_panel_t panel, int32_t key, uint16_t value);

qmsd_err_t qmsd_vmm_set_u32(qmsd_vmm_panel_t panel, int32_t key, uint32_t value);

qmsd_err_t qmsd_vmm_set_float(qmsd_vmm_panel_t panel, int32_t key, float value);

qmsd_err_t qmsd_vmm_set_blob(qmsd_vmm_panel_t panel, int32_t key, const void* value, uint32_t length);

qmsd_err_t qmsd_vmm_set_str(qmsd_vmm_panel_t panel, int32_t key, const char* value);

qmsd_err_t qmsd_vmm_get_i8(qmsd_vmm_panel_t panel, int32_t key, int8_t* out_value);

qmsd_err_t qmsd_vmm_get_i16(qmsd_vmm_panel_t panel, int32_t key, int16_t* out_value);

qmsd_err_t qmsd_vmm_get_i32(qmsd_vmm_panel_t panel, int32_t key, int32_t* out_value);

qmsd_err_t qmsd_vmm_get_u8(qmsd_vmm_panel_t panel, int32_t key, uint8_t* out_value);

qmsd_err_t qmsd_vmm_get_u16(qmsd_vmm_panel_t panel, int32_t key, uint16_t* out_value);

qmsd_err_t qmsd_vmm_get_u32(qmsd_vmm_panel_t panel, int32_t key, uint32_t* out_value);

qmsd_err_t qmsd_vmm_get_float(qmsd_vmm_panel_t panel, int32_t key, float* out_value);

qmsd_err_t qmsd_vmm_get_blob(qmsd_vmm_panel_t panel, int32_t key, void* out_value, uint32_t* length);

qmsd_err_t qmsd_vmm_get_str(qmsd_vmm_panel_t panel, int32_t key, char* out_value, uint32_t* length);

qmsd_err_t qmsd_vmm_sync(int32_t key, qmsd_vmm_item_type_t item_type, qmsd_vmm_panel_t from_panel, qmsd_vmm_panel_t to_panel);

// qmsd_err_t qmsd_get_update_key(char* key, qmsd_vmm_panel_t* panel, uint32_t timeout_ticks);

#ifdef __cplusplus
}
#endif
