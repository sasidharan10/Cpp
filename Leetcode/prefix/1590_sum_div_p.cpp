#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minSubarray(vector<int> &nums, int p)
    {
        int n = nums.size();
        int SUM = 0;

        //(a+b)%p = (a%p + b%p) % p
        for (int &num : nums)
        {
            SUM = (SUM + num) % p;
        }

        int target = SUM % p;

        if (target == 0)
        {
            return 0;
        }

        unordered_map<int, int> mp; // prev sum%p ko store karega

        int curr = 0;
        mp[0] = -1;

        int result = n;
        for (int j = 0; j < n; j++)
        {
            curr = (curr + nums[j]) % p;

            int remain = (curr - target + p) % p;
            if (mp.find(remain) != mp.end())
            {
                result = min(result, j - mp[remain]);
            }

            mp[curr] = j;
        }

        return result == n ? -1 : result;
    }
};
int main()
{
    Solution s;
    vector<int> nums{6, 3, 5, 2};
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/make-sum-divisible-by-p

Youtube: https://www.youtube.com/watch?v=5jpCEfRI1sM

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/Cumulative_Sum(Prefix%20Array)/Make%20Sum%20Divisible%20by%20P.cpp

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

- self explanatory

*/

/*

1590. Make Sum Divisible by P

Given an array of positive integers nums, remove the smallest subarray (possibly empty) such that
the sum of the remaining elements is divisible by p. It is not allowed to remove the whole array.

Return the length of the smallest subarray that you need to remove, or -1 if it's impossible.

A subarray is defined as a contiguous block of elements in the array.

Example 1:

Input: nums = [3,1,4,2], p = 6
Output: 1
Explanation: The sum of the elements in nums is 10, which is not divisible by 6. We can remove
the subarray [4], and the sum of the remaining elements is 6, which is divisible by 6.

Example 2:

Input: nums = [6,3,5,2], p = 9
Output: 2
Explanation: We cannot remove a single element to get a sum divisible by 9. The best way is to
remove the subarray [5,2], leaving us with [6,3] with sum 9.

Example 3:

Input: nums = [1,2,3], p = 3
Output: 0
Explanation: Here the sum is 6. which is already divisible by 3. Thus we do not need to remove anything.

Constraints:

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9
1 <= p <= 10^9

*/

/*
************* Java Code **************



*/