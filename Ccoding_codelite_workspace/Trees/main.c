#include <stdio.h>
#include <stdlib.h>

//#define PRINT_ONLY_LEAF_NODES

/*
 *  Main uses of trees include maintaining hierarchical data, providing moderate access and insert/delete operations. 
 * Binary trees are special cases of tree where every node has at most two children.
 */
 
struct node 
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* newNode(int data) 
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void printNodes(struct node *root) 
{
    if(!root)
        return;

#ifdef PRINT_ONLY_LEAF_NODES
    if(!root->left && !root->right)
    {
        printf("%d ",root->data);
        return;
    }
#else
    printf("%d ", root->data);
#endif
    
    if(root->left)
        printNodes(root->left);
        
    if(root->right)
        printNodes(root->right);
}

void readTree(struct node **current) 
{
    struct node *input;
    char initData;
    
    scantf("%c",&initData);
    input = 
}
int main(int argc, char **argv)
{
    struct node *root;
    readTree(&root);
    
    printNodes(root);
}
