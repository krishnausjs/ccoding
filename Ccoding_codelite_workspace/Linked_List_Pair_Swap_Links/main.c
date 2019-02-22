/* This program swaps the nodes of linked list rather than swapping the
field from the nodes.
Imagine a case where a node contains many fields, there will be plenty
of unnecessary swap calls. */
 
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
 
/* A linked list node */
struct Node
{
    int data;
    struct Node *next;
};
 
/* Function to pairwise swap elements of a linked list */
void pairWiseSwap(struct Node **head)
{
    // If linked list is empty or there is only one node in list
    if (*head == NULL || (*head)->next == NULL)
        return;
    printf("\n");
    printListAddr(*head);

    printf("*head = 0x%p\n",*head);
    // Initialize previous and current pointers
    struct Node *prev = *head;
    struct Node *curr = (*head)->next;
    printf("prev = 0x%p\n",prev);
    printf("curr = 0x%p\n",curr);    
    *head = curr;  // Change head before proceeeding
    printf("New *head = 0x%p\n",*head);
    // Traverse the list
    while (true)
    {
        printf(" curr->next = 0x%p\n", curr->next);
        struct Node *next = curr->next;
        printf("next = 0x%p\n",next);
        //printListAddr(*head);

        printf(" curr->next = 0x%p\n", curr->next);
        curr->next = prev; // Change next of current as previous node
       // printf("curr->next  = 0x%p\n",curr->next);

        // If next NULL or next is the last node
        if (next == NULL || next->next == NULL)
        {
            prev->next = next;
            break;
        }
 
        // Change next of previous to next next
        printf(" prev->next  = 0x%p\n",prev->next );        
        prev->next = next->next;
        printf(" next->next  = 0x%p\n",next->next );
        //printListAddr(*head);       
        // Update previous and curr
        printf(" prev = 0x%p\n\n",prev );
        prev = next;       
        curr = prev->next;
        printListAddr(*head);         
        printf(" prev = 0x%p\n",prev );
        printf(" curr = 0x%p\n",curr );
        printf("-------------------------------------------------\n");
    }
}
 
/* Function to add a node at the begining of Linked List */
void push(struct Node** head_ref, int new_data)
{
    /* allocate node */
    struct Node* new_node =
        (struct Node*) malloc(sizeof(struct Node));
 
    /* put in the data  */
    new_node->data  = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while(node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}


void printListAddr(struct Node *node)
{
    struct Node *temp=node;
    while(temp != NULL)
    {
        printf("0x%p (%d)->", temp,temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
/* Druver program to test above function */
int main()
{
    struct Node *start = NULL;
 
    /* The constructed linked list is:
     1->2->3->4->5->6->7 */
    push(&start, 7);
    push(&start, 6);
    push(&start, 5);
    push(&start, 4);
    push(&start, 3);
    push(&start, 2);
    push(&start, 1);
 
    printf("\n Linked list before calling  pairWiseSwap() ");
    printList(start);
 
    pairWiseSwap(&start);
 
    printf("\n Linked list after calling  pairWiseSwap() ");
    printList(start);
 
    getchar();
    return 0;
}