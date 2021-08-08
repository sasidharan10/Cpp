#include <iostream>
#include <cmath>
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
int Intersect(node *first, node *second)
{
    node *head = NULL;
    node *current = NULL;
    node *temp;
    int c1 = 0;
    int c2 = 0;
    temp = first;
    while (temp != NULL)
    {
        temp = temp->next;
        c1++;
    }
    temp = second;
    while (temp != NULL)
    {
        temp = temp->next;
        c2++;
    }
    temp = NULL;
    int diff = abs(c1 - c2);
    if (c1 > c2)
    {
        for (int i = 0; i < diff; i++)
        {
            first = first->next;
        }
    }
    else if (c2 > c1)
    {
        for (int i = 0; i < diff; i++)
        {
            second = second->next;
        }
    }
    while (first != second)
    {
        first = first->next;
        second = second->next;
    }
    if (first != NULL)
        return first->data;
    else
    {
        cout << "They do not Intersect" << endl;
        return -1;
    }
}
int main()
{
    node *first = NULL;
    node *second = NULL;
    // First List
    first = Insert(first, 30);
    first = Insert(first, 15);
    first = Insert(first, 9);
    first = Insert(first, 6);
    first = Insert(first, 3);
    // Second List
    second = Insert(second, 30);
    second = Insert(second, 15);
    second = Insert(second, 10);
    second->next = first->next->next->next;
    cout << "\nResult : " << Intersect(first, second);
    ;
    return 0;
}