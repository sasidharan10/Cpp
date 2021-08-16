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
bool find(node *root, int x)
{
    // Time  :  O(h) or O(logn)
    // Space :  O(1)

    if (root == NULL)
        return false;
    if (x == root->data)
        return true;
    else if (x < root->data)
        return find(root->left, x);
    else
        return find(root->right, x);
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
    int x = 6;
    cout << "\nValue X ? : " << find(root, x);
    return 0;
}