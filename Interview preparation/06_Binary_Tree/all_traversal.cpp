#include <iostream>
#include <algorithm>
#include <vector>
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
void print(node *root)
{
    if (root == NULL)
        return;
    print(root->left);
    cout << root->data << " ";
    print(root->right);
}
void allTraversal(node *root)
{
    vector<int> preOrder;
    vector<int> inOrder;
    vector<int> postOrder;
    stack<pair<node *, int>> s;
    s.push({root, 1});
    while (!s.empty())
    {
        pair<node *, int> p = s.top();
        s.pop();
        if (p.second == 1)
        {
            preOrder.push_back(p.first->data);
            p.second++;
            s.push({p.first, p.second});
            if (p.first->left)
                s.push({p.first->left, 1});
        }
        else if (p.second == 2)
        {
            inOrder.push_back(p.first->data);
            p.second++;
            s.push({p.first, p.second});
            if (p.first->right)
                s.push({p.first->right, 1});
        }
        else
        {
            postOrder.push_back(p.first->data);
        }
    }
    cout << "\nPreorder: ";
    for (auto &&i : preOrder)
    {
        cout << i << " ";
    }
    cout << "\nInorder: ";
    for (auto &&i : inOrder)
    {
        cout << i << " ";
    }
    cout << "\nPostorder: ";
    for (auto &&i : postOrder)
    {
        cout << i << " ";
    }
}
int main()
{
    node *root = NULL;
    root = Insert(4);
    root->left = Insert(2);
    root->left->left = Insert(1);
    root->left->right = Insert(3);
    root->right = Insert(6);
    root->right->left = Insert(5);
    root->right->right = Insert(7);
    cout << "\nList : ";
    print(root);
    allTraversal(root);
    // cout << "\nList : ";
    // print(root);
    return 0;
}

/*

link: https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1

leetcode:

*/

// root = Insert(10);
// root->left = Insert(-2);
// root->right = Insert(6);
// root->left->left = Insert(8);
// root->left->right = Insert(-4);
// root->right->left = Insert(7);
// root->right->right = Insert(5);

// 0 4 0 20 0 12 0
