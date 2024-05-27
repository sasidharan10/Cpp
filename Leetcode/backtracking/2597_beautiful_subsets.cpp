#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Recursion
    int beautifulSubsetsRecur(int ind, int prev, int n, vector<int> &nums, int k)
    {
        if (ind == n)
        {
            if (prev != -1)
                return 1;
            else
                return 0;
        }
        int notTake = beautifulSubsetsRecur(ind + 1, prev, n, nums, k);
        int take = 0;
        if (prev == -1 || abs(prev - nums[ind]) > k)
            take = beautifulSubsetsRecur(ind + 1, nums[ind], n, nums, k);
        return take + notTake;
    }
    // Memoization

    // Tabulation

    // Space Optimization

    int beautifulSubsets(vector<int> &nums, int k)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return beautifulSubsetsRecur(0, -1, n, nums, k);
    }
};
int main()
{
    Solution s;
    // vector<int> nums{2, 4, 6, 8};
    // int k = 2;
    vector<int> nums{4, 2, 5, 9, 10, 3};
    int k = 1;
    cout << "Result: " << s.beautifulSubsets(nums, k) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/the-number-of-beautiful-subsets/

Youtube:

Code Link:

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

-

*/

/*

2597. The Number of Beautiful Subsets

You are given an array nums of positive integers and a positive integer k.
A subset of nums is beautiful if it does not contain two integers with an absolute difference equal to k.
Return the number of non-empty beautiful subsets of the array nums.
A subset of nums is an array that can be obtained by deleting some (possibly none) elements
from nums. Two subsets are different if and only if the chosen indices to delete are different.

Example 1:

Input: nums = [2,4,6], k = 2
Output: 4
Explanation: The beautiful subsets of the array nums are: [2], [4], [6], [2, 6].
It can be proved that there are only 4 beautiful subsets in the array [2,4,6].

Example 2:

Input: nums = [1], k = 1
Output: 1
Explanation: The beautiful subset of the array nums is [1].
It can be proved that there is only 1 beautiful subset in the array [1].

*/

/*
************* Java Code **************



*/