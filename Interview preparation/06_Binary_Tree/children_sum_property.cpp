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
void print(node *root)
{
    if (root == NULL)
        return;
    print(root->left);
    cout << root->data << " ";
    print(root->right);
}
void convertChildrenSum(node *root)
{
    if (!root)
        return;
    int child = 0;
    if (root->left)
        child += root->left->data;
    if (root->right)
        child += root->right->data;
    if (child >= root->data)
        root->data = child;
    else
    {
        if (root->left)
            root->left->data = root->data;
        if (root->right)
            root->right->data = root->data;
    }
    
    convertChildrenSum(root->left);
    convertChildrenSum(root->right);

    int tot = 0;
    if (root->left)
        tot += root->left->data;
    if (root->right)
        tot += root->right->data;
    if (root->left || root->right)
        root->data = tot;
}
int main()
{
    node *root = NULL;
    root = Insert(4);
    root->left = Insert(2);
    root->left->left = Insert(1);
    root->left->right = Insert(3);
    root->right = Insert(6);
    root->right->left = Insert(5);
    root->right->right = Insert(7);
    cout << "\nList : ";
    print(root);
    convertChildrenSum(root);
    cout << "\nList : ";
    print(root);
    return 0;
}

/*

link: 

leetcode:

*/