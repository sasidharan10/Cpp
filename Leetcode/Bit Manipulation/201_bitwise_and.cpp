#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Brute - TLE
    int rangeBitwiseAnd3(int left, int right)
    {
        // TC: O(left - right)
        // SC: O(1)
        
        int ans = left;
        for (int i = left + 1; i <= right; i++)
        {
            ans &= i;
        }
        return ans;
    }
    // Better
    int rangeBitwiseAnd(int left, int right)
    {
        // TC: O(logn)
        // SC: O(1)
        
        int shiftCount = 0;
        while (left != right)
        {
            left = left >> 1;
            right = right >> 1;
            shiftCount++;
        }
        left = left << shiftCount;
        return left;
    }
    // Optimal
    int rangeBitwiseAnd2(int left, int right)
    {
        // TC: O(logn)
        // SC: O(1)
        
        while (right > left)
        {
            right = (right & (right - 1));
        }
        return right;
    }
};
int main()
{
    Solution s;
    int left = 5, right = 7;
    cout << "Result: " << s.rangeBitwiseAnd(left, right) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/bitwise-and-of-numbers-range

Youtube: https://www.youtube.com/watch?v=3XYQLHSoew8

algorithm:

- Brute Force Approach:

- Perform & operation to all elements in the given range
  and return the result.

- Optimal Approach:

-

*/

/*

201. Bitwise AND of Numbers Range

Given two integers left and right that represent the range [left, right],
return the bitwise AND of all numbers in this range, inclusive.


Example 1:

Input: left = 5, right = 7
Output: 4

Example 2:

Input: left = 0, right = 0
Output: 0

Example 3:

Input: left = 1, right = 2147483647
Output: 0

*/