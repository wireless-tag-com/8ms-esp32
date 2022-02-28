#ifndef __QMSD_TYPE_H
#define __QMSD_TYPE_H

#ifdef __cplusplus
extern "C"
{
#endif

#define QMSD_CTRL_WID_NAME		"wid"
#define QMSD_CTRL_WID_TYPE		"type"
#define QMSD_CTRL_CMD_NAME		"cmd"
#define QMSD_CTRL_ATTR_NAME	"attr"
#define QMSD_CTRL_EVENT_NAME	"event"

#define QMSD_CTRL_CMD_SET_NAME	"set_statue"
#define QMSD_CTRL_CMD_SET_STYLE	"set_style"
#define QMSD_CTRL_CMD_SEND_EVENT	"send_event"
#define QMSD_CTRL_CMD_GET_NAME	"get"

enum {
    QMSD_CTRL_CODE_OK = 0,
    QMSD_CTRL_CODE_PARAM_ERROR,
    QMSD_CTRL_CODE_WID_NOT_FOUND,
    QMSD_CTRL_CODE_FAIL
};

typedef enum {
    QMSD_CTRL_GET = 0,
    QMSD_CTRL_SET_STATUS,
    QMSD_CTRL_SET_STYLE,
    QMSD_CTRL_SEND_EVENT
}qmsd_ctrl_type;

enum {
    QMSD_EVENT_SCREEN_LOAD,
    QMSD_EVENT_SCREEN_DELETE,
    QMSD_EVENT_WIDGET_REFRESH,
    QMSD_EVENT_FREE_DYNAMIC_IMG,
    _QMSD_EVENT_LAST /** Number of events*/
};
typedef uint8_t qmsd_event;

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif //__QMSD_TYPE_H