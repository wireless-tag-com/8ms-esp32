idf_component_register(
                       INCLUDE_DIRS . ./ui ./res
                       REQUIRES lvgl qmsd_init
                       )
add_prebuilt_library(libqmsd_ui "lib/libqmsd_ui.a" REQUIRES lvgl qmsd_init)
target_link_libraries(${COMPONENT_LIB} INTERFACE libqmsd_ui)
