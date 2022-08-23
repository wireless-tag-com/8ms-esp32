#pragma once

#include "stdint.h"
#include "qmsd_utils.h"

#ifdef __cplusplus
extern "C" {
#endif

#define TOUCH_MAX_POINT_NUMBER (1)

typedef enum {
    TOUCH_MIRROR_X = 0x40, /**< Mirror X-axis */
    TOUCH_MIRROR_Y = 0x20, /**< Mirror Y-axis */
    TOUCH_SWAP_XY  = 0x80, /**< Swap XY axis */
} touch_panel_dir_t;

typedef enum {
    TOUCH_EVT_RELEASE = 0x0,  /*!< Release event */
    TOUCH_EVT_PRESS   = 0x1,  /*!< Press event */
} touch_panel_event_t;

typedef struct {
    touch_panel_event_t event;   /*!< Event of touch */
    uint8_t point_num;           /*!< Touch point number */
    uint16_t curx[TOUCH_MAX_POINT_NUMBER];            /*!< Current x coordinate */
    uint16_t cury[TOUCH_MAX_POINT_NUMBER];            /*!< Current y coordinate */
} touch_panel_points_t;

typedef struct {
    int8_t scl_pin;
    int8_t sda_pin;
    uint8_t i2c_num;
    uint32_t i2c_freq;
    int8_t intr_pin;                               /*-1: disable*/ 
    int8_t rst_pin;                                /*-1: disable*/
    uint16_t width;                                /*!< touch panel width */
    uint16_t height;                               /*!< touch panel height */
    touch_panel_dir_t direction;                   /*!< Rotate direction */
    int8_t task_en;
    int8_t task_priority;
    int8_t task_core;
}  touch_panel_config_t;

typedef struct {
    /**
    * @brief Initial touch panel
    * @attention If you have been called function touch_panel_init() that will call this function automatically, and should not be called it again.
    *
    * @param config Pointer to a structure with touch config arguments.
    *
    * @return
    *     - ESP_OK Success
    *     - ESP_FAIL Fail
    */
    qmsd_err_t (*init)(const touch_panel_config_t *config);

    /**
    * @brief Deinitial touch panel
    *
    * @return
    *     - ESP_OK Success
    *     - ESP_FAIL Fail
    */
    qmsd_err_t (*deinit)(void);

    /**
    * @brief Get current touch information, see struct touch_panel_points_t
    *
    * @param point a pointer of touch_panel_points_t contained touch information.
    *
    * @return
    *     - ESP_OK Success
    *     - ESP_FAIL Fail
    */
    qmsd_err_t (*read_point_data)(touch_panel_points_t *point);
} touch_panel_driver_t;

extern touch_panel_driver_t touch_ft5x06_driver;

qmsd_err_t touch_init(touch_panel_driver_t* touch_panel, touch_panel_config_t* panel_config);

qmsd_err_t touch_read_points(touch_panel_points_t *point);

uint32_t touch_get_last_press_ticks();

void touch_deinit();

#ifdef __cplusplus
}
#endif
