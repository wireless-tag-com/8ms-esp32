# HTTP PNG

支持如下功能:

1. 文件系统
2. HTTP下载图片
3. UI显示png图片

# 安装机型库

先按照SDK使用说明，加载机型的库文件（目前测试机型：ZX3D50CE02S_USRC_4832）

# 修改代码
通过如下代码修改WIFI的SSID和密码

```
// set wifi sta config
qmsd_wifi_sta_config("2G-TEST", "123456789", NULL);
```

通过如下代码修改HTTP图片的URL

```
// start http get png
qmsd_http_get_start("http://10.10.0.1:8080/test.png", NULL, NULL);
```

# 编译测试

```
idf.py build
idf.py -p COM flash monitor
```


