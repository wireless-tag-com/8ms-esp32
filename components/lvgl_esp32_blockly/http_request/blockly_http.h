/**
 * @file blockly_http.h
 */

#ifndef BLOCKLY_HTTP_H
#define BLOCKLY_HTTP_H


#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_event.h"
#include "esp_log.h"

#include "lwip/err.h"
#include "lwip/sockets.h"
#include "lwip/sys.h"
#include "lwip/netdb.h"
#include "lwip/dns.h"



/**********************
 *      TYPEDEFS
 **********************/
/** @brief Description of an http message */
typedef struct {
    char *h_server;                     /**< http server */    
    int h_server_len;                    /**< http server len*/ 
    char *h_port;                     /**< http port */
    int h_port_len;                    /**< http port len*/ 
    char *h_url;                     /**< http url */
    int h_url_len;                    /**< http url len*/ 
} blockly_http_msg_t;

/**********************
 * GLOBAL PROTOTYPES
 **********************/
void blockly_http_init();
void blockly_http_loop();
void user_set_http_msg(char *server,char *port,char *url);

/**********************
 *      MACROS
 **********************/


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* BLOCKLY_HTTP_H */

