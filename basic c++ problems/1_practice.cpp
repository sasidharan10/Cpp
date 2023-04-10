#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
    node(int n)
    {
        data=n;
        next=NULL;
    }
};
node *head;
void insertNode(int n)
{
    node *temp=new node(n);
    temp->next=head;
    head=temp;
}
void printData()
{
    node *temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main()
{
    int n=5;
    head=NULL;
    for (int i = 1; i <= n; i++)
    {
        insertNode(i);
    }
    return 0;
}