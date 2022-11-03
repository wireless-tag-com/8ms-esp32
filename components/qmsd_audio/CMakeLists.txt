idf_component_register(
    SRC_DIRS
        "."
        "wav"
        "libhelix-mp3"
        "libhelix-mp3/real"
        "codec"
    INCLUDE_DIRS
        "."
        "libhelix-mp3/pub"
        "wav"
        "codec"
    PRIV_INCLUDE_DIRS
        "libhelix-mp3/real"
    REQUIRES bus)

target_compile_options(${COMPONENT_LIB} PRIVATE -Wno-unused-but-set-variable)
