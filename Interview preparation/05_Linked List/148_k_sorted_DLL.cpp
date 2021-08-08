#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *prev;
};
class compare
{
public:
    bool operator()(node *p1, node *p2)
    {
        return p1->data > p2->data;
    }
};
void Insert(node **head, int n)
{
    node *temp = new node();
    temp->data = n;
    temp->next = NULL;
    temp->prev = NULL;
    if (*head == NULL)
    {
        *head = temp;
        return;
    }
    (*head)->prev = temp;
    temp->next = *head;
    *head = temp;
}
void print(node *head)
{
    cout << "\nList : ";
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
void sortDLL1(node *head)
{
    node *temp = head;
    for (node *i = head->next; i != NULL; i = i->next)
    {
        int key = i->data;
        node *index = i;
        while (index->prev != NULL && index->prev->data > key)
        {
            index->data = index->prev->data;
            index = index->prev;
        }
        index->data = key;
    }
}
void sortDLL2(node *head, int k)
{
    priority_queue<int, vector<int>, greater<>> pq;
    int count = 0;
    node *temp = head;
    while (count <= k) // push k+1 elements in stack
    {
        pq.push(temp->data);
        temp = temp->next;
        count++;
    }
    node *current = head;
    while (!pq.empty())
    {
        current->data = pq.top();
        pq.pop();
        current = current->next;
        if (temp != NULL)
        {
            pq.push(temp->data);
            temp = temp->next;
        }
    }
}
node *sortDLL3(node *head, int k)
{
    node *temp = head;
    node *newHead = NULL;
    node *current;
    int count = 0;
    priority_queue<node *, vector<node *>, compare> pq;
    while (count <= k)
    {
        pq.push(temp);
        temp = temp->next;
        count++;
    }
    while (!pq.empty())
    {
        if (newHead == NULL)
        {
            newHead = pq.top();
            newHead->prev = NULL;
            current = newHead;
        }
        else
        {
            current->next = pq.top();
            pq.top()->prev = current;
            current = pq.top();
        }
        pq.pop();
        if (temp != NULL)
        {
            pq.push(temp);
            temp = temp->next;
        }
    }
    current->next = NULL;
    return newHead;
}
int main()
{
    node *head = NULL;
    int k = 2;
    Insert(&head, 9);
    Insert(&head, 8);
    Insert(&head, 56);
    Insert(&head, 12);
    Insert(&head, 2);
    Insert(&head, 6);
    Insert(&head, 3);
    print(head);
    // sortDLL1(head);
    sortDLL2(head, k);
    // head = sortDLL3(head, k);
    print(head);
    // findPair(head, sum);
    return 0;
}