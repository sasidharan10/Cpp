#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Using map
    vector<int> singleNumber3(vector<int> &nums)
    {
        // TC: O(n) + O(n)
        // SC: O(n)

        int n = nums.size();
        vector<int> ans;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }
        for (auto it : mp)
        {
            if (it.second == 1)
                ans.push_back(it.first);
            if (ans.size() == 2)
                return ans;
        }
        return ans;
    }

    // Sorting and traversing the array by pairs
    vector<int> singleNumber2(vector<int> &nums)
    {
        // TC: O(nlogn) + O(n)
        // SC: O(1)

        int n = nums.size();
        vector<int> ans;
        sort(nums.begin(), nums.end());
        int sz = 0;
        for (int i = 1; i < n; i++)
        {
            if (nums[i - 1] != nums[i])
            {
                if (i > 2 && nums[i - 1] == nums[i - 2])
                    ans.push_back(nums[i]);
                else if (i < n - 2 && nums[i] == nums[i + 1])
                    ans.push_back(nums[i - 1]);
                else
                {
                    ans.push_back(nums[i]);
                    ans.push_back(nums[i - 1]);
                    return ans;
                }
                sz++;
                if (sz == 2)
                    return ans;
            }
            else
                i = i + 1;
        }
        if (sz == 1)
            ans.push_back(nums[n - 1]);
        return ans;
    }
    int findMask(int numXor)
    {
        
    }
    vector<int> singleNumber(vector<int> &nums)
    {
        // TC: O(n)
        // SC: O(1)

        int n = nums.size();
        long long numXor = 0;
        for (int i = 0; i < n; i++)
        {
            numXor ^= nums[i];
        }
        int mask = numXor & (-numXor);
        int num1 = 0, num2 = 0;
        for (int i = 0; i < n; i++)
        {
            if ((mask & nums[i]) != 0)
                num1 ^= nums[i];
            else
                num2 ^= nums[i];
        }
        return {num1, num2};
    }
};
int main()
{
    Solution s;
    // vector<int> nums{1, 2, 1, 3, 2, 5};
    // vector<int> nums{1, 1, 2, 2, 3, 4, 4, 5, 5, 6};
    // vector<int> nums{1, 1, 2, 2, 4, 4, 5, 5, 7, 6};
    vector<int> nums{9, 8, 2, 2, 4, 4, 5, 5, 7, 7};
    vector<int> ans = s.singleNumber(nums);
    cout << "Result: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/single-number-iii/

Youtube: https://www.youtube.com/watch?v=h1EVBhCMugI

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Bit_Magic/Single%20Number%20III.cpp

algorithm:

- Optimal Approach:

- There are exactly to unique numbers and all other numbers occurs exactly twice in
  the array. Hence there will be even number of elements in the array.
- We know that if we XOR the same numbers, they will cancel each other(5 ^ 5 = 0).
- So f we XOR all the elements in the array, all elements appearing twice will be cancelled.
- And we will have the XOR of those 2 unique elements. lets say x = "a" ^ "b";
- If we keep "a" and b in separate groups, and then XOR those 2 groups, we will get "a" and b.
- So we try to separate "a" and b, by cheching their bits from right to left.
- Let's say a = 5 => 101(bit) and b = 3 => 011.
- x = a ^ b => 110.
- We know if any bit of a ^ b == 0, it means both have been same bits in that position, hence resulted into 0
  and a ^ b == 1 means, both have different bits in their respective positions.
- 110, from right to left, 
- 0th bit == 0 => same.
- 1st bit == 1 => different.
- Hence we will try to separate the array, into 2 groups by cheching their 1st bit, if 0 then grp1 and if 1
  then grp2.
- Finally we will XOR both groups, and the unique numbers will be remaining, hence return it.

- How to separate the array with this analysis?
- Find the bit position which is different, let's take it as ith position, then create a "mask" number, 
  which will have 1 in ith position. a ^ b => 110 => mask = 010 (1st bit is diferent).So when we 
  do AND operation with the mask, then (nums[i] & mask) == 0, belongs to grp1 and vice versa.
- To create that mask, we take mask = 1, and left shift it until ith position.

- Creating mask using simple trick
- x = a ^ b.
- mask = x & (-x). (watch video for more explanation).

*/

/*

260. Single Number III

Given an integer array nums, in which exactly two elements appear only once and all the
other elements appear exactly twice. Find the two elements that appear only once. You can
return the answer in any order.

You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.

Example 1:

Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer.

Example 2:

Input: nums = [-1,0]
Output: [-1,0]

Example 3:

Input: nums = [0,1]
Output: [1,0]

Constraints:

2 <= nums.length <= 3 * 104
-231 <= nums[i] <= 231 - 1
Each integer in nums will appear twice, only two integers will appear once.

*/

/*
************* Java Code **************

public int[] singleNumber(int[] nums) {
        int n = nums.length;
        int numXor = 0;
        for (int i = 0; i < n; i++)
        {
            numXor ^= nums[i];
        }
        int mask = numXor & (-numXor);
        int num1 = 0, num2 = 0;
        for (int i = 0; i < n; i++)
        {
            if ((mask & nums[i]) != 0)
                num1 ^= nums[i];
            else
                num2 ^= nums[i];
        }
        int[] ans = new int[2];
        ans[0] = num1;
        ans[1] = num2;
        return ans;
    }

*/