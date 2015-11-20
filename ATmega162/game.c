//not much happens in node 1, we just want to send can messages
//Relevant initialize functions are run in main.c file


#include "game.h"
#include "Communication/canjoy.h"
#include "Display/oled.h"
#include "input.h"
#include "timer.h"
#include "Communication/can.h"
#include "Communication/mcp2515_define.h"
#include "eeprom.h"

#include <stdio.h>
#include <util/delay.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>



//transmitts input through can bus
//Allows you to leave game by button pressing

uint16_t global_score = 0;
#define THRESHOLD 70

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


	oled_write_screen();
	
	while(1){
		if(button_left_read()){
			return;
		}
		
		if(timer_read(TIMER_3) > 80){
			
			timer_reset(TIMER_3);
		}
		
		if(button_right_read()){
			game_save_highscore();
		}
	}
	
	
	
	
}


void game_highscore(){
	
	/*oled_put_string(0,0,"Player1: %i", EEPROM_read(0));*/
	
}


void game_save_highscore(){
	
	_delay_ms(300);
	
	uint8_t line_nr = 2;

	char* name1 = "Erlend";
	uint8_t adr1 = 24;
	char* name2 = "Martin";
	uint8_t adr2 = 16;
	char* name3 = "P3";
	uint8_t adr3 = 8;
	char* name4 = "P4";
	uint8_t adr4 = 0;
	

	
	oled_write_screen();
	
	while(1){
		if(timer_read(TIMER_3) > 80){
			oled_clear_screen();
			
			oled_put_string(0, 0, "Score: %i", global_score);
			oled_put_string(0, 2, "%s: %i", name1, EEPROM_read(adr1));
			oled_put_string(0, 3, "%s: %i", name2, EEPROM_read(adr2));
			oled_put_string(0, 4, "%s: %u", name3, EEPROM_read(adr3));
			oled_put_string(0, 5, "%s: %u", name4, EEPROM_read(adr4));
			oled_invert_line(line_nr);
			
			oled_write_screen();
			
			
			
		}
		
		
		if(joystick_y_value() > 70){
			line_nr--;
			_delay_ms(200);
		}
		else if(joystick_y_value() < -70){
			line_nr++;
			_delay_ms(200);
		}
		else{
			
		}
		
		if(button_right_read()){
			
			if(line_nr == 2){
				EEPROM_write(adr1, global_score);
			}
			else if(line_nr == 3){
				EEPROM_write(adr2, global_score);				
			}
			else if(line_nr == 4){
				EEPROM_write(adr3, global_score);
			}
			else if(line_nr == 5){
				EEPROM_write(adr4, global_score);
			}
			
		}
		
		
		if(line_nr < 2){
			line_nr = 2;
		}
		else if(line_nr > 5){
			line_nr = 5;
		}
		
		if(button_left_read()){
			global_score = 0;
			return;
		}
		
	}
	
}