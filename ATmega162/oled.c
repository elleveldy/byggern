#include <stdint.h>
#include <stdio.h>
#include <avr/io.h>
#include <math.h> //sqrt
#include "oled.h"
#include "font.h"
#include "joystick.h"//should be removed




static FILE oled_stdout = FDEV_SETUP_STREAM(oled_print_char, NULL, _FDEV_SETUP_WRITE); 

volatile char *oled_data_adr = (char *) 0x1200;
volatile char *oled_command_adr = (char *) 0x1000;



static inline void oled_command_write(char command){
	*oled_command_adr = command; 
}

static inline void oled_testo(char command){
	*oled_command_adr = command;	
}


static inline void oled_data_write(char data){
	*oled_data_adr = data;
}

void oled_init()
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
	oled_command_write(0x02);
	oled_command_write(0xdb);    //VCOM deselect level mode
	oled_command_write(0x30);
	oled_command_write(0xad);    //master configuration
	oled_command_write(0x00);
	oled_command_write(0xa4);    //out follows RAM content
	oled_command_write(0xa6);    //set normal display
	oled_command_write(0xaf);    // display on
	//oled_command_write(0xa4);    //Entire display on
	
	//oled_clear_screen();
	oled_home();
}




//void oled_goto_col(int col){
	//oled_command_write(0x0f + col);
	//
//}

void oled_goto_col(int column){
	oled_command_write(column & 0x0f);
	oled_command_write(((column & 0xf0) >> 4) | (0x10));
}

void oled_goto_page(int page){
	oled_command_write(0xB0 + page);
	oled_command_write(0x00);
}

void oled_goto_pos(int col, int page){
	oled_goto_page(page);
	oled_goto_col(col);
}

void oled_home(){
	oled_goto_pos(0,0);
}


void oled_clear_page(int page){
	oled_goto_page(page);
	for(int col = 0; col < 128; col++){
		oled_data_write(0x00);
	}
}

void oled_clear_col(int col){
	int col_nr = col*8;
	oled_goto_col(col_nr);
	for(int page = 0; page < 8; page++){
		oled_goto_pos(col_nr, page);
		oled_print_char(' ');
	}
}

void oled_clear_col_interval(int col, int a, int b){
	int col_nr = col*8;
	oled_goto_col(col_nr);
	for(int page = a; page < b; page++){
		oled_goto_pos(col_nr, page);
		oled_print_char(' ');
	}
}

void oled_clear_screen(){
	for(int page = 0;page < 8; page++){
		oled_clear_page(page);
	}
}


void oled_print_char(char character){
	for(int col = 0; col < font_width; col++){
		oled_data_write(pgm_read_byte(&font[character - FONT_OFFSET][col]));
	}
}


void oled_printf(char* fmt, ...){
	va_list v;
	va_start(v, fmt);
	vfprintf(&oled_stdout, fmt, v);
	va_end(v);
}


void oled_printf2(char* str){
	
	int i = 0;
	while(str[i] != '\0'){
		oled_print_char(i);
	}
	
}



void oled_mode_negative(){
	oled_command_write(0xa7);
}

void oled_mode_normal(){
	oled_command_write(0xa6);
}

int screen_negative = 0;

void oled_toggle_negative(){
	if(screen_negative){
		oled_mode_normal();
		screen_negative = 0;
	}
	else{
		oled_mode_negative();
		screen_negative = 1;
	}
}


//untested but might work
void oled_change_contrast(){

	int contrast;
	oled_clear_screen();
	oled_home();
	oled_printf("Contrast");
	oled_goto_pos(0, 3);
	oled_printf("left slider");
	oled_goto_pos(3,7);
	oled_printf("Default");


	while(1){
	
		
		if(button_left_read()){
			return;
		}
		else if(button_right_read()){
			oled_command_write(0x81);    
			oled_command_write(0x50);
			return;
		}

		contrast = slider_left_read();

		oled_command_write(0x81);    
		oled_command_write(contrast);

	}
}

//void oled_draw_line(int x0, int y0, int x1, int y1){
//
	//int slope = (y1-y0) / (x1 - x0);
	//int y;
//
	//for(int x = x0; x <= x1; x++){
		//y = slope * x + x1;
		////write to pixel (x,y)
	//}
//}
//
//void oled_draw_circle(int x0, int y0, int r){
//
	//int y;
	//int distX;
//
	//for(int x = x0 - r; x <= x0 + r; x++){
		////		if(x is out of range){
		////			continue;
		////		}
		////import math that allows sqrt()
		//
		//distX = r - x;
		//y = sqrt(r * r - distX * distX);
//
		////write to  (x, y0 + y) and (x, y0 - y)
//
		////write to pixel (x)
	//}
//
	//void oled_draw_rectangle(int x0, int y0, int x1, int y1){
		//oled_draw_line(x0, y0, x1, y0);
		//oled_draw_line(x1, y0, x1, y1);
		//oled_draw_line(x1, y1, x0, y1);
		//oled_draw_line(x0, y1, x0, y0);
	//}
//
