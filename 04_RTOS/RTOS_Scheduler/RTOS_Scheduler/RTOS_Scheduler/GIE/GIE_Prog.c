/*
 * GIE_Prog.c
 *
 *  Created on: Aug 17, 2023
 *      Author: Hardware
 */

#include<avr/io.h>
#include"../../LIB/BIT_MATH.h"

#include"GIE_Interface.h"

void GIE_voidEnableGlobalInterrupt(void){
	Set_Bit(SREG,7);
}
void GIE_voidDissableGlobalInterrupt(void){
	CLR_Bit(SREG,7);
}
