# include <stdio.h> 
#include <stdlib.h>
# include "../../STD_MATH.h"
# include "../../STD_TYPES.h"




typedef struct node {
	
	u16 data ;
	struct node* next ;
} node ;

node* create_node( u16 );
void append_node ( node** h-ptr ,node * );
void print_list( node * );

void main (void ){
	
	u16 choice,val ;
	printf("enter ur choice : ");
	scanf("%hu",& choice);
	node head ;
	while (1){
		
		
		if (choice == 0){
			 printf(" enter data to be stored ");
			 scanf("%hu",& val );
			node* new_node = create_node(val);
			append_node(&head ,)
			
		}
	}
	
	
	
	
}

node* create_node( u16 x ){
	
	node* temp = (node*) malloc(sizeof(node)) ;
	if(temp != NULL )
	   temp->data = x;
   
   return temp ;
	
	
}

void append_node ( node** h-ptr ,node * mynode ){
	
	node * current = *h-ptr ;
	
	if (current == NULL)
		*h-ptr = mynode ; 
	else{
		
		do {
			current = current -> next ;
			
		}while (current-> next != NULL);
		
		current->next = mynode ;
	}
	
	
}

void print_list( node * head ){
	
	u8 i = 0;
	while (head -> next != NULL){
		
		head = head -> next ;
		i++;
		
		printf("element number %d = %d \n",i,head->data);
		
	}
	
}