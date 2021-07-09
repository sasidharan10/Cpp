#include <iostream>
#include <algorithm>
using namespace std;
struct bstNode
{
    int data;
    bstNode *left;
    bstNode *right;
};
bstNode *createNode(int data)
{
    bstNode *node = new bstNode();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
bstNode *Insert(bstNode *root, int data)
{
    if (root == NULL)
        root = createNode(data);
    else if (data <= root->data)
        root->left = Insert(root->left, data);
    else
        root->right = Insert(root->right, data);
    return root;
}
bool Search(bstNode *root, int data)
{
    if (root == NULL)
        return false;
    else if (data == root->data)
        return true;
    else if (data <= root->data)
        return Search(root->left, data);
    else
        return Search(root->right, data);
    return false;
}
int main()
{
    bstNode *root = NULL;
    root = Insert(root, 6);
    root = Insert(root, 5);
    root = Insert(root, 8);
    root = Insert(root, 2);
    root = Insert(root, 9);
    if (Search(root, 2))
        cout << "\nElement Found :)" << endl;
    else
        cout << "\nElement Not Found :(" << endl;
    return 0;
}