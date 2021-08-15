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
void zigzag(node *root)
{
    queue<node *> q;
    vector<int> ans;
    q.push(root);
    int flag = 0;
    while (!q.empty())
    {
        vector<int> v;
        int n = q.size();
        while (n--)
        {
            node *temp = q.front();
            q.pop();
            v.push_back(temp->data);
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        if (flag)
            reverse(v.begin(), v.end());
        flag = !flag;
        for (int i : v)
            ans.push_back(i);
    }
    cout << "\nZigzag : ";
    for (int i : ans)
        cout << i << " ";
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
    zigzag(root);
    return 0;
}