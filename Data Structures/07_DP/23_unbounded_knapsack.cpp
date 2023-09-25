#include <bits/stdc++.h>
using namespace std;
// Recursion
int unboundedKnapsackRecur(int ind, int w, int n, vector<int> &val, vector<int> &wt)
{
    if (ind == 0)
    {
        if (w % wt[ind] == 0)
            return (w / wt[ind]) * val[ind];
        else
            return 0;
    }
    int notTake = 0 + unboundedKnapsackRecur(ind - 1, w, n, val, wt);
    int take = -1e9;
    if (w >= wt[ind])
        take = val[ind] + unboundedKnapsackRecur(ind, w - wt[ind], n, val, wt);
    return max(take, notTake);
}
// Memoization
int unboundedKnapsackMem(int ind, int w, int n, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (w % wt[ind] == 0)
            return (w / wt[ind]) * val[ind];
        else
            return 0;
    }
    if (dp[ind][w] != -1)
        return dp[ind][w];
    int notTake = 0 + unboundedKnapsackMem(ind - 1, w, n, val, wt, dp);
    int take = -1e9;
    if (w >= wt[ind])
        take = val[ind] + unboundedKnapsackMem(ind, w - wt[ind], n, val, wt, dp);
    return dp[ind][w] = max(take, notTake);
}
// Tabulation
int unboundedKnapsackTab(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n, vector<int>(w + 1, 0));
    for (int wt = weight[0]; wt <= w; wt++)
    {
        if (wt % weight[0] == 0)
            dp[0][wt] = (wt / weight[0]) * profit[0];
    }
    for (int ind = 1; ind < n; ind++)
    {
        for (int wt = 0; wt <= w; wt++)
        {
            int notTake = 0 + dp[ind - 1][wt];
            int take = -1e9;
            if (wt >= weight[ind])
                take = profit[ind] + dp[ind][wt - weight[ind]];
            dp[ind][wt] = max(take, notTake);
        }
    }
    return dp[n - 1][w];
}
// Space Optimization
int unboundedKnapsackSpc(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<int> prev(w + 1, 0), cur(w + 1, 0);
    for (int wt = weight[0]; wt <= w; wt++)
    {
        if (wt % weight[0] == 0)
            prev[wt] = (wt / weight[0]) * profit[0];
    }
    for (int ind = 1; ind < n; ind++)
    {
        for (int wt = 0; wt <= w; wt++)
        {
            int notTake = 0 + prev[wt];
            int take = -1e9;
            if (wt >= weight[ind])
                take = profit[ind] + cur[wt - weight[ind]];
            cur[wt] = max(take, notTake);
        }
        prev = cur;
    }
    return prev[w];
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // return unboundedKnapsackRecur(n - 1, w, n, profit, weight);
    vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    // return unboundedKnapsackMem(n - 1, w, n, profit, weight, dp);
    // return unboundedKnapsackTab(n, w, profit, weight);
    return unboundedKnapsackSpc(n, w, profit, weight);
}
int main()
{
    int n = 3, W = 15;
    vector<int> profits{7, 2, 4}, weights{5, 10, 20};
    cout << "Max Profit: " << unboundedKnapsack(n, W, profits, weights);
    return 0;
}

/*

link: https://www.codingninjas.com/studio/problems/unbounded-knapsack_1215029

leetcode:

Youtube:

algorithm:

*/