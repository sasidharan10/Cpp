#include <iostream>
#include <algorithm>
using namespace std;
class node
{
public:
    int data;
    node *next;
};
void Insert(node **head, int n)
{
    node *temp = new node();
    temp->data = n;
    temp->next = *head;
    *head = temp;
}
void print(node *head)
{
    if (head == NULL)
    {
        cout << "List Empty!!!" << endl;
        return;
    }
    node *temp = head;
    cout << "\nList is : ";
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
}
node* deleteAlternate(node *head)
{
    // node *temp=head->next->next;
    // while (temp!=head || temp->next!=head)
    // {
    //     node *delNode=temp->next;
    //     temp->next=temp->next->next;
    //     temp=temp->next;
    //     // cout<<temp->data<<" ";
    //     // delete delNode;
    // }
    node *temp=head;
    do
    {
        cout<<temp->data<<" ";
        node *delNode=temp->next;
        temp->next=temp->next->next;
        temp=temp->next;
    } while (temp->next!=head || temp!=head);
    
    return head;
}
void deleteAlt(node *head) 
{ 
    if (head == NULL) 
        return; 
  
    /* Initialize prev and node to be deleted */
    node *prev = head; 
    node *temp = head->next; 
  
    while (prev != NULL && temp != NULL) 
    { 
        /* Change next link of previous temp */
        prev->next = temp->next; 
        delete(temp); // delete the temp
        /* Update prev and temp */
        prev = prev->next; 
        if (prev != NULL) 
            temp = prev->next; 
    } 
}
int main()
{
    node *head = NULL;
    Insert(&head, 8);
    Insert(&head, 7);
    Insert(&head, 6);
    Insert(&head, 5);
    Insert(&head, 4);
    Insert(&head, 3);
    Insert(&head, 2);
    Insert(&head, 1);
    head->next->next->next->next->next->next->next->next = head;
    print(head);
    // head=deleteAlternate(head);
    deleteAlt(head);
    print(head);
    return 0;
}