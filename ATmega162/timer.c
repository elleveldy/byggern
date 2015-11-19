#include <avr/io.h>
#include <stdio.h>
#include "timer.h"
//timer 1 and 3 are 16 bit timers

void timer_init(){
	//timer1 to be used for Oled_refresh at 60 Hz
	
	TCCR1A = 0;
	TCCR1B = 0;
	
	//prescaler = 1024. Clock now counts at F_CPU / 1024 Hz = 4800 Hz
	TCCR1B |= (1<<CS12) | (1<<CS10);
	TCCR1B &= ~(1<<CS11);
	
	//Clock now counts at F_CPU / 1024 Hz = 4800 Hz
	//4800 / 80 = 60Hz, so we need to refresh every
	//80th count, and we want max TCNT1 to be a multiple
	//of 80 under 65535, 80*819 = 65520, which seems fine
	
	//or simpler, but makes it impossible for other modules
	//to use timer1, just reset and refresh oled after
	//80 clock ticks
	
	//Mode 0, clock max = 0xFFFF
	TCCR1A &= ~(1<<WGM10);
	TCCR1A &= ~(1<<WGM11);
	TCCR1B &= ~(1<<WGM12);
	TCCR1B &= ~(1<<WGM13);
	
	
	//timer 3 to avoid can message spam
	//same mode and prescalre as timer 1
	TCCR3A = 0;
	TCCR3B = 0;
	
	TCCR3B |= (1<<CS32) | (1<<CS30);
	TCCR3B &= ~(1<<CS31);
	
	TCCR3A &= ~(1<<WGM10);
	TCCR3A &= ~(1<<WGM11);
	TCCR3B &= ~(1<<WGM12);
	TCCR3B &= ~(1<<WGM13);
}

uint16_t timer_read(timer nr){
	if(nr == TIMER_1)
		return TCNT1;
	else if(nr == TIMER_2)
		return TCNT2;
	else if(nr == TIMER_3)
		return TCNT3;
}

void timer_reset(timer nr){
	if(nr == TIMER_1)
		TCNT1 = 0;
	else if(nr == TIMER_2)
		TCNT2 = 0;
	else if(nr == TIMER_3)
		TCNT3 = 0;
}

