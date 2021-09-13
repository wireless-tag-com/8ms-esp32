file(GLOB SOURCES *.c)
idf_component_register(SRCS ${SOURCES}
                    INCLUDE_DIRS "."
                    REQUIRES bus lvgl)
target_link_libraries(${COMPONENT_LIB} INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/libtouch_panel.a")
