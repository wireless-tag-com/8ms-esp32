file(GLOB_RECURSE SOURCES ./*.c)

set(incdirs "."
            "lvgl"
            "include"
            "lvgl/src")

idf_component_register(
                       INCLUDE_DIRS "${incdirs}"
                       REQUIRES blockly mqtt bus mbedtls json screen touch_panel wtctrl)

target_compile_definitions(${COMPONENT_LIB} INTERFACE LV_CONF_INCLUDE_SIMPLE=1)
target_link_libraries(${COMPONENT_LIB} INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/liblvgl.a")