#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Recursion
    int findTargetSumWaysRecur(int ind, int sum, int n, vector<int> &nums, int target)
    {
        if (ind == n)
            return (sum == target) ? 1 : 0;
        int positive = findTargetSumWaysRecur(ind + 1, sum + nums[ind], n, nums, target);
        int negative = findTargetSumWaysRecur(ind + 1, sum - nums[ind], n, nums, target);
        return positive + negative;
    }
    // Memoization
    
    // Tabulation

    // Space Optimization

    int findTargetSumWays(vector<int> &nums, int target)
    {
        // TC: O(2^n)
        // SC: O(1)
        
        int n = nums.size();
        return findTargetSumWaysRecur(0, 0, n, nums, target);
        // vector<vector<int>> dp(n, vector<int>(m + 1, -1));
    }
};
int main()
{
    Solution s;
    vector<int> nums{1, 1, 1, 1, 1};
    int target = 3;
    cout << "Result: " << s.findTargetSumWays(nums, target) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/target-sum

Youtube:

Code Link:

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

- self explanatory

*/

/*

494. Target Sum

You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in
nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build
the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

Example 1:

Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3

Example 2:

Input: nums = [1], target = 1
Output: 1

Constraints:

1 <= nums.length <= 20
0 <= nums[i] <= 1000
0 <= sum(nums[i]) <= 1000
-1000 <= target <= 1000

*/

/*
************* Java Code **************



*/