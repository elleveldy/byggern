#pragma once

#include "can.h"

#define GAME_ID 7


int canjoy_transmit();
can_message canjoy_update();

int canjoy_joystick_x();
int canjoy_joystick_y();
int canjoy_joystick_button();
int canjoy_slider_left();
int canjoy_slider_right();
int canjoy_button_left();
int canjoy_button_right();


