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
    printf("Head is 0x%x\n",head);
    while(head != NULL)
    {
        printf("0x%x -> %d \n",head->next,head->data);
        head = head->next;
    }
    printf("\n");
}

void insert_after_element(struct node** head_ref, int key, int data)
{
        //1->2->4->5->NULL
        //          3
        struct node* current = *head_ref;
        struct node* prev;
        
        if(current== NULL)
        {
            printf("Head node cant be null\n");
            return;
        }
        
        struct node* new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data = data;
        
        if(current->data == key)
        {
            new_node->next  = current->next;
            current->next = new_node;
        }
        else
        {
            while(current != NULL && current->data != key)
            {
                current = current->next;
            }
            new_node->next  = current->next;
            current->next= new_node;
        }
}

void insert_at_nth_position(struct node **head_ref, int position, int data)
{
    struct node *current = *head_ref;
    int pos = 1;
    
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    
    if(current == NULL)
    {
        printf("Head is null \n");
        return;
    }
 #if 0   
    else if(position == 1)
    {
        new_node->data = data;
        new_node->next = current->next;
        current->next = new_node;
    }
    else 
#endif
    {
        while(current->next != NULL && pos < position-1) 
        {
            printf("Current data at %d is %d storing 0x%x\n",pos,current->data,current->next);
            current  = current->next;
            pos++;
        }
        printf("Value of current is 0x%x\n",current);
        if(current == NULL)
        {
            printf("Current is NULL. Element not found\n");
            return;
        }
        else
        {
            new_node->data = data;
            new_node->next = current->next;
            current->next = new_node;
        }
    }
}

void insert_at_the_end_of_list(struct node** head_ref, int data)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    struct node* current = *head_ref;
    new_node->data = data;
    new_node->next = NULL;
    
    if(*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
    else
    {
        while(current->next != NULL)
        {
            current = current->next;
        }
         current->next = new_node;
    }
}
int main(int argc, char **argv)
{
    struct node* head = NULL;
    int i, n, node_data,key;
    int position = 0;
    printf("Enter number of linked list nodes \n");
    scanf("%d",&n);
    printf("Enter nodes in linked list\n");
    for(i = 0; i <n; i++)
    {
        scanf("%d",&node_data);
        push(&head,node_data);
    }
    display_linked_list(head);
#if 0
    printf("Enter element to insert at the beginning of linked list \n");
    scanf("%d",&node_data);
    insert_node_at_beginning(&head, node_data);
    printf("New elements in the list are\n");
    display_linked_list(head);
    printf("From above displayed list pick an element to insert a node after\n");
    scanf("%d",&key);
    printf("Enter element to insert after %d in linked list \n",key);
    scanf("%d",&node_data);
    insert_after_element(&head, key, node_data);
    printf("New elements in the list are\n");
    display_linked_list(head);
    printf("Enter the element to insert at the end of the current list\n");
    scanf("%d",&node_data);
    insert_at_the_end_of_list(&head, node_data);
    printf("New elements in the list are\n");
    display_linked_list(head);
#endif
    printf("Enter the position to insert \n");
    scanf("%d",&position);
    insert_at_nth_position(&head,position,10);
    printf("New elements in the list are\n");
    display_linked_list(head);
 	return 0;
}
