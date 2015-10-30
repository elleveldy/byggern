

#include <avr/io.h>
#include "uart.h"

void uart_Init(unsigned int ubrr){
	
	//Set baud rate
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)ubrr;
	
	//Enable receiver and transmitter
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	
	//Set frame format: 8data, 1stop bit
	UCSR0C = (1 << 7)|(3<<UCSZ00);//here, 7 replaces URSEL0 from ATmega162 project
	
	fdevopen(uart_Transmit, uart_Receive);
}

void uart_Transmit( unsigned char data ){
	
	//Wait for empty transmit buffer
	while( !( UCSR0A & (1<<UDRE0)) );
	
	//Put data into buffer, sends the data
	UDR0 = data;
}

unsigned char uart_Receive(void){
	
	//Wait for data to be received
	
	while( !(UCSR0A & (1<<RXC0)) );
	
	//Get and return received data from buffer
	
	return UDR0;
}
