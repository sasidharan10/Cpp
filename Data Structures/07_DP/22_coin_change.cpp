#include <bits/stdc++.h>
using namespace std;
// Recursion
long countWaysToMakeChangeRecur(int ind, int target, int *arr, int n)
{
    if (ind == 0)
    {
        if (target % arr[ind] == 0)
            return 1;
        else
            return 0;
    }
    long notTake = countWaysToMakeChangeRecur(ind - 1, target, arr, n);
    long take = 0;
    if (target >= arr[ind])
    {
        take = countWaysToMakeChangeRecur(ind, target - arr[ind], arr, n);
    }
    return take + notTake;
}
// Memoization
long countWaysToMakeChangeMem(int ind, int target, int *arr, int n, vector<vector<long>> &dp)
{
    if (ind == 0)
    {
        if (target % arr[ind] == 0)
            return 1;
        else
            return 0;
    }
    if (dp[ind][target] != -1)
        return dp[ind][target];
    long notTake = countWaysToMakeChangeMem(ind - 1, target, arr, n, dp);
    long take = 0;
    if (target >= arr[ind])
    {
        take = countWaysToMakeChangeMem(ind, target - arr[ind], arr, n, dp);
    }
    return dp[ind][target] = (take + notTake);
}
// Tabulation
long countWaysToMakeChangeTab(int *arr, int n, int value)
{
    vector<vector<long>> dp(n, vector<long>(value + 1, 0));
    for (int target = 0; target <= value; target++)
    {
        if (target % arr[0] == 0)
            dp[0][target] = 1;
    }
    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 0; target <= value; target++)
        {
            long notTake = dp[ind - 1][target];
            long take = 0;
            if (target >= arr[ind])
            {
                take = dp[ind][target - arr[ind]];
            }
            dp[ind][target] = (take + notTake);
        }
    }
    return dp[n - 1][value];
}
// Space Optimization
long countWaysToMakeChangeSpc(int *arr, int n, int value)
{
    vector<long> prev(value + 1, 0), cur(value + 1, 0);
    for (int target = 0; target <= value; target++)
    {
        if (target % arr[0] == 0)
            prev[target] = 1;
    }
    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 0; target <= value; target++)
        {
            long notTake = prev[target];
            long take = 0;
            if (target >= arr[ind])
            {
                take = cur[target - arr[ind]];
            }
            cur[target] = (take + notTake);
        }
        prev = cur;
    }
    return prev[value];
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    // return countWaysToMakeChangeRecur(n - 1, value, denominations, n);
    vector<vector<long>> dp(n, vector<long>(value + 1, -1));
    // return countWaysToMakeChangeMem(n - 1, value, denominations, n, dp);
    // return countWaysToMakeChangeTab(denominations, n, value);
    return countWaysToMakeChangeSpc(denominations, n, value);
}
int main()
{
    int nums[]{1, 2, 3};
    int n = 3;
    int val = 4;
    cout << "No of ways to make change: " << countWaysToMakeChange(nums, n, val);
    return 0;
}

/*

link:

leetcode: https://www.codingninjas.com/studio/problems/ways-to-make-coin-change_630471

Youtube: https://www.youtube.com/watch?v=HgyouUi11zk&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=23

algorithm:

*/