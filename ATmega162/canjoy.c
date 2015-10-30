#include "can.h"
#include "joystick.h"
#include "canjoy.h"
#include "mcp2515_define.h"

void canjoy_transmit()
{
	can_message joy;
	joy.id = CANJOY_ID;
	joy.length = 7;
	printf("ID set to 7");
	
	joy.data[0] = joystick_read_x();
	joy.data[1] = joystick_read_y();
	joy.data[2] = joystick_button_read();
	joy.data[3] = slider_left_read();
	joy.data[4] = slider_right_read();
	joy.data[5] = button_left_read();
	joy.data[6] = button_right_read();
	
	can_transmit(&joy, MCP_TXB0CTRL);
	
}

can_message canjoy_recieve(){
	
	can_message joy = can_recieve();
	
	if(joy.id == CANJOY_ID){
		printf("Correct ID\n");
		canjoy_msg = joy;
		return joy;
	}
	
	//return some other message?
	joy.length = 7;
	
	joy.data[0] = 0;
	joy.data[1] = 0;
	joy.data[2] = 0;
	joy.data[3] = 0;
	joy.data[4] = 0;
	joy.data[5] = 0;
	joy.data[6] = 0;
	return joy;
}

int canjoy_joystick_x(){
	return canjoy_msg.data[0];
}
int canjoy_joystick_y(){
	return canjoy_msg.data[1];
}
int canjoy_joystick_button(){
	return canjoy_msg.data[2];
}
int canjoy_slider_left(){
	return canjoy_msg.data[3];
}
int canjoy_slider_right(){
	return canjoy_msg.data[4];
}
int canjoy_button_left(){
	return canjoy_msg.data[5];
}
int canjoy_button_right(){
	return canjoy_msg.data[6];
}










