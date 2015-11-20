#include "pwm.h"

#include <stdio.h>
#include <stdlib.h>//abs()
#include <avr/io.h>

/*
#define SERVO_MAX 40
#define SERVO_MIN 20
#define SERVO_MID (SERVO_MAX + SERVO_MIN)/2*/



//P for pulse




void pwm_init(uint16_t pulse_period, uint16_t initial_pulse_width){
	DDRE |= (1<<PE3);
	PORTE |= (1<<PE3);
	
	TCCR3A = 0;
	TCCR3B = 0;
	TCCR3C = 0;
	
	//16 bit, fast pwm, top: ICR, update OCRnx at bottom, TOVn Flag set on TOP
	TCCR3A &= ~(1<< WGM30);
	TCCR3A |= (1<<WGM31);
	TCCR3B |= (1<<WGM32);
	TCCR3B |= (1<<WGM33);
	
	//inverting		
	TCCR3A |= (0<<COM3A0);
	TCCR3A |= (1<<COM3A1);
	
	//prescaler,	CLK / 64
	TCCR3B |= (1<<CS30) | (1<<CS31);
	TCCR3B &= ~(1<<CS32);
	
	//20 ms
	ICR3 = pulse_period;
	
	OCR3A = initial_pulse_width; //should be P_MID
	
	//printf("PWM init done:\n\tTCCRA: %02X\n\tTCCRB: %02X\n\tICR: %02X\n\tOCR: %02X\n", TCCR3A, TCCR3B, ICR3, OCR3A);
}


void pwm_set_pulse_width(uint16_t pulse){
	OCR3A = pulse;
}

/*
void pwm_set_pulse(int16_t val){
	
	if(val >= P_MAX)
		pwm_set_value(P_MAX);
	else if(val < P_MIN)
		pwm_set_value(P_MIN);
	else
		pwm_set_value(val);
	return;
}


//uses joystick_x_value() which returns between 0 and 255
void pwm_joystick_pulse(int16_t val){
	
	if((val > 255) || (val < 0)){
		printf("ERROR: pwm_joystick_pulse input val = %d out of range!\n", val);
		pwm_set_value(P_MID);
		return;
	}
	else{
		
		uint16_t pulse_width = (val * (300/255.0)) + P_MIN;
		
		//printf("\nPulse converted from %d to %d\t P_RESOLUTION = %d\n", val, pulse_width, P_RESOLUTION);
		pwm_set_pulse(pulse_width);
	}
	return;
}

void pwm_alt_joystick_pulse(int16_t val){
	
	pwm_joystick_pulse(abs(val - 255));
	
}
*/


