
if (CONFIG_ZX3D50CE02S_USRC_4832)
message(STATUS "Current board name is " CONFIG_ZX3D50CE02S_USRC_4832)
set(BOARD_DIR board/esp32-s3/ZX3D50CE02S-USRC-4832)
endif()

if (CONFIG_ZX3D95CE01S_UR)
message(STATUS "Current board name is " CONFIG_ZX3D95CE01S_UR)
set(BOARD_DIR board/esp32-s3/ZX3D95CE01S-UR)
endif()

if (CONFIG_ZX3D95CE01S_AR)
message(STATUS "Current board name is " CONFIG_ZX3D95CE01S_AR)
set(BOARD_DIR board/esp32-s3/ZX3D95CE01S-AR)
endif()

if (CONFIG_ZX4D30NS)
message(STATUS "Current board name is " CONFIG_ZX4D30NS)
set(BOARD_DIR board/esp32-s3/ZX4D30NS)
endif()

idf_component_register(
    SRC_DIRS ${BOARD_DIR} board_utility 
    INCLUDE_DIRS ${BOARD_DIR} board_utility
    REQUIRES driver esp_lcd bus screen qmsd_screen qmsd_touch qmsd_gui
)
