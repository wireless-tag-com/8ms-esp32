
idf_component_register(
    SRC_DIRS . ft5x06
    INCLUDE_DIRS . ft5x06
    REQUIRES driver i2c_bus qmsd_utils
)

add_prebuilt_library(lib${COMPONENT_NAME} lib${COMPONENT_NAME}.a REQUIRES driver i2c_bus qmsd_utils)
target_link_libraries(${COMPONENT_LIB} INTERFACE lib${COMPONENT_NAME})
