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
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
node *newNode(int n)
{
    node *temp = new node();
    temp->data = n;
    temp->next = NULL;
    return temp;
}
node *Intersect(node *first, node *second)
{
    node *head = NULL;
    node *current = NULL;
    node *temp;
    while (first != NULL && second != NULL)
    {
        if (first->data < second->data)
        {
            first = first->next;
        }
        if (second->data < first->data)
        {
            if (second != NULL)
                second = second->next;
        }
        if (first->data == second->data)
        {
            if (head == NULL)
            {
                temp = newNode(first->data);
                head = temp;
                current = temp;
            }
            else
            {
                temp = newNode(first->data);
                current->next = temp;
                current = current->next;
            }
            first = first->next;
            second = second->next;
        }
    }
    return head;
}
int main()
{
    node *first = NULL;
    node *second = NULL;
    node *res = NULL;
    // First List
    first = Insert(first, 6);
    first = Insert(first, 4);
    first = Insert(first, 3);
    first = Insert(first, 2);
    first = Insert(first, 1);
    cout << "\nFirst : ";
    print(first);
    // Second List
    second = Insert(second, 8);
    second = Insert(second, 6);
    second = Insert(second, 4);
    second = Insert(second, 2);
    cout << "\nSecond : ";
    print(second);
    res = Intersect(first, second);
    cout << "\nResult : ";
    print(res);
    return 0;
}