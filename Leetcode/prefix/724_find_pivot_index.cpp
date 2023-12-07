#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // brute
    int pivotIndex3(vector<int> &nums)
    {
        // TC: O(n^2)
        // SC: O(1)

        int j = 0, k = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int leftSum = 0, rightSum = 0;
            j = i - 1;
            k = i + 1;
            while (j >= 0)
            {
                leftSum += nums[j];
                j--;
            }
            while (k < n)
            {
                rightSum += nums[k];
                k++;
            }
            if (leftSum == rightSum)
                return i;
        }
        return -1;
    }

    // Better (prefix and suffix sum)
    int pivotIndex2(vector<int> &nums)
    {
        // TC: O(n) * 3
        // SC: O(n) * 2

        int n = nums.size();
        vector<int> prefix(n, 0), suffix(n, 0);
        prefix[0] = nums[0];
        suffix[n - 1] = nums[n - 1];
        int j = n - 1;
        for (int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] + nums[i];
            j = n - i - 1;
            suffix[j] = suffix[j + 1] + nums[j];
        }

        for (int i = 0; i < n; i++)
        {
            if (prefix[i] == suffix[i])
                return i;
        }
        return -1;
    }

    // Optimal
    int pivotIndex(vector<int> &nums)
    {
        // TC: O(n) * 1
        // SC: O(n) * 1

        int n = nums.size();
        vector<int> prefix(n, 0);
        prefix[0] = nums[0];
        int totSum = nums[0];
        for (int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] + nums[i];
            totSum += nums[i];
        }
        int suffix = 0;
        for (int i = 0; i < n; i++)
        {
            suffix = totSum - prefix[i] + nums[i];
            if (prefix[i] == suffix)
                return i;
        }
        return -1;
    }
};
int main()
{
    Solution s;
    vector<int> nums{1, 7, 3, 6, 5, 6};
    cout << "Find Pivot Index: " << s.pivotIndex(nums) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/find-pivot-index

Youtube:

algorithm:

*/

/*

724. Find Pivot Index

Given an array of integers nums, calculate the pivot index of this array.
The pivot index is the index where the sum of all the numbers strictly to
the left of the index is equal to the sum of all the numbers strictly to the index's right.
If the index is on the left edge of the array, then the left sum is 0
because there are no elements to the left. This also applies to the right edge of the array.
Return the leftmost pivot index. If no such index exists, return -1.

Example 1:

Input: nums = [1,7,3,6,5,6]
Output: 3
Explanation:
The pivot index is 3.
Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
Right sum = nums[4] + nums[5] = 5 + 6 = 11
Example 2:

Input: nums = [1,2,3]
Output: -1
Explanation:
There is no index that satisfies the conditions in the problem statement.
Example 3:

Input: nums = [2,1,-1]
Output: 0
Explanation:
The pivot index is 0.
Left sum = 0 (no elements to the left of index 0)
Right sum = nums[1] + nums[2] = 1 + -1 = 0



*/