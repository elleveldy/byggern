#pragma once

#include "can.h"

#define GAME_ID 7


int input_transmit();
can_message input_update();

int input_joystick_x();
int input_joystick_y();
int input_joystick_button();
int input_slider_left();
int input_slider_right();
int input_button_left();
int input_button_right();


