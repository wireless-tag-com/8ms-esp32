file(GLOB SOURCES *.c)

idf_component_register(SRCS ${SOURCES}
                       INCLUDE_DIRS .
                       REQUIRES lvgl)

target_link_libraries(${COMPONENT_LIB} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/lvgl_touch/liblvgl_touch.a" "${CMAKE_CURRENT_SOURCE_DIR}/lvgl_tft/liblvgl_tft.a")