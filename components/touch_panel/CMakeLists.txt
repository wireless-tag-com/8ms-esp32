
set(TOUCH_DIR "xpt2046" "ft5x06" "ns2016" "gslx680" "button" "hall")

idf_component_register(
                        INCLUDE_DIRS "." "${TOUCH_DIR}" "calibration/basic_painter" "calibration/basic_painter/fonts"
                        PRIV_INCLUDE_DIRS "calibration"
                        PRIV_REQUIRES bus nvs_flash
                        REQUIRES screen)

add_prebuilt_library(libtouch_panel "libtouch_panel.a" REQUIRES screen bus nvs_flash)
target_link_libraries(${COMPONENT_LIB} INTERFACE libtouch_panel)
