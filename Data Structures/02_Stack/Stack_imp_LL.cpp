#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
node *top;
void push(int x)
{
    node *temp = new node();
    temp->data = x;   // assigning value
    temp->next = top; // value in top is assigned to temp->next
    top = temp;
}
void pop()
{
    if (top == NULL)
    {
        cout << "Stack is empty!!!" << endl;
        return;
    }
    node *temp = top; // top node is assigned to  temp
    top = top->next;  // top is pointing to next element noe
    delete temp;      // deleting the top element
}
void getTop()
{
    if (top == NULL)
    {
        cout << "Stack is empty!!!" << endl;
        return;
    }
    cout << "Top: " << top->data << endl;
}
void print()
{
    if (top == NULL)
    {
        cout << "Stack is empty!!!" << endl;
        return;
    }
    node *temp = top;
    cout << "Stack is : ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    top = NULL;
    push(1);
    print();
    push(2);
    print();
    push(3);
    print();
    push(4);
    print();
    push(5);
    print();
    pop();
    print();
    pop();
    print();
    getTop();
    return 0;
}