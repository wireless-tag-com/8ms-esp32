
idf_component_register(
                       INCLUDE_DIRS . lvgl)

target_link_libraries(${COMPONENT_LIB} INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/lvgl/liblvgl.a")

