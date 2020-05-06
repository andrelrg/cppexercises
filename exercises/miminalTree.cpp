//4.2
// Minimal Tree: Given a sorted (increasing order) array with unique integer 
//elements, write an algo- rithm to create a binary search tree with minimal height.

#include <iostream>
#include <stdio.h>

typedef struct node {
    node *left, *right;
    int value;
} Node;

Node *newNode(int value){
    Node *n = new Node;
    n->value = value;
    n->right = NULL;
    n->left = NULL;

    return n;
}


Node *insert(int array[], int start, int end){
    if(start>end){
        return NULL;
    }
    
    int half = (start + end)/2 ;
    printf("creating node: %d\n", half);
    Node *no = newNode(array[half]);


    no->left = insert(array, start, half-1);
    if (no->left)
        printf("left of node: %d is %d\n", half, no->left->value);
    no->right = insert(array, half+1, end);
    if (no->right)
        printf("right of node: %d is %d\n", half, no->right->value);
    return no;
}

void preOrder(Node* node)  
{  
    if (node == NULL)  
        return;  
    printf("%d\n", node->value);
    preOrder(node->left);  
    preOrder(node->right);  
}  

int main(){
    int array[7] = {1, 2, 3, 4, 5, 6, 7};
    Node *root = insert(array, 0, 6);
    preOrder(root); 
}