#include <stdio.h> 

int get_max(int a ,int b , int c ,int d);
int get_min(int a ,int b , int c ,int d);

void main(void){

	int numbers[4];
	
	for ( int i = 0 ; i<4 ; i++ ){
		printf("enter value %d : ",i);
		scanf("%d",&numbers[i]);
	}
	int max =get_max(numbers[0],numbers[1],numbers[2],numbers[3]);
	int min =get_min(numbers[0],numbers[1],numbers[2],numbers[3]);
	
	printf("max value is : %d\n",max);
	printf("min value is : %d",min);
}
int get_max(int a ,int b , int c ,int d){
	
	 int max=a;
	if( b > max )
		max=b;
	if( c > max )
		max=c;
	if( d > max )
		max=d;
	return max;
	
	
	
}

int get_min(int a ,int b , int c ,int d){
	
	 int min=a;
	if( b < min )
		min=b;
	if( c < min )
		min=c;
	if( d < min )
		min=d;
	return min;
	
	
	
}
