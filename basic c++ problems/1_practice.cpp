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
node *insertNode(node *head, int n)
{
    node *temp1 = new node(n);
    if(head==NULL)
    {
        temp1->next=NULL;
        head=temp1;
        return head;
    }
    node *temp2=head;
    while (temp2->next!=NULL)
    {
        temp2=temp2->next;
    }
    temp2->next = temp1;
    return head;
}
node* insertNth(node *head, int pos, int n)
{
    node *temp=new node(n);
    if(pos==1)
    {
        temp->next=head;
        head=temp;
        return head;
    }
    node *temp2=head;
    for (int i = 1; i < pos-1; i++)
    {
        temp2=temp2->next;
    }
    temp->next=temp2->next;
    temp2->next=temp;
    return head;
}
void printData(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout<<endl;
}
node *deleteNth(node *head, int pos)
{
    node *temp=head;
    if(pos==1)
    {
        head=temp->next;
        temp->next=NULL;
        delete temp;
        return head;
    }
    for (int i = 1; i < pos-1; i++)
    {
        temp=temp->next;
    }
    node* deleteNode=temp->next;
    temp->next=deleteNode->next;
    deleteNode->next=NULL;
    delete deleteNode;
    return head;
}
node *deleteValue(node *head, int val)
{
    node *prev=NULL;
    node *current=head;
    while (current!=NULL)
    {
        if(current->data==val)
        {
            if(current==head)
            {
                head=current->next;
                current->next=NULL;
                delete current;
                return head;
            }
            // last element
            if(current->next==NULL)
            {
                prev->next=NULL;
                delete current;
                return head;
            }
            prev->next=current->next;
            current->next=NULL;
            delete current;
            return head;
        }
        prev=current;
        current=current->next;
    }
}
node *reverseList(node *head)
{
    node *prev=NULL, *current=head,*next_node=NULL;
    while (current!=NULL)
    {
        next_node=current->next;
        current->next=prev;
        prev=current;
        current=next_node;
    }
    head=prev; 
    return head;
}
int main()
{
    int n = 5;
    node *head = NULL;
    for (int i = 1; i <= n; i++)
    {
        head=insertNode(head, i);
    }
    printData(head);
    int pos=2;
    int val=78;
    head=insertNth(head, pos, val);
    printData(head);
    head=deleteNth(head, 2);
    printData(head);
    head=deleteValue(head, 1);
    printData(head);
    head=reverseList(head);
    printData(head);
    return 0;
}