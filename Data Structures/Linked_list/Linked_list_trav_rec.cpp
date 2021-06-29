#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
node* insert(node *head,int n)
{
    node *temp1= new node();
    temp1->data=n;
    temp1->next=NULL;
    if(head==NULL)
    {
        head=temp1;
        return head;
    }
    node *temp2=head;
    while(temp2->next!=NULL)
    {
        temp2=temp2->next;
    }
    temp2->next=temp1;
    return head;
}
void print(node *p)
{
    
    if(p==NULL)
        return;
    cout<<p->data<<", ";
    print(p->next);
}
void Reverse_print(node *p)
{
    if(p==NULL)
        return;
    Reverse_print(p->next);
    cout<<p->data<<", ";
}
int main()
{
    node *head=NULL; // 
    head=insert(head,1);
    head=insert(head,2);
    head=insert(head,3);
    head=insert(head,4);
    head=insert(head,5);
    cout<<"The list is : ";
    print(head);
    cout<<"\nThe reverse is : ";
    Reverse_print(head);
    return 0;
}