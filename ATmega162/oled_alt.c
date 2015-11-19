
/*
**********************************************************
If oled fucks up, use conservative oled_store() function
**********************************************************

*/



#include <avr/pgmspace.h>
#include "oled_alt.h"
#include "font.h"
#include "timer.h"	//to achieve 60Hz refresh rate
#include "joystick.h" //for oled_contrast_change
#include "util/delay.h"

#define OLED_DATA_ADRESS (volatile char*)0x1200
#define OLED_COMMAND_ADRESS (volatile char*)0x1000

#define SRAM_ADRESS (volatile char*)0x1800

#define FONT_SIZE 8
#define FONT_HEIGHT 8
#define FONT_WIDTH 8

#define NR_LINES 8 //1-indexed
#define NR_COL 128 //1-indexed



static inline void oled_command_write(char command){
	*OLED_COMMAND_ADRESS = command;
}


static inline void oled_data_write(char data){
	*OLED_DATA_ADRESS = data;
}





void oled_alt_init()
{
	
	oled_command_write(0xae);    // display off
	oled_command_write(0xa1);    //segment remap
	oled_command_write(0xda);    //common pads hardware: alternative
	oled_command_write(0x12);
	oled_command_write(0xc8);    //commonoutput scan direction:com63~com0
	oled_command_write(0xa8);    //multiplex ration mode:63
	oled_command_write(0x3f);
	oled_command_write(0xd5);    //displaydivide ratio/osc. freq. mode
	oled_command_write(0x80);
	oled_command_write(0x81);    //contrast control
	oled_command_write(0x50);
	oled_command_write(0xd9);    //set pre-charge period
	oled_command_write(0x21);

	oled_command_write(0x20);    //Set Memory Addressing Mode
	oled_command_write(0x00);	// 
	
	oled_command_write(0xdb);    //VCOM deselect level mode
	oled_command_write(0x30);
	oled_command_write(0xad);    //master configuration
	oled_command_write(0x00);
	oled_command_write(0xa4);    //out follows RAM content
	oled_command_write(0xa6);    //set normal display
	oled_command_write(0xaf);    // display on
	
	oled_command_write(0x21);
	oled_command_write(0x00);
	oled_command_write(0x7f);
	
	oled_command_write(0x22);
	oled_command_write(0x00);
	oled_command_write(0x7f);	
	//oled_command_write(0xa4);    //Entire display on
	
	//oled_clear_screen();
	//oled_home();
	
	//to allow 60Hz refresh rate	
	
}

void oled_store(char* string, int* position){
	//calculate position offset
	int start_position = position[0]*128 + position[1];
	for(int i = 0; string[i] != '\0'; ++i){
		//j goes through each col	n of the char in font
		for(int j = 0; j < FONT_SIZE; ++j){
			//font[char index in font][column of char]
			*(SRAM_ADRESS + start_position + i * FONT_SIZE + j) = pgm_read_byte(&font[(int)string[i] - 32][j]);
		}
	}
}


//might be unreliable, due to uncertain string length
void oled_store_string(char* string, int col, int line){
	
	oled_store(string, (int[2]){line, col});
	
}

void oled_store_string2(char* string, int col, int line){
	
	oled_store(*string, (int[2]){line, col});

}





void oled_write_screen(){
	for(int i = 0; i < 1024; ++i){
		*OLED_DATA_ADRESS = *(SRAM_ADRESS + i);
	}
}



//Seems work at 60Hz
void oled_refresh_60Hz(){
	
	//F_CPU = 4.9152MHz, prescaler = 1024
	//F_CPU / prescaler = 4800Hz = 60Hz * 80
	if(timer_read(TIMER_1) > 80){
		oled_write_screen();
		timer_reset(TIMER_1);
	}
}


void oled_invert_line(uint8_t line){
	
	uint16_t start_position = line * 128;
	uint8_t col_byte;
	
	for(int col = 0; col < 128; ++col){
		col_byte = ~*(SRAM_ADRESS + start_position + col);
		*(SRAM_ADRESS + start_position + col) = col_byte;
	}

}

void oled_alt_clear_line(int line){
	
	for(int col = 0; col < NR_COL; col += 8){
		oled_store((char[2]){" "}, (int[2]){line, col});
	}
	
}

void oled_alt_clear_col_line_interval(int col, int line_a, int line_b){
	
	for(int line = line_a; line < line_b; ++line){
		oled_store_string(" \n", col, line);
	}
	
}



void oled_alt_clear_screen(){
	for(int line = 0; line < NR_LINES; ++line){
		oled_alt_clear_line(line);
	}
}






void oled_alt_mode_negative(){
	oled_command_write(0xa7);
}

void oled_alt_mode_normal(){
	oled_command_write(0xa6);
}


uint8_t screen_negative = 0;

void oled_alt_toggle_negative(){
	if(screen_negative){
		oled_alt_mode_normal();
		screen_negative = 0;
	}
	else{
		oled_alt_mode_negative();
		screen_negative = 1;
	}
}


void oled_alt_change_contrast(){
	
	uint8_t contrast;
	
	//print usefull information
	
	
	while(1){
		//oled_alt_clear_screen();
		
		oled_alt_clear_screen();
		
		oled_store((char[9]){"Contrast"}, (int[2]){0, 0});
		oled_store((char[12]){"left slider"}, (int[2]){4, 3*8});
		oled_store((char[7]){"Return"}, (int[2]){7, 0});
		//oled_store((char[4]){"Max"}, (int[2]){7, 12*8});
		oled_store_string((char[4]){"Max"}, 12*8, 7);
			
			
		
		oled_write_screen();
		
		contrast = slider_left_read() - 2;
		oled_command_write(0x81);    //contrast control
		oled_command_write(contrast);  
		
		
		if(button_left_read()){
			return;
		}
		if(button_right_read()){
			oled_command_write(0x81);    //contrast control
			oled_command_write(0xff);
			return;
		}
	}	

}


void oled_epleptic_seizure(){
	while(1){
		oled_alt_toggle_negative();
		_delay_ms(70);
	}
	if(button_left_read()){
		return;
	}
}

//special characters
/*void oled_store*/
