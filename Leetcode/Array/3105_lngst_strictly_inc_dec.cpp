#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Brute force
    int longestMonotonicSubarray3(vector<int> &nums)
    {
        // TC: O(n^2)
        // SC: O(1)

        int n = nums.size();
        int result = 0;
        for (int i = 0; i < n; i++)
        {
            int increasing = 1;
            int j = i + 1;
            while (j < n && nums[j] > nums[j - 1])
            {
                increasing++;
                j++;
            }

            int decreasing = 1;
            j = i + 1;

            while (j < n && nums[j] < nums[j - 1])
            {
                decreasing++;
                j++;
            }
            result = max({result, increasing, decreasing});
        }
        return result;
    }

    // Optimal - find current longest subarray, then find next subarr starting from next index.
    int longestMonotonicSubarray2(vector<int> &nums)
    {
        // TC: O(2n) ~ O(n)
        // SC: O(1)

        int n = nums.size();
        int i = 0;
        int maxi = 1;
        // strictly increasing
        while (i < n - 1)
        {
            int curlen = 1;
            int j = i;
            while (j < n - 1 && nums[j] < nums[j + 1])
            {
                curlen++;
                j++;
            }
            maxi = max(maxi, curlen);
            if (i == j)
                i++;
            else
                i = j;
        }
        // strictly decreasing
        i = 0;
        while (i < n - 1)
        {
            int curlen = 1;
            int j = i;
            while (j < n - 1 && nums[j] > nums[j + 1])
            {
                curlen++;
                j++;
            }
            maxi = max(maxi, curlen);
            if (i == j)
                i++;
            else
                i = j;
        }
        return maxi;
    }

    // Optimal - more clean code
    int longestMonotonicSubarray(vector<int>& nums) {
        // TC: O(2n) ~ O(n)
        // SC: O(1)

        int n = nums.size();
        int result = 1;
        int increasing = 1;
        int decreasing = 1;
        //{3, 2, 1}
        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i-1]) {
                increasing++;
                decreasing = 1;
                result = max(result, increasing);
            } else if(nums[i] < nums[i-1]) {
                decreasing++;
                increasing = 1;
                result = max(result, decreasing);
            } else {
                increasing = 1;
                decreasing = 1;
            }
        }
        return result;
    }
};
int main()
{
    Solution s;
    vector<int> nums{1, 4, 3, 3, 2};
    cout << "Result: " << s.longestMonotonicSubarray(nums) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray

Youtube: https://www.youtube.com/watch?v=4Hi4v5OaOEA

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/Leetcode%20Easy/Longest%20Strictly%20Increasing%20or%20Strictly%20Decreasing%20Subarray.cpp

algorithm:

- Optimal Approach:

- self explanatory

*/

/*

3105. Longest Strictly Increasing or Strictly Decreasing Subarray

You are given an array of integers nums. Return the length of the longest
subarray of nums which is either strictly increasing or strictly decreasing.

Example 1:

Input: nums = [1,4,3,3,2]
Output: 2
Explanation:

The strictly increasing subarrays of nums are [1], [2], [3], [3], [4], and [1,4].
The strictly decreasing subarrays of nums are [1], [2], [3], [3], [4], [3,2], and [4,3].

Hence, we return 2.

Example 2:

Input: nums = [3,3,3,3]
Output: 1
Explanation:

The strictly increasing subarrays of nums are [3], [3], [3], and [3].
The strictly decreasing subarrays of nums are [3], [3], [3], and [3].

Hence, we return 1.

Example 3:

Input: nums = [3,2,1]
Output: 3
Explanation:

The strictly increasing subarrays of nums are [3], [2], and [1].
The strictly decreasing subarrays of nums are [3], [2], [1], [3,2], [2,1], and [3,2,1].

Hence, we return 3.

Constraints:

1 <= nums.length <= 50
1 <= nums[i] <= 50

*/

/*
************* Java Code **************



*/