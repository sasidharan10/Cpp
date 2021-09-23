#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int n)
    {
        data = n;
        left = right = NULL;
    }
};
void Insert(node **root, int n)
{
    node *temp = new node(n);
    if (*root == NULL)
    {
        *root = temp;
        return;
    }
    if ((*root)->left == NULL)
        Insert(&(*root)->left, n);
    else
        Insert(&(*root)->right, n);
}
void print(node *root)
{
    if (root == NULL)
        return;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
}
int main()
{
    node *root = NULL;
    Insert(&root, 1);
    Insert(&root, 2);
    Insert(&root, 3);
    Insert(&root, 4);
    Insert(&root, 5);
    Insert(&root, 6);
    cout << "\nTree : ";
    print(root);
    return 0;
}