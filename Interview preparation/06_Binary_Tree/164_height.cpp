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
node *Insert(int n)
{
    node *temp = new node();
    temp->data = n;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
int height1(node *root)
{
    if (root == NULL)
        return 0;
    // return 0 for no of nodes, return -1 for no of edges
    int leftHeight = height1(root->left);
    int rightHeight = height1(root->right);
    return max(leftHeight, rightHeight) + 1;
}
int height2(node *root)
{
    if (root == NULL)
        return 0;
    return max(height2(root->left), height2(root->right)) + 1;
}
int main()
{
    node *root = NULL;
    root = Insert(1);
    root->left = Insert(2);
    root->right = Insert(3);
    root->left->left = Insert(4);
    root->left->right = Insert(5);
    root->right->left = Insert(6);
    root->right->right = Insert(7);
    cout << "Height : " << height1(root) << endl;
    cout << "Height : " << height2(root) << endl;
    return 0;
}