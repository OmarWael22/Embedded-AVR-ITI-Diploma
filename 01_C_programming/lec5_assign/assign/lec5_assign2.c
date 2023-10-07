#include<stdio.h>

void get_stats(int size,int* arr ,int* pass ,int *fail ,int *max ,int *min ,int *av);

void main(void){
	
	int class1[]={10,20,30,40,50,60,70,80,90,100};
	int class2[]={35,40,45,50,60,70,75,80,85,85};
	int class3[]={40,47,55,68,78,87,92,95,98,98};
	
	int size=sizeof(class1)/sizeof(*class1);
	
	int pass[3]={0},fail[3]={0},max[3],min[3],av[3];
	
	// get class 1 stats 
	get_stats(size,class1,pass,fail,max,min,av);
	
	// get class 2 stats 
	get_stats(size,class2,pass+1,fail+1,max+1,min+1,av+1);
	
	// get class 3 stats 
	get_stats(size,class3,pass+2,fail+2,max+2,min+2,av+2);
	
	//print stats for three classes 
	
		for ( int i=0 ; i<3 ; i++ ){
			
			printf("stats for class %d : \n",i+1);
			printf("number of student passed = %d \n",pass[i]);
			printf("number of student failed = %d \n",fail[i]);
			printf("max grade = %d\n",max[i]);
			printf("Min grade = %d\n",min[i]);
			printf("average grade = %d\n\n\n",av[i]);
			
			
		}
	
	
	
	
}

void get_stats(int size,int* arr ,int* pass ,int *fail ,int *max ,int *min ,int *av){
	
	int sum=0;
	*max = *arr;
	*min = *max;
	
	for ( int i=0;i<size; i++){
		
		if(*arr > *max)
			*max = *arr;
		
		if(*arr < *min )
			*min = *arr;
		
		
		if(*arr >=50)
			(*pass)++;
		
		else
			(*fail)++;
		
		sum+=*arr;
		arr++;
		
	}
	
	*av=sum/size;
	
	
	
}


