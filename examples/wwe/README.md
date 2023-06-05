# WWE

支持如下功能:

1. 离线唤醒
2. 离线语音识别

# 安装机型库

先按照SDK使用说明，加载机型的库文件，目前只支持ZX3D95CE01S_AR_4848机型

# 编译测试

```
idf.py build
idf.py -p COM flash monitor
```

# 测试

对着麦克风说"小爱同学"，然后串口会打印

```
wakeword detected
```

然后对着麦克风说"打开空调"，串口将打印

```
command_id:
```

# 调试
可通过idf.py menuconfig，去修改唤醒词和离线语音指令

