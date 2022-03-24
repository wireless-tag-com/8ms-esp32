
set(SCREEN_DIR "controller_driver/st7789"
            "controller_driver/st7796"
            "controller_driver/ili9488"
            "qmsd_rgb"
            )

idf_component_register(
                        INCLUDE_DIRS "${SCREEN_DIR}" "interface_driver" "qmsd_rgb" "."
                        PRIV_INCLUDE_DIRS "screen_utility"
                        REQUIRES bus esp_lcd
                        )

add_prebuilt_library(libscreen "libscreen.a" REQUIRES bus esp_lcd)
target_link_libraries(${COMPONENT_LIB} INTERFACE libscreen)
