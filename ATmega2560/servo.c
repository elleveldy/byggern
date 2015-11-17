#include <stdio.h>
#include <stdlib.h>//abs()
#include <avr/io.h>

#include "pwm.h"

/*
	val = 250 -> 1 ms pulse
	val = 225 -> 0.9 ms pulse
	val = 525 -> 2.1 ms pulse
	we want pulse widths between 225 and 525
	
*/

//These values keep the pulse width in the specified range 0.9ms - 2.1ms
#define PULSE_PERIOD 5000

#define P_MAX 525
#define P_MIN 225
#define P_MID (P_MAX + P_MIN)/2 //( = 375)
#define P_RESOLUTION P_MAX - P_MIN // = 300



void servo_init(){
	pwm_init(PULSE_PERIOD, P_MID);
}


void servo_set_pulse(int16_t pulse_width){
	
	if(pulse_width >= P_MAX){
		pwm_set_pulse_width(P_MAX);
	}
	else if(pulse_width < P_MIN){
		pwm_set_pulse_width(P_MIN);
	}
	else{
		pwm_set_pulse_width(pulse_width);
	}
	return;
}

void servo_set_pulse_by_input(int16_t val){
	
	//reverses control, more intuitive width our hardware
	val = abs(val - 255);
	
	
	uint16_t pulse_width = (float)(val * (300/255.0)) + P_MIN;
	servo_set_pulse(pulse_width);
}
