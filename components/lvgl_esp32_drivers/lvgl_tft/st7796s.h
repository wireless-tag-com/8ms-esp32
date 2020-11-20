/**
 * @file ST7796S.h
 *
 * Mostly taken from lbthomsen/esp-idf-littlevgl github.
 */

#ifndef ST7796S_H
#define ST7796S_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "lvgl/lvgl.h"
#include "../lvgl_helpers.h"

#include "sdkconfig.h"

#define ST7796S_DC       CONFIG_LVGL_DISP_PIN_DC
#define ST7796S_RST      CONFIG_LVGL_DISP_PIN_RST
#define ST7796S_BCKL     CONFIG_LVGL_DISP_PIN_BCKL

#define ST7796S_ENABLE_BACKLIGHT_CONTROL CONFIG_LVGL_ENABLE_BACKLIGHT_CONTROL

#if CONFIG_LVGL_BACKLIGHT_ACTIVE_LVL
  #define ST7796S_BCKL_ACTIVE_LVL 1
#else
  #define ST7796S_BCKL_ACTIVE_LVL 0
#endif

/* ST7796S commands */
#define ST7796S_NOP      0x00
#define ST7796S_SWRESET  0x01
#define ST7796S_RDDID    0x04
#define ST7796S_RDDST    0x09

#define ST7796S_RDDPM        0x0A    // Read display power mode
#define ST7796S_RDD_MADCTL   0x0B    // Read display MADCTL
#define ST7796S_RDD_COLMOD   0x0C    // Read display pixel format
#define ST7796S_RDDIM        0x0D    // Read display image mode
#define ST7796S_RDDSM        0x0E    // Read display signal mode
#define ST7796S_RDDSR        0x0F    // Read display self-diagnostic result (ST7796SV)

#define ST7796S_SLPIN        0x10
#define ST7796S_SLPOUT       0x11
#define ST7796S_PTLON        0x12
#define ST7796S_NORON        0x13

#define ST7796S_INVOFF       0x20
#define ST7796S_INVON        0x21
#define ST7796S_GAMSET       0x26    // Gamma set
#define ST7796S_DISPOFF      0x28
#define ST7796S_DISPON       0x29
#define ST7796S_CASET        0x2A
#define ST7796S_RASET        0x2B
#define ST7796S_RAMWR        0x2C
#define ST7796S_RGBSET       0x2D    // Color setting for 4096, 64K and 262K colors
#define ST7796S_RAMRD        0x2E

#define ST7796S_PTLAR        0x30
#define ST7796S_VSCRDEF      0x33    // Vertical scrolling definition (ST7796SV)
#define ST7796S_TEOFF        0x34    // Tearing effect line off
#define ST7796S_TEON         0x35    // Tearing effect line on
#define ST7796S_MADCTL       0x36    // Memory data access control
#define ST7796S_IDMOFF       0x38    // Idle mode off
#define ST7796S_IDMON        0x39    // Idle mode on
#define ST7796S_RAMWRC       0x3C    // Memory write continue (ST7796SV)
#define ST7796S_RAMRDC       0x3E    // Memory read continue (ST7796SV)
#define ST7796S_COLMOD       0x3A

#define ST7796S_RAMCTRL      0xB0    // RAM control
#define ST7796S_RGBCTRL      0xB1    // RGB control
#define ST7796S_PORCTRL      0xB2    // Porch control
#define ST7796S_FRCTRL1      0xB3    // Frame rate control
#define ST7796S_PARCTRL      0xB5    // Partial mode control
#define ST7796S_GCTRL        0xB7    // Gate control
#define ST7796S_GTADJ        0xB8    // Gate on timing adjustment
#define ST7796S_DGMEN        0xBA    // Digital gamma enable
#define ST7796S_VCOMS        0xBB    // VCOMS setting
#define ST7796S_LCMCTRL      0xC0    // LCM control
#define ST7796S_IDSET        0xC1    // ID setting
#define ST7796S_VDVVRHEN     0xC2    // VDV and VRH command enable
#define ST7796S_VRHS         0xC3    // VRH set
#define ST7796S_VDVSET       0xC4    // VDV setting
#define ST7796S_VCMOFSET     0xC5    // VCOMS offset set
#define ST7796S_FRCTR2       0xC6    // FR Control 2
#define ST7796S_CABCCTRL     0xC7    // CABC control
#define ST7796S_REGSEL1      0xC8    // Register value section 1
#define ST7796S_REGSEL2      0xCA    // Register value section 2
#define ST7796S_PWMFRSEL     0xCC    // PWM frequency selection
#define ST7796S_PWCTRL1      0xD0    // Power control 1
#define ST7796S_VAPVANEN     0xD2    // Enable VAP/VAN signal output
#define ST7796S_CMD2EN       0xDF    // Command 2 enable
#define ST7796S_PVGAMCTRL    0xE0    // Positive voltage gamma control
#define ST7796S_NVGAMCTRL    0xE1    // Negative voltage gamma control
#define ST7796S_DGMLUTR      0xE2    // Digital gamma look-up table for red
#define ST7796S_DGMLUTB      0xE3    // Digital gamma look-up table for blue
#define ST7796S_GATECTRL     0xE4    // Gate control
#define ST7796S_SPI2EN       0xE7    // SPI2 enable
#define ST7796S_PWCTRL2      0xE8    // Power control 2
#define ST7796S_EQCTRL       0xE9    // Equalize time control
#define ST7796S_PROMCTRL     0xEC    // Program control
#define ST7796S_PROMEN       0xFA    // Program mode enable
#define ST7796S_NVMSET       0xFC    // NVM setting
#define ST7796S_PROMACT      0xFE    // Program action

void st7796s_init(void);
void st7796s_flush(lv_disp_drv_t *drv, const lv_area_t *area, lv_color_t *color_map);
void st7796s_enable_backlight(bool backlight);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* ST7796S_H  */
