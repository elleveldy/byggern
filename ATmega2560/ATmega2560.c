/*
 * ATmega2560.c
 *
 * Created: 23.10.2015 16:33:03
 *  Author: erlendvd
 */ 


#include <avr/io.h>
#define F_CPU 16000000
#include <util/delay.h>
#include <stdlib.h>
#include "can.h"
#include "mcp2515_define.h"
#include "uart.h"
#include "canjoy.h"
#include "pwm.h"
#include "adc.h"
#include "ir.h"
#include "timer.h"
#include "solenoid.h"
#include "motor.h"
#include "PI_controller.h"
#include "servo.h"
/*
check if header files are included in their respective c files, and if they should be
to avoid "implicit declaration of function

check if all neccessary _init() functions are called

Add calibration to joystick on NODE1

avoid using int, use uint8_t / uint16_t when possible

make functions static, if they shouldn't be called outside the .c file

*/



int main(void){
	

	MCUCR |= (1 << SRE);
	uart_Init(MYUBRR);
	//
	
	can_init(MODE_NORMAL);
	adc_init();
	
	DDRE |= (1 << 3); //studass PWM bandaid that can be removed? 



	timer_init();
	
	solenoid_init();
	motor_init();
	

	PI_controller* sliders = PI_controller_new(0.02, 0.05);
	
	uint16_t y;
	uint16_t x;
	float output;
	
	motor_controller_calibrate_by_reset();

	
	while(1){


		
		canjoy_update();
		
		x = abs(canjoy_joystick_x() - 255) * (float)(max_left) / 255.0;		
		y = motor_encoder_read();
		
		
		
		output = -PI_controller_output(sliders, x, y);
		
		if(y > max_left | y < 0){
			output = 0;
		}
		if(y > 65000){
			motor_encoder_reset();
		}
		
		
		//allows shooting solonoid, with 50ms pulse, without "burst mode"
		if(canjoy_button_right() && solenoid_is_shooting_allowed()){
			solenoid_shoot();
			solenoid_disallow_shooting();
		}
		else if(canjoy_button_right()){}
		else{
			solenoid_allow_shooting();			
		}
		
		servo_set_pulse_by_input(canjoy_slider_right());
		
		//motor_speed_direction_cap(output, 150);
		motor_speed_direction(output);

		
		
		//printf("Pos: %u\tRef: %u\toutput: %f\n", y, x, output);
		
		
	}
	
	
	
	
}