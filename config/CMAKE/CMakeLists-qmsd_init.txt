idf_component_register(
                    INCLUDE_DIRS "." "qmsd_board"
                    )

idf_build_get_property(project_ver PROJECT_VER)
string(SUBSTRING "${project_ver}" 0 31 PROJECT_VER_CUT)
target_compile_definitions(${COMPONENT_LIB} INTERFACE QMSD_PROJECT_VER="${PROJECT_VER_CUT}")

add_prebuilt_library(libqmsd_init "libqmsd_init.a" REQUIRES bus screen touch_panel lvgl main mqtt)
target_link_libraries(${COMPONENT_LIB} INTERFACE libqmsd_init)
                
