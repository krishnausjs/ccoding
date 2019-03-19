#include <stdio.h>
#define USE_RECURSIVE_METHOD
struct node
{
    int data;
    struct node *next;
};

void display_linked_list(struct node* head)
{
    printf("Elements in the list are ... \n");
    while(head != NULL)
    {
        printf("%d ",head->data);
        head = head->next;
    }
    printf("\n");
}

void push(struct node **head_ref, int data)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

#ifdef USE_RECURSIVE_METHOD
void remove_node_from_linked_list(struct node** head_ref, int key)
{
    if(*head_ref == NULL)
        return;
    else if(*head_ref->data)
    
    struct node* prev;
    prev = remove_node_from_linked_list()
}
#else
void remove_node_from_linked_list(struct node** head_ref, int key)
{
    //Firstnode
    if(*head_ref == NULL)
    {
        printf("Head node cannot be null\n");
        return;
    }
    //Middle node
    struct node *current = *head_ref;
    struct node *prev;
    while(current != NULL && current->data != key)
    {
        prev = current;
        current  = current->next;
    }
    
    if(current == NULL)
    {
        printf("Element is not available in the list\n");
        return;
    }
    prev->next = current->next;
    free(current);
}
#endif

int main(int argc, char **argv)
{
    struct node*  head = NULL;
    int i, n, node_data;

    printf("Enter number of nodes in linked list\n");
    scanf("%d",&n);
    
    printf("Enter linked list nodes\n");
    for(i=0; i<n; i++)
    {
        scanf("%d",&node_data);
        push(&head,node_data);
    }
    display_linked_list(head);
    printf("From above list enter the element to remvoe\n");
    scanf("%d",&node_data);
    remove_node_from_linked_list(&head, node_data);
    display_linked_list(head);
    return 0;
}
