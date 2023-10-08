#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Recursion
    int integerBreakRecur(int n)
    {
        // TC: O(n^n-1), exponential
        // SC: O(n * n - 1)

        if (n == 1)
            return 1;
        int res = INT_MIN;
        for (int i = 1; i < n; i++)
        {
            int prod = i * max(n - i, integerBreakRecur(n - i));
            res = max(res, prod);
        }
        return res;
    }
    // Memoization
    int integerBreakMem(int n, vector<int> &dp)
    {
        if (n == 1)
            return 1;
        if (dp[n] != -1)
            return dp[n];
        int res = INT_MIN;
        for (int i = 1; i < n; i++)
        {
            int prod = i * max(n - i, integerBreakMem(n - i, dp));
            res = max(res, prod);
        }
        return dp[n] = res;
    }
    // Tabulation
    int integerBreakTab(int n)
    {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        int res = INT_MIN;
        for (int i = n - 1; i >= 0; i--)
        {
            int prod = i * max(n - i, dp[n - i]);
            res = max(res, prod);
            dp[i] = res;
        }
        return dp[1];
    }
    // Space Optimization

    int integerBreak(int n)
    {
        // return integerBreakRecur(n);
        vector<int> dp(n + 1, -1);
        // return integerBreakMem(n, dp);
        return integerBreakTab(n);
    }
};
int main()
{
    Solution s;
    int n = 10;
    cout << "Max Product by dividing into k elements: " << s.integerBreak(n);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/integer-break/?envType=daily-question&envId=2023-10-06

Youtube: https://www.youtube.com/watch?v=iXtqfIrWMZg

algorithm:

*/