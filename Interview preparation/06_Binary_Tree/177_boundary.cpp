#include <iostream>
#include <algorithm>
#include <vector>
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
void left(node *root, vector<int> &v)
{
    if (root == NULL)
        return;
    if (root->left)
    {
        v.push_back(root->data);
        left(root->left, v);
    }
    else if (root->right)
    {
        v.push_back(root->data);
        left(root->right, v);
    }
}
void leaf(node *root, vector<int> &v)
{
    if (root == NULL)
        return;
    leaf(root->left, v);
    if (root->left == NULL && root->right == NULL)
        v.push_back(root->data);
    leaf(root->right, v);
}
void right(node *root, vector<int> &v)
{
    if (root == NULL)
        return;
    if (root->right)
    {
        right(root->right, v);
        v.push_back(root->data);
    }
    else if (root->left)
    {
        right(root->left, v);
        v.push_back(root->data);
    }
}
void boundary(node *root)
{
    if (root == NULL)
        return;
    vector<int> v;
    v.push_back(root->data);
    left(root->left, v);
    leaf(root, v);
    right(root->right, v);
    cout << "\nBoundary : ";
    for (int i : v)
        cout << i << " ";
}
int main()
{
    node *root = NULL;
    root = Insert(1);
    root->left = Insert(2);
    root->right = Insert(3);
    root->left->left = Insert(4);
    root->right->right = Insert(6);
    root->left->right = Insert(5);
    root->left->right->left = Insert(7);
    root->left->right->right = Insert(8);
    boundary(root);
    return 0;
}