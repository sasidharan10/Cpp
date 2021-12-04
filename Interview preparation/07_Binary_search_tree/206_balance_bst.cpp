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
};
node *createNode(int n)
{
    node *temp = new node();
    temp->data = n;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
void Insert(node **root, int n)
{
    if (*root == NULL)
        *root = createNode(n);
    else if (n < (*root)->data)
        Insert(&(*root)->left, n);
    else
        Insert(&(*root)->right, n);
}
void preorder(node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void storeBst(node *root, vector<node *> &v)
{
    if (root == NULL)
        return;
    storeBst(root->left, v);
    v.push_back(root);
    storeBst(root->right, v);
}
node *balanceBst(vector<node *> v, int start, int end)
{
    if (start > end)
        return NULL;
    int mid = start + (end - start) / 2;
    node *root = v[mid];
    root->left = balanceBst(v, start, mid - 1);
    root->right = balanceBst(v, mid + 1, end);
    return root;
}
int main()
{
    node *root = NULL;
    Insert(&root, 7);
    Insert(&root, 6);
    Insert(&root, 5);
    Insert(&root, 4);
    Insert(&root, 3);
    Insert(&root, 2);
    Insert(&root, 1);
    cout << "Tree before balancing : ";
    preorder(root);
    vector<node *> v;
    storeBst(root, v);
    int n = v.size();
    root = balanceBst(v, 0, n - 1);
    cout << "\nTree after balancing : ";
    preorder(root);
    return 0;
}