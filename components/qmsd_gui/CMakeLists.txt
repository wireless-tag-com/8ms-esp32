set(base_include 
    "."
    "qmsd_gui"
    "qmsd_gui/api"
    "qmsd_gui_port/include"
    "qmsd_gui/elements"
    "qmsd_gui/tools"
    "qmsd_gui/control"
)

file(GLOB_RECURSE QMSD_GUI_SRC qmsd_gui/*.c)
if(CONFIG_QMSD_GUI_LVGL_V7)
            file(GLOB_RECURSE UI_PORT_SRC qmsd_gui_port/lvgl7/*.c)
elseif(CONFIG_QMSD_GUI_LVGL_V8)
            file(GLOB_RECURSE UI_PORT_SRC qmsd_gui_port/lvgl8/*.c)    
endif()

idf_component_register( 
    SRCS ${QMSD_GUI_SRC} ${UI_PORT_SRC}
    INCLUDE_DIRS "${base_include}"
    REQUIRES mbedtls json nvs_flash spi_flash spiffs qmsd_utils ui_engine
)

target_compile_definitions(${COMPONENT_LIB} INTERFACE LV_CONF_INCLUDE_SIMPLE=1)

if(CONFIG_QMSD_GUI_LVGL_V7)
    add_prebuilt_library(lib${COMPONENT_NAME} lib${COMPONENT_NAME}_v7.a REQUIRES mbedtls json nvs_flash spi_flash spiffs qmsd_utils ui_engine)
elseif(CONFIG_QMSD_GUI_LVGL_V8)
    add_prebuilt_library(lib${COMPONENT_NAME} lib${COMPONENT_NAME}_v8.a REQUIRES mbedtls json nvs_flash spi_flash spiffs qmsd_utils ui_engine)
endif()
target_link_libraries(${COMPONENT_LIB} INTERFACE lib${COMPONENT_NAME})
