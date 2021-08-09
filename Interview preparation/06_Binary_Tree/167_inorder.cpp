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
void inorder1(node *root)
{
    if (root == NULL)
        return;
    inorder1(root->left);
    cout << root->data << " ";
    inorder1(root->right);
}
void inorder2(node *root)
{
    stack<node *> s;
    node *current = root;
    while (current != NULL || !s.empty())
    {
        while (current != NULL)
        {
            s.push(current);
            current = current->left;
        }
        current = s.top();
        s.pop();
        cout << current->data << " ";
        current = current->right;
    }
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
    cout << "\nTree (Recursion) : ";
    inorder1(root);
    cout << "\nTree (Iteration) : ";
    inorder2(root);
    return 0;
}