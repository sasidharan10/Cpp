#include<iostream>
#define max_size 100
using namespace std;
int a[max_size];
int top=-1;
void push(int x)
{
    if(top==max_size-1)
    {
        cout<<"Stack overflow!!!";
        return;
    }
    a[++top]=x;
}
void pop()
{
    if(top==-1)
    {
        cout<<"Stack is Empty!!!";
        return;
    }
    top--;
}
void print()
{
    if(top==-1)
    {
        cout<<"Stack is Empty!!!";
        return;
    }
    cout<<"Stack is : ";
    for (int i = 0; i <= top; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl; 
}
void getTop()
{
    if(top==-1)
    {
        cout<<"Stack is Empty!!!";
        return;
    }
    cout<<"top: "<<a[top]<<endl;
}
int main()
{
    push(1);  print();   
    push(2);  print();  
    push(3);  print();  
    push(4);  print();  
    push(5);  print();  
    pop();  print();
    pop();  print();
    getTop();
    return 0;
}