file(GLOB SOURCES *.c mod/*.c)
idf_component_register(SRCS ${SOURCES}
                       INCLUDE_DIRS "include"
                       REQUIRES json)