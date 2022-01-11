file(GLOB SOURCES *.c)

idf_component_register(SRCS ${SOURCES}
                       INCLUDE_DIRS . ./ui ./res
                       REQUIRES lvgl
                       )
add_prebuilt_library(libqmsd_ui "lib/libqmsd_ui.a" REQUIRES lvgl qmsd_init)
target_link_libraries(${COMPONENT_LIB} INTERFACE libqmsd_ui)
