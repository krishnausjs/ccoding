#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int data;
    struct node* left;
    struct node* right;
};

void printKDistant(struct node *root, int k)
{
    if(root == NULL)
        return;
    if(k == 0)
    {
        printf("%d ",root->data);
        return;
    }
    else
    {
        printKDistant(root->left, k-1);
        printKDistant(root->right, k-1);
    }
    printf("\n");
}

struct node* newNode(int data)
{
    struct node *node = (struct node*) \
                        malloc(sizeof(struct node));

    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

int main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->right = newNode(5);
    root->right->left = newNode(8);

    printKDistant(root, 2);
    return 0;
}
