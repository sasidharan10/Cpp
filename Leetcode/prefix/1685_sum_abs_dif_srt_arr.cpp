#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Brute
    vector<int> getSumAbsoluteDifferences3(vector<int> &nums)
    {
        // TC: O(n^2)
        // SC: O(n) for storing ans

        int n = nums.size(), sum = 0;
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            sum = 0;
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                sum += abs(nums[i] - nums[j]);
            }
            ans.push_back(sum);
        }
        return ans;
    }
    // Better
    vector<int> getSumAbsoluteDifferences2(vector<int> &nums)
    {
        // TC: O(n) + O(n)
        // SC: O(n) + O(n)

        int n = nums.size();
        vector<int> ans(n, 0), prefix(n, 0);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] + nums[i];
        }
        int leftSum, rightSum;
        for (int i = 0; i < n; i++)
        {
            leftSum = prefix[i] - nums[i];
            rightSum = (prefix[n - 1] - prefix[i]);

            ans[i] = (i * nums[i]) - leftSum + rightSum - (n - i - 1) * nums[i];
        }
        return ans;
    }
    // Optimal
    vector<int> getSumAbsoluteDifferences(vector<int> &nums)
    {
        // TC: O(n) + O(n)
        // SC: O(n)

        int n = nums.size();
        vector<int> ans(n, 0);
        int prefix = 0, totSum = 0;
        for (int i = 0; i < n; i++)
        {
            totSum += nums[i];
        }
        int leftSum, rightSum;
        for (int i = 0; i < n; i++)
        {
            leftSum = prefix;
            rightSum = totSum - prefix - nums[i];
            ans[i] = (i * nums[i]) - leftSum + rightSum - (n - i - 1) * nums[i];
            prefix += nums[i];
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums{1, 4, 6, 8, 10};
    vector<int> ans = s.getSumAbsoluteDifferences(nums);
    cout << "Sum of Absolute Differences in a Sorted Array: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array

Youtube: https://www.youtube.com/watch?v=2ENYvJL-Leo

algorithm:

- Prefix sum

*/

/*

1685. Sum of Absolute Differences in a Sorted Array

You are given an integer array nums sorted in non-decreasing order.
Build and return an integer array result with the same length as nums
such that result[i] is equal to the summation of absolute differences
between nums[i] and all the other elements in the array.

In other words, result[i] is equal to sum(|nums[i]-nums[j]|) where 0 <= j < nums.length
and j != i (0-indexed).

Example 1:

Input: nums = [2,3,5]
Output: [4,3,5]
Explanation: Assuming the arrays are 0-indexed, then
result[0] = |2-2| + |2-3| + |2-5| = 0 + 1 + 3 = 4,
result[1] = |3-2| + |3-3| + |3-5| = 1 + 0 + 2 = 3,
result[2] = |5-2| + |5-3| + |5-5| = 3 + 2 + 0 = 5.
Example 2:

Input: nums = [1,4,6,8,10]
Output: [24,15,13,15,21]


*/