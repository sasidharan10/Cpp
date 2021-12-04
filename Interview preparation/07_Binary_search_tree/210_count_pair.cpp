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
bool search(node *root, int k)
{
    if (root == NULL)
        return false;
    else if (k == root->data)
        return true;
    else if (k < root->data)
        return search(root->left, k);
    else
        return search(root->right, k);
}
int cnt = 0;
int countPairs(node *r1, node *r2, int k)
{
    if (r1 == NULL)
        return cnt;
    countPairs(r1->left, r2, k);
    if (search(r2, (k - r1->data)))
        cnt++;
    countPairs(r1->right, r2, k);
    return cnt;
}

int main()
{
    node *r1 = NULL;
    node *r2 = NULL;
    Insert(&r1, 5);
    Insert(&r1, 3);
    Insert(&r1, 2);
    Insert(&r1, 4);
    Insert(&r1, 7);
    Insert(&r1, 6);
    Insert(&r1, 8);

    Insert(&r2, 10);
    Insert(&r2, 6);
    Insert(&r2, 15);
    Insert(&r2, 3);
    Insert(&r2, 8);
    Insert(&r2, 11);
    Insert(&r2, 18);
    cout << "Tree 1 : ";
    inorder(r1);
    cout << "\nTree 2 : ";
    inorder(r2);
    cout << "\ncount : " << countPairs(r1, r2, 14);
    return 0;
}