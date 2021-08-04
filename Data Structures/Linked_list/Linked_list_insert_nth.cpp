#include <iostream>
using namespace std;
struct node
{
	int data;
	node *next;
};
node *head;
void insert(int data, int n)
{
	node *temp1 = new node();
	temp1->data = data;
	temp1->next = NULL;
	if (n == 1)
	{
		head = temp1;
		return;
	}
	node *temp2 = head;
	for (int i = 0; i < n - 2; i++)
	{
		temp2 = temp2->next;
	}
	temp1->next = temp2->next;
	temp2->next = temp1;
}
void print()
{
	cout << "List is : " << endl;
	node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << endl;
		temp = temp->next;
	}
}
int main()
{
	head = NULL;
	insert(1, 1);
	insert(2, 2);
	insert(5, 3);
	insert(4, 3);
	insert(3, 3);
	print();
	return 0;
}
