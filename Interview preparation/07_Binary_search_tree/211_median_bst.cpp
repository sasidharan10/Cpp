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

node *createNode(int n)
{
    node *temp = new node();
    temp->data = n;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
void Insert(node **root, int n)
{
    if (*root == NULL)
        *root = createNode(n);
    else if (n < (*root)->data)
        Insert(&(*root)->left, n);
    else
        Insert(&(*root)->right, n);
}

void inorder(node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int countNodes(node *root)
{
    static int count = 0;
    if (root == NULL)
        return 0;
    countNodes(root->left);
    count++;
    countNodes(root->right);
    return count;
}
void findMedian(node *root, node *&cur, node *&prev, int n, int &i)
{
    if (root == NULL)
        return;
    findMedian(root->left, cur, prev, n, i);
    if (prev == NULL)
        prev = root;
    if (n == i++)
    {
        cur = root;
        return;
    }
    else
        prev = root;
    findMedian(root->right, cur, prev, n, i);
}
float median(node *root)
{
    node *cur, *prev = NULL;
    int n = countNodes(root);
    // cout<<"n "<<n<<endl;
    int i = 0;
    findMedian(root, cur, prev, n / 2, i);
    float med;
    if (n % 2 == 0)
        med = (float)(cur->data + prev->data) / 2;
    else
        med = cur->data;
    return med;
}

int main()
{
    node *root = NULL;
    Insert(&root, 4);
    Insert(&root, 2);
    Insert(&root, 1);
    Insert(&root, 3);
    Insert(&root, 6);
    Insert(&root, 5);
    // Insert(&root, 7);

    cout << "\nTree : ";
    inorder(root);
    // cout << "\nMedian : " << median(root);
    cout << "\nMedian : " << median(root);
    return 0;
}