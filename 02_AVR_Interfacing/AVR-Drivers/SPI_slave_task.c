/*
 * main.c
 *
 * Created: 8/20/2023 3:27:04 PM
 *  Author: Omar
 */ 


#define F_CPU 8000000UL
#include"..\MCAL\DIO_Driver\DIO_interface.h"
#include "../MCAL/SPI_Driver/SPI_interface.h"
#include"util/delay.h"
#include "../LIB/BIT_MATH.h"

const int SevenSegment[] = {
	0x3F, // 0
	0x06, // 1
	0x5B, // 2
	0x4F, // 3
	0x66, // 4
	0x6D, // 5
	0x7D, // 6
	0x07, // 7
	0x7F, // 8
	0x6F, // 9
	0b, // A 
	0x7C, // B
	0x39, // C
	0x5E, // D
	0x79, // E
	0x71  //F
	
};

int main(void)
{	
	DIO_voidSetPortDirection(DIO_PORTC,DIO_OUTPUT);
	
	SPI_voidSlaveInit();
	u8 data=0;
	u8 seg_value=0;
	while(1){
		data = SPI_u8Transceiver(10);
		seg_value=SevenSegment[data%16];
		DIO_voidSetPortValue(DIO_PORTC,seg_value); 
			
	}
	
	
}


