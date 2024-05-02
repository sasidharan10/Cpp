#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Brute force
    int findMaxK4(vector<int> &nums)
    {
        // TC: O(n^2)
        // SC: O(1)

        int n = nums.size();
        int maxi = -1;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[j] == (-nums[i]))
                {
                    if (abs(nums[i]) > maxi)
                        maxi = abs(nums[i]);
                }
            }
        }
        return maxi;
    }

    // Using Hashset
    int findMaxK3(vector<int> &nums)
    {
        // TC: O(n)
        // SC: O(n)

        int n = nums.size();
        unordered_set<int> st;
        int maxi = -1;
        for (int i = 0; i < n; i++)
        {
            if (st.find(-nums[i]) != st.end())
            {
                if (abs(nums[i]) > maxi)
                    maxi = abs(nums[i]);
            }
            st.insert(nums[i]);
        }
        return maxi;
    }

    // Sorting and 2 pointer
    int findMaxK2(vector<int> &nums)
    {
        // TC: O(n)
        // SC: O(n)

        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0, j = n - 1;
        while (i < j)
        {
            if (nums[i] > 0 || nums[j] < 0)
                break;
            int temp = abs(nums[i]);
            if (temp == nums[j])
                return temp;
            else if (temp > nums[j])
                i++;
            else
                j--;
        }
        return -1;
    }

    // using array as map (due to small constraint [-1000, 1000])
    int findMaxK(vector<int> &nums)
    {
        // TC: O(1)
        // SC: O(n)

        int n = nums.size();
        int maxi = -1;
        vector<bool> mp(2002, false);
        for (int i = 0; i < n; i++)
        {
            int idx = nums[i] + 1000;
            int counterIdx = (-nums[i]) + 1000;
            mp[idx] = true;
            if (mp[counterIdx] == true)
            {
                if (abs(nums[i]) > maxi)
                    maxi = abs(nums[i]);
            }
        }
        return maxi;
    }
};
int main()
{
    Solution s;
    vector<int> nums{-1, 10, 6, 7, -7, 1};
    cout << "Result: " << s.findMaxK(nums) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/

Youtube: https://www.youtube.com/watch?v=9MLiRUIbzvs

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/Leetcode%20Easy/Largest%20Positive%20Integer%20That%20Exists%20With%20Its%20Negative.cpp

algorithm:

Approach:

- Not needed

*/

/*

2441. Largest Positive Integer That Exists With Its Negative

Given an integer array nums that does not contain any zeros, find the largest
positive integer k such that -k also exists in the array.

Return the positive integer k. If there is no such integer, return -1.

Example 1:

Input: nums = [-1,2,-3,3]
Output: 3
Explanation: 3 is the only valid k we can find in the array.

Example 2:

Input: nums = [-1,10,6,7,-7,1]
Output: 7
Explanation: Both 1 and 7 have their corresponding negative values in the array. 7 has a larger value.

Example 3:

Input: nums = [-10,8,6,7,-2,-3]
Output: -1
Explanation: There is no a single valid k, we return -1.

*/

/*
************* Java Code **************

public static int findMaxK(int[] nums) {
        int n = nums.length;
        HashSet<Integer> st = new HashSet<>();
        int maxi = -1;
        for (int i = 0; i < n; i++) {
            if (st.contains(-nums[i])) {
                if (Math.abs(nums[i]) > maxi)
                    maxi = Math.abs(nums[i]);
            }
            st.add(nums[i]);
        }
        return maxi;
    }

public static int findMaxK(int[] nums) {
        int n = nums.length;
        int maxi = -1;
        boolean[] mp = new boolean[2002];
        for (int i = 0; i < n; i++) {
            int idx = nums[i] + 1000;
            int counterIdx = (-nums[i]) + 1000;
            mp[idx] = true;
            if (mp[counterIdx] == true) {
                if (Math.abs(nums[i]) > maxi)
                    maxi = Math.abs(nums[i]);
            }
        }
        return maxi;
    }

*/