#pragma once



typedef struct PI_controller PI_controller;

PI_controller* PI_controller_new(float kp, float ki);

int16_t PI_controller_set_output(PI_controller* ctrl, uint16_t position, uint16_t reference);

void P_controller_init(float kp_in);
//sets motor speed and direction based on position, and reference
//both are between 0 and 9100, or we could translate reference from joystick domain to encoder
void P_controller_actuate(uint16_t position, uint16_t reference);
void P_controller_actuate_slider(uint16_t position, uint8_t reference);