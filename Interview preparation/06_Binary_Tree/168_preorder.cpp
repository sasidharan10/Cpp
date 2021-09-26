#include <iostream>
#include <algorithm>
#include <stack>
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
void preorder1(node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder1(root->left);
    preorder1(root->right);
}
void preorder2(node *root)
{
    if (root == NULL)
        return;
    stack<node *> s;
    node *current = root;
    s.push(current);
    while (!s.empty())
    {
        current = s.top();
        s.pop();
        cout << current->data << " ";
        if (current->right != NULL)
            s.push(current->right);
        if (current->left != NULL)
            s.push(current->left);
    }
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
    cout << "\nTree (Recursion) : ";
    preorder1(root);
    cout << "\nTree (Iteration) : ";
    preorder2(root);
    return 0;
}