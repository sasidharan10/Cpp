#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minimumMountainRemovals(vector<int> &nums)
    {
        // TC: O(n^2)
        // SC: O(1)

        int n = nums.size();
        int mini = INT_MAX;
        int leftCount, rightCount, toBeDeleted, peakElm;
        for (int i = 1; i < n - 1; i++)
        {
            int lt = i - 1;
            int rt = i + 1;
            toBeDeleted = 0;
            leftCount = 0;
            rightCount = 0;
            peakElm = nums[i];
            int currPeak = peakElm;
            while (lt >= 0)
            {
                if (nums[lt] < currPeak)
                {
                    currPeak = nums[lt];
                    leftCount++;
                }
                else
                    toBeDeleted++;
                lt--;
            }
            if (leftCount == 0)
                continue;
            currPeak = peakElm;
            while (rt < n)
            {
                if (nums[rt] < currPeak)
                {
                    currPeak = nums[rt];
                    rightCount++;
                }
                else
                    toBeDeleted++;
                rt++;
            }
            if (rightCount == 0)
                continue;
            mini = min(mini, toBeDeleted);
        }
        return mini;
    }
};
int main()
{
    Solution s;
    // vector<int> nums{2, 1, 1, 5, 6, 2, 3, 1};
    vector<int> nums{23, 47, 63, 72, 81, 99, 88, 55, 21, 33, 32};
    cout << "Result: " << s.minimumMountainRemovals(nums) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array

Youtube:

Code Link:

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

- self explanatory

*/

/*

1671. Minimum Number of Removals to Make Mountain Array

You may recall that an array arr is a mountain array if and only if:

arr.length >= 3
There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given an integer array nums​​​, return the minimum number of elements to remove to make nums​​​ a mountain array.

Example 1:

Input: nums = [1,3,1]
Output: 0
Explanation: The array itself is a mountain array so we do not need to remove any elements.

Example 2:

Input: nums = [2,1,1,5,6,2,3,1]
Output: 3
Explanation: One solution is to remove the elements at indices 0, 1, and 5, making the array
nums = [1,5,6,3,1].

Constraints:

3 <= nums.length <= 1000
1 <= nums[i] <= 10^9
It is guaranteed that you can make a mountain array out of nums.

*/

/*
************* Java Code **************



*/