#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
};
Node *Insert(int n)
{
    Node *temp = new Node();
    temp->data = n;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
void print(Node *root)
{
    if (root == NULL)
        return;
    print(root->left);
    cout << root->data << " ";
    print(root->right);
}
void getParent(Node *root, unordered_map<Node *, Node *> &parent)
{
    if (!root)
        return;
    if (root->left)
        parent[root->left] = root;
    if (root->right)
        parent[root->right] = root;
    getParent(root->left, parent);
    getParent(root->right, parent);
}
Node *searchNode(Node *root, int target)
{
    if (!root)
        return root;
    if (root->data == target)
        return root;

    Node *lt = searchNode(root->left, target);
    Node *rt = searchNode(root->right, target);
    if (!lt)
        return rt;
    if (!rt)
        return lt;
}
int minTime(Node *root, int target)
{
    int t = 0;
    queue<Node *> q;
    unordered_map<Node *, Node *> parent;
    unordered_map<Node *, bool> visited;
    getParent(root, parent);
    Node *targetNode = searchNode(root, target);
    visited[targetNode] = true;
    q.push(targetNode);
    while (!q.empty())
    {
        t++;
        int n = q.size();
        while (n--)
        {
            Node *temp = q.front();
            q.pop();

            // left
            if (temp->left && !visited[temp->left])
            {
                q.push(temp->left);
                visited[temp->left] = true;
            }

            // right
            if (temp->right && !visited[temp->right])
            {
                q.push(temp->right);
                visited[temp->right] = true;
            }

            // top
            if (parent[temp] && !visited[parent[temp]])
            {
                q.push(parent[temp]);
                visited[parent[temp]] = true;
            }
        }
    }
    return t-1;
}
int main()
{
    Node *root = NULL;
    root = Insert(4);
    root->left = Insert(2);
    root->left->left = Insert(1);
    root->left->right = Insert(3);
    root->right = Insert(6);
    root->right->left = Insert(5);
    root->right->right = Insert(7);
    cout << "\nList : ";
    print(root);
    cout << "\nTime to burn all the nodes of a tree : " << minTime(root, 1);
    return 0;
}

/*

link: https://practice.geeksforgeeks.org/problems/burning-tree/1

leetcode:

algorithm:

- we do a level order traversal, and increament the time, everytime we move to next node.
- to travel upwards, we use a map to store the parent nodes of every nodes.
- We mark the nodes as visited, since we will be going on all three directions.

*/