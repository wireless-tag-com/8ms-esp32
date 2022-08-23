使用到的硬件

LEDC -> 背光:
    LEDC_TIMER_3，LEDC_LOW_SPEED_MODE，LEDC_CHANNEL_5，LEDC_TIMER_10_BIT

工程下, 运行选择板子

```bash
idf.py load-board
```

Release sdk, 会在sdk目录下面生成一个release目录, 里面.a文件与cmake文件已替换好

Release 规则: component目录下如果存在CMakeLists.release, 则会删除该component下.c文件, 替换cmake文件, 从该工程的build目录提取.a文件到component下

```bash
idf.py release-sdk
```

生成当前工程的打包固件，会在运行目录下生成 firmware_0xXX.bin
```bash
idf.py generate-firmware
```
