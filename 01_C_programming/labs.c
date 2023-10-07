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
 
 
 struct employee {
		 
		 u16 salary;
		 u16 deduction;
		 u16 bonus;
		
	 };
	 
	 
typedef struct {
	
		u8 x : 4 ;
		u8 y: 2 ;
		u8 z: 1 ;
		u8 w :1;
	
} bit_wise ;



typedef enum {
	
	sat =2,
	sun,
	mon
} week ;
	 
	  int net_sal ( struct employee emp  );

	 
 void main (void ){
	 week today = 2 ;
	 
	 printf("%d",today);
	 


	 
 }
 
  int net_sal ( struct employee emp){
	  
	  return emp.salary + emp.bonus -emp.deduction ;
  }