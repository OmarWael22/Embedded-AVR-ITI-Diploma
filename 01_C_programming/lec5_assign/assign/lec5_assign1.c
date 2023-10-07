#include<stdio.h>



void main(void){
	
	int size,max,min;
	
	printf("enter size : ");
	scanf("%d",&size);
	 int num[size];
	 
	
	for ( int i=0 ; i<size ; i++){
		printf("enter element number %d : ",i);
		scanf("%d",&num[i]);
		
		
	}
	
	max=num[0];
	min=max;
	
	for ( int i=0 ;i<size; i++){
		if(num[i]>max)
			max=num[i];
		
		if(num[i]<min)
			min=num[i];
		
	}
	
	printf("max value is : %d\n",max);
	printf("Min value is : %d\n",min);
	
	
}

