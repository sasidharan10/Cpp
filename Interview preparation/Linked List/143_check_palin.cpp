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
    cout << "\nList is : ";
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
bool checkPalindrome(node *head)
{
    node *low = head;
    node *high = head;
    while (high != NULL && high->next != NULL)
    {
        low = low->next;
        high = high->next->next;
    }
    node *current = low;
    high = head;

    // Reverse second half :

    node *prev = NULL;
    node *nextNode;
    while (current != NULL)
    {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    // print(head);
    // checking Palindrome

    while (prev != NULL)
    {
        if (prev->data != high->data)
            return false;
        prev = prev->next;
        high = high->next;
    }
    return true;
}
int main()
{
    node *head = NULL;
    Insert(&head, 1);
    Insert(&head, 2);
    Insert(&head, 3);
    Insert(&head, 3);
    Insert(&head, 2);
    Insert(&head, 1);
    print(head);
    cout<<"\nPalindrome ? : "<<checkPalindrome(head);
    return 0;
}