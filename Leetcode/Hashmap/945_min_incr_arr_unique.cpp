#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Brute force - gives TLE
    int minIncrementForUnique3(vector<int> &nums)
    {
        // TC: O(n^2)
        // SC: O(1)

        int n = nums.size();
        int res = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }
        for (int i = 0; i < n; i++)
        {
            if (mp[nums[i]] == 1)
                continue;
            else
            {
                while (mp[nums[i]] != 1)
                {
                    int temp = 0;
                    for (int j = 0; j < 100000; j++)
                    {
                        if (mp[nums[i] + j] > 0)
                            temp++;
                        else
                        {
                            mp[nums[i] + j] = 1;
                            break;
                        }
                    }
                    res += temp;
                    mp[nums[i]]--;
                }
            }
        }
        return res;
    }

    // Optimal - using sorting
    int minIncrementForUnique2(vector<int> &nums)
    {
        // TC: O(nlogn) + O(n)
        // SC: O(1)

        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] <= nums[i - 1])
            {
                // (nums[i - 1] - nums[i]) gives no of moves to make nums[i] == nums[i - 1]
                // Then we add 1 to make it unique.
                res += nums[i - 1] - nums[i] + 1;
                nums[i] = nums[i - 1] + 1;
            }
        }
        return res;
    }

    // Optimal - using extra space as map
    int minIncrementForUnique(vector<int> &nums)
    {
        // TC: O(n) + O(n + maxi)
        // SC:  O(n + maxi)
        
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        int res = 0;
        int sz = maxi + n;
        vector<int> mp(sz, 0);
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }
        for (int i = 0; i < sz; i++)
        {
            if (mp[i] <= 1)
                continue;
            int extra = mp[i] - 1;
            mp[i + 1] += extra;
            res += extra;
            mp[i] = 1;
        }
        return res;
    }
};
int main()
{
    Solution s;
    vector<int> nums{3, 2, 1, 2, 1, 7};
    cout << "Result: " << s.minIncrementForUnique3(nums) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/minimum-increment-to-make-array-unique

Youtube:

Code Link:

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

-

*/

/*

945. Minimum Increment to Make Array Unique

You are given an integer array nums. In one move, you can pick an index i
where 0 <= i < nums.length and increment nums[i] by 1.

Return the minimum number of moves to make every value in nums unique.

The test cases are generated so that the answer fits in a 32-bit integer.

Example 1:

Input: nums = [1,2,2]
Output: 1
Explanation: After 1 move, the array could be [1, 2, 3].

Example 2:

Input: nums = [3,2,1,2,1,7]
Output: 6
Explanation: After 6 moves, the array could be [3, 4, 1, 2, 5, 7].
It can be shown with 5 or less moves that it is impossible for the array to have all unique values.

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 105

*/

/*
************* Java Code **************

public int minIncrementForUnique(int[] nums) {
        int n = nums.length;
        Arrays.sort(nums);
        int res = 0;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] <= nums[i - 1])
            {
                res += nums[i - 1] - nums[i] + 1;
                nums[i] = nums[i - 1] + 1;
            }
        }
        return res;
    }

*/