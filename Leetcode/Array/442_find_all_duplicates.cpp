#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Brute force - Sorting the array (Accepted)
    vector<int> findDuplicates3(vector<int> &nums)
    {
        // TC: O(nlogn)
        // SC: O(1)

        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] == nums[i + 1])
                ans.push_back(nums[i]);
        }
        return ans;
    }

    // Brute force - using map to mark the visited numbers
    vector<int> findDuplicates2(vector<int> &nums)
    {
        // TC: O(n)
        // SC: O(n)

        int n = nums.size();
        vector<bool> mp(n + 1, false);
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (mp[nums[i]])
                ans.push_back(nums[i]);
            mp[nums[i]] = true;
        }
        return ans;
    }

    // Optimal
    vector<int> findDuplicates(vector<int> &nums)
    {
        // TC: O(n)
        // SC: O(1)

        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            int ind = abs(nums[i]) - 1;
            if (nums[ind] < 0)
                ans.push_back(ind + 1);
            nums[ind] = -nums[ind];
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums{4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> ans = s.findDuplicates2(nums);
    cout << "All Duplicates: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/find-all-duplicates-in-an-array/

Youtube: https://www.youtube.com/watch?v=NqadCpaZnkk

algorithm:

Code Link:

- Brute Force Approach:

- Sorting and finding if adjacent element is same
- using map to check duplicate elements

- Optimal Approach:

- Since the given umbers are from the range 1 - n. we can use the 
  numbers as index and mark as -ve at that index.
- If that index is already marked, then its a duplicate number.
- while marking the index, we take ind = ind - 1. since the range is 1 to n, and the
  index range  is 0 to n - 1.
  
*/

/*

442. Find All Duplicates in an Array

Given an integer array nums of length n where all the integers of nums
are in the range [1, n] and each integer appears once or twice, return
an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant extra space.

Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]

Example 2:

Input: nums = [1,1,2]
Output: [1]

Example 3:

Input: nums = [1]
Output: []

*/

/*
************* Java Code **************



*/