#include <stdio.h>

int get_max(int x,int y);

void main(void){
	
	int num1,num2,num3,max;
	
	printf("enter number 1 : ");
	scanf("%d",&num1);
	
	printf("enter number 2 : ");
	scanf("%d",&num2);
	
	printf("enter number 3 : ");
	scanf("%d",&num3);
	
	max=get_max(num1,num2);
	max=get_max(num3,max);
		
	printf("maximun number is %d",max);
}

 int get_max(int x,int y){
	 
	 if(x>=y)
		return x;
	else
		return y ;
 }