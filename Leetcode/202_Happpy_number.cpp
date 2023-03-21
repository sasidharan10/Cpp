#include <iostream>
#include <unordered_set>
using namespace std;
int numSquare(int n)
{
    int ans = 0, rem;
    while (n > 0)
    {
        rem = n % 10;
        n = n / 10;
        ans += (rem * rem);
    }
    return ans;
}
bool isHappy(int n)
{
    unordered_set<int> s;
    while (1)
    {
        n = numSquare(n);
        if (n == 1)
            return true;
        if (s.find(n) != s.end())
            return false;
        s.insert(n);
    }
}
int main()
{
    int n = 20;
    if (isHappy(n))
        cout << "Yes, Happy number!" << endl;
    else
        cout << "No!!!" << endl;
    return 0;
}