#include <bits/stdc++.h>
using namespace std;

// Recursion
int maximumNonAdjacentSumRecur(int index, vector<int> &nums)
{
    // TC: O(2^n)
    // SC: O(n)

    if (index == 0)
        return nums[index];
    if (index < 0)
        return 0;
    int pick = nums[index] + maximumNonAdjacentSumRecur(index - 2, nums);
    int notPick = 0 + maximumNonAdjacentSumRecur(index - 1, nums);
    return max(pick, notPick);
}

// Memoization
int maximumNonAdjacentSumMem(int index, vector<int> &nums, vector<int> &dp)
{
    // TC: O(n)
    // SC: O(n) + O(n)  // SS

    if (index == 0)
        return nums[index];
    if (index < 0)
        return 0;
    if (dp[index] != -1)
        return dp[index];
    int pick = nums[index] + maximumNonAdjacentSumRecur(index - 2, nums);
    int notPick = 0 + maximumNonAdjacentSumRecur(index - 1, nums);
    return dp[index] = max(pick, notPick);
}

// Tabulation
int maximumNonAdjacentSumTab(vector<int> &nums)
{
    // TC: O(n)
    // SC: O(n)

    int n = nums.size();
    vector<int> dp(n + 1, 0);
    dp[0] = nums[0];
    int neg = 0;
    for (int i = 1; i < n; i++)
    {
        int pick = nums[i];
        if (i - 2 >= 0)
            pick += dp[i - 2];
        int notPick = 0 + dp[i - 1];
        dp[i] = max(pick, notPick);
    }
    return dp[n - 1];
}

// Space Optimization
int maximumNonAdjacentSumSpc(vector<int> &nums)
{
    // TC: O(n)
    // SC: O(1)

    int n = nums.size();
    int prev2 = nums[0];
    int prev = max(nums[0], nums[1]);
    for (int i = 2; i < n; i++)
    {
        int pick = nums[i] + prev2;
        int notPick = 0 + prev;
        int cur = max(pick, notPick);
        prev2 = prev;
        prev = cur;
    }
    return prev;
}
int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();
    // return maximumNonAdjacentSumRecur(n - 1, nums);
    vector<int> dp(n + 1, -1);
    // return maximumNonAdjacentSumMem(n - 1, nums, dp);
    return maximumNonAdjacentSumTab(nums);
    // return maximumNonAdjacentSumSpc(nums);
}
int main()
{
    vector<int> v{2, 1, 4, 9};
    cout << "Maximum sum of non-adjacent elements: " << maximumNonAdjacentSum(v);
    return 0;
}

/*

link: https://www.codingninjas.com/studio/problems/maximum-sum-of-non-adjacent-elements_843261

leetcode: https://leetcode.com/problems/house-robber

Youtube: https://www.youtube.com/watch?v=GrMBfJNk_NY&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=6

algorithm:

*/