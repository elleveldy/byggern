//#ifndef _USAR_INIT
//#define _USAR_INIT
//
//
//
//#define FOSC 4915200// Clock Speed
//#define BAUD 9600
//#define MYUBRR FOSC/16/BAUD-1
//
//void USART_Init(unsigned int ubrr);
//void USART_Transmit( unsigned char data );
//unsigned charUSART_Receive( void);
//void USART_Flush(void);

//void USART_Init(unsigned int ubrr){
	 //
	////Set baud rate
	//UBRR0H = (unsigned char)(ubrr>>8);
	//UBRR0L = (unsigned char)ubrr;
#define FOSC 16000000
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1




unsigned char uart_Receive(void);
void uart_Transmit( unsigned char data );
void uart_Init(unsigned int ubrr);