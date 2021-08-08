#include <iostream>
#include <algorithm>
using namespace std;
class node
{
public:
    int data;
    node *next;
};
void Insert(node **head, int n)
{
    node *temp = new node();
    temp->data = n;
    temp->next = *head;
    *head = temp;
}
void print(node *head)
{
    cout << "\nList is : ";
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
void split(node *head, node **left, node **right)
{
    node *low = head;
    node *high = head->next;
    // if high is pointed to head node then at one point we will have 2 elements in the
    // list and when we run the loop, high will directly jump to the null pointer,
    // and then we will have 1,2 in left node NULL in right node.
    // so to avoid it, we first point high to head->next,so when we have 2 nodes,
    // the loop will break immediately and then we split it to 2 equal halfs.

    while (high != NULL && high->next != NULL)
    {
        low = low->next;
        high = high->next->next;
    }

    *left = head;
    *right = low->next;
    low->next = NULL;
}
node *merge(node *left, node *right)
{
    node *res = NULL;
    if (left == NULL)
        return right;
    else if (right == NULL)
        return left;
    if (left->data <= right->data)
    {
        res = left;
        res->next = merge(left->next, right);
    }
    else
    {
        res = right;
        res->next = merge(left, right->next);
    }
    return res;
}
void mergesort(node **head)
{
    node *current = *head;
    node *left;
    node *right;
    if (current == NULL || current->next == NULL)
        return;
    split(current, &left, &right);
    mergesort(&left);
    mergesort(&right);
    *head = merge(left, right);
}
int main()
{
    node *head = NULL;
    Insert(&head, 2);
    Insert(&head, 3);
    Insert(&head, 1);
    Insert(&head, 5);
    Insert(&head, 4);
    print(head);
    mergesort(&head);
    print(head);
    return 0;
}