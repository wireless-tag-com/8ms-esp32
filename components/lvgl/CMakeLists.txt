file(GLOB_RECURSE SOURCES lvgl/src/*.c)

idf_component_register(SRCS ${SOURCES}
                       INCLUDE_DIRS . lvgl
                       REQUIRES mbedtls json wtctrl lvgl_esp32_drivers)

target_compile_definitions(${COMPONENT_LIB} INTERFACE LV_CONF_INCLUDE_SIMPLE=1)
target_link_libraries(${COMPONENT_LIB} INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/lvgl/liblvgl.a")