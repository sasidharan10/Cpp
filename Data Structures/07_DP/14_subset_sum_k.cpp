#include <bits/stdc++.h>
using namespace std;
// Recursion
bool subsetSumToKRecur(int ind, int target, vector<int> &arr)
{
    // TC: O(2^n)
    // SC: O(n)

    if (target == 0)
        return true;
    if (ind == 0)
        return (arr[0] == target);
    bool notTake = subsetSumToKRecur(ind - 1, target, arr);
    bool take = false;
    if (target >= arr[ind])
        take = subsetSumToKRecur(ind - 1, target - arr[ind], arr);
    return take | notTake;
}
// Memoization
bool subsetSumToKMem(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    // TC: O(n*target)
    // SC: O(n*target) + O(n)

    if (target == 0)
        return true;
    if (ind == 0)
        return (arr[0] == target);
    if (dp[ind][target] != -1)
        return dp[ind][target];
    bool notTake = subsetSumToKMem(ind - 1, target, arr, dp);
    bool take = false;
    if (target >= arr[ind])
        take = subsetSumToKMem(ind - 1, target - arr[ind], arr, dp);
    return dp[ind][target] = take | notTake;
}
// Tabulation
bool subsetSumToKTab(int n, int k, vector<int> &arr)
{
    // TC: O(n*target)
    // SC: O(n*target)
    
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }
    if (arr[0] <= k)
        dp[0][arr[0]] = 1;
    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 0; target <= k; target++)
        {
            bool notTake = dp[ind - 1][target];
            bool take = false;
            if (target >= arr[ind])
                take = dp[ind - 1][target - arr[ind]];
            dp[ind][target] = take | notTake;
        }
    }
    return dp[n - 1][k];
}
// Space Optimization
bool subsetSumToKSpc(int n, int k, vector<int> &arr)
{
    // TC: O(n*target)
    // SC: O(target)

    vector<int> prev(k + 1, 0), cur(k + 1, 0);
    prev[0] = cur[0] = 1;
    if (arr[0] <= k)
        prev[arr[0]] = 1;
    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 0; target <= k; target++)
        {
            bool notTake = prev[target];
            bool take = false;
            if (target >= arr[ind])
                take = prev[target - arr[ind]];
            cur[target] = take | notTake;
        }
        prev = cur;
    }
    return prev[k];
}
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    // return subsetSumToKRecur(n - 1, k, arr);
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    // return subsetSumToKMem(n - 1, k, arr, dp);
    // return subsetSumToKTab(n, k, arr);
    return subsetSumToKSpc(n, k, arr);
}
int main()
{
    // vector<int> arr{2, 5, 1, 6, 7};
    // int n = 5;
    // int k = 4;
    vector<int> arr{4, 3, 2, 1};
    int n = 4;
    int k = 5;
    cout << "Find subset sum of K: " << subsetSumToK(n, k, arr);
    return 0;
}

/*

link: https://www.codingninjas.com/studio/problems/subset-sum-equal-to-k_1550954

leetcode:

Youtube: https://www.youtube.com/watch?v=fWX9xDmIzRI&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=15

algorithm:

*/