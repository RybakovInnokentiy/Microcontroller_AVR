/*
 * LCD.h
 *
 * Created: 30.01.2022 15:56:03
 *  Author: Kesha
 */ 

#ifndef LCD_H_
#define LCD_H_

unsigned char portlcd;

void sendhafbyte(unsigned char data);
void sendbyte(unsigned char data, unsigned char mode);
void setpos(unsigned char x, unsigned char y);
void sendchar(unsigned char data);
void LCD_Init();

#define e1 I2C_SendByteByAddress(portlcd|=0x04,0b01001110) // установка линии E в 1
#define e0 I2C_SendByteByAddress(portlcd&=~0x04,0b01001110) // установка линии E в 0
#define data_trans_rs1() I2C_SendByteByAddress(portlcd|=0x01,0b01001110) // установка линии RS в 1
#define instr_trans_rs0() I2C_SendByteByAddress(portlcd&=~0x01,0b01001110) // установка линии RS в 0
#define setwrite() I2C_SendByteByAddress(portlcd&=~0x02,0b01001110) // установка записи в
#define setled() I2C_SendByteByAddress(portlcd|=0x08, 0b01001110) //включение подсветки
#endif /* LCD_H_ */