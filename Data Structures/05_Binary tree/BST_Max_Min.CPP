#include <iostream>
#include <algorithm>
using namespace std;
class bstNode
{
public:
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
int findMin(bstNode *root)
{
    if (root == NULL)
    {
        cout << "Tree is Empty!!!" << endl;
        return -1;
    }
    else if (root->left != NULL)
        return findMin(root->left);
    else
        return root->data;
}
int findMax(bstNode *root)
{
    if (root == NULL)
    {
        cout << "Tree is Empty!!!" << endl;
        return -1;
    }
    else if (root->right != NULL)
        return findMax(root->right);
    else
        return root->data;
}
int main()
{
    bstNode *root = NULL;
    root = Insert(root, 6);
    root = Insert(root, 5);
    root = Insert(root, 8);
    root = Insert(root, 2);
    root = Insert(root, 9);
    cout << "Max is : " << findMax(root) << endl;
    cout << "Min is : " << findMin(root) << endl;
    return 0;
}