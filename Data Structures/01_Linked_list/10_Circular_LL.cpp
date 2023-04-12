#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
node *tail;
void insertAtBeg(int n)
{
    node *temp = new node();
    temp->data = n;
    if (tail == NULL)
    {
        temp->next = temp;
        tail = temp;
        return;
    }
    temp->next = tail->next;
    tail->next = temp;
}
void insertAtEnd(int n)
{
    node *temp = new node();
    temp->data = n;
    if (tail == NULL)
    {
        temp->next = temp;
        tail = temp;
        return;
    }
    temp->next = tail->next;
    tail->next = temp;
    tail = temp;
}
void print()
{
    cout << "List is : ";
    node *temp = tail->next;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail->next);
    cout << endl;
}
int main()
{
    tail = NULL;
    insertAtBeg(1);
    insertAtBeg(2);
    insertAtBeg(3);
    insertAtBeg(4);
    insertAtBeg(5);
    print();
    print();
    insertAtEnd(6);
    insertAtEnd(7);
    print();
    return 0;
}

/*

We use tail pointer instead of head, since:
- In circular LL, the last node has to point to first node, hence
  we need a pointer to last node.
- using last node, we can get addres of first node(tail->next), but thats
  not possible with head pointer.
*/