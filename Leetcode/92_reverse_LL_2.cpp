#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};
node *insert(node *head, int n)
{
    node *temp1 = new node(n);
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
void print(node *p)
{

    cout << "\nList: ";
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}
node *reverseNth1(node *head, int left, int right)
{
    if (!head || left == right)
        return head;
    node *dummy = new node(0); // dummy to get head, since it will always point to head
    dummy->next = head;
    node *prevLast = dummy;
    node *current = head;
    for (int i = 0; i < left - 1; i++)
    {
        prevLast = current;
        current = current->next;
    }
    node *prev = NULL;
    node *nextNode;
    for (int i = 0; i < right - left + 1; i++)
    {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    prevLast->next->next = current;
    prevLast->next = prev;
    return dummy->next;
}
node *reverseNth2(node *head, int left, int right)
{
    // Optimised

    if (!head || left == right)
        return head;
    node *dummy = new node(0); // dummy to get head, since it will always point to head
    dummy->next = head;
    node *prevLast = dummy;
    node *current = head;
    for (int i = 0; i < left - 1; i++)
    {
        prevLast = current;
        current = current->next;
    }
    node *extractNode;
    for (int i = 0; i < right - left; i++)
    {
        extractNode = current->next;
        current->next = extractNode->next;
        extractNode->next = prevLast->next;
        prevLast->next = extractNode;
    }
    return dummy->next;
}
int main()
{
    node *head = NULL; //
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 4);
    head = insert(head, 5);
    print(head);
    head = reverseNth1(head, 2, 4);
    print(head);
    head = reverseNth1(head, 1, 3);
    print(head);
    return 0;
}