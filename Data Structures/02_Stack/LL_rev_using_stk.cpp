#include<iostream>
#include<stack>
using namespace std;
struct node
{
    int data;
    node *next;
};
node *head;
void insert(int x)
{
    node *temp1=new node();
    temp1->data=x;
    temp1->next=NULL;
    if(head==NULL)
    {
        temp1->next=head;
        head=temp1;
        return;
    }
    node *temp2=head;
    while (temp2->next!=NULL)
    {
        temp2=temp2->next;
    }
    temp2->next=temp1; 
}
void print()
{
    node *temp=head;
	cout<<"\nThe List are : ";
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
void Reverse()
{
    stack<node*> s;
    node *temp=head;
    if(temp==NULL)
    {
        cout<<"List is empty!!!"<<endl;
        return;
    }
    while(temp!=NULL)
    {
        s.push(temp);
        temp=temp->next;
    }
    temp=s.top();
    head=temp;
    s.pop(); // we are poping first node as it is already assigned in head,temp
    while(!s.empty())
    {
        temp->next=s.top();
        s.pop();
        temp=temp->next;
    }
    temp->next=NULL;  // making the last node to point at NULL
}
int main()
{
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    print();
    Reverse();
    print();
    return 0;
}