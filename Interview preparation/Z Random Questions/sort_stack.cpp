#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
void sorting(stack<int>&s,int n)
{
    if(s.empty() || n<s.top())
    {
        s.push(n);
    }
    else
    {
        int temp=s.top();
        s.pop();
        sorting(s,n);
        s.push(temp);
    }
}
void stackSort(stack<int>&s)
{
    if(!s.empty())
    {
        int temp=s.top();
        s.pop();
        stackSort(s);
        sorting(s,temp);
    }
}
int main()
{
    stack<int>s;
    s.push(6);
    s.push(2);
    s.push(3);
    s.push(1);
    s.push(5);
    s.push(4);
    stackSort(s);
    cout<<"Stack : ";
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}