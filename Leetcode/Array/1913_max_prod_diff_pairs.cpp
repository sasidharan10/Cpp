#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProductDifference2(vector<int> &nums)
    {
        // TC: O(NlogN)
        // SC: O(1)

        int n = nums.size();
        sort(nums.begin(), nums.end());
        int a = nums[0];
        int b = nums[1];
        int c = nums[n - 1];
        int d = nums[n - 2];
        return (c * d) - (a * b);
    }

    int maxProductDifference(vector<int> &nums)
    {
        // TC: O(n)
        // SC: O(1)

        int n = nums.size();
        int smallest1 = INT_MAX;
        int smallest2 = INT_MAX;
        int largest1 = INT_MIN;
        int largest2 = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > largest1)
            {
                largest2 = largest1;
                largest1 = nums[i];
            }
            else if (nums[i] > largest2)
                largest2 = nums[i];
            if (nums[i] < smallest1)
            {
                smallest2 = smallest1;
                smallest1 = nums[i];
            }
            else if (nums[i] < smallest2)
                smallest2 = nums[i];
        }
        return (largest1 * largest2) - (smallest1 * smallest2);
    }
};
int main()
{
    Solution s;
    // vector<int> nums{4, 2, 5, 9, 7, 4, 8};
    vector<int> nums{5, 6, 2, 7, 4};
    cout << "Result: " << s.maxProductDifference(nums) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/maximum-product-difference-between-two-pairs

Youtube:

algorithm:

- We have to find 2 pairs, whose difference will be maximum.
- And the difference can be maximum, if 1 pair consists of
  large numbers, and another pair consists of smaller numbers.
- Approach 1 is to sort the array to get the largest, smallest elements.
- Approach 2, is to iterate through the array, to get largest and smallest element.

*/

/*

1913. Maximum Product Difference Between Two Pairs

The product difference between two pairs (a, b) and (c, d) is defined as (a * b) - (c * d).

For example, the product difference between (5, 6) and (2, 7) is (5 * 6) - (2 * 7) = 16.
Given an integer array nums, choose four distinct indices w, x, y, and z such
that the product difference between pairs (nums[w], nums[x]) and (nums[y], nums[z]) is maximized.

Return the maximum such product difference.

Example 1:

Input: nums = [5,6,2,7,4]
Output: 34
Explanation: We can choose indices 1 and 3 for the first pair (6, 7) and
indices 2 and 4 for the second pair (2, 4).
The product difference is (6 * 7) - (2 * 4) = 34.
Example 2:

Input: nums = [4,2,5,9,7,4,8]
Output: 64
Explanation: We can choose indices 3 and 6 for the first pair (9, 8) and
indices 1 and 5 for the second pair (2, 4).
The product difference is (9 * 8) - (2 * 4) = 64.

*/