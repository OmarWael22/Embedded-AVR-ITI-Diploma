/*
 * assign1.c
 *
 *  Created on: Aug 12, 2023
 *      Author: Omar
 */

#include <avr/io.h>
#include<util/delay.h>
#include"../std_math.h"
#include"../std_types.h"


void main(void){

	DDRA=0x0FF;
	DDRC=0x0FF;
	DDRD=0xFF;
	u8 seg[10] = {

		    0x06,   // 1
		    0x5B,   // 2
		    0x4F,   // 3
		    0x66,   // 4
		    0x6D,   // 5
		    0x7D,   // 6
		    0x07,   // 7
		    0x7F,   // 8
		    0x6F,    // 9
			0x3F   // 0
		};


	while(1){


		for ( u8 i=9  ; i !=255 ; i--){
			// lighting the red led
			PORTA=set_bit(PORTA,0);
			// start counting from 10 down to 0
			PORTD=seg[i];
			PORTC=0;
			if(i==9)
				PORTC=seg[0];

			_delay_ms(1000);


		}

		clr_bit(PORTA,0);

		for (u8 i = 2 ; i !=255 ; i--){
				// lighting the yellow led
				PORTA=set_bit(PORTA,1);

				// start counting from 3 down to 0
				PORTD=seg[i];


				_delay_ms(1000);


			}

		clr_bit(PORTA,1);

		for (u8 i = 9 ; i !=255 ; i--){
				// lighting the red led
				PORTA=set_bit(PORTA,2);
				// start counting from 10 down to 0
				PORTD=seg[i];
				PORTC=0;
				if(i==9)
					PORTC=seg[0];

				_delay_ms(1000);



		}

		clr_bit(PORTA,2);


   }



}






