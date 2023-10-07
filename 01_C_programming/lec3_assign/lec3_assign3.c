#include <stdio.h>

void main (void){
	
	int h;
	printf("enter the height of the pyramid : ");
	scanf("%d",&h);
	
	for (int i = 0 ; i<h ; i++){
		
		for (int j = h-i-1 ; j>0 ; j-- )
			printf(" ");
		
		for (int k =  0; k<2*i+1 ; k++ )
			printf("#");
		
		printf("\n");
		
		
	
	}
	
}