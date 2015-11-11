
#include <util/delay.h>
#include <avr/io.h>
#include <stdint.h>
#include "motor.h"


void motor_init(){
	
	MOTOR_PORT |= 
	(1 << MOTOR_EN) | 
	(1 << 3/*MOTOR_DIR*/) | 
	(1 << MOTOR_SEL) | 
	(1 << MOTOR_RESET) | 
	(1 << MOTOR_OUTPUT_EN);
	
}


/*
void motor_enable(uint8_t enable){
	if(enable){
		MOTOR_PORT |= (1 << MOTOR_EN);
	}
	else{
		MOTOR_PORT &= ~(1 << MOTOR_EN);
	}
}*/

void motor_direction(uint8_t direction){
	
	if(direction == 1){
		MOTOR_PORT |= (1 << 3/*MOTOR_DIR*/);
	}
	else if(direction == -1){
		MOTOR_PORT |= (1 << 3/*MOTOR_DIR*/);		
	}
}

void motor_speed(uint8_t speed){
	max520_send(speed);
}

void motor_test(){
	printf("Entering motor_test\n");
	motor_speed(100);
	
	motor_direction(-1);
	_delay_ms(500);
	motor_direction(1);
	_delay_ms(500);
	
}
