#include <iostream>
#include <algorithm>
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
void print(node *root)
{
    if (root == NULL)
        return;
    print(root->left);
    cout << root->data << " ";
    print(root->right);
}
int sumTree(node *root)
{
    if (root == NULL)
        return 0;
    int old = root->data;
    root->data = sumTree(root->left) + sumTree(root->right);
    return root->data + old;
}
int main()
{
    node *root = NULL;
    root = Insert(4);
    root->left = Insert(2);
    root->right = Insert(6);
    root->left->right = Insert(3);
    root->left->left = Insert(1);
    root->right->left = Insert(5);
    root->right->right = Insert(7);
    cout << "\nList : ";
    print(root);
    sumTree(root);
    cout << "\nList : ";
    print(root);
    return 0;
}