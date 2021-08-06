#include<iostream>
#include<algorithm>
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
int findMid()
{
    node *low=head;
    node *high=head;
    while (high!=NULL && high->next!=NULL)
    {
        low=low->next;
        high=high->next->next;
    }
    return low->data;
}
int main()
{
    head = NULL;
    Insert(6);
    Insert(5);
    Insert(4);
    Insert(3);
    Insert(2);
    Insert(1);
    print();
    cout<<"\nMid : "<<findMid()<<endl;

}