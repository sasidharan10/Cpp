#include<iostream>
#include<stdio.h>
using namespace std;
int rear=-1,front=-1;
int n=10;  // size of array
int a[10];
bool isfull()
{
   return (rear+1)%n==front ? true:false;

}
bool isempty()
{
    return (front==-1 && rear==-1);
}
void enqueue(int x)
{
    if(isfull())
    {
        cout<<"\nQueue is full!!!"<<endl;
        return;
    }
    else if(isempty())
    {
        front=rear=0;
    }
    else
    {
        rear=(rear+1)%n;
    }
    a[rear]=x;
}
void dequeue()
{
    if(isempty())
    {
        cout<<"\nQueue is Empty!!!"<<endl;
        return;
    }
    else if(front==rear)
    {
        front=rear=-1;
    }
    else
    {
        front=(front+1)%n;
    }
}
void top()
{
    if(front==-1)
    {
        cout<<"\nQueue is empty!!!"<<endl;
        return;
    }
    else
    {
        cout<<"Front : "<<a[front]<<endl;
    }
}
void print()
{   
    if(isempty())
    {
        cout<<"\nQueue is Empty!!!"<<endl;
        return;
    }
    cout<<"\nQueue : ";
    int count=(rear+n-front)%n +1;
    for (int i = 0; i < count; i++)
    {
        int index=(front+i)%n;
        cout<<a[index]<<" ";
    }
    
}
int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    print();
    dequeue();
    dequeue();
    print();
    return 0;
}