#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        // TC: O(n)
        // SC: O(1)

        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < k; i++)
        {
            sum += nums[i];
        }
        int i = 0, j = k - 1;
        int maxi = INT_MIN;
        while (j < n)
        {
            maxi = max(maxi, sum);
            sum -= nums[i];
            if (j + 1 < n)
                sum += nums[j + 1];
            i++;
            j++;
        }
        return maxi / (double)k;
    }
};
int main()
{
    Solution s;
    vector<int> nums{1, 12, -5, -6, 50, 3};
    int k = 4;
    cout << "Maximum Average Subarray: " << s.findMaxAverage(nums, k) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/maximum-average-subarray-i

Youtube:

algorithm:

*/

/*

643. Maximum Average Subarray I

You are given an integer array nums consisting of n elements, and an integer k.

Find a contiguous subarray whose length is equal to k that has the maximum
average value and return this value. Any answer with a calculation error
less than 10-5 will be accepted.

Example 1:

Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
Example 2:

Input: nums = [5], k = 1
Output: 5.00000

*/