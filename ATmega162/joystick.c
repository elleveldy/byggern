//use uint more


//#include "Stdint.h"

#define F_CPU 4915200
#include <util/delay.h>
#include <avr/io.h>
#include <stdlib.h> //for abs()



uint8_t joystick_read_x(){
	
	volatile char *ext_joy = (char *) 0x1400;
	ext_joy[0] = 0x04;
	_delay_us(40);
	return (uint8_t)ext_joy[0];
	
}


uint8_t joystick_read_y(){
	
	volatile char *ext_joy = (char *) 0x1400;
	ext_joy[0] = 0x05;
	_delay_us(40);
	return (uint8_t)ext_joy[0];
	
}

int8_t joystick_x_value(){
	return (joystick_read_x() - 127);
}

int8_t joystick_y_value(){
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

int8_t slider_left_value(){
	return (slider_left_read() - 127);
}

int8_t slider_right_value(){
	return (slider_right_read() - 127);	
}

void buttons_init(){
	DDRB &= ~(1 << DDB1);	// ????
	
	//left & right
	DDRB &= (1<< PINB0); //right
	DDRB &= (1<< PINB1); //left

	//joystick button activate
	DDRB &= (1 << PINB2);
	PORTB |= (1 << PINB2);
}

uint8_t joystick_button_read(){
	int button = (PINB & (1 << PINB3));
	if (button > 0){
		return 0;
	}
	else{
		return 1;
	}
	
	
}

uint8_t button_left_read(){
	int button = (PINB & (1 << PINB1));
	if (button > 0){
		return 1;
	}
	else{
		return 0;
	}
}

uint8_t button_right_read(){
	int button = (PINB & (1 << PINB0));
	if (button > 0){
		return 1;
	}
	else{
		return 0;
	}
	
}


uint8_t joystick_is_moved(){
	int threshold = 10;
	
	if(abs(joystick_read_x()) > threshold)
		return 1;
	else if(abs(joystick_read_y()) > threshold)
		return 1;
	else if(joystick_button_read())
		return 1;
	else
		return 0;
}

void joystick_print_input(){

	printf("\n\nX:\t%d\tLeft Slide:\t%d\tLeft Button:\t%d\tJoyButton:\t%d\nY:\t%d\tRight Slide:\t%d\tRight Button:\t%d"
	, joystick_x_value(), slider_left_value(), button_left_read(), joystick_button_read(),joystick_y_value(),  slider_right_value(), button_right_read());
	
}

void laurits_print(){
	

	printf("X:%4i Left Slide:%4i Left Button:%2i JoyButton:%2i Y:%4i Right Slide:%2i Right Button: %2i \r"
	, joystick_x_value(), slider_left_value(), button_left_read(), joystick_button_read(),joystick_y_value(),  slider_right_value(), button_right_read());
		

}