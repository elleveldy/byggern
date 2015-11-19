//not much happens in node 1, we just want to send can messages
//Relevant initialize functions are run in main.c file


#include "game.h"
#include "canjoy.h"
#include "oled_alt.h"
#include "joystick.h"
#include "timer.h"
#include "can.h"
#include "mcp2515_define.h"
#include "eeprom.h"

#include <stdio.h>
#include <util/delay.h>
#include <stdlib.h>
#include <string.h>



//transmitts input through can bus
//Allows you to leave game by button pressing

uint16_t global_score = 0;


void game_play(){
		//fiks this
	can_init(MODE_NORMAL);
	can_message game_status = canjoy_recieve(&game_status);
	
	
	
	oled_clear_screen();
	oled_store_string((char[7]){"Return"}, 0, 7);
	oled_store_string((char[13]){"Playing game"}, 2*8, 3);

	

	uint8_t stuff = 10;
	while(1){
		
		
		
		//leave game
		if(button_left_read()){
			return;
		}
	
		
		printf("running: %u\tScore: %u\tId: %u\n",game_status.data[0], game_status.data[2], game_status.id);
		
		//*******************************************		
		//60 oled writing and canjoy transmition
		//*******************************************
		if(timer_read(TIMER_3) > 80){
			oled_clear_screen();
			
			
			
			global_score++;
			
			oled_store_string((char[7]){"Return"}, 0, 7);;
			oled_put_string(0, 7, "Return");
			oled_put_string(2*8, 3, "Playing game");
			
			
			oled_put_string(3*8, 5, "Score: %i", global_score);


			oled_write_screen();
			canjoy_transmit();
			_delay_ms(5);
			game_status = canjoy_recieve(&game_status);
			
			//printf("buffer: %s\n", buffer);
			
			if(game_status.id == CAN_GAME_STATE_OVER){
				

				game_over();
			}
			
			timer_reset(TIMER_3);
		}
		
		
		
	}
	
}


void game_over(){
	oled_clear_screen();
	oled_store_string((char[10]){"GAME OVER"}, 3*8, 3);
	oled_store_string((char[7]){"Return"}, 0, 7);
	oled_put_string(3*8, 5, "Score: %i", global_score);

	oled_write_screen();
	
	uint8_t number = 125; 

	oled_write_screen();
	
	while(1){
		if(button_left_read()){
			return;
		}
		
		if(timer_read(TIMER_3) > 80){
			
			//oled_store_string((char[6]){score_string}, 2*8, 5);
				
		
			
			timer_reset(TIMER_3);
		}
		
		if(button_right_read()){
			game_save_highscore();
		}
	}
	
	
	
	
}


void game_highscore(){
	
	oled_put_string(0,0,"Player1: %i", EEPROM_read(0));
	
}

void game_save_highscore(){
	
	oled_clear_screen();
	
	oled_put_string(0*8 , 0, "Score: %i", global_score);
	oled_put_string(0*8, 4, "P1");
	oled_put_string(3*8, 3, "P2");
	oled_put_string(7*8, 4, "P3");
	oled_put_string(3*8, 5, "P4");

	oled_write_screen();
	
	while(1){
		
		//use joystick to write to eeprom
		
	}
	
}