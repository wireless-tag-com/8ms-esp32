# V2.2

## 新特性

1.升级至基于4.4.4的IDF版本，*[获取地址](https://github.com/espressif/esp-idf.git)*  

2.更新3.95寸屏幕驱动 

3.增加离线语音工程wwe

# V2.1
## 新特性
1.新增启明智显S3系列开发板支持  

# V2.0

## 新特性

1.升级至基于4.4的IDF版本，*[获取地址](https://gitee.com/qiming-zhixian/esp-idf)*  

2.新增启明智显S3系列开发板支持  

3.允许自定义开发板的硬件初始化入口，相关api参考qmsd_set_board_init_cus  

4.调整驱动结构，允许自行调整屏幕角度以及显存大小  

5.新增qmsd_mod模块用于实现功能逻辑  

6.新增自动背光管理  

7.修复86盒tp表现

# V1.2

- 使用8ms平台进行UI开发的用户请将source.zip内容替换至 components/qmsd\_ui 目录
- 由于8ms生成的UI部分代码不再开放编辑，需要自定义UI交互请使用8ms自定义回调相关blockly指定需处理的事件，相关事件处理参考工程main/control/qmsd\_ui\_cb.c 中代码开发，UI相关元素获取可以参考 components/qmsd\_ui/ui/qmsd\_ui\_entry.h 中声明的相关get方法  
- qmsd\_ui\_cb.c中的 qmsd\_ui\_cb 函数运行在UI线程内部，因此不建议在其中执行阻塞或延时，需要异步任务可以参考main/control/qmsd\_control.c 中定义的事件收发与处理
- 在UI线程以外的外部线程中直接操作UI相关内容可能会造成不同程度的异常，因此在components/qmsd\_init/qmsd\_ctrl.h中提供了在保证线程安全情况下进行UI操作的相关api 其中的操作协议可以参考8ms开发文档*[控制协议](http://doc.8ms.xyz/docs/gui/gui-1dgqjgc2de1lk)*章节
