#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
};
node *Insert(int n)
{
    node *temp = new node();
    temp->data = n;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
int f = 1;
int height(node *root)
{
    if (root == NULL)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    if (abs(lh - rh) > 1)
    {
        f = 0;
        return 0;
    }
    return max(lh, rh) + 1;
}
int isBalanced(node *root)
{
    f = 1;
    height(root);
    return f;
}
int main()
{
    node *root = NULL;
    root = Insert(1);
    root->left = Insert(2);
    root->right = Insert(3);
    root->left->left = Insert(4);
    root->left->right = Insert(5);
    root->right->left = Insert(6);
    root->right->right = Insert(7);
    root->right->right->right = Insert(8);
    // root->right->right->right->right = Insert(9);
    // root->right->right->right->right->right = Insert(10);
    cout << "Balanced : " << isBalanced(root);
    return 0;
}