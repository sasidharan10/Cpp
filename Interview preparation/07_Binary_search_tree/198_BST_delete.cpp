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
    else if (n <= (*root)->data)
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
node *findMin(node *root)
{
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}
node *Delete(node *root, int x)
{
    // Time  :  O(h)
    // Space :  O(1)

    if (root == NULL)
    {
        cout << "Empty Tree!!!";
        return root;
    }
    else if (x < root->data)
        root->left=Delete(root->left, x);
    else if (x > root->data)
        root->right=Delete(root->right, x);
    else
    {
        // case 1 : no chlid
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root=NULL;
        }
        else if (root->left == NULL)
        {
            node *temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root;
            root = root->left;
            delete temp;
        }
        else
        {
            node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
}
void preorder(node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
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
    print(root);
    int x = 4;
    Delete(root, x);
    cout << "\nTree (After deletion) : ";
    print(root);
    cout << "\nTree (After deletion) : ";
    preorder(root);
    return 0;
}