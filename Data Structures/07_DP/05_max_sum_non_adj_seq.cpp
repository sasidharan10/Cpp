#include <bits/stdc++.h>
using namespace std;
int maximumNonAdjacentSumRecur(int index, vector<int> &nums)
{
    if (index == 0)
        return nums[index];
    if (index < 0)
        return 0;
    int pick = nums[index] + maximumNonAdjacentSumRecur(index - 2, nums);
    int notPick = 0 + maximumNonAdjacentSumRecur(index - 1, nums);
    return max(pick, notPick);
}
int maximumNonAdjacentSumMem(int index, vector<int> &nums, vector<int> &dp)
{
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
int maximumNonAdjacentSumTab(int n, vector<int> &nums)
{
    vector<int> dp(n + 1, -1);
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
int maximumNonAdjacentSumSpc(int n, vector<int> &nums)
{
    int prev = nums[0];
    int prev2 = 0;
    for (int i = 1; i < n; i++)
    {
        int pick = nums[i];
        if (i - 2 >= 0)
            pick += prev2;
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
    // return maximumNonAdjacentSumTab(n, nums);
    return maximumNonAdjacentSumSpc(n, nums);
}
int main()
{
    vector<int> v{2, 1, 4, 9};
    cout << "Maximum sum of non-adjacent elements: " << maximumNonAdjacentSum(v);
    return 0;
}

/*

link: https://www.codingninjas.com/studio/problems/maximum-sum-of-non-adjacent-elements_843261

leetcode: 

Youtube: https://www.youtube.com/watch?v=GrMBfJNk_NY&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=6

algorithm: 

*/