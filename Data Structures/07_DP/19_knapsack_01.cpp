#include <bits/stdc++.h>
using namespace std;
// Recursion
int knapsackRecur(int ind, int W, vector<int> wt, vector<int> val)
{
    if (ind == 0)
    {
        if (W >= wt[ind])
            return val[ind];
        else
            return 0;
    }
    int NotTake = 0 + knapsackRecur(ind - 1, W, wt, val);
    int take = -1e9;
    if (W >= wt[ind])
    {
        take = val[ind] + knapsackRecur(ind - 1, W - wt[ind], wt, val);
    }
    return max(take, NotTake);
}
// Memoization
int knapsackMem(int ind, int W, vector<int> wt, vector<int> val, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (W >= wt[ind])
            return val[ind];
        else
            return 0;
    }
    if (dp[ind][W] != -1)
        return dp[ind][W];
    int NotTake = 0 + knapsackMem(ind - 1, W, wt, val, dp);
    int take = -1e9;
    if (W >= wt[ind])
    {
        take = val[ind] + knapsackMem(ind - 1, W - wt[ind], wt, val, dp);
    }
    return dp[ind][W] = max(take, NotTake);
}
// Tabulation
int knapsackTab(int n, int maxWeight, vector<int> wt, vector<int> val)
{
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));
    for (int W = wt[0]; W <= maxWeight; W++)
    {
        dp[0][W] = val[0];
    }
    for (int ind = 1; ind < n; ind++)
    {
        for (int W = 0; W <= maxWeight; W++)
        {
            int NotTake = 0 + dp[ind - 1][W];
            int take = -1e9;
            if (W >= wt[ind])
            {
                take = val[ind] + dp[ind - 1][W - wt[ind]];
            }
            dp[ind][W] = max(take, NotTake);
        }
    }
    return dp[n - 1][maxWeight];
}
// Space Optimization
int knapsackSpc(int n, int maxWeight, vector<int> wt, vector<int> val)
{
    vector<int> prev(maxWeight + 1, 0), cur(maxWeight + 1, 0);
    for (int W = wt[0]; W <= maxWeight; W++)
    {
        prev[W] = val[0];
    }
    for (int ind = 1; ind < n; ind++)
    {
        for (int W = 0; W <= maxWeight; W++)
        {
            int NotTake = 0 + prev[W];
            int take = -1e9;
            if (W >= wt[ind])
            {
                take = val[ind] + prev[W - wt[ind]];
            }
            cur[W] = max(take, NotTake);
        }
        prev = cur;
    }
    return prev[maxWeight];
}
// more Space Optimization
int knapsackSpc2(int n, int maxWeight, vector<int> wt, vector<int> val)
{
    vector<int> prev(maxWeight + 1, 0), cur(maxWeight + 1, 0);
    for (int W = wt[0]; W <= maxWeight; W++)
    {
        prev[W] = val[0];
    }
    for (int ind = 1; ind < n; ind++)
    {
        for (int W = maxWeight; W >= 0; W--)
        {
            int NotTake = 0 + prev[W];
            int take = -1e9;
            if (W >= wt[ind])
            {
                take = val[ind] + prev[W - wt[ind]];
            }
            prev[W] = max(take, NotTake);
        }
    }
    return prev[maxWeight];
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    // return knapsackRecur(n - 1, maxWeight, weight, value);
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    // return knapsackMem(n - 1, maxWeight, weight, value, dp);
    // return knapsackTab(n, maxWeight, weight, value);
    return knapsackSpc2(n, maxWeight, weight, value);
}
int main()
{
    int n = 4;
    vector<int> wt{1, 2, 4, 5};
    vector<int> val{5, 4, 8, 6};
    int W = 5;
    cout << "Max Profit: " << knapsack(wt, val, n, W);
    return 0;
}

/*

link: https://www.codingninjas.com/studio/problems/0-1-knapsack_920542

leetcode:

Youtube: https://www.youtube.com/watch?v=GqOmJHQZivw&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=22

algorithm:

*/