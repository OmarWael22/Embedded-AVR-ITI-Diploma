/*
 * assign2.c
 *
 *  Created on: Aug 12, 2023
 *      Author: Omar
 */

#include<avr/io.h>
#include<util/delay.h>
#include"../std_types.h"
#include"../std_math.h"

void mode0();
void mode1();
void mode2();
void mode3();
void mode4();
void mode5();
void mode6();
void mode7();

void main(void){

	// output port A
	DDRA=0x0FF;
	// input port B
	DDRB=0;
	// enable built in resistor
	PORTB=0b00000111;
	u8 mode;

	while(1){


		// check if power is on or off
		if( (PINB & 0x80)==0){
			// calculate the mode
			mode = (~PINB&7);

		switch ( mode ){

		case 0:
			mode0();
			break;

		case 1:
			mode1();
			break;
		case 2:
			mode2();
			break;
		case 3:
			mode3();
			break;
		case 4:
			mode4();
			break;
		case 5:
			mode5();
			break;
		case 6:
			mode6();
			break;
		case 7:
			mode7();
			break;


			}
		}
		else
			PORTA=0;


	}


}

void mode0(){ //done


	PORTA=0x0FF;
	_delay_ms(500);
	PORTA=0;
	_delay_ms(500);
}

void mode1(){ //done

	static u8 i=0;
	PORTA= 0x80 >> i;
	i++;
	i=i%8;
	_delay_ms(250);


}

void mode2(){ //done

	static u8 i=0;
	PORTA= 1 <<i;
	i++;
	i=i%8;
	_delay_ms(250);

}

void mode3(){ //done

	static u8 i=0;
	PORTA= 0x80>>i | 1<<i ;
	i++;
	i=i%4;
	_delay_ms(300);
}

void mode4(){ //done

	static u8 i=0;
	PORTA= 16<<i | 8>>i ;
	i++;
	i=i%4;
	_delay_ms(300);

}

void mode5(){ //done
		static u8 i=0;
		if(i<7){

			PORTA= 0x80 >> i ;
		}
		else if(i<15){

			PORTA= 1 << (i-8);

		}

		i++;
		i=i%15;
		_delay_ms(250);


}

void mode6(){  //done

	static u8 pattern = 0x01;
	 static u8 snakeLength = 1;


	        PORTA = pattern;


	        pattern = (1 << snakeLength) - 1;

	        if (snakeLength <= 8) {
	            snakeLength++;
	        } else {

	            pattern = 0x01;
	            snakeLength = 1;
	        }

	        _delay_ms(300);
	    }


void mode7(){  //done

	static u8 i=0;

		if(i<3)
		PORTA= 0x80>>i | 1<<i ;

		else if (i<6)
			PORTA= 16<<(i-3) | 8>>(i-3) ;

		i++;
		i=i%6;

		_delay_ms(300);


}

