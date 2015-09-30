#pragma once


void JOY_init();
void JOY_calibrate();
//bool JOY_button(int button);
//JOY_position_t YOU_getPosition();
//JOY_direction_t JOY_getDirection();

unsigned int joystick_read_x();
unsigned int joystick_read_y();
signed int joystick_y_value();
signed int joystick_x_value();
int joystick_button_read();



int slider_left_read();
int slider_right_read();
signed int slider_left_value();
signed int slider_right_value();

void buttons_init();
int button_left_read();
int button_right_read();


void joystick_print_input();
