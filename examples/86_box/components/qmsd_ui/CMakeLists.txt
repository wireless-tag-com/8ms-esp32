file(GLOB SOURCES *.c ./ui/*.c ./res/*.c)

idf_component_register(SRCS ${SOURCES}
                       INCLUDE_DIRS . ./ui ./res
                       REQUIRES lvgl REQUIRES qmsd_init
                       )

target_compile_options(${COMPONENT_LIB} PRIVATE "-Wno-format")

