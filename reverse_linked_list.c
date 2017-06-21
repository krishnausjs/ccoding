#include <stdio.h>
#include <stdlib.h>

struct node 
{
	int data;
	struct node *next;
};

void allocate_ll(struct node **head,int num) {
	struct node *new_node=(struct node*)malloc(sizeof(struct node));	
	if(new_node != NULL)
	{
		new_node->data=num;
		new_node->next = *head->next;
		*head=new_node;
	}	
}

void print_ll(struct node *head)
{
	while( head->next != NULL)
	{
		printf("\n%d",head->data);
		head=head->next;
	}
}

void reverse_ll(struct node **head,int num) {
	struct node *current=NULL;
	struct node *prev=NULL;	
	
	
}
int main()
{

    return 0;
}
