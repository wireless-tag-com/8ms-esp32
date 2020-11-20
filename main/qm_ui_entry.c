#include "qm_ui_entry.h"
#include <stdio.h>
#include <stdlib.h>

lv_obj_t *main_screen;

/**
 * @brief 
 * @param 
 * @return 
 */
void show_screen_main_screen()
{
    lv_scr_load(main_screen);
}

/**
 * @brief 
 * @param 
 * @return 
 */
void init_function()
{
#ifdef BLOCKLY_INIT
    blockly_init();
#endif
}

/**
 * @brief 
 * @param 
 * @return 
 */
void lv_qm_ui_loop(void)
{
#ifdef BLOCKLY_LOOP
    blockly_loop();
#endif
}

/**
 * @brief 
 * @param 
 * @return 
 */
void lv_qm_ui_entry(void)
{
    LV_FONT_DECLARE(ali_font_16);
    lv_font_montserrat_16 = ali_font_16;

    main_screen = lv_obj_create(NULL, NULL);

    init_function();
}

/**
* @brief blockly initialization
*/

void lvgl_blockly_init()
{
#ifdef WT_WIFI
    blockly_wifi_init();
#endif // DEBUG
#ifdef WT_BLUFI
    blockly_blufi_init();
#endif // DEBUG
#ifdef WT_HTTP_REQUEST
    blockly_http_init();
#endif // WT_HTTP_REQUEST
}

/**
* @brief blockly loop
*/

void lvgl_blockly_loop()
{
#ifdef WT_BLUFI
    blockly_blufi_loop();
#endif // DEBUG
#ifdef WT_WIFI
    blockly_wifi_loop();
#endif // DEBUG
#ifdef WT_HTTP_REQUEST
    blockly_http_loop();
#endif // WT_HTTP_REQUEST
}


void lvgl_device_init(void)
{
#ifdef ESP32_GPIO
    pinInit();
#endif
#ifdef ESP32_TIMER
    timerInit();
#endif
#ifdef ESP32_UART
    serialInit();
#endif
}

void lvgl_device_loop(void)
{
#ifdef ESP32_GPIO
    pinLoop();
#endif
#ifdef ESP32_TIMER
    timerLoop();
#endif
#ifdef ESP32_UART
    serialLoop();
#endif
}