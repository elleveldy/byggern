#pragma once

#include <stdio.h>



void servo_init();
void servo_set_pulse(int16_t pulse_width);
void servo_set_pulse_by_input(int16_t val);