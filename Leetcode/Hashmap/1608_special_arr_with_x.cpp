#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // brute force
    int specialArray4(vector<int> &nums)
    {
        // TC: O(n*n)
        // SC: O(1)

        int n = nums.size();
        vector<int> mp(n, 0);
        mp[0] = -1;
        int cnt;
        for (int num = 1; num <= n; num++)
        {
            cnt = 0;
            for (int i = 0; i < n; i++)
            {
                if (nums[i] >= num)
                    cnt++;
            }
            if (cnt == num)
                return num;
        }
        return -1;
    }

    // Better - using Binary Search
    int specialArray3(vector<int> &nums)
    {
        // TC: O(nlogn) + O(nlogn)
        // SC: O(1)

        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int num = 0; num <= n; num++)
        {
            int idx = lower_bound(nums.begin(), nums.end(), num) - nums.begin();
            int cnt = n - idx;
            if (cnt == num)
                return num;
        }
        return -1;
    }

    // Better - using 2 Binary Search
    int specialArray2(vector<int> &nums)
    {
        // TC: O(nlogn) + O(logn * logn)
        // SC: O(1)

        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0, r = n;

        while (l <= r)
        {
            int num = l + (r - l) / 2;
            int idx = lower_bound(nums.begin(), nums.end(), num) - nums.begin();
            int cnt = n - idx;
            if (cnt == num)
                return num;
            else if (cnt > num)
                l = num + 1;
            else
                r = num - 1;
        }
        return -1;
    }

    // Optimal - Using map
    int specialArray(vector<int> &nums)
    {
        // TC: O(n) + O(n)
        // SC: O(n)
        
        int n = nums.size();
        vector<int> freq(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            int num = nums[i];
            if (num > n)
                freq[n]++;
            else
                freq[num]++;
        }

        int cumSum = 0;
        for (int i = n; i >= 0; i--)
        {
            cumSum = cumSum + freq[i];
            if (cumSum == i)
                return i;
        }
        return -1;
    }
};
int main()
{
    Solution s;
    vector<int> nums{0, 4, 3, 0, 4};
    cout << "Result: " << s.specialArray(nums) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/

Youtube: https://www.youtube.com/watch?v=pYqncHGUqh4

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/Leetcode%20Easy/Special%20Array%20With%20X%20Elements%20Greater%20Than%20or%20Equal%20X.cpp

algorithm:

- Optimal Approach:

- refer video

*/

/*

1608. Special Array With X Elements Greater Than or Equal X

You are given an array nums of non-negative integers. nums is considered special if there 
exists a number x such that there are exactly x numbers in nums that are greater than or equal to x.

Notice that x does not have to be an element in nums.

Return x if the array is special, otherwise, return -1. It can be proven that if nums is 
special, the value for x is unique.

Example 1:

Input: nums = [3,5]
Output: 2
Explanation: There are 2 values (3 and 5) that are greater than or equal to 2.

Example 2:

Input: nums = [0,0]
Output: -1
Explanation: No numbers fit the criteria for x.
If x = 0, there should be 0 numbers >= x, but there are 2.
If x = 1, there should be 1 number >= x, but there are 0.
If x = 2, there should be 2 numbers >= x, but there are 0.
x cannot be greater since there are only 2 numbers in nums.

Example 3:

Input: nums = [0,4,3,0,4]
Output: 3
Explanation: There are 3 values that are greater than or equal to 3.

*/

/*
************* Java Code **************

public int specialArray(int[] nums) {
        int n = nums.length;
        int[] freq = new int[n + 1];
        for (int i = 0; i < n; i++)
        {
            int num = nums[i];
            if (num > n)
                freq[n]++;
            else
                freq[num]++;
        }

        int cumSum = 0;
        for (int i = n; i >= 0; i--)
        {
            cumSum = cumSum + freq[i];
            if (cumSum == i)
                return i;
        }
        return -1;
    }

*/