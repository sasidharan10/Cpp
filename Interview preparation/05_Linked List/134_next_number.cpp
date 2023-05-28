#include <iostream>
#include <algorithm>
using namespace std;
class node
{
public:
    int data;
    node *next;
};
node *head;
void Insert(int n)
{
    node *temp = new node();
    temp->data = n;
    temp->next = head;
    head = temp;
}
void print()
{
    node *temp = head;
    cout << "\nList : ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
void Reverse(node *p)
{
    if (p->next == NULL)
    {
        head = p;
        return;
    }
    Reverse(p->next);
    node *temp;
    temp = p->next;
    temp->next = p;
    p->next = NULL;
}
void add1()
{
    Reverse(head);
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 9 && temp->next == NULL)
        {
            temp->data = 1;
            node *newNode = new node();
            newNode->data = 0;
            newNode->next = head;
            head = newNode;
            temp = temp->next;
        }
        else if (temp->data == 9)
        {
            temp->data = 0;
            temp = temp->next;
        }
        else
        {
            temp->data = temp->data + 1;
            temp = temp->next;
        }
    }
    Reverse(head);
}
void add3()
{
    int carry = addCarry(head);
    if (carry)
    {
        node *temp = new node();
        temp->data = carry;
        temp->next = head;
        head = temp;
    }
}
int addCarry(node *temp)
{
    if (temp == NULL)
        return 5;
    int res = temp->data + addCarry(temp->next);
    temp->data = res % 10;
    return res / 10;
}
void add2()
{
    Reverse(head);
    node *temp = head;
    int sum = 0;
    int carry = 5;
    while (temp != NULL)
    {
        if (temp->next == NULL && temp->data + carry > 9)
        {
            node *newNode = new node();
            int res = temp->data + carry;
            temp->data = res % 10;
            newNode->data = res / 10;
            temp->next = newNode;
            newNode->next = NULL;
            break;
        }
        sum = temp->data + carry;
        temp->data = sum % 10;
        carry = sum / 10;
        temp = temp->next;
    }
    Reverse(head);
}
int main()
{
    head = NULL;
    Insert(9);
    Insert(9);
    Insert(9);
    Insert(9);
    print();
    // add1();
    // add2();
    add3();
    print();
}