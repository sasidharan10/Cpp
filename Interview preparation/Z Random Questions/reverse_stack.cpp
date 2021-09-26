#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
void bottom(stack<int> &s,int n)
{
    if(s.empty())
    {
        s.push(n);
    }
    else
    {
        int temp=s.top();
        s.pop();
        bottom(s,n);
        s.push(temp);
    }
}
void Reverse(stack<int> &s)
{
    if (!s.empty())
    {
        int temp = s.top();
        s.pop();
        Reverse(s);
        bottom(s,temp);
    }
}
int main()
{
    stack<int> s,s1;
    for (int i = 1; i <= 5; i++)
    {
        s.push(i);
        s1.push(i);
    }
    cout<<"Stack : ";
    while (!s1.empty())
    {
        cout << s1.top() << " ";
        s1.pop();
    }
    Reverse(s);
    
    cout<<"\nReverse : ";
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}