#include "timer.h"
#include "solenoid.h"
#include "pwm.h"
#include "PI_controller.h"
#include "motor.h"
#include "canjoy.h"
#include "ir.h"

#include <stdlib.h>

//change these to tune the controller behaviour
#define K_p 0.02
#define K_i 0.05

static unsigned int score = 0;




//behaviour of IR is uncertain, as to what voltage/adc digital value range it operates in




void game_single_player(){
	
	
	ir_init();
	servo_init();
	motor_init();
	
	uint16_t ref_position;
	uint16_t output;
	
	PI_controller* controller = PI_controller_new(K_p, K_i);
	motor_controller_calibrate_by_reset();
	
	
	
	while(1){
		//updates input from joystick/slider/buttons
		input_update();
		
		
		//leave game
		if(input_button_left()){
			return;
		}

		
		//one clock cycle (4.1ms ish), number is arbitrary
		if(timer_read(5) == 123){
			score ++;
		}
		
		ref_position = abs(input_joystick_x() - 255) * (float)(max_left) / 255.0;
		
		//apparently needs minus?
		output = -PI_controller_output(controller, motor_encoder_read(), ref_position);
		
		motor_speed_direction(output);
		
		//solenoid shooting with 50 ms pulse, button needs to be
		//released to allow shooting again
		if(input_button_right() && solenoid_is_shooting_allowed()){
			solenoid_shoot();
			solenoid_disallow_shooting();
		}
		else if(input_button_right()){}
		else{
			solenoid_allow_shooting();
		}
		
		servo_set_pulse_by_input(input_slider_left());
		
	}
}
