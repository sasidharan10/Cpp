#include <iostream>
#include <algorithm>
using namespace std;
struct bstNode
{
    int data;
    bstNode *left;
    bstNode *right;
};
bstNode *createNode(int data)
{
    bstNode *node = new bstNode();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
bstNode *Insert(bstNode *root, int data)
{
    if (root == NULL)
        root = createNode(data);
    else if (data <= root->data)
        root->left = Insert(root->left, data);
    else
        root->right = Insert(root->right, data);
    return root;
}
bstNode *Findmin(bstNode *root)
{
    if (root == NULL)
        return root;
    else
    {
        while (root->left != NULL)
        {
            root = root->left;
        }
    }
    return root;
}
bstNode *Find(bstNode *root, int x)
{
    if (root == NULL)
        return root;
    else if (x == root->data)
        return root;
    else if (x < root->data)
        return Find(root->left, x);
    else
        return Find(root->right, x);
}
bstNode *getSuccessor(bstNode *root, int x)
{
    if (root == NULL)
    {
        cout << "Tree is Empty!!!" << endl;
        return root;
    }
    bstNode *current = Find(root, x);
    if (current == NULL)
    {
        cout << "Element Not Found!!!" << endl;
        return root;
    }
    // case 1 : if right child exist
    else if (current->right != NULL)
    {
        return Findmin(current);
    }
    // case 2 : if left child exist
    else
    {
        bstNode *successor = NULL;
        bstNode *ancestor = root;
        while (current != ancestor)
        {
            if (current->data < ancestor->data)
            {
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else
                ancestor = ancestor->right;
        }
        return successor;
    }
}
void inorder(bstNode *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main()
{
    bstNode *root = NULL;
    root = Insert(root, 4);
    root = Insert(root, 6);
    root = Insert(root, 2);
    root = Insert(root, 1);
    root = Insert(root, 3);
    root = Insert(root, 5);
    root = Insert(root, 7);
    cout << "Tree is : ";
    inorder(root);
    int x = 3;
    bstNode *successor = getSuccessor(root, x);
    if (successor != NULL)
        cout << "\nSuccessor of " << x << " is : " << successor->data << endl;
    else
        cout << "\n"
             << x << " has no Successor" << endl;
    return 0;
}