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
    cout << "\nList is : ";
    int count = 0;
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
        count++;
        if (count > 20)
            break;
    }
}
bool checkCircular1(node *head)
{
    if (head == NULL)
        return true;
    node *temp = head;
    node *high = head;
    temp = temp->next;
    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }
    if (temp == head)
        return true;
    else
        return false;
}
bool checkCircular2(node *head)
{
    // Floyd-cycle detection
    // this will work even if the list is looped

    if (head == NULL)
        return true;
    node *low = head;
    node *high = head;
    while (high != NULL && high->next != NULL)
    {
        low = low->next;
        high = high->next->next;
        if (low == high)
            break;
    }
    if (low == head)
        return true;
    else
        return false;
}
int main()
{
    node *head = NULL;
    Insert(&head, 5);
    Insert(&head, 4);
    Insert(&head, 3);
    Insert(&head, 2);
    Insert(&head, 1);
    head->next->next->next->next->next = head;
    // head->next->next->next->next->next = head->next->next;
    print(head);
    cout << "\nCircular ? : " << checkCircular1(head);
    cout << "\nCircular ? : " << checkCircular2(head);
    return 0;
}