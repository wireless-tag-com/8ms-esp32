#include "qmsd_ui_entry.h"
#include "qmsd_gui_init.h"
#include "qmsd_ui_api.h"
#include <stdio.h>
#include <stdlib.h>

int qmsd_ui_mlable_set(const bool gui, const char *text)
{
    int ret = -1;

    if (gui) {
        if (screen_main_label_1) {
            lv_label_set_text(screen_main_label_1, text);
            ret= 0;
        }
    } else {
        if (qmsd_gui_lock(portMAX_DELAY) == 0) {
            if (screen_main_label_1) {
                lv_label_set_text(screen_main_label_1, text);
                ret= 0;
            }
            qmsd_gui_unlock();
        }
    }

    return ret;
}