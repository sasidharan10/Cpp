#include <iostream>
#include <algorithm>
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
node *Reverse(node *p)
{
    node *head;
    if (p->next == NULL)
    {
        head = p;
        return head;
    }
    head = Reverse(p->next);
    node *temp;
    temp = p->next;
    temp->next = p;
    p->next = NULL;
    return head;
}
node *addList(node *first, node *second, node *res)
{
    int sum = 0;
    int carry = 0;
    first = Reverse(first);
    second = Reverse(second);
    while (first != NULL || second != NULL)
    {
        sum = (first ? first->data : 0) + (second ? second->data : 0) + carry;
        res = Insert(res, sum % 10);
        carry = (sum >= 10 ? 1 : 0);
        if (first != NULL)
            first = first->next;
        if (second != NULL)
            second = second->next;
    }
    if (carry)
    {
        res = Insert(res, carry);
    }
    // no need to reverse as we already inserted all element using "insert at beginning"
    // so the resutant list will be in correct order.
    return res;
}
int main()
{
    node *first = NULL;
    node *second = NULL;
    node *res = NULL;
    // First List
    first = Insert(first, 6);
    first = Insert(first, 8);
    first = Insert(first, 5);
    first = Insert(first, 4);
    first = Insert(first, 7);
    cout << "\nFirst : ";
    print(first);
    // Second List
    second = Insert(second, 7);
    second = Insert(second, 4);
    second = Insert(second, 9);
    second = Insert(second, 9);
    second = Insert(second, 9);
    cout << "\nSecond : ";
    print(second);
    res = addList(first, second, res);
    cout << "\nSum : ";
    print(res);
    return 0;
}