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
void Diagonal(node *root)
{
    if (root == NULL)
    {
        cout << "Empty!!!" << endl;
        return;
    }
    queue<node *> q;
    vector<int> v;
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
    cout << "\nDiagonal : ";
    for (int i : v)
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
    Diagonal(root);
    return 0;
}