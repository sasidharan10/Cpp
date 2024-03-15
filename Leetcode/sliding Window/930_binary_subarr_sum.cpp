#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Better - using prefix sum
    int numSubarraysWithSum2(vector<int> &nums, int goal)
    {
        // TC: O(n)
        // SC: O(n)

        int n = nums.size();
        unordered_map<int, int> mp;
        int cumSum = 0;
        int result = 0;
        mp[0] = 1;
        for (int i = 0; i < n; i++)
        {
            cumSum += nums[i];
            if (mp.find(cumSum - goal) != mp.end())
            {
                result += mp[cumSum - goal];
            }
            mp[cumSum]++;
        }
        return result;
    }

    // Optimal - Using Sliding Window
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        // TC: O(n) * 2
        // SC: O(1)

        int n = nums.size();
        int i = 0, j = 0;
        int result = 0;
        int windowSum = 0;
        int prefixZeroes = 0;
        while (j < n)
        {
            windowSum += nums[j];
            while (i < j && (nums[i] == 0 || windowSum > goal))
            {
                if (nums[i] == 0)
                    prefixZeroes++;
                else
                    prefixZeroes = 0;

                windowSum -= nums[i];
                i++;
            }

            if (windowSum == goal)
                result += 1 + prefixZeroes;
            j++;
        }
        return result;
    }
};
int main()
{
    Solution s;
    vector<int> nums{1, 0, 1, 0, 1};
    int goal = 2;
    cout << "Binary Subarrays With Sum K: " << s.numSubarraysWithSum(nums, goal) << endl;
    return 0;
}

/*

link:

leetcode:

Youtube:

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

-

*/

/*

930. Binary Subarrays With Sum

Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.

Example 1:

Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
Example 2:

Input: nums = [0,0,0,0,0], goal = 0
Output: 15

*/