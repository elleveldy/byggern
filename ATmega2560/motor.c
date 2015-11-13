


#include <util/delay.h>
#include <avr/io.h>
#include <stdint.h>
#include <stdlib.h> //for abs()
#include "motor.h"
#include "ir.h"
#include "canjoy.h"
#include "max520.h"
#include "pwm.h"
#include "solenoid.h"

void motor_init(){
	max520_init();
	
	MOTOR_DDR |=
	(1 << MOTOR_EN) |
	(1 << MOTOR_DIR) |
	(1 << MOTOR_SEL) |
	(1 << MOTOR_ENCODER_RESET) |
	(1 << MOTOR_OUTPUT_EN);
	
	MOTOR_PORT |= 
	(1 << MOTOR_EN) | 
	(1 << MOTOR_DIR) | 
	(1 << MOTOR_SEL);

	MOTOR_PORT &= ~(1 << MOTOR_OUTPUT_EN);
	
	DDRK = 0;
	
	motor_encoder_reset();
	
}


// val = bool
void motor_encoder_select_byte(uint8_t val){
	//MOTOR_DDR |= (1 << MOTOR_SEL);
	if(val){
		MOTOR_PORT |= (1 << MOTOR_SEL);
	}
	else{
		MOTOR_PORT &= ~(1 << MOTOR_SEL);
	}
}

void motor_encoder_output_enable(uint8_t enable){

	if(enable){
		MOTOR_PORT &= ~(1 << MOTOR_EN);
	}
	else{
		MOTOR_PORT |= (1 << MOTOR_EN);
	}
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

void motor_direction(motor_dir direction){
	
	//not sure what pin value gives left/right direction
	if(direction == right){
		MOTOR_PORT |= (1 << MOTOR_DIR);
	}
	else if(direction == left){
		MOTOR_PORT &= ~(1 << MOTOR_DIR);		
	}
}



//uint between 0 and 255
void motor_speed(uint16_t speed){ //uint8_t might give overflow with accidental speed >=256
	if(speed > 255){
		max520_send(255);
	}
	else{
		max520_send(speed);
	}
	
}


void motor_test(){
	motor_init();
	
	int16_t speed;
	
	while(1){
		canjoy_recieve();
		speed = 2 * abs(canjoy_joystick_x() - 127);
		
		motor_speed(speed);
		if(canjoy_joystick_x() > 128){
			motor_direction(right);
		}
		else
			motor_direction(left);
			
		pwm_alt_joystick_pulse(canjoy_joystick_x());
		
		
	}

}


void motor_solenoid_test(){
	pwm_init(); //for servo
	solenoid_init();
	motor_init();
	
	
/*
	motor_encoder_output_enable();
	motor_encoder_select_byte(0);*/
	
	int16_t speed;
	uint8_t ir;
	while(1){
		
		canjoy_recieve();
		speed = 2 * abs(canjoy_joystick_x() - 127);
			
		motor_speed(speed);
		
		if(canjoy_joystick_x() > 128){
			motor_direction(right);}
		else{
			motor_direction(left);}
		
		if(canjoy_button_right()){
			solenoid_extend();
		}
		else{
			solenoid_retract();
		}
		
		pwm_alt_joystick_pulse(canjoy_joystick_x());
		
		ir = ir_alt_blocked();
		
		printf("Ir blocked: %d\t\tEncoder: %d\n", ir, motor_encoder_read());
		
		
	}
}

void motor_encoder_reset(){
	MOTOR_PORT &= ~(1 << MOTOR_ENCODER_RESET);
	_delay_us(20);
	MOTOR_PORT |= (1 << MOTOR_ENCODER_RESET);
}


void motor_encoder_init(){
	DDRK = 0x0;
}



uint8_t motor_encoder_byte_read(){
	uint8_t byte = PINK;
	return byte;
	
	
	
	//reverse stuff
}


uint8_t motor_encoder_byte_reversed(){
	uint8_t byte = reverse_bits(PINK);
	
	
}


uint16_t motor_encoder_read(){

	uint8_t msb;
	uint8_t lsb;
	
	
	//enable output
	motor_encoder_output_enable(1);
	
	//read MSB to data
	motor_encoder_select_byte(0);
	_delay_us(20);
	msb = reverse_bits(motor_encoder_byte_read());
	
	//read LSB to data
	motor_encoder_select_byte(1);
	_delay_us(20);
	lsb = reverse_bits(motor_encoder_byte_read());
	
	//motor_encoder_reset();
	
	//disable output
	motor_encoder_output_enable(0);
	
	
	uint16_t data = (msb << 8) + lsb;
	
	return data;

	
}


static uint8_t reverse_bits(uint8_t byte){
	byte = ((byte & 0b01010101) << 1) | ((byte & 0b10101010) >> 1);
	byte = ((byte & 0b00110011) << 2) | ((byte & 0b11001100) >> 2);
	byte = ((byte & 0b00001111) << 4) | ((byte & 0b11110000) >> 4);
	return byte;
}
