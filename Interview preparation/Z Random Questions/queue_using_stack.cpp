#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
void Insert(stack<int> &s, int n)
{
    if (s.empty())
    {
        s.push(n);
        return;
    }
    else
    {
        int temp = s.top();
        s.pop();
        Insert(s, n);
        s.push(temp);
    }
}
int main()
{
    stack<int> s, s1;
    for (int i = 1; i <= 5; i++)
    {
        Insert(s, i);
    }

    cout << "Stack using Queue : ";
    Insert(s,6);
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}