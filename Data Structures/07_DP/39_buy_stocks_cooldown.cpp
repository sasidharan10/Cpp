#include <bits/stdc++.h>
using namespace std;
// Recursion
int maxProfitRecur(int ind, bool buy, bool cooldown, vector<int> &prices, int n)
{
    // TC: Exponential
    // SC: O(n + m + cooldown)

    if (ind == n)
        return 0;
    if (buy)
    {
        if (cooldown)
        {
            return max(-prices[ind] + maxProfitRecur(ind + 1, false, false, prices, n), maxProfitRecur(ind + 1, true, cooldown, prices, n));
        }
        return maxProfitRecur(ind + 1, true, true, prices, n);
    }
    return max(prices[ind] + maxProfitRecur(ind + 1, true, false, prices, n), maxProfitRecur(ind + 1, false, cooldown, prices, n));
}
// Memoization
int maxProfitMem(int ind, bool buy, bool cooldown, vector<int> &prices, int n, vector<vector<vector<int>>> &dp)
{
    // TC: O(n * m * cooldown)
    // SC: O(n * m * cooldown) + O(n + m + cooldown)

    if (ind == n)
        return 0;
    if (dp[ind][buy][cooldown] != -1)
        return dp[ind][buy][cooldown];
    if (buy)
    {
        if (cooldown)
        {
            return dp[ind][buy][cooldown] = max(-prices[ind] + maxProfitMem(ind + 1, false, false, prices, n, dp), maxProfitMem(ind + 1, true, cooldown, prices, n, dp));
        }
        return dp[ind][buy][cooldown] = maxProfitMem(ind + 1, true, true, prices, n, dp);
    }
    return dp[ind][buy][cooldown] = max(prices[ind] + maxProfitMem(ind + 1, true, false, prices, n, dp), maxProfitMem(ind + 1, false, cooldown, prices, n, dp));
}
// Tabulation
int maxProfitTab(vector<int> &prices)
{
    // TC: O(n * m * cooldown)
    // SC: O(n * m * cooldown)

    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(2, 0)));

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy < 2; buy++)
        {
            for (int cooldown = 0; cooldown < 2; cooldown++)
            {
                if (buy)
                {
                    if (cooldown)
                        dp[ind][buy][cooldown] = max(-prices[ind] + dp[ind + 1][0][0], dp[ind + 1][1][cooldown]);
                    else
                        dp[ind][buy][cooldown] = dp[ind + 1][1][1];
                }
                else
                {
                    dp[ind][buy][cooldown] = max(prices[ind] + dp[ind + 1][1][0], dp[ind + 1][0][cooldown]);
                }
            }
        }
    }
    return dp[0][1][1];
}
// Space Optimization
int maxProfitSpc(vector<int> &prices)
{
    // TC: O(n * m * cooldown)
    // SC: O(m * cooldown)

    int n = prices.size();
    vector<vector<int>> ahead(2, vector<int>(2, 0)), cur(2, vector<int>(2, 0));

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy < 2; buy++)
        {
            for (int cooldown = 0; cooldown < 2; cooldown++)
            {
                if (buy)
                {
                    if (cooldown)
                        cur[buy][cooldown] = max(-prices[ind] + ahead[0][0], ahead[1][cooldown]);
                    else
                        cur[buy][cooldown] = ahead[1][1];
                }
                else
                {
                    cur[buy][cooldown] = max(prices[ind] + ahead[1][0], ahead[0][cooldown]);
                }
            }
        }
        ahead = cur;
    }
    return cur[1][1];
}

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    // return maxProfitRecur(0, true, true, prices, n);
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(2, -1)));
    // return maxProfitMem(0, true, 2, prices, n, dp);
    // return maxProfitTab(prices);
    return maxProfitSpc(prices);
}
int main()
{
    vector<int> nums{1, 2, 3, 0, 2};
    cout << "Max Profit (with cooldown): " << maxProfit(nums);
    return 0;
}

/*

link: https://www.codingninjas.com/studio/problems/highway-billboards_3125969

leetcode: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/

Youtube: https://www.youtube.com/watch?v=IGIe46xw3YY&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=40

algorithm:

*/