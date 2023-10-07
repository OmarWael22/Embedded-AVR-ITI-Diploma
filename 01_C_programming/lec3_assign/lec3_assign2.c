#include <stdio.h> 
#include <string.h>
void main(void){
	
	int id,pass,real_pass; 
	char name[20];
	int ahmed_pass=7788 ,amr_pass=5566 ,wael_pass=1122;
	
	printf("please enter your ID : ");
	scanf("%d",&id);
	
	 int flag_id=0;
	switch(id){
		
		case 1234:
			strcpy(name,"ahmed");
			real_pass=ahmed_pass;
			break;
		case 5675:
			strcpy(name,"amr");
			real_pass=amr_pass;
			break;
		case 9870:
			strcpy(name,"omar");
			real_pass=wael_pass;
			break;
		default:
			printf("you are not registered\n");
			flag_id=1;
	}
	
	if(flag_id==1)
		return;
	
	int tries=3;
	
	printf("please enter password : ");
	for( int i = 0; i<tries;i++){
		scanf("%d",&pass);
		if(real_pass == pass){
			printf("Welcome %s",name);
			break;
		}
	if(i==2)
		printf("Incorrect password for 3 times,	No more tries");
	else
		printf("Try again : ");
	

		
	}
	
	
	
	
	
	

	
}

