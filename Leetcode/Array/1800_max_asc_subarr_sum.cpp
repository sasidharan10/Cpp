#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // brute force
    int maxAscendingSum(vector<int> &nums)
    {
        // TC: O(n^2)
        // SC: O(1)

        int n = nums.size();
        int maxi = nums[0];

        for (int i = 0; i < n; i++)
        {
            int sum = nums[i];
            int j = i + 1;
            while (j < n && nums[j - 1] < nums[j])
            {
                sum += nums[j];
                j++;
            }
            maxi = max(maxi, sum);
        }
        return maxi;
    }

    // Optimal
    int maxAscendingSum2(vector<int> &nums)
    {
        // TC: O(n)
        // SC: O(1)

        int n = nums.size();
        int maxi = nums[0];
        int sum = nums[0];
        for (int i = 1; i < n; i++)
        {
            if (nums[i - 1] < nums[i])
            {
                sum += nums[i];
            }
            else
                sum = nums[i];
            maxi = max(maxi, sum);
        }
        return maxi;
    }
};
int main()
{
    Solution s;
    vector<int> nums{12, 17, 15, 13, 10, 11, 12};
    cout << "Result: " << s.maxAscendingSum(nums) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/maximum-ascending-subarray-sum/

Youtube: https://www.youtube.com/watch?v=gj_lvZxY7GA
 
Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/Leetcode%20Easy/Maximum%20Ascending%20Subarray%20Sum.cpp

algorithm:

- Optimal Approach:

- self explanatory

*/

/*

1800. Maximum Ascending Subarray Sum

Given an array of positive integers nums, return the maximum possible sum of an ascending subarray in nums.
A subarray is defined as a contiguous sequence of numbers in an array.
A subarray [numsl, numsl+1, ..., numsr-1, numsr] is ascending if for all i where l <= i < r, numsi  < numsi+1.
Note that a subarray of size 1 is ascending.

Example 1:

Input: nums = [10,20,30,5,10,50]
Output: 65
Explanation: [5,10,50] is the ascending subarray with the maximum sum of 65.

Example 2:

Input: nums = [10,20,30,40,50]
Output: 150
Explanation: [10,20,30,40,50] is the ascending subarray with the maximum sum of 150.

Example 3:

Input: nums = [12,17,15,13,10,11,12]
Output: 33
Explanation: [10,11,12] is the ascending subarray with the maximum sum of 33.

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100

*/

/*
************* Java Code **************

    public int maxAscendingSum(int[] nums) {
        int n = nums.length;
        int maxi = nums[0];
        int sum = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] < nums[i]) {
                sum += nums[i];
            } else
                sum = nums[i];
            maxi = Math.max(maxi, sum);
        }
        return maxi;
    }

*/