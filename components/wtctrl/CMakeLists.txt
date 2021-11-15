idf_component_register(
                       INCLUDE_DIRS .
                       REQUIRES json bus touch_panel mqtt lvgl json blockly)
target_link_libraries(${COMPONENT_LIB} INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/libwtctrl.a")
