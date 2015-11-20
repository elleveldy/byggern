#ifndef SPI_H_
#define SPI_H_


void spi_init();
int spi_write(char data);

char spi_read();
/*int spi_transmit(char data);*/

#endif