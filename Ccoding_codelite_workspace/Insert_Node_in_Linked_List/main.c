#include <stdio.h>

struct node 
{
    int data;
    struct node* next;
};

void insert_node_at_beginning(struct node **head_ref, int new_node_data)
{
    //To insert node at beginning, create a node first
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_node_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void push(struct node** head_ref, int data)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next  = (*head_ref);
    (*head_ref) = new_node;
}

void display_linked_list(struct node *head)
{
    while(head != NULL)
    {
        printf("%d ",head->data);
        head = head->next;
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    struct node* head = NULL;
    int i, n, node_data;
    printf("Enter number of linked list nodes \n");
    scanf("%d",&n);
    printf("Enter nodes in linked list\n");
    for(i = 0; i <n; i++)
    {
        scanf("%d",&node_data);
        push(&head,node_data);
    }
    display_linked_list(head);
    printf("Enter element to insert at the beginning of linked list \n");
    scanf("%d",&node_data);
    insert_node_at_beginning(&head, node_data);
    printf("New elements in the list are\n")
    display_linked_list(head);
    printf("From above displayed list")
    printf("Enter element to insert at the beginning of linked list \n");
    scanf("%d",&node_data);
	return 0;
}
