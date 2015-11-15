#pragma once

#include <stdio.h>



#define MOTOR_PORT PORTF
#define MOTOR_DDR DDRF

#define MOTOR_DIR 3
#define MOTOR_EN 4
#define MOTOR_SEL 5
#define MOTOR_ENCODER_RESET 6
#define MOTOR_OUTPUT_EN 7

uint16_t max_left;

typedef enum motor_dir motor_dir;
enum motor_dir {right,left};

void motor_init();

void motor_encoder_reset();
void motor_encoder_select_byte(uint8_t val);
void motor_encoder_output_enable(uint8_t enable);
static uint8_t reverse_bits(uint8_t byte);//remove static fn from .h file?



void motor_encoder_init();


uint8_t motor_encoder_byte_read();
uint16_t motor_encoder_read();



void motor_direction(motor_dir direction);

//uint8_t might give overflow with accidental speed >= 256
void motor_speed(uint16_t speed);

//negative speed to the right to make transition to encoder values easier
void motor_speed_direction(int16_t speed);
void motor_speed_direction_cap(int16_t speed, uint8_t cap);

void motor_test();
void motor_solenoid_test();
void motor_controller_calibrate_by_reset();
void motor_controller_calibrate_by_offset();



//0 is to the right, and position increases leftward
void motor_crude_controller(uint16_t current_position, uint16_t reference);
//converts slider: 0-255 to 9100 - 0
void motor_crude_controller_slider(uint16_t current_position, uint8_t reference);


/*
#define ENCODER_PORT PORTK
#define ENCODER_EN 
*/
