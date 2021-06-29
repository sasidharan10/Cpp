#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
node *head;
void insert(int n)
{
    node *temp1 = new node();
    temp1->data = n;
    if (head == NULL)
    {
        head = temp1;
        temp1->next = head;
        return;
    }
    node *temp2 = head;
    do
    {
        temp2 = temp2->next;
    } while (temp2->next != head);
    temp2->next = temp1;
    temp1->next = head;
}
void print()
{
    cout << "List is : " << endl;
    node *temp = head;
    do
    {
        cout << temp->data << ", ";
        temp = temp->next;
    } while (temp != head);
}
int main()
{
    head = NULL;
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    print();
    return 0;
}