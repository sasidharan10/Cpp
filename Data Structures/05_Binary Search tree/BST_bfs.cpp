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
void bfs(bstNode *root)
{
    if (root == NULL)
    {
        cout << "Tree is Empty!!!" << endl;
        return;
    }
    cout << "BFS IS : ";
    queue<bstNode *> q;
    q.push(root);
    while (!q.empty())
    {
        bstNode *current = q.front();
        cout << current->data << " ";
        if (current->left != NULL)
            q.push(current->left);
        if (current->right != NULL)
            q.push(current->right);
        q.pop();
    }
}
int main()
{
    bstNode *root = NULL;
    root = Insert(root, 5);
    root = Insert(root, 3);
    root = Insert(root, 7);
    root = Insert(root, 9);
    root = Insert(root, 1);
    root = Insert(root, 6);
    root = Insert(root, 4);
    bfs(root);
    return 0;
}

/* 

we have to store the child in the queue and then we can print the data from it

*/