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
void inorder(node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int cnt = 0;
void countRange1(node *root, int l, int h)
{
    if (root == NULL)
        return;
    countRange1(root->left, l, h);
    if (root->data >= l && root->data <= h)
        cnt++;
    countRange1(root->right, l, h);
}
int countRange2(node *root, int l, int h)
{
    if (root == NULL)
        return 0;
    if (root->data >= l && root->data <= h)
        return 1 + countRange2(root->left, l, h) + countRange2(root->right, l, h);
    else if (root->data < l)
        return countRange2(root->right, l, h);
    else
        return countRange2(root->left, l, h);
}
int main()
{
    node *root = NULL;
    Insert(&root, 4);
    Insert(&root, 2);
    Insert(&root, 1);
    Insert(&root, 3);
    Insert(&root, 6);
    Insert(&root, 5);
    Insert(&root, 7);

    cout << "\nTree : ";
    inorder(root);
    int l = 4, h = 7;
    countRange1(root, l, h);
    cout << "\nCount : " << cnt;
    cout << "\nCount (optimised) : " << countRange2(root, l, h);

    return 0;
}