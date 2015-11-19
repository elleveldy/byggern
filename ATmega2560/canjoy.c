
#include <stdio.h>
#include "can.h"
#include "canjoy.h"
//#include "joystick.h"




can_message input_msg;


//Not needed in node 2
/*
void input_transmit(){
	can_message joy;
	joy.id = input_ID;
	joy.length = 7;
	
	joy.data[0] = joystick_read_x();
	joy.data[1] = joystick_read_y();
	joy.data[2] = joystick_button_read();
	joy.data[3] = slider_left_read();
	joy.data[4] = slider_right_read();
	joy.data[5] = button_left_read();
	joy.data[6] = button_right_read();
	
	can_transmit(&joy, 0x30);
}
*/


//must be run in while(1)
can_message input_update(){
	
	can_message joy = can_recieve();
	
	if(joy.id == GAME_ID){
		//printf("CORRECT ID\n");		
		input_msg = joy;
		return joy;
	}
	printf("WRONG ID\n");
	
	//return some other message?
	joy.length = 7;
	
	joy.data[0] = 7;
	joy.data[1] = 0;
	joy.data[2] = 0;
	joy.data[3] = 0;
	joy.data[4] = 0;
	joy.data[5] = 0;
	joy.data[6] = 0;
	return joy;
}

int input_joystick_x(){
	return input_msg.data[0];
}
int input_joystick_y(){
	return input_msg.data[1];
}
int input_joystick_button(){
	return input_msg.data[2];
}
int input_slider_left(){
	return input_msg.data[3];
}
int input_slider_right(){
	return input_msg.data[4];
}
int input_button_left(){
	return input_msg.data[5];
}
int input_button_right(){
	return input_msg.data[6];
}

/*
void input_test(){
	can_init(MODE_NORMAL);
	
	
}*/