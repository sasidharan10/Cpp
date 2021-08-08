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
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
void removeDuplicates()
{
    // Time  : O(n)
    // Space : O(1)
    
    node *temp=head;
    node *deleteNode;
    if(head==NULL)
        return;
    while (temp->next!=NULL)
    {
        if(temp->data==temp->next->data)
        {
            deleteNode=temp->next;
            temp->next=deleteNode->next;
            delete deleteNode;
        }
        else
            temp=temp->next;
    }
}
int main()
{
    head = NULL;
    Insert(5);
    Insert(4);
    Insert(4);
    Insert(4);
    Insert(3);
    Insert(2);
    Insert(2);
    Insert(1);
    Insert(1);
    Insert(1);
    print();
    removeDuplicates();
    print();
    removeDuplicates();
    return 0;
}