idf_component_register(
	INCLUDE_DIRS rgb_panel
	PRIV_REQUIRES driver esp_lcd
)

add_prebuilt_library(lib${COMPONENT_NAME} lib${COMPONENT_NAME}.a PRIV_REQUIRES driver esp_lcd)
target_link_libraries(${COMPONENT_LIB} INTERFACE lib${COMPONENT_NAME})
