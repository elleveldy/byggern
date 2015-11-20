#pragma once

#include "can.h"
#include <stdint.h>
#define GAME_ID 7

can_message canjoy_msg;

void canjoy_transmit();
can_message canjoy_recieve();

uint8_t canjoy_joystick_x();
uint8_t canjoy_joystick_y();
uint8_t canjoy_joystick_button();
uint8_t canjoy_slider_left();
uint8_t canjoy_slider_right();
uint8_t canjoy_button_left();
uint8_t canjoy_button_right();
