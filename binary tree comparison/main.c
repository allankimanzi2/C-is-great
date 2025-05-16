#include <stdio.h>
#include <stdlib.h>

// Defining node structure
struct Node    {
    int data;
    
    struct Node *left;
    struct Node *right;

};

// Function to create a new node
struct Node* createNode(int data)    {
    
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to count number of nodes in a tree
int countNodes(struct Node* root)   {
    
    if (root == NULL)
        return 0;
    return 1 + countNodes(root ->left) + countNodes(root->right);
}

// Function to compare 3 trees and print the one with most nodes
void compareBinaryTree(struct Node* A, struct Node* B, struct Node* C)  {
    int countA = countNodes(A);
    int countB = countNodes(B);
    int countC = countNodes(C);

    
    printf("Node count:\nTree A: %d\nTree B: %d\nTree C: %d\n", countA, countB, countC);

    if (countA >= countB && countA >= countC)
        printf("Tree A has the highest number of nodes.\n");
    else if (countB >= countA && countB >= countC)
        printf("Tree B has the highest number of nodes.\n");
    else
        printf("Tree C has the highest number of nodes.\n");
}

// Sample (test) data
int main()   { 
    // Tree A
   
    struct Node* A = createNode(1);
    A->left = createNode(2);
    A->right = createNode(3);
    A->left->left = createNode(4);

    // Tree B
    
    struct Node* B = createNode(10);
    B->left = createNode(20);
    B->right = createNode(30);

    // Tree C
    
    struct Node* C = createNode(5);
    C->left = createNode(6);
    C->right = createNode(7);
    C->left->left = createNode(8);
    C->left->right = createNode(9);
    C->right->left = createNode(10);

    // Compare trees
    compareBinaryTree(A, B, C);

    return 0;
}
