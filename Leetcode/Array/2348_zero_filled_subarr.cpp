#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // better - using (n * (n + 1))/2 formula
    long long zeroFilledSubarray2(vector<int> &nums)
    {
        // TC: O(n)
        // SC: O(1)

        int n = nums.size();
        long long len = 0; // length of current zero streak
        long long res = 0; // total zero-filled subarrays
        int i = 0;

        while (i < n)
        {
            if (nums[i] == 0)
            {
                // count length of consecutive zeros
                while (i < n && nums[i] == 0)
                {
                    len++;
                    i++;
                }
                // number of subarrays in this streak = len * (len+1)/2
                res += (len * (len + 1)) / 2;
                len = 0; // reset after processing streak
            }
            i++;
        }
        return res;
    }

    // Optimal - clean code
    long long zeroFilledSubarray(vector<int> &nums)
    {
        // TC: O(n)
        // SC: O(1)

        int n = nums.size();
        long long len = 0;
        long long res = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
                len++;
            else
                len = 0;

            res += len;
        }
        return res;
    }
};
int main()
{
    Solution s;
    vector<int> nums{1, 3, 0, 0, 2, 0, 0, 4};
    cout << "Result: " << s.zeroFilledSubarray(nums) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/number-of-zero-filled-subarrays

Youtube: https://www.youtube.com/watch?v=5sC5MUcF-Qc

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/Number%20of%20Zero-Filled%20Subarrays.cpp

algorithm:

- Optimal Approach:

- Consecutive zeros of length k form (k * (k+1)) / 2 subarrays.
- Traverse array, count streaks of zeros.
- For each streak, add (len * (len+1)) / 2 to result.
- Return result.

*/

/*

2348. Number of Zero-Filled Subarrays

Given an integer array nums, return the number of subarrays filled with 0.
A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:

Input: nums = [1,3,0,0,2,0,0,4]
Output: 6
Explanation:
There are 4 occurrences of [0] as a subarray.
There are 2 occurrences of [0,0] as a subarray.
There is no occurrence of a subarray with a size more than 2 filled with 0. Therefore, we return 6.

Example 2:

Input: nums = [0,0,0,2,0,0]
Output: 9
Explanation:
There are 5 occurrences of [0] as a subarray.
There are 3 occurrences of [0,0] as a subarray.
There is 1 occurrence of [0,0,0] as a subarray.
There is no occurrence of a subarray with a size more than 3 filled with 0. Therefore, we return 9.

Example 3:

Input: nums = [2,10,2019]
Output: 0
Explanation: There is no subarray filled with 0. Therefore, we return 0.

Constraints:

1 <= nums.length <= 105
-10^9 <= nums[i] <= 10^9

*/

/*
************* Java Code **************

    public static long zeroFilledSubarray(int[] nums) {
        int n = nums.length;
        long len = 0;
        long res = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0)
                len++;
            else
                len = 0;

            res += len;
        }
        return res;
    }

*/