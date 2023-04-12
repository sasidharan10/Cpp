#include <iostream>
using namespace std;
struct node
{
	int data;
	node *next;
};
node *head; // global variable so that we can access it anywhere
void insert(int a)
{
	node *temp = new node();
	temp->data = a; // storing data
	temp->next = head;
	head = temp; // head is connected to the node
}
void print()
{
	node *temp = head; // pointing to first element
	cout << "\nThe elements are : ";
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
}

int main()
{
	head = NULL; // setting head to point null
	int n=5;
	for (int i = 1; i <= n; i++)
	{
		insert(i);
	}
	print();
	return 0;
}