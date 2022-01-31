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

unsigned char buf[100];
unsigned char ind = 0, stringReceived = 0;
unsigned char gpgga[] = {'$', 'G', 'P', 'G', 'G', 'A'};


ISR(USART_RX_vect){


	   buf[ind] = UDR0;
	   ind = ind + 1;
	   if(ind < 7)
	   {
		   if( buf[ind - 1] != gpgga[ind - 1] )                // $GPGGA
		   ind = 0;
	   }
	   if(ind >= 50){
		   if(ind > 99) ind = 0;
		   stringReceived = 1;
	   }
	  
}

int main(void)
{

	sei();
	UART_init(BAUD);
	I2C_Init();
	LCD_Init();
	
	setpos(0, 0);
	sendchar('L');
	sendchar('A');
	sendchar('T');
	sendchar(':');
	setpos(0, 1);
	sendchar('L');
	sendchar('O');
	sendchar('G');
	sendchar(':');

	while(1) {
		
		if(stringReceived == 1){

			stringReceived = 0;
			setpos(4, 0);
			_delay_ms(10);
			for(int i = 17; i < 26; i++) {
				sendchar(buf[i]);
				_delay_ms(10);
			}
			sendchar(' ');
			_delay_ms(10);
			sendchar('N');
			_delay_ms(10);
			setpos(4, 1);
			_delay_ms(10);
			for(int i = 31; i < 40; i++) {
				sendchar(buf[i]);
				_delay_ms(10);
			}
			sendchar(' ');
			_delay_ms(10);
			sendchar('E');
			_delay_ms(10);
	

		}
	}	

}




