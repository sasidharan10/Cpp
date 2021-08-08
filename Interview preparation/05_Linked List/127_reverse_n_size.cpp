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
node *Insert(node *head, int n)
{
    node *temp = new node();
    temp->data = n;
    temp->next = head;
    head = temp;
    return head;
}
void print(node *head)
{
    node *temp = head;
    cout << "\nList : ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
node *Reverse(node *head, int n)
{
    // Time  : O(n)
    // Space : O(1)
    
    int count = 0;
    node *current, *nextPtr, *prev;
    current = head;
    prev = NULL;
    nextPtr = NULL;
    while (current != NULL && count < n)
    {
        nextPtr = current->next;
        current->next = prev;
        prev = current;
        current = nextPtr;
        count++;
    }
    if (nextPtr != NULL)
        head->next = Reverse(nextPtr, n);
    return prev;
}
int main()
{
    node *head = NULL;
    head = Insert(head, 6);
    head = Insert(head, 5);
    head = Insert(head, 4);
    head = Insert(head, 3);
    head = Insert(head, 2);
    head = Insert(head, 1);
    print(head);
    head = Reverse(head, 3);
    print(head);
}