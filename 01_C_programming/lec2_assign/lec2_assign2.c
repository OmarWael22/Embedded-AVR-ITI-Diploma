#include<stdio.h>

void main(void){
	int omar_pass=6545, ahmed_pass= 789441, mona_pass=9634;
	int id,pass;
	printf("enter userID : ");
	scanf("%d",&id);
	int id_flag = 0 ;
	char name;
	switch (id) {
		
		case 123:
			name='o';
			break;
		
		case 122:
			
			name='a';
			break;
		
		case 111 :
			name='m';
			break;
		
		default:
			id_flag=1;
		
	}
		if (id_flag){
			printf("wrong ID\n");
			return;
		}
		printf("enter user password : ");
		scanf("%d",&pass);
			
		
		switch(name){
			
			case 'o':
				if (pass==omar_pass){
					printf("welcome omar\n");
				break;
			}
			case 'a':
				if (pass == ahmed_pass){
					printf("welcome ahmed\n");
				break;
				}
				
			case 'm':
				if (pass == mona_pass){
					printf("welcome mona\n");
					break;
				}
				default:
				printf("wrong password\n");
		} 
			
				
		
		

	
	
}