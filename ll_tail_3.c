#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

void push(struct node** headRef, int data) {
	struct node* newNode=NULL;
	newNode=(struct node*)malloc(sizeof(struct node));
	newNode->data=data;   
	printf("%s:%d: Pushed value is %d\n",__FUNCTION__,__LINE__,newNode->data);
   newNode->next=*headRef; //Link next
	*headRef=newNode; //Link head
}

void printList(struct node* head) {
	while(head->next != NULL) {
		printf("%s:%d: Value of head is %d\n",__FUNCTION__,__LINE__,head->data);
		head=head->next; // Advance the next pointer in the list
	}
}

void BuildWithSpecialCase(struct node** headRef) {
//void BuildWithSpecialCase(struct node* head) {
	struct node* tail;
	int i;
	tail=*headRef;
	for(i=6;i<10;i++) {
		push(&((*tail)->next),i);
		tail = tail->next; //Advance the next pointer
	}
	printf("\n Printing header : start\n");	
   printList(head);
	printf("\n Printing header : stop\n");	
}
int main() {
	struct node* head=NULL;
	head=(struct node*)malloc(sizeof(struct node));
//	struct node* head1=NULL;
//	head1=(struct node*)malloc(sizeof(struct node));
	push(&head,1);
	push(&head,2);
	push(&head,3);
	push(&head,4);
	push(&head,5);
//   printList(head);
//	printf("-------------------\n");
	BuildWithSpecialCase(&head);
   printList(head);
	return 0;
}
