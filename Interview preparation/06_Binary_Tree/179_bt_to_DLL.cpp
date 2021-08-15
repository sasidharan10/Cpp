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
void convertUtil(node *root, node *&head, node *&prev, int &f)
{
    if (root == NULL)
        return;
    convertUtil(root->left, head, prev, f);
    if (f == 0)
    {
        f = 1;
        head = root;
        prev = root;
    }
    else
    {
        prev->right = root;
        prev->right->left = prev;
        prev = root;
    }
    convertUtil(root->right, head, prev, f);
}
node *convert(node *root)
{
    node *head = NULL;
    node *prev = NULL;
    int f = 0;
    convertUtil(root, head, prev, f);
    return head;
}
void print(node *head)
{
    if (head == NULL)
        return;
    cout << "\nDLL Traversal : ";
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->right;
    }
}
int main()
{
    node *root = NULL;
    root = Insert(4);
    root->left = Insert(2);
    root->right = Insert(6);
    root->left->right = Insert(3);
    root->left->left = Insert(1);
    root->right->left = Insert(5);
    root->right->right = Insert(7);
    node *head = convert(root);
    print(head);
    return 0;
}