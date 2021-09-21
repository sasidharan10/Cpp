#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int n = 0;

struct Node{
	int data;
	Node *left, *right;
};


// Getting new node for tree
Node *insertNode(int data){
	Node *newNode = new Node;
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}


// Binary Tree construction from preorder traversal
Node* build(int *preorder, int &pos, int min, int max){
    if (pos >= n) 
        return NULL;
    
    int val = preorder[pos];
    
    if (val > max || val <min) 
        return NULL;
    
    Node* node = insertNode(val);
    
    pos++;
    node->left = build(preorder, pos, min, val);
    node->right = build(preorder, pos, val, max);
    
    return node;
}



// Check for base condition before constructing tree 
Node* constructTree(int *preorder){
    if(n == 0) 
        return NULL;
    
    int pos = 0;
    return build(preorder, pos, INT_MIN, INT_MAX);
}



// Print the Ans : Inorder Traversal
void printInorder(Node* node){
    if (node == NULL)
        return;
    
    printInorder(node->left);
    
    cout << node->data << " ";
    
    printInorder(node->right);
}


int main(){

    int pre[] = { 10, 5, 1, 7, 40, 50 };
    int size = sizeof(pre) / sizeof(pre[0]);
    n = size;
 
    Node* root = constructTree(pre);
 
    cout << "Inorder traversal of the constructed tree: \n";
    printInorder(root);
 
    return 0;

}