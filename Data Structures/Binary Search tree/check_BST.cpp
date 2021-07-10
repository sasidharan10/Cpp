#include <iostream>
#include <algorithm>
#include <climits>
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
bool Isbst1Util(bstNode *root, int min, int max)
{
    if (root == NULL)
        return true;
    else if (root->data > min && root->data < max && Isbst1Util(root->left, min, root->data) && Isbst1Util(root->right, root->data, max))
        return true;
    else
        return false;
}
bool Isbst1(bstNode *root)
{
    return Isbst1Util(root, INT_MIN, INT_MAX);
}
bool Isbst2(bstNode *root)
{
    static bstNode *prev = NULL;
    if (root == NULL)
        return true;
    else
    {
        if (!Isbst2(root->left))
            return false;
        if (prev != NULL && root->data <= prev->data)
            return false;
        prev = root;
        return Isbst2(root->right);
    }
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
    if (Isbst1(node))
        cout << "\nIt is BST :)" << endl;
    else
        cout << "\nIt is Not BST :(" << endl;
    if (Isbst2(node))
        cout << "\nIt is BST :)" << endl;
    else
        cout << "\nIt is Not BST :(" << endl;
    return 0;
}