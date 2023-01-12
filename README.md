# qmsd ESP32

qmsd ESP32 project

# prepare ESP32 v4.4.3 SDK

please refr to https://docs.espressif.com/projects/esp-idf/zh_CN/release-v4.3.1/get-started/index.html
Or just use docker we provide: docker push shukewt/esp-idf-4.3-release:tagname

# build project

idf.py build

# 载入标准品的预设配置
Ubuntu需要指定bash或关闭dash
bash load.sh

./load.sh  
1): WT32_SC01
2): WT154_C3SI1
3): WT154_S2MI1
4): WT_86_32_3ZW1
5): WT280_S2MX1
6): WT240_C3SI1
7): WT_0_S2_240MW1
1
Set to 1-WT32_SC01
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