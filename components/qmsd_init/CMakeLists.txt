file(GLOB_RECURSE SOURCES *.c)
idf_component_register(SRCS ${SOURCES}
INCLUDE_DIRS "." "qmsd_board"
REQUIRES bus screen touch_panel lvgl main mqtt)
                    
idf_build_get_property(project_ver PROJECT_VER)
string(SUBSTRING "${project_ver}" 0 31 PROJECT_VER_CUT)
target_compile_definitions(${COMPONENT_LIB} INTERFACE QMSD_PROJECT_VER="${PROJECT_VER_CUT}")
