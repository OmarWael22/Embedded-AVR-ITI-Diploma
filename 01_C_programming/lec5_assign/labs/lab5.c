#include<stdio.h>

int dot ( int *,int  ,int * ,int ,int* );

void main(void){
	
	int arr1[] = {10,20,30};
	int size1= sizeof(arr1) / sizeof(arr1[0]);
	
	int arr2[] = {1,1,1};
	int	size2= sizeof(arr2) / sizeof(arr2[0]);

	int res=0;
	 
	int flag= dot(arr1,size1,arr2,size2,&res);
	
	if (flag==0){
		
		printf("the dot product = %d \n",res);
	}
	else 
		printf("Error arrays has different sizes\n");
	
}

int dot ( int* arr1 ,int size1 ,int* arr2 ,int size2 , int* res_ptr ){
	
	if(size1 != size2 )
		return 1;
	
	for ( int i = 0 ; i<size1 ; i++ ){
		
		(*res_ptr) += arr1[i] * arr2[i];
		
	}
	return 0;
	
	
	
}
