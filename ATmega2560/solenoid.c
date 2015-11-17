#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>


static uint8_t shoot = 1;

void solenoid_init(){
	DDRH |= (1<<PH3);
	PORTH |= (1<<PH3);
}

void solenoid_shoot(){
	PORTH &= ~(1<<PH3);
	_delay_ms(150);
	PORTH |= (1<<PH3);
}

void solenoid_extend(){
	PORTH &= ~(1<<PH3);
}

void solenoid_retract(){
	PORTH |= (1<<PH3);	
}

void solenoid_disallow_shooting(){
	shoot = 0;
}
void solenoid_allow_shooting(){
	shoot = 1;
}
uint8_t solenoid_is_shooting_allowed(){
	return shoot;
}

