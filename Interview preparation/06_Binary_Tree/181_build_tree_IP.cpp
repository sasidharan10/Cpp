#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
class node
{
public:
    char data;
    node *left;
    node *right;
};
node *Insert(char n)
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

unordered_map<char, int> m;
int idx;

node *buildtreeUtil(char *in, char *pre, int lb, int ub)
{
    if (lb > ub)
        return NULL;
    node *temp = Insert(pre[idx++]); // creating node
    if (lb == ub)                    // if no left and right child exists
        return temp;
    int mid = m[temp->data]; // getting index of inorder
    temp->left = buildtreeUtil(in, pre, lb, mid - 1);
    temp->right = buildtreeUtil(in, pre, mid + 1, ub);
    return temp;
}
node *buildtree(char *in, char *pre, int n)
{
    idx = 0;
    m.clear();
    for (int i = 0; i < n; i++)
    {
        m[in[i]] = i;
    }
    return buildtreeUtil(in, pre, 0, n - 1);
}
int main()
{
    char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
    char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
    int n = sizeof(in) / sizeof(in[0]);
    node *root = buildtree(in, pre, n);
    cout << "\nTree : ";
    print(root);
    return 0;
}