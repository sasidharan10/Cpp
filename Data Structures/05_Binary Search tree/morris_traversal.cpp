#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class bstNode
{
public:
    int data;
    bstNode *left;
    bstNode *right;
    bstNode(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
void inorder(bstNode *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
vector<int> morrisInorder(bstNode *root)
{
    bstNode *cur = root;
    vector<int> v;
    while (cur)
    {
        // case 1: when there is no left node
        if (cur->left == NULL)
        {
            v.push_back(cur->data);
            cur = cur->right;
        }
        // case 2: when left node exists
        else
        {
            bstNode *prev = cur->left;
            while (prev->right != NULL && prev->right != cur)
            {
                prev = prev->right;
            }
            // create a thread to next node, then move to left.
            if (prev->right == NULL)
            {
                prev->right = cur;
                cur = cur->left;
            }
            // If the thread already exists, remove the thread, move to next node.
            else
            {
                prev->right = NULL;
                v.push_back(cur->data);
                cur = cur->right;
            }
        }
    }
    return v;
}
int main()
{
    bstNode *node = new bstNode(4);
    node->left = new bstNode(2);
    node->left->left = new bstNode(1);
    node->left->right = new bstNode(3);
    node->right = new bstNode(6);
    node->right->left = new bstNode(5);
    node->right->right = new bstNode(7);
    cout << "\nTree is : ";
    inorder(node);
    vector<int> v = morrisInorder(node);
    cout << "\nTree is : ";
    for (auto &&i : v)
        cout << i << " ";
    return 0;
}