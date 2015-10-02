
//#include "Stdint.h"

#define F_CPU 4915200
#include <util/delay.h>
#include <avr/io.h>




void joystick_initialize(){
	volatile char *ext_joy = (char *) 0x1400;
	ext_joy[0] = 0x04;
	_delay_us(40);
	joystick_initial_x_value = (uint8_t)ext_joy[0];
}

unsigned int joystick_read_x(){
	
	volatile char *ext_joy = (char *) 0x1400;
	ext_joy[0] = 0x04;
	_delay_us(40);
	return (uint8_t)ext_joy[0];
	
}


unsigned int joystick_read_y(){
	
	volatile char *ext_joy = (char *) 0x1400;
	ext_joy[0] = 0x05;
	_delay_us(40);
	return (uint8_t)ext_joy[0];
	
}

int joystick_x_value(){
	return (joystick_read_x() - 127);
}

int joystick_y_value(){
	return (joystick_read_y() - 127);
}



uint8_t slider_left_read(){
	volatile char *ext_slide = (char *) 0x1400;
	ext_slide[0] = 0x06;
	_delay_us(40);
	return (uint8_t)ext_slide[0];
}

uint8_t slider_right_read(){
	volatile char *ext_slide = (char *) 0x1400;
	ext_slide[0] = 0x07;
	_delay_us(40);
	return (uint8_t)ext_slide[0];
}

signed int slider_left_value(){
	return (slider_left_read() - 127);
}

signed int slider_right_value(){
	return (slider_right_read() - 127);	
}

void buttons_init(){
	DDRB &= ~(1 << DDB1);
	
	//joystick button activate
	DDRB &= (1 << PINB6);
	PORTB |= (1 << PINB6);
}

int joystick_button_read(){
	int button = (PINB & (1 << PINB6));
	if (button > 0){
		return 0;
	}
	else{
		return 1;
	}
	
	
}

int button_left_read(){
	int button = (PINB & (1 << PINB2));
	if (button > 0){
		return 1;
	}
	else{
		return 0;
	}
}

int button_right_read(){
	int button = (PINB & (1 << PINB1));
	if (button > 0){
		return 1;
	}
	else{
		return 0;
	}
	
}



void joystick_print_input(){

	printf("\n\nX:\t%d\tLeft Slide:\t%d\tLeft Button:\t%d\tJoyButton:\t%d\nY:\t%d\tRight Slide:\t%d\tRight Button:\t%d"
	, joystick_x_value(), slider_left_value(), button_left_read(), joystick_button_read(),joystick_y_value(),  slider_right_value(), button_right_read());
	
}

void laurits_print(){
	

	printf("X:%4i Left Slide:%4i Left Button:%2i JoyButton:%2i Y:%4i Right Slide:%2i Right Button: %2i \r"
	, joystick_x_value(), slider_left_value(), button_left_read(), joystick_button_read(),joystick_y_value(),  slider_right_value(), button_right_read());
		

}