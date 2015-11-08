#include "pwm.h"

#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>

/*
#define SERVO_MAX 40
#define SERVO_MIN 20
#define SERVO_MID (SERVO_MAX + SERVO_MIN)/2*/


/*
	val = 250 gir 1 ms pulse
	val = 225 gir 0.9 ms pulse
	val = 525 gir 2.1 ms pulse
	vi vil ha verdier mellom 225 og 525
	
*/
//P for pulse
#define P_MAX 525
#define P_MIN 225
#define P_MID (P_MAX + P_MIN)/2 //( = 375)
#define P_RESOLUTION P_MAX - P_MIN // = 300



void pwm_init(){
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
	ICR3 = 5000;
	
	OCR3A = 375;
	
	//printf("PWM init done:\n\tTCCRA: %02X\n\tTCCRB: %02X\n\tICR: %02X\n\tOCR: %02X\n", TCCR3A, TCCR3B, ICR3, OCR3A);
}


void pwm_set_value(uint16_t val){
	OCR3A = val;
}

void pwm_set_servo(int16_t val){
	//delete and remove from header
}

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



