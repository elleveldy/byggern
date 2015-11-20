
int mcp2515_init();
int mcp2515_read(int address);
void mcp2515_write(int address, int data);

void mcp2515_request_to_send(int buffer_select);
void mcp2515_bit_modify(int address, int mask, int data);
void mcp2515_reset();
int mcp2515_read_status();