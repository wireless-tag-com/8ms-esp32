#ifndef _QMSD_WIDGET_STYLE_H_
#define _QMSD_WIDGET_STYLE_H_

#include "base_widget_type.h"

#ifdef __cplusplus
extern "C" {
#endif

#if defined QMSD_GUI_LVGL_V7
typedef lv_state_t qmsd_state_t;
#include "lvgl/src/lv_core/lv_obj_style_dec.h"

#ifdef __cplusplus
#define _QMSD_OBJ_GET_STYLE(prop_name, func_name, value_type, style_type)                                \
    static inline value_type qmsd_widget_style_get_##func_name(const qmsd_widget_t * obj, uint8_t part)       \
    {                                                                                               \
        return (value_type)_lv_obj_get_style##style_type(obj, part, LV_STYLE_##prop_name);          \
    }
#else
#define _QMSD_OBJ_GET_STYLE(prop_name, func_name, value_type, style_type)                                \
    static inline value_type qmsd_widget_get_style_##func_name(const qmsd_widget_t * obj, uint8_t part)       \
    {                                                                                               \
        return _lv_obj_get_style##style_type(obj, part, LV_STYLE_##prop_name);                      \
    }
#endif

#define _QMSD_OBJ_SET_STYLE_LOCAL(prop_name, func_name, value_type, style_type)                                                      \
    static inline void qmsd_widget_style_set_##func_name(qmsd_widget_t * obj, uint8_t part, qmsd_state_t state, value_type value)     \
    {                                                                                                                           \
        _lv_obj_set_style_local##style_type(obj, part, LV_STYLE_##prop_name | (state << LV_STYLE_STATE_POS), value);            \
    }

#define _QMSD_OBJ_STYLE_SET_GET_DECLARE(prop_name, func_name, value_type, style_type)                                      \
    _QMSD_OBJ_GET_STYLE(prop_name, func_name, value_type, style_type)                                                         \
    _QMSD_OBJ_SET_STYLE_LOCAL(prop_name, func_name, value_type, style_type)                                                   \

typedef lv_style_int_t qmsd_style_int_t;
typedef lv_opa_t qmsd_opa_t;
typedef lv_color_t qmsd_color_t;

_QMSD_OBJ_STYLE_SET_GET_DECLARE(RADIUS, radius, qmsd_style_int_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(CLIP_CORNER, clip_corner, bool, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(SIZE, size, qmsd_style_int_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(TRANSFORM_WIDTH, transform_width, qmsd_style_int_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(TRANSFORM_HEIGHT, transform_height, qmsd_style_int_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(TRANSFORM_ANGLE, transform_angle, qmsd_style_int_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(TRANSFORM_ZOOM, transform_zoom, qmsd_style_int_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(OPA_SCALE, opa_scale, qmsd_opa_t, _opa)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(PAD_TOP, pad_top, qmsd_style_int_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(PAD_BOTTOM, pad_bottom, qmsd_style_int_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(PAD_LEFT, pad_left, qmsd_style_int_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(PAD_RIGHT, pad_right, qmsd_style_int_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(PAD_INNER, pad_inner, qmsd_style_int_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(MARGIN_TOP, margin_top, qmsd_style_int_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(MARGIN_BOTTOM, margin_bottom, qmsd_style_int_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(MARGIN_LEFT, margin_left, qmsd_style_int_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(MARGIN_RIGHT, margin_right, qmsd_style_int_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(BG_BLEND_MODE, bg_blend_mode, lv_blend_mode_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(BG_MAIN_STOP, bg_main_stop, qmsd_style_int_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(BG_GRAD_STOP, bg_grad_stop, qmsd_style_int_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(BG_GRAD_DIR, bg_grad_dir, lv_grad_dir_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(BG_COLOR, bg_color, qmsd_color_t, _color)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(BG_GRAD_COLOR, bg_grad_color, qmsd_color_t, _color)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(BG_OPA, bg_opa, qmsd_opa_t, _opa)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(BORDER_WIDTH, border_width, qmsd_style_int_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(BORDER_SIDE, border_side, lv_border_side_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(BORDER_BLEND_MODE, border_blend_mode, lv_blend_mode_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(BORDER_POST, border_post, bool, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(BORDER_COLOR, border_color, qmsd_color_t, _color)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(BORDER_OPA, border_opa, qmsd_opa_t, _opa)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(OUTLINE_WIDTH, outline_width, qmsd_style_int_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(OUTLINE_PAD, outline_pad, qmsd_style_int_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(OUTLINE_BLEND_MODE, outline_blend_mode, lv_blend_mode_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(OUTLINE_COLOR, outline_color, qmsd_color_t, _color)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(OUTLINE_OPA, outline_opa, qmsd_opa_t, _opa)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(SHADOW_WIDTH, shadow_width, qmsd_style_int_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(SHADOW_OFS_X, shadow_ofs_x, qmsd_style_int_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(SHADOW_OFS_Y, shadow_ofs_y, qmsd_style_int_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(SHADOW_SPREAD, shadow_spread, qmsd_style_int_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(SHADOW_BLEND_MODE, shadow_blend_mode, lv_blend_mode_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(SHADOW_COLOR, shadow_color, qmsd_color_t, _color)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(SHADOW_OPA, shadow_opa, qmsd_opa_t, _opa)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(PATTERN_REPEAT, pattern_repeat, bool, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(PATTERN_BLEND_MODE, pattern_blend_mode, lv_blend_mode_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(PATTERN_RECOLOR, pattern_recolor, qmsd_color_t, _color)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(PATTERN_OPA, pattern_opa, qmsd_opa_t, _opa)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(PATTERN_RECOLOR_OPA, pattern_recolor_opa, qmsd_opa_t, _opa)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(PATTERN_IMAGE, pattern_image, const void *, _ptr)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(VALUE_LETTER_SPACE, value_letter_space, qmsd_style_int_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(VALUE_LINE_SPACE, value_line_space, qmsd_style_int_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(VALUE_BLEND_MODE, value_blend_mode, lv_blend_mode_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(VALUE_OFS_X, value_ofs_x, qmsd_style_int_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(VALUE_OFS_Y, value_ofs_y, qmsd_style_int_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(VALUE_ALIGN, value_align, lv_align_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(VALUE_COLOR, value_color, qmsd_color_t, _color)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(VALUE_OPA, value_opa, qmsd_opa_t, _opa)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(VALUE_FONT, value_font, const lv_font_t *, _ptr)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(VALUE_STR, value_str, const char *, _ptr)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(TEXT_LETTER_SPACE, text_letter_space, qmsd_style_int_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(TEXT_LINE_SPACE, text_line_space, qmsd_style_int_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(TEXT_DECOR, text_decor, lv_text_decor_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(TEXT_BLEND_MODE, text_blend_mode, lv_blend_mode_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(TEXT_COLOR, text_color, qmsd_color_t, _color)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(TEXT_SEL_COLOR, text_sel_color, qmsd_color_t, _color)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(TEXT_SEL_BG_COLOR, text_sel_bg_color, qmsd_color_t, _color)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(TEXT_OPA, text_opa, qmsd_opa_t, _opa)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(TEXT_FONT, text_font, const lv_font_t *, _ptr)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(LINE_WIDTH, line_width, qmsd_style_int_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(LINE_BLEND_MODE, line_blend_mode, lv_blend_mode_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(LINE_DASH_WIDTH, line_dash_width, qmsd_style_int_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(LINE_DASH_GAP, line_dash_gap, qmsd_style_int_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(LINE_ROUNDED, line_rounded, bool, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(LINE_COLOR, line_color, qmsd_color_t, _color)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(LINE_OPA, line_opa, qmsd_opa_t, _opa)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(IMAGE_BLEND_MODE, image_blend_mode, lv_blend_mode_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(IMAGE_RECOLOR, image_recolor, qmsd_color_t, _color)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(IMAGE_OPA, image_opa, qmsd_opa_t, _opa)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(IMAGE_RECOLOR_OPA, image_recolor_opa, qmsd_opa_t, _opa)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(TRANSITION_TIME, transition_time, qmsd_style_int_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(TRANSITION_DELAY, transition_delay, qmsd_style_int_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(TRANSITION_PROP_1, transition_prop_1, qmsd_style_int_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(TRANSITION_PROP_2, transition_prop_2, qmsd_style_int_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(TRANSITION_PROP_3, transition_prop_3, qmsd_style_int_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(TRANSITION_PROP_4, transition_prop_4, qmsd_style_int_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(TRANSITION_PROP_5, transition_prop_5, qmsd_style_int_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(TRANSITION_PROP_6, transition_prop_6, qmsd_style_int_t, _int)

#define QMSD_COLOR_RGB(r,g,b) (LV_COLOR_MAKE((r),(g),(b)))
#elif defined QMSD_GUI_LVGL_V8
#include "lvgl/src/misc/lv_style_gen.h"
typedef lv_state_t qmsd_state_t;
#define _QMSD_OBJ_GET_STYLE(api_name, func_name, value_type, style_type)                                \
    static inline value_type qmsd_widget_get_style_##func_name(const qmsd_widget_t * obj, uint8_t part)       \
    {                                                                                               \
        return lv_obj_get_style_##api_name(obj, part);                      \
    }

#define _QMSD_OBJ_SET_STYLE_LOCAL(api_name, func_name, value_type, style_type)                                                      \
    static inline void qmsd_widget_style_set_##func_name(qmsd_widget_t * obj, uint32_t part, qmsd_state_t state, value_type value)     \
    {                                                                                                                           \
        lv_obj_set_style_##api_name(obj, value, part | state);            \
    }

#define _QMSD_OBJ_STYLE_SET_GET_DECLARE(api_name, func_name, value_type, style_type)                                      \
    _QMSD_OBJ_GET_STYLE(api_name, func_name, value_type, style_type)                                                         \
    _QMSD_OBJ_SET_STYLE_LOCAL(api_name, func_name, value_type, style_type)       

typedef int16_t qmsd_style_int_t;
typedef lv_opa_t qmsd_opa_t;
typedef lv_color_t qmsd_color_t;
#if defined QMSD_GUI_LVGL_V7

#elif defined QMSD_GUI_LVGL_V8 
_QMSD_OBJ_STYLE_SET_GET_DECLARE(anim_time, anim_time, qmsd_style_int_t, _int)
#endif
_QMSD_OBJ_STYLE_SET_GET_DECLARE(radius, radius, qmsd_style_int_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(clip_corner, clip_corner, bool, _int)
//_QMSD_OBJ_STYLE_SET_GET_DECLARE(size, size, qmsd_style_int_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(transform_width, transform_width, qmsd_style_int_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(transform_height, transform_height, qmsd_style_int_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(transform_angle, transform_angle, qmsd_style_int_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(transform_zoom, transform_zoom, qmsd_style_int_t, _int)
//_QMSD_OBJ_STYLE_SET_GET_DECLARE(opa_scale, opa_scale, qmsd_opa_t, _opa)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(pad_top, pad_top, qmsd_style_int_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(pad_bottom, pad_bottom, qmsd_style_int_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(pad_left, pad_left, qmsd_style_int_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(pad_right, pad_right, qmsd_style_int_t, _int)
//_QMSD_OBJ_STYLE_SET_GET_DECLARE(pad_inner, pad_inner, qmsd_style_int_t, _int)
//_QMSD_OBJ_STYLE_SET_GET_DECLARE(margin_top, margin_top, qmsd_style_int_t, _int)
//_QMSD_OBJ_STYLE_SET_GET_DECLARE(margin_bottom, margin_bottom, qmsd_style_int_t, _int)
//_QMSD_OBJ_STYLE_SET_GET_DECLARE(margin_left, margin_left, qmsd_style_int_t, _int)
//_QMSD_OBJ_STYLE_SET_GET_DECLARE(margin_right, margin_right, qmsd_style_int_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(blend_mode, bg_blend_mode, lv_blend_mode_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(bg_main_stop, bg_main_stop, qmsd_style_int_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(bg_grad_stop, bg_grad_stop, qmsd_style_int_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(bg_grad_dir, bg_grad_dir, lv_grad_dir_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(bg_color, bg_color, qmsd_color_t, _color)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(bg_grad_color, bg_grad_color, qmsd_color_t, _color)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(bg_opa, bg_opa, qmsd_opa_t, _opa)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(border_width, border_width, qmsd_style_int_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(border_side, border_side, lv_border_side_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(blend_mode, border_blend_mode, lv_blend_mode_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(border_post, border_post, bool, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(border_color, border_color, qmsd_color_t, _color)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(border_opa, border_opa, qmsd_opa_t, _opa)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(outline_width, outline_width, qmsd_style_int_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(outline_pad, outline_pad, qmsd_style_int_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(blend_mode, outline_blend_mode, lv_blend_mode_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(outline_color, outline_color, qmsd_color_t, _color)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(outline_opa, outline_opa, qmsd_opa_t, _opa)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(shadow_width, shadow_width, qmsd_style_int_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(shadow_ofs_x, shadow_ofs_x, qmsd_style_int_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(shadow_ofs_y, shadow_ofs_y, qmsd_style_int_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(shadow_spread, shadow_spread, qmsd_style_int_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(blend_mode, shadow_blend_mode, lv_blend_mode_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(shadow_color, shadow_color, qmsd_color_t, _color)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(shadow_opa, shadow_opa, qmsd_opa_t, _opa)
//_QMSD_OBJ_STYLE_SET_GET_DECLARE(pattern_repeat, pattern_repeat, bool, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(blend_mode, pattern_blend_mode, lv_blend_mode_t, _int)
//_QMSD_OBJ_STYLE_SET_GET_DECLARE(pattern_recolor, pattern_recolor, qmsd_color_t, _color)
//_QMSD_OBJ_STYLE_SET_GET_DECLARE(pattern_opa, pattern_opa, qmsd_opa_t, _opa)
//_QMSD_OBJ_STYLE_SET_GET_DECLARE(pattern_recolor_opa, pattern_recolor_opa, qmsd_opa_t, _opa)
//_QMSD_OBJ_STYLE_SET_GET_DECLARE(pattern_image, pattern_image, const void *, _ptr)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(text_letter_space, value_letter_space, qmsd_style_int_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(text_line_space, value_line_space, qmsd_style_int_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(blend_mode, value_blend_mode, lv_blend_mode_t, _int)
//_QMSD_OBJ_STYLE_SET_GET_DECLARE(value_ofs_x, value_ofs_x, qmsd_style_int_t, _int)
//_QMSD_OBJ_STYLE_SET_GET_DECLARE(value_ofs_y, value_ofs_y, qmsd_style_int_t, _int)
//_QMSD_OBJ_STYLE_SET_GET_DECLARE(value_align, value_align, lv_align_t, _int)
//_QMSD_OBJ_STYLE_SET_GET_DECLARE(value_color, value_color, qmsd_color_t, _color)
//_QMSD_OBJ_STYLE_SET_GET_DECLARE(value_opa, value_opa, qmsd_opa_t, _opa)
//_QMSD_OBJ_STYLE_SET_GET_DECLARE(value_font, value_font, const lv_font_t *, _ptr)
//_QMSD_OBJ_STYLE_SET_GET_DECLARE(value_str, value_str, const char *, _ptr)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(text_letter_space, text_letter_space, qmsd_style_int_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(text_line_space, text_line_space, qmsd_style_int_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(text_decor, text_decor, lv_text_decor_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(blend_mode, text_blend_mode, lv_blend_mode_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(text_color, text_color, qmsd_color_t, _color)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(text_color, text_sel_color, qmsd_color_t, _color)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(text_color, text_sel_bg_color, qmsd_color_t, _color)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(text_opa, text_opa, qmsd_opa_t, _opa)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(text_font, text_font, const lv_font_t *, _ptr)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(line_width, line_width, qmsd_style_int_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(blend_mode, line_blend_mode, lv_blend_mode_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(line_dash_width, line_dash_width, qmsd_style_int_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(line_dash_gap, line_dash_gap, qmsd_style_int_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(line_rounded, line_rounded, bool, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(line_color, line_color, qmsd_color_t, _color)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(line_opa, line_opa, qmsd_opa_t, _opa)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(blend_mode, image_blend_mode, lv_blend_mode_t, _int)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(img_recolor, image_recolor, qmsd_color_t, _color)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(img_opa, image_opa, qmsd_opa_t, _opa)
_QMSD_OBJ_STYLE_SET_GET_DECLARE(img_recolor_opa, image_recolor_opa, qmsd_opa_t, _opa)
//_QMSD_OBJ_STYLE_SET_GET_DECLARE(TRANSITION_TIME, transition_time, qmsd_style_int_t, _int)
//_QMSD_OBJ_STYLE_SET_GET_DECLARE(TRANSITION_DELAY, transition_delay, qmsd_style_int_t, _int)

#define QMSD_COLOR_RGB(r,g,b) (lv_color_make((r),(g),(b)))
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
#endif // _QMSD_WIDGET_STYLE_H_