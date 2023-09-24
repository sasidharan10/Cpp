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
// Space Optimization

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    // return knapsackRecur(n - 1, maxWeight, weight, value);
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    return knapsackMem(n - 1, maxWeight, weight, value, dp);
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