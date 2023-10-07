# include <stdio.h>

typedef unsigned char         u8;
typedef signed char           s8;
typedef unsigned short int   u16;
typedef signed short int     s16;
typedef unsigned long int    u32;
typedef signed long int      s32;
typedef float 			 	 f32;
typedef double 				 f64;
typedef long double 		 f128;

typedef struct {
	
		u16 x;
		u16 z;
		u32 k;
		u32 y;
	
	
}st;

typedef union {
	
		u16 x;
		u16 z;
		u32 k;
		u32 y;
	
	
}unn;

void main (void){
	
	//  st data ; 
	printf("%d\n",sizeof(st));
	
 //	unn data2;
	printf("%d",sizeof(unn));

	
	
	
	
	
}