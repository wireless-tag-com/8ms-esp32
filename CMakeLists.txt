cmake_minimum_required(VERSION 3.5)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
list(APPEND "EXTRA_COMPONENT_DIRS" "./components/lvgl_esp32_drivers" "./components/lvgl_esp32_drivers/lvgl_touch" "./components/lvgl_esp32_drivers/lvgl_tft" 
	"./components/lvgl_esp32_blockly/blufi" "./components/lvgl_esp32_blockly/wifi" "./components/lvgl_esp32_blockly/http_request" "./components/lvgl_esp32_blockly/data_analysis" 
	"./components/lvgl_device" "./components/lvgl_device/esp32_gpio" "./components/lvgl_device/esp32_timer" "./components/lvgl_device/esp32_uart")

if (NOT DEFINED PROJECT_NAME)
	project(lvgl-demo)
endif (NOT DEFINED PROJECT_NAME)
