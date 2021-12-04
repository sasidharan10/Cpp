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
int ans = 0;
void kthElement(node *root, int k, int &index)
{
    // reverse inorder traveesal
    
    if (root == NULL)
        return;
    kthElement(root->right, k, index);
    if (k == index++)
    {
        ans = root->data;
        return;
    }
    kthElement(root->left, k, index);
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
    cout << "Tree : ";
    inorder(root);
    int k = 3, index = 0;
    kthElement(root, k - 1, index);
    cout << "\n3rd Largest Element : " << ans << endl;
    return 0;
}