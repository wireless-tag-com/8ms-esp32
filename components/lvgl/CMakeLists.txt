#file(GLOB_RECURSE SOURCES ./*.c)

set(incdirs "."
            "lvgl"
            "include"
            "lvgl/src")

idf_component_register(SRCS ${SOURCES}
                       INCLUDE_DIRS "${incdirs}"
                       REQUIRES bus screen touch_panel mbedtls json wtctrl mqtt blockly)

target_compile_definitions(${COMPONENT_LIB} INTERFACE LV_CONF_INCLUDE_SIMPLE=1)
target_link_libraries(${COMPONENT_LIB} INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/liblvgl.a")
