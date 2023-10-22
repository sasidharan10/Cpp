#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Recursion
    int constrainedSubsetSumRecur(int ind, int prev, vector<int> &nums, int k)
    {
        int n = nums.size();
        if (ind == n && prev == -1)
            return 0;
        if (ind == n)
            return 0;
        int notPick = 0 + constrainedSubsetSumRecur(ind + 1, prev, nums, k);
        int pick = -1e9;
        if (ind - prev <= k)
            pick = nums[ind] + constrainedSubsetSumRecur(ind + 1, ind, nums, k);
        return max(pick, notPick);
    }
    // Memoization
    int constrainedSubsetSumMem(int ind, int prev, vector<int> &nums, int k, vector<vector<int>> &dp)
    {
        int n = nums.size();
        if (ind == n && prev == -1)
            return -1e9;
        if (ind == n)
            return 0;
        if (dp[ind][prev + 1] != -1e9)
            return dp[ind][prev + 1];
        int notPick = 0 + constrainedSubsetSumMem(ind + 1, prev, nums, k, dp);
        int pick = -1e9;
        if (ind - prev <= k)
            pick = nums[ind] + constrainedSubsetSumMem(ind + 1, ind, nums, k, dp);
        return dp[ind][prev + 1] = max(pick, notPick);
    }
    // Tabulation

    // Space Optimization

    int constrainedSubsetSum(vector<int> &nums, int k)
    {
        int n = nums.size();
        return constrainedSubsetSumRecur(0, -1, nums, k);
        vector<vector<int>> dp(n + 1, vector<int>(n + 2, -1e9));
        // return constrainedSubsetSumMem(0, -1, nums, k, dp);
    }
};
int main()
{
    Solution s;
    // vector<int> nums{10, -2, -10, -5, 20};
    vector<int> nums{-8269, 3217, -4023, -4138, -683, 6455, -3621, 9242, 4015, -3790};
    int k = 1;
    cout << "Maximum Subsequence Sum: " << s.constrainedSubsetSum(nums, k);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/constrained-subsequence-sum

Youtube:

algorithm:

*/