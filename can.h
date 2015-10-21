#ifndef CAN_H_
#define CAN_H_
#include <stdint.h>


typedef struct can_message can_message;
struct can_message{
	uint16_t id; //16bit 
	uint8_t length; //4bit
	uint8_t data[8]; //8*8bit
};





#endif /* CAN_H_ */