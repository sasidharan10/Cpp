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
        if (n == 1)
            return nums[0];
        vector<int> temp1, temp2;
        for (int i = 0; i < n; i++)
        {
            if (i != 0)
                temp1.push_back(nums[i]);
            if (i != n - 1)
                temp2.push_back(nums[i]);
        }
        // return max(robRecur(n - 1, n, temp1), robRecur(n - 1, n, temp2));
        vector<int> dp(n, -1);
        vector<int> dp2(n, -1);

        // list size will be (n -1) and last position will be n - 2
        // return max(robMem(n - 2, n - 1, temp1, dp), robMem(n - 2, n - 1, temp2, dp));

        // return max(robTab(temp1), robTab(temp2));
        return max(robSpc(temp1), robSpc(temp2));
    }
};
int main()
{
    Solution s;
    vector<int> nums{1, 2, 3, 1};
    cout << "Maximum profit: " << s.rob(nums) << endl;
    return 0;
}


/*

link: https://www.codingninjas.com/studio/problems/house-robber_839733

leetcode: https://leetcode.com/problems/house-robber-ii/description/

Youtube: https://www.youtube.com/watch?v=3WaxQMELSkw&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=7

Code Link: 

algorithm: 

- Optimal Approach:

- Very similar to House Robber - 1 problem (LC 198)
- Houses in a circle → can’t rob first & last together.
- Break into 2 linear subproblems:
- Rob houses [1..n-1] (exclude first).
- Rob houses [0..n-2] (exclude last).
- Answer = max of the two.

*/

/*

213. House Robber II

You are a professional robber planning to rob houses along a street. Each house has a certain amount of 
money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor 
of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically 
contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of 
money you can rob tonight without alerting the police.

Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.

Example 2:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).

Total amount you can rob = 1 + 3 = 4.
Example 3:

Input: nums = [1,2,3]
Output: 3
 
Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 1000

*/

/*   
************* Java Code **************

    public static int robSpc(int[] nums) {
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

    public static int rob(int[] nums) {
        int n = nums.length;
        if (n == 1)
            return nums[0];

        // Exclude first house -> nums[1..n-1]
        int[] temp1 = new int[n - 1];
        for (int i = 1; i < n; i++) {
            temp1[i - 1] = nums[i];
        }

        // Exclude last house -> nums[0..n-2]
        int[] temp2 = new int[n - 1];
        for (int i = 0; i < n - 1; i++) {
            temp2[i] = nums[i];
        }

        return Math.max(robSpc(temp1), robSpc(temp2));
    }

*/