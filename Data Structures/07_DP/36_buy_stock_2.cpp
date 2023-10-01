#include <bits/stdc++.h>
using namespace std;
// Recursion
long getMaximumProfitRecur(int ind, bool buy, long *values, int n)
{
    if (ind == n)
        return 0;
    long profit = 0;
    if (buy)
        profit = max(-values[ind] + getMaximumProfitRecur(ind + 1, false, values, n), getMaximumProfitRecur(ind + 1, true, values, n));
    else
        profit = max(values[ind] + getMaximumProfitRecur(ind + 1, true, values, n), getMaximumProfitRecur(ind + 1, false, values, n));
    return profit;
}
// Memoization
long getMaximumProfitMem(int ind, bool buy, long *values, int n, vector<vector<long>> &dp)
{
    if (ind == n)
        return 0;
    long profit = 0;
    if (dp[ind][buy] != -1)
        return dp[ind][buy];
    if (buy)
        profit = max(-values[ind] + getMaximumProfitMem(ind + 1, false, values, n, dp), getMaximumProfitMem(ind + 1, true, values, n, dp));
    else
        profit = max(values[ind] + getMaximumProfitMem(ind + 1, true, values, n, dp), getMaximumProfitMem(ind + 1, false, values, n, dp));
    return dp[ind][buy] = profit;
}
// Tabulation
long getMaximumProfitTab(long *values, int n)
{
    vector<vector<long>> dp(n + 1, vector<long>(2, 0));
    dp[n][0] = 0;
    dp[n][1] = 0;
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            long profit = 0;
            if (buy)
                profit = max(-values[ind] + dp[ind + 1][0], dp[ind + 1][1]);
            else
                profit = max(values[ind] + dp[ind + 1][1], dp[ind + 1][0]);
            dp[ind][buy] = profit;
        }
    }
    return dp[0][1];
}
// Space Optimization
long getMaximumProfitSpc(long *values, int n)
{
    vector<long> ahead(2, 0), cur(2, 0);
    ahead[0] = 0;
    ahead[1] = 0;
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            long profit = 0;
            if (buy)
                profit = max(-values[ind] + ahead[0], ahead[1]);
            else
                profit = max(values[ind] + ahead[1], ahead[0]);
            cur[buy] = profit;
        }
        ahead = cur;
    }
    return ahead[1];
}
long getMaximumProfit(long *values, int n)
{
    // return getMaximumProfitRecur(0, true, values, n);
    vector<vector<long>> dp(n, vector<long>(2, -1));
    // return getMaximumProfitMem(0, true, values, n, dp);
    // return getMaximumProfitTab(values, n);
    return getMaximumProfitSpc(values, n);
}
int main()
{
    long nums[]{1, 2, 3, 4, 5, 6, 7};
    int n = 7;
    cout << "Max Profit: " << getMaximumProfit(nums, n);
    return 0;
}

/*

link: https://www.codingninjas.com/studio/problems/selling-stock_630282

leetcode: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

Youtube: https://www.youtube.com/watch?v=nGJmxkUJQGs&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=38

algorithm:

*/