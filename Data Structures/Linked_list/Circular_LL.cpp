#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
node *head;
void insertAtBeg(int n)
{
    node *temp1 = new node();
    temp1->data = n;
    if (head == NULL)
    {
        temp1->next = head;
        head = temp1;
        return;
    }
    temp1->next = head;
    head = temp1;
}
void insertAtEnd(int n)
{
    node *temp1 = new node();
    temp1->data = n;
    if (head == NULL)
    {
        head = temp1;
        temp1->next = head;
        return;
    }
    node *temp2 = head;
    while (temp2->next != head)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp1;
    temp1->next = head;
}
void print()
{
    cout << "List is : " << endl;
    node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
}
int main()
{
    head = NULL;
    insertAtBeg(1);
    insertAtBeg(2);
    insertAtBeg(3);
    insertAtBeg(4);
    insertAtBeg(5);
    print();
    insertAtEnd(6);
    insertAtEnd(7);
    print();
    return 0;
}