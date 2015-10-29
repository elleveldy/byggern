#ifndef CAN_H_
#define CAN_H_
#include <stdint.h>


typedef struct can_message can_message;
struct can_message{
	uint16_t id; //16bit 
	uint8_t length; //4bit
	uint8_t data[8]; //8*8bit
};

void can_init(int mode);
void can_transmit(can_message* msg, int buffer_select);
can_message can_recieve();
uint8_t can_poll_interrupt();






#endif /* CAN_H_ */