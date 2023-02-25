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
bstNode *createNode(int x)
{
    bstNode *node = new bstNode();
    node->data = x;
    node->left = node->right = NULL;
    return node;
}
bstNode *Insert(bstNode *root, int x)
{
    if (root == NULL)
        root = createNode(x);
    else if (x <= root->data)
        root->left = Insert(root->left, x);
    else
        root->right = Insert(root->right, x);
    return root;
}
bstNode *Findmin(bstNode *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
bstNode *Delete(bstNode *root, int x)
{
    if (root == NULL)
    {
        cout << "\nTree is Empty!!!" << endl;
        return root;
    }
    else if (x < root->data)
        root->left = Delete(root->left, x);
    else if (x > root->data)
        root->right = Delete(root->right, x);
    else // we got the element that to be deleted
    {
        // case 1 : No Child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        // case 2 : One Child
        else if (root->left == NULL)
        {
            bstNode *temp = root;
            root = root->right; // linking the nodes
            delete temp;
        }
        else if (root->right == NULL)
        {
            bstNode *temp = root;
            root = root->left; // linking the nodes
            delete temp;
        }
        // case 2 : Two Child
        else
        {
            bstNode *temp;
            temp = Findmin(root->right);
            root->data = temp->data;                       // assigning the minimum value in the deeted area
            root->right = Delete(root->right, temp->data); // sending the sub-tree for deleting the duplicate
        }
    }
    return root;
}
void Inorder(bstNode *root)
{
    if (root == NULL)
        return;
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
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
    cout << "\nBST is : ";
    Inorder(root);
    root = Delete(root, 3);
    root = Delete(root, 2);
    cout << "\nBST is (After deletion): ";
    Inorder(root);
    return 0;
}