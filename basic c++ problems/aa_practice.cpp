#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
    node *prev;
    node(int val)
    {
        this->data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
void insert(int a, node **head)
{
    node *temp = new node(a);
    if (*head == NULL)
    {
        *head = temp;
        return;
    }
    temp->next = *head;
    (*head)->prev = temp;
    *head = temp;
    return;
}
void Delete(int val, node **head)
{
    node *temp = (*head);
    if ((*head)->data == val)
    {
        (*head) = (*head)->next;
        delete temp;
        return;
    }
    node *prev = temp;
    temp = temp->next;
    while (temp != NULL)
    {
        if (temp->data == val)
        {
            if (temp->next == NULL)
            {
                prev->next = NULL;
                delete temp;
                return;
            }
            prev->next = temp->next;
            temp->next = NULL;
            delete temp;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}
void print(node *head)
{
    node *temp = head; // pointing to first element
    cout << "\nThe list is: ";
    while (temp->next != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data << " ";
    cout << "\nThe reverse is: ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
}
int main()
{
    node *head = NULL;
    int n, a;
    insert(5, &head);
    insert(4, &head);
    insert(3, &head);
    insert(2, &head);
    insert(1, &head);
    print(head);
    // Delete(5, &head);
    // print(head);
    return 0;
}