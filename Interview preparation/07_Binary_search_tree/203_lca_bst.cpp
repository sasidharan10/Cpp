#include <iostream>
#include <algorithm>
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
    temp->left = temp->right = NULL;
    return temp;
}
void Insert(node **root, int n)
{
    if (*root == NULL)
    {
        *root = createNode(n);
        return;
    }
    else if (n < (*root)->data)
        Insert(&(*root)->left, n);
    else
        Insert(&(*root)->right, n);
}
void print(node *root)
{
    if (root == NULL)
        return;
    print(root->left);
    cout << root->data << " ";
    print(root->right);
}
node *findLCA1(node *root, int a, int b)
{
    // time  : O(h)
    // space : O(h) (stack frame)

    if (root == NULL)
        return NULL;
    if (root->data > a && root->data > b)
        return findLCA1(root->left, a, b);
    if (root->data < a && root->data < b)
        return findLCA1(root->right, a, b);
    return root;
}
int findLCA2(node *root, int a, int b)
{
    // time  : O(h)
    // space : O(1)

    while (root != NULL)
    {
        if (root->data > a && root->data > b)
            root = root->left;
        else if (root->data < a && root->data < b)
            root = root->right;
        else
            break;
    }
    return root->data;
}
int main()
{
    node *root = NULL;
    Insert(&root, 20);
    Insert(&root, 8);
    Insert(&root, 22);
    Insert(&root, 4);
    Insert(&root, 12);
    Insert(&root, 10);
    Insert(&root, 14);
    cout << "Tree : ";
    print(root);
    // node *root1=root;
    node *temp = findLCA1(root, 10, 14);
    cout << "\nAns : " << temp->data;
    cout << "\nAns : " << findLCA2(root, 10, 14);
    return 0;
}
