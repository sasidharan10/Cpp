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
node *createNode(int n)
{
    node *temp = new node();
    temp->data = n;
    temp->left = temp->right = NULL;
    return temp;
}
void Insert(node **root, int n)
{
    if (*root == NULL)
    {
        *root = createNode(n);
        return;
    }
    else if (n <= (*root)->data)
        Insert(&(*root)->left, n);
    else
        Insert(&(*root)->right, n);
}
void print(node *root)
{
    if (root == NULL)
        return;
    print(root->left);
    cout << root->data << " ";
    print(root->right);
}
node *findMin(node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
node *find(node *root, int x)
{
    if (root == NULL)
        return NULL;
    else if (root->data == x)
        return root;
    else if (x <= root->data)
        return find(root->left, x);
    else
        return find(root->right, x);
}
node *findMax(node *root)
{
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
node *getSuccessor(node *root, int x)
{
    // Time  :  O(h)
    // Space :  O(1)

    node *current = find(root, x);
    if (current == NULL)
    {
        cout << "Tree Empty!!!";
        return root;
    }
    // case 1 : if right subtree exists
    if (current->right != NULL)
    {
        return findMin(current->right);
    }
    // case 2 : no right subtree
    else
    {
        node *successor = NULL;
        node *ancestor = root;
        while (ancestor != current)
        {
            if (current->data < ancestor->data)
            {
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else
                ancestor = ancestor->right;
        }
        return successor;
    }
}
node *getPredecessor(node *root, int x)
{
    // Time  :  O(h)
    // Space :  O(1)

    node *current = find(root, x);
    if (current == NULL)
    {
        cout << "Tree Empty!!!";
        return root;
    }
    if (current->left != NULL)
    {
        return findMax(current->left);
    }
    else
    {
        node *ancestor = root;
        node *predecessor = NULL;
        while (ancestor != current)
        {
            if (current->data > ancestor->data)
            {
                predecessor = ancestor;
                ancestor = ancestor->right;
            }
            else
            {
                ancestor = ancestor->left;
            }
        }
        return predecessor;
    }
}
void findPreSuc(node *root,node **pre,node **suc,int x)
{
    // Time  :  O(h)
    // Space :  O(1)

    if(root==NULL)
        return;
    if(root->data==x)
    {
        if(root->right!=NULL)
            *suc=findMin(root->right);
        if(root->right!=NULL)
            *pre=findMax(root->left);
    }
    else if(x>root->data)
    {
        *pre=root;
        findPreSuc(root->right,&*pre,&*suc,x);
    }
    else
    {
        *suc=root;
        findPreSuc(root->left,&*pre,&*suc,x);
    }
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
    Insert(&root, 7);
    cout << "\nTree : ";
    print(root);
    int x = 6;
    cout << "\nSuccessor : " << getSuccessor(root, x)->data << endl;
    cout << "Predecessor : " << getPredecessor(root, x)->data << endl;
    node *pre=NULL;
    node *suc=NULL;
    findPreSuc(root,&pre,&suc,x);
    cout << "\nSuccessor : " << suc->data << endl;
    cout << "Predecessor : " << pre->data << endl;
    return 0;
}