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
    cout << "\nList : ";
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
node *Rotate(node *head, int n)
{
    node *current = head;
    node *newHead;
    int count = 0;
    while (count < n)
    {
        current = current->next;
        count++;
    }
    newHead = current;
    newHead->prev->next = NULL;
    newHead->prev = NULL;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = head;
    head->prev = current;
    return newHead;
}
int main()
{
    node *head = NULL;
    int n = 4;
    Insert(&head, 7);
    Insert(&head, 6);
    Insert(&head, 5);
    Insert(&head, 4);
    Insert(&head, 3);
    Insert(&head, 2);
    Insert(&head, 1);
    print(head);
    head = Rotate(head, n);
    print(head);
    return 0;
}