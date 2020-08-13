#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define LOP(i,j,n) for(int i = j; i<n; i++)
#define MOD 1000000007
#define mp make_pair
#define pb push_back
#define FOREACH(it, l) for(auto it = l.begin(); it!= l.end(); it++)

// The following code is from Geeks for Geeks, you can check it out here at
// https://www.geeksforgeeks.org/serialize-deserialize-binary-tree/
struct Node 
{ 
    int val; 
    struct Node* left, *right; 
}; 

Node* newNode(int val) 
{ 
    Node* temp = new Node; 
    temp->val = val; 
    temp->left = temp->right = NULL; 
    return (temp); 
} 

void serialize(Node *root, FILE *fp) 
{ 
    if (root == NULL) 
    { 
        fprintf(fp, "%d ", -1); 
        return; 
    } 
    fprintf(fp, "%d ", root->key); 
    serialize(root->left, fp); 
    serialize(root->right, fp); 
} 

void deSerialize(Node *&root, FILE *fp) 
{ 

    int val; 
    if ( !fscanf(fp, "%d ", &val) || val == -1) 
       return; 

    root = newNode(val); 
    deSerialize(root->left, fp); 
    deSerialize(root->right, fp); 
} 

void inorder(Node *root) 
{ 
    if (root) 
    { 
        inorder(root->left); 
        printf("%d ", root->val); 
        inorder(root->right); 
    } 
} 
int main(){
    // A simple solution is to store both Inorder and Preorder traversals. 
    // This solution requires requires space twice the size of Binary Tree.
    // We can save space by storing Preorder traversal and a marker for NULL pointers.
    struct Node *root        = newNode(20); 
    root->left               = newNode(8); 
    root->right              = newNode(22); 
    root->left->left         = newNode(4); 
    root->left->right        = newNode(12); 
    root->left->right->left  = newNode(10); 
    root->left->right->right = newNode(14); 
  
    // Let us open a file and serialize the tree into the file 
    FILE *fp = fopen("tree.txt", "w"); 
    if (fp == NULL) 
    { 
        puts("Could not open file"); 
        return 0; 
    } 
    serialize(root, fp); 
    fclose(fp); 
  
    // Let us deserialize the storeed tree into root1 
    Node *root1 = NULL; 
    fp = fopen("tree.txt", "r"); 
    deSerialize(root1, fp); 
  
    printf("Inorder Traversal of the tree constructed from file:\n"); 
    inorder(root1); 
  
    return 0;
    

}