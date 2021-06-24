#ifndef __LV_8MS_CTRL_H
#define __LV_8MS_CTRL_H

#define LV_8MS_CTRL_WID_NAME		"wid"
#define LV_8MS_CTRL_CMD_NAME		"cmd"
#define LV_8MS_CTRL_ATTR_NAME	"attr"
#define LV_8MS_CTRL_EVENT_NAME	"event"

#define LV_8MS_CTRL_CMD_SET	"set"
#define LV_8MS_CTRL_CMD_GET	"get"

enum {
    LV_8MS_CTRL_CODE_OK = 0,
    LV_8MS_CTRL_CODE_PARAM_ERROR,
    LV_8MS_CTRL_CODE_WID_NOT_FOUND,
    LV_8MS_CTRL_CODE_FAIL
};

#endif //__LV_8MS_CTRL_H
