#include <iostream>
#include <algorithm>
#include <queue>
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
        left = nullptr;
        right = nullptr;
    }
};
bstNode *insertNode(bstNode *root, int val)
{
    if (root == nullptr)
    {
        bstNode *temp = new bstNode(val);
        return temp;
    }
    if (val <= root->data)
        root->left = insertNode(root->left, val);
    else
        root->right = insertNode(root->right, val);
    return root;
}
void inorder(bstNode *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void bfs(bstNode *root)
{
    queue<bstNode *> q;
    q.push(root);
    while (!q.empty())
    {
        bstNode *current = q.front();
        cout << current->data << " ";
        if (current->left)
            q.push(current->left);
        if (current->right)
            q.push(current->right);
        q.pop();
    }
}
bstNode *findMin(bstNode *root)
{
    while (root->left)
    {
        root = root->left;
    }
    return root;
}
bstNode *deleteNode(bstNode *root, int val)
{
    if (val < root->data)
        root->left = deleteNode(root->left, val);
    else if (val > root->data)
        root->right = deleteNode(root->right, val);
    else if (root->data == val)
    {
        if (!root->left && !root->right)
        {
            bstNode *temp = root;
            delete temp;
            root = nullptr;
        }
        else if (!root->left)
        {
            bstNode *temp = root;
            root = root->right;
            delete temp;
        }
        else if (!root->right)
        {
            bstNode *temp = root;
            root = root->left;
            delete temp;
        }
        else
        {
            bstNode *temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}
int main()
{
    bstNode *root = nullptr;
    root = insertNode(root, 4);
    root = insertNode(root, 2);
    root = insertNode(root, 1);
    root = insertNode(root, 3);
    root = insertNode(root, 6);
    root = insertNode(root, 5);
    root = insertNode(root, 7);
    inorder(root);
    cout << endl;
    bfs(root);
    cout << endl;
    root = deleteNode(root, 6);
    bfs(root);
    return 0;
}