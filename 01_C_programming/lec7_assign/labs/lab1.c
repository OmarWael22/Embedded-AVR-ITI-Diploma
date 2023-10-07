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
	 
	  int net_sal ( struct employee emp  );

	 
 void main (void ){
	 
	 
	 struct employee ahmed ,amr ,waleed;
	 
	 

	 printf("enter ahmed's  salary : ");
	 scanf("%hu",&ahmed.salary);
	 
     printf("enter bonus : ");
	 scanf("%hu",&ahmed.bonus);	 
	 
	 printf("enter deduction : ");
	 scanf("%hu",&ahmed.deduction);
	 
	 
	 printf("enter amr's  salary : ");
	 scanf("%hu",&amr.salary);
	 
     printf("enter bonus : ");
	 scanf("%hu",&amr.bonus);	 
	 
	 printf("enter deduction : ");
	 scanf("%hu",&amr.deduction);
	 
	 printf("enter waleed's  salary : ");
	 scanf("%hu",&waleed.salary);
	 
     printf("enter bonus : ");
	 scanf("%hu",&waleed.bonus);	 
	 
	 printf("enter deduction : ");
	 scanf("%hu",&waleed.deduction);
	 
	 
	 
	 int finance = net_sal(amr) + net_sal(ahmed)+net_sal(waleed);
	 
	 
	 printf("total value needed = %d",finance);
	 
 }
 
  int net_sal ( struct employee emp){
	  
	  return emp.salary + emp.bonus -emp.deduction ;
  }