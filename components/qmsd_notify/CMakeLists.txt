idf_component_register(
	INCLUDE_DIRS .
	REQUIRES qmsd_utils esp_event
)

add_prebuilt_library(lib${COMPONENT_NAME} lib${COMPONENT_NAME}.a REQUIRES qmsd_utils esp_event)
target_link_libraries(${COMPONENT_LIB} INTERFACE lib${COMPONENT_NAME})
