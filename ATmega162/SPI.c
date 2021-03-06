#include "uart.h"
#include "SPI.h"
#include <avr/io.h>

void spi_init(){
			//SI out		SS out		SCK out
	DDRB |= ( 1 << PB5) | (1 << PB4) | (1 << PB7);
			//SO in
	DDRB &= ~(1 << PB6);
	
	//								 frequency / 16
	SPCR= (1 << SPE) | (1 << MSTR) | (1 << SPR0);
}

//both read and write
int spi_write(char data){
	//SPDR = data;
	//while(!(SPSR & (1<<SPIF)));
	SPDR = data;
	while(!(SPSR & (1<<SPIF)));
	return SPDR;
}

//obsolete?
char spi_read(){
	while(!(SPSR & (1<<SPIF)));
	return SPDR;
}

/*
int spi_transmit(char data){
	//SPDR = data;
	//while(!(SPSR & (1<<SPIF)));
}*/