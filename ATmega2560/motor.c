


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






static uint16_t max_right = 0;
static uint16_t position_offset = 0;




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

//negative speed to the right to make transition to encoder values easier
void motor_speed_direction(int16_t speed){
	if(speed < 0){
		motor_direction(right);
	}
	else{
		motor_direction(left);
	}
	
	motor_speed(abs(speed));
}

void motor_speed_direction_cap(int16_t speed, uint8_t cap){
	if(speed < 0){
		motor_direction(right);
	}
	else{
		motor_direction(left);
	}
	if(abs(speed) > cap){
		motor_speed(abs(cap));
	}
	
}


uint8_t motor_speed_controller(uint8_t speed){
	
	uint8_t tilt = abs(input_joystick_x() - 127);
	
	if((tilt < 70) && tilt > 30){
		motor_speed(90);
	}
	else if(tilt >= 70){
		motor_speed(130);
	}
	else{
		motor_speed(0);
	}
	
	if(input_joystick_x() > 127){
		motor_speed(right);
	}
	else{
		motor_speed(left);
	}
	
}

//0 is to the right, and position increases leftward
void motor_crude_controller(uint16_t current_position, uint16_t reference){
	
	
	//if requested position is out of reach
	if(reference > max_left){
		motor_crude_controller(max_left, reference);
	}
	
	//if we're close to ref
	if(abs(current_position - reference) < 300){
		motor_speed(0);
		return;
	}
	
	//too far left
	if(current_position > reference){
		motor_direction(right);
		motor_speed(100);
	}
	//too far right
	else{
		motor_direction(left);
		motor_speed(100);
	}
}

//converts slider: 0-255 to 9100 - 0
void motor_crude_controller_slider(uint16_t current_position, uint8_t reference){
		
	uint16_t  pos_multiplier = max_left / 255.0;
	
	uint16_t ref = reference * pos_multiplier;
	printf("Slider: %d\tRef: %d", reference, ref);
	
	motor_crude_controller(current_position, abs(reference - 255) * pos_multiplier);
	
	
}


//MOTOR SPEED NEEDS TO BE TUNED FOR INDIVIDUAL GAME BOARD
void motor_controller_calibrate_by_reset(){
	
	uint8_t speed = 65;
	
	motor_init();
	
	uint16_t position;
	uint16_t prev_position;
	
	motor_speed(speed);
	motor_direction(right);
	_delay_ms(150);
	
	position =  motor_encoder_read();
	
	//go right until stopped, then set encoder to zero
	while(position != prev_position){
		
		
		position =  motor_encoder_read();
		_delay_ms(100);
		prev_position = position;
		position = motor_encoder_read();
		printf("position: %u\tPrev: %u\n", position, prev_position);

		
	}
	motor_encoder_reset();
	
	motor_speed(speed);
	motor_direction(left);
	_delay_ms(150);
	
	//go left until stopped, set max left to current position
	do{
		
		
		position =  motor_encoder_read();
		_delay_ms(100);
		prev_position = position;
		position = motor_encoder_read();
		printf("position: %d\n", position);
		
		
	} while(position != prev_position);
	
	max_left = position;
	motor_speed(0);
	
	motor_speed(speed);
	motor_direction(right);
	_delay_ms(100);
	while(motor_encoder_read() > 4500){
		_delay_ms(100);
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
	
	//disable output
	motor_encoder_output_enable(0);
	
	
	uint16_t data = (msb << 8) + lsb;
	
	return data;

	
}


uint8_t reverse_bits(uint8_t byte){
	byte = ((byte & 0b01010101) << 1) | ((byte & 0b10101010) >> 1);
	byte = ((byte & 0b00110011) << 2) | ((byte & 0b11001100) >> 2);
	byte = ((byte & 0b00001111) << 4) | ((byte & 0b11110000) >> 4);
	return byte;
}
