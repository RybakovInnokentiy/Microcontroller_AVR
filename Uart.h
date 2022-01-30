/*
 * Uart.h
 *
 * Created: 29.01.2022 11:12:25
 *  Author: Kesha
 */ 


#ifndef UART_H_
#define UART_H_

#define F_OSC 8000000

void UART_init(unsigned int baud);
void UART_Transmit(unsigned char data);



#endif /* UART_H_ */