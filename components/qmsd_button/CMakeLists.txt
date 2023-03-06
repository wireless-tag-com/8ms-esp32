if("${IDF_VERSION_MAJOR}.${IDF_VERSION_MINOR}" VERSION_GREATER_EQUAL "5.0")
    list(APPEND PRIVREQ esp_adc)
else() 
    list(APPEND PRIVREQ esp_adc_cal)
endif()

idf_component_register(
    SRC_DIRS .
    INCLUDE_DIRS .
    REQUIRES driver
    PRIV_REQUIRES ${PRIVREQ}
)
