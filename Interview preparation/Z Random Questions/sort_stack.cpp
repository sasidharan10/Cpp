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
    stack<int> s;
    for (int i = 1; i <= 5; i++)
    {
        s.push(i);
    }

    Reverse(s);
    
    cout<<"Reverse : ";
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}