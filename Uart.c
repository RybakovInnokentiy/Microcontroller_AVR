/*
 * Uart.c
 *
 * Created: 29.01.2022 11:12:09
 *  Author: Kesha
 */ 
#include <xc.h>
#include "Uart.h"
#include <math.h>

void UART_init(unsigned int baud){
	//Setting up  baud rate
    unsigned int ubrr =  F_OSC/baud/16 - 1;
	UBRR0L = ubrr;
	
	//Enable receive & transmit
	UCSR0B = (1 << RXCIE0) | (1 << RXEN0) | (1 << TXEN0);
	
	//Set frame format: 8 data bit, 1 stop bit
	UCSR0C =  (1 << UCSZ00) | (1 << UCSZ01);
}

void UART_Transmit(unsigned char data){
	
	while ( !(UCSR0A & (1 << UDRE0)) );
	UDR0 = data;
}

