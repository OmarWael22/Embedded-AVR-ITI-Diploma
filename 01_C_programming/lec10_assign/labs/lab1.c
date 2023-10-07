# include <stdio.h> 
#include <stdlib.h>
# include "../../STD_MATH.h"
# include "../../STD_TYPES.h"

void swap ( u32* );

void main (void){
	
	u8 size ;
	
	printf("please enter size : ");
	scanf("%hu",&size);
	
	u32 * ptr = malloc (size * sizeof(u32));
	
	for ( int i = 0 ; i<size ; i++){
		
		
		printf("enter number %d : ",i);
		scanf("%d",&ptr[i]);
		
	}
	
	
	
	
	for ( int i = 0 ; i<=size ; i++){
		
		for ( int j = 0 ; j<size-i-1 ; j++){
			
			if( ptr[j] > ptr[j+1] ){
				
				swap(&ptr[j]);
			}
			
		}
		
	}
	
	for ( int i = 0 ; i<size ; i++){
		
		
		printf(" number %d : %d \n",i,ptr[i]);
		
		
	}
	
	free(ptr);
	
	
}

void swap ( u32 * ptr){
	
	
	u32 temp = *ptr ;
	*ptr = *(ptr+1);
	*(ptr+1)= temp ;
	
}