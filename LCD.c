/*
 * LCD.c
 *
 * Created: 30.01.2022 15:56:17
 *  Author: Kesha
 */ 



#include "LCD.h"
#include "I2C.h"
#include <util/delay.h>

extern unsigned char portlcd = 0x00;

void sendhafbyte(unsigned char data){
	data <<= 4;
	e1;
	_delay_us(400);
	I2C_SendByteByAddress(portlcd|data, 0b01001110); 
	e0;
	_delay_us(400);
}

void sendbyte(unsigned char data, unsigned char mode){
	if (mode == 0) instr_trans_rs0();
	else data_trans_rs1();
	unsigned char c = data >> 4;
	sendhafbyte(c);
	sendhafbyte(data);
}

void setpos(unsigned char x, unsigned char y){
	unsigned char addr = (0x40 * y + x)|0x80;
	sendbyte(addr, 0);
}

void sendchar(unsigned char data){
	sendbyte(data, 1);
}

void LCD_Init(){
	//base set up
	_delay_ms(200);
	setled();
	instr_trans_rs0();
	setwrite();
	sendhafbyte(0x03);
	_delay_ms(50);
	sendhafbyte(0x03);
	_delay_ms(10);
	sendhafbyte(0x03);
	_delay_ms(10);
	sendhafbyte(0x02);
	_delay_ms(1);

	//user set up
	sendbyte(0x06, 0);
	_delay_ms(1);
	sendbyte(0x0F, 0);
	_delay_ms(1);
	sendbyte(0x2C, 0);
	_delay_ms(1);

}
