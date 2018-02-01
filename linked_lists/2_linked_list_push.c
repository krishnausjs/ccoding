#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void push(struct node** headRef, int data) {
   struct node* newNode=(struct node*)malloc(sizeof(struct node));  
   newNode->data=data;
   newNode->next=*headRef;
   *headRef=newNode;
}

int main() {
   struct node *head=NULL;
   push(&head,1);
   push(&head,2);
   push(&head,3);
   
   while(head != NULL) {
       printf("%d\t",head->data);
       head=head->next;
   }
   printf("\n");
   return 0;
}
