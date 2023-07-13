file(GLOB EXTERN_FILES res_files/*)

file(GLOB SOURCES *.c ./ui/*.c ./res/*.c)

idf_component_register(SRCS ${SOURCES}
                       INCLUDE_DIRS . ./ui ./res
                       REQUIRES qmsd_init
    EMBED_FILES ${EXTERN_FILES}
                       )

