#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
void getElement(node *root, vector<int> &ans)
{
    if (root == NULL)
        return;
    getElement(root->left, ans);
    ans.push_back(root->data);
    getElement(root->right, ans);
}
void convert(node *root, vector<int> ans, int &index)
{
    if (root == NULL)
        return;
    convert(root->left, ans, index);
    root->data = ans[index++];
    convert(root->right, ans, index);
}
void inorder(node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main()
{
    node *root = NULL;
    root = new node(1);
    root->left = new node(2);
    root->right = new node(6);
    root->left->left = new node(5);
    root->left->right = new node(7);
    root->right->left = new node(3);
    root->right->right = new node(4);
    cout << "Tree : ";
    inorder(root);
    vector<int> ans;
    getElement(root, ans);
    cout << "\nElements : ";
    for (int i : ans)
        cout << i << " ";
    int i = 0;
    sort(ans.begin(), ans.end());
    convert(root, ans, i);
    cout << "\nTree : ";
    inorder(root);
    return 0;
}
