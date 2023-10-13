#include <bits/stdc++.h>
using namespace std;
// Recursion
int longestIncreasingSubsequenceRecur(int ind, int prev, int arr[], int n)
{
    if (ind == n)
        return 0;
    int notPick = 0 + longestIncreasingSubsequenceRecur(ind + 1, prev, arr, n);
    int pick = -1e9;
    if (prev == -1 || arr[prev] <= arr[ind])
        pick = 1 + longestIncreasingSubsequenceRecur(ind + 1, ind, arr, n);
    return max(pick, notPick);
}
// Memoization
int longestIncreasingSubsequenceMem(int ind, int prev, int arr[], int n, vector<vector<int>> &dp)
{
    if (ind == n)
        return 0;
    if (dp[ind][prev + 1] != -1)
        return dp[ind][prev + 1];
    int notPick = 0 + longestIncreasingSubsequenceMem(ind + 1, prev, arr, n, dp);
    int pick = -1e9;
    if (prev == -1 || arr[prev] <= arr[ind])
        pick = 1 + longestIncreasingSubsequenceMem(ind + 1, ind, arr, n, dp);
    return dp[ind][prev + 1] = max(pick, notPick);
}
// Tabulation

// Space Optimization

int longestIncreasingSubsequence(int arr[], int n)
{
    // return longestIncreasingSubsequenceRecur(0, -1, arr, n);
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return longestIncreasingSubsequenceMem(0, -1, arr, n, dp);
}
int main()
{
    int nums[]{5, 4, 11, 1, 16, 8};
    int n = 6;
    cout << "Longest Increasing Subsequence: " << longestIncreasingSubsequence(nums, n);
    return 0;
}

/*

link: https://www.codingninjas.com/studio/problems/longest-increasing-subsequence_630459

leetcode: https://leetcode.com/problems/longest-increasing-subsequence/

Youtube: https://www.youtube.com/watch?v=ekcwMsSIzVc&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=42

algorithm:

*/