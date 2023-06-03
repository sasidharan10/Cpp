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
void postorder1(node *root)
{
    if (root == NULL)
        return;
    postorder1(root->left);
    postorder1(root->right);
    cout << root->data << " ";
}
void postorder2(node *root)
{
    if (root == NULL)
        return;
    stack<node *> s1, s2;
    node *current = root;
    s1.push(current);
    while (!s1.empty())
    {
        current = s1.top();
        s1.pop();
        s2.push(current);
        if (current->left != NULL)
            s1.push(current->left);
        if (current->right != NULL)
            s1.push(current->right);
    }
    while (!s2.empty())
    {
        current = s2.top();
        s2.pop();
        cout << current->data << " ";
    }
}
int main()
{
    node *root = NULL;
    root = Insert(4);
    root->left = Insert(2);
    root->right = Insert(6);
    root->left->left = Insert(1);
    root->left->right = Insert(3);
    root->right->left = Insert(5);
    root->right->right = Insert(7);
    cout << "\nTree (Recursion) : ";
    postorder1(root);
    cout << "\nTree (Iteration) : ";
    postorder2(root);
    return 0;
}