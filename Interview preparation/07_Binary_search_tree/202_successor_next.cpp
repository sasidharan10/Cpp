#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node *next;
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
void fillNext(node *root, node *&prev)
{
    if (root == NULL)
        return;
    fillNext(root->left, prev);
    if (prev != NULL)
        prev->next = root;
    prev = root;
    fillNext(root->right, prev);
}
void printList(node *root)
{
    cout << "\nList : ";
    while (root->left != NULL)
    {
        root = root->left;
    }
    while (root != NULL)
    {
        cout << root->data << " ";
        root = root->next;
    }
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
    node *prev = NULL;
    fillNext(root, prev);
    printList(root);
    // cout << "\nBST ? : " << checkBst1(root);
    return 0;
}