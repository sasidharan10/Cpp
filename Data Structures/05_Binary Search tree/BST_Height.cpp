#include <iostream>
#include <algorithm>
using namespace std;
class bstNode
{
public:
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
int height(bstNode *root)
{
    if (root == NULL)
        return -1;

    int leftHeight = height(root->left) + 1;
    int rightHeight = height(root->right) + 1;
    return max(leftHeight, rightHeight);

    // return max(height(root->left),height(root->right)) +1;
}
int main()
{
    bstNode *root = NULL;
    root = Insert(root, 6);
    root = Insert(root, 5);
    root = Insert(root, 8);
    root = Insert(root, 2);
    root = Insert(root, 9);
    root = Insert(root, 10);
    cout << "\nHeight : " << height(root);
    return 0;
}