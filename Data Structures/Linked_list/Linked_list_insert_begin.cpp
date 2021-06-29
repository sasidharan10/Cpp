#include<iostream>
using namespace std;
struct node
{
	int data;
	node *next;
};
node *head;  // global variable so that we can access it anywhere
void insert(int a)
{
	node *temp = new node();
	temp->data=a; // storing data
	temp->next=head; 
	head=temp; // head is connected to the node
}
void print()
{
	node *temp =head;  // pointing to first element
	cout<<"\nThe elements are : ";
	while(temp!=NULL)
	{
		cout<<temp->data<<", ";
		temp=temp->next;
	}
}

int main()
{
	head=NULL;  // setting head to point null
	int n,a;
	cout<<"Enter the size of the list :";
	cin>>n;
	cout<<"\nEnter the Elements : ";
	for (int i = 0; i < n; i++)
	{
		cin>>a;
		insert(a);
	}
	print();
	return 0;
}