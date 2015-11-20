


#include <avr/io.h>
#include "timer.h"
#include <stdio.h>


//with prescaler = 1024 and COUNT = 65535, one full count cycle = 4.1 s    (ish)
#define COUNT 65535
//time[sec] = 65535  / 16Mhz = 0.0040959375


void timer_init() {
	
	//**********************
	//timer 4
	//**********************
	//Normal mode, zero prescaler
	TCCR4A = 0;
	TCCR4B = 0;
	
	//CS4{2:0}   = 101  prescaler set to 1024
	TCCR4B |=  (1<<CS42) | (1<<CS40);
	TCCR4B &= ~(1<<CS41);
	
	
	//**********************
	//timer 5
	//**********************
	//Normal mode, zero prescaler	
	TCCR5A = 0;
	TCCR5B = 0;
	
	//CS5{2:0}   = 001  prescaler set to 1
	TCCR5B |= (1<<CS52) | (1<<CS50);
	TCCR5B &= ~(1<<CS51);
	
	//0100 -> Mode CTC -> TOP = OCRnA
/*
	TCCR4A &= ~(1<<WGM40);
	TCCR4A &= ~(1<<WGM41);
	TCCR4B |=  (1<<WGM42);
	TCCR4B &= ~(1<<WGM43);
	
	OCR4A = 0x7FFF;*/

}



uint16_t timer_read(uint8_t timer){
	if(timer == 1)
		return TCNT1;
	else if(timer == 3)
		return TCNT3;
	else if(timer == 4)
		return TCNT4;
	else if(timer == 5)
		return TCNT5;
}

uint16_t timer1_read(){
	return TCNT1;
}
uint16_t timer3_read(){
	return TCNT3;
}
uint16_t timer4_read(){
	return TCNT4;
}
uint16_t timer5_read(){
	return TCNT5;
}


void timer_reset(uint8_t timer){
	if(timer == 1)
		TCNT1 = 0;
	else if(timer == 3)
		TCNT3 = 0;
	else if(timer == 4)
		TCNT4 = 0;
	else if(timer == 5)
		TCNT5 = 0;
}

void timer1_reset(){
	TCNT1 = 0;
}
void timer3_reset(){
	TCNT3 = 0;
}
void timer4_reset(){
	TCNT4 = 0;
}
void timer5_reset(){
	TCNT5 = 0;
}


