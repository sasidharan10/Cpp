#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
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
    temp->left = temp->right = NULL;
    return temp;
}
node *constructTree(vector<int> &v, int n, int &pos, int min, int max)
{
    if (pos >= n)
        return NULL;
    int val = v[pos];
    if (val < min || val > max)
        return NULL;
    node *temp = createNode(val);
    pos++;
    temp->left = constructTree(v, n, pos, min, val);
    temp->right = constructTree(v, n, pos, val, max);
    return temp;
}
node *Preorder(vector<int> &v)
{
    int pos = 0;
    int n = v.size();
    if (n == 0)
        return NULL;
    return constructTree(v, n, pos, INT_MIN, INT_MAX);
}
void print(node *root)
{
    if (root == NULL)
        return;
    print(root->left);
    cout << root->data << " ";
    print(root->right);
}
int main()
{
    vector<int> v{10, 5, 1, 7, 40, 50};
    node *root = Preorder(v);
    cout << "\nTree : ";
    print(root);
    return 0;
}