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
		cout<<temp->data<<", ";
		temp=temp->next;
	}
}
node* Reverse(node* head)
{
    node *prev,*current,*next_node;
    prev=NULL;
    current=head;
    while(current!=NULL)
    {
        next_node=current->next;  // storing the next address in next_node
        current->next=prev;  // linking the current to previous node
        prev=current;  // updating prev pointer
        current=next_node;  // updating current pointer
    }
    head =prev; // sice prev points to last node, we point head to this node as last step
    return head;
}
int main()
{
    node* head=NULL;
	int n,a;
	head =insert(head,1);
	head =insert(head,2);
	head =insert(head,3);
	head =insert(head,4);
	head =insert(head,5);
	print(head);
    head=Reverse(head);
    print(head);
	return 0;
}

// here we have to keep track of the previous node as well as the next node for reversing it