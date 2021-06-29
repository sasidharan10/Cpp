#include<iostream>
#include<stdio.h>
using namespace std;
struct node
{
    int data;
    node* next;
};
node* front;
node* rear;
void enqueue(int n)
{
    node *temp= new node();
    temp->data=n;
    temp->next=NULL;
    if(front==NULL)
    {
        front=rear=temp;
        return;
    }
    rear->next=temp;
    rear=temp;
}
void dequeue()
{
    node *temp = front;
    if(front==NULL)
    {
        cout<<"Queue is Empty!!!"<<endl;
        return;
    }
    else if(front==rear)
    {
        front=rear=NULL;
        delete temp;
        return;
    }
    front=front->next;
    delete temp;
}
void print()
{
	node *temp =front; 
	cout<<"\nThe elements are : ";
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    print();
    dequeue();
    dequeue();
    print();
    return 0;
}

// here we insert at the back and delete at the first