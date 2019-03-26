#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
	struct node* next;
};

struct node* BuildOneTwoThree() {
   struct node* head = NULL;
   struct node* second = NULL;
   struct node* third = NULL;

   head = (struct node*)malloc(sizeof(struct node));
   second = (struct node*)malloc(sizeof(struct node));
   third = (struct node*)malloc(sizeof(struct node));

   head->data = 1;
   head->next = second;
   printf("%s:%d Value of ptr storing second is %p\n",__FUNCTION__,__LINE__,head->next);

   second->data = 2;
   second->next = third;
   printf("%s:%d Value of ptr storing third is %p\n",__FUNCTION__,__LINE__,second->next);

   third->data=3;
   third->next=NULL;

   return head;
}

int Length(struct node *head) {
    struct node* current = head;
    int count = 0;

    while(current != NULL) {
        count++;
        printf(" Node is %d\n",current->data);
        if(current != NULL)
    	    printf("%s:%d Value of %d node pointer is %p\n",__FUNCTION__,__LINE__,count,current->next);
    	current = current->next;
    }
    return count;
}

struct node* LinkTest(struct node* current) {
   printf("Entering LinkTest\n");
   //Linked list 3 step rule
   //Allocate
   struct node* newNode;
   newNode=(struct node*)malloc(sizeof(struct node));
   newNode->data=1;

   //Link next
   newNode->next=current;

   //Link head
   current=newNode;
   printf("%s:%d Value of new node pointer is %p\n",__FUNCTION__,__LINE__,newNode->next);
   printf("Exiting LinkTest\n");
   return current;
}

void push(struct node** headRef, int data) {
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=*headRef;
    *headRef=newNode;
}

int main()
{
   int len=0;

   struct node* current = NULL;
   struct node* newNode = current;

   current = BuildOneTwoThree();
   len = Length(current);

   printf("Value of len is %d\n",len);

   newNode = LinkTest(current);

   len=Length(newNode);

   //printf("Value of %d node pointer is %p\n",current->next);
   printf("Value of len is %d\n",len);

   push(&current,20);
   len=Length(current);
   printf("Value of len is %d\n",len);

   return 0;
}
