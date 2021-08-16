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
bool checkBstUtil1(node *root, int min, int max)
{
    if (root == NULL)
        return true;
    else if (root->data > min && root->data < max && checkBstUtil1(root->left, min, root->data) && checkBstUtil1(root->right, root->data, max))
        return true;
    else
        return false;
}
bool checkBst1(node *root)
{
    return checkBstUtil1(root, INT_MIN, INT_MAX);
}
bool checkBstUtil2(node *root, node *&prev)
{
    if (root == NULL)
        return true;
    if (!checkBstUtil2(root->left, prev))
        return false;
    else if (prev != NULL && root->data <= prev->data)
        return false;
    prev = root;
    return checkBstUtil2(root->right, prev);
}
bool checkBst2(node *root)
{
    node *prev = NULL;
    return checkBstUtil2(root, prev);
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
    cout << "\nBST ? : " << checkBst1(root);
    cout << "\nBST ? : " << checkBst2(root);
    return 0;
}