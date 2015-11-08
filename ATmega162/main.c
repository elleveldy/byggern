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
#include "stdio.h" //for fdevopen

#include "uart.h"
#include "joystick.h"

//#include "oled.h"		FIX
#include "oled_alt.h"

//#include "gui.h"
#include "gui_alt.h"

#include "menu.h"
#include "mcp2515.h"
#include "SPI.h"
#include "snake.h"
#include "mcp2515_define.h"
#include "can.h"
#include "canjoy.h"

/*
FIX BEFORE EVALUATION
check if header files are included in their respective c files, and if they should be
to avoid "implicit declaration of function

If oled writing fucks up, check if you need to:
		oled_store_string((char[5]){"dick"}, (int[2]){0, 0});

MENU/GUI instantly goes into first submenu in main, but this pattern doesn't repeat
	in sub menus, so wtf

can recieve has pointer parameter which is not used.

Try to remove all warnings

Add drawing functions



*/


void SRAM_test(void);



int main(void){
	fdevopen(uart_Transmit, uart_Receive);
	
	MCUCR |= (1 << SRE);
	
	uart_Init(MYUBRR);
	
	
	buttons_init(); // useless thus far
	/*oled_init();	
	oled_clear_screen();	
	oled_home();*/
	
	
	Menuitem* menu = create_menu();
	menu_selector = menu;
	menu_line_nr = 0; 
	
	can_init(MODE_NORMAL);
	
	
	/*can_message joy;
	joy.id = 3;
	joy.length = 2;*/
	
	/*while(1){
		
		/ *can_test_transmit();
		printf("\nin main while\n");* /
		
		
		
		printf("X: %d\n", joystick_read_x());
		canjoy_transmit();
		
	}*/
	
	oled_alt_init();
	
	//gui_print_menu(menu);
	//oled_store_string("Testing2", 0 , 0);
	
	//gui_print_menu(menu);
	
	
	while(1){
		gui_alt_run();
		
		oled_write_screen();	
		
		
		//printf("menu_line_nr: %d\n", menu_line_nr);
		
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





