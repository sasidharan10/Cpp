#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
class Stack
{
    queue<int>q1,q2;
    public:
    int size;
    Stack()
    {
        size=0;
    }
    void Push(int x)
    {
        q1.push(x);
        while(!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
        swap(q1,q2);
        size++;
    }
    void Pop()
    {
        if(q2.empty())
        {
            cout<<"Empty!!!";
            return;
        }
        q2.pop();
        size--;
    }
    int Top()
    {
        if(q2.empty())
        {
            cout<<"Empty!!!";
            return 0;
        }
        return q2.front();
    }
    int Size()
    {
        return size;
    }
};
int main()
{
    Stack s;
    s.Push(5);
    s.Push(4);
    s.Push(3);
    s.Push(2);
    s.Push(1);
    while (s.Size())
    {
        cout<<s.Top()<<" ";
        s.Pop();
    }
    return 0;
}