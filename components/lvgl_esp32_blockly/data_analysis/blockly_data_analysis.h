#ifndef BLOCKLY_DATA_ANALYSIS_H
#define BLOCKLY_DATA_ANALYSIS_H

#ifdef __cplusplus
extern "C" {
#endif
/*********************
 *      INCLUDES
 *********************/

#include "cJSON.h"

/*********************
 *      DEFINES
 *********************/

#define VLAUE_LEN 32

/**********************
 *      TYPEDEFS
 **********************/



/**********************
 * GLOBAL PROTOTYPES
 **********************/


/**********************
 *      MACROS
 **********************/

void json_init( const char* jsonStr);
char* json_getValue(char* key);
void json_delete(void);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif