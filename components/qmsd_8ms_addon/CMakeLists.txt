file(GLOB_RECURSE SOURCES *.c)
    idf_component_register(SRCS ${SOURCES}
        INCLUDE_DIRS "." 
        REQUIRES json qmsd_init)
                    
