#pragma once

#define BOARD_RESET_PIN     (-1)

#define LCD_RST_PIN         (-1)

// RGB SPI interface
#define LCD_SPI_DATA0     9  /*!< for 1-line SPI, this also refered as MOSI */
#define LCD_SPI_CLK       10
#define LCD_SPI_CS        0
#define LCD_SPI_DC        -1
#define LCD_SPI_RST       -1

// RGB interface
#define LCD_PCLK_GPIO     (14)
#define LCD_VSYNC_GPIO    (12)
#define LCD_HSYNC_GPIO    (11)
#define LCD_DE_GPIO       (13)

#define LCD_D0_GPIO       (10)  // B0
#define LCD_D1_GPIO       (9)   // B1
#define LCD_D2_GPIO       (40)  // B2
#define LCD_D3_GPIO       (20)  // B3
#define LCD_D4_GPIO       (19)  // B4
#define LCD_D5_GPIO       (41)  // G0
#define LCD_D6_GPIO       (46)  // G1
#define LCD_D7_GPIO       (3)   // G2
#define LCD_D8_GPIO       (42)  // G3
#define LCD_D9_GPIO       (8)   // G4
#define LCD_D10_GPIO      (18)  // G5
#define LCD_D11_GPIO      (2)   // R0
#define LCD_D12_GPIO      (17)  // R1
#define LCD_D13_GPIO      (16)  // R2
#define LCD_D14_GPIO      (1)   // R3
#define LCD_D15_GPIO      (15)  // R4
#define LCD_DISP_EN_GPIO  (-1)

#define LCD_BL_PIN          (45)

#define TOUCH_IIC_SDA_PIN   (7)
#define TOUCH_IIC_SCL_PIN   (6)
#define TOUCH_IIC_INT_PIN   (-1)
#define TOUCH_IIC_RST_PIN   (-1)
