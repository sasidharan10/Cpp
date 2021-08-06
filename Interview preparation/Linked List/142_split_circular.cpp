#include <iostream>
#include <algorithm>
#include <string>
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
    cout << "\nList : ";
    node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
}
void splitCircular(node *head, node **first, node **second)
{
    node *low = head;
    node *high = head->next; // if head, then it will not even enter the loop
    while (high != head && high->next != head)
    {
        low = low->next;
        high = high->next->next;
    }

    //first

    *first = head;
    *second = low->next;
    low->next = *first;

    // for second

    node *temp = *second;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = *second;
}
int main()
{
    node *head = NULL;
    node *first = NULL;
    node *second = NULL;
    Insert(&head, 6);
    Insert(&head, 5);
    Insert(&head, 4);
    Insert(&head, 3);
    Insert(&head, 2);
    Insert(&head, 1);
    head->next->next->next->next->next->next = head;
    print(head);
    splitCircular(head, &first, &second);
    print(first);
    print(second);
    return 0;
}