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
    string s = "4(2(3)(1))(6(5))";
    int i = 0;
    root = convert(s, i);
    print(root);
    return 0;
}