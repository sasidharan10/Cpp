#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Brute force - Gives TLE
    int findMaxLength(vector<int> &nums)
    {
        // TC: O(n^2)
        // SC: O(1)

        int n = nums.size();
        int temp = 0;
        int maxLen = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (nums[j] == 1)
                    temp++;
                else
                    temp--;
                if (temp == 0)
                    maxLen = max(maxLen, j - i + 1);
            }
            temp = 0;
        }
        return maxLen;
    }

    // Optimal
    int findMaxLength2(vector<int> &nums)
    {
        // TC: O(n)
        // SC: O(n)

        int n = nums.size();
        int temp = 0;
        int maxLen = 0;
        // vector<int>ans(n, 0);
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 1)
                temp++;
            else
                temp--;
            if (temp == 0)
                maxLen = max(maxLen, i + 1);
            if (mp.find(temp) != mp.end())
                maxLen = max(maxLen, i - mp[temp]);
            else
                mp[temp] = i;
        }
        return maxLen;
    }
};
int main()
{
    Solution s;
    vector<int> nums{1, 1, 1, 1, 1, 0, 0, 0};
    cout << "Max Subarray with equal 0's and 1's: " << s.findMaxLength(nums) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/contiguous-array/

Youtube:

algorithm:

Code Link:

- Brute Force Approach:

- We try to traverse through each possible subarray, and check if it has
  equal no of 0's and 1's. 
- If yes, we update the maxLen.

- Optimal Approach:

- Think of On/Off strategy.
- When we encounter 1, we increment temp, and when we encounter 0 we decrement
  temp.
- If (temp == 0), the subarray from 0 - i, has equal 0's amd 1's. hence
  we update maxLen.
- Or mp[temp] exists, which means between mp[temp] - i, the subarray has equal 0's amd 1's.
- Note, we only put mp[temp] once, so it stores the index of first occurence of temp. If we keep
  updating it, the length wont be maximum.

*/

/*

525. Contiguous Array

Given a binary array nums, return the maximum length of a contiguous subarray
with an equal number of 0 and 1.

Example 1:

Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.

Example 2:

Input: nums = [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.

*/