#file(GLOB SOURCES *.c)
file(GLOB_RECURSE SOURCES ./*.c ./custom/*.c ./control/*.c test/*.c lv_lib_freetype/*.c)
idf_component_register(SRCS ${SOURCES}
                       INCLUDE_DIRS . ./custom ./control ./lv_lib_freetype ./include
			EMBED_TXTFILES font.ttf
                       )
add_prebuilt_library(prebuilt "lib/libfreetype.a" REQUIRES esp_rom)

target_link_libraries(${COMPONENT_LIB} PRIVATE prebuilt)

target_compile_options(${COMPONENT_LIB} PRIVATE "-Wno-format")

# target_compile_definitions(${COMPONENT_LIB} PRIVATE LV_CONF_INCLUDE_SIMPLE=1)
