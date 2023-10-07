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



void main (void) {
	
	s32 x=10;
	s32 y=20;
	s32 z=30;
	
	s32* p = &x;
	s32* q = &y;
	s32* r = &z;
	
	printf("x = %d\n",x);
	printf("y = %d\n",y);
	printf("z = %d\n",z);
	printf("*p = %d\n",*p);
	printf("*q = %d\n",*q);
	printf("*r = %d\n\n",*r);
	
	// swapping pointers
	r=p; p=q; q=r;
	printf("Swaping pointers\n\n");
 	
	// excepected output after swapping x,y,z remains the same 
	// *p=y , *q =x , *r=x 
	
	printf("x = %d\n",x);
	printf("y = %d\n",y);
	printf("z = %d\n",z);
	printf("*p = %d\n",*p);
	printf("*q = %d\n",*q);
	printf("*r = %d\n",*r);
	
}