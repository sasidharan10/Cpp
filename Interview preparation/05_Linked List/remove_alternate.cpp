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
node *deleteAlternate(node *head)
{
    node *temp = head;
    do
    {
        node *delNode = temp->next;
        temp->next = temp->next->next;
        temp = temp->next;
        delete delNode;
    } while (temp != head && temp->next != head);

    return head;
}
int main()
{
    node *head = NULL;
    Insert(&head, 8);
    Insert(&head, 7);
    Insert(&head, 6);
    Insert(&head, 5);
    Insert(&head, 4);
    Insert(&head, 3);
    Insert(&head, 2);
    Insert(&head, 1);
    head->next->next->next->next->next->next->next->next = head;
    print(head);
    head = deleteAlternate(head);
    print(head);
    return 0;
}