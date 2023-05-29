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
    cout << "List is : ";
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp);
    cout << endl;
}
void deleteAlternate(node *head)
{
    node *temp = head;
    while (temp != nullptr && temp->next != nullptr)
    {
        cout << temp->data << " ";
        temp->next = temp->next->next;
        temp = temp->next;
    }
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
    print(head);
    deleteAlternate(head);
    print(head);
    return 0;
}