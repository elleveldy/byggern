#include <avr/io.h>
#include <stdio.h>
#include "uart.h"
#include "mcp2515.h"
#include "SPI.h"
#include "mcp2515_define.h"


int mcp2515_init(){
	spi_init();
	mcp2515_reset();
	
	uint8_t val = mcp2515_read(MCP_CANSTAT);
	if((val & MODE_MASK) != MODE_CONFIG){
		printf("ERROR: MCP2515 is NOT in config mode after reset!\n");
		return 1;
	}
	return 0;
}


int mcp2515_read(int address){
	
	int result;
	
	PORTB &= ~(1 << MCP2515_CS);
	
	spi_write(MCP_READ);
	spi_write(address);
	
	result = spi_write(0x00);
	
	PORTB |= (1 << MCP2515_CS);
	return result;
}

void mcp2515_write(int address, int data){
	
	PORTB &= ~(1 << MCP2515_CS);
	
	spi_write(MCP_WRITE);
	spi_write(address);
	spi_write(data);
	
	PORTB |= (1 << MCP2515_CS);	
}

void mcp2515_request_to_send(int buffer_select){
	PORTB &= ~(1 << MCP2515_CS);
	spi_write(buffer_select);
	PORTB |= (1 << MCP2515_CS);
}

void mcp2515_bit_modify(int address, int mask, int data){
	PORTB &= ~(1 << MCP2515_CS);
	
	spi_write(MCP_BITMOD);
	spi_write(address);
	spi_write(mask);
	spi_write(data);

	PORTB |= (1 << MCP2515_CS);
	
}

void mcp2515_reset(){
	PORTB &= ~(1 << MCP2515_CS);
	spi_write(MCP_RESET);
	PORTB |= (1 << MCP2515_CS);
}

int mcp2515_read_status(){
	
	int result;
	
	PORTB &= ~(1 << MCP2515_CS);

	spi_write(MCP_READ_STATUS);
	result = spi_read();
	PORTB |= (1 << MCP2515_CS);
	
	return result;
}