#include <iostream>
#include <algorithm>
#include <string>
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
node *convert(string s, int &i)
{
    if (s.size() == 0 || i > s.size())
        return NULL;
    int num = 0;
    while (i < s.size() && s[i] != '(' && s[i] != ')')
    {
        int rem = int(s[i] - '0');
        num = num * 10 + rem;
        i++;
    }

    node *root = Insert(num);

    if (i >= s.size())
        return root;

    if (i < s.size() && s[i] == '(')
    {
        i++;
        root->left = convert(s, i);
    }
    if (i < s.size() && s[i] == ')')
    {
        i++;
    }

    if (i < s.size() && s[i] == '(')
    {
        i++;
        root->right = convert(s, i);
    }
    if (i < s.size() && s[i] == ')')
    {
        i++;
    }
    return root;
}
void convert2(node **root, string s, int &i)
{
    if (s.size() == 0 || i > s.size())
        return;
    int num = 0;
    while (i < s.size() && s[i] != '(' && s[i] != ')')
    {
        int rem = int(s[i] - '0');
        num = num * 10 + rem;
        i++;
    }

    *root = Insert(num);

    if (i >= s.size())
        return;

    if (i < s.size() && s[i] == '(')
    {
        i++;
        convert2(&(*root)->left, s, i);
    }
    if (i < s.size() && s[i] == ')')
    {
        i++;
    }

    if (i < s.size() && s[i] == '(')
    {
        i++;
        convert2(&(*root)->left, s, i);
    }
    if (i < s.size() && s[i] == ')')
    {
        i++;
    }
    return;
}
void print(node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    print(root->left);
    print(root->right);
}
int main()
{
    node *root = NULL;
    node *root2 = NULL;
    string s = "4(2(1)(3))(6(5)(7))";
    // string s = "4(2)(5)";
    int i = 0;
    root = convert(s, i);
    i=0;
    convert2(&root2,s, i);
    cout<<"\nTree : ";
    print(root);
    cout<<"\nTree : ";
    print(root2);
    return 0;
}