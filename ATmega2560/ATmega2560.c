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
#include "game.h"
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
	/*adc_init();*/
	ir_init();
	
	
	DDRE |= (1 << 3); //studass PWM bandaid that can be removed? 



	timer_init();
	
	solenoid_init();
	motor_init();
	pwm_init(SERVO_PERIOD, P_MID);
	

	PI_controller* sliders = PI_controller_new(0.02, 0.05);
	
	uint16_t position;
	uint16_t reference;
	float output;
	
	motor_controller_calibrate_by_reset();

	
	can_message game_status;
	while(1){
		
		/*switch(message_node1.id){
			case(GAME_ID):*/
				input_update();
				
				//printf("stuff: %u\n", input_joystick_x());
				
				//inverts and multiplies 8 bit input to board game domain
				reference = abs(input_joystick_x() - 255) * (float)(max_left) / 255.0;
				
				position = motor_encoder_read();
				output =  PI_controller_output(sliders, position, reference);
				motor_speed_direction(output);
				
				printf("Output: %d\n", abs(output));
				
				//clockblock spinning at either wall
				if((position > max_left) && (reference < 127)){
					output = 0;
				}//if negative overflow
				else if(position > 60000){
					motor_encoder_reset();
				}
				
				//allows shooting solonoid, with 50ms pulse, without "burst mode"
				if(input_button_right() && solenoid_is_shooting_allowed()){
					solenoid_shoot();
					solenoid_disallow_shooting();
				}
				else if(input_button_right()){}
				else{
					solenoid_allow_shooting();
				}
				
				//controll servo
				servo_set_pulse_by_input(input_slider_right());
				

				
				printf("score: %u\n",game_score);
				
				//use timer for this, to avoid spamming?
				if(timer5_read() > 100){//somewhat arbitrary time
					game_score++;
					game_status.id = CAN_GAME_STATE_RUNNING;
					game_status.data[0] = 0; // game over

					if(ir_alt_blocked()){
						game_status.id = CAN_GAME_STATE_OVER;

					}
					else{
						game_status.id = CAN_GAME_STATE_RUNNING; // game over

					}
					can_transmit(&game_status, 0x30);
					timer5_reset();
				}
				

				/*else{
					game_status.id = CAN_GAME_STATE;
					game_status.length = 2;
					game_status.data[0] = 1; // game running
					game_status.data[1] = game_score;
					can_transmit(&game_status, 0x30);
					
				}*/
				
				
				
				
				//printf("input: %u\n", input_slider_right());
				
				//printf("Pos: %u\tRef: %u\toutput: %f\n", position, reference, output);
				
			/*case(CAN_TEST_LOOPBACK):
				can_test_loopback();
			case(CAN_TEST_TRANSMIT):
				can_test_transmit();
			case(CAN_TEST_RECIEVE):
				can_test_recieve();
		}

		*/
			
		//message_node1 = can_recieve();
		
	}
	
	
	
	
}