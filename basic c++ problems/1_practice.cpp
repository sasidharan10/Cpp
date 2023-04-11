#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
    node(int n)
    {
        data = n;
        next = NULL;
    }
};
node *head;
void insertNode(int n)
{
    node *temp1 = new node(n);
    if(head==NULL)
    {
        temp1->next=NULL;
        head=temp1;
        return;
    }
    node *temp2=head;
    while (temp2->next!=NULL)
    {
        temp2=temp2->next;
    }
    temp2->next = temp1;
}
void printData()
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main()
{
    int n = 5;
    head = NULL;
    for (int i = 1; i <= n; i++)
    {
        insertNode(i);
    }
    printData();
    return 0;
}