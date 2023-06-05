#include <iostream>
#include <algorithm>
#include <vector>
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
vector<int> Diagonal(node *root)
{
    vector<int> v;
    if (root == NULL)
    {
        return v;
    }
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        while (temp)
        {
            if (temp->left)
                q.push(temp->left);
            v.push_back(temp->data);
            temp = temp->right;
        }
    }
    return v;
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
    vector<int> v = Diagonal(root);
    cout << "\nDiagonal : ";
    for (int i : v)
        cout << i << " ";
    return 0;
}

/*

link: https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1

leetcode:

*/