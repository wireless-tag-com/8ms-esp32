#pragma once

#define FT5x06_DEVICE_MODE                0x00
#define FT5x06_GESTURE_ID                 0x01
#define FT5x06_TOUCH_POINTS               0x02

#define FT5x06_TOUCH1_EV_FLAG             0x03
#define FT5x06_TOUCH1_XH                  0x03
#define FT5x06_TOUCH1_XL                  0x04
#define FT5x06_TOUCH1_YH                  0x05
#define FT5x06_TOUCH1_YL                  0x06

#define FT5x06_TOUCH2_EV_FLAG             0x09
#define FT5x06_TOUCH2_XH                  0x09
#define FT5x06_TOUCH2_XL                  0x0A
#define FT5x06_TOUCH2_YH                  0x0B
#define FT5x06_TOUCH2_YL                  0x0C

#define FT5x06_TOUCH3_EV_FLAG             0x0F
#define FT5x06_TOUCH3_XH                  0x0F
#define FT5x06_TOUCH3_XL                  0x10
#define FT5x06_TOUCH3_YH                  0x11
#define FT5x06_TOUCH3_YL                  0x12

#define FT5x06_TOUCH4_EV_FLAG             0x15
#define FT5x06_TOUCH4_XH                  0x15
#define FT5x06_TOUCH4_XL                  0x16
#define FT5x06_TOUCH4_YH                  0x17
#define FT5x06_TOUCH4_YL                  0x18

#define FT5x06_TOUCH5_EV_FLAG             0x1B
#define FT5x06_TOUCH5_XH                  0x1B
#define FT5x06_TOUCH5_XL                  0x1C
#define FT5x06_TOUCH5_YH                  0x1D
#define FT5x06_TOUCH5_YL                  0x1E

#define FT5X0X_REG_THGROUP                0x80   /* touch threshold related to sensitivity */
#define FT5X0X_REG_THPEAK                 0x81
#define FT5X0X_REG_THCAL                  0x82
#define FT5X0X_REG_THWATER                0x83
#define FT5X0X_REG_THTEMP                 0x84
#define FT5X0X_REG_THDIFF                 0x85
#define FT5X0X_REG_CTRL                   0x86
#define FT5X0X_REG_TIMEENTERMONITOR       0x87
#define FT5X0X_REG_PERIODACTIVE           0x88   /* report rate */
#define FT5X0X_REG_PERIODMONITOR          0x89
#define FT5X0X_REG_HEIGHT_B               0x8a
#define FT5X0X_REG_MAX_FRAME              0x8b
#define FT5X0X_REG_DIST_MOVE              0x8c
#define FT5X0X_REG_DIST_POINT             0x8d
#define FT5X0X_REG_FEG_FRAME              0x8e
#define FT5X0X_REG_SINGLE_CLICK_OFFSET    0x8f
#define FT5X0X_REG_DOUBLE_CLICK_TIME_MIN  0x90
#define FT5X0X_REG_SINGLE_CLICK_TIME      0x91
#define FT5X0X_REG_LEFT_RIGHT_OFFSET      0x92
#define FT5X0X_REG_UP_DOWN_OFFSET         0x93
#define FT5X0X_REG_DISTANCE_LEFT_RIGHT    0x94
#define FT5X0X_REG_DISTANCE_UP_DOWN       0x95
#define FT5X0X_REG_ZOOM_DIS_SQR           0x96
#define FT5X0X_REG_RADIAN_VALUE           0x97
#define FT5X0X_REG_MAX_X_HIGH             0x98
#define FT5X0X_REG_MAX_X_LOW              0x99
#define FT5X0X_REG_MAX_Y_HIGH             0x9a
#define FT5X0X_REG_MAX_Y_LOW              0x9b
#define FT5X0X_REG_K_X_HIGH               0x9c
#define FT5X0X_REG_K_X_LOW                0x9d
#define FT5X0X_REG_K_Y_HIGH               0x9e
#define FT5X0X_REG_K_Y_LOW                0x9f
#define FT5X0X_REG_AUTO_CLB_MODE          0xa0
#define FT5X0X_REG_LIB_VERSION_H          0xa1
#define FT5X0X_REG_LIB_VERSION_L          0xa2
#define FT5X0X_REG_CIPHER                 0xa3
#define FT5X0X_REG_MODE                   0xa4
#define FT5X0X_REG_PMODE                  0xa5   /* Power Consume Mode        */
#define FT5X0X_REG_FIRMID                 0xa6   /* Firmware version */
#define FT5X0X_REG_STATE                  0xa7
#define FT5X0X_REG_FT5201ID               0xa8
#define FT5X0X_REG_ERR                    0xa9
#define FT5X0X_REG_CLB                    0xaa
