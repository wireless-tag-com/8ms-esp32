if(ESP_PLATFORM)

file(GLOB SOURCES *.c ./qmsd_touch/*.c)

#@todo add SimleInclude macro here

# Include only the source file of the selected
# display controller.

# Add touch driver to compilation only if it is selected in menuconfig

    list(APPEND LVGL_INCLUDE_DIRS "./qmsd_tft/controller_driver")
    list(APPEND LVGL_INCLUDE_DIRS "./qmsd_tft/interface_driver")
    list(APPEND LVGL_INCLUDE_DIRS "./qmsd_tft/screen_utility")

if(CONFIG_WT_86_32_3ZW0)
    list(APPEND LVGL_INCLUDE_DIRS lvgl_touch)
    list(APPEND LVGL_INCLUDE_DIRS "./qmsd_tp/gt911/")
elseif(CONFIG_WT_86_32_3ZW1)
    list(APPEND LVGL_INCLUDE_DIRS lvgl_touch)
    list(APPEND LVGL_INCLUDE_DIRS "./qmsd_tp/gslx680/")
endif()

idf_component_register(
                       INCLUDE_DIRS ${LVGL_INCLUDE_DIRS} . ./lvgl_touch
                       REQUIRES bus lvgl)
                       
#target_compile_definitions(${COMPONENT_LIB} PUBLIC "-DLV_LVGL_H_INCLUDE_SIMPLE")

add_prebuilt_library(liblvgl_esp32_drivers "liblvgl_esp32_drivers.a" REQUIRES bus lvgl)
target_link_libraries(${COMPONENT_LIB} INTERFACE liblvgl_esp32_drivers)

else()
    message(FATAL_ERROR "LVGL ESP32 drivers: ESP_PLATFORM is not defined. Try reinstalling ESP-IDF.")
endif()
