


#include <avr/io.h>
#include "timer.h"
#include <stdio.h>


//with prescaler = 1024 and COUNT = 65535, one full count cycle = 4.1 s    (ish)
#define COUNT 65535
//time[sec] = 65535  / 16Mhz = 0.0040959375


int time_tick = 0;
int time_tick_max = 0;
void timer_init() {
	
	//Normal mode, zero prescaler
	TCCR4A = 0;
	TCCR4B = 0;
	
	//CS4{2:0}   = 101  prescaler set to 1024
	TCCR4B |=  (1<<CS42) | (1<<CS40);
	TCCR4B &= ~(1<<CS41);
	
	
	//0100 -> Mode CTC -> TOP = OCRnA
/*
	TCCR4A &= ~(1<<WGM40);
	TCCR4A &= ~(1<<WGM41);
	TCCR4B |=  (1<<WGM42);
	TCCR4B &= ~(1<<WGM43);
	
	OCR4A = 0x7FFF;*/

}

uint16_t timer_read(){
	return TCNT4;
}

void timer_reset(){
	TCNT4 = 0;
}

void timer_start(){
	OCR4A = COUNT;
	TCNT4 = 0;
}


int timer_done(){
	if(TCNT4 >= COUNT){
		return 1;
	}
	else{
		return 0;
	}
}

/*
void timer_simple_test(){
	int ticktock;
	timer_start();
	while(1){
		if(timer_done()){
			printf("t: %d\n", ticktock);
		}
	}
}
*/


int timer_cycle_start(int time_max){
	
	time_tick = 0;
	timer_start();
	
}

//Needs to be called in while loop to increase time_tick
void timer_tick_iterate(){
	if(timer_done()){
		time_tick++;
	}
}

int timer_cycle_done(){
	if(time_tick >= time_tick_max){
		time_tick = 0;
		return 1;
	}
	else{
		return 0;
	}
}

int time_ms_start(int ms_time){
	
	time_tick_max = (ms_time * 16000000.0)/COUNT;
	
}




/*
ISR(TIMER4_COMPA_vect){
	//printf("read: %d\n",adc_read(0));
	//printf("edge: %d\n\n",ir_edge_detected());

	if(ir_edge_detected()){
		can_ir_transmit();
		
	}
	
	can_handle_message();
}
*/


