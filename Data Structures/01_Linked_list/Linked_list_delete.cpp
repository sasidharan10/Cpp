#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
node *insert(node *head, int a)
{
    node *temp1 = new node();
    temp1->data = a;
    temp1->next = NULL;
    if (head == NULL)
    {
        head = temp1;
        return head;
    }
    node *temp2 = head;
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp1;
    return head;
}
void print(node *head)
{
    node *temp = head; // pointing to first element
    cout << "\nThe elements are : ";
    while (temp != NULL)
    {
        cout << temp->data << ", ";
        temp = temp->next;
    }
}
node *Delete(node *head, int n)
{
    node *temp1 = head;
    if (n == 1)
    {
        head = temp1->next;
        delete temp1;
        return head;
    }
    for (int i = 0; i < n - 2; i++)
    {
        temp1 = temp1->next; // temp1 is at (n-1)th node
    }
    node *temp2 = temp1->next; // now temp2 points to the nth node to be deleted
    temp1->next = temp2->next;
    delete temp2;
    return head;
}
int main()
{
    node *head = NULL;
    int s, a, n;
    cout << "Enter the size of the list :";
    cin >> s;
    cout << "\nEnter the Elements : ";
    for (int i = 0; i < s; i++)
    {
        cin >> a;
        head = insert(head, a);
    }
    print(head);
    cout << "\nEnter the position you want to delete : ";
    cin >> n;
    head = Delete(head, n);
    print(head);
    return 0;
}