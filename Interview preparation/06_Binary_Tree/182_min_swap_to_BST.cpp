#include <iostream>
#include <algorithm>
#include <vector>
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
void minSwapUtil(node *root, vector<int> &v)
{
    if (root == NULL)
        return;
    minSwapUtil(root->left, v);
    v.push_back(root->data);
    minSwapUtil(root->right, v);
}
int minSwap1(node *root)
{
    // Time  : O(nlogn)
    // Space : O(n)

    vector<int> a;
    minSwapUtil(root, a);

    int n = a.size();
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        v[i] = {a[i], i};
    }
    sort(v.begin(), v.end());
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i].second == i)
            continue;
        else
        {
            count++;
            swap(v[i], v[v[i].second]);
            i--;
        }
    }
    return count;
}
void inorder(int *a, vector<int> &v, int n, int index)
{
    if (index >= n)
        return;
    inorder(a, v, n, (2 * index) + 1);
    v.push_back(a[index]);
    inorder(a, v, n, (2 * index) + 2);
}
int minSwap2(vector<int> a)
{
    int n = a.size();
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        v[i] = {a[i], i};
    }
    sort(v.begin(), v.end());
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i].second == i)
            continue;
        else
        {
            count++;
            swap(v[i], v[v[i].second]);
            i--;
        }
    }
    return count;
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
    cout << "\nMin Swap  : " << minSwap1(root);

    // If only array given :

    int a[] = {5, 6, 7, 8, 9, 10, 11};
    int n = sizeof(a) / sizeof(a[0]);
    vector<int> v;
    int index = 0;
    inorder(a, v, n, index);
    cout << "\nMin Swap  : " << minSwap2(v) << endl;
    return 0;
}