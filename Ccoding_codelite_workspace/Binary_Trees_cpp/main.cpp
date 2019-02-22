#include <iostream>
using namespace std;

struct Node{
    Node *lLink;
    int value;
    Node *rLink;
};

Node *cons(int x){//create new node
    Node *q;
    q = new Node;
    q->lLink = NULL;
    q->value = x;
    q->rLink = NULL;
    return q;
}

Node * readListInter();// read input date and bulid a ninary tree
void preorderPrint(Node *root );
void postorderPrint(Node *root );
void inorderPrint(Node *root );

Node * readListInter(){
    Node* root = NULL;//returning object
    Node* temp;
    Node* input;//new node to add
    int x;
    
    cout << "enter number (>0 to stop): ";
    cin >> x;
    while(x>=0){
        input = cons(x);
        if(root == NULL){//if root is empty
            root = input;
            temp = root;//temp is use to store value for compare
        }
        else{
            temp = root; //for each new addition, must start at root to find correct spot
            while(input != NULL){
                if( x < temp->value){//if smaller x to add to left
                    if(temp->lLink == NULL){//left is empty
                        temp->lLink = input;
                        input = NULL;//new node added, exit the loop
                    }
                    else{//if not empty set temp to subtree
                        temp = temp->lLink;//need to move left from the current position
                    }
                }
                else{//otherwise x add to right
                    if(temp->rLink == NULL){//right is empty
                        temp->rLink = input;
                        input = NULL;//new node added, exit the loop
                    }
                    else{
                        temp = temp->rLink;//need to move right from the current position
                    }
                }
            }
        }
        cin >> x;
    }
    return root;
}

void preorderPrint(Node *root){
    if ( root != NULL ){
        cout << root->value << " ";
        preorderPrint( root->lLink );
        preorderPrint( root->rLink );
    }
}

void postorderPrint(Node *root ){
    if ( root != NULL ){
        postorderPrint( root->lLink );
        postorderPrint( root->rLink );
        cout << root->value << " ";
    }
}

void inorderPrint(Node *root ){
    if ( root != NULL ) {
        inorderPrint( root->lLink );
        cout << root->value << " ";
        inorderPrint( root->rLink );
    }
}

bool search(int x, Node *root){
    if(root==NULL)
        return false;//empty tree
    else if(x == root->value)
        return true;
    else if(x < root->value)
        return search(x, root->lLink);
    else
        return search(x, root->rLink);
}

int main(){
    Node *p;
    p = readListInter();
    
    inorderPrint(p);
    cout << endl;
    postorderPrint(p);
    cout << endl;
    if(search(4,p))
        cout << "found" << endl;
    else
        cout << "not found" << endl;
    system("PAUSE");
}