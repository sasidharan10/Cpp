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
void removeDuplicates1()
{
    // TC: O(n)
    // SC: O(n)

    node *temp = head;
    node *prev = NULL;
    node *deleteNode;
    unordered_multiset<int> um;
    while (temp != NULL)
    {
        if (um.find(temp->data) != um.end())
        {
            deleteNode = temp;
            prev->next = temp->next;
            temp = temp->next;
            delete deleteNode;
        }
        else
        {
            um.insert(temp->data);
            prev = temp;
            temp = temp->next;
        }
    }
}
void removeDuplicates2()
{
    // TC: O(n^2)
    // SC: O(1)

    node *temp = head;
    node *prev = nullptr;
    node *delNode = nullptr;
    while (temp != nullptr)
    {
        node *t1 = temp->next;
        while (t1 != nullptr)
        {
            if (temp->data == t1->data)
            {
                delNode = t1;
                prev->next = t1->next;
                t1 = prev->next;
                delete delNode;
            }
            else
            {
                prev = t1;
                t1 = t1->next;
            }
        }
        temp = temp->next;
    }
}
int main()
{
    head = NULL;
    Insert(4);
    Insert(1);
    Insert(3);
    Insert(1);
    Insert(5);
    Insert(4);
    Insert(1);
    Insert(5);
    Insert(2);
    print();
    removeDuplicates1();
    // removeDuplicates2();
    print();
    return 0;
}