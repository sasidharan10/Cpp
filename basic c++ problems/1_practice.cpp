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
void insertNth(int pos, int n)
{
    node *temp=new node(n);
    if(pos==1)
    {
        temp->next=head;
        head=temp;
        return;
    }
    node *temp2=head;
    for (int i = 1; i < pos-1; i++)
    {
        temp2=temp2->next;
    }
    temp->next=temp2->next;
    temp2->next=temp;
}
void printData()
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
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
    int pos=3;
    int val=9;
    insertNth(pos, val);
    printData();
    return 0;
}