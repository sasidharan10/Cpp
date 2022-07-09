#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
class node
{
    public:
    int data;
    node *next;
    node(int val)
    {
        data=val;
        next=NULL;
    }
};
void insert(int n,node **head)
{
    node *temp=new node(n);
    temp->next=*(head);
    *(head)=temp;
}
void reverse(node **head)
{
    if(!*(head))
    {
        cout<<"Empty List!!!"<<endl;
        return;
    }
    stack<node*>s;
    node *temp=*(head);
    while (temp!=NULL)
    {
        s.push(temp);
        temp=temp->next;
    }
    *(head)=s.top();
    temp=s.top();
    s.pop();
    while (!s.empty())
    {
        temp->next=s.top();
        s.pop();
        temp=temp->next;
    }
    temp->next=NULL;
}
void print(node *head)
{
    node *temp = head; // pointing to first element
    cout << "\nList: ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main()
{
    node *head=NULL;
    insert(1,&head);
    insert(2,&head);
    insert(3,&head);
    insert(4,&head);
    insert(5,&head);
    print(head);
    reverse(&head);
    print(head);
    return 0;
}