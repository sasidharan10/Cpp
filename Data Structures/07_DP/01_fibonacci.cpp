#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int fib(int n, vector<int> &dp)
{
    // TC: O(n)  memoization
    // SC: O(n) + O(n)
    if (n <= 1)
        return n;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
}

int fib2(int n)
{

    // TC: O(n)
    // SC: O(1)

    int prev2 = 0;
    int prev1 = 1;
    for (int i = 2; i <= n; i++)
    {
        int cur = prev1 + prev2;
        prev2 = prev1;
        prev1 = cur;
    }
    cout << "prev: " << prev1 << endl;
    return prev1;
}

int main()
{
    int n = 5;
    vector<int> dp(n + 1, -1);
    cout << "Fib: " << fib(n, dp) << endl;
    cout << "Fib: " << fib2(n) << endl;
    return 0;
}