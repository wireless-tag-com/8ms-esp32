set(lib_path ${CMAKE_CURRENT_SOURCE_DIR}/ali-smartliving-device-sdk-c/output/release/lib)

set(COMPONENT_PRIV_INCLUDEDIRS
    ali-smartliving-device-sdk-c/output/release/include/imports)
    
set(COMPONENT_ADD_INCLUDEDIRS
    conn_mgr
    ali-smartliving-device-sdk-c/output/release/include
    ali-smartliving-device-sdk-c/output/release/include/exports)

# Edit following two lines to set component requirements (see docs)
set(COMPONENT_REQUIRES "nvs_flash" "app_update" "esp-tls")
set(COMPONENT_PRIV_REQUIRES )

if(CONFIG_IDF_TARGET_ESP32S3)
set(COMPONENT_SRCDIRS
    conn_mgr
    wrappers)
endif()

register_component()
if(CONFIG_IDF_TARGET_ESP32S3)
component_compile_options(-Wno-error=stringop-truncation -Wno-error=stringop-overflow -DAUTH_MODE_CERT)

add_library(iot_sdk STATIC IMPORTED)
set_property(TARGET iot_sdk PROPERTY IMPORTED_LOCATION ${lib_path}/libiot_sdk.a)
target_link_libraries(${COMPONENT_LIB} INTERFACE iot_sdk)
set_property(TARGET iot_sdk APPEND PROPERTY INTERFACE_LINK_LIBRARIES ${COMPONENT_LIB} "-u ota_pubn_buf")
endif()
