#include <iostream>
#include <algorithm>
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
void leftview(node *root, int current, int &maxLevel)
{
    if (root == NULL)
        return;
    if (current > maxLevel)
    {
        cout << root->data << " ";
        maxLevel = current;
    }
    leftview(root->right, current + 1, maxLevel);
    leftview(root->left, current + 1, maxLevel);
}
void leftview1(node *root)
{
    int maxLevel = 0;
    leftview(root, 1, maxLevel);
}
void leftview2(node *root)
{
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        while (n--)
        {
            node *temp = q.front();
            q.pop();
            if (n == 0)
                cout << temp->data << " ";

            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
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
    root->left->right->right = Insert(10);
    root->left->right->right->right = Insert(11);
    root->right->left = Insert(6);
    root->right->right = Insert(7);
    cout << "Left View (Recursion) : ";
    leftview1(root);
    cout << "\nLeft View (Iteration) : ";
    leftview2(root);
    return 0;
}