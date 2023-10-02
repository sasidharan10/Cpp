#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Recursion
    int maxProfitRecur(int ind, int trano, vector<int> &prices, int n, int k)
    {
        if (ind == n || trano == 2 * k)
            return 0;
        if (trano % 2 == 0)
        {
            return max(-prices[ind] + maxProfitRecur(ind + 1, trano + 1, prices, n, k), maxProfitRecur(ind + 1, trano, prices, n, k));
        }
        return max(prices[ind] + maxProfitRecur(ind + 1, trano + 1, prices, n, k), maxProfitRecur(ind + 1, trano, prices, n, k));
    }
    // Memoization
    int maxProfitMem(int ind, int trano, vector<int> &prices, int n, int k, vector<vector<int>> &dp)
    {
        if (ind == n || trano == 2 * k)
            return 0;
        if (dp[ind][trano] != -1)
            return dp[ind][trano];
        if (trano % 2 == 0)
        {
            return dp[ind][trano] = max(-prices[ind] + maxProfitMem(ind + 1, trano + 1, prices, n, k, dp), maxProfitMem(ind + 1, trano, prices, n, k, dp));
        }
        return dp[ind][trano] = max(prices[ind] + maxProfitMem(ind + 1, trano + 1, prices, n, k, dp), maxProfitMem(ind + 1, trano, prices, n, k, dp));
    }
    // Tabulation
    int maxProfitTab(vector<int> &prices, int k)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));
        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int trano = 2 * k - 1; trano >= 0; trano--)
            {
                if (trano % 2 == 0)
                {
                    dp[ind][trano] = max(-prices[ind] + dp[ind + 1][trano + 1], dp[ind + 1][trano]);
                }
                else
                {
                    dp[ind][trano] = max(prices[ind] + dp[ind + 1][trano + 1], dp[ind + 1][trano]);
                }
            }
        }
        return dp[0][0];
    }
    // Space Optimization
    int maxProfitSpc(vector<int> &prices, int k)
    {
        int n = prices.size();
        vector<int> ahead(2 * k + 1, 0), cur(2 * k + 1, 0);
        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int trano = 2 * k - 1; trano >= 0; trano--)
            {
                if (trano % 2 == 0)
                {
                    cur[trano] = max(-prices[ind] + ahead[trano + 1], ahead[trano]);
                }
                else
                {
                    cur[trano] = max(prices[ind] + ahead[trano + 1], ahead[trano]);
                }
            }
            ahead = cur;
        }
        return ahead[0];
    }

    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        // return maxProfitRecur(0, 0, prices, n, k);
        vector<vector<int>> dp(n, vector<int>(2 * k, -1));
        // return maxProfitMem(0, 0, prices, n, k, dp);
        return maxProfitTab(prices, k);
        // return maxProfitSpc(prices, k);
    }
};
int main()
{
    Solution s;
    vector<int> nums{3, 2, 6, 5, 0, 3};
    int k = 2;
    cout << "Max Profit (k transactions): " << s.maxProfit(k, nums);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

Youtube: https://www.youtube.com/watch?v=IV1dHbk5CDc&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=39

algorithm:

*/