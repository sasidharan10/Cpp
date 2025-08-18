#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Recursion
    int robRecur(int ind, int n, vector<int> &nums)
    {
        // TC: O(2^n)
        // SC: O(n)

        if (ind < 0)
            return 0;
        int notPick = 0 + robRecur(ind - 1, n, nums);
        int pick = nums[ind] + robRecur(ind - 2, n, nums);
        return max(notPick, pick);
    }

    // Memoization
    int robMem(int ind, int n, vector<int> &nums, vector<int> &dp)
    {
        // TC: O(n)
        // SC: O(n) + O(n) // SS

        if (ind < 0)
            return 0;
        if (dp[ind] != -1)
            return dp[ind];
        int notPick = 0 + robMem(ind - 1, n, nums, dp);
        int pick = nums[ind] + robMem(ind - 2, n, nums, dp);
        return dp[ind] = max(notPick, pick);
    }

    // Tabulation
    int robTab(vector<int> &nums)
    {
        // TC: O(n)
        // SC: O(n)

        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        vector<int> dp(n + 1, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++)
        {
            int notPick = 0 + dp[i - 1];
            int pick = nums[i] + dp[i - 2];
            dp[i] = max(notPick, pick);
        }
        return dp[n - 1];
    }

    // Space Optimization

    int robSpc(vector<int> &nums)
    {
        // TC: O(n)
        // SC: O(1)

        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        int prev2 = nums[0];
        int prev = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++)
        {
            int notPick = 0 + prev;
            int pick = nums[i] + prev2;
            int cur = max(pick, notPick);
            prev2 = prev;
            prev = cur;
        }
        return prev;
    }

    int rob(vector<int> &nums)
    {
        int n = nums.size();
        // return robRecur(n - 1, n, nums);
        // vector<int> dp(n + 1, -1);
        // return robMem(n-1, n, nums, dp);
        // return robTab(nums);
        return robSpc(nums);
    }
};
int main()
{
    Solution s;
    vector<int> nums{40, 2, 4, 10};
    cout << "Maximum profit: " << s.rob(nums) << endl;
    return 0;
}

/*

link: 

leetcode: https://leetcode.com/problems/house-robber

Youtube: 

Code Link: 

algorithm: 

- Brute Force Approach:

- 

- Optimal Approach:

- self explanatory

*/

/*

198. House Robber

You are a professional robber planning to rob houses along a street. Each house has a certain amount of 
money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have 
security systems connected and it will automatically contact the police if two adjacent houses were 
broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount 
of money you can rob tonight without alerting the police.

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
 
Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 400


*/

/*   
************* Java Code **************

    public static int rob(int[] nums) {
        int n = nums.length;
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        int prev2 = nums[0];
        int prev = Math.max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            int notPick = 0 + prev;
            int pick = nums[i] + prev2;
            int cur = Math.max(pick, notPick);
            prev2 = prev;
            prev = cur;
        }
        return prev;
    }

*/