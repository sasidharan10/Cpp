#include <iostream>
#include <algorithm>
using namespace std;
class bstNode
{
public:
    int data;
    bstNode *left;
    bstNode *right;
    bstNode(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
void inorder(bstNode *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main()
{
    bstNode *node = new bstNode(4);
    node->left = new bstNode(2);
    node->left->left = new bstNode(1);
    node->left->right = new bstNode(3);
    node->right = new bstNode(6);
    node->right->left = new bstNode(5);
    node->right->right = new bstNode(7);
    cout << "Tree is : ";
    inorder(node);
    return 0;
}