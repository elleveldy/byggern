#include <avr/io.h>

void pwm_init();
void pwm_set_value(uint16_t val);
void pwm_set_pulse(int16_t val);
void pwm_joystick_pulse(int16_t val);


void pwm_set_servo(int16_t val);