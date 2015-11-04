#include "can.h"
#include "mcp2515.h"
#include "mcp2515_define.h"
#include <avr/io.h>
#include <stdlib.h>
#include <string.h>
#include <util/delay.h>



void can_init(int mode){

	mcp2515_init();
	mcp2515_bit_modify(MCP_RXB0CTRL, MCP_MASK_FILTER, 0xff);
	mcp2515_bit_modify(MCP_RXB1CTRL, MCP_MASK_FILTER, 0xff);
	mcp2515_bit_modify(MCP_CANCTRL, MODE_MASK, mode);
	DDRE &= ~(1 << PE0);
}

void can_transmit(can_message* msg, int buffer_select){
	
	mcp2515_bit_modify(buffer_select, 0x08, 0xff);
	
	while(mcp2515_read(buffer_select) & (1 << MCP_TXREQ));
	
	volatile uint8_t idl = MCP2515_MASK_IDL & (msg->id << 5);
	volatile uint8_t idh = MCP2515_MASK_IDH & (msg->id >> 3);
	
	mcp2515_write(buffer_select + MCP2515_IDL_OFFSET, idl); //3 LSB
	mcp2515_write(buffer_select + MCP2515_IDH_OFFSET, idh); //8 MSB
	
	mcp2515_write(buffer_select + MCP2515_DLC_OFFSET, MCP2515_MASK_DLC & (msg->length));
	
	
	for(int i = 0; i < msg->length; i++){
		mcp2515_write(buffer_select + MCP2515_TXB_OFFSET + i, msg->data[i]);
		
	}
	
	int buffer_control;
	
	if (buffer_select == MCP_TXB0CTRL){
		buffer_control = MCP_RTS_TX0;
	}
	else if (buffer_select == MCP_TXB1CTRL){
		buffer_control = MCP_RTS_TX1;
	}
	else if (buffer_select == MCP_TXB2CTRL){
		buffer_control=MCP_RTS_TX2;
	}
	else{
		return; 
	}
	
	//printf("Buffer =\n\tID = %02x\n\tDLC = %02x\n\tD0 = %02x\n", mcp2515_read(buffer_select + MCP2515_IDH_OFFSET) | (mcp2515_read(buffer_select + MCP2515_IDL_OFFSET) >> 5), mcp2515_read(buffer_select + MCP2515_DLC_OFFSET),  mcp2515_read((buffer_select + MCP2515_TXB_OFFSET)));
	
	mcp2515_request_to_send(buffer_control);
}

can_message can_recieve(can_message* msg){
	can_message m;
	
	uint8_t buffer_select = can_poll_interrupt();
	
	m.id = mcp2515_read(buffer_select + MCP2515_IDH_OFFSET) << 3 | (mcp2515_read(buffer_select + MCP2515_IDL_OFFSET) >> 5);
	m.length = mcp2515_read(buffer_select + MCP2515_DLC_OFFSET) & MCP2515_MASK_DLC;
	
	for(uint8_t i = 0; i < m.length; i++){
		m.data[i] = mcp2515_read(buffer_select + MCP2515_RXB_OFFSET + i);// + i, msg->data[i]);
	}
	
	//printf("Buffer =\n\tID = %02x\n\tDLC = %02x\n\tD0 = %02x\n", mcp2515_read(buffer_select + MCP2515_IDH_OFFSET) << 3 | (mcp2515_read(buffer_select + MCP2515_IDL_OFFSET) >> 5), mcp2515_read(buffer_select + MCP2515_DLC_OFFSET),  mcp2515_read((buffer_select + MCP2515_TXB_OFFSET)));
	
	
	switch(buffer_select){
		case MCP_RXB0CTRL:
			mcp2515_bit_modify(MCP_CANINTF, MCP_RX0IF, 0x00);
		break;
		case MCP_RXB1CTRL:
			mcp2515_bit_modify(MCP_CANINTF, MCP_RX1IF, 0x00);
		break;
	}
	
	return m;
}


uint8_t can_poll_interrupt(){
	
	while(!(PINE & (1 << PE0))){}
	
	if(mcp2515_read(MCP_CANINTF) & MCP_RX0IF){
		//mcp2515_bit_modify(MCP_CANINTF, MCP_RX0IF, 0x00);
		return MCP_RXB0CTRL;
	}
	
	else if(mcp2515_read(MCP_CANINTF) & MCP_RX1IF){
		//mcp2515_bit_modify(MCP_CANINTF, MCP_RX1IF, 0x00);
		return MCP_RXB1CTRL;
	}
	return -1;
}

void can_test_loopback(){
	can_init(MODE_LOOPBACK);
	
	can_message msg;
	msg.id = 10;
	msg.length = 1;
	msg.data[0] = 'T';
	
	can_transmit(&msg, MCP_TXB0CTRL);
	
	can_message recieved;
	can_message done = can_recieve(&recieved);
	
	printf("\n\nSend ID = 10\tRecieved ID = %d\nSend Length = 1\tRecieved Length = %d\nSend Data = 'T'\tRecieved Data = %c\n\n", done.id, done.length, done.data[0]);
	
	
}

void can_test_transmit(){
	can_init(MODE_NORMAL);
	
	while(1){
	_delay_ms(100);
		
	can_message msg;
	msg.id = 10;
	msg.length = 1;
	msg.data[0] = 'T';
	
	can_transmit(&msg, MCP_TXB0CTRL);
	printf("\n\nSend ID = %d\nSend Length = %d\nSend Data = %c\n\n", msg.id, msg.length, msg.data[0]);
	}
}

void can_test_recieve(){
	can_init(MODE_NORMAL);
	
	while(1){
		_delay_ms(200);
	
		can_message recieved;
		can_message done = can_recieve(&recieved);
	
		printf("\n\nSend ID = %d\nSend Length = %d\nSend Data = %c\n\n", done.id, done.length, done.data[0]);
	}
}



