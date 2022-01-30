/*
 * I2C.c
 *
 * Created: 30.01.2022 15:56:28
 *  Author: Kesha
 */ 

#include <xc.h>

void I2C_Init() {
	TWBR = 0x20;
}

void I2C_StartCondition(){
	TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
	while( !(TWCR & (1 << TWINT)));
}

void I2C_StopCondition(){
	TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);
}

void I2C_SendByte(unsigned char byte){
	TWDR = byte;
	TWCR = (1 << TWINT) | (1 << TWEN);
	while( !(TWCR & (1 << TWINT)));
}

void I2C_SendByteByAddress(unsigned char data, unsigned char address){
	I2C_StartCondition();
	I2C_SendByte(address);
	I2C_SendByte(data);
	I2C_StopCondition();
}