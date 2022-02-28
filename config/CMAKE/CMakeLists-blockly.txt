idf_component_register(
                       INCLUDE_DIRS .
                       REQUIRES nvs_flash 
                       )
add_prebuilt_library(libblockly "libblockly.a" REQUIRES nvs_flash app_update esp_http_client esp_https_ota)
target_link_libraries(${COMPONENT_LIB} INTERFACE libblockly)
