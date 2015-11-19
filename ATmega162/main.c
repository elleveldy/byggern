/*
 * Byggern_G48_2015.c
 *
 * Created: 28.08.2015 13:48:07
 *  Author: marteil
 */ 

//#define F_CPU 4915200

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
#include "sram.h"

#include "timer.h"

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

Write highscore to EEROM? In atmega162 datasheet

Settings -> difficulty ->change speed of motor

Add drawing functions?



*/



/*
Node 2 runs by a switch case, controlled
by the recieved can message ID.



*/


int main(void){
	fdevopen(uart_Transmit, uart_Receive);
	
	MCUCR |= (1 << SRE);
	
	uart_Init(MYUBRR);
	
	
	buttons_init(); // useless thus far

	
	Menuitem* menu = create_menu();
	menu_selector = menu;
	//menu_line_nr = 0; 
	
	
	//consider putting this elsewhere, to
	//allow selection of can tests in runtime
	can_init(MODE_NORMAL);
	
	timer_init();	
	oled_alt_init();
	

	
	while(1){


		gui_alt_run();

		oled_refresh_60Hz();
		
	
		
		/*canjoy_transmit();*/
		


		
	}
	
	
}








