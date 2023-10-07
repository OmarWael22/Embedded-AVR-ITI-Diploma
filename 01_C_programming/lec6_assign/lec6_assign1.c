#include<stdio.h>

void bubble_sort(int* arr , int size );
void swap (int* arr , int idx);


void main(void){
	
	int size;
	printf("enter size : ");
	scanf("%d",&size);
	
	int num[size];
	
	for ( int i=0 ; i<size ; i++){
		printf("enter element number %d : ",i);
		scanf("%d",&num[i]);
		
		
	}
	
	bubble_sort( num , size );
	
	printf("the values after sorting\n");
	
	
	
	for ( int i=0 ; i<size ; i++){
		printf(" element number %d : %d \n",i,num[i]);
		
	}
	
}

void bubble_sort(int* arr ,int size ){
	
	for ( int i=0 ; i<size-1 ; i++){
		
		for ( int j=0 ; j<size-i-1; j++){
			
			
			if(arr[j+1] < arr[j])
				swap(arr,j);
		}
			
	}
	
	
	
	
	
}

void swap(int * arr, int idx){
	
	int temp = arr[idx];
	arr[idx]=arr[idx+1];
	arr[idx+1]=temp;
	
	
	
}