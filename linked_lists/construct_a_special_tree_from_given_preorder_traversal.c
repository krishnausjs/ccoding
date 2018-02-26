//A program to construct binary tree from preorder traversal
#include <stdio.h>

//A binary tree node structure
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

//Utility function to create a new Binary Tree node
struct node* newNode(int data)
{
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node *constructTreeUtil(int pre[], char preLN[],int *index_ptr, int n)
{
    //Store the current value of index in pre[]
    int index = *index_ptr;

    //Base Case: All nodes are constructed
    if(index == n)
        return NULL;

    strut node *temp = newNode( pre[index] );
    (*index_ptr)++;

    if(preLn[index] == 'N')
    {
        temp->left = constructTreeUtil(pre, preLN, index_ptr, n);
        temp->right = constructTreeUtil(pre, preLN, index_ptr, n);
    }
    return temp;
}

struct node *constructTree(int pre[], char preLN[], int n)
{
    int index=0;
    return constructTreeUtil(pre, preLN, &index, n);
}

void printInOder(struct node* node)
{
    if(node == NULL)
        return;

    printInOrder(node->left);
    printf("%d ",node->data);
    printInOrder(node->right);
}

int main()
{
    struct node *root = NULL;
    int pre[] = {10, 30, 20, 5, 15};
    int n = sizeof(pre)/sizeof(pre[0]);

    root = constructTree(pre, preLn, n);
    print("Following is Inorder Traversal of the Constructed Binary tree\n");    
    printInOrder(root);
    return 0;
}
