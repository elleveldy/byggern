#pragma once

#include <avr/io.h>


#define P_MAX 525
#define P_MIN 225
#define P_MID (P_MAX + P_MIN)/2 //( = 375)
#define P_RESOLUTION P_MAX - P_MIN // = 300
#define SERVO_PERIOD 5000

void pwm_init(uint16_t period_length, uint16_t initial_pulse_width);
void pwm_set_pulse_width(uint16_t val);

