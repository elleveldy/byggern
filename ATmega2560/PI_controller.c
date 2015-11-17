
#include "motor.h"
#include "PI_controller.h"
#include "timer.h"

#include <avr/io.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <util/delay.h>



static float kp;


//static float integral;

static uint16_t max_left_position;
static uint16_t position_multiplier;

float fcpu = 16000000.0;
float prescaler = 1024.0;

struct PI_controller {
	//float reference;
	
	float Kp;
	float Ki;
	
	//prev_time lets us run without timer reset, so that 
	//we can use the same timer for multiple controllers
	uint16_t prev_time;
	

	
	float error;
	float integral;
};


PI_controller* PI_controller_new(float kp, float ki){
	PI_controller* this = malloc(sizeof(PI_controller));
	
	//initialized variables of controller type to 0
	memset(this, 0, sizeof(PI_controller));
	
	this->Ki = ki;
	this->Kp = kp;
	
	return this;
}

int16_t PI_controller_output(PI_controller* ctrl, uint16_t position, uint16_t reference){
	//copy pasta ish
	float dt = (float)(timer_read(4) * prescaler / fcpu);	
	timer_reset();
	
	int16_t error			= reference - position;
	ctrl->integral		+= error * dt;
	
	return		ctrl->Kp * error +
				ctrl->Ki * ctrl->integral;
				
	/*
	uint16_t time = timer_read();
	float dt;
	
	
	//Set dt
	if(ctrl->prev_time > time){
		dt = (time - ctrl->prev_time + MAX_TIME) * PRESCALER / F_CPU; 
	}
	else{
		dt = (time - ctrl->prev_time) * PRESCALER / F_CPU;
	}
	ctrl->prev_time = time;
	
	//calculate error
	ctrl->error = reference - position; 
	
	//add to integral
	ctrl->integral += ctrl->error * dt;
	
	float output = ctrl->Kp * ctrl->error + ctrl->integral * ctrl->Ki;
	
	//printf("dt: %f\terror: %f\toutput: %f\n", dt, ctrl->error, output);
	
	return output;
	*/
	
}


//must be called after motor calibration to set max_left, and multiplier
void P_controller_init(float kp_in){
	kp = kp_in;
	max_left_position = max_left;
	position_multiplier = max_left_position / 255.0;
}


//sets motor speed and direction based on position, and reference
//both are between 0 and 9100, or we could translate reference from joystick domain to encoder
void P_controller_actuate(uint16_t position, uint16_t reference){
	
	
	int16_t error = reference - position;
	int16_t speed = error * kp;
	
	if(speed > 150){
		speed = 150;
	}
	else if(speed < -150){
		speed = -150;
	}
	
	
	printf("Position: %d\tRef: %d\tSpeed: %d\tError: %d\tDirection: \n",position, reference, speed, error);
	
	
	motor_speed_direction(speed);

}

void P_controller_actuate_slider(uint16_t position, uint8_t reference){
	//just incase we call it outside it's supposed range
	if(reference > 255){
		P_controller_actuate_slider(position, 255);
	}
	
	P_controller_actuate(position, abs(reference - 255) * position_multiplier);
	printf("Slider: %d\t", reference);
}

