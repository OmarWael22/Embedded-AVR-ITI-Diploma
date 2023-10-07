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
 
 
 typedef struct  {
		 
		 u16 ID;
		 u16 math;
		 u16 physics;
		 u16 lang;
		 
		
	 } student;
	 
	 
void print_grade(student);
	 
 void main (void ){
	 
	 u32 size ;
	 
	 printf("enter numbr of students : ");
	 scanf("%d",&size);
	 
	 student arr[size];
	 
	 for ( int i=0 ; i<size ; i++){
		 
		 printf("enter ID of student :  ");
		 scanf("%hu",&arr[i].ID);
		 
		  printf("enter math grade of student :  ");
		 scanf("%hu",&arr[i].math);
		 
		  printf("enter physics grade of student :  ");
		 scanf("%hu",&arr[i].physics);
		 
		  printf("enter lang grade of student :  ");
		 scanf("%hu",&arr[i].lang);
		 
		 printf("\n");
		 
		 
	 }
	 
	 u16 id ;
	 printf("enter student ID to view grades ");
	 scanf("%hu",&id);
	 
	 u16 flag =0;  
	   
	 for ( int i =0 ; i<size ; i++){
		 
		 
		 if(id == arr[i].ID){
			 
			 print_grade(arr[i]);
			 flag=1;
			 break;
		 }
	 }
	 
	 
	 if(flag==0)
		 printf("Invalid ID \n");


	 
 }
 void print_grade(student s ){
	 
	 printf("math grade = %d\n",s.math);
	 printf("physics grade = %d\n",s.physics);
	 printf("lang grade = %d\n",s.lang);
	 
 }
  