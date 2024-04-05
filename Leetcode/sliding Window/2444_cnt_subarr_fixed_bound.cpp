#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // brute force - gives TLE
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        // TC: O(n^2)
        // SC: O(1)

        int n = nums.size();
        long long res = 0;
        for (int i = 0; i < n; i++)
        {
            int mini = nums[i];
            int maxi = nums[i];
            if (mini == minK && maxi == maxK)
                res++;
            for (int j = i + 1; j < n; j++)
            {
                mini = min(mini, nums[j]);
                maxi = max(maxi, nums[j]);
                if (mini < minK || maxi > maxK)
                    break;
                if (mini == minK && maxi == maxK)
                    res++;
            }
            mini = 0;
            maxi = 0;
        }
        return res;
    }

    // Optimal - Sliding Window
    long long countSubarrays2(vector<int> &nums, int minK, int maxK)
    {
        // TC: O(2n)
        // SC: O(1)
        
        int n = nums.size();
        int minIndex = -1;
        int maxIndex = -1;
        int culpritIndex = -1;
        long long res = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] > maxK || nums[i] < minK)
                culpritIndex = i;

            if (nums[i] == minK)
                minIndex = i;
            if (nums[i] == maxK)
                maxIndex = i;

            long long leftBound = min(minIndex, maxIndex); // finding subarr starting index
            int temp = leftBound - culpritIndex;

            res += (temp < 0) ? 0 : temp;
        }

        return res;
    }
};
int main()
{
    Solution s;
    vector<int> nums{1, 3, 5, 2, 7, 5};
    int minK = 1, maxK = 5;
    cout << "Result: " << s.countSubarrays(nums, minK, maxK) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/count-subarrays-with-fixed-bounds/

Youtube: https://www.youtube.com/watch?v=z6LwIkEn9qc

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Sliding%20Window/Count%20Subarrays%20With%20Fixed%20Bounds.cpp

algorithm:

- Brute Force Approach:

- Generate all subarrs and check the condition.

- Optimal Approach:

- Using sliding window
- intially we assign minIndex, maxIndex, culpritIndex as -1.
- So when we calculate, if minK, or maxk is -1, then (res == 0).
- if we found mink, maxK, then we find the starting index of the subarr,
  which is leftBound = min(minIndex, maxIndex).
- If the culprit index is before the starting index, then (leftBound - culpritIndex)
  will be no of subarrs that can be formed from the current subarr.
- incase the culprit index is inbetween the subarr, temp will be negative, hence
  no subarr will be formed.
- If the culprit index is after the last index, again temp will be negative.
  since we would have already added that subarr into the res, hence avoiding duplicates.

*/

/*

2444. Count Subarrays With Fixed Bounds

You are given an integer array nums and two integers minK and maxK.

A fixed-bound subarray of nums is a subarray that satisfies the following conditions:

The minimum value in the subarray is equal to minK.
The maximum value in the subarray is equal to maxK.
Return the number of fixed-bound subarrays.

A subarray is a contiguous part of an array.

Example 1:

Input: nums = [1,3,5,2,7,5], minK = 1, maxK = 5
Output: 2
Explanation: The fixed-bound subarrays are [1,3,5] and [1,3,5,2].
Example 2:

Input: nums = [1,1,1,1], minK = 1, maxK = 1
Output: 10
Explanation: Every subarray of nums is a fixed-bound subarray. There are 10 possible subarrays.

*/

/*
************* Java Code **************

public long countSubarrays(int[] nums, int minK, int maxK) {
        int n = nums.length;
        int minIndex = -1;
        int maxIndex = -1;
        int culpritIndex = -1;
        long res = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] > maxK || nums[i] < minK)
                culpritIndex = i;

            if (nums[i] == minK)
                minIndex = i;
            if (nums[i] == maxK)
                maxIndex = i;

            long leftBound = Math.min(minIndex, maxIndex);
            long temp = leftBound - culpritIndex;

            res += (temp < 0) ? 0 : temp;
        }

        return res;
    }

*/