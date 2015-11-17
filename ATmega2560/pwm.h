#pragma once

#include <avr/io.h>

void pwm_init(uint16_t period_length, uint16_t initial_pulse_width);
void pwm_set_pulse_width(uint16_t val);

