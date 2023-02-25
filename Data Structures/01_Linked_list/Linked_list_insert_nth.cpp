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
	node *temp = new node();
	temp->data = data;
	temp->next = NULL;
	if (n == 1)
	{
		head = temp;
		return;
	}
	node *prev = head;
	for (int i = 0; i < n - 2; i++)
	{
		prev = prev->next;
	}
	temp->next = prev->next;
	prev->next = temp;
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
