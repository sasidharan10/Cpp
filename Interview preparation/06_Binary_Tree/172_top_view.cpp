#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
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
void topview(node *root)
{
    // Time  : O(nlogn)  logn for insertion in map
    // Space : O(n)

    queue<pair<node *, int>> q;
    map<int, int> m;
    q.push({root, 0});
    while (!q.empty())
    {
        node *temp = q.front().first;
        int h = q.front().second;
        q.pop();
        if (!m[h])
        {
            m[h] = temp->data;
        }
        if (temp->left)
            q.push({temp->left, h - 1});
        if (temp->right)
            q.push({temp->right, h + 1});
    }
    cout << "Top View : ";
    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << it->second << " ";
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
    topview(root);
    return 0;
}