#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;
class node
{
public:
    int data;
    node *next;
};
node *head;
void Insert(int a)
{
    node *temp = new node();
    temp->data = a;
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
void endLoop1()
{
    // Time  : O(n)
    // Space : O(n)

    node *current = head;
    node *prev = NULL;
    unordered_set<node *> hash;
    while (hash.find(current) == hash.end())
    {
        hash.insert(current);
        prev = current;
        current = current->next;
    }
    prev->next = NULL;
}
void endLoop2()
{
    // Floyd - cycle detection

    // Time  : O(n)
    // Space : O(1)

    node *low = head;
    node *high = head;
    while (high != NULL && high->next != NULL)
    {
        low = low->next;
        high = high->next->next;
        if (low == high)
            break;
    }
    // exception if it is a circular linked list
    // In this case low,high will end in starting node, so they will
    // end in same position after every iteration
    if (low == head)
    {
        while (high->next != low)
        {
            high = high->next;
        }
        high->next = NULL;
        return;
    }
    low = head;
    while (low->next != high->next)
    {
        low = low->next;
        high = high->next;
    }
    high->next = NULL;
}
int main()
{
    head = NULL;
    Insert(5);
    Insert(4);
    Insert(3);
    Insert(2);
    Insert(1);
    head->next->next->next->next->next = head;
    print();
    // endLoop1();
    endLoop2();
    print();
    return 0;
}