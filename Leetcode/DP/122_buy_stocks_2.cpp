#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Recursion
    int maxProfitRecur(int ind, bool buy, vector<int> &prices)
    {
        int n = prices.size();
        if (ind == n)
            return 0;
        int profit = 0;
        if (buy)
            profit = max(-prices[ind] + maxProfitRecur(ind + 1, false, prices), maxProfitRecur(ind + 1, true, prices));
        else
            profit = max(prices[ind] + maxProfitRecur(ind + 1, true, prices), maxProfitRecur(ind + 1, false, prices));
        return profit;
    }
    // Memoization
    int maxProfitMem(int ind, bool buy, vector<int> &prices, vector<vector<int>> &dp)
    {
        int n = prices.size();
        if (ind == n)
            return 0;
        int profit = 0;
        if (dp[ind][buy] != -1)
            return dp[ind][buy];
        if (buy)
            profit = max(-prices[ind] + maxProfitMem(ind + 1, false, prices, dp), maxProfitMem(ind + 1, true, prices, dp));
        else
            profit = max(prices[ind] + maxProfitMem(ind + 1, true, prices, dp), maxProfitMem(ind + 1, false, prices, dp));
        return dp[ind][buy] = profit;
    }

    // Tabulation
    int maxProfitTab(vector<int> &prices)
    {
        int n = prices.size();
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
                    profit = max(prices[ind] + dp[ind + 1][1], dp[ind + 1][0]);
                dp[ind][buy] = profit;
            }
        }
        return dp[0][1];
    }
    // Space Optimization
    int maxProfitSpc(vector<int> &prices)
    {
        int n = prices.size();
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
                    profit = max(prices[ind] + ahead[1], ahead[0]);
                cur[buy] = profit;
            }
            ahead = cur;
        }
        return ahead[1];
    }
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        // return maxProfitRecur(0, true, prices);
        vector<vector<int>> dp(n, vector<int>(2, -1));
        // return maxProfitMem(0, true, prices, dp);
        // return maxProfitTab(prices);
        return maxProfitSpc(prices);
    }
};
int main()
{
    Solution s;
    vector<int> nums{1, 2, 3, 4, 5, 6, 7};
    cout << "Max Profit: " << s.maxProfit(nums);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

Youtube: https://www.youtube.com/watch?v=nGJmxkUJQGs&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=38

algorithm:

*/