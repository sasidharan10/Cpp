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
    int count = 0;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
        count++;
        if (count == 15)
            break;
    }
}
int startLoop1()
{
    // Floyd - cycle detection

    // Time  : O(n)
    // Space : O(1)

    node *low=head;
    node *high=head;
    while (high!=NULL && high->next!=NULL)
    {
        low=low->next;
        high=high->next->next;
        if(low==high)
            break;
    }
    if(low!=high)
        return -1;
    if(low==head)
        return head->data;
    low=head;
    while (high!=low)
    {
        low=low->next;
        high=high->next;
    }
    return high->data;
}
int main()
{
    head = NULL;
    Insert(5);
    Insert(4);
    Insert(3);
    Insert(2);
    Insert(1);
    head->next->next->next->next->next = head->next->next->next;
    print();
    cout<<"\nStart : "<<startLoop1();
    // endLoop2();
    return 0;
}