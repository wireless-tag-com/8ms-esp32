#file(GLOB SOURCES *.c)
file(GLOB_RECURSE SOURCES ./*.c ./custom/*.c ./control/*.c ./init/*.c)
idf_component_register(SRCS ${SOURCES}
                       INCLUDE_DIRS . ./custom ./control ./init
                       )
# target_compile_definitions(${COMPONENT_LIB} PRIVATE LV_CONF_INCLUDE_SIMPLE=1)
