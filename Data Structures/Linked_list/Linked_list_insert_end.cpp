#include<iostream>
using namespace std;
struct node
{
    int data;
    node* next;
};
node* insert(node *head,int a)
{
    node *temp1=new node();
    temp1->data=a;
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
void print(node *head)
{
    node *temp =head;  // pointing to first element
	cout<<"\nThe elements are : ";
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
int main()
{
    node* head=NULL;
	int n,a;
	cout<<"Enter the size of the list : ";
	cin>>n;
	cout<<"\nEnter the Elements : ";
	for (int i = 0; i < n; i++)
	{
		cin>>a;
		head=insert(head,a);
	}
	print(head);
    cout<<"\nFirst node : "<<head->data;
	return 0;
}