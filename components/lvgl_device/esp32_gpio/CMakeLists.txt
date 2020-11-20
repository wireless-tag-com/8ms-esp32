file(GLOB SOURCES *.c ../gc/gc.c)

message("SOURCES contents: " "${SOURCES}")

idf_component_register(SRCS ${SOURCES}
                       INCLUDE_DIRS . 
                       )