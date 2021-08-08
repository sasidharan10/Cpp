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
    if (head == NULL)
    {
        cout << "List Empty!!!" << endl;
        return;
    }
    node *temp = head;
    cout << "\nList is : ";
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
}
node *deleteCircular(node *head, int n)
{
    node *prev = head;
    node *temp = head->next;
    // to check if its head node
    if (head->data == n)
    {
        head = head->next;
    }
    if (head->data == n && head->next == head)
    {
        delete head;
        head = NULL;
        return NULL;
    }
    while (temp->data != n)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    delete temp;
    return head;
}
int main()
{
    node *head = NULL;
    Insert(&head, 6);
    Insert(&head, 5);
    Insert(&head, 4);
    Insert(&head, 3);
    Insert(&head, 2);
    Insert(&head, 1);
    head->next->next->next->next->next->next = head;
    print(head);
    head = deleteCircular(head, 1);
    head = deleteCircular(head, 6);
    print(head);
    return 0;
}