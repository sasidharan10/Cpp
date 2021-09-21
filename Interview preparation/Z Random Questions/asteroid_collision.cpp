#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
void collision(vector<int> &v)
{
    stack<int> s;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] > 0)
            s.push(v[i]);
        else
        {
            while (!s.empty() && s.top() > 0 && s.top() < (-v[i]))
                s.pop();
            if (!s.empty() && s.top() == (-v[i]))
                s.pop();
            else if (!s.empty() && s.top() > (-v[i]))
                continue;
            else
                s.push(v[i]);
        }
    }
    int n=s.size();
    vector<int>ans(n);
    while (n--)
    {
        ans[n]=s.top();
        s.pop();
    }
    cout << "Resultant array : ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}
int main()
{
    vector<int> v{5, 10, -5};
    collision(v);
    return 0;
}