#include <iostream>
#include <algorithm>
using namespace std;
struct bstNode
{
    int data;
    bstNode *left;
    bstNode *right;
};
bstNode *createNode(int x)
{
    bstNode *node = new bstNode();
    node->data = x;
    node->left =node->right= NULL;
    return node;
}
bstNode *Insert(bstNode *root, int x)
{
    if (root == NULL)
        root = createNode(x);
    else if (x <= root->data)
        root->left = Insert(root->left, x);
    else
        root->right = Insert(root->right, x);
    return root;
}
void preorder(bstNode *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(bstNode *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void postorder(bstNode *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
int main()
{
    bstNode *root = NULL;
    root = Insert(root, 4);
    root = Insert(root, 6);
    root = Insert(root, 2);
    root = Insert(root, 1);
    root = Insert(root, 3);
    root = Insert(root, 5);
    root = Insert(root, 7);
    cout << "\nPreorder : ";
    preorder(root);
    cout << "\nInorder : ";
    inorder(root);
    cout << "\nPostorder : ";
    postorder(root);
    return 0;
}