#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Brute force - using O(n) space
    int firstMissingPositive(vector<int> &nums)
    {
        // TC: O(n)
        // SC: O(n)
        
        int n = nums.size();
        vector<bool> mp(n + 1, false);
        for (int i = 0; i < n; i++)
        {
            if (nums[i] >= 1 && nums[i] <= n)
                mp[nums[i]] = true;
        }

        for (int i = 1; i <= n; i++)
        {
            if (!mp[i])
                return i;
        }
        return n + 1;
    }

    // Optimal - using number as index trick (works for problems having numbers 1 to n)
    int firstMissingPositive2(vector<int> &nums)
    {
        // TC: O(3n) = O(n)
        // SC: O(1)

        int n = nums.size();
        bool contains1 = false;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 1)
                contains1 = true;
            if (nums[i] <= 0 || nums[i] > n)
                nums[i] = 1;
        }
        if (!contains1)
            return 1;

        for (int i = 0; i < n; i++)
        {
            int num = abs(nums[i]);
            int ind = num - 1;
            if (nums[ind] > 0)
                nums[ind] = -nums[ind];
        }

        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
                return i + 1;
        }
        return n + 1;
    }
};
int main()
{
    Solution s;
    vector<int> nums{3, 4, -1, -2, 1, 5, 16, 0, 2, 0};
    // vector<int> nums{1, 2, 3};
    cout << "Result: " << s.firstMissingPositive(nums) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/first-missing-positive/

Youtube: https://www.youtube.com/watch?v=lyjOwaUEWWQ

algorithm:

Code Link:

- Brute Force Approach:

-

- Optimal Approach:

-

*/

/*

41. First Missing Positive

Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.

You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.



Example 1:

Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.
Example 2:

Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.
Example 3:

Input: nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.

*/

/*
************* Java Code **************

public static int firstMissingPositive(int[] nums) {
        int n = nums.length;
        boolean contains1 = false;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1)
                contains1 = true;
            if (nums[i] <= 0 || nums[i] > n)
                nums[i] = 1;
        }
        if (!contains1)
            return 1;

        for (int i = 0; i < n; i++) {
            int num = Math.abs(nums[i]);
            int ind = num - 1;
            if (nums[ind] > 0)
                nums[ind] = -nums[ind];
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0)
                return i + 1;
        }
        return n + 1;
    }

*/