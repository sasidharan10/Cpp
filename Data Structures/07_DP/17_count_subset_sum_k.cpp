#include <bits/stdc++.h>
using namespace std;
// Recursion
int findWaysRecur(int ind, int target, vector<int> &arr)
{
    // TC: O(2^n)
    // SC: O(n)
    
    if (ind == 0)
    {
        if (target == 0 && arr[0] == 0)
            return 2;
        if (target == 0 || arr[0] == target)
            return 1;
        return 0;
    }
    return (arr[ind] == target);
    int Notpick = findWaysRecur(ind - 1, target, arr);
    int pick = 0;
    if (arr[ind] <= target)
        pick = findWaysRecur(ind - 1, target - arr[ind], arr);
    return pick + Notpick;
}
// Memoization
int findWaysMem(int ind, int target, vector<int> &arr, vector<vector<int>> dp)
{
    // TC: O(n*target)
    // SC: O(n*target) + O(n)
    
    int mod = 1e9 + 7;
    if (ind == 0)
    {
        if (target == 0 && arr[0] == 0)
            return 2;
        if (target == 0 || arr[0] == target)
            return 1;
        return 0;
    }
    if (dp[ind][target] != -1)
        return dp[ind][target];
    int Notpick = findWaysMem(ind - 1, target, arr, dp);
    int pick = 0;
    if (arr[ind] <= target)
        pick = findWaysMem(ind - 1, target - arr[ind], arr, dp);
    return dp[ind][target] = (pick + Notpick) % mod;
}
// Tabulation
int findWaysTab(vector<int> &arr, int k)
{
    // TC: O(n*target)
    // SC: O(n*target)
    
    int mod = 1e9 + 7;
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));
    if (arr[0] == 0)
        dp[0][0] = 2;
    else
        dp[0][0] = 1;
    if (arr[0] != 0 && arr[0] <= k)
        dp[0][arr[0]] = 1;
    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 0; target <= k; target++)
        {
            int Notpick = dp[ind - 1][target];
            int pick = 0;
            if (arr[ind] <= target)
                pick = dp[ind - 1][target - arr[ind]];
            dp[ind][target] = (pick + Notpick) % mod;
        }
    }
    return dp[n - 1][k];
}
// Space Optimization
int findWaysSpc(vector<int> &arr, int k)
{

    // TC: O(n*target)
    // SC: O(target)
    int mod = 1e9 + 7;
    int n = arr.size();
    vector<int> prev(k + 1, 0), cur(k + 1, 0);
    if (arr[0] == 0)
        prev[0] = 2;
    else
        prev[0] = 1;
    if (arr[0] != 0 && arr[0] <= k)
        prev[arr[0]] = 1;
    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 0; target <= k; target++)
        {
            int Notpick = prev[target];
            int pick = 0;
            if (arr[ind] <= target)
                pick = prev[target - arr[ind]];
            cur[target] = (pick + Notpick) % mod;
        }
        prev = cur;
    }
    return prev[k];
}
int findWays(vector<int> &arr, int k)
{
    int n = arr.size();
    // return findWaysRecur(n - 1, k, arr);
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    // return findWaysMem(n - 1, k, arr, dp);
    // return findWaysTab(arr, k);
    return findWaysSpc(arr, k);
}

int main()
{
    vector<int> arr{1, 4, 4, 5};
    int n = 4;
    int k = 5;
    cout << "Count subset sum K: " << findWays(arr, k);
    return 0;
}

/*

link: https://www.codingninjas.com/studio/problems/number-of-subsets_3952532

leetcode:

Youtube: https://www.youtube.com/watch?v=ZHyb-A2Mte4&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=18

algorithm:

*/