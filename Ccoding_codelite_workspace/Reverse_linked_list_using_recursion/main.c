#include <stdio.h>

struct node 
{
    int data;
    struct node *next;
};

void push(struct node** head_ref, int data)
{
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void display_linked_list(struct node *head)
{
    int i = 0;
    while(head != NULL)
    {
        printf("%d ",head->data);
        head = head->next;
    }
    printf("\n");
}
#define USE_RECURSION_METHOD

#ifdef USE_RECURSION_METHOD
struct node* reverse_linked_list(struct node **head_ref)
{
        if(*head_ref == NULL)
            return;
        struct node *current = *head_ref;
        struct node *prev = NULL;
        struct node *next_node = NULL;
        
        next_node = current->next;
        current->next = prev;
        prev = reverse_linked_list((*head_ref)->next);
        current = prev;
        (*head_ref) = prev;
}
#else
void reverse_linked_list(struct node **head_ref)
{
    struct node* current = *head_ref;
    struct node* prev = NULL;
    struct node *new_node = NULL;
    
    while(current != NULL)
    {
        new_node = current->next;
        current->next = prev;
        prev = current;
        current = new_node;
    }
    
    (*head_ref) = prev;
}
#endif

int main(int argc, char **argv)
{
    struct node *head = NULL;
    int n,i;
    int node_data;
    
    printf("Enter the number of nodes \n");
    scanf("%d",&n);
    printf("Enter the nodes\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d",&node_data);
        push(&head,node_data);
    }
    printf("Nodes in linked list are \n");
    display_linked_list(head);
    
    printf("Reversing a linked list now\n");
    reverse_linked_list(&head);
    display_linked_list(head);
    
	return 0;
}
