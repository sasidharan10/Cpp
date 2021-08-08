#include <iostream>
#include <algorithm>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *prev;
};
void Insert(node **head, int n)
{
    node *temp = new node();
    temp->data = n;
    temp->next = NULL;
    temp->prev = NULL;
    if (*head == NULL)
    {
        *head = temp;
        return;
    }
    (*head)->prev = temp;
    temp->next = *head;
    *head = temp;
}
void print(node *head)
{
    cout << "List : ";
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
void findPair(node *head, int sum)
{
    node *left = head;
    node *right = head;
    while (right->next != NULL)
    {
        right = right->next;
    }
    while (left != right)
    {
        if (left->data + right->data == sum)
        {
            cout << "\nPair is : " << left->data << " " << right->data;
            left = left->next;
            right = right->prev;
        }
        else if (left->data + right->data < sum)
            left = left->next;
        else
            right = right->prev;
    }
}
int main()
{
    node *head = NULL;
    int sum = 10;
    Insert(&head, 9);
    Insert(&head, 8);
    Insert(&head, 6);
    Insert(&head, 5);
    Insert(&head, 4);
    Insert(&head, 2);
    Insert(&head, 1);
    print(head);
    findPair(head, sum);
    return 0;
}