#include<stdio.h>

void main(void){
	
	int numbers[10];
	
	for (int i = 1 ; i<=10 ; i++ ){
		
		printf("Enter number %d: ",i);
		scanf("%d",&numbers[i]);
		
	}
	int target;
	printf("enter the value to search: ");
	scanf("%d",&target);
	
	for (int i=1;i<=10;i++){
		
		if(target==numbers[i]){
			printf("the value is exist at element number %d ",i);
		}
	}
	
	
	
}