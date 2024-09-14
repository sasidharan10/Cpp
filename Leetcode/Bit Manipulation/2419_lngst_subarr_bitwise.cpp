#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Optimal - Simple observation
    int longestSubarray(vector<int> &nums)
    {
        // TC: O(n)
        // SC: O(1)
        
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        int maxLen = 0;
        int curLen = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == maxi)
            {
                curLen++;
                if (curLen > maxLen)
                    maxLen = curLen;
            }
            else
                curLen = 0;
        }
        return maxLen;
    }
};
int main()
{
    Solution s;
    vector<int> nums{1, 2, 3, 3, 2, 2};
    cout << "Result: " << s.longestSubarray(nums) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and

Youtube: https://www.youtube.com/watch?v=xhKpOhtqAnM

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/Longest%20Subarray%20With%20Maximum%20Bitwise%20AND.cpp

algorithm:

- Optimal Approach:

- Simple observation: Lets take 2 numbers A and B.
- A & B <= max(A, B). The resultant will not be bigger than A,B no matter what the value of A, B is.  
- if A is the max number, then if we use 'AND' operation with other numbers, the resultant will
  always end up being a smaller number, Unless the other number is also A. If the other number
  is also A, then the result will be A itself.
- So, in the given array, the max subarray bitwise 'AND' result will always be equal to max value.
- So, we first find the max value.
- Then, we need to find the longest subarray, which consists of only the max number.
- Then return that max subarray's length.

*/

/*

2419. Longest Subarray With Maximum Bitwise AND

You are given an integer array nums of size n.
Consider a non-empty subarray from nums that has the maximum possible bitwise AND.
In other words, let k be the maximum value of the bitwise AND of any subarray of nums. Then, only
subarrays with a bitwise AND equal to k should be considered.
Return the length of the longest such subarray.
The bitwise AND of an array is the bitwise AND of all the numbers in it.
A subarray is a contiguous sequence of elements within an array.

Example 1:

Input: nums = [1,2,3,3,2,2]
Output: 2
Explanation:
The maximum possible bitwise AND of a subarray is 3.
The longest subarray with that value is [3,3], so we return 2.

Example 2:

Input: nums = [1,2,3,4]
Output: 1
Explanation:
The maximum possible bitwise AND of a subarray is 4.
The longest subarray with that value is [4], so we return 1.

Constraints:

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^6

*/

/*
************* Java Code **************

    public static int longestSubarray(int[] nums) {
        int n = nums.length;
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            maxi = Math.max(maxi, nums[i]);
        }
        int maxLen = 0;
        int curLen = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == maxi) {
                curLen++;
                if (curLen > maxLen)
                    maxLen = curLen;
            } else
                curLen = 0;
        }
        return maxLen;
    }

*/