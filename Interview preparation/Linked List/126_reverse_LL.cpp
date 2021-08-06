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
node *head;
void Reverse1()
{
    // Time  : O(n)
    // Space : O(1)
    node *prev, *nextptr, *current;
    prev = NULL;
    current = head;
    if (head == NULL)
    {
        cout << "LIst Empty!!!" << endl;
        return;
    }
    while (current != NULL)
    {
        nextptr = current->next;
        current->next = prev;
        prev = current;
        current = nextptr;
    }
    head = prev;
}
void Reverse2(node *p)
{
    // Time  : O(n)
    // Space : O(1) { O(n) for stack memory }
    if (p->next == NULL)
    {
        head = p;
        return;
    }
    Reverse2(p->next);
    node *temp;
    temp = p->next;
    temp->next = p;
    p->next = NULL;
}
void Insert(int n)
{
    node *temp = new node();
    temp->data = n;
    if (head == NULL)
    {
        head = temp;
        temp->next = NULL;
        return;
    }
    temp->next = head;
    head = temp;
}
void Print()
{
    node *temp = head;
    cout << "\nList is : ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main()
{
    head = NULL;
    Insert(5);
    Insert(4);
    Insert(3);
    Insert(2);
    Insert(1);
    Print();
    Reverse1();
    Print();
    Reverse2(head);
    Print();
    return 0;
}