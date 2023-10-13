#include <bits/stdc++.h>
using namespace std;
// Recursion
int getMaximumProfitRecur(int ind, bool buy, int fee, vector<int> prices, int n)
{
    if (ind == n)
        return 0;
    int profit = 0;
    if (buy)
        profit = max(-prices[ind] + getMaximumProfitRecur(ind + 1, false, fee, prices, n), getMaximumProfitRecur(ind + 1, true, fee, prices, n));
    else
        profit = max(prices[ind] - fee + getMaximumProfitRecur(ind + 1, true, fee, prices, n), getMaximumProfitRecur(ind + 1, false, fee, prices, n));
    return profit;
}
// Memoization
int getMaximumProfitMem(int ind, bool buy, int fee, vector<int> prices, int n, vector<vector<int>> &dp)
{
    if (ind == n)
        return 0;
    int profit = 0;
    if (dp[ind][buy] != -1)
        return dp[ind][buy];
    if (buy)
        profit = max(-prices[ind] + getMaximumProfitMem(ind + 1, false, fee, prices, n, dp), getMaximumProfitMem(ind + 1, true, fee, prices, n, dp));
    else
        profit = max(prices[ind] - fee + getMaximumProfitMem(ind + 1, true, fee, prices, n, dp), getMaximumProfitMem(ind + 1, false, fee, prices, n, dp));
    return dp[ind][buy] = profit;
}
// Tabulation
int getMaximumProfitTab(vector<int> prices, int fee, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    dp[n][0] = 0;
    dp[n][1] = 0;
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            int profit = 0;
            if (buy)
                profit = max(-prices[ind] + dp[ind + 1][0], dp[ind + 1][1]);
            else
                profit = max(prices[ind] - fee + dp[ind + 1][1], dp[ind + 1][0]);
            dp[ind][buy] = profit;
        }
    }
    return dp[0][1];
}
// Space Optimization
int getMaximumProfitSpc(vector<int> prices, int fee, int n)
{
    vector<int> ahead(2, 0), cur(2, 0);
    ahead[0] = 0;
    ahead[1] = 0;
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            int profit = 0;
            if (buy)
                profit = max(-prices[ind] + ahead[0], ahead[1]);
            else
                profit = max(prices[ind] - fee + ahead[1], ahead[0]);
            cur[buy] = profit;
        }
        ahead = cur;
    }
    return ahead[1];
}
int getMaximumProfit(vector<int> prices, int n, int fee)
{
    // return getMaximumProfitRecur(0, true, fee, prices, n);
    vector<vector<int>> dp(n, vector<int>(2, -1));
    // return getMaximumProfitMem(0, true, fee, prices, n, dp);
    // return getMaximumProfitTab(prices, fee, n);
    return getMaximumProfitSpc(prices, fee, n);
}
int main()
{
    vector<int> nums{1, 3, 2, 8, 4, 9};
    int n = 6;
    int fee = 2;
    cout << "Max Profit: " << getMaximumProfit(nums, n, fee);
    return 0;
}

/*

link: https://www.codingninjas.com/studio/problems/rahul-and-his-chocolates_3118974

leetcode: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

Youtube: https://www.youtube.com/watch?v=k4eK-vEmnKg&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=41

algorithm:

*/