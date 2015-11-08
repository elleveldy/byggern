#include <avr/pgmspace.h>


#define OLED_DATA_ADRESS 
#define SRAM_ADRESS 0x0000
#define FONT_SIZE 8

static FILE oled_stdout = FDEV_SETUP_STREAM(oled_print_char, NULL, _FDEV_SETUP_WRITE); 

volatile char *oled_data_adr = (char *) 0x1200;
volatile char *oled_command_adr = (char *) 0x1000;


static inline void oled_command_write(char command){
	*oled_command_adr = command; 
}	

static inline void oled_testo(char command){
	*oled_command_adr = command;	
}


static inline void oled_data_write(char data){
	*oled_data_adr = data;
}

void oled_init()
{
	
	oled_command_write(0xae);    // display off
	oled_command_write(0xa1);    //segment remap
	oled_command_write(0xda);    //common pads hardware: alternative
	oled_command_write(0x12);
	oled_command_write(0xc8);    //commonoutput scan direction:com63~com0
	oled_command_write(0xa8);    //multiplex ration mode:63
	oled_command_write(0x3f);
	oled_command_write(0xd5);    //displaydivide ratio/osc. freq. mode
	oled_command_write(0x80);
	oled_command_write(0x81);    //contrast control
	oled_command_write(0x50);
	oled_command_write(0xd9);    //set pre-charge period
	oled_command_write(0x21);

	oled_command_write(0x20);    //Set Memory Addressing Mode
	oled_command_write(0x00);
	
	oled_command_write(0xdb);    //VCOM deselect level mode
	oled_command_write(0x30);
	oled_command_write(0xad);    //master configuration
	oled_command_write(0x00);
	oled_command_write(0xa4);    //out follows RAM content
	oled_command_write(0xa6);    //set normal display
	oled_command_write(0xaf);    // display on
	//oled_command_write(0xa4);    //Entire display on
	
	//oled_clear_screen();
	oled_home();
}

	



static inline void oled_command_write(char command){
	*oled_command_adr = command; 
}
static inline void oled_data_write(char data){
	*oled_data_adr = data;
}


void oled_store_string(char* string, int* position){
	//calculate position offset
	int start_position = position[0]*128 + position[1];

	for(int i = 0; string[i] != '\0' ++i){
		//j goes through each col	n of the char in font
		for(int j = 0; j < FONT_SIZE; ++j){
			//font[char index in font][column of char]
			*(SRAM_ADRESS + start_position + i * FONT_SIZE + j) = pgm_read_byte(font[i][j]);//what should be here?
		}
	} 
}	

void oled_write_data(){
	for(int i = 0; i < 1024; ++i){
		*OLED_DATA_ADRESS = *(SRAM_ADRESS + i);
	}

}