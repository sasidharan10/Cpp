#include <bits/stdc++.h>
using namespace std;
// Recursion
int maxProfitRecur(int ind, bool buy, int cap, vector<int> &prices, int n)
{
    // TC: Exponential
    // SC: O(n + m + cap)

    if (ind == n || cap == 0)
        return 0;
    if (buy)
    {
        return max(-prices[ind] + maxProfitRecur(ind + 1, false, cap, prices, n), maxProfitRecur(ind + 1, true, cap, prices, n));
    }
    return max(prices[ind] + maxProfitRecur(ind + 1, true, cap - 1, prices, n), maxProfitRecur(ind + 1, false, cap, prices, n));
}
// Memoization
int maxProfitMem(int ind, bool buy, int cap, vector<int> &prices, int n, vector<vector<vector<int>>> &dp)
{
    // TC: O(n * m * cap)
    // SC: O(n * m * cap) + O(n + m + cap)

    if (ind == n || cap == 0)
        return 0;
    if (dp[ind][buy][cap] != -1)
        return dp[ind][buy][cap];
    if (buy)
    {
        return dp[ind][buy][cap] = max(-prices[ind] + maxProfitMem(ind + 1, false, cap, prices, n, dp), maxProfitMem(ind + 1, true, cap, prices, n, dp));
    }
    return dp[ind][buy][cap] = max(prices[ind] + maxProfitMem(ind + 1, true, cap - 1, prices, n, dp), maxProfitMem(ind + 1, false, cap, prices, n, dp));
}
// Tabulation
int maxProfitTab(vector<int> &prices)
{
    // TC: O(n * m * cap)
    // SC: O(n * m * cap)

    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy < 2; buy++)
        {
            for (int cap = 1; cap < 3; cap++)
            {
                if (buy)
                {
                    dp[ind][buy][cap] = max(-prices[ind] + dp[ind + 1][0][cap], dp[ind + 1][1][cap]);
                }
                else
                {
                    dp[ind][buy][cap] = max(prices[ind] + dp[ind + 1][1][cap - 1], dp[ind + 1][0][cap]);
                }
            }
        }
    }
    for (auto &&i : dp)
    {
        for (auto &&j : i)
        {
            for (auto &&k : j)
            {
                cout << k << " ";
            }
            cout << endl;
        }
        cout << endl
             << endl;
    }
    cout << endl;
    return dp[0][1][2];
}
// Space Optimization
int maxProfitSpc(vector<int> &prices)
{
    // TC: O(n * m * cap)
    // SC: O(m * cap)

    int n = prices.size();
    vector<vector<int>> ahead(2, vector<int>(3, 0)), cur(2, vector<int>(3, 0));

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy < 2; buy++)
        {
            for (int cap = 1; cap < 3; cap++)
            {
                if (buy)
                {
                    cur[buy][cap] = max(-prices[ind] + ahead[0][cap], ahead[1][cap]);
                }
                else
                {
                    cur[buy][cap] = max(prices[ind] + ahead[1][cap - 1], ahead[0][cap]);
                }
            }
        }
        ahead = cur;
    }
    return cur[1][2];
}

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    // return maxProfitRecur(0, true, 2, prices, n);
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
    // return maxProfitMem(0, true, 2, prices, n, dp);
    // return maxProfitTab(prices);
    return maxProfitSpc(prices);
}
int main()
{
    vector<int> nums{1, 3, 1, 2, 4, 8};
    cout << "Max Profit (only 2 transaction): " << maxProfit(nums);
    return 0;
}

/*

link: https://www.codingninjas.com/studio/problems/buy-and-sell-stock_1071012

leetcode:

Youtube:

algorithm:

*/