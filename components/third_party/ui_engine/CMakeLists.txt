if(CONFIG_QMSD_GUI_LVGL_V7)
set(engine_include 
            "lvgl7/"
            "lvgl7/lvgl/"
            "lvgl7/lvgl/src")
            file(GLOB_RECURSE UI_ENGINE_SRC lvgl7/*.c)
elseif(CONFIG_QMSD_GUI_LVGL_V8)
    set(engine_include 
            "lvgl8/"
            "lvgl8/lvgl/"
            "lvgl8/lvgl/src") 
            file(GLOB_RECURSE UI_ENGINE_SRC lvgl8/*.c)  
endif()
idf_component_register( 
    SRCS ${UI_ENGINE_SRC}
    INCLUDE_DIRS "${engine_include}"
    )

target_compile_definitions(${COMPONENT_LIB} INTERFACE LV_CONF_INCLUDE_SIMPLE=1)
