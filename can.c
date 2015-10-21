#include "can.h"
#include "mcp2515.h"
#include "mcp2515_define.h"
#include <stdlib.h>
#include <string.h>


void can_init(int mode){

	mcp2515_init();
	mcp2515_bit_modify(MCP_RXB0CTRL, MCP_FILTER_MASK, 0xff);
	mcp2515_bit_modify(MCP_RXB1CTRL, MCP_FILTER_MASK, 0xff);
	mcp2515_bit_modify(MCP_CANCTRL, MODE_MASK, operationMode);
	DORD &= ~(1 << PD2);
}

void can_transmit(can_message* msg, int buffer_select){
	
	mcp2515_bit_modify(buffer_select, 0x08, 0xff);
	
	mcp2515_bit_modify(buffer_select + mcp2515_IDH_OFFSET, 0xff, msg->id >> 3); //3 LSB
	mcp2515_bit_modify(buffer_select + mcp2515_IDL_OFFSET, 0xff, msg->id << 5); //8 MSB
	
	
	mcp2515_bit_modify(buffer_select + mcp2515_DLC_OFFSET, 0x0f, msg->length);
	
	while(mcp2515_read(buffer_select) & (1 << MCP_TXREQ))
	
	for(int i = 0; i < msg->length; i++){
		mcp2515_bit_modify(buffer_select + mcp2515_IDH_OFFSET + i, 0xff, msg->data[i]);
		
	}
	
	if (bufferSelect==MCP_TXB0CTRL){
		buffer_control=MCP_RTS_TX0;
	}
	else if (bufferSelect==MCP_TXB1CTRL){
		buffer_control=MCP_RTS_TX1;
	}
	else if (bufferSelect==MCP_TXB2CTRL){
		buffer_control=MCP_RTS_TX2;
	}
	else{
		return; 
	}
	
	mcp2515_request_to_send(buffer_control);
}

can_message can_recieve(){
	can_message m;
	
	uint8_t buffer_select = can_poll_interrupt();
	
	m->id = uint16_t((mcp2515_read(buffer_select + MCP2515_IDL_OFFSET) >> 5)) | (mcp2515_read(buffer_select + MCP2515_IDH_OFFSET) << 3)));
	m->length = mcp2515_read(buffer_select + MCP2515_DLC_OFFSET) & MCP2515_MASK_DLC;
	
	for(uint8_t i = 0; i < msg->length; i++){
		m->data[i] = mcp2515_read(buffer_select + MCP2515_RXB_OFFSET + i, msg->data[i]);
	}
	
	return m;
}


uint8_t can_poll_interrupt(){
	
	while(!(PIND & (1 << PD2))){}
	
	if(mcp2515_read(MCP_CANINTF) & MCP_RX0IF){
		mcp2515_bit_modify(MCP_CANINTF, MCP_RX0IF, 0x00);
		return MCP_RXB0CTRL;
	}
	
	else if(mcp2515_read(MCP_CANINTF) & MCP_RX1IF){
		mcp2515_bit_modify(MCP_CANINTF, MCP_RX1IF, 0x00);
		return MCP_RXB1CTRL;
	}
}


