#file(GLOB SOURCES *.c)
file(GLOB_RECURSE SOURCES ./*.c)
idf_component_register(SRCS ${SOURCES}
                       INCLUDE_DIRS . ./custom
                       )
# target_compile_definitions(${COMPONENT_LIB} PRIVATE LV_CONF_INCLUDE_SIMPLE=1)