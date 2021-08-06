#include <iostream>
#include <algorithm>
#include <string>
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
    cout << "List : ";
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
void findTriplet(node *head, int sum)
{
    node *ptr = head;
    node *left = head;
    node *right = head;
    int x = sum;
    while (right->next != NULL)
    {
        right = right->next;
    }
    node *last = right;
    while (ptr->next->next != NULL)
    {
        sum = x;
        left = ptr->next;
        right = last;
        sum = sum - ptr->data;
        while (left != right  && right->next != left && left != NULL && right != NULL )
        {
            if (left->data + right->data == sum)
            {
                cout << "\nTriplet is : " << ptr->data << " " << left->data << " " << right->data;
                left = left->next;
                right = right->prev;
            }
            else if (left->data + right->data < sum)
                left = left->next;
            else
                right = right->prev;
        }
        ptr = ptr->next;
    }
}
int main()
{
    node *head = NULL;
    int sum = 17;
    Insert(&head, 9);
    Insert(&head, 8);
    Insert(&head, 6);
    Insert(&head, 5);
    Insert(&head, 4);
    Insert(&head, 2);
    Insert(&head, 1);
    print(head);
    findTriplet(head, sum);
    return 0;
}