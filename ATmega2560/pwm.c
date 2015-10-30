#include "pwm.h"
#include <avr/io.h>

#define SERVO_MAX 40
#define SERVO_MIN 20
#define SERVO_MID = (SERVO_MAX + SERVO_MIN)/2

void pwm_init(){
	//fast pwm
	TCCR3A &= ~(1<< WGM30);
	TCCR3A |= (1<<WGM31);
	TCCR3B |= (1<<WGM32);
	TCCR3B |= (1<<WGM33);
	
	//inverting
	TCCR3A|= (1<<COM3A0);
	TCCR3A|= (1<<COM3A1);
	
	//prescaler
	TCCR3B |= (1<<CS30) | (1<<CS32);
	TCCR3B&= ~(1<<CS31);
	
	ICR3 = 312;
}


void pwn_set_value(uint8_t val){
	OCR3AL = val;
}

void pwm_set_servo(int16_t val){
	
	val = -val;
	val += 128;
	val = (val*18) / 255 + MIN_SERVO;
	
	printf("val: %4i \n",val);
	
	if (val <= (SERVO_MID + 1) && (val>= (SERVO_MID - 1))) {
		pwm_set_value(SERVO_MID);
	} 
	else if(val >= SERVO_MIN && val <= SERVO_MAX){
		pwm_set_value(val);
	} 
	else{
		pwm_set_value(SERVO_MIN);
	}

}



