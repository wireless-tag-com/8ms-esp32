# DEMO BLE WIFI

支持如下功能:

1. WIFI STA
2. BLE GATTS
3. MQTT
4. NTP
4. OTA

# 安装机型库

先按照SDK使用说明，加载机型的库文件

# 修改sdkconfig

1. 增加BLE 4.2支持（CONFIG_BT_BLE_42_FEATURES_SUPPORTED=y）
2. 增加OTA HTTP支持（CONFIG_OTA_ALLOW_HTTP=y，CONFIG_PARTITION_TABLE_CUSTOM_FILENAME="partitions_qmsd_ota.csv"
CONFIG_PARTITION_TABLE_FILENAME="partitions_qmsd_ota.csv"）

# 编译测试

```
idf.py build
idf.py -p COM flash monitor
```

# 测试WIFI

通过串口输入如下命令：
```
sta ssid pwd
```

WIFI将连接输入的ssid，重启之后也将自动连接该ssid，连接成功之后，将开启NTP对时和MQTT连接

# 测试BLE

通过串口输入如下命令：
```
ble gatts
```

通过蓝牙调试助手，可以搜索到ZXBLE_GATT_XXXXXX

# 测试OTA

通过串口输入如下命令：
```
ota URL
```

将从URL下载固件进行OTA升级


# 8ms
通过串口输入如下命令：
```
8ms json_str
```

例如：
1. 跳转到screen_test

```
8ms {"wid":"screen_test","cmd":"set_status","attr":{"action":"switch"}}
```

2. 跳转到screen_main

```
8ms {"wid":"screen_test","cmd":"set_status","attr":{"action":"switch"}}
```

具体文档请参考：https://doc.8ms.xyz/docs/gui/gui-1d5fb15kvfcoq


