#ifndef CANJOY_H_
#define CANJOY_H_
#include "can.h"

uint16_t CANJOY_ID;

can_message canjoy_msg;
void canjoy_transmit();
can_message canjoy_recieve();

int canjoy_joystick_x();
int canjoy_joystick_y();
int canjoy_joystick_button();
int canjoy_slider_left();
int canjoy_slider_right();
int canjoy_button_left();
int canjoy_button_right();


#endif /* CANJOY_H_ */