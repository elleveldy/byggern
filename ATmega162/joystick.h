#pragma once


int joystick_initial_x_value;
int joystick_initial_y_value;


void JOY_initialize();
void JOY_calibrate();
//bool JOY_button(int button);
//JOY_position_t YOU_getPosition();
//JOY_direction_t JOY_getDirection();

unsigned int joystick_read_x(); //unsinged, wtf?
unsigned int joystick_read_y();	//unsinged, wtf?
signed int joystick_y_value();
signed int joystick_x_value();
int joystick_button_read();
int joystick_is_moved();



int slider_left_read();
int slider_right_read();
signed int slider_left_value();
signed int slider_right_value();

void buttons_init();
int button_left_read();
int button_right_read();

void joystick_print_input();

