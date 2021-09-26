#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
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
void reverseOrder(node *root)
{
    queue<node *> q;
    vector<int> v;
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        v.push_back(temp->data);
        q.pop();
        if (temp->left != NULL)
            q.push(temp->left);
        if (temp->right != NULL)
            q.push(temp->right);
    }
    reverse(v.begin(), v.end());
    cout << "Reverse Level Order : ";
    for (int i : v)
        cout << i << " ";
}
void reverseOrder2(node *root)
{
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if (temp->right != NULL)
            q.push(temp->right);
        if (temp->left != NULL)
            q.push(temp->left);
    }
}
void reverseOrder3(node *root)
{
    queue<node *> q;
    stack<node *> s;
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        s.push(temp);
        q.pop();
        if (temp->left != NULL)
            q.push(temp->left);
        if (temp->right != NULL)
            q.push(temp->right);
    }
    while (!s.empty())
    {
        cout<<s.top()->data<<" ";
        s.pop();
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
    reverseOrder(root);
    cout << "\nReverse Level Order : ";
    reverseOrder2(root);
    cout << "\nReverse Level Order : ";
    reverseOrder3(root);
    return 0;
}