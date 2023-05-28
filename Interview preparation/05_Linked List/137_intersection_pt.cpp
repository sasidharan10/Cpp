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
    cout << "List: ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
node *Intersect(node *first, node *second)
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
    if (first)
        return first;
    else
    {
        cout << "They do not Intersect" << endl;
        return NULL;
    }
}
node *Intersect2(node *l1, node *l2)
{
    node *a = l1, *b = l2;
    while (a != b)
    {
        if (!a)
            a = l2;
        else
            a = a->next;
        if (!b)
            b = l1;
        else
            b = b->next;
    }
    return a;
}
int main()
{
    node *first = NULL;
    node *second = NULL;
    // First List
    first = Insert(first, 2);
    first = Insert(first, 7);
    first = Insert(first, 9);
    first = Insert(first, 6);
    first = Insert(first, 3);
    print(first);
    // Second List
    second = Insert(second, 30);
    second = Insert(second, 15);
    second = Insert(second, 10);
    second->next = first->next->next->next;
    print(second);
    cout << "\nResult : " << Intersect(first, second)->data;
    return 0;
}