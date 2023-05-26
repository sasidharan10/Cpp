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
void lastToFirst()
{
    // TC: O(n)
    // SC: O(1)

    node *temp = head;
    node *prev = NULL;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    temp->next = head;
    head = temp;
}
int main()
{
    head = NULL;
    Insert(5);
    Insert(4);
    Insert(3);
    Insert(2);
    Insert(1);
    print();
    lastToFirst();
    print();
    return 0;
}