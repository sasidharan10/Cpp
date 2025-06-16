#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Brute force
    int maximumDifference3(vector<int> &nums)
    {
        // TC: O(n^2)
        // SC: O(1)

        int n = nums.size();
        int maxDiff = -1;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] >= nums[j])
                    continue;
                maxDiff = max(nums[j] - nums[i], maxDiff);
            }
        }
        return maxDiff;
    }
    // better - using prefix array.
    int maximumDifference2(vector<int> &nums)
    {
        // TC: O(n)
        // SC: O(n)

        int n = nums.size();
        vector<int> prefix(n, 0);
        prefix[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            prefix[i] = max(nums[i], prefix[i + 1]);
        }
        int maxDiff = -1;
        int minVal = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            minVal = min(minVal, nums[i]);
            maxDiff = max(maxDiff, prefix[i] - minVal);
        }
        return maxDiff == 0 ? -1 : maxDiff;
    }

    // Optimal
    int maximumDifference(vector<int> &nums)
    {
        // TC: O(n)
        // SC: O(1)

        int n = nums.size();
        int minVal = nums[0];
        int maxDiff = -1;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] > minVal)
                maxDiff = max(maxDiff, nums[i] - minVal);
            else
                minVal = nums[i];
        }
        return maxDiff;
    }
};
int main()
{
    Solution s;
    vector<int> nums{7, 1, 5, 4};
    cout << "Result: " << s.maximumDifference(nums) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/maximum-difference-between-increasing-elements

Youtube: https://www.youtube.com/watch?v=2WdXwYYDNNg

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/Leetcode%20Easy/Maximum%20Difference%20Between%20Increasing%20Elements.cpp

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

- just store the min element in a variable, and iterate over the array, and find the maxDiff.

*/

/*

2016. Maximum Difference Between Increasing Elements

Given a 0-indexed integer array nums of size n, find the maximum difference between nums[i] and
nums[j] (i.e., nums[j] - nums[i]), such that 0 <= i < j < n and nums[i] < nums[j].
Return the maximum difference. If no such i and j exists, return -1.

Example 1:

Input: nums = [7,1,5,4]
Output: 4
Explanation:
The maximum difference occurs with i = 1 and j = 2, nums[j] - nums[i] = 5 - 1 = 4.
Note that with i = 1 and j = 0, the difference nums[j] - nums[i] = 7 - 1 = 6, but i > j, so it is not valid.

Example 2:

Input: nums = [9,4,3,2]
Output: -1
Explanation:
There is no i and j such that i < j and nums[i] < nums[j].

Example 3:

Input: nums = [1,5,2,10]
Output: 9
Explanation:
The maximum difference occurs with i = 0 and j = 3, nums[j] - nums[i] = 10 - 1 = 9.

Constraints:

n == nums.length
2 <= n <= 1000
1 <= nums[i] <= 10^9

*/

/*
************* Java Code **************

    public int maximumDifference(int[] nums) {
        int n = nums.length;
        int minVal = nums[0];
        int maxDiff = -1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > minVal)
                maxDiff = Math.max(maxDiff, nums[i] - minVal);
            else
                minVal = nums[i];
        }
        return maxDiff;
    }

*/