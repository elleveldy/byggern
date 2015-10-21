/*
 * Byggern_G48_2015.c
 *
 * Created: 28.08.2015 13:48:07
 *  Author: marteil
 */ 

#define F_CPU 4915200

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

#include "uart.h"
#include "joystick.h"
#include "oled.h"
#include "gui.h"
#include "menu.h"
#include "mcp2515.h"
#include "SPI.h"
#include "snake.h"
#include "mcp2515_define.h"



void SRAM_test(void);



int main(void){
	fdevopen(uart_Transmit, uart_Receive);
	
//switch case that only rewrites menu when joystick is moved
	
	
	MCUCR |= (1 << SRE);
	
	uart_Init(MYUBRR);
	
	
	buttons_init(); // useless thus far
	oled_init();	
	oled_clear_screen();	
	oled_home();
	
	
	Menuitem* menu = create_menu();
	menu_selector = menu;
	menu_line_nr = 0; 
	
	
	
	mcp2515_init();
	
	snake_print_snake();
	
    while(1){
		//mcp2515_write(MCP_CANINTE, 120);
		//svar = mcp2515_read(MCP_CANINTE);
		//
		//printf("Svar: %d\n", svar);
		//
		//_delay_ms(500);
		
		//alt_gui_run();
	}
}




void SRAM_test(void)
{
	volatile char *ext_ram = (char *) 0x1800; // Start address for the SRAM
	uint16_t ext_ram_size       = 0x800;
	uint16_t write_errors       = 0;
	uint16_t retrieval_errors   = 0;

	printf("Starting SRAM test...\n");

	// rand() stores some internal state, so calling this function in a loop will
	// yield different seeds each time (unless srand() is called before this function)
	uint16_t seed = rand();

	// Write phase: Immediately check that the correct value was stored
	srand(seed);
	for (uint16_t i = 0; i < ext_ram_size; i++) {
		uint8_t some_value = rand();
		ext_ram[i] = some_value;
		uint8_t retreived_value = ext_ram[i];
		if (retreived_value != some_value) {
			//printf("Write phase error: ext_ram[%4d] = %02X (should be %02X)\n", i, retreived_value, some_value);
			write_errors++;
		}
	}

	// Retrieval phase: Check that no values were changed during or after the write phase
	srand(seed);    // reset the PRNG to the state it had before the write phase
	for (uint16_t i = 0; i < ext_ram_size; i++) {
		uint8_t some_value = rand();
		uint8_t retreived_value = ext_ram[i];
		if (retreived_value != some_value) {
			//printf("Retrieval phase error: ext_ram[%4d] = %02X (should be %02X)\n", i, retreived_value, some_value);
			retrieval_errors++;
		}
	}
	printf("SRAM test completed with \n%4d errors in write phase and \n%4d errors in retrieval phase\n\n", write_errors, retrieval_errors);
}





