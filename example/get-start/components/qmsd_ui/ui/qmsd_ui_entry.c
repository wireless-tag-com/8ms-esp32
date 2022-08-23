#include "qmsd_ui_entry.h"
//#include "qmsd_ctrl.h"
#include <stdio.h>
#include <stdlib.h>



/*
* includes
*/

/*
* declear screens
*/

qmsd_img_t g_qmsd_img[] = 
{
    {"clock_bg",&img1639365041009_png},
};

qmsd_font_t g_qmsd_font[] =
{
    {"ali_font_16",&ali_font_16},
    {"ali_font_58",&ali_font_58},
};
extern lv_obj_t* g_logo_boot_scr;
void qmsd_ui_entry(void)
{
    LV_FONT_DECLARE(ali_font_16);

    qmsd_img_res_init(g_qmsd_img,sizeof(g_qmsd_img)/sizeof(g_qmsd_img[0]));
    qmsd_font_res_init(g_qmsd_font,sizeof(g_qmsd_font)/sizeof(g_qmsd_font[0]));
    
    qmsd_screen_build(&screen_main_obj,true);
}

