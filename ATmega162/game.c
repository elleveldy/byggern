//not much happens in node 1, we just want to send can messages
//Relevant initialize functions are run in main.c file

#include "canjoy.h"
#include "oled_alt.h"
#include "joystick.h"
#include "timer.h"

#include <util/delay.h>




//transmitts input through can bus
//Allows you to leave game by button pressing

void game_play(){
		//fiks this
	can_message mode = canjoy_recieve(&mode);
	
	
	
	oled_alt_clear_screen();
	uint8_t score;
	//could be  called in while loop, but shouldn't be neccessary
	
	//can_message game_state = can_recieve(&unused);

	
	while(1){
		
		//oled_alt_clear_screen();
		
		oled_store_string((char[7]){"Return"}, 0, 7);
		oled_store_string((char[13]){"Playing game"}, 2*8, 3);
		
		/*if(timer_read(TIMER_3) > 80){
			canjoy_transmit();
			timer_reset(TIMER_3);	
		}*/
		
		
		/*if(timer_read(TIMER_3) > 80){
			canjoy_recieve();
			timer_reset(TIMER_3);
		}*/
		
		//printf("Timer3: %u", timer_read(TIMER_3));
		
		
		
		//leave game
		if(button_left_read()){
			return;
		}
		
		//score =  mode.data[1];
		
		//printf("%u\n", score);
		
		
		
		//*******************************************		
		//for some reason this fucs our entire oled up
		//*******************************************
		/*if(timer_read(TIMER_3) > 80){
			mode = canjoy_recieve(&mode);
			canjoy_transmit();
			oled_write_screen();
			
			timer_reset(TIMER_3);
		}*/
		
		
		
	}
	
	}