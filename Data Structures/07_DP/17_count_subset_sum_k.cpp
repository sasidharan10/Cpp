#include <bits/stdc++.h>
using namespace std;
// Recursion
int findWaysRecur(int ind, int target, vector<int> &arr)
{
    if (target == 0)
        return 1;
    if (ind == 0)
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
    if (target == 0)
        return 1;
    if (ind == 0)
        return (arr[ind] == target);
    if (dp[ind][target] != -1)
        return dp[ind][target];
    int Notpick = findWaysMem(ind - 1, target, arr, dp);
    int pick = 0;
    if (arr[ind] <= target)
        pick = findWaysMem(ind - 1, target - arr[ind], arr, dp);
    return dp[ind][target] = pick + Notpick;
}
// Tabulation
int findWaysTab(vector<int> &arr, int k)
{
    int n = arr.size();
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
            int Notpick = dp[ind - 1][target];
            int pick = 0;
            if (arr[ind] <= target)
                pick = dp[ind - 1][target - arr[ind]];
            dp[ind][target] = pick + Notpick;
        }
    }
    return dp[n - 1][k];
}
// Space Optimization

int findWays(vector<int> &arr, int k)
{
    int n = arr.size();
    // return findWaysRecur(n - 1, k, arr);
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    // return findWaysMem(n - 1, k, arr, dp);
    return findWaysTab(arr, k);
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