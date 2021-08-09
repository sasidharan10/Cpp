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
void bottomview(node *root)
{
    queue<pair<node *, int>> q;
    map<int, int> m;
    q.push({root, 0});
    while (!q.empty())
    {
        node *temp = q.front().first;
        int h = q.front().second;
        q.pop();
        m[h] = temp->data;
        if (temp->left)
            q.push({temp->left, h - 1});
        if (temp->right)
            q.push({temp->right, h + 1});
    }
    cout << "\nBottom View : ";
    for (auto it : m)
        cout << it.second << " ";
}
int main()
{
    node *root = NULL;
    root = Insert(20);
    root->left = Insert(8);
    root->right = Insert(22);
    root->left->left = Insert(5);
    root->left->right = Insert(3);
    root->right->left = Insert(4);
    root->right->right = Insert(25);
    root->left->right->left = Insert(10);
    root->left->right->right = Insert(14);
    // 5 10 4 14 25
    bottomview(root);
    return 0;
}