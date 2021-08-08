#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;
class node
{
public:
    int data;
    node *next;
};
node *head;
void Insert(int a)
{
    node *temp = new node();
    temp->data = a;
    temp->next = head;
    head = temp;
}
void print()
{
    node *temp = head;
    cout << "\nList : ";
    int count = 0;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
        count++;
        if (count == 15)
            break;
    }
}
bool detectLoop1()
{
    // Time  : O(n)
    // Space : O(n)

    node *temp = head;
    unordered_set<node *> hash;
    while (temp != NULL)
    {
        if (hash.find(temp) != hash.end())
            return true; // loop detected

        hash.insert(temp);
        temp = temp->next;
    }
    return false;
}
bool detectLoop2()
{
    // Floyd - cycle detection

    // Time  : O(n)
    // Space : O(1)
    node *low = head;
    node *high = head;
    while (high != NULL && high->next != NULL)
    {
        low = low->next;
        high = high->next->next;
        if (low == high)
            return true; // loop detected
    }
    return false;
}
int main()
{
    head = NULL;
    Insert(5);
    Insert(4);
    Insert(3);
    Insert(2);
    Insert(1);
    head->next->next->next->next->next = head->next->next;
    print();
    cout << "\nLoop Exist ? : " << detectLoop1() << endl;
    cout << "Loop Exist ? : " << detectLoop2() << endl;
    return 0;
}