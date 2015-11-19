#pragma once
#include <stdint.h>

int joystick_initial_x_value;
int joystick_initial_y_value;


void JOY_initialize();
void JOY_calibrate();
//bool JOY_button(int button);
//JOY_position_t YOU_getPosition();
//JOY_direction_t JOY_getDirection();


//0 to 255
uint8_t joystick_read_x(); 
uint8_t joystick_read_y();	


// -127 to + 127
int8_t joystick_y_value();
int8_t joystick_x_value();


uint8_t joystick_button_read();
uint8_t joystick_is_moved();


//0 to 255
uint8_t slider_left_read();
uint8_t slider_right_read();

// -127 to + 127
int8_t slider_left_value();
int8_t slider_right_value();

void buttons_init();
uint8_t button_left_read();
uint8_t button_right_read();

void joystick_print_input();

