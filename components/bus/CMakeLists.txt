idf_component_register( 
                        INCLUDE_DIRS "include" )
add_prebuilt_library(libbus "libbus.a" REQUIRES driver)
target_link_libraries(${COMPONENT_LIB} INTERFACE libbus)
