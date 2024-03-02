#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        // TC: O(n)
        // SC: O(n)

        int n = nums.size();
        vector<int> ans(n, 0);
        int l = 0, r = n - 1, i = n - 1;
        while (l <= r)
        {
            int left = nums[l] * nums[l];
            int right = nums[r] * nums[r];
            if (left > right)
            {
                ans[i] = left;
                l++;
            }
            else
            {
                ans[i] = right;
                r--;
            }
            i--;
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums{-4, -1, 0, 3, 10};
    vector<int> ans = s.sortedSquares(nums);
    cout << "Result: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/squares-of-a-sorted-array/

Youtube: https://www.youtube.com/watch?v=MakXVqKUcug

algorithm:

- Brute Force Approach:

- store the sqrt of all elements in an array
- sort and return  the array.

- Optimal Approach:

- Using 2 pointer
- check which element is greater, and store at the end of arr.
- do this until l<=r.

*/

/*

977. Squares of a Sorted Array

Given an integer array nums sorted in non-decreasing order, return an
array of the squares of each number sorted in non-decreasing order.

Example 1:

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].

Example 2:

Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]

*/