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

/*
check if header files are included in their respective c files, and if they should be
to avoid "implicit declaration of function

check if all neccessary _init() functions are called

Add calibration to joystick on NODE1

avoid using int, use uint8_t / uint16_t when possible

make functions static, if they shouldn't be called outside the .c file

*/



int main(void){
	
	/*DDRB = 0xff;
	while(1){
		PORTB = 0xff;
		_delay_ms(500);
		PORTB = 0;
		_delay_ms(500);
	}*/
	
	
	MCUCR |= (1 << SRE);
	uart_Init(MYUBRR);
	//
	
	
	can_init(MODE_NORMAL);
	pwm_init();//servo
	adc_init();
	
	DDRE |= (1 << 3); //studass PWM bandaid that can be removed? 


	
	/*
	int high = adc_read(0x00);
	int low = adc_read(0x00);
	*/

	timer_init();
	
	solenoid_init();
	motor_init();
	
	int16_t speed;
	
	
	motor_controller_calibrate_by_reset();
	
	
	while(1){
		
		motor_solenoid_test();
		
		canjoy_recieve();
		
		//motor_crude_controller_slider(motor_encoder_read(), canjoy_slider_right());
		//motor_crude_controller(motor_encoder_read(), 4500);
/*
		canjoy_recieve();
		speed = 2 * abs(canjoy_joystick_x() - 127);
		
		motor_speed(speed);
		if(canjoy_joystick_x() > 128){
			motor_direction(right);
		}
		else
			motor_direction(left);
		
		printf("x: %d\tspeed: %d\n",canjoy_joystick_x(), speed);*/
		
		//can_test_recieve();
		
		/*printf("Node2 entering main while(1)\n");
		canjoy_recieve();
		pwm_joystick_pulse(canjoy_joystick_x());
		
		//motor_test();

		
		
		//can_test_recieve();
		
		printf("x: %d\n",canjoy_joystick_x());
		
		if(canjoy_button_right()){
			PORTH &= ~(1 << PH3);
			_delay_ms(50);
			printf("shoot\n");
		}
		else{
			PORTH |= (1 << PH3);
		}*/
	
		/*int adc = adc_read(PF1);
		
		if(adc > high)
			high = adc;
		if(adc < low)
			low = adc;
		printf("\nIR VALUE: %d\tHighest: %d\tLowest: %d\tUnblocked: %d\talt_blocked: %d\n", adc, high, low, ir_unblocked(), ir_alt_unblocked());*/
		
	}
	
	
	
	
}