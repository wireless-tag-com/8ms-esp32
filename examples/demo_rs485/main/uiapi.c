#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include"qmsd_gui_init.h"
#include "qmsd_ui_entry.h"

/*
 * ui api
 */
void screen_main_show(void)
{
    qmsd_gui_lock(portMAX_DELAY);
    if (screen_main) {
        lv_scr_load(screen_main);
    }
    qmsd_gui_unlock();
}

void screen_test_show(void)
{
    qmsd_gui_lock(portMAX_DELAY);
    if (screen_test) {
        lv_scr_load(screen_test);
    }
    qmsd_gui_unlock();
}