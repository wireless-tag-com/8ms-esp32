idf_component_register(
                    INCLUDE_DIRS "."
                    )
add_prebuilt_library(libqmsd_init "libqmsd_init.a" REQUIRES blockly bus lvgl_esp32_drivers lvgl main)
target_link_libraries(${COMPONENT_LIB} INTERFACE libqmsd_init)
                
