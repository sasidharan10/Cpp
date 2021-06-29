#include<iostream>
using namespace std;
struct node
{
    int data;
    node *prev;
    node *next;
};
node *head;
node *getNode(int n)
{
    node *newNode=new node();
    newNode->data=n;
    newNode->prev=NULL;
    newNode->next=NULL;
    return newNode;
}
void insertEnd(int n)
{
    node *newNode=getNode(n);
    if(head==NULL)
    {
        head=newNode;
        return;
    }
    node *temp2=head;  // temporary pointer to go to last node
    while(temp2->next!=NULL)
    {
        temp2=temp2->next;
    }
    temp2->next=newNode;
    newNode->prev=temp2;
}
void insertBeg(int n)
{
    node *newNode=getNode(n);
    if(head==NULL)
    {
        head=newNode;
        return;
    }
    head->prev=newNode;
    newNode->next=head;
    head=newNode;
}
void print()
{
    node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<", ";
        temp=temp->next;
    }
}
void Reverse()
{
    node *temp=head;
    if(temp==NULL)
        return;  // if list is empty
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    while(temp!=NULL)
    {
        cout<<temp->data<<", ";
        temp=temp->prev;
    }
}
int main()
{
    head=NULL;
    // insertBeg(1);
    // insertBeg(2);
    // insertBeg(3);
    // insertBeg(4);
    // insertBeg(5);
    insertEnd(1);
    insertEnd(2);
    insertEnd(3);
    insertEnd(4);
    insertEnd(5);
    cout<<"The list is : ";
    print();
    cout<<"\nThe reverse is : ";
    Reverse();
    return 0;
}