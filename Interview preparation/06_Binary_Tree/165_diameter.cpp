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
node *Insert(int n)
{
    node *temp = new node();
    temp->data = n;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
int height(node *root)
{
    if (root == NULL)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}
int diameter1(node *root)
{
    if (root == NULL)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    int currentDiameter = leftHeight + rightHeight + 1;

    int leftDiameter = diameter1(root->left);
    int rightDiameter = diameter1(root->right);

    return max({currentDiameter, leftDiameter, rightDiameter});
}
int maxdiameter = 0;
int calcHeight(node *root)
{
    if (root == NULL)
        return 0;
    int leftHeight = calcHeight(root->left);
    int rightHeight = calcHeight(root->right);

    maxdiameter = max(maxdiameter, leftHeight + rightHeight + 1);
    return max(leftHeight, rightHeight) + 1;
}
int calcDiameter(node *root)
{
    int x = calcHeight(root);
    return maxdiameter;
}
int main()
{
    node *root = NULL;
    root = Insert(1);
    root->left = Insert(2);
    root->right = Insert(3);
    root->left->left = Insert(4);
    root->left->right = Insert(5);
    root->left->right->right = Insert(10);
    root->left->right->right->right = Insert(11);
    root->right->left = Insert(6);
    root->right->right = Insert(7);
    cout << "Diameter (method 1) : " << diameter1(root) << endl;
    cout << "Diameter (method 2) : " << calcDiameter(root) << endl;
    return 0;
}