#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        // TC: O(n^2)
        // SC: O(1)
        
        int n = nums.size();
        if (n <= 2)
            return 0;
        int cnt = 0;
        for (int start = 0; start <= n - 3; start++)
        {
            int i = start + 1;
            int prev = nums[start];
            int diff = 0;
            int len = 1;
            while (i < n)
            {
                if (len == 1)
                {
                    diff = prev - nums[i];
                    prev = nums[i];
                    len++;
                }
                else
                {
                    if (prev - nums[i] == diff)
                    {
                        len++;
                        prev = nums[i];
                        if (len >= 3)
                            cnt++;
                    }
                    else
                        break;
                }
                i++;
            }
        }
        return cnt;
    }
};
int main()
{
    Solution s;
    vector<int> nums{1, 2, 3, 4};
    cout << "Result: " << s.numberOfArithmeticSlices(nums) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/arithmetic-slices/

Youtube:

algorithm:

- We try to take each element as starting element and check if its adjacent
  elements diff are same. If yes, we increase the len.
- If len>=3, we found a subarray, hence increase the cnt.
- If the diff is not same, that means that subarray no longer follows the pattern,
  hence, we break the loop, and check the same with next element.

*/

/*

413. Arithmetic Slices

An integer array is called arithmetic if it consists of at least three elements
and if the difference between any two consecutive elements is the same.

For example, [1,3,5,7,9], [7,7,7,7], and [3,-1,-5,-9] are arithmetic sequences.
Given an integer array nums, return the number of arithmetic subarrays of nums.

A subarray is a contiguous subsequence of the array.

Example 1:

Input: nums = [1,2,3,4]
Output: 3
Explanation: We have 3 arithmetic slices in nums: [1, 2, 3], [2, 3, 4] and [1,2,3,4] itself.

Example 2:

Input: nums = [1]
Output: 0

*/