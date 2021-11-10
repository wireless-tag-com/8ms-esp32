#ifndef __LV_8MS_GPIO_H
#define __LV_8MS_GPIO_H

typedef enum {
	LV_8MS_GPIO_OUT = 0,      /**< Output. A Mode can also be set */
	LV_8MS_GPIO_IN = 1,       /**< Input */
	LV_8MS_GPIO_OUT_HIGH = 2, /**< Output. Init High */
	LV_8MS_GPIO_OUT_LOW = 3   /**< Output. Init Low */
} lv_8ms_gpio_dir_t;

typedef void (*lv_8ms_gpio_isr_t)(void *);

/**
 * @brief GPIO引脚初始化
 * 
 * @param pin          选择初始化的引脚号
 * @param dir          选择引脚模式（输入/输出）
 * @param pull_down_en 选择引脚是否使用内部下拉
 * @param pull_up_en   选择引脚是否使用内部下拉
 * @return int         成功返回：0
 */
int lv_8ms_gpio_init(int pin, int dir, int pull_down_en, int pull_up_en);

/**
 * @brief      释放GPIO引脚
 * 
 * @param pin  选择要释放的GPIO引脚号
 * @return int 成功返回：0
 */
int lv_8ms_gpio_uninit(int pin);

/**
 * @brief      设置GPIO引脚中断类型
 * 
 * @param pin  选择要设置中断类型的引脚号
 * @param type 选择要设置的中断类型
 * @return int 成功返回：0
 */
int lv_8ms_gpio_set_intr_type(int pin, int type);

/**
 * @brief      使能GPIO引脚中断
 * 
 * @param pin  选择要使能的GPIO引脚号
 * @return int 成功返回：0
 */
int lv_8ms_gpio_intr_enable(int pin);

/**
 * @brief      禁用GPIO引脚中断
 * 
 * @param pin  选择要禁用中断的引脚号
 * @return int 成功返回：0
 */
int lv_8ms_gpio_intr_disable(int pin);

/**
 * @brief      注册中断服务函数
 * 
 * @param args 如果参数为0表示开始注册
 * @return int 成功返回：0
 */
int lv_8ms_gpio_isr_init(int args);

/**
 * @brief      注销中断服务函数
 * 
 * @return int 成功返回：0，失败返回：-1
 */
int lv_8ms_gpio_isr_uninit(void);

/**
 * @brief             设置GPIO中断回调函数
 * 
 * @param pin         选择设置回调函数的引脚号
 * @param isr_handler 回调函数的函数指针
 * @param args        回调函数的参数
 * @return int        成功返回：0
 */
int lv_8ms_gpio_isr_handler_add(int pin, lv_8ms_gpio_isr_t isr_handler, void *args);

/**
 * @brief      删除GPIO中断回调函数
 * 
 * @param pin  选择删除中断回调函数的引脚号
 * @return int 成功返回：0
 */
int lv_8ms_gpio_isr_handler_remove(int pin);

/**
 * @brief      设置GPIO引脚的模式
 * 
 * @param pin  选择要设置引脚模式的引脚号
 * @param dir  选择要设置的模式
 * @return int 成功返回：0
 */
int lv_8ms_gpio_set_dir(int pin, int dir);

/**
 * @brief      获取GPIO引脚当前模式
 * 
 * @param pin  选择要获取模式的引脚号
 * @param dir  获取模式的整型变量指针
 * @return int 成功返回：0
 */
int lv_8ms_gpio_get_dir(int pin, int *dir);

/**
 * @brief 读取GPIO引脚电平
 * 
 * @param pin  选择要读取电平的引脚号
 * @return int 读取的电平数据
 */
int lv_8ms_gpio_read(int pin);

/**
 * @brief 设置GPIO引脚电平
 * 
 * @param pin   选择要设置电平的引脚号
 * @param value 要设置的电平
 * @return int  
 */
int lv_8ms_gpio_write(int pin, int value);

#endif