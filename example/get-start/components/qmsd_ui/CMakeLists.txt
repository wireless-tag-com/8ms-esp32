file(GLOB SOURCES *.c ./ui/*.c ./res/*.c)

idf_component_register(SRCS ${SOURCES}
                       INCLUDE_DIRS . ./ui ./res
                       REQUIRES qmsd_gui ui_engine
                       )

