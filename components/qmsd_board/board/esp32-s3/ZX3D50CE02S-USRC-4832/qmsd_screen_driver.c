#include "st7796.h"

#define LCD_WRITE_CMD(x)    lcd_st7796_write_cmd(x)
#define LCD_WRITE_DATA(x)   lcd_st7796_write_data(x)

esp_err_t qmsd_lcd_reg_config(void) {
    LCD_WRITE_CMD(0x11);     
    vTaskDelay(pdMS_TO_TICKS(120));
    LCD_WRITE_CMD(0x36);     // Memory Data Access Control MY,MX~~
    LCD_WRITE_DATA(0x48);   

    LCD_WRITE_CMD(0x3A);     
    LCD_WRITE_DATA(0x55);   //LCD_WRITE_DATA(0x66);

    LCD_WRITE_CMD(0xF0);     // Command Set Control
    LCD_WRITE_DATA(0xC3);   

    LCD_WRITE_CMD(0xF0);     
    LCD_WRITE_DATA(0x96);   

    LCD_WRITE_CMD(0xB4);     
    LCD_WRITE_DATA(0x01);   

    LCD_WRITE_CMD(0xB7);     
    LCD_WRITE_DATA(0xC6);   

    LCD_WRITE_CMD(0xB9);     
    LCD_WRITE_DATA(0x02);   
    LCD_WRITE_DATA(0xE0);   

    LCD_WRITE_CMD(0xC0);     
    LCD_WRITE_DATA(0x80);   
    LCD_WRITE_DATA(0x16);   

    LCD_WRITE_CMD(0xC1);     
    LCD_WRITE_DATA(0x19);   

    LCD_WRITE_CMD(0xC2);     
    LCD_WRITE_DATA(0xA7);   

    LCD_WRITE_CMD(0xC5);     
    LCD_WRITE_DATA(0x16);   

    LCD_WRITE_CMD(0xE8);     
    LCD_WRITE_DATA(0x40);   
    LCD_WRITE_DATA(0x8A);   
    LCD_WRITE_DATA(0x00);   
    LCD_WRITE_DATA(0x00);   
    LCD_WRITE_DATA(0x29);   
    LCD_WRITE_DATA(0x19);   
    LCD_WRITE_DATA(0xA5);   
    LCD_WRITE_DATA(0x33);   

    LCD_WRITE_CMD(0xE0);     
    LCD_WRITE_DATA(0xF0);   
    LCD_WRITE_DATA(0x07);   
    LCD_WRITE_DATA(0x0D);   
    LCD_WRITE_DATA(0x04);   
    LCD_WRITE_DATA(0x05);   
    LCD_WRITE_DATA(0x14);   
    LCD_WRITE_DATA(0x36);   
    LCD_WRITE_DATA(0x54);   
    LCD_WRITE_DATA(0x4C);   
    LCD_WRITE_DATA(0x38);   
    LCD_WRITE_DATA(0x13);   
    LCD_WRITE_DATA(0x14);   
    LCD_WRITE_DATA(0x2E);   
    LCD_WRITE_DATA(0x34);   

    LCD_WRITE_CMD(0xE1);     
    LCD_WRITE_DATA(0xF0);   
    LCD_WRITE_DATA(0x10);   
    LCD_WRITE_DATA(0x14);   
    LCD_WRITE_DATA(0x0E);   
    LCD_WRITE_DATA(0x0C);   
    LCD_WRITE_DATA(0x08);   
    LCD_WRITE_DATA(0x35);   
    LCD_WRITE_DATA(0x44);   
    LCD_WRITE_DATA(0x4C);   
    LCD_WRITE_DATA(0x26);   
    LCD_WRITE_DATA(0x10);   
    LCD_WRITE_DATA(0x12);   
    LCD_WRITE_DATA(0x2C);   
    LCD_WRITE_DATA(0x32); 

    LCD_WRITE_CMD(0xF0);     
    LCD_WRITE_DATA(0x3C);

    LCD_WRITE_CMD(0xF0);
    LCD_WRITE_DATA(0x69);
    vTaskDelay(pdMS_TO_TICKS(120));

    LCD_WRITE_CMD(0x29);
    LCD_WRITE_CMD(0x21);

    return ESP_OK;
}
