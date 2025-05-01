#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Brute force - gives TLE
    int subarraysDivByK3(vector<int> &nums, int k)
    {
        // TC: O(n^2)
        // SC: O(1)

        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += nums[j];
                if (sum % k == 0)
                    cnt++;
            }
        }
        return cnt;
    }

    // using prefix sum - gives TLE
    int subarraysDivByK2(vector<int> &nums, int k)
    {
        // TC: O(n^2)
        // SC: O(1)

        int n = nums.size();
        int cnt = 0;
        for (int i = 1; i < n; i++)
        {
            nums[i] += nums[i - 1];
        }
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = i; j < n; j++)
            {
                sum = (i == 0) ? nums[j] : nums[j] - nums[i - 1];
                if (sum % k == 0)
                    cnt++;
            }
        }
        return cnt;
    }

    //
    int subarraysDivByK(vector<int> &nums, int k)
    {
        // TC: O(n)
        // SC: O(1)

        int n = nums.size();
        unordered_map<int, int> mp;
        int cnt = 0;
        int sum = 0;
        mp[0] = 1;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            int rem = sum % k;

            if (rem < 0)
                rem += k;

            if (mp.find(rem) != mp.end())
                cnt += mp[rem];

            mp[rem]++;
        }
        return cnt;
    }
};
int main()
{
    Solution s;
    // vector<int> nums{2, -6, 3, 1, 2, 8, 2, 1};
    // int k = 7;
    vector<int> nums{4, 5, 0, -2, -3, 1};
    int k = 5;
    cout << "Result: " << s.subarraysDivByK(nums, k) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/subarray-sums-divisible-by-k/

Youtube: https://www.youtube.com/watch?v=7Xeorb721LQ

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/Subarray%20Sums%20Divisible%20by%20K%20.cpp

algorithm:

- Brute Force Approach:

- Find all possible sub arrrays and check its sum.

- Optimal Approach:

- self explanatory

*/

/*

974. Subarray Sums Divisible by K

Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.
A subarray is a contiguous part of an array.

Example 1:

Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]

Example 2:

Input: nums = [5], k = 9
Output: 0

Constraints:

1 <= nums.length <= 3 * 10^4
-10^4 <= nums[i] <= 10^4
2 <= k <= 10^4

*/

/*
************* Java Code **************

    public static int subarraysDivByK(int[] nums, int k) {
        int n = nums.length;
        HashMap<Integer, Integer> mp = new HashMap<>();
        int cnt = 0;
        int sum = 0;
        mp.put(0, 1);
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int rem = sum % k;

            if (rem < 0)
                rem += k;

            if (mp.containsKey(rem))
                cnt += mp.get(rem);

            mp.put(rem, mp.getOrDefault(rem, 0) + 1);
        }
        return cnt;
    }

*/