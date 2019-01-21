#include "myLinkedList.h"

/**************************************************************** 
* insert_into_list: Inserts the number n into the inputted list * 
****************************************************************/
void insert_into_list (struct node **list, int n)
{
	struct node *cur, *prev, *new_node;

	if ((new_node = malloc (sizeof(struct node))) == NULL){
		printf("Error creating new node. Memory is full.");
		return;
	}
	
	new_node->value = n;	
	for (cur = *list, prev = NULL;
		 cur != NULL && new_node->value > cur->value;
		 prev = cur, cur = cur->next)
	  ;
	if (cur != NULL && new_node->value == cur->value){
		free(new_node);
		return;
	}
	
	new_node->next = cur;
	if (prev == NULL){
		*list = new_node;
	} else {
		prev->next = new_node;
	}
}