# qmsd ESP32

qmsd ESP32 project

# prepare ESP32 v4.4.3 SDK

please refr to https://docs.espressif.com/projects/esp-idf/zh_CN/v4.4.3/esp32/get-started/index.html  

# build project

idf.py build

# 载入标准品的预设配置
Ubuntu需要指定bash或关闭dash
bash load.sh

./load.sh  
1): WT32_SC01_LANDSCAPE  
2): WT32_SC01_PORTRAIT  
3): WT154-S2MI1-PERFORMANCE  
4): WT154-S2MI1-WIFI  
5): WT154_C3SI1  
6): WT-86-32-3ZW0-PERFORMANCE  
7): WT-86-32-3ZW0-WIFI  
8): WT-86-32-3ZW1-PERFORMANCE  
9): WT-86-32-3ZW1-WIFI  
1
Set to 1-WT32_SC01_LANDSCAPE  
--- _qmsd_init done  
--- lvgl done  
--- blockly done  
--- lvgl_esp32_drivers done  
--- bus done  
--- sdkconfig done  
  
Done  

# How to add new board
1.在load.sh、save.sh中添加新型号
2.在components/lvgl_esp32_drivers/lvgl_tft/Kconfig中添加新型号
    已支持的SPI屏+TP：直接从menuconfig中配置屏幕、tp驱动，调试完成后利用save脚本保存到添加到型号
    已支持的8080屏：参考其他型号添加默认管教配置等，之后同样利用save脚本保存

# 8ms相关SDK问题反馈  
https://8ms.xyz/supports?contact  