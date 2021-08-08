#include<iostream>
#include<algorithm>
using namespace std;
class bstNode
{
    public:
    int data;
    bstNode* left;
    bstNode* right;
};
bstNode *Insert(int n)
{
    bstNode *temp = new bstNode();
    temp->data=n;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
void print(bstNode *root)
{
    if(root==NULL)
        return;
    print(root->left);
    cout<<root->data<<" ";
    print(root->right);
}
int main()
{
    bstNode *root=NULL;
    root=Insert(6);
    root->left=Insert(3);
    root->right=Insert(8);
    root->left->right=Insert(4);
    root->left->left=Insert(1);
    root->right->left=Insert(7);
    root->right->right=Insert(9);
    cout<<"Tree : ";
    print(root);
    return 0;
}