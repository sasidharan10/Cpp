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
node *Insert(node *head, int n)
{
    node *temp = new node();
    temp->data = n;
    temp->next = NULL;
    temp->prev = NULL;
    if (head == NULL)
    {
        head = temp;
        return head;
    }
    head->prev = temp;
    temp->next = head;
    head = temp;
    return head;
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
node *Reverse(node *head)
{
    node *current = head;
    node *temp;
    while (current != NULL)
    {
        // swapping
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        current = current->prev;
    }
    // as current becomes null,we assign temp->prev as head since it is pointing
    // to second node.
    head = temp->prev;
    return head;
}
int main()
{
    node *head = NULL;
    head = Insert(head, 5);
    head = Insert(head, 4);
    head = Insert(head, 3);
    head = Insert(head, 2);
    head = Insert(head, 1);
    print(head);
    head = Reverse(head);
    print(head);
    return 0;
}