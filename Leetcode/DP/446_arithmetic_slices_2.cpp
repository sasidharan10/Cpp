#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Recursion
    int numberOfArithmeticSlicesRecur(int ind, int prev, int diff, int len, int n, vector<int> &nums)
    {
        // TC: O(2^n) will not work for large inputs
        // SC: O(n)

        if (ind == n)
            return len >= 3 ? 1 : 0;

        int pick = 0;
        int notPick = 0;

        if (len == 0)
        {
            pick = numberOfArithmeticSlicesRecur(ind + 1, nums[ind], diff, len + 1, n, nums);
            notPick = numberOfArithmeticSlicesRecur(ind + 1, prev, diff, len, n, nums);
        }
        else if (len == 1)
        {
            pick = numberOfArithmeticSlicesRecur(ind + 1, nums[ind], prev - nums[ind], len + 1, n, nums);
            notPick = numberOfArithmeticSlicesRecur(ind + 1, prev, diff, len, n, nums);
        }
        else if (len > 1)
        {
            if (prev - nums[ind] == diff)
            {
                pick = numberOfArithmeticSlicesRecur(ind + 1, nums[ind], diff, len + 1, n, nums);
                notPick = numberOfArithmeticSlicesRecur(ind + 1, prev, diff, len, n, nums);
            }
            else
            {
                notPick = numberOfArithmeticSlicesRecur(ind + 1, prev, diff, len, n, nums);
            }
        }
        return (pick + notPick);
    }

    // Tabulation
    int numberOfArithmeticSlicesTab(vector<int> &nums)
    {
        // TC: O(n^2)
        // SC: O(n*2)

        int n = nums.size();
        unordered_map<long, long> mp[n];
        long res = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                long diff = (long)nums[i] - nums[j];
                long cnt_j;
                if (mp[j].find(diff) == mp[j].end())
                    cnt_j = 0;
                else
                    cnt_j = mp[j][diff];
                mp[i][diff] += cnt_j + 1;
                res += cnt_j;
            }
        }
        return res;
    }

    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int n = nums.size();
        // return numberOfArithmeticSlicesRecur(0, INT_MAX, INT_MAX, 0, n, nums);
        return numberOfArithmeticSlicesTab(nums);
    }
};
int main()
{
    Solution s;
    // vector<int> nums{2, 4, 6, 8, 10};
    vector<int> nums{7, 7, 7, 7, 7};
    cout << "Result: " << s.numberOfArithmeticSlices(nums) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/arithmetic-slices-ii-subsequence

Youtube: https://www.youtube.com/watch?v=cau0JE1q_ZA

algorithm: refer video, too complex to explain :(

*/

/*

446. Arithmetic Slices II - Subsequence

Given an integer array nums, return the number of all the arithmetic subsequences of nums.

A sequence of numbers is called arithmetic if it consists of at least
three elements and if the difference between any two consecutive elements is the same.

For example, [1, 3, 5, 7, 9], [7, 7, 7, 7], and [3, -1, -5, -9] are arithmetic sequences.
For example, [1, 1, 2, 5, 7] is not an arithmetic sequence.
A subsequence of an array is a sequence that can be formed by removing
some elements (possibly none) of the array.

For example, [2,5,10] is a subsequence of [1,2,1,2,4,1,5,10].
The test cases are generated so that the answer fits in 32-bit integer.

Example 1:

Input: nums = [2,4,6,8,10]
Output: 7
Explanation: All arithmetic subsequence slices are:
[2,4,6]
[4,6,8]
[6,8,10]
[2,4,6,8]
[4,6,8,10]
[2,4,6,8,10]
[2,6,10]

Example 2:

Input: nums = [7,7,7,7,7]
Output: 16
Explanation: Any subsequence of this array is arithmetic.

*/