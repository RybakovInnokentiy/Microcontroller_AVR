/*
 * main.c
 *
 * Created: 1/26/2022 8:53:58 PM
 *  Author: Kesha
 */ 

#include <xc.h>
#include <avr/io.h>
#include <util/delay.h>
#include <math.h>
#include <avr/interrupt.h>
#include "Uart.h"
#include "I2C.h"
#include "LCD.h"

#define BAUD 9600

ISR(USART_RX_vect){
	unsigned char data = UDR0;	
	UART_Transmit(data);
}

int main(void)
{
	sei();
	UART_init(BAUD);
	I2C_Init();
	LCD_Init();
	
	setpos(0, 0);
	_delay_ms(1);
	sendchar('K');
	sendchar('E');
	sendchar('s');
	sendchar('H');
	sendchar('A');
	sendchar('n');
	setpos(0, 1);
	_delay_ms(1);
	sendchar('M');
	sendchar('o');
	sendchar('L');
	sendchar('o');
	sendchar('D');
	sendchar('E');
	sendchar('C');
    while(1)
    {
		
    }
}





