/*
 * I2C.h
 *
 * Created: 30.01.2022 15:55:49
 *  Author: Kesha
 */ 


#ifndef I2C_H_
#define I2C_H_

void I2C_Init();
void I2C_StartCondition();
void I2C_StopCondition();
void I2C_SendByte(unsigned char byte);
void I2C_SendByteByAddress(unsigned char data, unsigned char address);



#endif /* I2C_H_ */