idf_component_register(SRC_DIRS "." 
                        INCLUDE_DIRS "include" REQUIRES driver
                        REQUIRES esp_rom driver)

target_compile_options(${COMPONENT_LIB} PRIVATE "-Wno-format")
