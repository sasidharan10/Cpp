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

bool comparator(node *r1, node *r2)
{
    return r1->data < r2->data;
}
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
void inorder(node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
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
    node *r1 = NULL;
    node *r2 = NULL;
    Insert(&r1, 3);
    Insert(&r1, 2);
    Insert(&r1, 1);
    Insert(&r1, 4);

    Insert(&r2, 6);
    Insert(&r2, 5);
    Insert(&r2, 7);

    cout << "Tree r1 : ";
    preorder(r1);
    cout << "\nTree r2 : ";
    preorder(r2);
    vector<node *> v;
    storeBst(r2, v);
    storeBst(r1, v);
    int n = v.size();
    cout << "\nElements before : ";
    for (node *i : v)
        cout << i->data << " ";
    sort(v.begin(), v.end(), comparator);
    cout << "\nElements after : ";
    for (node *i : v)
        cout << i->data << " ";
    node *root = balanceBst(v, 0, n - 1);
    cout << "\nBalanced tree (preorder) : ";
    preorder(root);
    cout << "\nBalanced tree (inorder) : ";
    inorder(root);
    return 0;
}