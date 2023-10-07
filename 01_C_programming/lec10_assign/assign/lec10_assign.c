# include <stdio.h> 
#include <stdlib.h>
# include "../../STD_MATH.h"
# include "../../STD_TYPES.h"

typedef struct node {
	
	u16 data ;
	struct node* next ;
} node ;

void delete_nodes(node* , u16);
node* create_node( u16 );
void append_node ( node** h_ptr , node ** t_ptr ,node * );
void print_list( node * );

void main (void ){
	
	u16 choice,val ;
	
	
	node * head = NULL ;
	node* tail =NULL ;
	
	while (1){
		
		printf("To add node enter 0 \n"
				"To print the list enter 1 \n"
				"To exist press 2 \n"
				"To delete node enter 3\n"
				"To insert custom node enter 4 \n");
				
		printf("enter ur choice : ");
		scanf("%hu",& choice);
		
		switch (choice) {
			
			case 0 :
			
				printf(" enter data to be stored ");
			    scanf("%hu",& val );
				node* new_node = create_node(val);
				append_node( &head , &tail  , new_node);
				break;
			
			case 1 :
				
				print_list ( head );
				break ;
			
			case 2 : 
				
				return ;
				break ;
				
			case 3 :
			
				printf("enter the value to be deleted ");
				scanf("%hu",&val);
				delete_nodes( &head,val);
				break ;
				
			case 4 : 
			
				printf(" enter data to be stored ");
			    scanf("%hu",& val );
				node* new_node = create_node(val);
				append_node( &head , &tail  , new_node);
				break;
				
			default :
				
				while( head != NULL){
					
					node * temp = head ;
					free( temp );
					head = head -> next ;
					
					
				}
				printf("Incorrect option");
			
		}
			 
			printf("\n");
		
	}
	
	
	
	
}

node* create_node( u16 x ){
	
	node* temp = (node*) malloc(sizeof(node)) ;
	if(temp != NULL ){
	   temp->data = x;
	   temp->next = NULL ;
	}
   
   return temp ;
	
	
}

void append_node ( node** h_ptr , node** t_ptr ,node * mynode ){
	
	node * current = *h_ptr ;
	
	if (current == NULL)
		*h_ptr = mynode ; 
		
	else{
		(*t_ptr)->next = mynode ;
		
	}
	
	*t_ptr = mynode ;
	
	
}

void print_list( node * head ){
	
	u8 i = 1 ;
	while ( head  != NULL){
		
		
		
		printf("element number %d = %d \n",i,head->data);
		
		head = head -> next ;
		i++;
		
	}
	if ( i == 1){
		
		printf("Error! list is empty \n");
	}
	
}

void delete_nodes(node** head_ptr , u16 val ){
	
	
	node * prev = NULL ;
	node * current =  *head_ptr  ;
	// chec if list is empty 
	if( current  == NULL){
		
		printf("Error! list is empty \n");
	}
	// check if the val found at the head 
	if ( current -> data == val ){
		
		*head_ptr = current -> next ;
		current->next = NULL ;
		free(current);
	}
	
	while (  current -> next != null ){
		
		
			if( current-> data = val ){
			
			prev->next =current -> next ;
			current->next = NULL;
			free (current);
			}
			
		
		
			
			prev = current ;
			current = current -> next ;
		} 
		
		// first case current.data = val 
		// second current.data != val and current .next = null
		if( current-> data = val ){
			
			prev->next =current -> next ;
			current->next = NULL;
			free (current);
			
		}
		
		
		
	}
	
}