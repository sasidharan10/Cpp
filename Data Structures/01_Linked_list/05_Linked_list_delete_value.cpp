#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
node *insert(node *head, int a)
{
    node *prev = new node();
    prev->data = a;
    prev->next = NULL;
    if (head == NULL)
    {
        head = prev;
        return head;
    }
    node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = prev;
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
node *Delete(node *head, int x)
{
    node *prev = head;
    node *current = head;
    int n = 0;
    while (current != NULL)
    {
        if (current->data == x)
        {
            if (current == head)  // condition if it is a first element
            {
                head = current->next;
                delete current;
                return head;
            }
            if(current->next==NULL)  // condition if it is a last element
            {
                prev->next=NULL;
                delete current;
                return head;
            }
            prev->next = current->next;  // normal deletion
            delete current;
            return head;
        }
        else
        {
            prev = current;
            current = current->next;
        }
    }
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
    cout << "\nEnter the element you want to delete : ";
    cin >> n;
    head = Delete(head, n);
    print(head);
    return 0;
}

// Hint : keep track of the previous node