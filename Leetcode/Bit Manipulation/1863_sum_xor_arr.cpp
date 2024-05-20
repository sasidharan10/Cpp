#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Recursion
    int solve(int ind, int Xor, int n, vector<int> &nums)
    {
        if (ind == n)
            return Xor;
        int notTake = solve(ind + 1, Xor, n, nums);
        int take = solve(ind + 1, Xor ^ nums[ind], n, nums);
        return take + notTake;
    }
    // brute force
    int subsetXORSum2(vector<int> &nums)
    {
        // TC: O(2^n)
        // SC: O(n)

        int n = nums.size();
        return solve(0, 0, n, nums);
    }

    // Optimal
    int subsetXORSum(vector<int> &nums)
    {
        // TC: O(n)
        // SC: O(1)

        int n = nums.size();
        int num = 0;
        for (int i = 0; i < n; i++)
        {
            num = num | nums[i];
        }
        return num << (n - 1);
    }
};
int main()
{
    Solution s;
    // vector<int> nums{3, 4, 5, 6, 7, 8};
    vector<int> nums{5, 1, 6};
    cout << "Result: " << s.subsetXORSum(nums) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/sum-of-all-subset-xor-totals/

Youtube: https://www.youtube.com/watch?v=3tzP38WPAoA

Code Link:

algorithm:

- Brute Force Approach:

- Finding all subsets, and taking Xor of it using recursion. Return the res and sum it.

- Optimal Approach:

- 

*/

/*

1863. Sum of All Subset XOR Totals

The XOR total of an array is defined as the bitwise XOR of all its elements, or 0 if the array is empty.

For example, the XOR total of the array [2,5,6] is 2 XOR 5 XOR 6 = 1.
Given an array nums, return the sum of all XOR totals for every subset of nums.

Note: Subsets with the same elements should be counted multiple times.

An array a is a subset of an array b if a can be obtained from b by deleting some (possibly zero)
elements of b.

Example 1:

Input: nums = [1,3]
Output: 6
Explanation: The 4 subsets of [1,3] are:
- The empty subset has an XOR total of 0.
- [1] has an XOR total of 1.
- [3] has an XOR total of 3.
- [1,3] has an XOR total of 1 XOR 3 = 2.
0 + 1 + 3 + 2 = 6

Example 2:

Input: nums = [5,1,6]
Output: 28
Explanation: The 8 subsets of [5,1,6] are:
- The empty subset has an XOR total of 0.
- [5] has an XOR total of 5.
- [1] has an XOR total of 1.
- [6] has an XOR total of 6.
- [5,1] has an XOR total of 5 XOR 1 = 4.
- [5,6] has an XOR total of 5 XOR 6 = 3.
- [1,6] has an XOR total of 1 XOR 6 = 7.
- [5,1,6] has an XOR total of 5 XOR 1 XOR 6 = 2.
0 + 5 + 1 + 6 + 4 + 3 + 7 + 2 = 28

Example 3:

Input: nums = [3,4,5,6,7,8]
Output: 480
Explanation: The sum of all XOR totals for every subset is 480.

*/

/*
************* Java Code **************



*/