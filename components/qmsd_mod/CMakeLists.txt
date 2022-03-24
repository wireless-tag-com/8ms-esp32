idf_component_register(
                       INCLUDE_DIRS . include
                       PRIV_REQUIRES mbedtls
                       )
if(CONFIG_IDF_TARGET_ESP32)
    add_prebuilt_library(qmsd_mod "lib/libqmsd_mod_esp32.a" REQUIRES mbedtls)
    target_link_libraries(${COMPONENT_LIB} INTERFACE qmsd_mod)
elseif(CONFIG_IDF_TARGET_ESP32C3)
    add_prebuilt_library(qmsd_mod "lib/libqmsd_mod_esp32c3.a" REQUIRES mbedtls)
    target_link_libraries(${COMPONENT_LIB} INTERFACE qmsd_mod)
elseif(CONFIG_IDF_TARGET_ESP32S2)
    add_prebuilt_library(qmsd_mod "lib/libqmsd_mod_esp32s2.a" REQUIRES mbedtls)
    target_link_libraries(${COMPONENT_LIB} INTERFACE qmsd_mod)
elseif(CONFIG_IDF_TARGET_ESP32S3)
    add_prebuilt_library(qmsd_mod "lib/libqmsd_mod_esp32s3.a" REQUIRES mbedtls)
    target_link_libraries(${COMPONENT_LIB} INTERFACE qmsd_mod)
endif()