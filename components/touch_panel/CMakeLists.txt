idf_component_register(
                    INCLUDE_DIRS "."
                    REQUIRES lvgl touch_panel bus)

target_link_libraries(${COMPONENT_LIB} INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/libtouch_panel.a")
